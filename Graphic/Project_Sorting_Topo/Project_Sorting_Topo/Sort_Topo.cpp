#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph {
    //So dinh
    int V;
    // Con trỏ đến một mảng chứa danh sách kề
    // Pointer to an array containing adjacency listsList
    list<int>* adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
        stack<int>& Stack);

public:
    // Constructor
    Graph(int V);

    // hàm thêm một cạnh vào đồ thị
    void addEdge(int v, int w);

    // in ra một Sắp xếp Tôpô của // một đồ thị hoàn chỉnh
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.// Thêm w vào danh sách của v
    adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
    stack<int>& Stack)
{
    // Đánh dấu nút hiện tại là đã truy cập
    visited[v] = true;

    // Lap cho tất cả các đỉnh, kề với đỉnh này
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Đẩy đỉnh hiện tại vào ngăn xếp // nơi lưu trữ kết quả
    Stack.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited// Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack// In nội dung của ngăn xếp
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver Code
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given "
        "graph \n";

    // Function Call
    g.topologicalSort();

    return 0;
}