#include<bits/stdc++.h>

using namespace std;

long long dp[10005];

int cube(int n)
{
    return n*n*n;
}

void coin_change()
{
    dp[0]=1;

    for(int x=1;x<22;x++)
    {
        int cuby=cube(x);
        for(int y=cuby;y<10005;y++)
        {
            dp[y]+=dp[y-cuby];

        }
    }
}


int main()
{
    memset(dp,0,sizeof dp);
    coin_change();
    int i;
    while(cin>>i)
    {
        cout<<dp[i]<<endl;
    }

    return 0;
}
