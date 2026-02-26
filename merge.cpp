#include <iostream>
#include <vector> // Dynamic Array.

using namespace std;

//___________________________________
//___________________________________
//________FUNCTION DEFINITION________

// _______________PRINT_______________
// Function to print the contents of the vector to the console------------
void printArray(vector<int> &A)
{
    int N = A.size();
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}
// Function to print the contents of the vector to the console------------
// _______________PRINT_______________



// _______________MERGING_______________
// Function to merge two sorted subarrays into one sorted section---------
void merge(vector<int> &A, int left, int mid, int right)
{
    int n1 = mid - left + 1; // calculate the size of the left subarray.
    int n2 = right - mid; // calculate the size of the right subarray.

    // create a temporary.
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data correctly.
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0; // i tracks the index of L, j tracks the index of R.
    int k = left; // k tracks the current position in the original array (A).

    // compare elements from L and R and merge.
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    // copy remaining elements left vector.
    while (i < n1)
        A[k++] = L[i++];
    // copy remaining elements right vector.
    while (j < n2)
        A[k++] = R[j++];

    // print after each merge (for assignment requirement).
    printArray(A);
}
// Function to merge two sorted subarrays into one sorted section---------
// _______________MERGING_______________



// _______________MERGESORT_______________
// Recursive function that implements the "Divide and Conquer" logic of MergeSort---------
void mergeSort(vector<int> &A, int left, int right)
{
    if (left >= right) // Base Case; if the subarray has 1 or 0 elements, it is already sorted.
        return;

    int mid = left + (right - left) / 2; // calculate the midpoint divide the array.

    mergeSort(A, left, mid); // recursive sort the left half.
    mergeSort(A, mid + 1, right); // recursive sort the right half.
    merge(A, left, mid, right);
}
// Recursive function that implements the "Divide and Conquer" logic of MergeSort---------
// _______________MERGESORT_______________

//________FUNCTION DEFINITION________
//___________________________________
//___________________________________


// _______________MAIN_______________
int main()
{
    // initial array.
    vector<int> A = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};

    cout << "Original Array:\n";
    printArray(A); // display the unsorted array.

    cout << "\nMerge Sort Steps:\n";
    mergeSort(A, 0, A.size() - 1); // trigger the MergeSort process on the entire vector.

    cout << "\nFinal Sorted Array:\n";
    printArray(A); // display the final sorted vector.
}
// _______________MAIN_______________ END
