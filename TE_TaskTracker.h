#pragma once
#include <any>

#include "Enums.h"

struct TypeErasedTaskFunctionTable
{
	std::any(*construct)();
	void (*destruct)(std::any&);

	bool (*equality_check)(const std::any&, const std::any&);

	void (*start)(std::any&, std::any&);
	void (*tick)(std::any&);
	ETaskStatus(*get_status)(const std::any&);
};

class TypeErasedTask
{
public:
	TypeErasedTask(TypeErasedTaskFunctionTable* task_function_table)
		: m_function_table(task_function_table)
	{
		m_object = m_function_table->construct();
	}

	~TypeErasedTask()
	{
		m_function_table->destruct(m_object);
	}

	bool operator ==(const TypeErasedTask& other) const { return m_function_table->equality_check(m_object, other.m_object); }

	template<typename TData>
	void start(const TData& data)
	{
		std::any anyData(data);
		m_function_table->start(m_object, anyData);
	}

	void tick() { m_function_table->tick(m_object); }

	ETaskStatus get_status() { return m_function_table->get_status(m_object); }

private:
	TypeErasedTaskFunctionTable* m_function_table;
	std::any m_object;
};
