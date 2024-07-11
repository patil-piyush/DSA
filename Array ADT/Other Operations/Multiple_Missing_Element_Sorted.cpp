#include<iostream>
using namespace std;

int main(){
    int n = 11;
    int a[n] = {6,7,8,9,11,12,15,16,17,18,19};
    int l = a[0];
    int diff = l - 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            while (diff<a[i]-i)
            {
                cout<<i+diff;
                diff++;
            }
            
        }
    }
    return 0;
}