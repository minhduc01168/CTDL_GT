#include<iostream>
#include<math.h>
using namespace std;
int a[20];
bool Check(int x2,int y2){//Kiem tra vi tri toa do x2,y2
    //kiem tra c�ch dat c� thoa m�n kh�ng
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )//kiem tra 2 quan hau cungf cot va cung duong cheo
            return false;
    //Neu kiem tra het c�c truong hop van kh�ng sai th� tri vi true
    return true;
}
 
void Xuat(int n){
    //in ra mot ket qua
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
 
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        // thu dat qu�n hau v�o c�c cot tu 1 den n
        if(Check(i,j)){
            //neu c�ch dat n�y thoa m�n th� luu lai vi tr�
            a[i] = j;
            //neu dat xong qu�n hau thu n th� xuat ra mot ket qua
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
int main(){
    int n = 8;//  d�y m�nh cho b�i to�n l� 8 qu�n hau tr�n b�n 8*8
    Try(1,n);
    return 0;
}
