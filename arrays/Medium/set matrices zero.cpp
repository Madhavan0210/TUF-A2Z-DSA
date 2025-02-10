#include<bits\stdc++.h>
using namespace std;
vector<vector<int>> zeromatrix(vector<vector<int>> &matrix)
{
    int col0=1;
    int n=4;
    int m=4;
    //marking
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                if(j!=0) matrix[0][j]=0;
                else col0=0;
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
           if(matrix[i][j]!=0)
           {
            if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
           } 
        }
    }
    if(matrix[0][0]==0)
    {
        for(int i=0;i<m;i++) matrix[0][i]=0;
    }
    if(col0==0)
    {
        for(int i=0;i<n;i++)
        {
            matrix[i][0]=0;
        }
    }
    return matrix;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<vector<int>>matrix={{1,1,1,1},
    {1,0,1,1},
    {1,1,0,1},
    {0,1,1,1}};
    vector<vector<int>>ans=zeromatrix(matrix);
    int n=4;
    int m=4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
       cout<<endl;
    }
    return 0;
 }