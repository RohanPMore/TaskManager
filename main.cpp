#include "TaskManager.h"
#include "Utilities.h"
#include <iostream>

int main()
{
	TaskManager manager;

	// Generate random tasks
	Utilities::generateRandomTasks(manager, 5);

	std::cout << "All Tasks: \n";
	manager.displayTasks();

	std::cout << "\nSorted Tasks:\n";
	manager.sortTasks();
	manager.displayTasks();

	std::cout << "\nHigh Priority Tasks (Priority > 5):\n";
	manager.filterTasks([](const Task& task) {return task.getPriority() > 5;});

	return 0;
}