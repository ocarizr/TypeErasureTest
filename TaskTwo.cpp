#include "TaskTwo.h"

TaskTwo::TaskTwo()
	: m_result(0)
	, m_current_location(0)
	, m_status(-1)
{
}

void TaskTwo::Start(const std::string& buffer, const std::string& target)
{
	m_buffer = buffer;
	m_search_to = target;
	m_result = 0;
	m_status = 0;
}

void TaskTwo::Update()
{
	if(m_status != 0)
	{
		return;
	}

	m_current_location = m_buffer.find(m_search_to, m_current_location);
	if(m_current_location == std::string::npos)
	{
		m_status = 1;
		//printf("Task Two: Completed\n");
		return;
	}

	m_result++;
	m_current_location += m_search_to.size() - 1;
}
