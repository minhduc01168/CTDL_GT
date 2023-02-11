#include <iostream>
#include <cstdio>
 
using namespace std;
 
void Enqueue(int queue[], int element, int& rear, int arraySize) {
    if(rear == arraySize)            // Queue is full
        printf("OverFlow\n");
    else {
        queue[rear] = element;    // Add the element to the back
        rear++;
    }
}
 
 
void Dequeue(int queue[], int& front, int rear) {
    if(front == rear)            // Queue is empty
        printf("UnderFlow\n");
    else {
        queue[front] = 0;        // Delete the front element
        front++;
    }
}
void Print(int queue[],int front,int rear)
 {
 	for(int i = front;i < rear;++i)
        cout<<queue[i]<<"   ";
    cout<<"\n";
    cout<<front<<"---"<<rear<<endl;
 }
 
int main() {
    int queue[4];        
    int front = 0, rear = 0;                
    int arraySize = 10;                // Size of the array
    Enqueue(queue, 51, rear, arraySize); 
    Dequeue(queue, front, rear);
	Enqueue(queue, 42, rear, arraySize);
	Enqueue(queue, 13, rear, arraySize); 
	Dequeue(queue, front, rear);
	Enqueue(queue, 64, rear, arraySize);
	Dequeue(queue, front, rear);
	Enqueue(queue, 25, rear, arraySize);
	Enqueue(queue, 86, rear, arraySize);
	Dequeue(queue, front, rear);
	Print(queue,front,rear);
	return 0;
}
