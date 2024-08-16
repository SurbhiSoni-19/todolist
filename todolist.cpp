#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the to-do list." << std::endl;
            return;
        }

        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }

    void deleteTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            std::cout << "Task deleted: " << tasks[index - 1] << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoList toDoList;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore(); // Clear the newline character from the input buffer
            std::string task;
            std::cout << "Enter a new task: ";
            std::getline(std::cin, task);
            toDoList.addTask(task);
        } else if (choice == 2) {
            toDoList.viewTasks();
        } else if (choice == 3) {
            size_t taskNumber;
            std::cout << "Enter the task number to delete: ";
            std::cin >> taskNumber;
            toDoList.deleteTask(taskNumber);
        } else if (choice == 4) {
            std::cout << "Exiting the To-Do List Manager. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}