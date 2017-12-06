#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n;
    while(cin>>n && n!=0)
    {
        map<pair<ll,ll>,ll>m;
        for(ll i=0;i<n;i++)
        {
            ll a,b;
            cin>>a>>b;
            m[mp(a,b)]++;
        }

        bool flag=true;
        for(map<pair<ll,ll>,ll>::iterator it=m.begin();it!=m.end();it++)
        {
            ll a,b;
            a=(it->first).second;
            b=(it->first).first;
            if(m[mp(b,a)]!=m[mp(a,b)])
            {
                flag=false;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}




