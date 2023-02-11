//1.Cai dat Stack va Queue bang DS moc noi don voi cac thao tac khoi tao, bo sung ,loai bo.Viet ctrinh chinh su dung Stack va Queue do
#include<iostream>
using namespace std;

template <typename T>
class Node
{
	private:
        T  data_; 
        Node<T>* pNext;
    public:
        Node() : pNext(NULL) { ; }
        void         set_data(T val) { data_ = val; }
        T            get_data() { return data_; }
        void         set_next(Node<T>* next) { pNext= next; }
        Node<T>* get_next() { return pNext; };

};
template <typename T>
class Stack{
	private:
		Node<T>* stack;
	public:
		Stack(){
			stack=NULL;
		}
	    Node<T> *CreateNode(int d){
	        Node<T> *pNode=new Node<T>();
	        pNode->set_data(d);
	        pNode->set_next(NULL);
        }
        void Push(int d){
	        Node<T> *pNode=CreateNode(d);
	        if(stack==NULL){
		        stack=pNode;
	        }
	        else
	        {
		        pNode->set_next(stack);
		        stack=pNode;
	        }
        }
        int Pop(){
	        int d=stack->get_data();
	        Node<T> *pDel=stack;
	        stack=stack->get_next();
	        pDel->set_next(NULL);
	        delete pDel;
	        pDel=NULL;
	        return d;
        }
        void Show(){
	        Node<T> *temp=stack;
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
	cout<<"\n";
	S.Show();
	return 0;
}
