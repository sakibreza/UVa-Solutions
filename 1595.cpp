#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

map<pair<ll,ll>,ll>m;

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll t;
    cin>>t;
    while(t--)
    {
        m.clear();
        ll n,mx=-1e18,mn=1e18;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            mx=max(mx,x);
            mn=min(mn,x);
            m[mp(x,y)]++;
        }

        ll d=mx+mn;

        bool flag=true;
        for(map<pair<ll,ll>,ll>::iterator it=m.begin();it!=m.end();it++)
        {
            ll xx,yy;
            xx=(it->first).first;
            yy=(it->first).second;
            if(!m[mp((d-xx),yy)])
            {
//                cout<<d-xx<<" "<<yy<<endl;
                flag=false;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}






