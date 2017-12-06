#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

ll adj[101][101],u,v;
bool node[101];

void floyd_warshall()
{
    for(ll k=0;k<101;k++)
        for(ll i=0;i<101;i++)
            for(ll j=0;j<101;j++)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

}

int main()
{
    ll ks=0;
    while(cin>>u>>v && u!=0 &&v!=0)
    {
        ks++;
        memset(adj,63,sizeof adj);
        memset(node,0,sizeof node);

        node[u]=1;
        node[v]=1;
        adj[u][v]=1;
        while(cin>>u>>v && u!=0 &&v!=0)
        {
            node[u]=1;
            node[v]=1;
            adj[u][v]=1;
        }

        floyd_warshall();

        ll res=0,cnt=0;
        for(ll i=0;i<101;i++)
        {
            for(ll j=0;j<101;j++)
            {
                if(i!=j&&node[i]&&node[j])
                {
                    res+=adj[i][j];
//                    cout<<adj[i][j]<<endl;
                    cnt++;
                }
            }
        }

//        cout<<res<<" "<<cnt<<endl;

        cout<<"Case "<<ks<<": average length between pages = "<<fixed<<setprecision(3)<<res/(1.0*cnt)<<" clicks"<<endl;
    }
    return 0;
}


