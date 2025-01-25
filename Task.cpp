#include "Task.h"

Task::Task(const std::string& title, const std::string& description, int priority, const std::string& deadline):title(title), description(description), priority(priority), deadline(deadline) {}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
std::string Task::getDeadline() const { return deadline; }

void Task::display() const
{
	std::cout << "Title: " << title << "\n";
	std::cout << "Description: " << description << "\n";
	std::cout << "Priority: " << priority << "\n";
	std::cout << "Deadline: " << deadline << "\n";
}

bool Task::operator<(const Task& other) const
{
	if (priority != other.priority)
	{
		return priority > other.priority;	//Higher priority first
	}
	return deadline < other.deadline;	//Earlier deadline first
}