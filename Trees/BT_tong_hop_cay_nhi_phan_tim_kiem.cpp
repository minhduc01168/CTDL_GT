//xay dung cay nhi phan tim kiem de luu tru cac sinh vien theo thu tu cua ma sinh vien .
//Thong tin cua sinh vien bao gom : ma so sinh vien(int), ho ten(string), lop(string), diem trung binh (float)
//Hay thuc hien cac thao tac (ham) sau:
//1.Khoi tao cay rong
//2.Bo sung 1 sinh vien vao cay
//3.Loai bo mot sinh vien khoi cay theo ma so sinh vien
//4.Tim kiem sinh vien theo ma so
///5.Tim kiem sinh vien theo ten
//6.Sap xep sinh vien theo chieu tang dan cua ma so sinh vien
//7. Dua ra thong tin cua sinh vien co diem trung binh cao nhat
//8.Tinh diem trung binh cua toan bo sinh vien
//9.Hien thi thong tin cua tat ca sinh vien
#include<iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include<conio.h>

using namespace std;
struct Student{
	int ms;
	string name;
	string lop;
	float DiemTB;
	     
};
struct Node
{
	Student* key;
	Node *LP,*RP;
};
typedef Node* PNode;
typedef PNode BinaryTree;
typedef BinaryTree BSearchTree;
//1.Khoi tao cay rong
void InitBT(BSearchTree &T){//Khoi tao mot cay rong
	T=NULL;
}
PNode CreateNode(Student *sv){
	PNode node=new Node;
	node->key=sv;
	node->LP=node->RP=NULL;
}
//2.Bo sung 1 sinh vien vao cay
void InsertT(BSearchTree &root, Student *x){//Bo sung mot phan tu
	PNode Q=CreateNode(x);
	if(root==NULL){
		root=Q;
	}
	else
	{
		if(x->ms<root->key->ms) InsertT (root->LP,x);
		else if(x->ms>root->key->ms) InsertT(root->RP,x);
	}
}
//4.Tim kiem sinh vien theo ma so
PNode SearchTMS(BSearchTree root,int ma)//Tim kiem mot sinh vien theo ma so sv
{
	if(root==NULL) return NULL;
	if(ma==root->key->ms) return root;
	else if( ma< root->key->ms)return SearchTMS(root->LP,ma);
	else return SearchTMS(root->RP,ma);
}

///5.Tim kiem sinh vien theo ten
void TimTheoTen(BSearchTree root,string ten){
	if(root!=NULL) {
		if(ten==root->key->name) {
			cout<<setw(20)<<left<<root->key->ms<<setw(30)<<left<<root->key->name<<setw(35)<<left<<root->key->lop<<setw(10)<<left<<root->key->DiemTB<<endl;
		}
		TimTheoTen(root->LP,ten);
		TimTheoTen(root->RP,ten);
		
	}
}
//9.Hien thi thong tin cua tat ca sinh vien
void PreOrder_NLR(BSearchTree root){//Hien thi khoa tren cay
	if(root!=NULL){
		cout<<setw(20)<<left<<root->key->ms<<setw(30)<<left<<root->key->name<<setw(35)<<left<<root->key->lop<<setw(10)<<left<<root->key->DiemTB<<endl;
		PreOrder_NLR(root->LP);
		PreOrder_NLR(root->RP);
	}
}
void InOrder_LNR(BSearchTree root){
	if(root!=NULL){
		InOrder_LNR(root->LP);
		cout<<setw(20)<<left<<root->key->ms<<setw(30)<<left<<root->key->name<<setw(35)<<left<<root->key->lop<<setw(10)<<left<<root->key->DiemTB<<endl;
		InOrder_LNR(root->RP);
	}
}
void PostOrder_LRN(BSearchTree root){
	if(root!=NULL){
		PostOrder_LRN(root->LP);
		PostOrder_LRN(root->RP);
		cout<<setw(20)<<left<<root->key->ms<<setw(30)<<left<<root->key->name<<setw(35)<<left<<root->key->lop<<setw(10)<<left<<root->key->DiemTB<<endl;
	}
}
//3.Loai bo mot sinh vien khoi cay theo ma so sinh vien
void DelNode (PNode & P) { //Xóa giá tri o nút P & sap lai cây
    PNode Q, R;
    if (P->LP == NULL) { //Xóa nút chi có cây con ph?i
        Q = P;
        P = P->RP;
    } 
	else if (P->RP == NULL) //Xóa nút chi có cây con trái
    {
	    Q = P;
        P = P->LP;
    } 
	else { //Xóa nút có 2 cây con
        Q = P->LP;
        if (Q->RP == NULL) {
            P->key = Q->key;
            P->LP = Q->LP;
        } 
		else {
            do { //Dùng R de luu parent cua Q
                R = Q;
                Q = Q->RP;
            } while (Q->RP != NULL);
            P->key = Q->key; //Lay giá tri o Q dua lên
            R->RP = Q->LP; //Chuyen con cua Q lên vi trí Q
        }
    }
    delete Q; //Xoá Q
}
void DeleteT (BSearchTree & Root, int x){
    if (Root != NULL) {
    if (x < Root->key->ms) DeleteT (Root->LP, x);
    else if (x > Root->key->ms) DeleteT (Root->RP, x);
    else DelNode (Root); //Xoá goc cua cây
    }
}

