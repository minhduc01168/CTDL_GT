#include<iostream>
using namespace std;
void InterchangeSort( int M[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(M[j]<M[i])
			{
				int temp=M[i];
				M[i]=M[j];
				M[j]=temp;
			}
		}
	}
}
int main(){
	return 0;
}
