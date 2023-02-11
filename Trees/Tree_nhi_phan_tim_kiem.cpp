//Cai dat mot cay nhi phan tim kiem voi cac khoa la so nguyen, thuc hien cac thao tac sau:
//Khoi tao mot cay rong 
//Bo sung mot phan tu
///Loai bo mot phan tu 
//Tim kiem mot phan tu
//Hien thi cac khoa tren cay
//Tinh tong cac phan tu khoa cua cay
//Dem so phan tu cua cay
//Viet chuong trinh chinh su dung cay vua cai dat
//Viet ham tao mot nut moi voi khoa tren nut la value:Pnode make TreeNode( int value)
//Thuc hien ham bo sung mot nut moi vao cay nhi phan tim kiem trong do co su dung ham Pnode make TreeNode( int value)
//Viet ham tim gia tri khoa nho nhat tren cay
//Viet ham tim phan tu co khoa nho nhat tren cay
//Viet ham dem so luong nut co khoa la so chan tren cay
#include<iostream>

using namespace std;
struct Node
{
	int key;
	Node *LP,*RP;
};
typedef Node* PNode;
typedef PNode BinaryTree;
typedef BinaryTree BSearchTree;

void InitBT(BSearchTree &T){//Khoi tao mot cay rong
	T=NULL;
}
PNode SearchT(BSearchTree root,int x)//Tim kiem mot phan tu
{
	if(root==NULL) return NULL;
	if(x==root->key) return root;
	else if( x< root->key)return SearchT(root->LP,x);
	else return SearchT(root->RP,x);
}
void InsertT(BSearchTree &root, int x){//Bo sung mot phan tu
	PNode Q;
	Q=new Node ;
	Q->key=x;
	Q->LP=Q->RP=NULL;
	if(root==NULL){
		root=Q;
	}
	else
	{
		if(x<root->key) InsertT (root->LP,x);
		else if(x>root->key) InsertT(root->RP,x);
	}
}
void PreOrder_NLR(BSearchTree root){//Hien thi khoa tren cay
	if(root!=NULL){
		cout<<root->key<<"\t";
		PreOrder_NLR(root->LP);
		PreOrder_NLR(root->RP);
	}
}
void InOrder_LNR(BSearchTree root){
	if(root!=NULL){
		InOrder_LNR(root->LP);
		cout<<root->key<<"\t";
		InOrder_LNR(root->RP);
	}
}
void PostOrder_LRN(BSearchTree root){
	if(root!=NULL){
		PostOrder_LRN(root->LP);
		PostOrder_LRN(root->RP);
		cout<<root->key<<"\t";
	}
}


