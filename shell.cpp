#include <iostream>
using namespace std;

void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
}

void shellSort(int A[], int N)
{
    int i, j, Increment, Tmp;
    cout << "\n--- ShellSort Iterations ---" << endl;

    // Start with gap = N/2, then divide by 2
    for (Increment = N / 2; Increment > 0; Increment /= 2)
    {
        for (i = Increment; i < N; i++)
        {
            Tmp = A[i];
            for (j = i; j >= Increment; j -= Increment)
            {
                if (Tmp < A[j - Increment])
                {
                    A[j] = A[j - Increment];
                }
                else
                {
                    break;
                }
            }
            A[j] = Tmp;
        }
        cout << "Gap " << Increment << ": ";
        printArray(A, N);
    }
}

int main()
{
    int A[] = {5, 9, 2, 15, 23, 8, 41, 3, 99, 62, 12, 6, 10, 13, 1, 82};
    int N = 16;

    cout << "Original Array:\n";
    printArray(A, N);

    cout << "\nShell Sort Steps:\n";
    shellSort(A, N);

    cout << "\nFinal Sorted Array:\n";
    printArray(A, N);

    return 0;
}