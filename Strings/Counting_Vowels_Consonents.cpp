#include <iostream>
using namespace std;

int main()
{
    char s[10];
    int Vcount = 0, Ccount = 0;
    cin >> s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        //for vowels
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            Vcount++;
        }
        //for consonents
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            Ccount++;
        }
    }

    cout << "vowels: " << Vcount << endl;
    cout << "consonents: " << Ccount << endl;
    return 0;
}