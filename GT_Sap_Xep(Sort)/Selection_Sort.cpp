#include<iostream>
using namespace std;
void SelectionSort( int M[],int n)
{
	int min;
	for( int i=0;i<n;i++)
	{
		min=i;//Gia su so dau trong day dang xet la nho nhat
		for(int j=i+1;j<n;j++){//tim so nho nhat trong day dang xet
			if(M[j]<M[min])
			{
				min=j;
			}
		}
		if(min!=i)//neu co so nao nho hon so dau trong day dang xet thi doi vi tri cho nhau
		{
			int temp=M[i];
			M[i]=M[min];
			M[min]=temp;
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
    SelectionSort(arr,n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}
