
//Viet ham tim UCLN cua cua 2 so nguyen a,b .Sd de quy va khu de quy
#include<iostream>
using namespace std;
int UCLN1(int m,int n){
	int r;
	if(m<n) return UCLN1(n,m);
	r=m%n;
	if(r==0){
		return n;
	}
	else
	{
		return UCLN1(n,r);
	}
}
int UCLN2(int a, int b){
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; // a = a - b
        }else{
            b -= a;
        }
    }
    return a; // return a 
}
int main(){
	int m,n;
	cin>>m;
	cin>>n;
	cout<<"UCLN(de quy):"<<UCLN1(m,n)<<endl;
	cout<<"UCLN(khu de quy):"<<UCLN2(m,n)<<endl;
	return 0;
}
