//Cai dat 1 ds cac mon hoc, moi mon hoc gom: ma mon, ten mon, so tin chi.
//DS luon sap xep theo thu tu tang dan so tin chi 
//Y/c: Sd cau truc luu tru moc noi don de cai dat ds
//cai dat thao tac khoi tao,bo sung 1 mon, loai bo 1 mon co ma mon cho truoc, in ra noi dung cua DS
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct Subjects{
	string ma;
	string name;
	int tc;
};
struct Node{
	Subjects *data;
	Node *pNext;
};
struct SingleList{
	Node *pHead;
};
void Initialize(SingleList *&list){
	list=new SingleList;
	list->pHead=NULL;
}
Node*CreateNode(Subjects *sv){
	Node *pNode=new Node;
	if(pNode!=NULL){
		pNode->data=sv;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"Cap phat bo nho that bai";
	}
	return pNode;
}
Subjects *Input(){
	Subjects *sub=new Subjects;
	cout<<"Ma:";
	getline(cin,sub->ma);
	cout<<"Ten:";
	getline(cin,sub->name);
	cout<<"Tin chi:";
	cin>>sub->tc;
	cin.ignore();
	return sub; 
} 
void SortList(SingleList *&list)
{
	for(Node* pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node* pTmp2=list->pHead;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{
			Subjects *sub1=pTmp->data;
			Subjects *sub2=pTmp2->data;
			if(sub1->tc<sub2->tc){
				Subjects *sub=pTmp->data;
				pTmp->data=pTmp2->data;
				pTmp2->data=sub;
			}
		}
	}
}
void InsertFirst(SingleList *&list, Subjects *sub){//chen phan tu vao dau ds
	Node *pNode= CreateNode(sub);//tao con tro pNode
	if(list->pHead==NULL){//neu list rong
		list->pHead=pNode;//pHead=pNode
	}
	else
	{
		pNode->pNext=list->pHead;//pNode tro phan tu dau
		list->pHead=pNode;//chuyen pHead ve dau danh sach
	}
	SortList(list);
}
Node *SearchNodeSX(SingleList *list,Subjects *sub){//tim kiem phan tu trong ds lk don
    Node *pTmp=list->pHead ;// khoi tao biem tam
    while(pTmp!=NULL){//duyet ds
    	if(sub->tc<pTmp->data->tc){//gap node can tim
    	   break;
		}
		pTmp=pTmp->pNext;
	}
	return pTmp;//xuat node
}
void InsertBefore(SingleList *&list, Subjects *sub){//chen phan tu vao dau ds
	Node *pNode= CreateNode(sub);//tao con tro pNode
	Node *P=SearchNodeSX(list,sub);
	if(list->pHead==NULL){//neu list rong
		list->pHead=pNode;//pHead=pNode
	}
	else
	{
		pNode->data=P->data;
		P->data=sub;
		pNode->pNext=P->pNext;//pNode tro phan tu dau
		P->pNext=pNode;//chuyen pHead ve dau danh sach
	}
}
void InsertLast(SingleList *&list, Subjects *sub){//chen phan tu vao cuoi ds
	Node *pNode=CreateNode(sub);//tao 1 node moi
	if(list->pHead==NULL){//neu list rong
		list->pHead=pNode;
	}
	else
	{
		Node *pTmp=list->pHead;//tao node tam
		while(pTmp->pNext!=NULL){//kiem tra node cuoi
		    pTmp=pTmp->pNext;//tro tiep tuc
		}
		pTmp->pNext=pNode;//tro den pNode
	}
	SortList(list);
}
void RemoveNode(SingleList *&list,string m){//xoa node khoi danh sach
    Node *pDel=list->pHead;
    if(pDel==NULL){//danh sach rong
        cout<<"The list is empty!";
	}
	else
	{
		Node *pPre=NULL;//tao node
		while(pDel!=NULL){
			Subjects *sub=pDel->data;
			if(sub->ma==m)//tim vi tri pDel
			{
				break;
			}
			pPre=pDel;//duyet tung node
			pDel=pDel->pNext;
		}
		if(pDel==NULL){//ds khong chua node do
		    cout<<"Could not found number!";
		}
		else
		{
			if(pDel==list->pHead)//xoa node dau ds
			{
				list->pHead=list->pHead->pNext;//chuyen pHead den node tiep theo
				pDel->pNext=NULL;//cho node dau tro NULL
				delete pDel;//xoa node dau
				pDel=NULL;//cho gia tri node dau =NULL
			}
			else//xoa node o giua
			{
				pPre->pNext=pDel->pNext;//2 node cung tro den node sau
				pDel->pNext=NULL;//cat node pDel
				delete pDel;//xoa node pDel
				pDel=NULL;//cho node pDel=NULL
			}
		}
	}
	SortList(list);
}

Node *SearchNode(SingleList *list,string m){//tim kiem phan tu trong ds lk don
    Node *pTmp=list->pHead ;// khoi tao biem tam
    while(pTmp!=NULL){//duyet ds
        Subjects *sub=pTmp->data;
    	if(sub->ma==m){//gap node can tim
    	   break;
		}
		pTmp=pTmp->pNext;
	}
	return pTmp;//xuat node
}

void PrintList(SingleList *list)//duyet danh sach
{
	Node *pTmp=list->pHead;//con tro tam de duyet
	if(pTmp==NULL){
		cout<<"The list is empty!";
		return;
	}
	while(pTmp!=NULL){//duyet
	    Subjects *sub=pTmp->data;
		cout<<sub->ma<<"     "<<sub->name<<"         "<<sub->tc<<endl;//xuat data
		pTmp=pTmp->pNext;//tro den Node tiep theo
	}
}

int main(){
	SingleList *list;
	Initialize(list);
	Subjects *a=Input();
	InsertFirst(list,a);
	Subjects *b=Input();
	InsertFirst(list,b);
	Subjects *c=Input();
	InsertLast(list,c);
	PrintList(list);
	Subjects *d=Input();
	InsertBefore(list, d);
	PrintList(list);
	//cout<<"\nDanh sach sau khi xoa:"<<endl;
	//string x="qwerty1";
	//RemoveNode(list,x);
	//PrintList(list);
	
	//cout<<"\nDanh sach sau khi sap xep:"<<endl;
	//SortList(list);
	//PrintList(list);
	
	return 0;
}
