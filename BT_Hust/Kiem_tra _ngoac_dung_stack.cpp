//C1:Dung thu vien STL
//C2:Tao Stack
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//C1
/*bool KiemTraXauNgoac(string str,stack<char> a)
{
	//string str l� chuoi x�u ngoac se nhap v�o
	for(int i=0;i<str.size();i++)//duyet lan luot het chuoi
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//neu gap dau mo ngoac
		{
			a.push(str[i]);//push het v�o stack 
		}
		else //neu gap dau d�ng ngoac
		{
			if(!a.empty())//neu stack kh�c rong 
			{
				if(str[i]==']')//kiem tra xem phan tu ngoac dinh stack c� hop voi str[i] hay kh�ng
				{
					if(a.top()!='[')//kh�ng hop
					{
						return false;//sai
					}
				}
				if(str[i]==')')//kiem tra xem phan tu ngoac dinh stack c� hop voi str[i] hay kh�ng
				{
					if(a.top()!='(')//kh�ng hop
					{
						return false;//sai
					}
				}
				if(str[i]=='}')//kiem tra xem phan tu ngoac dinh stack c� hop voi str[i] hay kh�ng
				{
					if(a.top()!='{')//kh�ng hop
					{
						return false;//sai
					}
				}
				a.pop();//kiem tra xong x�a n� di
			}
			else //neu nhu stack rong, kh�ng hop ly, c� dau mo m� kh�ng c� d�ng
			{
				return false;
			}
		}
	}
	return a.empty()==true;
	//neu nhu cuoi c�ng stack van rong c�c phan tu d� lay ra kiem tra ph� hop het
}
int main()
{
	//v� du c� chuoi str;
	string str;
	stack<char> a;
	getline(cin,str);
	if(KiemTraXauNgoac(str,a)==true)
	{
		cout<<"Xau ngoac dung"<<endl;
	}
	else 
	{
		cout<<"xau ngoac sai:"<<endl;
	}

	return 0;
}
*/
struct Node{
	char data;
	Node *pLink;
};
typedef Node* Stack;
void Initialize(Stack &stack){
	stack=NULL;
}
Node *CreateNode(char d){
	Node *pNode=new Node;
	pNode->data=d;
	pNode->pLink=NULL;
}
void Push(Stack &stack, char d){
	Node *pNode=CreateNode(d);
	if(stack==NULL){
		stack=pNode;
	}
	else
	{
		pNode->pLink=stack;
		stack=pNode;
	}
}
int Pop(Stack &stack){
	char d=stack->data;
	Node *pDel=stack;
	stack=stack->pLink;
	pDel->pLink=NULL;
	delete pDel;
	pDel=NULL;
	return d;
}
int Top(Stack stack){
	char d=stack->data;
	return d;
}
bool IsEmpty(Stack stack) {
        if (stack== NULL) return true;
        else return false;
    }
bool KiemTraXauNgoac(string str,Stack &a)
{
	//string str l� chuoi x�u ngoac se nhap v�o
	for(int i=0;i<str.size();i++)//duyet lan luot het chuoi
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//neu gap dau mo ngoac
		{
			Push(a,str[i]);//push het v�o stack 
		}
		else //neu gap dau d�ng ngoac
		{
			if(!IsEmpty(a))//neu stack kh�c rong 
			{
				if(str[i]==']')//kiem tra xem phan tu ngoac dinh stack c� hop voi str[i] hay kh�ng
				{
					if(Top(a)!='[')//kh�ng hop
					{
						return false;//sai
					}
				}
				if(str[i]==')')//kiem tra xem phan tu ngoac dinh stack c� hop voi str[i] hay kh�ng
				{
					if(Top(a)!='(')//kh�ng hop
					{
						return false;//sai
					}
				}
				if(str[i]=='}')//kiem tra xem phan tu ngoac dinh stack c� hop voi str[i] hay kh�ng
				{
					if(Top(a)!='{')//kh�ng hop
					{
						return false;//sai
					}
				}
				Pop(a);//kiem tra xong x�a n� di
			}
			else //neu nhu stack rong, kh�ng hop ly, c� dau mo m� kh�ng c� d�ng
			{
				return false;
			}
		}
	}
	return IsEmpty(a)==true;
}
int main()
{
	//v� du c� chuoi str;
	string str;
	Stack a;
	Initialize(a);
	getline(cin,str);
	if(KiemTraXauNgoac(str,a)==true)
	{
		cout<<"Xau ngoac dung"<<endl;
	}
	else 
	{
		cout<<"xau ngoac sai"<<endl;
	}

	return 0;
}

