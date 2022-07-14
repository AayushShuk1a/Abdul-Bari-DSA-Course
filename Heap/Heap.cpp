#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> vec;

public:
    void insert(int val);
    void print();
};

void Heap::print()
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void Heap::insert(int key)
{
    auto i = vec.size();
    vec.emplace_back(key);

    while (i > 0)
    {
        int parent = i % 2 == 0 ? (i / 2) - 1 : i / 2;
        if (vec[i] > vec[parent])
        {
            swap(vec[i], vec[parent]);
            i = parent;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    Heap h;
    h.insert(20);
    h.insert(25);
    h.insert(30);
    h.insert(32);
    h.insert(15);
    h.insert(19);
    h.print();
}