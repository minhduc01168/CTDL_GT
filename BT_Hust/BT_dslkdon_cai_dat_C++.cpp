#include<iostream>
using namespace std;
template<class T>
class NodeData{//xay dung lop du lieu NodeData
	private:
		T data;
		NodeData<T> *pNext;
	public:
		NodeData(){
		    pNext=NULL;
		}//khoi tao 1 NodeData
		void set_data(T val){//Gan du lieu cho node
			data=val;
		}
		T get_data() const{return data;}//xuat du lieu data cua Node hien tai
		void set_next(NodeData<T> *next){//gan pNext=next
			pNext=next;
		}
		NodeData<T> *get_next( ) const {return pNext;}//tra ve con tro pNext cua node hien tai
		
};
template<class T>
class LinkedList{
	public:
		NodeData<T> *pHead;//tao con tro pHead tro vao phan tu dau tien
	public:
		LinkedList(){//Ham khoi tao danh sach rong
			pHead=NULL;
		}
		~LinkedList(){;}//ham huy
		NodeData<T> *CreateNode(T val){//Ham tao node moi
			NodeData<T> *pNode=new NodeData<T>();//tao node moi rong (cap phat bo nho)
			if(pNode!=NULL){
				pNode->set_data(val);//gan gia tri cho node moi
				pNode->set_next(NULL);//gan cho con tro next 
			}
			else
			{
				cout<<"Error allocated memory";
			}
			return pNode;
		}
		void PrintList(){//Ham xuat danh sach
			NodeData<T> *pTmp=new NodeData<T>();
			pTmp=pHead;
			if(pTmp==NULL){// ds rong
				cout<<"The list is empty!";
				return ;
			}
			while(pTmp!=NULL){//duyet
				cout<<pTmp->get_data()<<"   ";//xuat data
				pTmp=pTmp->get_next();//tro den node tiep theo 
			}
		}
		int SizeOfList(){//Ham dem so node
			NodeData<T> *pTmp=new NodeData<T>();
			pTmp=pHead;
			int size=0;
			while(pTmp!=NULL){
				pTmp=pTmp->get_next();
				size++;
			}
			return size;
		}
		void InsertFirst1(T val){//Ham chen phan tu vao dau danh sach
			NodeData<T> *temp=new NodeData<T>();//tao node moi rong
			temp->set_data(val);//gan gia tri cho node do
			temp->set_next(pHead);//pNext cua con tro moi la pHead hien tai
			pHead=temp;//chuyen con tro pHead ve dau
		}
		void InsertFirst(T val){
			NodeData<T> *pNode=CreateNode(val);
			if(pHead==NULL){//ds rong
			    pHead=pNode;
			}
			else
			{
				pNode->set_next(pHead);//pNode tro phan tu dau
				pHead->set_next(pNode);//chuyen pHead ve dau danh sach
			}
		}
		void InsertLast(T val){//Ham chen vao cuoi danh sach
			//NodeData<T> *pNode=new NodeData<T>();//tao node moi rong
			//pNode->set_data(val);
			NodeData<T> *pNode=CreateNode(val);
			if(pHead==NULL)//danh sach rong
			{
				pHead=pNode;
			}
			else
			{
				NodeData<T> *pTmp=new NodeData<T>();
				pTmp=pHead;//tao node tam
				while(pTmp->get_next()!=NULL)//kiem tra node cuoi
				{
					pTmp=pTmp->get_next();//tro node tiep theo
				}
				pTmp->set_next(pNode);//tro den pNode
			}	
		}
		void InsertBefore(NodeData<T> *P,T val){//Ham chen 1 node vao sau node P
			NodeData<T> *Q=CreateNode(val);
			if(pHead==NULL){
				pHead=Q;
			}
			else
			{
				if(P==NULL)return ;
				Q->set_next(P->get_next());
				P->set_next(Q);
			}	
		}
		void InsertAfter(NodeData<T> *P,T val){//Ham chen 1 node moi vao truoc node P
			NodeData<T> *Q=CreateNode(val);
			if(pHead==NULL)
			{
				pHead=Q;
			}
			else
			{
				if(P==NULL)return ;
				Q->set_data(P->get_data());
				P->set_data(val);
				Q->set_next(P->get_next());
				P->set_next(Q);
			}
		}
		void InsertMid(int pos,T val){//Ham chen 1 node moi vao vi tri thu pos
			
			NodeData<T> *pNode=CreateNode(val);//tao node can chen
			NodeData<T> *pIns=new NodeData<T>();//tao node tam de duy ds
			pIns=pHead;
			NodeData<T> *pPre=new NodeData<T>();//node truoc vi tri chen
			int i=0;
			while(pIns!=NULL){
				if(i==pos)//tim vi tri chen
				{
					break;
				}
				pPre=pIns;
				pIns=pIns->get_next();
				i++;
			}
			pNode->set_next(pIns);//noi node moi voi node sau
			pPre->set_next(pNode);//noi node phia truoc voi node moi
	    }
		NodeData<T> *SearchNode(T val){//Ham tim kiem phan tu co data val
			NodeData<T> *pTmp=new NodeData<T>();
			pTmp=pHead;
			while(pTmp!=NULL){
				if(pTmp->get_data()==val){
					break;
				}
				pTmp=pTmp->get_next();
			}
			return pTmp;
		}
		void RemoveNode(T val){
			NodeData<T> *pDel=new NodeData<T>();
			pDel=pHead;
			if(pHead==NULL)//danh sach rong
			{
				cout<<"The list empty!";
			} 
			else
			{
				NodeData<T> *pPre=new NodeData<T>();//node phia truoc node can xoa
				while(pDel!=NULL){//tim vi tri node pDel
					if(pDel->get_data()==val){
						break;
					}
					pPre=pDel;
					pDel=pDel->get_next();
				}
				if(pDel==NULL){//danh sach khong chua node do
					cout<<"Could not found number!";
				}
				else
				{
					if(pDel==pHead){//xoa node dau danh sach
					    pHead=pHead->get_next();//chuyen pHead den node tiep theo
					    pDel->set_next(NULL);//cho node dau tro NULL
					    delete pDel;//xoa node dau
					    pDel=NULL;
					}
					else//xoa node giua
					{
						pPre->set_next(pDel->get_next());//Node pPre tro den node sau node can xoa
						pDel->set_next(NULL);//cat node pDel
						delete pDel;
						pDel=NULL;
					}
				}
			}
		}
		void SortList()
		{
			NodeData<T> *pTmp=new NodeData<T>();
			NodeData<T> *pTmp2=new NodeData<T>();
			for(pTmp=pHead;pTmp!=NULL;pTmp=pTmp->get_next())
			{
				for(pTmp2=pTmp->get_next();pTmp2!=NULL;pTmp2=pTmp2->get_next())
				{
					if(pTmp->get_data()>pTmp2->get_data())
					{
						int temp=pTmp->get_data();
						pTmp->set_data(pTmp2->get_data());
						pTmp2->set_data(temp);
					}
				}
			}
		}	
		
};
int main(){
	LinkedList<int> L;
	L.InsertFirst(8);
	L.InsertLast(9);
	L.InsertLast(7);
	L.InsertLast(113);
	L.InsertLast(6);
	L.InsertLast(10);
	NodeData<int> *p=L.SearchNode(113);
	L.InsertAfter(p,99);
	L.InsertBefore(L.SearchNode(113),66);
	L.InsertMid(4,1000);
	L.PrintList();
	cout<<"\nDanh sach sau khi xoa:"<<endl;
	L.RemoveNode(99);
	L.PrintList();
	cout<<"\nDanh sach sau khi sap xep:"<<endl;
	L.SortList();
	L.PrintList();
	int size=L.SizeOfList();
	cout<<"\nSo phan tu cua danh sach:"<<size;

	return 0;
}
