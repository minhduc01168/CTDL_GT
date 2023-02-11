#include<iostream>
using namespace std;
struct TNode{
	int value;
	TNode *pLeft;
	TNode *pRight;
};
typedef TNode* BTree;//dinh nghia ten thay the cho kieu con tro TNode
TNode *CreateNode(int v){//tao node moi
	TNode *node=new TNode;
	node->value=v;
	node->pLeft=node->pRight=NULL;
}
void InsertNode(BTree &root, int v){
	TNode *node=CreateNode(v);//tao 1 node moi
	if(root==NULL)
	{
		root=node;//ktra cay co rong 
	}
	else//tim vi tri node cha
	{
		BTree tmp=root;//khoi tao node tam
		BTree parent=NULL;
		while(tmp!=NULL){//tim node cha
			parent=tmp;
			if(tmp->value>node->value){
				tmp=tmp->pLeft;
			}
			else
			{
				tmp=tmp->pRight;
			}
		}
		if(parent->value>node->value)//kiem tra gia tri
		{
			parent->pLeft=node;//cha>con->trai
		}
		else
		{
			parent->pRight=node;//cha<con->phai
		}
	}
}
void PreOrder_NLR(BTree root){
	if(root!=NULL){
		cout<<root->value<<"\t";
		PreOrder_NLR(root->pLeft);
		PreOrder_NLR(root->pRight);
	}
}
void PostOrder_LRN(BTree root){
	if(root!=NULL){
		PostOrder_LRN(root->pLeft);
		PostOrder_LRN(root->pRight);
		cout<<root->value<<"\t";
	}
}
void InOrder_LNR(BTree root){
	if(root!=NULL){
		InOrder_LNR(root->pLeft);
		cout<<root->value<<"\t";
		InOrder_LNR(root->pRight);
	}
}
int CountNode(BTree root){
	if(root==NULL){
		return 0;
	}
	else{
		return (1+(CountNode(root->pLeft)+CountNode(root->pRight)));
	}
}
int CountLeaf(BTree root){
	if(root!=NULL){
		if(root->pLeft==NULL && root->pRight==NULL){
			return 1;
		}
		else
		{
			return CountLeaf(root->pLeft)+CountLeaf(root->pRight);
		}
	}
	else
	{
		return 0;
	}
}
int max(int a,int b){
	return a>b?a:b;
}
int Height(BTree root){
	if(root==NULL){
		return 0;
	}
	else
	{
		return 1+max(Height(root->pLeft),Height(root->pRight));
	}
}
TNode *Search(BTree root, int v){
	if(root==NULL||root->value==v){
		return root;
	}
	else
	{
		if(v<root->value){
			return Search(root->pLeft,v);
		}
		else if(v>root->value)
		{
			return Search(root->pRight,v);
		}
	}
}
void RemoveNode(BTree &root,int v)
{
	if(root==NULL){//kiem tra cay rong
	   cout<<"Tree is empty!";
	   return ;
	}
	TNode *pParent=NULL;
	TNode *pDel=NULL;
	TNode *pTmp=root;
	while(pTmp!=NULL)//Tim vi tri node can xoa
	{
		pParent=pTmp;//node cha
		if(pTmp->value>v)//tim tren cay con trai
		{
			pTmp=pTmp->pLeft;
		}
		else if(pTmp->value<v)//tim tren cay con phai
		{
			pTmp=pTmp->pRight;
		}
		if(pTmp->value==v){
			pDel=pTmp;
			break;
		}
	}
	if(pDel==NULL)//Khong tim thay node can xoa
	{
		cout<<"Not found!";
		return;
	}
	if(pDel->pLeft==NULL && pDel->pRight==NULL){//nut can xoa la nut la
		if(pParent->value>pDel->value)//xoa trai
		{
			pParent->pLeft=NULL;
		}
		else
		{
			pParent->pRight=NULL;//xoa phai
		}
		delete pDel;
		pDel=NULL;
	}
	else if(pDel->pLeft!=NULL && pDel->pRight==NULL){//xoa node co node con trai
		if(pParent->value>pDel->value){
			pParent->pLeft=pDel->pLeft;//noi nut cha truoc node pDel voi node con trai duy nhat cua node pDel
		}
		else
		{
			pParent->pRight=pDel->pLeft;
		}
		pDel->pLeft=NULL;
		delete pDel;
		pDel=NULL;
	}
	else if(pDel->pLeft==NULL && pDel->pRight!=NULL){//xoa node co cay con phai
		if(pParent->value>pDel->value){
			pParent->pLeft=pDel->pRight;
			pDel->pRight=NULL;
		}
		else
		{
			pParent->pRight=pDel->pRight;
			pDel->pRight=NULL;
		}
		delete pDel;
		pDel=NULL;
	}
	else
	{
		//xoa node co ca cay con trai va phai
		//tim node trai nhat cua cay con phai
		TNode *pMinOfRight=pDel->pRight;//bien tam
		TNode *pParentMinOfRight=NULL;//luu vet
		while(pMinOfRight->pLeft!=NULL)
		{
			pParentMinOfRight=pMinOfRight;
			pMinOfRight=pMinOfRight->pLeft;
		}
		pDel->value=pMinOfRight->value;
		//gan thong node the mang cho node can xoa
		if(pParentMinOfRight==NULL){
			pDel->pRight=NULL;
		}
		else if(pParentMinOfRight->value>pMinOfRight->value){
			//noi cha cua nut the mang voi con cua nut the mang
			pParentMinOfRight->pLeft=pMinOfRight->pRight;
		}
		delete pMinOfRight;
		pMinOfRight=NULL;
	}
}
int main(){
	return 0;
}
