//Cai dat Queue bang ds moc noi don voi cac thao tac khoi tao, bo sung, loai bo.Viet chuong trinh chinh su dung Queue do
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
class Queue{
	private:
		Node<T>* queue;
	public:
		Queue(){
			queue=NULL;
		}
	    Node<T> *CreateNode(int d){
	        Node<T> *pNode=new Node<T>();
	        pNode->set_data(d);
	        pNode->set_next(NULL);
        }
        void Push(int d){
	        Node<T> *pNode=CreateNode(d);
	        Node<T> *temp=queue;
	        if(queue==NULL){
		        queue=pNode;
	        }
	        else
	        {
		        Node<T> *pTmp=queue;
				while(pTmp->get_next()!=NULL)//kiem tra node cuoi
				{
					pTmp=pTmp->get_next();//tro node tiep theo
				}
				pTmp->set_next(pNode);//tro den pNode
		        
	        }
        }
        int Pop(){
	        int d=queue->get_data();
	        Node<T> *pDel=queue;
	        queue=queue->get_next();
	        pDel->set_next(NULL);
	        delete pDel;
	        pDel=NULL;
	        return d;
        }
        void Show(){
	        Node<T> *temp=queue;
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
	cout<<"\n";
	Q.Show();
	return 0;
}
