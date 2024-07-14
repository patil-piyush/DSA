#include <iostream>
using namespace std;

int main()
{
    char s[]="How  are you?";
    int count = 1;


    //if there are no white spaces
    for (int i = 0; s[i] != '\0'; i++)
    {
       if(s[i]==' '){
        count++;
       }
    }

    // if there are white spaces
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i-1]!=' ')
        {
            count++;
        }
    }

    cout << "Words: " << count << endl;
    return 0;
}