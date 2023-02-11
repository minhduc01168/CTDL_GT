//Cai dat hang doi Uu tien(Priority Queue) bang CTLT tuan tu 
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
void Enqueue(Queue &Q, int element, int& rear) {
    if(rear == MAX)            // Queue is full
            printf("OverFlow\n");
    else{
         Q.arr[rear] = element;    // Add the element to the back
         rear++;
        Q.n++;
    }
    for (int i = 0; i < Q.n-1; i++){
        for (int j = 0; j < Q.n-i-1; j++){
            if (Q.arr[j] < Q.arr[j+1]){
                swap(Q.arr[j], Q.arr[j+1]);
            }
        }
    }
}
void Dequeue(Queue &Q, int& front, int rear) {
    if(front == rear)            // Queue is empty
        printf("UnderFlow\n");
    else {
        Q.arr[front] = 0;        // Delete the front element
        front++;
        Q.n--;
    }
}
void Print(Queue Q,int front,int rear)
{
    for (int i = front; i < rear; i++){
            cout<<Q.arr[i]<<" ";
        }
        cout<<endl;
}
int main(int argc, char** argv) {
	Queue Q;
	Initilize(Q);
	int rear=0;
	int front=0;
	Enqueue(Q, 12, rear);
	Enqueue(Q, 13, rear);
	Enqueue(Q, 6, rear);
    Enqueue(Q, 9, rear);
    Enqueue(Q, 1, rear);

	Print(Q,front,rear);
	Dequeue(Q, front, rear);
	Dequeue(Q, front, rear);
	Print(Q,front,rear);
	
	return 0;
}
