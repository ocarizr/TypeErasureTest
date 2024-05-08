#pragma once

#include <vector>

#include "TE_TaskBuilder.h"

using TaskHandle = unsigned int;

class TE_TaskManager
{
public:
	template<typename TTask, typename TDataStruct>
	TaskHandle start_task(const TDataStruct& data)
	{
		m_tasks.push_back(TaskTrackerBuilder::build_function_table<TTask, TDataStruct>());
		TaskHandle handle = m_tasks.size() - 1;
		m_tasks[handle].start(data);
		return handle;
	}

	void tick()
	{
		std::vector<size_t> to_remove;
		for (size_t index = 0; index < m_tasks.size(); ++index)
		{
			TypeErasedTask& task = m_tasks[index];
			task.tick();
			if (task.get_status() != ETaskStatus::RUNNING)
			{
				to_remove.push_back(index);
			}
		}

		for (auto it = to_remove.rbegin(); it != to_remove.rend(); ++it)
		{
			// trigger listener
			m_tasks.erase(m_tasks.begin() + *it);
		}
	}

	[[nodiscard]] bool has_tasks_running() const { return !m_tasks.empty(); }

private:
	std::vector<TypeErasedTask> m_tasks;
};

