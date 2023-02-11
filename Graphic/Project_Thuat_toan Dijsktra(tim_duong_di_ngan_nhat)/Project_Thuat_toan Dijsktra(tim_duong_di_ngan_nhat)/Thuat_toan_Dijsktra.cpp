#include <limits.h>
#include <stdio.h>
#include<iostream>
using namespace std;
// Số đỉnh trong đồ thị
#define V 9

//Tim dinh co gia tri khoang cach nho nhat tu 1 dinh bat ki
//Tap cac dinh chua co trong tap duong di ngan nhat
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    cout<<"Vertex"<<"   "<<"Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<<i <<"                "<<dist[i]<<"\n";
}

//cho một đồ thị được biểu diễn bằng cách sử dụng biểu diễn ma trận kề
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; //Mang chua khoang cach tu src den i

    bool sptSet[V]; //Mang kiem tra dinh i co bao gom trong cay duong di ngan nhat khong

    // Khởi tạo tất cả khoảng cách dưới dạng INFINITE và stpSet [] là false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Khoảng cách của đỉnh nguồn so với chính nó luôn là 0
    dist[src] = 0;

    // Tìm đường đi ngắn nhất cho tất cả các đỉnh
    for (int count = 0; count < V - 1; count++) {
        // Chọn đỉnh có khoảng cách nhỏ nhất từ ​​tập hợp các đỉnh chưa 
        // chưa được xử lý.  u luôn bằng src trong lần lặp đầu tiên.
        int u = minDistance(dist, sptSet);

        // Đánh dấu đỉnh đã chọn là đã xử lý
        sptSet[u] = true;

        // Cập nhật giá trị dist của các đỉnh liền kề của đỉnh đã chọn.
        for (int v = 0; v < V; v++)
            // Chỉ cập nhật dist [v] nếu không có trong sptSet, có cạnh từ (graph[u][v])
            // u đến v và tổng trọng số của đường dẫn từ src đến v đến u 
            // nhỏ hơn giá trị hiện tại của dist [v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}