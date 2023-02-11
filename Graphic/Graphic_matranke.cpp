#include<iostream> 
#define NMAX 100

using namespace std;
int main(){
    int a[NMAX+1][NMAX+1];
    int n, m, u, v;
 
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            a[i][j]=0; // Ðau tiên chúng ta coi do thi không có canh nào ca 
 
    for (int i=1; i<=m; i++)
    {
        cin >> u >> v;
        a[u][v]=1;
        a[v][u]=1;
    }
    for (int h=1; h<=n; h++)
    {
        for (int k=1; k<=n; k++)
        {
            cout<<a[h][k]<<"   "<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
