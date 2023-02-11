//Cai dat hang doi hai dau(Double_ended Queue) bang CTLT tuan tu 
#include<iostream>
#define MAX 100
using namespace std;

typedef struct {
	int arr[MAX];
    int n;//So phan tu cua Queue
}Queue;
void Initilize(Queue &Q)//tao Hang doi rong
{
	Q.n=0;
}
bool IsEmpty(Queue Q)//Check hang doi co rong 
{
	if( Q.n==0){
		return true;
	}
	else return false;
}
bool IsFull(Queue Q){//Check hang doi da full chua
	if(Q.n==MAX){
		return true;
	}
	else return false;
}
void InsertAtBack(Queue &Q,int element, int &rear){//Them phan tu vao cuoi hang doi 
    if(rear == MAX)
        cout<<"Overflow\n";
    else{
        Q.arr[rear] = element;
        rear = rear + 1;
    }
}
void DeleteFromBack(Queue &Q, int &rear, int front){//Xoa phan tu cuoi
    if(front == rear)
        printf("Underflow\n");
    else{
        rear = rear - 1;
        Q.arr[rear] = 0;
    }
}
void InsertAtFront(Queue &Q, int &rear, int &front, int element){//Them vao dau du lieu
    if(rear == MAX)
        printf("Overflow\n");
    else{
        for(int i=rear; i>front; i--)
            Q.arr[i] = Q.arr[i-1];//dich cac phan tu ve phia sau 1 phan tu 
        Q.arr[front] = element;
        rear = rear+1;
    }
}
void DeleteAtFront(Queue &Q, int &front, int &rear){//Xoa du lieu o dau queue 
    if(front == rear)
        printf("Underflow\n");
    else{
        Q.arr[front] = 0;
        front = front + 1;
    }
}
int GetFront(Queue &Q, int front){//Lay gia tri o dau queue 
    return Q.arr[front];
}
int GetRear(Queue Q, int rear){//Lay phan tu o cuoi queue 
    return Q.arr[rear-1];
}
void Print(Queue Q,int front, int rear)
{
    cout<<"Cac phan tu trong hang doi la: ";
    for (int i = front; i < rear; i++){
        cout<<Q.arr[i]<<" ";
    }
        cout<<endl;
}
int main(){
	Queue Q;
	Initilize(Q);
	int front=0;
	int rear=0;
	InsertAtBack( Q,10, rear);
	InsertAtBack( Q,11, rear);
	Print(Q,front,rear);
    InsertAtFront(Q, rear, front, 113);
    InsertAtFront(Q, rear, front, 9);
    Print(Q,front,rear);
    cout<<"Xoa phan tu cuoi:"<<endl;
    DeleteFromBack(Q,rear,front);
    Print(Q,front,rear);
    cout<<"\nXoa phan tu dau:"<<endl;
    DeleteAtFront(Q,front, rear);
    Print(Q,front,rear);
    cout<<"Lay phan tu dau:"<<GetFront(Q,front)<<endl;
    cout<<"Lay phan tu cuoi:"<<GetRear(Q,rear)<<endl;
	return 0;
} 