Node* deleteNode(Node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k) {
        root->LP = deleteNode(root->LP, k);
        return root;
    }
    else if (root->key < k) {
        root->RP = deleteNode(root->RP, k);
        return root;
    }
 
    // Chúng ta den dây khi root là nút // se bi xóa.  // Neu mot trong các phan tu con trong
    if (root->LP == NULL) {
        Node* temp = root->RP;
        delete root;
        return temp;
    }
    else if (root->RP == NULL) {
        Node* temp = root->LP;
        delete root;
        return temp;
    }
 
    // If both children exist//// Neu ca hai con deu ton tai
    else {
 
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->RP;
        while (succ->LP != NULL) {
            succParent = succ;
            succ = succ->LP;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->LP = succ->RP;
        else
            succParent->RP = succ->RP;
 
        // Copy Successor Data to root
        root->key = succ->key;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}
//Tinh tong cac phan tu khoa cua cay

int Sum(BSearchTree root, int &sum){
	if(root!=NULL){
		sum=sum+root->key;
		Sum(root->LP,sum);
		Sum(root->RP,sum);
	}
	return sum;
}
int CountNode(BSearchTree root){//dem so phan tu
	if(root==NULL){
		return 0;
	}
	else{
		return (1+(CountNode(root->LP)+CountNode(root->RP)));
	}
}
//Viet ham tao mot nut moi voi khoa tren nut la value:Pnode make TreeNode( int value)
PNode CreateNode(int value){
	Node* node=new Node;
	node->key=value;
	node->LP=node->RP=NULL;
}
//Thuc hien ham bo sung mot nut moi vao cay nhi phan tim kiem trong do co su dung ham Pnode make TreeNode( int value)
void Insert_BS(BSearchTree &root, int value){//Bo sung mot phan tu
	PNode Q=CreateNode(value);
	if(root==NULL){
		root=Q;
	}
	else
	{
		if(value<root->key) InsertT (root->LP,value);
		else if(value>root->key) InsertT(root->RP,value);
	}
}
//Viet ham tim gia tri khoa nho nhat tren cay
int Min_Tree_value(BSearchTree root,int &min){
	if(root!=NULL){
		if(root->key<min){
			min=root->key;
		}
		Min_Tree_value(root->LP,min);
		Min_Tree_value(root->RP,min);
	}
    return min;
}
//Viet ham tim phan tu co khoa nho nhat tren cay
PNode Min_Tree(BSearchTree root,PNode &min){
	if(root!=NULL){
		if(root->key<min->key){
			min=root;
		}
		Min_Tree(root->LP,min);
		Min_Tree(root->RP,min);
	}
    return min;
}
//Viet ham tim gia tri khoa lon nhat tren cay
int Max_Tree_value(BSearchTree root,int &max){
	if(root!=NULL){
		if(root->key>max){
			max=root->key;
		}
		Max_Tree_value(root->LP,max);
		Max_Tree_value(root->RP,max);
	}
    return max;
}
//Viet ham tim phan tu co khoa lon nhat tren cay
PNode Max_Tree(BSearchTree root,PNode &max){
	if(root!=NULL){
		if(root->key>max->key){
			max=root;
		}
		Max_Tree(root->LP,max);
		Max_Tree(root->RP,max);
	}
    return max;
}
//Viet ham dem so luong nut co khoa la so chan tren cay
int Dem_SL_Khoa_Chan(BSearchTree root, int &dem_chan){
	if(root!=NULL){
		if((root->key)%2==0){
			dem_chan++;
		}
		Dem_SL_Khoa_Chan(root->LP,dem_chan);
		Dem_SL_Khoa_Chan(root->RP,dem_chan);
	}
    return dem_chan;
}
int main(){
	BSearchTree Tree;
	InitBT(Tree);
	//K={40,30,65,25,50,76,35,10,28,27,73,36,34}
	InsertT(Tree, 40);
	InsertT(Tree, 30);
	InsertT(Tree, 65);
	InsertT(Tree, 25);
	InsertT(Tree, 50);
	InsertT(Tree, 76);
	InsertT(Tree, 35);
	InsertT(Tree, 10);
	InsertT(Tree, 28);
	InsertT(Tree, 27);
	InsertT(Tree, 73);
	Insert_BS(Tree,36);
    Insert_BS(Tree,34);
	cout<<"Duyet cay theo thu tu truoc:";
	PreOrder_NLR(Tree);//->51->42->13->25->38->64->86->79->97
	cout<<"\nDuyet cay theo thu tu giua:";
	InOrder_LNR(Tree);//->13->25->38->42->51->64->79->86->97
	cout<<"\nDuyet cay theo thu tu sau:";
	PostOrder_LRN(Tree);//->38->25->13->42->79->97->86->64->51
	PNode d=SearchT(Tree ,25);
	cout<<"\nTim kiem thay phan tu:"<<d->key<<endl;
	int sum=0;
	cout<<"\nTong cac phan tu cua cay:"<<Sum(Tree,sum)<<endl;
	cout<<"So phan tu tren cay:"<<CountNode(Tree)<<endl;

	Node* root=NULL;
	root=deleteNode(Tree, 30);
	cout<<"Duyet cay theo thu tu truoc:";
	PreOrder_NLR(Tree);
	int min=INT_MAX;
	cout<<"\nGia tri khoa nho nhat tren cay:"<<Min_Tree_value(Tree,min)<<endl;
	int max=INT_MIN;
	cout<<"\nGia tri khoa lon nhat tren cay:"<<Max_Tree_value(Tree,max)<<endl;
	int dem_chan=0;
	cout<<"\nSo luong nut co khoa la so chan tren cay:"<<Dem_SL_Khoa_Chan(Tree,dem_chan)<<endl;
	PNode MIN=CreateNode(INT_MAX);
	PNode Q1=Min_Tree(Tree,MIN);
	cout<<"\nPhan tu co khoa nho nhat tren cay, co gia tri khoa:"<<Q1->key<<endl;
	PNode MAX=CreateNode(INT_MIN);
	PNode Q2=Max_Tree(Tree,MAX);
	cout<<"\nPhan tu co khoa lon nhat tren cay, co gia tri khoa:"<<Q2->key<<endl;
	return 0;
}
