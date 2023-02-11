//Bai2 Cai dat danh sach tong quat bang CTLT tuan tu (voi danh sach tong quat ,viec bo sung va lay ra mot phan tu co the thuc hien o mot vi tri bat ki trong danh sach 
#include<iostream>
#define MAX 20
using namespace std;

typedef struct{
	int arr[MAX];
	int n;// so phan tu cua danh sach
}List;
void Initilize( List *L){
	L->n=0;
}
bool IsEmpty(List *L)
{
	if(L->n==0)
	{
		return true;
	}
	else return false;
}
void Inser_List(List *L, int p,int x)
{
	if(L->n==MAX){
		cout<<"Danh sach day";
	}
	else if(p<1||p>MAX){
		cout<<"Vi tri khong hop le";
	}
	else
	{
		for(int i=(L->n-1)+1;i>p-1;i--){
			L->arr[i]=L->arr[i-1];
		}
		L->arr[p-1]=x;
		L->n++;
	}
}
void Delete_List(List *L,int p)
{
	if(p<1||p>MAX){
		cout<<"vi tri khong hop le";
	}
	else if(IsEmpty(L)){
		cout<<"Danh sach rong";
	}
	else
	{
		for(int i=p-1;i<L->n;i++){
			L->arr[i]=L->arr[i+1];
		}
		L->n--;
	}
}
void Search_List(List *L,int x){
	int dem=0;
	for(int i=0;i<L->n;i++){
		if(L->arr[i]==x){
			cout<<"Tim thay "<<x<<" o vi tri thu "<<i+1<<endl;
			dem++;
		}
	}
	if(dem==0){
	    cout<<"Khong tim thay";
	}
}
int main(){
	List *L=new List;
	cout<<"Nhap a=";
	cin>>L->n;
	cout<<"Nhap du lieu"<<endl;
	for(int i=0;i<L->n;i++){
		cin>>L->arr[i];
	}
	for(int i=0;i<L->n;i++){
		cout<<L->arr[i]<<"   ";
	}
	cout<<endl;
	Inser_List(L, 3,113);
	for(int i=0;i<L->n;i++){
		cout<<L->arr[i]<<"   ";
	}
	cout<<endl;
	Delete_List(L,3);
	for(int i=0;i<L->n;i++){
		cout<<L->arr[i]<<"    ";
	}
	cout<<endl;
	Search_List(L,4);
	return 0;
} 
