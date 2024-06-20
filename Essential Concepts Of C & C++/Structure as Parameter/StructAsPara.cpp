#include <iostream>
using namespace std;

/*
Structure as parameter , call by value
    struct Rectangle {
        int length;
        int breadth;
    };

    int area(struct Rectangle R){
        return (R.length) * (R.breadth);
    }
    int main(){
        struct Rectangle r = {10 , 5};
        cout<<area(r);
        return 0;
    }
*/

/*
Structure as parameter , call by refrence
    struct Rectangle {
        int length;
        int breadth;
    };

    int area(struct Rectangle &R){
        return (R.length) * (R.breadth);
    }
    int main(){
        struct Rectangle r = {10 , 5};
        cout<<area(r);
        return 0;
    }
*/

/*
Structure as parameter , call by Address
    struct Rectangle {
        int length;
        int breadth;
    };

    int area(struct Rectangle *R){
        return (R->length) * (R->breadth);
    }
    int main(){
        struct Rectangle r = {10 , 5};
        cout<<area(&r);
        return 0;
    }
*/

/*  Return rectangle as pointer  */

struct Rectangle
{
    int length;
    int breadth;
};

struct Rectangle *fun()
{
    Rectangle *p;
    p = new Rectangle;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length = 20;
    p->breadth = 10;
    return (p);
}
int main()
{
    struct Rectangle *r;
    r = fun();
    cout << r->length << endl;
    cout << r->breadth << endl;
    return 0;
}