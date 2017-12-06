#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll m,n;
ll wt[105];
ll val[105];
ll dp[15205][105];

ll knapsack(ll w,ll n)
{
    if(n==0||w<=-200) return 0;

    ll &ret=dp[w+200][n];
    if(ret!=-1) return ret;

    ret=knapsack(w,n-1);

    if( (w+200>=wt[n-1] && m-w+wt[n-1]>2000) || w>=wt[n-1])
    {
        ret=max(ret,val[n-1]+knapsack(w-wt[n-1],n-1));
    }

    return ret;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll ks=0;
    while(cin>>m>>n)
    {
        memset(dp,-1,sizeof dp);

        for(ll i=0;i<n;i++)
        {
            cin>>wt[i]>>val[i];
        }

        cout<<knapsack(m,n)<<endl;
    }
    return 0;
}


