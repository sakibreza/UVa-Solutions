#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

int main()
{
    ll n,m,ans;
    while(cin>>n>>m)
    {
        if(m==0) cout<<1<<endl;
        else
        {
            ans=1;
            for(ll i=n-m+1;i<=n;i++)
            {
                ans*=i;
                while(ans%10==0)
                    ans/=10;
                ans%=1000000000;
            }
            cout<<ans%10<<endl;
        }
    }
    return 0;
}

