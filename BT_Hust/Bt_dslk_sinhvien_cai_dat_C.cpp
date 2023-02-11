//2.Cai dat mot cau truc list quan ly sinh vien.Thong tin ve sinh vien duoc bieu dien boi mot struct gom ma sinh vien(int), ho ten sinh vien (string), lop (string).Cac thao tac can thuc hien 
//Them SV vao dau danh sach
//Them SV vao cuoi danh sach
//Tim sinh vien theo ten
//Xoa sinh vien theo ten
//Thuc hien yeu cau tren ca 2 ngon ngu C va C++
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
struct SinhVien{
	int ma;
	string name;
	string lop;
};
struct Node{
	SinhVien *data;
	Node *pNext;
};
struct SingleList{
	Node *pHead;
};
void Initialize(SingleList *&list){
	list=new SingleList;
	list->pHead=NULL;
}
Node*CreateNode(SinhVien *sv){
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
SinhVien *Input(){
	SinhVien *sv=new SinhVien;
	cout<<"Ma:";
	cin>>sv->ma;
	cin.ignore();
	cout<<"Ten:";
	getline(cin,sv->name);
	cout<<"Lop:";
	getline(cin,sv->lop);
	return sv; 
} 
void InsertFirst(SingleList *&list, SinhVien *sv){//chen phan tu vao dau ds
	Node *pNode= CreateNode(sv);//tao con tro pNode
	if(list->pHead==NULL){//neu list rong
		list->pHead=pNode;//pHead=pNode
	}
	else
	{
		pNode->pNext=list->pHead;//pNode tro phan tu dau
		list->pHead=pNode;//chuyen pHead ve dau danh sach
	}
	
}
void InsertLast(SingleList *&list, SinhVien *sv){//chen phan tu vao cuoi ds
	Node *pNode=CreateNode(sv);//tao 1 node moi
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
}
void RemoveNode(SingleList *&list,string name){//xoa node khoi danh sach
    Node *pDel=list->pHead;
    if(pDel==NULL){//danh sach rong
        cout<<"The list is empty!";
	}
	else
	{
		Node *pPre=NULL;//tao node
		while(pDel!=NULL){
			SinhVien *sv=pDel->data;
			if(sv->name==name)//tim vi tri pDel
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
}

Node *SearchNode(SingleList *list,string name){//tim kiem phan tu trong ds lk don
    Node *pTmp=list->pHead ;// khoi tao biem tam
    while(pTmp!=NULL){//duyet ds
        SinhVien *sv=pTmp->data;
    	if(sv->name==name){//gap node can tim
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
	    SinhVien *sv=pTmp->data;
		cout<<sv->ma<<"    "<<sv->name<<"     "<<sv->lop<<endl;//xuat data
		pTmp=pTmp->pNext;//tro den Node tiep theo
	}
}
int main(){
	SingleList *list;
	Initialize(list);
	SinhVien *a=Input();
	InsertFirst(list,a);
	SinhVien *b=Input();
	InsertFirst(list,b);
	SinhVien *c=Input();
	InsertLast(list,c);
	PrintList(list);
	cout<<"Tim kiem sinh vien co ten Nguyen Minh Duc:"<<endl;
	Node* pTmp=SearchNode(list,"Nguyen Minh Duc");
	SinhVien *sv=pTmp->data;
	cout<<sv->ma<<"    "<<sv->name<<"     "<<sv->lop<<endl;//xuat data
	cout<<"Xoa sinh vien co ten Nguyen Minh Hieu:"<<endl;
	RemoveNode(list,"Nguyen Minh Hieu");
	PrintList(list);
	return 0;
}
