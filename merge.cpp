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

void merge(vector<int> &A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data correctly
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];

    // Print after each merge (for assignment requirement)
    printArray(A);
}

void mergeSort(vector<int> &A, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
}

int main()
{
    vector<int> A = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};

    cout << "Original Array:\n";
    printArray(A);

    cout << "\nMerge Sort Steps:\n";
    mergeSort(A, 0, A.size() - 1);

    cout << "\nFinal Sorted Array:\n";
    printArray(A);
}
