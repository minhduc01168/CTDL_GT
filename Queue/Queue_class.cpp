#include<iostream>
#define MAX 100
using namespace std;
int front=-1;
int rear=-1; 
template<class T>
class Queue {
    T  info[MAX];
    int n;	//So phan tu cua Queue
public:
    //Khoi tao Queue
    Queue() {
        n = 0;
    }
    //Kiem tra Queue rong hay khong
    bool IsEmpty() {
        if (n == 0) return true;
        else return false;
    }

    //Kiem tra Queue day hay khong
    bool IsFull() {
        if (n == MAX) return true;
        else return false;
        //return (n==Max);
    }

    //Bo sung phan tu vao Queue
    void Push(T val) {
        if (rear == MAX- 1)
            cout<<"Tran hang doi"<<endl;
        else {
            if (front == - 1)
                front = 0;
            rear++;
            info[rear] = val;
        }
    }

    //Lay ra phan tu o dinh Stack
    void Pop() {
        if(front==-1||front==rear){
		    cout<<"Khong the xoa phan tu trong hang doi ";
            return ;
        } 
        else {
            cout<<"Phan tu da xoa khoi hang doi la: "<< info[front] <<endl;
            front++;;
        }
    }
    //Hien thi phan tu trong Stack
    void show() {
        if (front == - 1)
            cout<<"Hang doi rong!!"<<endl;
        else {
            cout<<"Cac phan tu trong hang doi la: ";
            for (int i = front; i <= rear; i++)
            {
			    cout<<info[i]<<" ";
			}
            cout<<endl;
        }
    }
};

int main(){
	Queue<int> Q;
	Q.Push(5);
	Q.Push(3);
	Q.Push(25);
	Q.Push(50);
	Q.Push(99);
	Q.show();
	cout<<endl;
	Q.Pop();
	Q.show();
	cout<<endl;
	
	return 0;
}
