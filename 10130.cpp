#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll m,sum=0,cnt=0;
ll wt[1005];
ll val[1005];
ll dp[35][1005];

ll knapsack(ll w,ll n)
{

    if(w==0||n==0) return 0;

    ll &ret=dp[w][n];
    if(ret!=-1) return ret;

    ret=knapsack(w,n-1);

    if(w>=wt[n-1])
        ret=max(ret,val[n-1]+knapsack(w-wt[n-1],n-1));

    return ret;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>val[i]>>wt[i];
        }

        ll g,res=0;
        cin>>g;
        for(ll i=0;i<g;i++)
        {
            ll c;
            cin>>c;
            res+=knapsack(c,n);
        }
        cout<<res<<endl;
    }

    return 0;
}


