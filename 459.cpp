#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
map<ll,vector<ll> >edge;
map<ll,bool>visited;

void dfs(ll n)
{
    visited[n]=true;
    for(ll i=0;i<edge[n].size();i++)
    {
        ll temp=edge[n][i];
        if(!visited[temp])
        {
            dfs(temp);
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    scanf("\n");
    while(t--)
    {
        string s;
        getline(cin,s);
        ll n=s[0]-'A';

        while(getline(cin,s) && s[0])
        {
            edge[s[0]-'A'].pb(s[1]-'A');
            edge[s[1]-'A'].pb(s[0]-'A');
        }

        ll res=0;
        for(ll i=0;i<=n;i++)
        {
            if(!visited[i])
            {
                dfs(i);
                res++;
            }
        }
        cout<<res<<endl;
        if(t)cout<<endl;
        edge.clear();
        visited.clear();
    }
    return 0;
}

/**
1
E
AB
CE
DB
EC
**/
