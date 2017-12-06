#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 100005

bool is_prime[N];
vector<ll>prime;

ll d[N];
ll sigma[N];

void precal()
{
    d[1]=1;
    sigma[1]=1;

    for(ll i=2;i<=N;i++)
    {
        d[i]=2;
        sigma[i]=1+i;
        for(ll j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                d[i]+=2;
                sigma[i]+=j+(i/j);
            }
        }

        ll temp=(ll)sqrt(i);
        if(temp*temp==i)
        {
            d [i]--;
            sigma[i]-=temp;
        }
    }
}


int main()
{
    precal();
    ll n,t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,res1=0,res2=0;
        cin>>a>>b>>c;
        for(ll i=a;i<=b;i++)
        {
            if(i%c==0)
            {
                res1+=d[i];
                res2+=sigma[i];
            }
        }
        cout<<res1<<" "<<res2<<endl;
    }
    return 0;
}
