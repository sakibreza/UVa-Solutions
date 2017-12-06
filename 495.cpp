#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

ll fibo[5001];

int main()
{
    fibo[0]=0;
    fibo[1]=1;
    for(ll i=2;i<=5000;i++)
        fibo[i]=fibo[i-1]+fibo[i-2];

    ll n;
    while(cin>>n)
    {
        printf("The Fibonacci number for %lld is %lld\n",n,fibo[n]);
    }
}



