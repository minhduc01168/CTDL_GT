//Cai dat cau truc FIFO ( Queue) bang cau truc luu tru tuan tu 
#include <iostream>
#define MAX 10
using namespace std;
int front=-1;
int rear=-1; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
	int arr[MAX];
	unsigned int n;//So phan tu cua Queue
}Queue;
void Initilize(Queue *Q)
{
	Q->n=0;
}
bool IsEmpty(Queue *Q)
{
	if( Q->n==0){
		return true;
	}
	else return false;
}
bool IsFull(Queue *Q){
	if(Q->n==MAX){
		return true;
	}
	else return false;
}
void Push(Queue *Q, int k)
{
   if (rear == MAX- 1)
        cout<<"Tran hang doi"<<endl;
   else {
      if (front == - 1)
        front = 0;
      rear++;
      Q->arr[rear] = k;
   }
}
void Pop(Queue *Q)//lay phan tu dau hang doi
{
	if(front==-1||front==rear){
		cout<<"Khong the xoa phan tu trong hang doi ";
      return ;
   } 
   else {
      cout<<"Phan tu da xoa khoi hang doi la: "<< Q->arr[front] <<endl;
      front++;;
   }
}
void Print(Queue *Q)
{
	if (front == - 1)
        cout<<"Hang doi rong!!"<<endl;
   else {
      cout<<"Cac phan tu trong hang doi la: ";
      for (int i = front; i <= rear; i++){
            cout<<Q->arr[i]<<" ";
        }
        cout<<endl;
   }

}
int main(int argc, char** argv) {
	Queue *Q=new Queue;
	Initilize(Q);
	Push(Q,1);
	Push(Q,5);
	Push(Q,9);
	Push(Q,10);
	Push(Q,113);
	Print(Q);
	Pop(Q);
	
	return 0;
}
