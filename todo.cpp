#include <iostream>
#include <list>

using namespace std;

int main() {
    list<string> tasks;

    while (true) {
        cout << "Your tasks:\n";
        int i = 0;
        for (string task : tasks) {
            cout << i << ". " << task << "\n"; // printing tasks
            i++;
        }

        int whattodo;
        cout << "\n\nType 1 to add a new task\nType 2 to remove a task\nType 3 to exit\n";
        cin >> whattodo;

        switch (whattodo) {
        case 1: {
            system("cls");

            // get a new task
            string task;
            cout << "Enter the task: ";
            cin.ignore();
            getline(cin, task);
            
            // add a new task
            tasks.push_back(task);
            
            system("cls");
            break;
        }
        case 2: {
            system("cls");

            // get the index
            int taskIndex;
            cout << "Enter the index of the task to remove: ";
            cin >> taskIndex;
            
            // Check if the index is valid
            if (taskIndex >= 0 && static_cast<size_t>(taskIndex) < tasks.size()) {
                auto it = tasks.begin();
                advance(it, taskIndex);
                tasks.erase(it);
            }

            system("cls");
            break;
        }
        case 3:
            return 0;
        default:
            system("cls");
            break;
        }
    }

    return 0;
}
