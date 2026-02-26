#include <iostream>
using namespace std;

//___________________________________
//___________________________________
//________FUNCTION DEFINITION________


// _______________PRINT_______________
void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}
// _______________PRINT_______________

// Function to perform ShellSort on an array of size N
void shellSort(int A[], int N)
{
    int i, j, Increment, Tmp;
    cout << "\n--- ShellSort Iterations ---" << endl;

    // the outer loop controls the "Gap" (Increment).
    // start with gap = N/2, then divide by 2.
    for (Increment = N / 2; Increment > 0; Increment /= 2)
    {   
        // this loop performs a "gapped" insertion sort.
        for (i = Increment; i < N; i++)
        {
            Tmp = A[i]; // store the current element to be positioned.

            // shift earlier gap-sorted elements up until the correct location for 'Tmp' is found.
            for (j = i; j >= Increment; j -= Increment)
            {   
                // compare Tmp.
                if (Tmp < A[j - Increment])
                {
                    A[j] = A[j - Increment]; // shift the larger element forward.
                }
                else
                {
                    break; // found the correct spot for Tmp.
                }
            }
            A[j] = Tmp; // insert Tmp into its correct position in the gapped sequence.
        }
        cout << "Gap " << Increment << ": ";
        printArray(A, N);
    }
}
// Function to perform ShellSort on an array of size N

//________FUNCTION DEFINITION________
//___________________________________
//___________________________________

// _______________MAIN_______________
int main()
{   
    // initial array.
    int A[] = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};
    int N = 16;

    cout << "Original Array:\n";
    printArray(A, N); // display the unsorted array.

    cout << "\nShell Sort Steps:\n";
    shellSort(A, N); // trigger the ShellSort process

    cout << "\nFinal Sorted Array:\n";
    printArray(A, N); // display the final sorted array.

    return 0;
}
// _______________MAIN_______________ END