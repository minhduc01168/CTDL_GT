//Tinh to hop chap k cua n dung de quy va khu de quy
#include<iostream>
using namespace std;
int Choose(int n,int k){//de quy 
	if(k==0||n==k){
		return 1;
	}
	return Choose(n-1,k)+Choose(n-1,k-1);
}
long long gt(int n) {
    long long s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
long long C(int k, int n) {
    return  gt(n) / (gt(k)*gt(n - k));
}
int main(){

	int n, k;
    cout << "Nhap k: ";
    cin >> k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "To hop (cach khu de quy): " << C(k, n)<<endl;
    cout << "To hop (cach de quy): " << Choose(n,k)<<endl;
	return 0;
}
