#include<iostream>
#include<math.h>
using namespace std;
int a[20];
bool Check(int x2,int y2){//Kiem tra vi tri toa do x2,y2
    //kiem tra cách dat có thoa mãn không
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )//kiem tra 2 quan hau cungf cot va cung duong cheo
            return false;
    //Neu kiem tra het các truong hop van không sai thì tri vi true
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
        // thu dat quân hau vào các cot tu 1 den n
        if(Check(i,j)){
            //neu cách dat này thoa mãn thì luu lai vi trí
            a[i] = j;
            //neu dat xong quân hau thu n thì xuat ra mot ket qua
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
int main(){
    int n = 8;//  dây mình cho bài toán là 8 quân hau trên bàn 8*8
    Try(1,n);
    return 0;
}
