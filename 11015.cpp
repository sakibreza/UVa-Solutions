#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007
#define inf 1e12

using namespace std;

ll n,m;
string name[30];
ll dis[30][30];


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t=0;
    while(cin>>n>>m && (n!=0||m!=0))
    {
        t++;
        for(ll i=0; i<30; i++)
        {
            for(ll j=0; j<30; j++)
            {
                if(i==j) dis[i][j]=0;
                else dis[i][j]=inf;
            }
        }

        for(ll i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            name[i]=s;
        }

        for(ll i=0; i<m; i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            dis[x][y]=z;
            dis[y][x]=z;
        }

        for(ll k=1; k<=n; k++)
            for(ll i=1; i<=n; i++)
                for(ll j=1; j<=n; j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

        ll res1,res2=0;
        res1=inf;
        for(ll i=1; i<=n; i++)
        {
            ll sum=0;
            for(ll j=1; j<=n; j++)
            {
                sum+=dis[i][j];
            }
            if(res1>sum)
            {
                res1=sum;
                res2=i;
            }
        }

        printf("Case #%lld : ",t);
        cout<<name[res2]<<endl;
    }
}


