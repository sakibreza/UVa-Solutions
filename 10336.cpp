#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1000006

ll n,m;
ll ax[]={1,0,-1,0};
ll ay[]={0,1,0,-1};
vector<string>vs;
vector<pair<char,ll> >rv;
bool visited[100][100];

bool cmp(pair<char,ll> a, pair<char,ll> b)
{
    if(a.second!=b.second)
        return a.second>b.second;
    return a.first<b.first;
}

void dfs(ll x,ll y,char ch)
{
    visited[x][y]=true;
    for(ll i=0;i<4;i++)
    {
        ll a,b;
        a=x+ax[i];
        b=y+ay[i];
        if(a>=0&&b>=0&&a<n&&b<m&&!visited[a][b])
        {
            if(vs[a][b]==ch)dfs(a,b,ch);
        }
    }
}

int main()
{
    ll k=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        k++;
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vs.pb(s);
        }

        ll res=0;
        for(ll c='a';c<='z';c++)
        {
            res=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<vs[i].size();j++)
            {
                if(vs[i][j]==(char)c&&!visited[i][j])
                {
                    dfs(i,j,vs[i][j]);
                    res++;
                }
            }
        }
            if(res>0) rv.pb(mp((char)c,res));
        }
        sort(rv.begin(),rv.end(),cmp);
        printf("World #%d\n", k);
        for(ll i=0;i<rv.size();i++)
            printf("%c: %d\n",rv[i].first,rv[i].second);
        vs.clear();
        rv.clear();
        memset(visited,0,sizeof visited);
    }
    return 0;

}

