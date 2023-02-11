#include <iostream>
#include <climits>
#define n 6
int parent[n]; // Parent array to hold the parent nodes of each node in the graph//// Mảng cha để giữ các nút cha của mỗi nút trong đồ thị

using namespace std;

void printMST(int a[n], int b[n], int weight[n]) // Printing the MST
{
    int Minweight = 0; // Weight of Minimum spanning tree//// Trọng số của cây bao trùm tối thiểu
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Edge: " << a[i] << "-" << b[i] << " "
            << "cost: " << weight[i] << endl;
        Minweight += weight[i];
    }
    cout << "Minimum Weight is " << Minweight << endl; // Printing the weight of MINIMUM SPANNING TREE//// In trọng lượng của CÂY TỐI THIỂU
}

int findParent(int node) // Function to determine the parent node//Ham xác định nút cha
{
    while (parent[node] >= 0)
        node = parent[node];

    return node;
}

/* "findParentPathCompression" is an alternative for "findParent" which is more efficient.
 * We use a technique called "path compression" here.
 * With path compression, we destroy the structure of the tree, and only focus on which group a node is in.
 */

int findParentPathCompression(int node)//Ham xac dinh tap hop chua x
{
    if (node == parent[node]) return node;
    return parent[node] = findParentPathCompression(parent[node]);
}


void kruskal(int cost[n][n]) // Function performing Kruskal's algorithm
{
    fill_n(parent, n, -1);//Khoi tao n phan tu cua mang parent =-1
    int u, v, k = 0, count = 0;
    int firstNode, secondNode;
    int a[n]; // Array containing the first nodes of all the edges present in MST//// Mảng chứa các nút đầu tiên của tất cả các cạnh có trong MST
    int b[n]; // Array containing the second nodes of all the edges present in MST//// Mảng chứa các nút thứ hai của tất cả các cạnh có trong MST
    int weight[n]; // Array containing the weights of the edges present in MST//// Mảng chứa trọng số của các cạnh có trong MST
    int minimum;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] == 0) //  If i and j nodes are not adjacent//// Nếu nút i và nút j không kề nhau
                cost[i][j] = INT_MAX; // Then, initialize their weight as INFINITE//// Sau đó, khởi tạo trọng lượng của chúng dưới dạng INFINITE
    //INT_MAX la mot gioi han lon nhat ma so nguyen co the luu tru
    while (count < n - 1)
    {
        minimum = INT_MAX; // Initializing minimum as INFINITE//Khởi tạo tối thiểu thành INFINITE

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < minimum)
                {
                    minimum = cost[i][j]; // find the minimum cost edge// tìm cạnh chi phí tối thiểu
                    firstNode = i; // First node of determined edge// Nút đầu tiên của cạnh xác định
                    secondNode = j; // Second node of determined edge// Nút thứ hai của cạnh xác định
                }
            }
        }

        u = findParent(firstNode);
        v = findParent(secondNode);


        if (u != v) // If parents of both the nodes are different, no circuit is being formed
        {// Nếu cha của cả hai nút khác nhau, không có mạch nào được hình thành
            parent[v] = u;
            a[k] = firstNode; // Store first node in array// Lưu trữ nút đầu tiên trong mảng
            b[k] = secondNode; // Store second node in array
            weight[k] = cost[firstNode][secondNode]; // Store the determined edge's weight in array// Lưu trữ trọng số của cạnh đã xác định trong mảng
            count++;
            k++;
        }

        cost[firstNode][secondNode] = cost[secondNode][firstNode] = INT_MAX; // Edges getting included in MST will be given the weight of INFINITE
    }// Các cạnh được đưa vào MST sẽ được tính theo trọng lượng của INFINITE vi de sau khi vong lap for quy lai khong lay lai canh da them vao roi

    printMST(a, b, weight); // Printing the MST
}

// Driver program to test above function
int main()
{

    /* Let the given graph is :
         (1)____1___(2)
        /  \       /  \
       3    4     4    6
      /      \   /      \
     /        \ /        \
    (0)___5___(5)____5___(3)
     \         |         /
      \        |        /
       \       |       /
        \      2      /
         6     |     8
          \    |    /
           \   |   /
            \  |  /
             \ | /
              (4)
    */

    int cost[n][n] = {
        { 0, 3, 0, 0, 6, 5 },
        { 3, 0, 1, 0, 0, 4 },
        { 0, 1, 0, 6, 0, 4 },
        { 0, 0, 6, 0, 8, 5 },
        { 6, 0, 0, 8, 0, 2 },
        { 5, 4, 4, 5, 2, 0 }
    };

    kruskal(cost);
    return 0;
}

/*
Output :
 Edge: 0-1 cost: 3
 Edge: 1-2 cost: 1
 Edge: 1-5 cost: 4
 Edge: 5-4 cost: 2
 Edge: 5-3 cost: 5
 Minimum Weight is 15
*/

