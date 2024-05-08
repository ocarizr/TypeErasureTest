#pragma once
#include <vector>

enum class ETaskThreeStatus : unsigned char
{
	IDLE,
	PROCESSING,
	SUCCESS,
	FAILURE
};

struct TaskThreeData
{
	std::vector<int> buffer;
	int search_to;
};

class TaskThree
{
public:
	TaskThree();

	bool operator ==(const TaskThree& other) const
	{
		bool result = m_searching == other.m_searching;
		result = result && m_buffer.size() == other.m_buffer.size();

		if(result)
		{
			for (int i = 0; i < m_buffer.size(); ++i)
			{
				result = result && (m_buffer[i] == other.m_buffer[i]);
				if (!result)
				{
					break;
				}
			}
		}

		return result;
	}

	void Start(const std::vector<int>& buffer, int target);

	void Update();

	ETaskThreeStatus GetStatus() const { return m_status; }

private:
	std::vector<int> m_buffer;
	int m_searching;

	ETaskThreeStatus m_status;
};

