//Cai dat hang doi vong(Circular Queue) bang CTLT tuan tu 
#include<iostream>
#define MAX 5
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
void Enqueue(Queue &Q, int element, int& rear) {
    if(Q.n == MAX)            // Queue is full
        cout<<"OverFlow\n";
    else{
        Q.arr[rear] = element;
        rear = (rear + 1)%MAX;
        Q.n = Q.n + 1;
    }
}
void Dequeue(Queue &Q, int& front, int rear) {
    if(Q.n == 0)            // Queue is empty
        cout<<"UnderFlow\n";
    else {
        Q.arr[front] = 0;        // Delete the front element
        front = (front + 1)%MAX;
        Q.n = Q.n - 1;
    }
}
int Front(Queue Q, int front) {
    return Q.arr[front];
}
void Print(Queue Q,int front, int rear)
{
	cout<<"Cac phan tu trong hang doi la: ";
	if(rear==0&&front==0){
		for (int i = front; i < MAX; i++){
		    cout<<Q.arr[i]<<" ";
        }	
	}
	else if(rear==0&&front!=0)
	{
		for (int i = front; i <MAX; i++){
		    cout<<Q.arr[i]<<" ";
        }	
	}
    else{
        for (int i = front; i < rear; i++){
            cout<<Q.arr[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
	Queue Q;
	Initilize(Q);
	int front=0;
	int rear=0;
	Enqueue(Q, 77, rear);
	Dequeue(Q, front, rear);
	Enqueue(Q, 84, rear);
	Enqueue(Q, 81, rear);
	Dequeue(Q, front, rear);
	Enqueue(Q, 90, rear);
	Enqueue(Q, 91, rear);
	Enqueue(Q, 59, rear);
	Dequeue(Q, front, rear);
	//Dequeue(Q, front, rear);
	Print( Q, front, rear);
	cout<<"\nLay phan tu dau tien:"<<Front(Q, front) ;
	return 0;
}
