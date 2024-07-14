#include <iostream>
using namespace std;

int main()
{
    char a[] = "Piyush";
    char b[] = "Piyush";
    int i = 0, j = 0;
    
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
        cout << "equal" << endl;
    else if (a[i] > b[j])
        cout << "smaller" << endl;
    else
        cout << "Greater" << endl;
    return 0;
}