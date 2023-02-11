//Viet ham tim vi tri be nhat trong day so nguyen gom n phan tu
//Y tuong chia de tri
#include<iostream>
using namespace std;

int Min2(int arr[], int dau,int cuoi){
	int m;
	int min1,min2;
	if(dau==cuoi)
	   return dau;
	if(dau<cuoi){
		m=(dau+cuoi)/2;
		min1=Min2(arr,dau,m);
		min2=Min2(arr,m+1,cuoi);
		if(arr[min1]<=arr[min2])
		    return min1;
		else
		    return min2;
	}
	
}
int main(){
	
	int arr[6]={8,4,3,67,16,9};
	//cout<<Min1(arr,8)<<endl;
	cout<<Min2(arr,0,5)<<endl;
	return 0;
}
