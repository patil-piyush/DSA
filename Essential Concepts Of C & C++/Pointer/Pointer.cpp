#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p; // declaration of pointer 'p'
    p = &a; // Pointing to variable 'a' / intialisation of 'p'
    cout << a << endl
         << *p; // Dereferencing

    /*
        // array using pointer

        int A[5] = {1, 2, 3, 4, 5}; // declaration and initialisation of an array
        int *p;                     // declaration of pointer
        p = A;                      // pointer pointing to the array
        for (int i = 0; i < 5; i++)
        {
            // cout<<A[i]<<endl; //accessing the data of array by simple method
            cout << p[i] << endl; // accessing the data of array using the pointer
        }
    */

    /*
        Lets create an array which will use the memory in Heap
            int *p; //declaration of pointer
            p = new int[5];
            //we have also implemented the dynamic memory allocation by using the keyword 'new' so we have to deallocate the memory at the end of the program by using 'delete' keyword
            p[0] = 10; p[1] = 11; p[2] = 12; p[3] = 13; p[4] = 14; //assigning the values
            for (int i = 0; i < 5; i++)
            {
                cout<<p[i]<<endl;   //accessing the data of array using the pointer
            }

            delete [ ] p;  //deleting the memory allocated to array
    */

    /*
        calculating the size of pointers of various data types
            int *p1;
            char *p2;
            float *p3;
            double p4;
            struct rectangle *p5;

            cout << sizeof(p1) << endl;
            cout << sizeof(p2) << endl;
            cout << sizeof(p3) << endl;
            cout << sizeof(p4) << endl;
            cout << sizeof(p5) << endl;

        all pointers are of size of 8 bytes
    */
    return 0;
}