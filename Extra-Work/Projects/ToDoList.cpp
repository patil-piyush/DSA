#include<iostream>
#include<string>
using namespace std;

// prototyping of functions
void menu();
void addTask(int&, string[]);
void removeTask(int, string[], int&);
void showList(string[]);
int markDone(string[], string[], int, int);
void showDone(string[]);

int main(){
    string list[10], done[10];
    int count_task = 0, count_done = 0;

    while(1){
        menu();
        int menu_choice;
        cin >> menu_choice;

        switch (menu_choice){
            case 1:
                cout << "List created, you can add at most 10 tasks in the list.\n";
                break;
            case 2:
                if (count_task>0){
                    showList(list);
                }
                else{
                    cout<<"To-Do-List is empty\n";
                }
                break;
            case 3:
                if (count_task >= 10){
                    cout << "The list is full.\n";
                } 
                else {
                    addTask(count_task, list);
                }
                break;
            case 4:
                int n; 
                cout << "Enter the number of the task that you want to remove: ";
                cin >> n;
                removeTask(n - 1, list, count_task);
                break;
            case 5:
                int m;
                cout << "Enter the number of the task that you want to mark as done: ";
                cin >> m;
                count_done = markDone(list, done, m - 1, count_done);
                break;
            case 6:
                if(count_done>0){
                    showDone(done);
                }
                else{
                    cout<<"None of the task is completed\n";
                }
                break;
            case 7:
                cout << "Exiting the program.\n";
                exit(0);
            default:
                cout << "Invalid choice, choose again\n";
                break;
        }
    }

    return 0;
}

// Defining the functions
void menu(){
    cout << "Choose your option from the following list: \n"
         << "1. Create a To-Do-List\n"
         << "2. Show the list\n"
         << "3. Add a task in list\n"
         << "4. Remove a task from the list\n"
         << "5. Mark the task as completed\n"
         << "6. Show completed tasks\n"
         << "7. Exit\n"
         << "\t\tYour Choice: ";
}

void showList(string List[]){
    cout << "Your To-Do-List is:\n";
    for (int i = 0; i < 10; i++) {
        if (!List[i].empty()) {
            cout << i + 1 << ". " << List[i] << endl;
        }
    }
    cout<<"---------------------------------------------------------------------------------\n";
}

void addTask(int& count, string list[]){
    cin.ignore();  // Consume the newline character
    cout << "Enter the task: ";
    getline(cin, list[count]);
    count++;
}

void removeTask(int n, string list[], int& count){
    list[n] = " ";
    for (int i = n; i < 9; i++) {
        list[i] = list[i + 1];
    }
    count--;  
}

int markDone(string list[], string done[], int n, int count_done){
    done[count_done] = list[n];
    count_done++;
    return count_done;
}

void showDone(string List[]){
    cout << "Completed tasks:\n";
    for (int i = 0; i < 10; i++) {
        if (!List[i].empty()) {
            cout << i + 1 << ". " << List[i] << endl;
        }
    }
    cout<<"---------------------------------------------------------------------------------\n";
}
