#include<iostream>
using namespace std;

/*
call by address
    void swap(int x, int y){
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    int main(){
        int num1 = 10, num2 = 5;
        swap(num1, num2);
        cout<<"First number = "<<num1;
        cout << "Second number = " << num2;
        return 0;
    }
*/

/*
call by address
    void swap(int *x, int *y){
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    int main(){
        int num1 = 10, num2 = 5;
        swap(&num1, &num2);
        cout<<"First number = "<<num1;
        cout << "Second number = " << num2;
        return 0;
    }
*/

/*
call by Referance
    void swap(int &x, int &y){
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    int main(){
        int num1 = 10, num2 = 5;
        swap(num1, num2);
        cout<<"First number = "<<num1;
        cout << "Second number = " << num2;
        return 0;
    }
*/