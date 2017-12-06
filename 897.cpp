#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001

bool is_prime[N];
vector<ll>gram;
vector<ll>v;

ll add()
{
    ll res=0;
    for(ll i=0;i<v.size();i++)
    {
        res*=10;
        res+=v[i];
    }
    return res;
}

bool ana(ll n)
{
    v.clear();
    while(n!=0)
    {
        v.pb(n%10);
        n/=10;
    }

    sort(v.begin(),v.end());

    do
    {
        ll temp=add();
        if(!is_prime[temp]) return false;
    }
    while(next_permutation(v.begin(),v.end()));

    return true;
}

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

    for(ll i=2;i<n;i++)
    {
        if(is_prime[i])
        {
            if(ana(i))
            {
                gram.pb(i);
            }
        }
    }

}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sieve(N);

    ll n;
    while(cin>>n &&n!=0)
    {
        ll up=ceil(log10(n));
        if(log10(n)==(ll)log10(n))up++;
        ll temp=(ll)round(pow(10,up));
        ll ans=0;
        for(ll i=0;i<gram.size();i++)
        {
            if(gram[i]>n)
            {
                ans=gram[i];
                if(ans>temp)ans=0;
                break;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
