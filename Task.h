#pragma once
#ifndef TASK_H
#define TASK_H

#include<string>
#include<iostream>
#include<memory>

class Task {
private:
	std::string title;
	std::string description;
	int priority;	// Higher number = higher priority
	std::string deadline; // Format: "dd/mm/yyyy"

public:
	Task(const std::string& title, const std::string& description, int priority, const std::string& deadline);

	// Getters
	std::string getTitle() const;
	std::string getDescription() const;
	int getPriority() const;
	std::string getDeadline() const;

	//Display task details
	void display() const;

	// Overload < operator for sorting by priority and deadling
	bool operator<(const Task& other) const;
};

#endif // !TASK_H	