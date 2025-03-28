    #include<bits\stdc++.h>
    using namespace std;
    class Solution{
        public:
    bool isvalid(string s)
    {
        stack<char>s1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                s1.push(s[i]);
            }
            else
            {
            char ch=s1.top();
            s1.pop();
            if((s[i]==')'&& ch=='(')|| (s[i]=='}'&&ch=='{')|| (s[i]==']'&&ch=='[')) 
            {     
            continue;
            }
            else return false;
        }
        }
        return s1.empty();
    }
    };
    int main()
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        string s;
        getline(cin,s);
        Solution sol;
        cout<<sol.isvalid(s);
        return 0;
    }