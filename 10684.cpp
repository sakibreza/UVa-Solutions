#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,dp[10004],a[10004];

    while((cin>>N)&&N!=0)
    {
        for(int x=0;x<N;x++)cin>>a[x];

        memset (dp, 0, sizeof (dp));

        dp[0]=a[0];
        for(int x=1;x<N;x++)
        {
        if(dp[x-1]+a[x]>a[x])dp[x]=dp[x-1]+a[x];
        else dp[x]= a[x];

        //cout<<dp[x]<<endl;
        }

        sort(dp,dp+N);

        if(dp[N-1]>0) cout<<"The maximum winning streak is "<<dp[N-1]<<"."<<endl;
        else cout<<"Losing streak."<<endl;
    }

    return 0;
}
