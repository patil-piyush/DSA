#include<iostream>
using namespace std;


int valid(char s[]){
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main(){
    //it is used in various login pages to check whether the entered password is valid or not
    //validation condition - the string is valid only if it contains only letters and numbers
    char s[] = "Howndscn?";

    if(valid(s)){
        cout<<"valid"<<endl;
    }
    else{
        cout<<"invalid"<<endl;
    }
    return 0;
}