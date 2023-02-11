#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *pLink;
};
struct Queue{
	Node *pFront;
	Node *pRear;
};
void Initialize(Queue &queue){
	queue.pFront=NULL;
	queue.pRear=NULL;
}
Node *CreateNode(int d){
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}
void Enqueue(Queue &queue, int d){
	Node *pNode=CreateNode(d);
	if(queue.pFront==NULL){
		queue.pFront=queue.pRear=pNode;
	}
	else
	{
		queue.pRear->pLink=pNode;
		queue.pRear=pNode;
	}
}
int Dequeue(Queue &queue){
	if(queue.pFront==NULL){
		cout<<"Queue rong";
		exit(0);
	}
	int d=queue.pFront->data;
	Node *pDel=queue.pFront;
	queue.pFront=queue.pFront->pLink;
	pDel->pLink=NULL;
	delete pDel;
	pDel=NULL;
	return d;
}
void Print(Queue &queue){
	Node *temp=queue.pFront;
	if(temp==NULL){
		cout<<"Queue rong";
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
	Queue queue;
	Initialize(queue);
	Enqueue(queue,1);
	Enqueue(queue,8);
	Enqueue(queue,10);
	Print(queue);
	cout<<endl;
	cout<<Dequeue(queue)<<endl;
	return 0;
}
