#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1000006

ll n;
ll ax[]={1,1,1,0,0,-1,-1,-1};
ll ay[]={1,0,-1,1,-1,1,0,-1};
vector<string>vs;
bool visited[25][25];

void dfs(ll x,ll y)
{
    visited[x][y]=true;
    for(ll i=0;i<8;i++)
    {
        ll a,b;
        a=x+ax[i];
        b=y+ay[i];
        if(a>=0&&b>=0&&a<n&&b<n&&!visited[a][b])
        {
            if(vs[a][b]=='1')dfs(a,b);
        }
    }
}

int main()
{
    ll k=0;
    while(cin>>n)
    {
        k++;
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vs.pb(s);
        }

        ll res=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<vs[i].size();j++)
            {
                if(vs[i][j]=='1'&&!visited[i][j])
                {
                    dfs(i,j);
                    res++;
                }
            }
        }
        cout<<"Image number "<<k<<" contains "<<res<<" war eagles."<<endl;
        vs.clear();
        memset(visited,0,sizeof visited);
    }
    return 0;

}

