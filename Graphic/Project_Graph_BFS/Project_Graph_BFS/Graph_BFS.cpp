#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int data;
	Node* pLink;
};
struct Queue {
	Node* pFront;
	Node* pRear;
};
void Initialize(Queue& queue) {
	queue.pFront = NULL;
	queue.pRear = NULL;
}
Node* CreateNode(int d) {
	Node* pNode = new Node;
	pNode->data = d;
	pNode->pLink = NULL;
    return pNode;
}
void Enqueue(Queue& queue, int d) {
	Node* pNode = CreateNode(d);
	if (queue.pFront == NULL) {
		queue.pFront = queue.pRear = pNode;
	}
	else
	{
		queue.pRear->pLink = pNode;
		queue.pRear = pNode;
	}
}
int Dequeue(Queue& queue) {
	if (queue.pFront == NULL) {
		cout << "Queue rong";
		exit(0);
	}
	int d = queue.pFront->data;
	Node* pDel = queue.pFront;
	queue.pFront = queue.pFront->pLink;
	pDel->pLink = NULL;
	delete pDel;
	pDel = NULL;
	return d;
}
bool IsEmpty(Queue queue)
{
    if (queue.pFront==NULL) {
        return true;
    }
    else return false;
}
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
//create a new node
AdjListNode* newAdjListNode(int data) {
    AdjListNode* nptr = new AdjListNode;
    nptr->data = data;
    nptr->next = NULL;
    return nptr;
}

//Ham tao do thi V-dinh
Graph* createGraph(int V) {
    Graph* graph = new Graph;//khoi tao dothi moi 
    graph->V = V;//so dinh
    //Khoi tao 1 mang danh sach ke kich thuoc V
    graph->arr = new AdjList[V];
    //Khoi tao cac node pHead cua cac danh sach lien ket bang NULL
    for (int i = 0; i < V; i++) {
        graph->arr[i].head = NULL;
    }
    return graph;
}

//Them 1 canh vao 1 do thi vo huong
void addEdge(Graph* graph, int src, int dest) {
    // Thêm một cạnh từ src đến dest. Một nút mới được thêm vào danh sách kề của src
    // nút được thêm vào đầu
    //Lam viec trong dslk cua src
    AdjListNode* nptr1 = newAdjListNode(dest);//tao nut moi nptr1=dest
    AdjListNode* temp1 = new AdjListNode;//tao node tam
    temp1 = graph->arr[src].head;//gan temp1= pHead
    if (graph->arr[src].head == NULL) {//th dslk cua phan tu src rong
        graph->arr[src].head = nptr1;
    }
    else// th dslk cua src co phan tu
    {
        while (temp1->next != NULL) {//tim phan tu cuoi
            temp1 = temp1->next;
        }
        temp1->next = nptr1;//them phan tu vao cuoi ds
    }
    //Lam viec trong dslk cua dest
    // kết nối từ dest đến src (vì vô hướng)
    AdjListNode* nptr2 = newAdjListNode(src);
    AdjListNode* temp2 = new AdjListNode;
    temp2 = graph->arr[dest].head;
    if (graph->arr[dest].head == NULL) {
        graph->arr[dest].head = nptr2;
    }
    else
    {
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = nptr2;
    }
}

//function to print the graph//Ham xuat do thi
void printGraph(Graph* graph) {
    //loop over each adjacent list//Lap qua tung dslk
    for (int i = 0; i < (graph->V); i++) {
        AdjListNode* root = graph->arr[i].head;//tao node tam =pHead cua tung dslk de duyet
        cout << "Danh sach dinh ke cua dinh " <<i<< endl;
        //loop over each node in list//Lap qua tung node trong moi ds
        while (root != NULL) {
            cout << root->data << " -> ";//Xuat du lieu cac node trong tung dslk
            root = root->next;
        }
        cout << endl;
    }
}
void Graph_BFS(Graph* graph,int s) {
    //Danh dau tat ca cac dinh chua duoc tham
    //vector<int> visited = {};//vector danh dau 
    bool* visited = new bool[graph->V];
    for (int i = 0; i < (graph->V); i++)
        visited[i] = false;
    //Khoi tao Hang doi
    Queue queue;
    Initialize(queue);
    //Đánh dấu nút hiện tại là đã truy cập và xếp vào hàng đợi
    visited[s] = true;
    Enqueue(queue, s);
    while (!IsEmpty(queue))
    {
        s = Dequeue(queue);
        cout << s << "   ";
        AdjListNode* temp = new AdjListNode;
        //temp = graph->arr[s].head;
        for (temp = graph->arr[s].head; temp != NULL; temp = temp->next)
        {
            if (!visited[temp->data])
            {
                visited[temp->data] = true;
                Enqueue(queue, temp->data);
            }
        }

    }
}

int main() {
    //create a new graph
    int totalVertices = 7;//dothi 6 dinh={1,2,3,4,5,6}
    Graph* graph;
    graph = createGraph(totalVertices);//tao dothi
    //connect edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph,2,6);
    //addEdge(graph,4,6);
    //addEdge(graph,5,6);
    
    //print the adjacency list representation of graph
    printGraph(graph);
    Graph_BFS(graph,0);
    return 0;
}