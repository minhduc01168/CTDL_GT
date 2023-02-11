#include<iostream>
using namespace std;
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = A[i];
        int j = i-1;
        while ((temp<A[j])&&(j>=0))
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main(){
	int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    InsertionSort(arr,n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}
