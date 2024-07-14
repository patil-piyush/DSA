#include<iostream>
using namespace std;

int main(){
    char a[10]="python";
    int i=0,j=0;

    //method 1 - using extra array
    char b[10];
    for (i = 0; a[i] != '\0'; i++){}
    i=i-1;

    for (j = 0; i>=0; j++,i--)
    {
        b[j]=a[i];
    }
    b[j]='\0';
    cout<<b;


    return 0;
}