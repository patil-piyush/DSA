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

struct matrix{
    int *a;
    int n;
};

void set(struct matrix *m, int i, int j, int x){
    if(i==j){
        m->a[i-1] = x;
    }
}

int get(struct matrix m, int i, int j){
    if(i==j){
        return m.a[i-1];
    }
    else{
        return 0;
    }
}

void display(struct matrix m){
    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){
            if(i==j){
                cout<<m.a[i-1]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
    

//Input function
void Input(struct matrix *m){
    cout<<"Enter the Dimension of array: ";
    cin>>m->n;
    //created a dynamic array
    m->a = new int[m->n];
    int y;
    cout<<"Enter the elements: ";
    for(int i=1; i<=m->n; i++){
        for(int j=1; j<=m->n; j++){
            cin>>y;
            set(m,i, j, y);
        }
    }

    cout<<endl<<endl;
}

int main(){
    struct matrix d;
    int i,j,y;
    while (1)
    {
        switch (Menu())
        {
        case 1:
            Input(&d);
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>y;
            cout<<"Enter the Index as i and j: ";
            cin>>i>>j;
            set(&d,i, j, y);
            cout<<endl<<endl;
            break;
        case 3:
            cout<<"Enter the Index as i and j: ";
            cin>>i>>j;
            get(d, i, j);
            cout<<endl<<endl;
            break;
        case 4:
            display(d);
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