//Viet ham tim gia tri be nhat trong day so nguyen gom n phan tu
//Y tuong chia doi de tri
#include<iostream>
using namespace std;
int Min1(int arr[], int n){
	if(n==1){
		return arr[0];
	}
	int temp=Min1(arr,n-1);
	if(temp<arr[n-1]){
		return temp;
	}
	else
	{
		return arr[n-1];
	}
}
int Min2(int arr[], int dau,int cuoi,int &min){
	int m;
	int min1,min2;
	if(dau==cuoi)
	   return min=arr[dau];
	if(dau<cuoi){
		m=(dau+cuoi)/2;
		Min2(arr,dau,m,min1);
		Min2(arr,m+1,cuoi,min2);
		if(min1<=min2)
		    return min=min1;
		else
		    return min=min2;
	}
	
}
int main(){
	
	int arr[6]={8,4,3,67,-16,9};
	int min=arr[0];
	//cout<<Min1(arr,8)<<endl;
	cout<<Min2(arr,0,5,min)<<endl;
	return 0;
}
