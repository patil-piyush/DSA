#include <iostream>
using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle();
    Rectangle(int l, int b);
    int area();
    int perimeter();
    void setLength(int l)
    {
        length = l;
    }
    void setBreadth(int b)
    {
        breadth = b;
    }
    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
    }
    ~Rectangle() {}
};

Rectangle::Rectangle()
{
    length = 0;
    breadth = 0;
}
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

int main()
{
    Rectangle r(10,5);
    cout<<"area = "<<r.area()<<endl<<"Perimeter = "<<r.perimeter()<<endl;

    return 0;
}