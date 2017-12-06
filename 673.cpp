#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

int main()
{
    string s;
    ll t;
    cin>>t;
    getline(cin,s);
    while(t--)
    {
        stack<char>stk;
        getline(cin,s);
        for(ll i=0;i<s.size();i++)
        {
            if(!stk.empty()&&s[i]==')'&&stk.top()=='(')
                stk.pop();
            else if(!stk.empty()&&s[i]==']'&&stk.top()=='[')
                stk.pop();
            else stk.push(s[i]);
        }

        if(!stk.empty())cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}

