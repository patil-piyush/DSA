#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {10, 5};
    struct Rectangle *p = &r; // pointer declaration + initialization

    // accessing data members by using '.' operator
    cout << r.length << endl;
    cout << r.breadth << endl;

    // accessing data members by using a pointer
    cout << p->length << endl;
    cout << p->breadth << endl;

    /*
    Allocating memory in Heap (Dynamic memory allocation)
        struct Rectangle *p;  //pointer declaration
        p = new Rectangle;  //dynamic allocation

        //accessing data members by using a pointer
        cout<<p->length<<endl;
        cout<<p->breadth<<endl;

    */

    return 0;
}