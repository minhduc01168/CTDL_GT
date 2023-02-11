//Bài 2: Mot don vi quan tâm ve dân so lap mot bang thong kê so luong
//nguoi sinh trong trong nam, ke tu nam 1920 (X) den 1970 (Y) và luu tru
//bang dó trong máy tính bang mot mang mot chieu N voi N[k] (k=0->(YX) ) có giá tri bang so nguoi sinh ra tuong ung trong nam tu 1920 (X) 
//den 1970 (Y). Hãy viet giai thuat thuc hien
//1. In ra nhung nam không có nguoi nào duoc sinh ra
//2. Tính so luong nhung nam mà so nguoi sinh ra không quá 10 (k)
//3. Tính so nguoi dã trên 50 (t) tuoi tính den nam 1985 (Z).
#include<iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include<conio.h>
using namespace std;
int BinarySearch( int M[],int x, int left, int right)
{
	if(left>right)
	    return -1;
    int mid=(left+right)/2;
    if(x==M[mid])
    {
    	return mid;
	}
	if(x<M[mid])
	{
		return BinarySearch(M,x,left,mid-1);
	}
	return BinarySearch(M,x,mid+1,right);
}

void Doc_File(ifstream &in,int arr[]){ //1.Ðoc du lieu vao con tro
    int dem=0;
    while(in.eof()==false){
        string x;
        getline(in,x,' ');
        dem++;
	}
	in.seekg(0);
	for(int i=0;i<dem;i++){
		string line;
	    getline(in,line,' ');
	    int sl=atof(line.c_str());
		arr[i]=sl;
	}
}
void no_birth(int arr[], int begin, int end) {
    int i = 0;
    for(i; i < end - begin + 1; i++) {
        if(arr[i] == 0) {
            cout << begin + i << endl;
        }
    }
}
void Nho_Hon_10(int arr[], int begin, int end) {
    int i = 0;
    for(i; i < end - begin + 1; i++) {
        if(arr[i] <= 10) {
            cout << begin + i << endl;
        }
    }
}

int sum=0;
int Sum(int arr[],int Z, int x, int begin)
{
	for(int i=0;i<Z-x-begin+1;i++){
		sum=sum+arr[i];
	}
	return sum;
}
// Driver program
int main()
{
	cout << "Nhap nam bat dau: ";
    int X, Y;
    cin >> X;
    cout << "Nhap nam ket thuc: ";
    cin >> Y;
	int arr[100];
    ifstream ifs1("SL_dan_so.txt");
	Doc_File(ifs1,arr);
	cout<< "So luong dan so tung nam theo thong ke:"<<endl;
	for (int i = 0; i < 51; ++i)
        cout << arr[i] << " ";
    cout<<"\nNhung nam khong co nguoi nao duoc sinh ra"<<endl;
	no_birth(arr, X,Y);
	cout<<"\nSo luong nhung nam ma so nguoi sinh ra khong qua 10 "<<endl;
	Nho_Hon_10(arr, X,Y);
	cout<<"So nguoi da tren 50 tuoi tinh den nam 1985:";
	cout<<Sum(arr,1985, 50, X);
	return 0;
}

