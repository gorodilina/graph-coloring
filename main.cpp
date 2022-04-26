#include "header.h"

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> M(N+2, vector<int> (N+3));
    for (int i=1; i<N+1; i++)
    {
        M[0][i]=i-1;
        M[i][0]=i-1;
    }
    for (int i=0; i<K; i++)
    {
        int u, v;
        cin >> u >> v;
        M[u+1][v+1]=1;
        M[v+1][u+1]=1;
        M[u+1][N+1]++;
        M[v+1][N+1]++;
    }

    int colors=colorize(M);
    cout << colors;
    return 0;
}
