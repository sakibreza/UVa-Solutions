#include <bits/stdc++.h>

using namespace std;

int n,m,capacity;
int dp[105][25005],value[100];

long long knapsack(int idx,int w)
{
    if(idx>=m) return 0;
    int &ret=dp[idx][w];
    if(ret!=-1) return ret;

    int p=0,q=0;
    if(capacity>=w+value[idx]) p=value[idx]+knapsack(idx+1,value[idx]+w);
    q=knapsack(idx+1,w);
    return ret=max(p,q);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>m;
        capacity=0;
        for(int i=0;i<m;i++)
        {
            int coin_value;
            cin>>coin_value;
            value[i]=coin_value;
            capacity+=coin_value;
        }

        int sum=capacity;
        capacity/=2;
        memset(dp,-1,sizeof dp);

        cout<<sum-2*knapsack(0,0)<<endl;
    }
    return 0;
}
