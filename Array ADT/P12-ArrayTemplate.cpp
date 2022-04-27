#include <iostream>
using namespace std;

template <class T>

class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new int[10];
        length = 0;
    }

    Array(int sz)
    {
        size = sz;
        A = new int[sz];
        length = 0;
    }

    ~Array()
    {
        delete[] A;
    }

    int getLength()
    {
        return length;
    }

    void insert(T value, int index);
    void display();
    void Delete(int index);
    void fillArray(T value, int index);
};

template <class T>
void Array<T>::fillArray(T value, int index)
{

    A[index] = value;
    length++;
}

template <class T>
void Array<T>::insert(T value, int index)
{

    if (index >= 0 && index <= length)
    {

        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = value;
        length++;
    }
}
template <class T>
void Array<T>::display()
{

    cout << "The Elements are : " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::Delete(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
}

int main()
{
    Array<int> *arr; // change datatype of int in whole main function int x and int n
    int ch, sz;

    int x, index;

    cout << "Enter size of an array : ";

    cin >> sz;
    arr = new Array<int>(sz);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. FillArray\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5.Exit\n";
        cout << "enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Elements : ";
            int n;
            for (int i = arr->getLength(); i < sz; i++)
            {
                cin >> n;
                arr->fillArray(n, i);
            }
            break;

        case 2:

            if (arr->getLength() >= sz)
            {
                cout << "Array is Full please delete element to insert new element ";
            }
            else
            {
                cout << "Enter element and index ";
                cin >>
                    x >> index;
                arr->insert(x, index);
            }

            break;

        case 3:
            cout << "Enter Index You want to delete : ";
            cin >> index;
            arr->Delete(index);
            break;

        case 4:
            arr->display();
            break;
        }

    } while (ch < 5);
}
