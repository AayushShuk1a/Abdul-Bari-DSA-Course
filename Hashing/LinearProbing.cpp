#include <iostream>
using namespace std;

class LinearProbing
{
public:
    int *HT;
    LinearProbing();
    void insert(int key);
    int search(int key);
    int probe(int key);
    void print();
};

int LinearProbing::search(int key)
{
    int index = key % 10;
    int i = 0;
    while (HT[(index + i) % 10] != key)
    {
        i++;
        if (HT[(index + i) % 10] == 0)
        {
            return -1;
        }
    }

    return (index + i) % 10;
}

int LinearProbing::probe(int key)
{

    int index = key % 10;

    int i = 0;
    while (HT[(index + i) % 10] != 0)
    {

        i++;
    }

    return (index + 1) % 10;
}

LinearProbing::LinearProbing()
{

    HT = new int[10];
    for (int i = 0; i < 10; i++)
    {
        HT[i] = 0;
    }
}

void LinearProbing::insert(int key)
{
    int index = key % 10;
    if (HT[index] != 0)
    {
        index = probe(key);
    }

    HT[index] = key;
}

void LinearProbing::print()
{
    for (int i = 0; i < 10; i++)
    {
        cout << HT[i] << " ";
    }
}

int main()
{
    LinearProbing lp;
    lp.insert(25);
    lp.insert(27);
    lp.insert(26);
    lp.insert(35);
    lp.print();

    cout << endl;

    cout << lp.search(27);
}