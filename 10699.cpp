#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 100000008

ll res;
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
        if(is_prime[i])prime.pb(i);
    }
}

bool check(ll n)
{
    if(n%2)
    {
        res=2;
        return is_prime[n-res];
    }

    ll pos=(upper_bound(prime.begin(),prime.end(),n/2)-prime.begin());

    for(;pos>=0;pos--)
    {
        ll temp=n-prime[pos];
        if(is_prime[temp])
        {
            if(2*prime[pos]==n) continue;
            res=min(prime[pos],n-prime[pos]);
            return true;
        }
    }

    return false;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve(N);

    ll n;
    while(cin>>n)
    {
        if(check(n))
        {
            printf("%lld is the sum of %lld and %lld.\n",n,res,n-res);
        }

        else
            printf("%lld is not the sum of two primes!\n", n);
    }
    return 0;
}
