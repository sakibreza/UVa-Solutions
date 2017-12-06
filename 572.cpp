#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007


ll n,m,cnt=0;
ll ax[]={0,0,1,-1,1,-1,1,-1};
ll ay[]={1,-1,0,0,1,1,-1,-1};

bool visited[110][110];
char grid[110][110];

bool check(ll x,ll y)
{
    if(x>=0&&y>=0&&x<n&&y<m) return true;
    else return false;
}

void dfs(ll x,ll y)
{
    cnt++;
    visited[x][y]=true;
    for(ll i=0;i<8;i++)
    {
//        cout<<x+ax[i]<<" "<<y+ay[i]<<endl;

       if(check(x+ax[i],y+ay[i]))
       {

            char temp=grid[x+ax[i]][y+ay[i]];
            if(!visited[x+ax[i]][y+ay[i]]&&temp=='@')
            {
                //cout<<temp<<" "<<x+ax[i]<<" "<<y+ay[i]<<endl;
                dfs(x+ax[i],y+ay[i]);
            }
       }
    }
}

int main()
{
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }

        ll res=0;
        memset(visited,false,sizeof visited);
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                char curr=grid[i][j];
                if(!visited[i][j]&&curr=='@')
                {
//                    cout<<endl;
                    cnt=0;
                    dfs(i,j);
//                    cout<<cnt<<endl;
//                    cout<<i<<" "<<j<<endl;
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
