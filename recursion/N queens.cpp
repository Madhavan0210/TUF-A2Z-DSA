    #include<bits\stdc++.h>
    using namespace std;
    class Optimal{
        public:
        void queen(int col,vector<string>&vec,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upper,vector<int>&lower,int n)
        {
            if(col==n)
            {
                ans.push_back(vec);
                return;
            }
            for(int row=0;row<n;row++)
            {
                if(leftrow[row]==0 && upper[n-1+col-row]==0 && lower[row+col]==0)
                {
                    vec[row][col]='M';
                    leftrow[row]=1;
                    upper[n-1+(col-row)]=1;
                    lower[row+col]=1;
                    queen(col+1,vec,ans,leftrow,upper,lower,n);
                    vec[row][col]='.';
                    leftrow[row]=0;
                    upper[n-1+(col-row)]=0;
                    lower[row+col]=0;
                }
            }
        }
       vector<vector<string>>solve(int n)
    {
    vector<vector<string>>ans;
    vector<string>vec(n);
    vector<int>temp;
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
    vec[i]=s;
    }
    vector<int> leftrow(n,0),upper(2*n-1,0),lower(2*n-1,0);
    queen(0,vec,ans,leftrow,upper,lower,n);
    return ans;
    }
    };
    class Solution
    {
    public:
    bool safe(int row,int col,vector<string>vec,int n)
    {
      int r=row;
      int c=col;
      //check row
      while(col>=0)
      {
        if(vec[row][col]=='Q') return false;
        col--;
      }
      //check lower
      row=r;
      col=c;
      while(row<n && col>=0)
      {
        if(vec[row][col]=='Q') return false;
        row++;
        col--;
      }
      //check upper
      row=r;
      col=c;
      while(row>=0 && col>=0)
      {
        if(vec[row][col]=='Q') return false;
        row--;
        col--;
      }
      return true;
    }
    void solvequeen(int col,vector<string>&vec,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(vec);
        }
        for(int row=0;row<n;row++)
        {
          if(safe(row,col,vec,n))
          {
            vec[row][col]='Q';
            solvequeen(col+1,vec,ans,n);
            vec[row][col]='.';
          }
        }
    }
    vector<vector<string>> solve(int n)
    {
    vector<vector<string>>ans;
    vector<string>vec(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
    vec[i]=s;
    }
    for(auto it:vec)
    {
            cout<<it<<" ";
    }
    cout<<endl;
    solvequeen(0,vec,ans,n);
    return ans;
    }
    };
    int main()
    {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    Solution obj;
    vector<vector<string>>ans=obj.solve(n);
    for(auto it:ans)
    {
        for(auto it1:it)
        {
            cout<<it1<<endl;
        }
        cout<<endl;
    }
    return 0;
    }