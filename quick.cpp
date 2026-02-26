#include <iostream>
#include <vector>

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

// _______________MEDIANOFTHREE_______________
// Selects the median of the first, middle, and last elements to use as a pivot
int medianOfThree(vector<int> &A, int low, int high)
{
    int mid = (low + high) / 2; // find the index of the middle element.

    // sort the low, middle, and high elements so the median ends up at index 'mid'.
    if (A[low] > A[mid])
    {
        int temp = A[low];
        A[low] = A[mid];
        A[mid] = temp; //SWAP
    }

    if (A[low] > A[high])
    {
        int temp = A[low];
        A[low] = A[high];
        A[high] = temp; //SWAP
    }

    if (A[mid] > A[high])
    {
        int temp = A[mid];
        A[mid] = A[high];
        A[high] = temp; //SWAP
    }

    return mid; // return the index where the median value is now located
}
// _______________MEDIANOFTHREE_______________

// _______________PARTITION_______________
int partition(vector<int> &A, int low, int high)
{
    int pivotIndex = medianOfThree(A, low, high); // find the median index.

    // swap the pivot element with the last element to keep it out of the way.
    int temp1 = A[pivotIndex];
    A[pivotIndex] = A[high];
    A[high] = temp1;

    int pivot = A[high];
    int i = low - 1;

    // rearrange elements based on the pivot.
    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;

            int temp2 = A[i];
            // swap A[i] and A[j]
            A[i] = A[j];
            A[j] = temp2;
        }
    }

    // final swap.
    // place the pivot in its correct sorted position.
    int temp3 = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp3;

    printArray(A); // show state after partition.

    return i + 1;
}
// _______________PARTITION_______________

// _______________QUICKSORT_______________
// The recursive QuickSort function
void quickSort(vector<int> &A, int low, int high)
{
    if (low < high) // continue while the subarray has more than one element
    {
        int pi = partition(A, low, high); // find the partition index (where the pivot ends up).

        // recursive sort elements before and after the partition.
        quickSort(A, low, pi - 1); // sort the left side
        quickSort(A, pi + 1, high); // sort the right side
    }
}
// The recursive QuickSort function
// _______________QUICKSORT_______________


// _______________MAIN_______________
int main()
{
    vector<int> A = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};

    cout << "Original Array:\n";
    printArray(A); // display the unsorted array.

    cout << "\nQuick Sort Steps:\n";
    quickSort(A, 0, A.size() - 1); // trigger the QuickSort process on the entire vector.

    cout << "\nFinal Sorted Array:\n";
    printArray(A); // display the final sorted vector.
}
// _______________MAIN_______________ END
