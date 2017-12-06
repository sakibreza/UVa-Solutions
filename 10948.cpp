#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 10000007

bool is_prime[N];
vector<ll>prime;
ll x;

void sieve(ll n)
{
    memset(is_prime,true,sizeof is_prime);

    is_prime[0]=false;
    is_prime[1]=false;

    for(ll i=2;i*i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            for(ll j=i*i;j<=n;j+=i)
            {
                is_prime[j]=false;
            }
        }
    }

    for(ll i=0;i<n;i++)
    {
        if(is_prime[i]) prime.pb(i);
    }
}


bool check(ll n)
{
    if(n==4 || n%2==1)
    {
        x=2;
        return is_prime[n-x];
    }

    for(ll i=0;i<prime.size()&&prime[i]<=n/2;i++)
    {
        if(is_prime[n-prime[i]])
        {
            x=prime[i];
            return true;
        }
    }

    return false;
}

int main()
{
    sieve(N);
    ll n,t,cnt=0;
    while(cin>>n && n!=0)
    {
        printf("%lld:\n",n);
        if(check(n)) printf("%lld+%lld\n",x,n-x);
        else printf("NO WAY!\n");
    }
}
