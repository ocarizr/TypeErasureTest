#include "ITask.h"

void TaskOneTracker::start(const std::any& data)
{
	const TaskOneData& cast_data = std::any_cast<TaskOneData>(data);
	m_task.Start(cast_data.start_point, cast_data.target);
}

void TaskOneTracker::tick()
{
	m_task.Pump();
}

ETaskStatus TaskOneTracker::get_status()
{
	int status = m_task.GetStatus();

	if (status == 0)
	{
		return ETaskStatus::RUNNING;
	}

	if (status == 1)
	{
		return ETaskStatus::SUCCESS;
	}

	return ETaskStatus::NONE;
}

void TaskTwoTracker::start(const std::any& data)
{
	const TaskTwoData& cast_data = std::any_cast<TaskTwoData>(data);
	m_task.Start(cast_data.buffer, cast_data.search_to);
}

void TaskTwoTracker::tick()
{
	m_task.Update();
}

ETaskStatus TaskTwoTracker::get_status()
{
	const int status = m_task.GetStatus();
	if (status == 0)
	{
		return ETaskStatus::RUNNING;
	}

	if (status == 1)
	{
		return ETaskStatus::SUCCESS;
	}

	return ETaskStatus::NONE;
}

void TaskThreeTracker::start(const std::any& data)
{
	const TaskThreeData& cast_data = std::any_cast<TaskThreeData>(data);
	m_task.Start(cast_data.buffer, cast_data.search_to);
}

void TaskThreeTracker::tick()
{
	m_task.Update();
}

ETaskStatus TaskThreeTracker::get_status()
{
	const ETaskThreeStatus status = m_task.GetStatus();
	switch (status)
	{
	case ETaskThreeStatus::IDLE:
		return ETaskStatus::NONE;
	case ETaskThreeStatus::PROCESSING:
		return ETaskStatus::RUNNING;
	case ETaskThreeStatus::SUCCESS:
		return ETaskStatus::SUCCESS;
	case ETaskThreeStatus::FAILURE:
		return ETaskStatus::FAILURE;
	default:
		return ETaskStatus::NONE;
	}
}
