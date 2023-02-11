#include<iostream>
#include <list>
 
using namespace std;
 
// Lop n�y bieu dien mot do thi c� huong bang c�ch su dung 
// bieu dien danh s�ch ke
class Graph
{
    int V;    // so dinh
 
    // Con tro den mot mang c� chua // danh s�ch lien ke
    list<int> *adj;  
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    void BFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v�s list.// Th�m w v�o danh s�ch cua v
}
 
void Graph::BFS(int s)
{
    // ��nh dau tat ca c�c dinh l� kh�ng duoc tham
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Tao h�ng doi cho BFS
    list<int> queue;
 
    // ��nh dau n�t hien tai l� d� truy cap v� xep n� v�o h�ng doi
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' se duoc su dung de lay tat ca c�c dinh // lien ke cua mot dinh
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Xep h�ng doi mot dinh tu h�ng doi v� in n�
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Lay tat ca c�c dinh lien ke cua dinh s. Neu mot v�ng lien ke chua duoc truy cap, 
		// sau d� d�nh dau n� d� duoc truy cap v� xep h�ng
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
