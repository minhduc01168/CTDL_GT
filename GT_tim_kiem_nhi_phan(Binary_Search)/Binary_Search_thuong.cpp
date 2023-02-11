#include<iostream>
using namespace std;
//Giai thuat tim kiem nhi phan thuong
int BinarySearch( int M[],int n,int x)
{
	int left=0, right=n-1;
	int mid;
	do{
		mid=(left+right)/2;
		if(x==M[mid])
		{
			return mid; //Thay x tai mid
		}
		else if(x<M[mid])
		{
			right=mid-1;
		}
		else
		{
			left=mid+1;
	    }
	}while(left<= right);
	return -1;//tim het day khong tim thay x
}
int main(){
	return 0;
}
