#include "TaskThree.h"

#include <algorithm>

TaskThree::TaskThree()
	: m_searching(0)
	, m_status(ETaskThreeStatus::IDLE)
{
}

void TaskThree::Start(const std::vector<int>& buffer, int target)
{
	m_buffer = buffer;
	m_searching = target;

	std::sort(m_buffer.begin(), m_buffer.end());
}

void TaskThree::Update()
{
	if(m_status != ETaskThreeStatus::PROCESSING)
	{
		return;
	}

	if(m_buffer.empty() || (m_buffer.size() == 1 && m_buffer[0] != m_searching))
	{
		m_status = ETaskThreeStatus::FAILURE;
		return;
	}

	const int mid_index = static_cast<int>(m_buffer.size()) / 2;
	const int mid_value = m_buffer[mid_index];
	if(mid_value == m_searching)
	{
		m_status = ETaskThreeStatus::SUCCESS;
		return;
	}

	if(mid_value > m_searching)
	{
		m_buffer.erase(m_buffer.begin() + mid_index, m_buffer.end());
		return;
	}

	if(mid_value < m_searching)
	{
		m_buffer.erase(m_buffer.begin(), m_buffer.begin() + mid_index);
	}
}
