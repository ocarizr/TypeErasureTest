#pragma once
#include <string>

struct TaskTwoData
{
	std::string buffer;
	std::string search_to;
};

class TaskTwo
{
public:
	TaskTwo();

	bool operator==(const TaskTwo& other) const
	{
		return m_buffer == other.m_buffer && m_search_to == other.m_search_to;
	}

	void Start(const std::string& buffer, const std::string& target);

	void Update();

	int GetStatus() const { return m_status; }

private:
	int m_result;
	std::string m_buffer;
	std::string m_search_to;

	size_t m_current_location;

	int m_status;
};

