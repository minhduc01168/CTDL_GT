//2.Cai dat Stack bang DS moc noi kep voi thao tac khoi tao, bo sung , loai bo. Viet ctrinh chinh su dung stack
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
class Stack{
	private:
		NodeData<T> *stack;
	public:
		Stack(){//Khoi Tao danh sach rong
			stack=NULL;
		}
		~Stack(){
			//Giai phong vung nho khi ket thuc ctrinh
			NodeData<T> *temp=stack;
			while(temp!=NULL){
				stack=stack->get_next();
				delete temp;
				temp=stack;
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
	        if(stack==NULL){
		        stack=pNode;
	        }
	        else
	        {
		        pNode->set_next(stack);
		        stack->set_prev(pNode);
		        stack=pNode;
		        pNode->set_prev(NULL);
	        }
        }
        int Pop(){
	        int d=stack->get_data();
	        NodeData<T> *pDel=stack;
	        stack=stack->get_next();
	        stack->set_prev(NULL);
	        pDel->set_next(NULL);
	        pDel->set_prev(NULL);
	        delete pDel;
	        pDel=NULL;
	        return d;
        }
        void Show(){
	        NodeData<T> *temp=stack;
	        while(temp!=NULL){
			    cout<<temp->get_data()<<"   ";
			    temp=temp->get_next();
			}
        }
};
int main(){
	Stack<int> S;
	S.Push(1);
	S.Push(7);
	S.Push(9);
	S.Push(18);
	S.Push(15);
	S.Show();
	S.Pop();
	S.Pop();
	cout<<"\n";
	S.Show();
	return 0;
}
