#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Todo {
    int id;
    string task;
};

int ID = 0;

void addTodo() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    Todo todo;
    cout << "\n\tEnter new task: ";
    cin.ignore();
    getline(cin, todo.task);
    ID++;

    ofstream write("todo.txt", ios::app);
    write << "\n" << ID << "\n" << todo.task;
    write.close();

    ofstream idWrite("id.txt");
    idWrite << ID;
    idWrite.close();

    char ch;
    cout << "Do you want to add more tasks? (y/n): ";
    cin >> ch;

    if (ch == 'y') {
        addTodo();
    }
    else {
        cout << "\n\tTask has been added successfully";
    }
}

void print(const Todo& s) {
    cout << "\n\tID is: " << s.id;
    cout << "\n\tTask is: " << s.task;
}

void readData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    Todo todo;
    ifstream read("todo.txt");

    cout << "\n\t------------------Your current Tasks in the list--------------------";

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        print(todo);
    }
    read.close();
}

int searchData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int id;
    cout << "\n\tEnter task id: ";
    cin >> id;

    Todo todo;
    ifstream read("todo.txt");

    while (!read.eof()) {
        read >> todo.id;
        read.ignore();
        getline(read, todo.task);
        if (todo.id == id) {
            print(todo);
            return id;
        }
    }
    return -1; // Return -1 if task not found
}

void deleteData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int id = searchData();
    if (id == -1) {
        cout << "\n\tTask not found.";
        return;
    }

    cout << "\n\tDo you want to delete this task (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        Todo todo;
        ofstream tempFile("temp.txt");
        ifstream read("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id << "\n" << todo.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask deleted successfully";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    int id = searchData();
    if (id == -1) {
        cout << "\n\tTask not found.";
        return;
    }

    cout << "\n\tYou want to update this task (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        Todo newData;
        cout << "\n\tEnter todo task: ";
        cin.ignore();
        getline(cin, newData.task);

        Todo todo;
        ofstream tempFile("temp.txt");
        ifstream read("todo.txt");

        while (!read.eof()) {
            read >> todo.id;
            read.ignore();
            getline(read, todo.task);
            if (todo.id != id) {
                tempFile << "\n" << todo.id << "\n" << todo.task;
            }
            else {
                tempFile << "\n" << todo.id << "\n" << newData.task;
            }
        }
        read.close();
        tempFile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "\n\tTask updated successfully";
    }
    else {
        cout << "\n\tRecord not updated";
    }
}

int main() {
    system("cls");
    system("title todoapp @copyassignment");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t*                      WELCOME TO Your ToDo List                      *" << endl;
    cout << "\t\t\t*                                                                     *" << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl << endl;

    ifstream read("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    read.close();

    while (true) {
        cout << endl << endl;
        cout << "\n\t1. Add task";
        cout << "\n\t2. See tasks";
        cout << "\n\t3. Search task";
        cout << "\n\t4. Delete task";
        cout << "\n\t5. Update task";
        cout << "\n\t6. Exit";

        int choice;
        cout << "\n\tEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
