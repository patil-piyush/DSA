#include<iostream>
using namespace std;

int main(){
    int n = 11;
    int a[n] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int h=a[n-1], l=a[0];
    int H[h]={0};

    for (int i = 0; i < n; i++)
    {
        H[a[i]]++;
    }
    for (int i = l; i < h; i++)
    {
        if(H[i]==0){
            cout<<i<<endl;
        }
    }

    return 0;
}