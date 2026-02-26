#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &A)
{
    for (int x : A)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> A = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};

    cout << "Original Array:\n";
}