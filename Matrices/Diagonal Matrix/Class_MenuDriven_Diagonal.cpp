#include<iostream>
using namespace std;

//Main Menu
int Menu()
{
    int n;
    cout << "Choose from the following options: " << endl
         << "1. Input Array." << endl
         << "2. Set Element." << endl
         << "3. Get Element." << endl
         << "4. Display Array." << endl
         << "5. Exit." << endl
         << "--------------------------------------------------------" << endl;
    cin >> n;
    return n;
}

class diagonal{
    private:
    int *a;
    int n;

    public:
    diagonal();
    diagonal(int n);
    ~diagonal();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    void Input();
};

diagonal::diagonal(){
    n = 2;
    a = new int[2];
}

diagonal::diagonal(int n){
    this->n = n;
    a = new int[n];
}

void diagonal::set(int i, int j, int x){
    if(i==j){
        a[i-1] = x;
    }
}

int diagonal::get(int i, int j){
    if(i==j){
        return a[i-1];
    }
    else{
        return 0;
    }
}

void diagonal::display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                cout<<a[i-1]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

diagonal::~diagonal(){
    delete []a;
}
    

//Input function
void diagonal::Input(){
    cout<<"Enter the Dimension of array: ";
    cin>>n;
    //created a dynamic array
    a = new int[n];
    int y;
    cout<<"Enter the elements: ";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>y;
            set(i, j, y);
        }
    }

    cout<<endl<<endl;
}

int main(){
    diagonal d;
    int i,j,y;
    while (1)
    {
        switch (Menu())
        {
        case 1:
            d.Input();
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>y;
            cout<<"Enter the Index as i and j: ";
            cin>>i>>j;
            d.set(i, j, y);
            cout<<endl<<endl;
            break;
        case 3:
            cout<<"Enter the Index as i and j: ";
            cin>>i>>j;
            cout<<d.get(i, j);
            cout<<endl<<endl;
            break;
        case 4:
            d.display();
            break;
        case 5:
            exit(0);
        default:
            cout<<"Incorrect choice ....... choose again!!"<<endl;
            break;
        }
    }
    
    return 0;
}