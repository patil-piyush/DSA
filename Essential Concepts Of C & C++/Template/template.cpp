#include <iostream>
using namespace std;
template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> x(10, 20);
    Arithmetic<float> y(1.1, 2.2);
    cout << x.add() << endl
         << x.sub() << endl;
    cout << y.add() << endl
         << y.sub() << endl;
    return 0;
}