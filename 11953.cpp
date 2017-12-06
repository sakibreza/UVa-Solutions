#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll n;
ll ax[]={-1,0,1,0};
ll ay[]={0,1,0,-1};
string grid[102];

void dfs(ll x,ll y)
{
   if(x<0||x>=n||y<0||y>=n||grid[x][y]=='.') return;
   grid[x][y]='.';

   for(ll i=0;i<4;i++)
   {
       dfs(x+ax[i],y+ay[i]);
   }
}

int main()
{
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>grid[i];

        ll res=0;

        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
//                cout<<grid[i][j];
                if(grid[i][j]=='x')
                {
                    res++;
                    dfs(i,j);
                }
            }
//            cout<<endl;
        }
        cout<<"Case "<<ks<<": "<<res<<endl;
    }
}
