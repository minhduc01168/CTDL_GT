#include<iostream>
using namespace std;
void Merge(int M[],int left, int mid, int right)
{
	int nTemp=right-left+1;
	int Temp[nTemp];
	int pos=0, i=left,j=mid+1;
	while(!(i>mid&&j>right))
	{
		if((i<=mid&&j<=right&&M[i]<M[j])||j>right)
		{
			Temp[pos++]=M[i++];
		}
		else
		{
			Temp[pos++]=M[j++];
			
		}
	}
	for(int i=0;i<nTemp;i++)
	{
		M[left+i]=Temp[i];
	}
}
void MergeSort( int M[],int left,int right)
{
	if(left>=right) return;
	int mid=(left+right)/2;
	MergeSort(M,left, mid);
	MergeSort(M,mid+1,right);
	Merge(M,left,mid,right);
}
////////////////////////////////////////////////////////////
//Tron 2 day con ma da duoc sap xep trong A
//L1=A[m],A[m+1],...,A[n]; 
//L2=A[n+1],A[n+2],...,A[p]
void MergeArrays(int A[],int m, int n, int p)
{
    int i=m,j=n+1;
    while (i<j && j<=p){
        if (A[i]<=A[j]) i++;
        else {//chen Aj vao vi tri i
            int x=A[j];
            for (int k=j-1;k>=i;k--) 
                A[k+1]=A[k];
            A[i]=x;
            i++; j++;
        }
    }
}
void Merge(int A[], int first, int last)
{
    if (first>=last) return;
    int m=(first+last)/2;
    Merge(A,first,m);
    Merge(A,m+1,last);
    MergeArrays(A,first,m,last);
}
void MergeSort1(int A[], int N){
    if (N<2) return;
    Merge(A,0,N-1);
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
    //MergeSort(arr,0,n-1);
    MergeSort1(arr,n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}
