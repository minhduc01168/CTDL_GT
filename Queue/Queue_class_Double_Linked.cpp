//2.Cai dat Queue bang DS moc noi kep voi thao tac khoi tao, bo sung , loai bo. Viet ctrinh chinh su dung Queue
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
class Queue{
	private:
		NodeData<T> *queue;
	public:
		Queue(){//Khoi Tao danh sach rong
			queue=NULL;
		}
		~Queue(){
			//Giai phong vung nho khi ket thuc ctrinh
			NodeData<T> *temp=queue;
			while(temp!=NULL){
				queue=queue->get_next();
				delete temp;
				temp=queue;
			}
		}
		NodeData<T> *CreateNode(int d){
	        NodeData<T> *pNode=new NodeData<T>();
	        pNode->set_data(d);
	        pNode->set_next(NULL);
	        pNode->set_prev(NULL);
        }
        void Push(int d){
	        NodeData<T> *pNode=CreateNode(d);
	        if(queue==NULL){
		        queue=pNode;
	        }
	        else
	        {
	        	NodeData<T> *temp=queue;
		        while(temp->get_next()!=NULL){
					temp=temp->get_next();
				}
				temp->set_next(pNode);
				pNode->set_prev(temp);
				pNode->set_next(NULL);
	        }
        }
        int Pop(){
	        int d=queue->get_data();
	        NodeData<T> *pDel=queue;
	        queue=queue->get_next();
	        queue->set_prev(NULL);
	        pDel->set_next(NULL);
	        pDel->set_prev(NULL);
	        delete pDel;
	        pDel=NULL;
	        return d;
        }
        void Show(){
	        NodeData<T> *temp=queue;
	        while(temp!=NULL){
			    cout<<temp->get_data()<<"   ";
			    temp=temp->get_next();
			}
        }
};
int main(){
	Queue<int> Q;
	Q.Push(1);
	Q.Push(7);
	Q.Push(9);
	Q.Push(18);
	Q.Push(15);
	Q.Show();
	Q.Pop();
	Q.Pop();
	cout<<"\n";
	Q.Show();
	return 0;
}
