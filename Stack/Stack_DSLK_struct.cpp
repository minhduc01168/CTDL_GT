#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *pLink;
};
typedef Node* Stack;
void Initialize(Stack &stack){
	stack=NULL;
}
Node *CreateNode(int d){
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}
void Push(Stack &stack, int d){
	Node *pNode=CreateNode(d);
	if(stack==NULL){
		stack=pNode;
	}
	else
	{
		pNode->pLink=stack;
		stack=pNode;
	}
}
int Pop(Stack &stack){
	int d=stack->data;
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	delete pDel;
	pDel=NULL;
	return d;
}
void Print(Stack &stack){
	Node *temp=stack;
	if(temp==NULL){
		cout<<"Stack rong";
	}
	else
	{
		while(temp!=NULL){
			cout<<temp->data<<"   ";
			temp=temp->pLink;
		}
	}
}
int main(){
	Stack stack;
	Initialize(stack);
	Push(stack,1);
	Push(stack,8);
	Push(stack,10);
	Print(stack);
	cout<<endl;
	cout<<Pop(stack)<<endl;
	return 0;
}
