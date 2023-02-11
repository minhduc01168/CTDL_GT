#include<iostream>
using namespace std;
void QuickSort( int M[],int left, int right)
{
	if(left>=right)
	{
		return ;
	}
	int pivot=M[(left+right)/2];
	int i=left,j=right;
	do
	{
		while(M[i]<pivot) i++;
		while(M[j]>pivot) j--;
		if(i<=j){
			int temp=M[i];
			M[i]=M[j];
			M[j]=temp;
			i++;
			j--;
		}
	}while(i<j);
	QuickSort(M,left,j);
	QuickSort(M,i,right);
}
/////////////////////////////////////////////////////////////
void Partition(int A[], int first, int last)
{
    if (first>=last) return;
    int c=A[first];
    int i=first+1,j=last;
    while (i<=j){
        while (A[i]<=c && i<=j) 
            i++;
        while (A[j]>c && i<=j) 
            j--;
        if (i<j) 
            swap(A[i],A[j]);
    }
    swap(A[first],A[j]);
    Partition(A, first,j-1);
    Partition(A, j+1,last);
}
void QuickSort1(int A[], int N){
    Partition(A,0,N-1);
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
    //QuickSort(arr,0,n-1);
    
    QuickSort1(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}
