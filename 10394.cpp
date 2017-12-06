#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 20000007

bool is_prime[20000007];
vector<ll>tprime;

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
        if(is_prime[i]&&is_prime[i+2])
        {
            tprime.pb(i);
        }
        if(tprime.size()>100001) break;
    }


}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve(N);

    ll n;
    while(cin>>n)
    {
        printf("(%lld, %lld)\n",tprime[n-1],tprime[n-1]+2);
    }
    return 0;
}


