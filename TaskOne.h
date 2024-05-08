#pragma once

struct TaskOneData
{
	int start_point;
	int target;
};

class TaskOne
{
public:
	TaskOne();

	bool operator== (const TaskOne& other) const
	{
		return m_target == other.m_target && m_currentValue == other.m_currentValue;
	}

	void Start(int start_point, int target);

	void Pump();

	int GetStatus() const { return m_status; }

private:
	int m_target;
	int m_currentValue;

	int m_status;
};

