#include<iostream>
using namespace std;

class Base{
    public:
        int x = 10;
        virtual void display(){
            cout<<x<<endl<<"called base class"<<endl;
        }
};

class derivedFirst : public Base{
    public:
        int y = 100;
        void display(){
            cout<<x<<endl<<y<<endl<<"called first derived class"<<endl;
        }
};

class derivedSecond : public Base{
    public:
        int z = 200;
        void display(){
            cout<<x<<endl<<z<<endl<<"called second derived class"<<endl;
        }
};


int main(){
    Base* objbase[2];
    derivedFirst objfirst;
    derivedSecond objsecond;
    objbase[0] = &objfirst;
    objbase[1] = &objsecond;
    objbase[0]->display();
    objbase[1]->display();
    return 0;
}