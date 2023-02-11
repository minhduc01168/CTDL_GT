//1.Cai dat mot ds moc noi kep voi cac thao tac da hoc, moi node trong danh sach chi chua mot du lieu kieu int.Viet ctrinh chinh minh hoa cach su dung danh sach moc noi kep do
#include<iostream>
using namespace std;
struct DNode{//cau truc danh sach lien ket doi
	int data;
	DNode *pNext;
	DNode *pPrevious;
};
struct DoubleList{// kieu danh sach quan ly bang pHead
	DNode *pHead;
};
void Initialize(DoubleList &list){//Khoi tao danh sach lien ket doi rong
	list.pHead=NULL;
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
DNode *CreateDNode(int d){//Tao 1 node moi
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
void InsertFirst(DoubleList &list,int d){// chen phan tu vao dau danh sach lien ket doi
	DNode *pDNode=CreateDNode(d);
	if(list.pHead==NULL){
		list.pHead=pDNode;
	}
	else
	{
		pDNode->pNext=list.pHead;
		list.pHead->pPrevious=pDNode;
		list.pHead=pDNode;
	}
}
void InsertLast(DoubleList &list,int d){// chen phan tu vao cuoi ds lien ket doi
	DNode *pDNode=CreateDNode(d);
	if(list.pHead==NULL){
		list.pHead=pDNode;
	}
	else
	{
		DNode *pTmp=list.pHead;
		while(pTmp->pNext!=NULL){
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pDNode;
		pDNode->pPrevious=pTmp;
	}
}
void InsertMid(DoubleList &list,int pos, int d){//chen phan tu vao giua ds lien ket doi
	if(pos<0||pos>=SizeOfList(list)){
		cout<<"Not valid position do insert";
		return;
	}
	if(pos==0){
		InsertFirst(list,d);
	}
	else if(pos==SizeOfList(list)-1){
		InsertLast(list,d);
	}
	else
	{
		DNode *pDNode=CreateDNode(d);
		DNode *pIns=list.pHead;
		DNode *pPre=NULL;
		int i=0;
		while(pIns!=NULL){
			if(i==pos){
				break;
			}
			pPre=pIns;
			pIns=pIns->pNext;
			i++;
		}
		pDNode->pNext=pIns;
		pDNode->pPrevious=pPre;
		pPre->pNext=pDNode;
		pIns->pPrevious=pDNode;
	}
}
void RemoveNode(DoubleList &list,int d){// xoa phan tu trong danh sach doi
	DNode *pDel=list.pHead;
	if(pDel==NULL){//Ds rong
	   cout<<"The list is empty!";
	   return;
	}
	DNode *pPre=NULL;//duyet ds
	while(pDel!=NULL){
		if(pDel->data==d)//tim phan tu can xoa
		{
			break;
		}
		pPre=pDel;
		pDel=pDel->pNext;
	}
	if(pDel==NULL)//tim khong thay node can xoa
	{
		cout<<"Could not found number!";
	}
	else
	{
		if(pDel==list.pHead)//xoa node dau
		{
			list.pHead=list.pHead->pNext;
			pDel->pNext=NULL;
			list.pHead->pPrevious=NULL;
		}
		else if(pDel->pNext==NULL)//xoa node cuoi
		{
		    pDel->pPrevious=NULL;
		    pPre->pNext=NULL;
		}
		else //xoa o giua danh sach
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
DNode *SearchNode(DoubleList list, int d){// tim kiem tren ds lien ket doi
	DNode *pTmp=list.pHead;
	while(pTmp!=NULL){
		if(pTmp->data=d){
			break;
		}
		pTmp=pTmp->pNext;
	}
	return pTmp;
}
void FreeMemory(DoubleList &list){// Huy danh sach lien ket doi
	cout<<"\n--------\nStarting to delete----\n";
	while(list.pHead!=NULL){
		DNode *pDel=list.pHead;
		list.pHead=list.pHead->pNext;
		pDel->pNext=NULL;
		pDel->pPrevious=NULL;
		cout<<pDel->data<<" is deleted\n";
		delete pDel;
		pDel=NULL;
	}
	cout<<"Deleted is complete\n---\n";
}
int main(){
	DoubleList Dlist;
	Initialize(Dlist);
	InsertFirst(Dlist, 1);
	InsertFirst(Dlist, 6);
	InsertLast(Dlist, 10);
	InsertLast(Dlist, 16);
	InsertMid(Dlist, 2, 113);
	PrintList(Dlist);
	cout <<"\nSo phan tu cua Double Linked: "<< SizeOfList(Dlist)<<endl;
	InsertMid(Dlist, 3, 114);
	RemoveNode(Dlist, 113);
	PrintList(Dlist);
	cout << "\nSo phan tu cua Double Linked: " << SizeOfList(Dlist) << endl;
	//InsertMid(Dlist, 4, 111);
	//PrintList(Dlist);
	//DNode* temp = SearchNode(Dlist, 111);
	//cout << "\nTim thay phan tu: " << temp->data << endl;
	FreeMemory(Dlist);
	//PrintList(Dlist);
	return 0;
}
