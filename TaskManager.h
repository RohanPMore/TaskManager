#pragma once
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <memory>
#include <functional>

class TaskManager
{
private:
	std::vector<std::shared_ptr<Task>> tasks;

public:
	void addTask(const std::string& title, const std::string& description, int priority, const std::string& deadline);
	void removeTask(const std::string& title);
	std::shared_ptr<Task> findTask(const std::string& title) const;
	void displayTasks() const;
	void sortTasks();
	void filterTasks(const std::function<bool(const Task&)>& criteria) const;
};

#endif // !TASKMANAGER_H