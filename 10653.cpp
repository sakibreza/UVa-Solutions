#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

ll n,m;
ll level[1005][1005];
bool vis[1005][1005];
ll grid[1005][1005];
ll ax[]={0,1,-1,0};
ll ay[]={1,0,0,-1};

bool check(ll x,ll y)
{
    if(x>=0&&y>=0&&x<n&&y<m)
        return true;
    return false;
}

void bfs(ll sx,ll sy,ll dx,ll dy)
{
    vis[sx][sy]=true;
    level[sx][sy]=0;
    queue<pair<ll,ll> >q;
    q.push(mp(sx,sy));
    while(!q.empty())
    {
        sx=q.front().first;
        sy=q.front().second;
        vis[sx][sy]=true;
        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll x=sx+ax[i];
            ll y=sy+ay[i];
            if(check(x,y)&&!vis[x][y])
            {
//                if(x==0&&y==0)cout<<vis[x][y]<<endl;
                vis[x][y]=true;
                level[x][y]=level[sx][sy]+1;
                q.push(mp(x,y));
            }
        }
    }
    cout<<level[dx][dy]<<endl;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        memset(vis,0,sizeof vis);
        memset(level,0,sizeof level);
        ll r;
        cin>>r;
        for(ll i=0;i<r;i++)
        {
            ll row,n;
            cin>>row>>n;
            for(ll j=0;j<n;j++)
            {
                ll a;
                cin>>a;
                vis[row][a]=true;
            }
        }
        ll sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        bfs(sx,sy,dx,dy);
    }
    return 0;
}

