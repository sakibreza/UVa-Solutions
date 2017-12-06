#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

ll ncr[101][101];

int main()
{
    ncr[1][1]=1;
    ncr[1][0]=1;
    for(ll i=2;i<=100;i++)
    {
        ncr[i][0]=1;
        for(ll j=1;j<=i;j++)
        {
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }

    ll n,r;
    while(cin>>n>>r&&n!=0&&r!=0)
    {
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,r,ncr[n][r]);
    }
}


