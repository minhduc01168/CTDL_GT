#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *pNext;
};
struct SingleList{
	Node *pHead;
	Node *pTail;
};
void Initialize(SingleList &list){// khoi tao danh sach rong
	list.pHead=list.pTail=NULL;
}
Node *CreateNode(int d){// khoi tao moi cho ds
	Node *pNode=new Node;
	if(pNode=NULL){
		pNode->data=d;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"Error allocated memory";
	}
	return pNode;
}
void PrintList(SingleList list){
	Node *pTmp=list.pHead;
	if(pTmp==NULL){
		cout<<"The list is empty!";
		return;
	}
	while(pTmp!=NULL){
		cout<<pTmp->data<<"    ";
		pTmp=pTmp->pNext;
	}
}
void InsertFirst(SingleList &list, int d){
	Node *pNode=CreateNode(d);
	if(list.pHead==NULL){
		list.pHead=list.pTail=pNode;
	}
	else
	{
		pNode->pNext=list.pHead;
		list.pHead=pNode;
	}
}
void InsertLast(SingleList &list, int d){
	Node *pNode=CreateNode(d);
	if(list.pTail==NULL){
		list.pHead=list.pTail=pNode;
	}
	else
	{
		list.pTail->pNext=pNode;
		list.pTail=pNode;
	}
}
void RemoveNode(SingleList &list, int d){
	Node *pDel=list.pHead;
	if(pDel==NULL){
		cout<<"The list is empty!";
	}
	else
	{
		Node *pPre=NULL;
		while(pDel!=NULL){
			if(pDel->data==d){
				break;
			}
			pPre=pDel;
			pDel=pDel->pNext;
		}
		if(pDel==NULL){
			cout<<"Could not found number!";
		}
		else
		{
			if(pDel==list.pHead){
				list.pHead=list.pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
			else if(pDel->pNext==NULL){
				list.pTail=pPre;
				pPre->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
			else
			{
				pPre->pNext=pDel->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
		}
	}
}
int main(){
	return 0;
}
