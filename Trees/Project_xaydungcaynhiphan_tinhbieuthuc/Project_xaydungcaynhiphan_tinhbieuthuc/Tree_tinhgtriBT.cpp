//Bài tập 2. Cho phép tính sau : 8 * 7 - 2 * 3 + (32 - 7) * (40 + 8).Hãy dựng cây nhị phân và
//a.Chuyển biểu thức trên sang tiền tố bằng cách duyệt cây theo thứ tự trước
//b.Chuyển biểu thức trên sang hậu tố bằng cách duyệt cây theo thứ tự sau
#include<iostream>
#include<stack>
using namespace std;

// Một nút cây biểu thức
struct Node
{
    char value;
    Node* left, * right;
};

// Một hàm tiện ích để kiểm tra xem 'c'
// là một toán tử
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^')
        return true;
    return false;
}

// Hàm tiện ích để thực hiện việc duyệt inorder
void inorder(Node* t)
{
    if (t)
    {
        inorder(t->left);
        cout<<t->value;
        inorder(t->right);
    }
}

//Tao 1 node moi
Node* newNode(char v)
{
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

// Trả về gốc của cây đã xây dựng cho
// biểu thức hậu tố
Node* constructTree(char postfix[])
{
    stack<Node*> st;
    Node* t, * t1, * t2;

    // Duyệt qua mọi ký tự của
    // biểu thức đầu vào
    for (int i = 0; i < strlen(postfix); i++)
    {
        // Nếu toán hạng, chỉ cần đẩy vào ngăn xếp
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);

            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();

            //  make them children
            t->right = t1;
            t->left = t2;

            // Add this subexpression to stack
            st.push(t);
        }
    }

    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();

    return t;
}

// Driver program to test above
int main()
{
    char postfix[] = "ab+ef*g*-";
    Node* r = constructTree(postfix);
    printf("infix expression is \n");
    inorder(r);
    return 0;
}