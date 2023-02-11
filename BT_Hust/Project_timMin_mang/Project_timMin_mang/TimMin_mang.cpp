//Viet ham tim gia tri be nhat trong day so nguyen gom n phan tu
#include<iostream>
using namespace std;
int Min1(int arr[], int n) {
	if (n == 1) {
		return arr[0];
	}
	int temp = Min1(arr, n - 1);
	if (temp < arr[n - 1]) {
		return temp;
	}
	else
	{
		return arr[n - 1];
	}
}
int Min2(int arr[], int dau, int cuoi) {
	int m;
	int min1, min2;
	if(dau==cuoi)
	    return dau;
	m = (dau + cuoi) / 2;
	min1 = Min2(arr, dau, m);
	min2 = Min2(arr, m + 1, cuoi);
	if (arr[min1] <= arr[min2])
		return min1;
	else return min2;
}
int main() {

	int arr[8] = { 1,8,4,99,3,67,-1,-99 };
	//cout<<Min1(arr,8)<<endl;
	cout << Min2(arr, 1, 7) << endl;
	return 0;
}