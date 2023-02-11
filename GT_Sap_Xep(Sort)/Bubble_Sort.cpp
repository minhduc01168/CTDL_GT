#include<iostream>
using namespace std;
void BubbleSort( int M[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(M[j]<M[j-1])
			{
				int temp=M[j];
				M[j]=M[j-1];
				M[j-1]=temp;
			}
		}
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
    BubbleSort(arr,n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}
