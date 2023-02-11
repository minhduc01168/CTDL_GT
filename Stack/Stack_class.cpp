#include<iostream>
#define MAX 100
using namespace std;
template<class T>
class Stack {
    T  info[MAX];
    int n;	//So phan tu cua Stack
public:
    //Khoi tao Stack
    Stack() {
        n = 0;
    }
    //Kiem tra Stack rong hay khong
    bool IsEmpty() {
        if (n == 0) return true;
        else return false;
    }

    //Kiem tra Stack day hay khong
    bool IsFull() {
        if (n == MAX) return true;
        else return false;
        //return (n==Max);
    }

    //Bo sung phan tu vao Stack
    void Push(T K) {
        if (IsFull()) return;
        info[n] = K;
        n++;
    }

    //Lay ra phan tu o dinh Stack
    T Pop() {
        if (IsEmpty()) return NULL;
        n--;
        return info[n];
    }

    //Tra phan tu o dinh Stack, khong lay ra phan tu do
    T Top() {
        if (IsEmpty()) return NULL;
        return info[n - 1];
    }

    //Hien thi phan tu trong Stack
    void show() {
        if (IsEmpty())
            return;
        for (int i = n-1; i >= 0; i--){
            cout << info[i] << "\t";
        }
        cout << endl;
    }
};

int main(){
	Stack<int> S;
	S.Push(5);
	S.Push(3);
	S.Push(25);
	S.Push(50);
	S.Push(99);
	S.show();
	cout<<endl;
	S.Pop();
	S.show();
	cout<<endl;
	cout<<S.Top()<<endl;
	
	return 0;
}
