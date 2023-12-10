#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <conio.h>

int main() {
    std::vector<std::string> tasks;

    // Loading the tasks
    std::ifstream Load("save.txt");
    std::string task;
    while (std::getline(Load, task)) {
        tasks.push_back(task);
    }
    Load.close();


    while (true) {
        // Printing the tasks
        std::cout << "Your tasks:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }

        // Asking what to do
        int whattodo;
        std::cout << "\n\nType 1 to add a new task\nType 2 to remove a task\nType 3 to save and exit\n";

        while (!(std::cin >> whattodo) || (whattodo != 1 && whattodo != 2 && whattodo != 3)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1, 2, or 3: ";
        }

        switch (whattodo) {
        case 1: {
            system("cls");
            std::cin.ignore();

            std::string task;
            std::cout << "Enter the task: ";
            std::getline(std::cin, task);
            tasks.push_back(task);

            system("cls");
            break;
        }
        case 2: {
            system("cls");

            int taskIndex;
            std::cout << "Enter the index of the task to remove: ";
            std::cin >> taskIndex;
            while(taskIndex < 1 || static_cast<size_t>(taskIndex) > tasks.size()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid index. Please enter a valid index: ";
            }

            tasks.erase(tasks.begin() + taskIndex - 1);

            system("cls");
            break;
        }
        case 3: {
            std::ofstream Save;
            Save.open("save.txt");
            for (const std::string& task : tasks) {
                Save << task << '\n';
            }
            Save.close();
            return 0;
        }
        default:
            system("cls");
            break;
        }
    }

    return 0;
}
