//3. Xay dung cay nhi phan tim kiem tu day K sau do K={51, 42, 13, 64, 25, 86, 97, 38, 79}
//a.Duyet cay theo thu tu truoc
//b.Duyet cay theo thu tu giua 
//c.Duyet cay theo thu tu sau 
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

void InitBT(BSearchTree &T){
	T=NULL;
}
PNode SearchT(BSearchTree root,int x)
{
	if(root==NULL) return NULL;
	if(x==root->key) return root;
	else if( x< root->key)return SearchT(root->LP,x);
	else return SearchT(root->RP,x);
}
void InsertT(BSearchTree &root, int x){
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
void PreOrder_NLR(BSearchTree root){
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
int sum=0;
int Sum(BSearchTree root){
	if(root!=NULL){
		Sum(root->LP);
		Sum(root->RP);
		if ((root->LP != NULL && root->RP == NULL) || (root->LP == NULL && root->RP != NULL))
		{
			sum=sum+root->key;
		}
	}
	return sum;
}
int main(){
	BSearchTree Tree;
	InitBT(Tree);
	//K={51, 42, 13, 64, 25, 86, 97, 38, 79}
	InsertT(Tree, 60);
	InsertT(Tree, 68);
	InsertT(Tree, 36);
	InsertT(Tree, 80);
	InsertT(Tree, 90);
	InsertT(Tree, 50);
	InsertT(Tree, 28);
	InsertT(Tree, 27);
	InsertT(Tree, 26);
	InsertT(Tree, 25);
	cout<<"Duyet cay theo thu tu truoc:";
	PreOrder_NLR(Tree);//->51->42->13->25->38->64->86->79->97
	cout<<"\nDuyet cay theo thu tu giua:";
	InOrder_LNR(Tree);//->13->25->38->42->51->64->79->86->97
	cout<<"\nDuyet cay theo thu tu sau:";
	PostOrder_LRN(Tree);//->38->25->13->42->79->97->86->64->51
	cout<<"\nTong cac phan tu co 1 con cua cay:"<<Sum(Tree)<<endl;
	return 0;
}
