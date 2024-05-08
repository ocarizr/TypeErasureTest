#pragma once

#include <memory>
#include <vector>

#include "ITask.h"

using TaskHandle = unsigned int;

class PO_TaskManager
{
public:
	template<typename TTask, typename TDataStruct>
	TaskHandle start_task(const TDataStruct& data)
	{
		m_tasks.push_back(std::make_unique<TTask>());
		const TaskHandle handle = m_tasks.size() - 1;
		m_tasks[handle]->start(data);
		return handle;
	}

	void tick()
	{
		std::vector<size_t> to_remove;
		for (size_t index = 0; index < m_tasks.size(); ++index)
		{
			std::unique_ptr<ITask>& task = m_tasks[index];
			task->tick();
			if (task->get_status() != ETaskStatus::RUNNING)
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
	std::vector<std::unique_ptr<ITask>> m_tasks;
};



