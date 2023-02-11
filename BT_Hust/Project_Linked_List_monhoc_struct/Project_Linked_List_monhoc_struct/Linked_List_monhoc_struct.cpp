//Cai dat 1 ds cac mon hoc, moi mon hoc gom: ma mon, ten mon, so tin chi.
//DS luon sap xep theo thu tu tang dan so tin chi 
//Y/c: Sd cau truc luu tru moc noi don de cai dat ds
//cai dat thao tac khoi tao,bo sung 1 mon, loai bo 1 mon co ma mon cho truoc, in ra noi dung cua DS
#include<iostream>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
struct Subjects {
	string ma;
	string name;
	int tin_chi;
};
struct Node {//khoi tao cau truc
	Subjects *data;
	Node* pNext;
};
struct SingleList {//Quan ly phan tu dau
	Node* pHead;
};
void Initialize(SingleList*& list)//khoi tao
{
	list = new SingleList;
	list->pHead = NULL;
}
Node* CreateNode(Subjects* d) {//tao node cho dslk don
	Node* pNode = new Node;//cap phat bo nho
	if (pNode != NULL) {
		pNode->data = d;
		pNode->pNext = NULL;
	}
	else
	{
		cout << "Error allocated memory";
	}
	return pNode;
}
void PrintList(SingleList *&list)//duyet danh sach
{
	Node* pTmp = list->pHead;//con tro tam de duyet
	if (pTmp == NULL) {
		cout << "The list is empty!";
		return;
	}
	while (pTmp != NULL) {//duyet
		Subjects* d = pTmp->data;
		cout <<setw(10)<<left<< (d->ma).c_str() <<setw(30)<<left<<(d->name).c_str()<<setw(10)<<left<<d->tin_chi<<endl;//xuat data
		pTmp = pTmp->pNext;//tro den Node tiep theo
	}
}
int SizeofList(SingleList &list) {//dem so phan tu cua ds
	Node* pTmp = list.pHead;
	int nSize = 0;
	while (pTmp != NULL) {
		pTmp = pTmp->pNext;
		nSize++;
	}
	return nSize;
}
bool IsEmpty(SingleList list) {
	return(list.pHead == NULL);
}
void InsertFirst(SingleList*& list, Subjects *d) {//chen phan tu vao dau ds
	Node* pNode = CreateNode(d);//tao con tro pNode
	if (list->pHead == NULL) {//neu list rong
		list->pHead = pNode;//pHead=pNode
	}
	else
	{
		pNode->pNext = list->pHead;//pNode tro phan tu dau
		list->pHead = pNode;//chuyen pHead ve dau danh sach
	}

}
void InsertLast(SingleList*& list, Subjects *d) {//chen phan tu vao cuoi ds
	Node* pNode = CreateNode(d);//tao 1 node moi
	if (list->pHead == NULL) {//neu list rong
		list->pHead = pNode;
	}
	else
	{
		Node* pTmp = list->pHead;//tao node tam
		while (pTmp->pNext != NULL) {//kiem tra node cuoi
			pTmp = pTmp->pNext;//tro tiep tuc
		}
		pTmp->pNext = pNode;//tro den pNode
	}
}

void RemoveNode(SingleList*& list, string d) {//xoa node khoi danh sach
	
	Node* pDel = list->pHead;
	if (pDel == NULL) {//danh sach rong
		cout << "The list is empty!";
	}
	else
	{
		Node* pPre = NULL;//tao node
		while (pDel != NULL) {
			Subjects* sub = pDel->data;
			if (sub->ma== d)//tim vi tri pDel
			{
				break;
			}
			pPre = pDel;//duyet tung node
			pDel = pDel->pNext;
		}
		if(pDel == NULL) {//ds khong chua node do
			cout << "Could not found number!";
		}
		else
		{
			if (pDel == list->pHead)//xoa node dau ds
			{
				list->pHead = list->pHead->pNext;//chuyen pHead den node tiep theo
				pDel->pNext = NULL;//cho node dau tro NULL
				delete pDel;//xoa node dau
				pDel = NULL;//cho gia tri node dau =NULL
			}
			else//xoa node o giua
			{
				pPre->pNext = pDel->pNext;//2 node cung tro den node sau
				pDel->pNext = NULL;//cat node pDel
				delete pDel;//xoa node pDel
				pDel = NULL;//cho node pDel=NULL
			}
		}
	}
}
Node* SearchNode(SingleList list, string d) {//tim kiem phan tu trong ds lk don
	Node* pTmp = list.pHead;// khoi tao biem tam
	while (pTmp != NULL) {//duyet ds
		Subjects* sub = pTmp->data;
		if (sub->ma== d) {//gap node can tim
			break;
		}
		pTmp = pTmp->pNext;
	}
	return pTmp;//xuat node
}
void SortList(SingleList& list) {//sap xep ds lk 
	for (Node* pTmp = list.pHead; pTmp != NULL; pTmp = pTmp->pNext)
	{
		for (Node* pTmp2 = pTmp->pNext; pTmp2 != NULL; pTmp2 = pTmp2->pNext)
		{
			if (pTmp->data > pTmp2->data) {
				Subjects* temp = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = temp;
			}
		}
	}
}
void Freememory(SingleList& list) {//huy danh sach
	cout << "\n-----------\n Starting to delete -------\n";
	while (list.pHead != NULL) {//duyet ds
		Node* pTmp = list.pHead;//khoi tao node tam
		list.pHead = pTmp->pNext;//dich node pHead
		pTmp->pNext = NULL;//cat node pTmp
		cout << pTmp->data << "is delete\n";
		delete pTmp;//xoa node pTmp
		pTmp = NULL;
	}
	cout << "Delete is complete \n------\n";
}
Subjects* Input() {
	Subjects* d = new Subjects;
	
	cout << "Ma:";
	getline(cin,d->ma);
	
	cout << "Name:";
	getline(cin, d->ma);
	cout << "Tin chi: ";
	cin >> d->tin_chi;
	cin.ignore();
	return d;
}
void Doc_File_Input(ifstream &in,SingleList* &list) {
	int dem = 0;
	while (in.eof() == false) {
		string x;
		getline(in, x, '\n');
		dem++;
	}
	in.seekg(0);
	Subjects** d = new Subjects * [dem / 3];
	for (int i = 0; i < dem / 3; i++)
		d[i] = new Subjects[dem / 3];
	for (int i = 0; i < dem / 3; i++)
	{
		getline(in, d[i]->ma);
		getline(in, d[i]->name);
		string line;
		getline(in, line);
		d[i]->tin_chi = atof(line.c_str());
		InsertLast(list, d[i]);
	}
}
int main() {
	SingleList* list;
	Initialize(list);
	//ifstream ifs ("Subjects.txt");
	//Doc_File_Input(ifs,list);
	//PrintList(list);
	cout << "\n";
	Subjects* Sub1 = Input();
	InsertFirst(list, Sub1);
	Subjects* Sub2 = Input();
	InsertFirst(list, Sub2);
	Subjects* Sub3 = Input();
	InsertFirst(list, Sub3);
	PrintList(list);
	//string x = "MI2020";
	//RemoveNode(list, x);
	//cout << "\n";
	//PrintList(list);
	return 0;
}