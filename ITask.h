#pragma once

#include <any>

#include "TaskOne.h"
#include "TaskThree.h"
#include "TaskTwo.h"
#include "TE_TaskTracker.h"

class ITask
{
public:
	virtual ~ITask() = default;
	virtual bool operator ==(const ITask& other) const = 0;
	virtual void start(const std::any& data) = 0;
	virtual void tick() = 0;
	virtual ETaskStatus get_status() = 0;
};

class TaskOneTracker : public ITask
{
public:
	TaskOneTracker() = default;
	~TaskOneTracker() override = default;

	bool operator ==(const ITask& other) const override
	{
		const auto cast_other = dynamic_cast<const TaskOneTracker*>(&other);
		if(!cast_other)
		{
			return false;
		}

		return m_task == cast_other->m_task;
	}

	void start(const std::any& data) override;

	void tick() override;

	ETaskStatus get_status() override;
private:
	TaskOne m_task;
};

class TaskTwoTracker : public ITask
{
public:
	TaskTwoTracker() = default;
	~TaskTwoTracker() override = default;

	bool operator ==(const ITask& other) const override
	{
		const auto cast_other = dynamic_cast<const TaskTwoTracker*>(&other);
		if (!cast_other)
		{
			return false;
		}

		return m_task == cast_other->m_task;
	}

	void start(const std::any& data) override;

	void tick() override;

	ETaskStatus get_status() override;
private:
	TaskTwo m_task;
};

class TaskThreeTracker : public ITask
{
public:
	TaskThreeTracker() = default;
	~TaskThreeTracker() override = default;

	bool operator ==(const ITask& other) const override
	{
		const auto cast_other = dynamic_cast<const TaskThreeTracker*>(&other);
		if (!cast_other)
		{
			return false;
		}

		return m_task == cast_other->m_task;
	}

	void start(const std::any& data) override;

	void tick() override;

	ETaskStatus get_status() override;
private:
	TaskThree m_task;
};

