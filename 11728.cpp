#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
//#define N 100005

ll sum_d[1005];

void SumOfDivisor_N_logN(ll N)
{
    for(ll i=1;i<=N;i++)
    {
        for(ll j=i;j<=N;j+=i)
        {
            sum_d[j]+=i;
        }
    }
}

int main()
{
    ll res[1005];
    memset(res,-1,sizeof res);
    SumOfDivisor_N_logN(1001);
    for(ll i=1;i<=1000;i++)
    {
        if(sum_d[i]<=1000) res[sum_d[i]] = i;
    }

    ll n,k=0;
    while(cin>>n && n)
    {
        k++;
        cout<<"Case "<<k<<": "<<res[n]<<endl;
    }

    return 0;
}
