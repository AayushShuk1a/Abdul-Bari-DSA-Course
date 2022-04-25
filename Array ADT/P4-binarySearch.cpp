#include <iostream>
using namespace std;

class binarySearch
{
private:
    int *arr;
    int size;
    int length;

public:
    binarySearch(int sz)
    {
        size = sz;
        arr = new int[size];
        length = 0;
    }
    ~binarySearch()
    {
        delete[] arr;
    }
    int search1(int key);
    void storenum(int num, int i)
    {
        arr[i] = num;
        length++;
    }
};

int binarySearch::search1(int key)
{
    int l = 0;
    int h = length - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key >= arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int main()
{
    binarySearch search(5);
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        search.storenum(a[i], i);
    }

    cout << "Enter value you want to search";
    int key;
    cin >> key;

    cout << search.search1(key);
}