#include<iostream>
using namespace std;
//Giai thuat tim kiem nhi phan dung de quy
int BinarySearch( int M[],int x, int left, int right)
{
	if(left>right)
	    return -1;
    int mid=(left+right)/2;
    if(x==M[mid])
    {
    	return mid;
	}
	if(x<M[mid])
	{
		return BinarySearch(M,x,left,mid-1);
	}
	return BinarySearch(M,x,mid+1,right);
}
int main(){
	return 0;
}
