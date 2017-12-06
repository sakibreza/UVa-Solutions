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
ll arr[30];
ll dp[205][21];

bool knapsack(ll w,ll n)
{

    if(w==0)
    {
        dp[w][n]=1;
        return 1;
    }
    else if(w<0) return 0;
    else if(n<=0) return 0;

     if(dp[w][n]!=-1)
        return dp[w][n];

    if(knapsack(w-arr[n-1],n-1))
    {
        dp[w][n]=1;
        return 1;
    }
    if(knapsack(w,n-1))
    {
        dp[w][n]=1;
        return 1;
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sum=0;
    cin>>m;
    string s;
    getline(cin,s);
    for(ll i=0;i<m;i++)
    {
        memset(dp,-1,sizeof dp);
        cnt=0;
        sum=0;
        getline(cin,s);
        stringstream ss(s);


        while(ss>>arr[cnt])
        {
            sum+=arr[cnt++];
        }

        if(sum%2)
        {
            cout<<"NO"<<endl;
        }

        else
        {
            if(knapsack(sum/2,cnt))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}


