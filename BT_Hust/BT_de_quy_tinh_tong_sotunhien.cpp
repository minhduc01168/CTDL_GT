//Viet 1 ham tinh tong cua n phan tu dau tien cua day so tu nhien
//Dung de quy va khu de quy
#include<iostream>
using namespace std;
int Sum1(int n){//khu de quy
	int sum=0;
	for(int i=0;i<=n;i++){
		sum=sum+i;
	}
	return sum;
}
int Sum2(int n){//de quy
	if(n==0){
		return 0;
	}
	return n+Sum2(n-1);
}
int main()
{
	cout<<"Nhap so phan tu muon tinh tong:";
	int n;
	cin>>n;
	cout<<Sum2(n)<<endl;
	cout<<Sum1(n);
	return 0;
}
