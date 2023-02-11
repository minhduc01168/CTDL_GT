//Viet ham tim phan tu be nhat trong day so nguyen gom n phan tu
#include<iostream>
using namespace std;
int Min(int arr[], int n){
	if (n==2)
	return arr[0]<arr[1] ? arr[0]: arr[1];
	else 
	return (Min(int arr[], int N/2) < Min(int arr[N/2],int N/2) ? Min(int arr[], int N/2): Min(int arr[N/2],int N/2));
}
int main(){
	int A[4]=[1,3,2,5];
	int a=Min(A, 4);
	cout<<a;
}
