#pragma once

#include "TE_TaskTracker.h"

class TaskTrackerBuilder
{
public:
	// implement a specialization for this for all possible TTasks we are managing here
	template<typename TTask, typename TData>
	static TypeErasedTaskFunctionTable* build_function_table()
	{
		return nullptr;
	}
};

#include "TaskOne.h"

template<>
inline TypeErasedTaskFunctionTable* TaskTrackerBuilder::build_function_table<TaskOne, TaskOneData>()
{
	static TypeErasedTaskFunctionTable table
	{
		// construct
		[]() { return std::any(TaskOne()); },
		// destruct
		[](std::any&) {},
		//equality_check
		[](const std::any& rhs, const std::any& lhs)
		{
			if(!rhs.has_value() || !lhs.has_value())
			{
				return false;
			}

			if(rhs.type() != lhs.type())
			{
				return false;
			}

			return std::any_cast<TaskOne>(rhs) == std::any_cast<TaskOne>(lhs);
		},
		// start
		[](std::any& obj, std::any& data)
		{
			const TaskOneData& cast_data = std::any_cast<TaskOneData>(data);
			const TaskOne& typedObj = std::any_cast<TaskOne>(obj);
			auto ptr = const_cast<TaskOne*>(&typedObj);
			ptr->Start(cast_data.start_point, cast_data.target);
		},
		// tick
		[](std::any& obj)
		{
			const TaskOne& typedObj = std::any_cast<TaskOne>(obj);
			auto ptr = const_cast<TaskOne*>(&typedObj);
			ptr->Pump();
		},
		//get_status
		[](const std::any& obj)
		{
			const TaskOne& typedObj = std::any_cast<TaskOne>(obj);
			const int status = typedObj.GetStatus();

			if(status == 0)
			{
				return ETaskStatus::RUNNING;
			}

			if (status == 1)
			{
				return ETaskStatus::SUCCESS;
			}

			return ETaskStatus::NONE;
		}
	};

	return &table;
}

#include "TaskTwo.h"

template<>
inline TypeErasedTaskFunctionTable* TaskTrackerBuilder::build_function_table<TaskTwo, TaskTwoData>()
{
	static TypeErasedTaskFunctionTable table
	{
		// construct
		[]() { return std::any(TaskTwo()); },
		// destruct
		[](std::any&) {},
		//equality_check
		[](const std::any& rhs, const std::any& lhs)
		{
			if (!rhs.has_value() || !lhs.has_value())
			{
				return false;
			}

			if (rhs.type() != lhs.type())
			{
				return false;
			}

			return std::any_cast<TaskTwo>(rhs) == std::any_cast<TaskTwo>(lhs);
		},
		// start
		[](std::any& obj, std::any& data)
		{
			const TaskTwoData& cast_data = std::any_cast<TaskTwoData>(data);
			const TaskTwo& typedObj = std::any_cast<TaskTwo>(obj);
			auto ptr = const_cast<TaskTwo*>(&typedObj);
			ptr->Start(cast_data.buffer, cast_data.search_to);
		},
		// tick
		[](std::any& obj)
		{
			const TaskTwo& typedObj = std::any_cast<TaskTwo>(obj);
			auto ptr = const_cast<TaskTwo*>(&typedObj);
			ptr->Update();
		},
		//get_status
		[](const std::any& obj)
		{
			const TaskTwo& typedObj = std::any_cast<TaskTwo>(obj);
			int status = typedObj.GetStatus();

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
	};

	return &table;
}

#include "TaskThree.h"

template<>
inline TypeErasedTaskFunctionTable* TaskTrackerBuilder::build_function_table<TaskThree, TaskThreeData>()
{
	static TypeErasedTaskFunctionTable table
	{
		// construct
		[]() { return std::any(TaskThree()); },
		// destruct
		[](std::any&) {},
		//equality_check
		[](const std::any& rhs, const std::any& lhs)
		{
			if (!rhs.has_value() || !lhs.has_value())
			{
				return false;
			}

			if (rhs.type() != lhs.type())
			{
				return false;
			}

			return std::any_cast<TaskThree>(rhs) == std::any_cast<TaskThree>(lhs);
		},
		// start
		[](std::any& obj, std::any& data)
		{
			const TaskThreeData& cast_data = std::any_cast<TaskThreeData&>(data);
			const TaskThree& typedObj = std::any_cast<TaskThree>(obj);
			auto ptr = const_cast<TaskThree*>(&typedObj);
			ptr->Start(cast_data.buffer, cast_data.search_to);
		},
		// tick
		[](std::any& obj)
		{
			const TaskThree& typedObj = std::any_cast<TaskThree>(obj);
			auto ptr = const_cast<TaskThree*>(&typedObj);
			ptr->Update();
		},
		//get_status
		[](const std::any& obj)
		{
			const TaskThree& typedObj = std::any_cast<TaskThree>(obj);
			ETaskThreeStatus status = typedObj.GetStatus();
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
	};

	return &table;
}