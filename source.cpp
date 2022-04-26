#include "header.h"

using namespace std;

void show_mat(vector<vector<int>> &M)
{
    int N=M.size();
    int K=M[1].size();
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<K; j++)
        {
            cout<< M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool comp (vector <int> a, vector <int> b)
{
    return (a[a.size()-2]> b[b.size()-2]);
}

int colorize (vector<vector<int>> &M)
{
    int colors=0;
    int N=M.size()-2;
    sort(M.begin()+1, M.end(), comp);
    colors=0;
    for (int i=1; i<N+1; i++)
        {
            if (M[i][N+2]==0)
            {
                colors++;
                M[i][N+2]=colors;
                M[N+1][M[i][0]+1]=colors;
                for (int j=i+1; j<N+1; j++)
                {
                     int c=0;
                     for (int k=1; k<N+1; k++)
                     {
                         if (M[N+1][k]==colors && M[j][k]==1)
                         c++;
                     }
                     if (c==0 && M[j][N+2]==0)
                     {
                         M[j][N+2]=colors;
                         M[N+1][M[j][0]+1]=colors;
                     }
                }
            }
        }
    return colors;
}
