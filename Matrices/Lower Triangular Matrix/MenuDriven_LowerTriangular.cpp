#include <iostream>
using namespace std;

// Main Menu
int Menu()
{
    int n;
    cout << "Choose from the following options: " << endl
         << "1. Input Array." << endl
         << "2. Set Element." << endl
         << "3. Get Element." << endl
         << "4. Display Array." << endl
         << "5. Back." << endl
         << "6. Exit." << endl
         << "--------------------------------------------------------" << endl;
    cin >> n;
    return n;
}

struct matrix
{
    int *a;
    int n;
};

// all functions for row major
//  set function for row major
void Rowset(struct matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->a[i * (i - 1) / 2 + j - 1] = x;
    }
}

// get function for row major
int Rowget(struct matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.a[i * (i - 1) / 2 + j - 1];
    }
    else
    {
        return 0;
    }
}

// display function for row major
void Rowdisplay(struct matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                cout << m.a[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Input function for row major
void RowInput(struct matrix *m)
{
    cout << "Enter the Dimension of array: ";
    cin >> m->n;
    // created a dynamic array
    m->a = new int[m->n];
    int Element;
    cout << "Enter the elements: ";
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            cin >> Element;
            Rowset(m, i, j, Element);
        }
    }

    cout << endl
         << endl;
}

// all functions for column major
// set function for column major
void Colset(struct matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->a[m->n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = x;
    }
}

// get function for column major
int Colget(struct matrix m, int i, int j)
{
    if (i >= j)
    {
        return m.a[m.n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];
    }
    else
    {
        return 0;
    }
}

// display function for column major
void Coldisplay(struct matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
            {
                cout << m.a[m.n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Input function for column major
void ColInput(struct matrix *m)
{
    cout << "Enter the Dimension of array: ";
    cin >> m->n;
    // created a dynamic array
    m->a = new int[m->n];
    int Element;
    cout << "Enter the elements: ";
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            cin >> Element;
            Colset(m, i, j, Element);
        }
    }

    cout << endl
         << endl;
}

int main()
{
    struct matrix d;
    int i, j, Element, sideMenu;
    cin >> sideMenu;
    while (1)
    {
        cout << "Choose from the following options: " << endl
             << "1. Row Major Representation." << endl
             << "2. Column Major Representation." << endl
             << "3. Exit." << endl
             << "--------------------------------------------------------" << endl;
        switch (sideMenu)
        {
        case 1:
            switch (Menu())
            {
            case 1:
                RowInput(&d);
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> Element;
                cout << "Enter the Index as i and j: ";
                cin >> i >> j;
                Rowset(&d, i, j, Element);
                cout << endl
                     << endl;
                break;
            case 3:
                cout << "Enter the Index as i and j: ";
                cin >> i >> j;
                Rowget(d, i, j);
                cout << endl
                     << endl;
                break;
            case 4:
                Rowdisplay(d);
                break;
            case 5:
                break;
            case 6:
                exit(0);
            default:
                cout << "Incorrect choice ....... choose again!!" << endl;
                break;
            }

            break;
        case 2:
            switch (Menu())
            {
            case 1:
                ColInput(&d);
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> Element;
                cout << "Enter the Index as i and j: ";
                cin >> i >> j;
                Colset(&d, i, j, Element);
                cout << endl
                     << endl;
                break;
            case 3:
                cout << "Enter the Index as i and j: ";
                cin >> i >> j;
                Colget(d, i, j);
                cout << endl
                     << endl;
                break;
            case 4:
                Coldisplay(d);
                break;
            case 5:
                break;
            case 6:
                exit(0);
            default:
                cout << "Incorrect choice ....... choose again!!" << endl;
                break;
            }
            break;
        case 3:
            exit(0);
        default:
            cout << "Incorrect choice ....... choose again!!" << endl;
            break;
        }
    }

    return 0;
}