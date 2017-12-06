#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 40000

bool is_prime[N];
vector<ll>prime;

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


int main()
{
    sieve(N);
    ll n;
    while(cin>>n&&n!=0)
    {
        ll res=0;

        for(ll i=2;2*i<=n;i++)
        {
            ll f=n-i;
            if(is_prime[f]&&is_prime[i])
            {
                res++;
            }
        }
        cout<<res<<endl;
    }
}
