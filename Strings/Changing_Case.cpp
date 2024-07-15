#include <iostream>
using namespace std;

int main()
{
    char s[10];
    cin >> s;

    // for uppercase to lowercase
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = s[i] + 32;
        }
    }
    cout << s;

    // for lowercase to uppercase
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 32;
        }
    }
    cout << s;

    return 0;
}