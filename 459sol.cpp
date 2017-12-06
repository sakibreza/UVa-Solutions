#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>

using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define KS printf("Case %d: ",kk++)

#define MOD 1000000007
#define MX 100010

bool vis[30];
vector<int>adj[30];

void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(!vis[v]) dfs(v);
    }
    return;
}
int main()
{
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,tc,c,w,x,y,z,n,m,u,v,cnt,mx,mn,p,q,r,sum;
    char s[3];
    cin>>tc;
    scanf("\n");
    while(tc--)
    {
        gets(s);
        n=s[0]-'A';
        CLR(vis);
        for(int i=0;i<=n;i++)   adj[i].clear();

        while(gets(s) && s[0])
        {
            adj[s[0]-'A'].push_back(s[1]-'A');
            adj[s[1]-'A'].push_back(s[0]-'A');
        }

        cnt=0;
        for(int i=0;i<=n;i++)
            if(!vis[i])
                dfs(i), cnt++;
        cout<<cnt<<endl;
        if(tc) cout<<endl;

    }
    return 0;
}
