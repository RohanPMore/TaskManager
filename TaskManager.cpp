#include "TaskManager.h"
#include <iostream>
#include <algorithm>

void TaskManager::addTask(const std::string& title, const std::string& description, int priority, const std::string& deadline)
{
	tasks.push_back(std::make_shared<Task>(title, description, priority, deadline));
}

void TaskManager::removeTask(const std::string& title)
{
	auto it = std::remove_if(tasks.begin(), tasks.end(), [&title](const std::shared_ptr<Task>& task) {return task->getTitle() == title;});
	if (it != tasks.end())
	{
		tasks.erase(it, tasks.end());
		std::cout << "Task \"" << title << "\" removed successfully.\n";
	}
	else
	{
		std::cout << "Task \"" << title << "\" not found.\n";
	}	
}

std::shared_ptr<Task> TaskManager::findTask(const std::string& title) const
{
	auto it = std::find_if(tasks.begin(), tasks.end(), [&title](const std::shared_ptr<Task>& task) {return task->getTitle() == title;});
	return (it != tasks.end()) ? *it : nullptr;
}

void TaskManager::displayTasks() const
{
	for (const auto& task : tasks)
	{
		task->display();
	}
}

void TaskManager::sortTasks()
{
	std::sort(tasks.begin(), tasks.end(), [](const std::shared_ptr<Task>& a, const std::shared_ptr<Task>& b) { return *a < *b;});
}

void TaskManager::filterTasks(const std::function<bool(const Task&)>& criteria) const
{
	for (const auto& task : tasks)
	{
		if (criteria(*task))
		{
			task->display();
		}
	}
}
