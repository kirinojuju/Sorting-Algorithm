#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &A)
{
    int N = A.size();
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Median of three (basic swap)
int medianOfThree(vector<int> &A, int low, int high)
{
    int mid = (low + high) / 2;

    if (A[low] > A[mid])
    {
        int temp = A[low];
        A[low] = A[mid];
        A[mid] = temp;
    }

    if (A[low] > A[high])
    {
        int temp = A[low];
        A[low] = A[high];
        A[high] = temp;
    }

    if (A[mid] > A[high])
    {
        int temp = A[mid];
        A[mid] = A[high];
        A[high] = temp;
    }

    return mid;
}

int partition(vector<int> &A, int low, int high)
{
    int pivotIndex = medianOfThree(A, low, high);

    // Move pivot to end (manual swap)
    int temp1 = A[pivotIndex];
    A[pivotIndex] = A[high];
    A[high] = temp1;

    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;

            int temp2 = A[i];
            A[i] = A[j];
            A[j] = temp2;
        }
    }

    // Final swap
    int temp3 = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp3;

    printArray(A); // show state after partition

    return i + 1;
}

void quickSort(vector<int> &A, int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main()
{
    vector<int> A = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};

    cout << "Original Array:\n";
    printArray(A);

    cout << "\nQuick Sort Steps:\n";
    quickSort(A, 0, A.size() - 1);

    cout << "\nFinal Sorted Array:\n";
    printArray(A);
}
