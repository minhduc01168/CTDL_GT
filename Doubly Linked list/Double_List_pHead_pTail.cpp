#include<iostream>
using namespace std;
struct DNode{//cau truc danh sach lien ket doi
	int data;
	DNode *pNext;
	DNode *pPrevious;
};
struct DoubleList{// kieu danh sach quan ly bang pHead
	DNode *pHead;
	DNode *pTail;
};
void Initialize(DoubleList &list){//Khoi tao danh sach lien ket doi rong
	list.pHead=list.pTail=NULL;
}
void PrintList(DoubleList list){//Xuat danh sach
	DNode *pTmp=list.pHead;
	if(pTmp==NULL){
		cout<<"The list is empty!";
		return;
	}
	while(pTmp!=NULL){
		cout<<pTmp->data<<"    ";
		pTmp=pTmp->pNext;
	}
}
int SizeOfList(DoubleList list){//dem so phan tu cua danh sach
    DNode *pTmp=list.pHead;
    int nSize=0;
    while(pTmp!=NULL){
    	pTmp=pTmp->pNext;
    	nSize++;
	}
	return nSize;
}
DNode *CreateDNode(int d){//Tao Node moi cho danh sach 
	DNode *pDNode=new DNode;
	if(pDNode!=NULL){
		pDNode->data=d;
		pDNode->pNext=NULL;
	}
	else
	{
		cout<<"Error allocated memory!";
	}
	return pDNode;
}
void InsertFirst(DoubleList &list, int d){
	DNode *pDNode=CreateDNode(d);
	if(list.pHead==NULL){
		list.pHead=list.pTail=pDNode;
	}
	else
	{
		pDNode->pNext=list.pHead;
		list.pHead->pPrevious=pDNode;
		list.pHead=pDNode;
	}
}
void InsertLast(DoubleList &list,int d){
	DNode *pDNode=CreateDNode(d);
	if(list.pTail==NULL){
		list.pHead=list.pTail=pDNode;
	}
	else
	{
		list.pTail->pNext=pDNode;
		pDNode->pPrevious=list.pTail;
		list.pTail=pDNode;
	}
}
void RemoveNode(DoubleList &list, int d){
	DNode *pDel=list.pHead;
	if(pDel==NULL){
		cout<<"The list is empty!";
		return;
	}
	DNode *pPre=NULL;
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
			list.pHead->pPrevious=NULL;
		}
		else if(pDel->pNext==NULL){
			list.pTail=pPre;
			pDel->pPrevious=NULL;
			pPre->pNext=NULL;
			
		}
		else
		{
			pPre->pNext=pDel->pNext;
			pDel->pNext->pPrevious=pPre;
			pDel->pPrevious=NULL;
			pDel->pNext=NULL;
		}
		delete pDel;
		pDel=NULL;
	}
}
int main(){
	return 0;
}
