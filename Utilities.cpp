#include "Utilities.h"
#include <cstdlib>

void Utilities::generateRandomTasks(TaskManager& manager, int count)
{
	static const std::vector<std::string> titles = { "Fix Bugs", "Write Report", "Team Meeting", "Code Review", "Plan Spirit"};
	static const std::vector<std::string> deadlines = { "2025-01-31", "2025-02-10", "2025-02-15", "2025-02-20", "2025-03-01" };

	for (int i = 0; i < count; ++i)
	{
		std::string title = titles[rand() % titles.size()];
		std::string description = "Description for " + title;
		int priority = rand() % 10 + 1;
		std::string deadline = deadlines[rand() % deadlines.size()];
		manager.addTask(title, description, priority, deadline);
	}
}