#include <iostream>
using namespace std;
#include <conio.h>

void mergeSort(int* arr, int startIndex, int endIndex);
void merge(int*, int, int,int);

int main() 
{
    int n;
    cout << "Enter the number of numbers to be sorted : ";
    cin >> n;
    int * a = new int[n];
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << " : ";
        cin >> a[i];
        cout << endl;
    }
    mergeSort(a, 0, n - 1);
    cout << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    delete []a;
    return 0;
}

void mergeSort(int* arr, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }
    int temp = (startIndex + endIndex)/2;
    mergeSort(arr, startIndex, temp);
    mergeSort(arr, temp+1, endIndex);
    merge(arr, startIndex, temp, endIndex);
}

void merge(int* arr, int p, int q, int r)
{
    int lengthOfL = q - p + 1;
    int* L = new int[lengthOfL];
    int lengthOfR = r - q;
    int* R = new int[lengthOfR];
    for (int i = 0; i < lengthOfL; i++)
    {
        L[i] = arr[p+i];
    }
    for (int i = 0; i < lengthOfR; i++)
    {
        R[i] = arr[q + 1 + i];
    }
 
    int Lcount = 0, Rcount = 0, arrcount = 0;
    while (Lcount < lengthOfL && Rcount < lengthOfR)
    {
        if (L[Lcount] < R[Rcount])
        {
            arr[p+arrcount] = L[Lcount];
            arrcount++;
            Lcount++;
        }
        else
        {
            arr[p+arrcount] = R[Rcount];
            arrcount++;
            Rcount++;
        }
    }
    if (Lcount == lengthOfL)
    {
        while (Rcount < lengthOfR)
        {
            arr[p+arrcount] = R[Rcount];
            arrcount++;
            Rcount++;
        }
    }
    else
    {
        while (Lcount < lengthOfL)
        {
            arr[p+arrcount] = L[Lcount];
            arrcount++;
            Lcount++;
        }
    }

    delete []L;
    delete []R;
}