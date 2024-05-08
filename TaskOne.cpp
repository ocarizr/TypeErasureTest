#include "TaskOne.h"

TaskOne::TaskOne()
	: m_target(0)
	, m_currentValue(0)
	, m_status(-1)
{
}

void TaskOne::Start(int start_point, int target)
{
	m_target = target;
	m_currentValue = start_point;
	m_status = 0;
}

void TaskOne::Pump()
{
	if(m_status != 0)
	{
		return;
	}

	if(m_currentValue++ == m_target)
	{
		m_status = 1;
	}
}
