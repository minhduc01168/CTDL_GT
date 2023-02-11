#include<iostream>
#include<cstdlib>
using namespace std;

//Kieu node
struct AdjListNode {
    int data;
    AdjListNode* next;
};

struct AdjList {
    AdjListNode* head;  //con tro dau pHead
};

//Cau truc cho 1 do thi.Bieu dien duoi dang 1 mang danh sach ke
//Kich thuoc cua mang la V(so dinh)
struct Graph {
    int V;
    AdjList* arr;
};

AdjListNode* newAdjListNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void printGraph(Graph*);

int main() {
    //create a new graph
    int totalVertices = 4;//dothi 4 dinh={0,1,2,3}
    Graph* graph;
    graph = createGraph(totalVertices);//tao dothi
    //connect edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    /*
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    */
    //print the adjacency list representation of graph
    printGraph(graph);
}

//create a new node
AdjListNode* newAdjListNode(int data) {
    AdjListNode* nptr = new AdjListNode;
    nptr->data = data;
    nptr->next = NULL;
    return nptr;
}

//function to create a graph of V - vertices
//Ham tao do thi V-dinh
Graph* createGraph(int V) {
    Graph* graph = new Graph;//khoi tao dothi moi 
    graph->V = V;//so dinh
    //create an array of adjacency list. size of array - V
    //Khoi tao 1 mang danh sach ke kich thuoc V
    graph->arr = new AdjList[V];
    //initialize with NULL (e.g root=NULL)
    //Khoi tao cac node pHead cua cac danh sach lien ket bang NULL
    for (int i = 0; i < V; i++) {
        graph->arr[i].head = NULL;
    }
    return graph;
}

//add an edge to an undirected Graph
//Them 1 canh vao 1 do thi vo huong
void addEdge(Graph* graph, int src, int dest) {
    // Thêm một cạnh từ src đến dest. Một nút mới được thêm vào danh sách kề của src
    // nút được thêm vào đầu
    //Lam viec trong dslk cua src
    AdjListNode* nptr = newAdjListNode(dest);//tao nut moi nptr=dest
    nptr->next = graph->arr[src].head;//pNext cua nptr la pHead
    graph->arr[src].head = nptr;//Dich pHead ve dau danh sach lk cua src
    //Lam viec trong dslk cua dest
    // kết nối từ dest đến src (vì vô hướng)
    nptr = newAdjListNode(src);//gan nptr =node moi src
    nptr->next = graph->arr[dest].head;//pNext cua nptr la pHead
    graph->arr[dest].head = nptr;//Dich pHead ve dau danh sach lk cua dest
}

//function to print the graph//Ham xuat do thi
void printGraph(Graph* graph) {
    //loop over each adjacent list//Lap qua tung dslk
    for (int i = 0; i < graph->V; i++) {
        AdjListNode* root = graph->arr[i].head;//tao node tam =pHead cua tung dslk de duyet
        cout << "Danh sach dinh ke cua dinh " << i << endl;
        //loop over each node in list//Lap qua tung node trong moi ds
        while (root != NULL) {
            cout << root->data << " -> ";//Xuat du lieu cac node trong tung dslk
            root = root->next;
        }
        cout << endl;
    }
}