#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

ll t,n,m;

class Edge
{
public:
    ll u,v,cost;
};

Edge edge[2003];

bool bellford()
{
    ll w[2003];
    memset(w,1e18,sizeof w);
    w[0]=0;

    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<m;j++)
        {
            w[edge[j].v]=min(w[edge[j].v],w[edge[j].u]+edge[j].cost);

        }
    }

    for(ll j=0;j<m;j++)
    {
        if(w[edge[j].v]>w[edge[j].u]+edge[j].cost)
            return true;
    }

    return false;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(ll i=0;i<m;i++)
        {
            cin>>edge[i].u>>edge[i].v>>edge[i].cost;
        }

        if(bellford()) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
    return 0;
}

