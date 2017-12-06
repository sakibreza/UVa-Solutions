#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001

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

    prime.pb(1);
    for(ll i=0;i<n;i++)
    {
        if(is_prime[i]) prime.pb(i);
    }
}


int main()
{
    sieve(N);
    ll n,c;
    while(cin>>n>>c)
    {
        printf("%lld %lld:",n,c);
        ll l[1001],cnt=0;
        for(ll i=0;i<prime.size();i++)
        {
            if(prime[i]>n) break;
            l[cnt++]=prime[i];
        }

        if(cnt%2==1) c=2*c-1;
        else c*=2;

        if(c>cnt) c=cnt;

        for(ll i=cnt/2-c/2;i<cnt/2-c/2+c;i++)
            printf(" %lld",l[i]);
        printf("\n\n");
    }
}
