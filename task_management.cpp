#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a structure to represent a task
struct Task {
    string name;
    string description;
    bool completed;
};

// Function to add a new task to the task list
void addTask(vector<Task>& tasks) {
    Task newTask;
    
    cout << "Enter task name: ";
    getline(cin >> ws, newTask.name);
    cout << "Enter task description: ";
    getline(cin >> ws, newTask.description);
    newTask.completed = false;

    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to display all tasks in the task list
void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "Task list is empty." << endl;
        return;
    }

    cout << "\nTasks:" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        cout << "Name: " << tasks[i].name << ", Description: " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [Completed]";
        } else {
            cout << " [Pending]";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    int taskIndex;

    do {
        cout << "\nTask Management System\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Ignore the newline character left by cin
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex);
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);
	return 0;
}