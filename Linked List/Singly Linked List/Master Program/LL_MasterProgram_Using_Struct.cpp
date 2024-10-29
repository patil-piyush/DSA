#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first, *second, *third;

void createfirst(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = 0;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

void createsecond(int a[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = a[0];
    second->next = 0;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

// simple count function for counting nodes of a linked list
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// recursive count function for counting nodes of a linked list
int Rcount(struct Node *p)
{
    if (p != 0)
    {
        return Rcount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

// simple display function for displaying linked list
void DisplayLL(struct Node *p)
{
    while (p != 0)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

// recursive display function for displaying linked list
void RDisplayLL(struct Node *p)
{
    if (p != 0)
    {
        cout << p->data << endl;
        RDisplayLL(p->next);
    }
}

// function for deleting a node
int DeleteNode(struct Node *p, int pos)
{
    Node *c, *q;
    int x = -1, i;
    if (pos < 1 || pos > count(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        c = first;
        first = first->next;
        x = c->data;
        delete c;
        return x;
    }
    else
    {
        c = first;
        q = nullptr;

        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// function for checking whether the linked list is sorted or not
bool isSorted(struct Node *p)
{
    int x = INT8_MIN;

    while (p)
    {
        if (p->data < x)
        {
            return false;
        }
        else
        {
            x = p->data;
            p = p->next;
        }
    }
    return true;
}

// function for removing the duplicates from the sorted linked list
void RemoveDuplicates(struct Node *p)
{
    p = first;
    Node *q = first->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Function for inserting a node in a sorted linked list
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q;
    q = NULL;

    t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Insert function for inserting a node in a linked list
int Insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > count(p))
        return 0;
    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1 && p; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// simple function for finding max element of a linked list
int max(struct Node *p)
{
    int m = INT32_MIN;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// recursive function for finding max element of a linked list
int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    x = Rmax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

// simple function for finding min element of a linked list
int min(struct Node *p)
{
    int m = INT32_MAX;
    while (p)
    {
        if (p->data < m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

// recursive function for finding min element of a linked list
int Rmin(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MAX;
    }
    x = Rmin(p->next);
    if (x < p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

// simple function for counting sum of elements of a linked list
int sum(struct Node *p)
{
    int s = 0;
    while (p)
    {
        s = s + p->data;
        p = p->next;
    }
    return s;
}

// recursive function for counting sum of elements of a linked list
int Rsum(struct Node *p)
{
    if (p != 0)
    {
        return Rsum(p->next) + p->data;
    }
    else
    {
        return 0;
    }
}

// reversing the linked list Method 1
// it uses a array of size equal to the size of linked list
// firstly traverse the LL and copy the elements from LL to the array
// while traversing second time copy the elements from array to LL in reverse order
void ReverseElements1(struct Node *p)
{

    int *arr = new int[sizeof(int) * count(p)];
    Node *q = p, *temp;
    int i = 0;
    while (q)
    {
        arr[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q)
    {
        q->data = arr[i];
        q = q->next;
        i--;
    }
}

// Reversing the LL method 2 -
// Reversing it by using 3 sliding pointers
void ReverseElements2(struct Node *p)
{
    Node *current = nullptr;
    Node *prev = nullptr;

    while (p)
    {
        prev = current;
        current = p;
        p = p->next;
        current->next = prev;
    }
    first = current;
}

// Reversing the LL method 3 -
// Reversing it by using Recursion
void ReverseElements3(struct Node *q, struct Node *p)
{
    if (p)
    {
        ReverseElements3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

// Function for concatenating two lists
void Concatenate(struct Node *p, struct Node *q)
{
    while (p->next)
    {
        p = p->next;
    }
    p->next = second;
}

// Function for Merging two linked list
void MergeLL(struct Node *p, struct Node *q)
{
    Node *last;
    // comparing first node of two linked list and making it first node of merged list
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    // merging all nodes after the first node
    while (first && second)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    // merging remaining nodes
    if (first)
        last->next = first;
    else
        last->next = second;
}


// Function for finding the existance of loop in the LL
int isLoop(Node *f){
    Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        if(q){
            q=q->next;            
        }
    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}


int main()
{
    int choice, index, value, n;

    // Input for the linked list
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;
    int *a = new int[n];
    cout << "Enter the elements of the linked list: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    createfirst(a, n);  // Creating the linked list from user input

    while (1)  // Infinite loop for menu-driven program
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Display Linked List\n";
        cout << "2. Count Nodes\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Node\n";
        cout << "5. Reverse Linked List (Using Array)\n";
        cout << "6. Reverse Linked List (Using Pointers)\n";
        cout << "7. Reverse Linked List (Using Recursion)\n";
        cout << "8. Check if List is Sorted\n";
        cout << "9. Find Max Element\n";
        cout << "10. Find Min Element\n";
        cout << "11. Sum of Elements\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Linked List: \n";
            DisplayLL(first);
            break;

        case 2:
            cout << "Number of nodes: " << count(first) << endl;
            break;

        case 3:
            cout << "Enter index to insert: ";
            cin >> index;
            cout << "Enter value to insert: ";
            cin >> value;
            Insert(first, index, value);
            break;

        case 4:
            cout << "Enter position to delete node: ";
            cin >> index;
            value = DeleteNode(first, index);
            if (value != -1)
                cout << "Deleted element: " << value << endl;
            else
                cout << "Invalid position!" << endl;
            break;

        case 5:
            cout << "Reversing Linked List using Array...\n";
            ReverseElements1(first);
            break;

        case 6:
            cout << "Reversing Linked List using Pointers...\n";
            ReverseElements2(first);
            break;

        case 7:
            cout << "Reversing Linked List using Recursion...\n";
            ReverseElements3(NULL, first);
            break;

        case 8:
            if (isSorted(first))
                cout << "The linked list is sorted.\n";
            else
                cout << "The linked list is not sorted.\n";
            break;

        case 9:
            cout << "Maximum element: " << max(first) << endl;
            break;

        case 10:
            cout << "Minimum element: " << min(first) << endl;
            break;

        case 11:
            cout << "Sum of elements: " << sum(first) << endl;
            break;

        case 12:
            cout << "Exiting the program...\n";
            exit(0);  // Exiting the program

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}    