//8.Tinh diem trung binh cua toan bo sinh vien
//Tinh tong cac phan tu khoa cua cay
float sum=0; 
float Sum(BSearchTree root){
	if(root!=NULL){
		sum=sum+root->key->DiemTB;
		Sum(root->LP);
		Sum(root->RP);
	}
	return sum;
}
//dem tong so sinh vien
int CountNode(BSearchTree root){//dem so phan tu
	if(root==NULL){
		return 0;
	}
	else{
		return (1+(CountNode(root->LP)+CountNode(root->RP)));
	}
}

//6.Sap xep sinh vien theo chieu tang dan cua ma so sinh vien
//Duyet theo InOrder_LNR thu duoc danh sach sap xep
//7. Dua ra thong tin cua sinh vien co diem trung binh cao nhat
PNode MaxDiemTB(BSearchTree root)
{
	PNode Q;
	float MAX=0;
	if(root!=NULL){
		if(MAX<root->key->DiemTB)
		{
			MAX=root->key->DiemTB;
			Q=root;
		}
		MaxDiemTB(root->LP);
		MaxDiemTB(root->RP);
	}
    return Q;
}
Student *Doc_File_Student(ifstream &in){ //Doc du lieu tu file txt
    Student *sv=new Student;
	fflush(stdin);
	string line;
	getline(in,line);
	sv->ms=atof(line.c_str());
	
	getline(in,sv->name);
	getline(in,sv->lop);
	
	getline(in,line);
	sv->DiemTB=atof(line.c_str());
	// Neu là string, convert ve char array su dung .c_str()
	return sv;
}
void Doc_File_DS_Student(ifstream &in,BSearchTree &root){ //1.Ðoc du lieu vao con tro
    //Student *sv=new Student;
    int dem=0;
    while(in.eof()==false){
        string x;
        getline(in,x,'\n');
        dem++;
	}
	in.seekg(0);
	int sl=dem/4;
	Student **DS=new Student*[sl];
	for(int i=0;i<sl;i++){
		DS[i]=Doc_File_Student(in);
		InsertT(root, DS[i]);
	}
}
int main()
{
	BSearchTree Tree;
	InitBT(Tree);
	ifstream ifs1("Student_tree.txt");
	Doc_File_DS_Student(ifs1,Tree);
	cout<<"Tong so sinh vien:"<<CountNode(Tree)<<endl;
	cout<<"Danh sach sinh vien:"<<endl;
	cout<<setw(20)<<left<<"Ma so sinh vien"<<setw(30)<<left<<"Ten"<<setw(35)<<left<<"Lop"<<setw(10)<<left<<"Diem TB";
	cout<<"\n---------------------------------------------------------------------------------------------------------\n";
	PreOrder_NLR(Tree);
	cout<<"Tong diem trung binh cua sinh vien:"<<Sum(Tree)<<endl;
	DeleteT (Tree, 90);
	cout<<"\n---------------------------------------------------------------------------------------------------------\n";
	PreOrder_NLR(Tree);
	cout<<"Tim kiem sinh vien theo ma:"<<endl;
	PNode Q1=SearchTMS(Tree,89);
	cout<<setw(20)<<left<<Q1->key->ms<<setw(30)<<left<<Q1->key->name<<setw(35)<<left<<Q1->key->lop<<setw(10)<<left<<Q1->key->DiemTB<<endl;
	cout<<"Danh sach sap xep theo chieu tang dan ma so sinh vien:"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------\n";
	InOrder_LNR(Tree);
	cout<<"Thong tin cua sinh vien co diem trung binh cao nhat:"<<endl;
	PNode Q3=MaxDiemTB(Tree);
	cout<<setw(20)<<left<<Q3->key->ms<<setw(30)<<left<<Q3->key->name<<setw(35)<<left<<Q3->key->lop<<setw(10)<<left<<Q3->key->DiemTB<<endl;
	cout<<"Tim kiem sinh vien theo ten:"<<endl;
	TimTheoTen(Tree,"Le Van Nhat");
	TimTheoTen(Tree,"Le Thi Chi");
	return 0;
}
