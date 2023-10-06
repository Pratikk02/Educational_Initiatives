#include<bits/stdc++.h>
using namespace std;
class ToDoList {
public:
    void addTask(const string& title, const string& dueDate) 
    {
        tasks.push_back(title + " - Due: " + dueDate);
        taskStatus.push_back(false);                            // As initially, tasks are not completed
    }

     bool isEmpty() const                               //Function to check if tasks is empty
    {
        return tasks.empty();
    }

    int markasCompleted(const string& title)     //Function to mark the task as completed
    {       
        
        for (size_t i = 0; i < tasks.size(); ++i) 
        {
            if (tasks[i].find(title) != string::npos) 
            {
                taskStatus[i] = true;
                return 1;
            }
        }
    }

    bool delete_T(const string& title)                   //Function to delete a tasks
    {
        auto it = remove_if(tasks.begin(), tasks.end(),[title](const string& task) 
        {
            return task.find(title) != string::npos;
        });
        if (it != tasks.end()) 
        {
            tasks.erase(it);
            taskStatus.erase(taskStatus.begin() + (it - tasks.begin()));
        }
    }

    void viewtasks(const int& filter = 1)                    //Function to view all tasks according to filter
    {
        cout <<"\n\nList of Tasks:\n\n";
        for (size_t i = 0; i < tasks.size(); ++i) 
        {
            if (filter == 1 || (filter == 2 && taskStatus[i]) || (filter == 3 && !taskStatus[i])) 
            {
                cout<<i+1<<"\t"<<tasks[i] <<" - " <<(taskStatus[i] ? "Completed" : "Pending") <<"\n\n";
            }
        }
    }
    
private:
    vector<bool> taskStatus;        //storing status of all tasks
    vector<string> tasks;           //list of all tasks stored in a vector
};

int main()                                  // The MAIN function
{
    system("cls");
    ToDoList todoList;
    int choice;
    string title, dueDate;
    int filter;
start:
    while (true) {
        cout<<"\t\t\t";
        for (int i=0;i<12;i++)
            cout<<"-";
        for (int j=0;j<9;j++)
            cout<<"*";
        for (int h=0;h<12;h++)
            cout<<"-";
        cout<<"\n\n\n\t\t\t    Personal To-Do List Manager\n\n\n\t\t\t";
        for (int i=0;i<12;i++)
            cout<<"-";
        for (int j=0;j<9;j++)
            cout<<"*";
        for (int h=0;h<12;h++)
            cout<<"-";
        cout<<"\n\n\t1.   Add a Task\n" 
            <<"\t2.   Mark task Completed\n" 
            <<"\t3.   Delete a Task\n" 
            <<"\t4.   View all Tasks\n"
            <<"\t5.   Exit\n";
        cout <<"\n\t\tEnter a command: ";
        cin >> choice;

        switch (choice)
        {
        case 1 :                                                //To add a new task
            cout << "\nEnter the Task Title:\t";
            cin.ignore();
            getline(cin, title);
            cout << "Enter due date: ";
            cin >> dueDate;
            todoList.addTask(title, dueDate);
            break;
        case 2 :                                                //To mark a task as completed
            if (todoList.isEmpty())             //to check if list is empty or not                    
            {    
                cout<<"\nList is empty";
                cout<<"\n\nPlease Enter to continue to main menu...\n\n";
                cin.get();
                cin.get();
                _sleep(600);
                goto start;
            }
            cout << "\nEnter Task Title to mark as Completed:\t";
            cin.ignore();
            getline(cin, title);
            todoList.markasCompleted(title);
            if (todoList.markasCompleted(title) == 1)
            {
                cout <<"\nTask completed successfully!";
                cout<<"\n\nPlease Enter to continue to main menu...";
            }
            else
            {
                cout<<"\nTask not found";                       //if the task is not present in the list
                cout<<"\n\nPlease Enter to continue to main menu...";
            }
            cin.get();
            break;
        case 3 :                                                //To delete a certain task
            if (todoList.isEmpty())             //to check if list is empty or not
            {
                cout<<"\nList is empty.";
                cout<<"\n\nPlease Enter to continue to main menu...\n\n";
                cin.get();
                cin.get();
                _sleep(600);
                goto start;
            }
            cout <<"\nEnter Task Title to Delete:\t";          //if the task is not present in the list
            cin.ignore();
            getline(cin, title); 
            if (todoList.delete_T(title) == false)
            {
                cout<<"\nTask not found";
                cout<<"\n\nPlease Enter to continue to main menu...";
            }
            else
            {
                todoList.delete_T(title);
                cout <<"\nTask deleted successfully!";
                cout<<"\n\nPlease Enter to continue to main menu...";
            }
            cin.get();
            break;
        case 4 :                                                    //To view all the tasks accoring to filter
            cout <<"\nFilter Options: ";
            cout<<"\n\n1. All filters"
                <<"\n2. Completed"
                <<"\n3. Pending";                
            cout <<"\n\nEnter Filter (1/2/3):\t";
            cin >> filter;
              if (!todoList.isEmpty())
            {
                todoList.viewtasks(filter);
            }
            else cout<<"\n\tList is empty.";
            cout<<"\n\nPlease Enter to continue to main menu...";
            cin.get();
            cin.get();
            break;
        case 5:                                                     //To exit the program
            abort();
        default:                                                    //If invalid input is entered
            cout << "\nInvalid Command."<<"\n"<<"Try again.\n";
            _sleep(900);
            goto start;
            break;
        }
        _sleep(900);
        system("cls");
    }

    return 0;
}
