#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

ll level[10][10];
bool vis[10][10];
ll ax[]={2,1,-1,-2,-2,-1,1,2};
ll ay[]={1,2,2,1,-1,-2,-2,-1};

bool check(ll x,ll y)
{
    if(x>=0&&y>=0&&x<8&&y<8)
        return true;
    return false;
}

void bfs(string src,string des)
{
    ll sx=src[0]-'a';
    ll sy=src[1]-'1';
    ll dx=des[0]-'a';
    ll dy=des[1]-'1';

    vis[sx][sy]=true;
    queue<pair<ll,ll> >q;
    q.push(mp(sx,sy));
    while(!q.empty())
    {
        sx=q.front().first;
        sy=q.front().second;
        vis[sx][sy]=true;
        q.pop();
        for(ll i=0;i<8;i++)
        {
            ll x=sx+ax[i];
            ll y=sy+ay[i];
            if(check(x,y)&&!vis[x][y])
            {
                level[x][y]=level[sx][sy]+1;
                q.push(mp(x,y));
            }
        }
    }
}

int main()
{
    string s,d;
    while(cin>>s>>d)
    {
        memset(vis,0,sizeof vis);
        memset(level,0,sizeof level);
        bfs(s,d);
        printf("To get from %c%c to %c%c takes %lld knight moves.\n",s[0],s[1],d[0],d[1],level[d[0]-'a'][d[1]-'1']);
    }
    return 0;
}

