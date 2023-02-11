//Cai dat 1 ds cac mon hoc, moi mon hoc gom: ma mon, ten mon, so tin chi.
//DS luon sap xep theo thu tu tang dan so tin chi 
//Y/c: Sd cau truc luu tru moc noi don de cai dat ds
//cai dat thao tac khoi tao,bo sung 1 mon, loai bo 1 mon co ma mon cho truoc, in ra noi dung cua DS
#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
template<class T>
class NodeData {//xay dung lop du lieu NodeData
private:
	T data;
	NodeData<T>* pNext;
public:
	NodeData() {
		pNext = NULL;
	}//khoi tao 1 NodeData
	void set_data(T val) {//Gan du lieu cho node
		data = val;
	}
	T get_data() const { return data; }//xuat du lieu data cua Node hien tai
	void set_next(NodeData<T>* next) {//gan pNext=next
		pNext = next;
	}
	NodeData<T>* get_next() const { return pNext; }//tra ve con tro pNext cua node hien tai
};
template<class T>
class LinkedList {
public:
	NodeData<T>* pHead;//tao con tro pHead tro vao phan tu dau tien
public:
	LinkedList() {//Ham khoi tao danh sach rong
		pHead = NULL;
	}
	~LinkedList() {
		while (pHead == NULL) {
			NodeData<T>* pTmp = new NodeData<T>();
			pTmp = pHead;
			pHead->set_next(pHead);
			pTmp->set_next(NULL);
			delete pTmp;
			pTmp = NULL;
		}
	}//ham huy
	NodeData<T>* CreateNode(T val) {//Ham tao node moi
		NodeData<T>* pNode = new NodeData<T>();//tao node moi rong (cap phat bo nho)
		if (pNode != NULL) {
			pNode->set_data(val);//gan gia tri cho node moi
			pNode->set_next(NULL);//gan cho con tro next 
		}
		else
		{
			cout << "Error allocated memory";
		}
		return pNode;
	}
	
	void Print() {//Ham xuat danh sach
		NodeData<T>* phead = pHead;
		if (phead != NULL)
		{
			NodeData<T>* temp = phead;
			while (temp != NULL)
			{
				temp->get_data().Show();//dung ham cua class khac van dc do public
				std::cout << "\n";
				temp = temp->get_next();
			}
		}
	}
	int SizeOfList() {//Ham dem so node
		NodeData<T>* pTmp = new NodeData<T>();
		pTmp = pHead;
		int size = 0;
		while (pTmp != NULL) {
			pTmp = pTmp->get_next();
			size++;
		}
		return size;
	}
	void InsertFirst1(T val) {//Ham chen phan tu vao dau danh sach
		NodeData<T>* temp = new NodeData<T>();//tao node moi rong
		temp->set_data(val);//gan gia tri cho node do
		temp->set_next(pHead);//pNext cua con tro moi la pHead hien tai
		pHead = temp;//chuyen con tro pHead ve dau
	}
	void InsertFirst(T val) {
		NodeData<T>* pNode = CreateNode(val);
		if (pHead == NULL) {//ds rong
			pHead = pNode;
		}
		else
		{
			pNode->set_next(pHead);//pNode tro phan tu dau
			pHead=pNode;//chuyen pHead ve dau danh sach
		}
		SortList();
	}
	void InsertLast(T val) {//Ham chen vao cuoi danh sach
		//NodeData<T> *pNode=new NodeData<T>();//tao node moi rong
		//pNode->set_data(val);
		NodeData<T>* pNode = CreateNode(val);
		if (pHead == NULL)//danh sach rong
		{
			pHead = pNode;
		}
		else
		{
			NodeData<T>* pTmp = new NodeData<T>();
			pTmp = pHead;//tao node tam
			while (pTmp->get_next() != NULL)//kiem tra node cuoi
			{
				pTmp = pTmp->get_next();//tro node tiep theo
			}
			pTmp->set_next(pNode);//tro den pNode
		}
		SortList();
	}
	void InsertBefore(NodeData<T>* P, T val) {//Ham chen 1 node vao sau node P
		NodeData<T>* Q = CreateNode(val);
		if (pHead == NULL) {
			pHead = Q;
		}
		else
		{
			if (P == NULL)return;
			Q->set_next(P->get_next());
			P->set_next(Q);
		}
		SortList();
	}
	void InsertAfter(NodeData<T>* P, T val) {//Ham chen 1 node moi vao truoc node P
		NodeData<T>* Q = CreateNode(val);
		if (pHead == NULL)
		{
			pHead = Q;
		}
		else
		{
			if (P == NULL)return;
			Q->set_data(P->get_data());
			P->set_data(val);
			Q->set_next(P->get_next());
			P->set_next(Q);
		}
		SortList();
	}
	void InsertMid(int pos, T val) {//Ham chen 1 node moi vao vi tri thu pos

		NodeData<T>* pNode = CreateNode(val);//tao node can chen
		NodeData<T>* pIns = new NodeData<T>();//tao node tam de duy ds
		pIns = pHead;
		NodeData<T>* pPre = new NodeData<T>();//node truoc vi tri chen
		int i = 0;
		while (pIns != NULL) {
			if (i == pos)//tim vi tri chen
			{
				break;
			}
			pPre = pIns;
			pIns = pIns->get_next();
			i++;
		}
		pNode->set_next(pIns);//noi node moi voi node sau
		pPre->set_next(pNode);//noi node phia truoc voi node moi
		SortList();
	}
	NodeData<T>* SearchNode(T val) {//Ham tim kiem phan tu co data val
		NodeData<T>* pTmp = new NodeData<T>();
		pTmp = pHead;
		while (pTmp != NULL) {
			if (pTmp->get_data() == val) {
				break;
			}
			pTmp = pTmp->get_next();
		}
		return pTmp;
	}
	
