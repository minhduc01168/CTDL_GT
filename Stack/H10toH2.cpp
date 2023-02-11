//Viet 1 chuong trinh chuyen tu co so 10 sang co so 2 ba ng stack
#include<iostream>
#define MAX 20
using namespace std;
typedef struct {
	int arr[MAX];
	unsigned int n;//So phan tu cua Queue
}Stack;
void Initilize(Stack *S)
{
	S->n=0;
}
bool IsEmpty(Stack *S)
{
	if( S->n==0){
		return true;
	}
	else return false;
}
bool IsFull(Stack *S){
	if(S->n==MAX){
		return true;
	}
	else return false;
}
void Push(Stack *S, int k)
{
	if(IsFull(S)) return;
	S->arr[S->n]=k;
	S->n++;
}
int Pop(Stack *S)
{
	if(IsEmpty(S)) return 0;
	S->n--;
	return S->arr[S->n];
}
int Top(Stack *S)
{
	if(IsEmpty(S)) return 0;
	return S->arr[S->n-1];
}

void H10toH2_dequy(int n){// Su dung de quy
	if(n>0){
		int sd=n%2;
		H10toH2_dequy(n/2);
		cout<<sd;
	}
}
void H10toH2_stack( Stack *S, int a )
{
	while( a>0){
		int sd=a%2;
		a=a/2;
		Push(S,sd);
	}
	while(!IsEmpty(S)){
		int v=Pop(S);
	    cout<<v;
	}
}
int main(){
	Stack *S=new Stack;
	int a;
	cout<<"Nhap so a=";
	cin>>a;
	H10toH2_dequy(a);
	cout<< "\nKet qua:";
	H10toH2_stack( S, a );

	return 0;
}
