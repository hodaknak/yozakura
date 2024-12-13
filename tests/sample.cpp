// Sample C++ Code: Simple CLI To-Do App
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Task {
    std::string text;
    bool completed;

    Task(const std::string& t) : text(t), completed(false) {}
};

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "\nTo-Do List:" << std::endl;
    if (tasks.empty()) {
        std::cout << "  No tasks yet!" << std::endl;
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << "  " << (i + 1) << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].text << std::endl;
        }
    }
}

void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter a task: ";
    std::string taskText;
    std::getline(std::cin, taskText);
    if (!taskText.empty()) {
        tasks.emplace_back(taskText);
        std::cout << "Task added!" << std::endl;
    } else {
        std::cout << "Task cannot be empty." << std::endl;
    }
}

void deleteTask(std::vector<Task>& tasks) {
    std::cout << "Enter task number to delete: ";
    int taskNum;
    std::cin >> taskNum;
    std::cin.ignore(); // Consume newline
    if (taskNum > 0 && static_cast<size_t>(taskNum) <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        std::cout << "Task deleted!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void toggleTaskCompletion(std::vector<Task>& tasks) {
    std::cout << "Enter task number to toggle completion: ";
    int taskNum;
    std::cin >> taskNum;
    std::cin.ignore(); // Consume newline
    if (taskNum > 0 && static_cast<size_t>(taskNum) <= tasks.size()) {
        tasks[taskNum - 1].completed = !tasks[taskNum - 1].completed;
        std::cout << "Task status updated!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    while (true) {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "  1. View tasks" << std::endl;
        std::cout << "  2. Add task" << std::endl;
        std::cout << "  3. Delete task" << std::endl;
        std::cout << "  4. Toggle task completion" << std::endl;
        std::cout << "  5. Exit" << std::endl;

        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Consume newline

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                toggleTaskCompletion(tasks);
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
