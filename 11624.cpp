#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

string grid[1001];
ll F[1001][1001],J[1001][1001];
ll n,m;
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};

class point
{
public:
    ll x,y;
};

point pf,pj;
point tn,tx;
queue<point>q;

void ini()
{
    ll i,j;
    while(!q.empty()) q.pop();
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(grid[i][j]=='F')
            {
                pf.x=i,pf.y=j;
                q.push(pf);
                F[pf.x][pf.y]=1;
            }
        }
    }

    while(!q.empty())
    {
        tn=q.front();
        q.pop();
        for(ll i=0;i<4;i++)
        {
            tx.x=tn.x+dx[i];
            tx.y=tn.y+dy[i];
            if(tx.x<0||tx.x>=n||tx.y<0||tx.y>=m)
                continue;
            if(grid[tx.x][tx.y]=='#')
                continue;
            if(F[tx.x][tx.y]==0)
            {
                F[tx.x][tx.y]=F[tn.x][tn.y]+1;
                q.push(tx);
            }
        }
    }

}

void solve()
{
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(grid[i][j]=='J')
                pj.x=i,pj.y=j;
        }
    }
    q.push(pj);
    J[pj.x][pj.y]=1;
    while(!q.empty())
    {
        tn=q.front();
        q.pop();
        if(tn.x==0||tn.y==0||tn.x==n-1||tn.y==m-1)
        {
            cout<<J[tn.x][tn.y]<<endl;
            return;
        }

        for(ll i=0;i<4;i++)
        {
            tx.x=tn.x+dx[i];
            tx.y=tn.y+dy[i];

            if(tx.x<0||tx.x>=n||tx.y<0||tx.y>=m)
                continue;
            if(grid[tx.x][tx.y]=='#')
                continue;
            if(J[tx.x][tx.y]==0&&(J[tn.x][tn.y]+1<F[tx.x][tx.y]||F[tx.x][tx.y]==0))
            {
                J[tx.x][tx.y]=J[tn.x][tn.y]+1;
                q.push(tx);
            }
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(ll i=0;i<n;i++)
        {
            cin>>grid[i];
            for(ll j=0;j<m;j++)
            {
                F[i][j]=0,J[i][j]=0;
            }
        }
        ini();
        solve();
    }

    return 0;
}
