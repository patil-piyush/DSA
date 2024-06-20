#include <iostream>
using namespace std;

class Base
{
public:
    int x = 10;
    virtual void display()
    {
        cout << x << endl
             << "called base class" << endl;
    }

    /*
        1) ABOVE CODE EXPLAINS THE CONCEPT OF VIRTUAL FUNCTIONS  AND HOW TO USE IT.
        2) NOW WE ARE  GOING TO ADD A CONCEPT OF PURE VIRTUAL FUNCTIONS IN THIS STEP:
                WE NEED TO MODIFY THIS CODE AS:     virtual void display()=0;
                WE JUST ASSIGNED THE VALUE OF DISPLAY FUNCTION EQUAL TO ZERO, IT IS NOW A PURE VIRTUAL FUNCTION .
                IT MEANS THAT EVERY DERIVED CLASS OF BASE CLASS MUST HAVE A FUNCTION NAMED AS DISPLAY AND EVERYTIME YOU CALL THE DISPLAY FUNCTION BY USING BASE CLASS POINTER WHICH IS POINTNG TOWARDS OBJECT OF DERIVED CLASS IT WILL EXECUTE THE DISPLAY FUNCTION DEFINED IN THE DERIVED CLASS.
                AND BY CREATING THE PURE VIRTUAL FUNCTION IN BASE CLASS MAKES IT ABSTRACT CLASS

        3) ABSTRACT CLASS :
                ABSTRACT CLASS IS A CLASS WHICH CONTAINS AT LEAST ONE PURE VIRTUAL FUNCTION , AND IT ONLY USED TO INHERITE FEATURES OF BASE CLASS IN MANY DERIVED CLASSES
    */
};

class derivedFirst : public Base
{
public:
    int y = 100;
    void display()
    {
        cout << x << endl
             << y << endl
             << "called first derived class" << endl;
    }
};

class derivedSecond : public Base
{
public:
    int z = 200;
    void display()
    {
        cout << x << endl
             << z << endl
             << "called second derived class" << endl;
    }
};

int main()
{
    Base *objbase[2];
    derivedFirst objfirst;
    derivedSecond objsecond;
    objbase[0] = &objfirst;
    objbase[1] = &objsecond;
    objbase[0]->display();
    objbase[1]->display();
    return 0;
}