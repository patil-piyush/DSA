#include<iostream>
using namespace std;

int main(){
    int n = 11;
    int a[n] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int LastDuplicate = 0;
    for(int i=0; i<n; i++){
        if(LastDuplicate != a[i] && a[i] == a[i+1]){
            cout<<a[i]<<endl;
            LastDuplicate=a[i];
        }
    }
    return 0;
}