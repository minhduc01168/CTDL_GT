#include <iostream>
#include<map>
#include<list>
using namespace std;

// Lớp đồ thị biểu diễn một đồ thị có hướng
// sử dụng biểu diễn danh sách kề
class Graph
{
public:
    map<int, bool> visited;//dung de kiem tra nut duyet chua
    map<int, list<int>> adj;//danh sach cac nut ke cua nut ,danh sach ke cua nut int

    // hàm thêm một cạnh vào đồ thị
    void addEdge(int v, int w);

    // DFS duyệt các đỉnh
    // có thể truy cập từ v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Thêm w vào danh sách của v
    //Trong danh sach ke cua v them nut w vao
}

void Graph::DFS(int v)
{
    // Đánh dấu nút hiện tại là đã truy cập và
    // in nó
    visited[v] = true;
    cout << v << " ";

    // Duyet cho tất cả các đỉnh liền kề
    // đến đỉnh này
    list<int>::iterator i;//Khai bao 1 iterator dung cho list<int>
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])//*i tra ve gia tri trong ds lien ket cua dinh v ma iterator duoc dat
            DFS(*i);//goi de quy
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "Following is Depth First Traversal"
        " (starting from vertex 0) \n";
    g.DFS(0);

    return 0;
}

// improved by Vishnudev C