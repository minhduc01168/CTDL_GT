#include<iostream>
using namespace std;
template <class T>
class NodeData{
	private:
		T data;
		NodeData<T> *pNext;
		NodeData<T> *pPrev;
	public:
		NodeData(){//Tao node rong
			pNext=NULL;
			pPrev=NULL;
		}
		void set_data(T val){//Ham gan gia tri cho data
			data=val;
		}
		T get_data()const{return data;};//Ham tra ve gia tri data
		void set_next(NodeData<T> *next){//Ham gan pNext cua node bang next
			pNext=next;
		}
		NodeData<T> *get_next()const{return pNext;}//Ham tra ve pNext cua node hien tai
		void set_prev(NodeData<T> *prev){//Ham gan pPrev cua node bang prev
			pPrev=prev;
		}
		NodeData<T> *get_prev()const{return pPrev;}//Ham tra ve pPrev cua node hien tai
};
template<class T>
class DoubleList{
	private:
		NodeData<T> *pHead;
	public:
		DoubleList(){//Khoi Tao danh sach rong
			pHead=NULL;
		}
		~DoubleList(){
			//Giai phong vung nho khi ket thuc ctrinh
			NodeData<T> *temp=pHead;
			while(temp!=NULL){
				pHead=pHead->get_next();
				delete temp;
				temp=pHead;
			}
		}
		//Chen truoc danh sach
		void InsertFirst(T val){
			NodeData<T> *temp=new NodeData<T>();
			temp->set_data(val);
			temp->set_next(pHead);
			temp->set_prev(NULL);
			if(pHead!=NULL){
				pHead->set_prev(temp);
			}
			pHead=temp;
		}
		//chen sau danh sach
		void InsertLast(T val){
			NodeData<T> *last=pHead;//tim node cuoi
			if(last==NULL){
				NodeData<T> *temp=new NodeData<T>();
				temp->set_data(val);
				pHead=temp;
				last=temp;
			}
			else
			{
				while(last->get_next()!=NULL){
					last=last->get_next();
				}
				NodeData<T> *temp=new NodeData<T>();
				temp->set_data(val);
				temp->set_next(NULL);
				temp->set_prev(last);
				last->set_next(temp);
			}
		}
		//Chen sau 1 Node da co
		void InsertAfter(NodeData<T> *pNode,T val){
			if(pNode!=NULL){
				NodeData<T> *temp=new NodeData<T>();
				temp->set_data(val);
				temp->set_next(pNode->get_next());
				//next cua temp=next cua Node hien tai
				temp->set_prev(pNode);//prev cua temp =Node
				pNode->set_next(temp);//next node=temp
				if(temp->get_next()!=NULL){
					temp->get_next()->set_prev(temp);
					//prev cua next cua pNode =temp
				}
			}
		}
		//Chen truoc 1 Node da co
		void InsertBefore(NodeData<T> *pNode,T val){
			if(pNode!=NULL){
				NodeData<T> *temp=new NodeData<T>();
				temp->set_data(val);
				temp->set_next(pNode);
				temp->set_prev(pNode->get_prev());
				pNode->get_prev()->set_next(temp);
				pNode->set_prev(temp);
			}
		}
		void RemoveFront(T val)//ham xoa phan tu
		{
			NodeData<T> *pDel=new NodeData<T>();
			pDel=pHead;
			//NodeData<T> *pDel=pHead;
			if(pDel==NULL){//Ds rong
				cout<<"The list is empty!";
				return;
			}
			NodeData<T> *pPre=new NodeData<T>();
			while(pDel!=NULL){
				if(pDel->get_data()==val){//tim phan tu can xoa
				    break;
				}
		        pPre=pDel;
		        pDel=pDel->get_next();
		    }
		    if(pDel==NULL)//tim khong thay node can xoa
		    {
		    	cout<<"Could not found number!";
			}
			else
			{
				if(pDel==pHead){//xoa node dau
				   pHead=pHead->get_next();
				   pDel->set_next(NULL);
				   pHead->set_prev(NULL);
				}
				else if(pDel->get_next()==NULL)//xoa node cuoi
				{
					pDel->set_prev(NULL);
					pPre->set_next(NULL);
					
				}
				else{//xoa o giua danh sach
				    pPre->set_next(pDel->get_next());
				    pDel->get_next()->set_prev(pPre);
				    pDel->set_prev(NULL);
				    pDel->set_next(NULL);
				}
				delete pDel;
				pDel=NULL;
			}
	    }
	    void PrintList(){
	    	NodeData<T> *pTmp=new NodeData<T>();
	    	pTmp=pHead;
	    	if(pTmp==NULL){
	    		cout<<"The list is empty!";
	    		return;
			}
			while(pTmp!=NULL){
				cout<<pTmp->get_data()<<"   ";
				pTmp=pTmp->get_next();
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
};
int main(){
	DoubleList<int> L;
	L.InsertFirst(6);
	L.InsertLast(7);
	L.InsertLast(10);
	L.InsertLast(20);
	L.InsertLast(66);
	L.InsertAfter(L.SearchNode(7),100);
	L.InsertBefore(L.SearchNode(20),111);
	L.PrintList();
	cout<<"\nDanh sach sau khi sap xep:"<<endl;
	L.SortList();
	L.PrintList();
	cout<<"\nSo phan tu cua danh sach:"<<L.SizeOfList();
	L.RemoveFront(66);
	cout<<"\nXoa phan tu:"<<endl;
	L.PrintList();
	return 0;
}