	void RemoveNode(T val) {
		NodeData<T>* pDel = new NodeData<T>();
		pDel = pHead;
		if (pHead == NULL)//danh sach rong
		{
			cout << "The list empty!";
		}
		else
		{
			NodeData<T>* pPre = new NodeData<T>();//node phia truoc node can xoa
			while (pDel != NULL) {//tim vi tri node pDel
				if (pDel->get_data() == val) {
					break;
				}
				pPre = pDel;
				pDel = pDel->get_next();
			}
			if (pDel == NULL) {//danh sach khong chua node do
				cout << "Could not found number!";
			}
			else
			{
				if (pDel == pHead) {//xoa node dau danh sach
					pHead = pHead->get_next();//chuyen pHead den node tiep theo
					pDel->set_next(NULL);//cho node dau tro NULL
					delete pDel;//xoa node dau
					pDel = NULL;
				}
				else//xoa node giua
				{
					pPre->set_next(pDel->get_next());//Node pPre tro den node sau node can xoa
					pDel->set_next(NULL);//cat node pDel
					delete pDel;
					pDel = NULL;
				}
			}
		}
		SortList();
	}
	void SortList()
	{
		NodeData<T>* pTmp = new NodeData<T>();
		NodeData<T>* pTmp2 = new NodeData<T>();
		for (pTmp = pHead; pTmp != NULL; pTmp = pTmp->get_next())
		{
			for (pTmp2 = pTmp->get_next(); pTmp2 != NULL; pTmp2 = pTmp2->get_next())
			{
				T sub1=pTmp->get_data();
				T sub2=pTmp2->get_data();
				if (sub1 > sub2)
				{
					T temp = pTmp->get_data();
					pTmp->set_data(pTmp2->get_data());
					pTmp2->set_data(temp);
				}
			}
		}
	}
	NodeData<T>* head() { return pHead; };

};
class Subjects {
private:
	string ma;
	string name;
	int tc;
public:
	Subjects() {
		ma = "";
		name = "";
		tc=0;
	}
	Subjects(string ma, string name, int tc) {
		this->ma = ma;
		this->name = name;
		this->tc = tc;
	}
	~Subjects() {
		ma = "";
		name = "";
		tc = 0;
	}
	string get_ma()const { return ma; }
	string get_name()const { return name; }
	int get_tc()const { return tc; }
	void Show() {
		cout << setw(10) << left << (this->ma).c_str()<< setw(30) << left << (this->name).c_str() << setw(10) << left << this->tc << endl;
	}
	bool operator==(Subjects& p) {
		if (this->ma == p.ma )
			return true;
		else return false;
	}
	bool operator>(Subjects& p) {
		if (this->tc > p.tc )
			return true;
		else return false;
	}
	
};
int main() {
	LinkedList<Subjects> List;

	Subjects sub1("ET2050", "Ly thuyet mach", 3);
	Subjects sub2("ET2040", "Cau kien dien tu", 3);
	Subjects sub3("MI1131", "Giai tich 3", 3);
	Subjects sub4("ET2072", "Ly thuyet thong tin", 2);
	Subjects sub5("ED3280", "Tam ly hoc ung dung", 2);
	Subjects sub6("ET2060", "Tin hieu he thong", 3);
	Subjects sub7("IT1110", "Tin hoc dai cuong", 4);
	List.InsertFirst(sub1);
	List.InsertLast(sub2);
	List.InsertFirst(sub3);
	List.InsertFirst(sub4);
	List.InsertFirst(sub6);
	List.InsertLast(sub5);
	List.InsertLast(sub7);
	List.Print();
	cout << "Tim kiem mon hoc :"<<endl;
	NodeData<Subjects>* pTmp = List.SearchNode(sub5);
	cout << pTmp->get_data().get_ma() << "    " << pTmp->get_data().get_name() << "     " << pTmp->get_data().get_tc()<< endl;//xuat data
	cout << "Xoa mon hoc:" << endl;
	List.RemoveNode( sub5);
	List.Print();
	//cout<<"Sap xep theo chieu tang dan so tc:"<<endl;
	//List.SortList();
	//List.Print();
	return 0;
}
