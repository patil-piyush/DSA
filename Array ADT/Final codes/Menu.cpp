#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

// Function prototypes
void display(struct Array a);
void append(struct Array *arr, int x);
int average(struct Array arr);
int BinSearch(struct Array arr, int key);
int Delete(struct Array *arr, int index);
int get(struct Array arr, int index);
void set(struct Array *arr, int index, int x);
void Insert(struct Array *arr, int index, int x);
void SortedInsert(struct Array *arr, int x);
int LinearSearch(struct Array arr, int key);
void Merge(struct Array first, struct Array second, struct Array *third);
int max(struct Array arr);
int min(struct Array arr);
void sortInt(struct Array *arr);
void Reverse(struct Array *arr);
void LeftRotation(struct Array *arr);
void RightRotation(struct Array *arr);
void LeftShift(struct Array *arr);
void RightShift(struct Array *arr);
bool CheckSort(struct Array arr);
int sum(struct Array arr);
void swap(int *x, int *y);

// function definations

// 1.Display Function
void display(struct Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        cout << a.A[i] << " ";
    }
    cout << endl;
}
// 2.Append Function
void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}
// 3.Average Function
int average(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum / arr.length;
}
// 4.Binary Search
int BinSearch(struct Array arr, int key)
{
    int l = 0;
    int h = arr.length;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
// 5.Delete Function
int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return x;
}
// 6.Get function
int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}
// 7.set function
void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}
// 8.insert function
void Insert(struct Array *arr, int index, int x)
{
    if (arr->length < arr->size && index >= 0)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
// 9.insert function for sorted array
void SortedInsert(struct Array *arr, int x)
{
    int i = arr->length - 1;
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
// 10.linear search
int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}
// 11.function for merging
void Merge(struct Array first, struct Array second, struct Array *third)
{
    third->size = first.size + second.size;
    third->length = 0;
    int i, j, k;
    i = j = k = 0;
    while (i < first.length && j < second.length)
    {
        if (first.A[i] > second.A[j])
        {
            third->A[k++] = second.A[j++];
        }
        else if (first.A[i] < second.A[j])
        {
            third->A[k++] = first.A[i++];
        }
        else
        {
            third->A[k++] = second.A[j++];
            i++;
        }
    }

    for (; i < first.length; i++)
    {
        third->A[k++] = first.A[i];
    }
    for (; j < second.length; j++)
    {
        third->A[k++] = second.A[j];
    }
    third->length = k;
}
// 12.max function
int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i];
        }
    }
    return max;
}
// 13.min function
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    return min;
}
// 14.function for arranging Positive numbers on right and negative numbers on left
void sortInt(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr->A[i], arr->A[j]);
        }
    }
}
// 15.Reverse Function
void Reverse(struct Array *arr)
{
    int temp;
    for (int i = 0; i < arr->length / 2; i++)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[arr->length - 1 - i];
        arr->A[arr->length - 1 - i] = temp;
    }
}
// 16.Left Rotation
void LeftRotation(struct Array *arr)
{
    arr->A[arr->length] = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
}
// 17.Right Rotation
void RightRotation(struct Array *arr)
{
    for (int i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = arr->A[arr->length];
}
// 18.Left shift
void LeftShift(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

// 19.Right shift
void RightShift(struct Array *arr)
{
    int i;
    for (i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[i] = 0;
    arr->length++;
}
// 20.function for checking if array is sorted or not
bool CheckSort(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}
// 21.sum function
int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}
// 22.swap Function
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// 23.Menu printer
int Menu()
{
    int n;
    cout << "Choose from the following options: " << endl
         << "1. Input Array." << endl
         << "2. Choose operation." << endl
         << "3. Exit." << endl
         << "--------------------------------------------------------" << endl;
    cin >> n;
    return n;
}
// 24.Printing Operations
int Opr()
{
    cout << "Choose one operations from the following options: " << endl
         << "1. Display." << endl
         << "2. Append an element." << endl
         << "3.Average." << endl
         << "4.Searching." << endl
         << "5.Delete an element." << endl
         << "6.Display an element." << endl
         << "7.Replace an element." << endl
         << "8.Insert an element." << endl
         << "9.Insert an element in sorted array." << endl
         << "10.Merge." << endl
         << "11.Find Minimum element." << endl
         << "12.Find Maximum element." << endl
         << "13.Arrange elements in order as positive negative." << endl
         << "14.Reverse." << endl
         << "15.Left Rotation." << endl
         << "16.Right Rotation." << endl
         << "17.Left Shift." << endl
         << "18.Right Shift." << endl
         << "19.Check If array is sorted or not." << endl
         << "20.Sum of all elements." << endl
         << "Back" << endl
         << "Exit." << endl
         << "--------------------------------------------------------" << endl;
    int n;
    cin >> n;
    return n;
}

int main()
{
    // declaration of 3 objects of struct Array to input the aarays and performing operations on them
    struct Array first;
    struct Array second;
    struct Array third;
    int ch1, ch2;
    ch1 = ch2 = 0;
    while (ch1 == 0)
    {
        // switch case for main menu
        switch (Menu())
        {
            // storing array data from user
            // Taking input from user
            case 1:
                cout << "Choose The array for storing data: " << endl
                    << "1. Array 'A'" << endl
                    << "2. Array 'B'" << endl
                    << "3. Back." << endl
                    << "--------------------------------------------------------" << endl;
                int InputChoice;
                cin >> InputChoice;
                switch (InputChoice)
                {
                    case 1:
                        // taking input for First array
                        cout << "Enter the size: ";
                        cin >> first.size;
                        first.A = new int[first.size];
                        first.length = 0;

                        int n;
                        cout << "enter the number of elements: ";
                        cin >> n;
                        cout << "enter the elements: ";
                        for (int i = 0; i < n; i++)
                        {
                            cin >> first.A[i];
                        }
                        first.length = n;
                        break;

                    case 2:
                        // taking input for second array
                        cout << "Enter the size: ";
                        cin >> second.size;
                        second.A = new int[second.size];
                        second.length = 0;

                        cout << "enter the number of elements: ";
                        cin >> n;
                        cout << "enter the elements: ";
                        for (int i = 0; i < n; i++)
                        {
                            cin >> second.A[i];
                        }
                        second.length = n;
                        break;

                    case 3:
                        break;

                    default:
                        cout << "Choice is Invalid !!...Try Again";
                        break;
                }
                break;
            // End of Taking input from user

            // Choosing operation to perform
            case 2:
                switch (Opr())
                {
                    // Display function
                    case 1:
                        cout << "Choose The array to display: " << endl
                            << "1. Array 'A'" << endl
                            << "2. Array 'B'" << endl
                            << "3. Back." << endl
                            << "--------------------------------------------------------" << endl;
                        int DisplayChoice;
                        cin>>DisplayChoice;
                        switch (DisplayChoice)
                        {
                            case 1:
                                cout<<"Elements of Array A:"<<endl;
                                display(first);
                                cout << "--------------------------------------------------------" << endl;
                                break;
                            case 2:
                                cout << "Elements of Array B:" << endl;
                                display(second);
                                cout << "--------------------------------------------------------" << endl;
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Choice is Invalid !!...Try Again";
                                break;
                        }
                        break;

                    // Append Function
                    case 2:
                        cout << "Choose The array to Append element: " << endl
                            << "1. Array 'A'" << endl
                            << "2. Array 'B'" << endl
                            << "3. Back." << endl
                            << "--------------------------------------------------------" << endl;
                        int AppendChoice;
                        cin>>AppendChoice;
                        cout << "Enter The element to append";
                        int AppendElement;
                        cin >> AppendElement;
                        switch (AppendChoice)
                        {
                            case 1:
                                append(&first, AppendElement);
                                cout << "Element is appended successfully in array A"<<endl
                                     <<"--------------------------------------------------------" << endl;
                                break;
                            case 2:
                                append(&second, AppendElement);
                                cout << "Element is appended successfully in array B" << endl
                                     << "--------------------------------------------------------" << endl;
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Choice is Invalid !!...Try Again";
                                break;
                        }
                        break;

                    // Average Function
                    case 3:
                        cout << "Choose The array to find average of the same: " << endl
                            << "1. Array 'A'" << endl
                            << "2. Array 'B'" << endl
                            << "3. Back." << endl
                            << "--------------------------------------------------------" << endl;
                        int AverageChoice;
                        cin >> AverageChoice;
                        switch (AverageChoice)
                        {
                            case 1:
                                cout<<"Average of elements of A is: "<<average(first)<<endl
                                    << "--------------------------------------------------------" << endl;
                                break;
                            case 2:
                                cout << "Average of elements of A is: " << average(second) << endl
                                     << "--------------------------------------------------------" << endl;
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Choice is Invalid !!...Try Again";
                                break;
                        }
                        break;

                    //searching operations
                    case 4:
                        cout << "Choose The array to find for searching operation: " << endl
                            << "1. Array 'A'" << endl
                            << "2. Array 'B'" << endl
                            << "3. Back." << endl
                            << "--------------------------------------------------------" << endl;
                        int SearchChoice;
                        switch (SearchChoice)
                        {
                            // searching for first array
                            case 1:
                                cout << "Choose Type of searching operation: " << endl
                                    << "1. Linear Search" << endl
                                    << "2. Binary Search" << endl
                                    << "3. Back." << endl
                                    << "--------------------------------------------------------" << endl;
                                int OprChoice;
                                cin >> OprChoice;
                                cout << "Enter The element to Search: ";
                                int SearchElement;
                                cin >> SearchElement;
                                switch (OprChoice)
                                {
                                    case 1:
                                        cout << "Element is present at index: ";
                                        LinearSearch(first,SearchElement);
                                        cout<<"Found by using linear search";
                                        break;
                                    case 2:
                                        cout<<"Element is present at index: ";
                                        BinSearch(first, SearchElement);
                                        cout << "Found by using Binary search";
                                        break;
                                    default:
                                        cout << "Choice is Invalid !!...Try Again";
                                        break;
                                }
                                break;

                            // searching for second array
                            case 2:
                                cout << "Choose Type of searching operation: " << endl
                                    << "1. Linear Search" << endl
                                    << "2. Binary Search" << endl
                                    << "3. Back." << endl
                                    << "--------------------------------------------------------" << endl;
                                cin >> OprChoice;
                                cout << "Enter The element to Search";
                                cin >> SearchElement;
                                switch (OprChoice)
                                {
                                    case 1:
                                        LinearSearch(second, SearchElement);
                                        break;
                                    case 2:
                                        BinSearch(second, SearchElement);
                                        break;
                                    default:
                                        cout << "Choice is Invalid !!...Try Again";
                                        break;
                                }
                                break;

                            case 3:
                                break;
                                
                            default:
                                cout << "Choice is Invalid !!...Try Again";
                                break;
                        }
                        break;
                        // end of searching operation

                    //Delete Operation
                    case 5:
                        cout << "Choose The array to Delete element: " << endl
                             << "1. Array 'A'" << endl
                             << "2. Array 'B'" << endl
                             << "3. Back." << endl
                             << "--------------------------------------------------------" << endl;
                        int DeleteChoice;
                        cout << "Enter The index of the element to Delete";
                        int DeleteIndex;
                        cin >> DeleteIndex;
                        switch (DeleteChoice)
                        {
                            case 1:
                                Delete(&first, DeleteIndex);
                                break;
                            case 2:
                                Delete(&second, DeleteIndex);
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Choice is Invalid !!...Try Again";
                                break;
                        }
                        break;
                        //end of delete operation

                    //Get operation
                    case 6:
                        cout << "Choose The array to get element from: " << endl
                             << "1. Array 'A'" << endl
                             << "2. Array 'B'" << endl
                             << "3. Back." << endl
                             << "--------------------------------------------------------" << endl;
                        int GetChoice;
                        cout << "Enter The index of the element to get";
                        int GetIndex;
                        cin >> GetIndex;
                        switch (GetChoice)
                        {
                        case 1:
                            get(first, GetIndex);
                            break;
                        case 2:
                            get(second, GetIndex);
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Choice is Invalid !!...Try Again";
                            break;
                        }
                        break;
                        // end of get operation

                    // Set operation
                    case 7:
                        cout << "Choose The array to set element : " << endl
                             << "1. Array 'A'" << endl
                             << "2. Array 'B'" << endl
                             << "3. Back." << endl
                             << "--------------------------------------------------------" << endl;
                        int SetChoice;
                        int SetIndex;
                        int SetElement;
                        cout << "Enter The element to set";
                        cin>>SetElement;
                        cout << "Enter The index of the element to set";
                        cin >> SetIndex;
                        switch (SetChoice)
                        {
                        case 1:
                            set(&first, SetIndex, SetElement);
                            break;
                        case 2:
                            set(&second, SetIndex, SetElement);
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Choice is Invalid !!...Try Again";
                            break;
                        }
                        break;
                        // end of set operation

                    // Insert operation
                    case 8:
                        cout << "Choose The array to Insert element: " << endl
                             << "1. Array 'A'" << endl
                             << "2. Array 'B'" << endl
                             << "3. Back." << endl
                             << "--------------------------------------------------------" << endl;
                        int InsertChoice;
                        int InsertIndex;
                        int InsertElement;
                        cout << "Enter The element to Insert";
                        cin >> InsertElement;
                        cout << "Enter The index of the element to Insert";
                        cin >> InsertIndex;
                        switch (InsertChoice)
                        {
                        case 1:
                            Insert(&first, InsertIndex, InsertElement);
                            break;
                        case 2:
                            Insert(&second, InsertIndex, InsertElement);
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Choice is Invalid !!...Try Again";
                            break;
                        }
                        break;
                        // end of Insert operation

                    // Insert operation for sorted array
                    case 9:
                        cout << "Choose The array to Insert element: " << endl
                             << "1. Array 'A'" << endl
                             << "2. Array 'B'" << endl
                             << "3. Back." << endl
                             << "--------------------------------------------------------" << endl;
                        int sortedInsertChoice;
                        cin>>sortedInsertChoice;
                        
                        int InsertElement;
                        
                        
                        switch (InsertChoice)
                        {
                        case 1:
                            if(CheckSort(first)){
                                cout << "Enter The element to Insert";
                                cin >> InsertElement;
                                SortedInsert(&first, InsertElement);
                            }
                            else{
                                cout << "Array is not sorted!....use another insert operation"
                                     << "--------------------------------------------------------" << endl;
                            }
                            break;
                        case 2:
                            if (CheckSort(second))
                            {
                                cout << "Enter The element to Insert";
                                cin >> InsertElement;
                                SortedInsert(&second, InsertElement);
                            }
                            else
                            {
                                cout << "Array is not sorted!....use another insert operation"
                                     << "--------------------------------------------------------" << endl;
                            }
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Choice is Invalid !!...Try Again";
                            break;
                        }
                        break;
                        // end of Insert operation for sorted array

                    // Merging operation
                    case 10:

                    default:
                        cout << "Choice is Invalid !!...Try Again";
                        break;
                }
                break;
            // End of Choosing operation to perform

            // for Exiting the menu/program
            case 3:
                ch1 = 1;
                exit(0);
            default:
                cout << "Choice is Invalid !!...Try Again";
                break;
        }
        // End of switch case for main menu
    }
    return 0;
}