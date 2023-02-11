//Dung Stack de tinh bieu thuc o dang postfix
#include<iostream>
#include <string.h>  
using namespace std;
typedef struct {
	int *arr;
	unsigned int n;//So phan tu cua Queue
}Stack;
Stack* createStack( unsigned int n )  
{  
    Stack* S = new Stack;   
    S->n= n;  
    S->arr = new int[S->n]; 
	return S;  
}  
bool IsEmpty(Stack *S)
{
	if( S->n==0){
		return true;
	}
	else return false;
}
void Push(Stack *S, int k)
{
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
int Postfix(char* exp)  
{  
    // Create a stack of capacity equal to expression size  
    Stack* S = createStack(strlen(exp)); 
    //Quet tung ky tu cua chuoi 
    for (int i = 0; i<strlen(exp); ++i)  
    {  
        // If the scanned character is an operand (number here),//Neu ky tu la toan hang thi day vao stack  
        // push it to the stack.  
        if (isdigit(exp[i]))  
            Push(S, exp[i] - '0');  
  
        // Neu ký tu duoc quét là mot toán tu, hãy lay haoi toan hang
        // các phan tu tu ngan xep áp dung toán tu
        else
        {  
            int val1 = Pop(S);  
            int val2 = Pop(S);  
            switch (exp[i])  
            {  
            case '+': Push(S, val2 + val1); break;  
            case '-': Push(S, val2 - val1); break;  
            case '*': Push(S, val2 * val1); break;  
            case '/': Push(S, val2/val1); break;  
            }  
        }  
    }  
    return Pop(S);  
}  
int main(){
	char exp[] = "231*+9-";  
    cout<<"Postfix evaluation: "<< Postfix(exp);
	return 0;
}
