#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 10001
#define PI acos(-1.0)
#define M (ll)1e9+7

bool operator<(pair<ll,ll>a,pair<ll,ll>b)
{
    return a.second>b.second;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll s;
    map<ll,ll>m;
    vector<ll>v;
    while(cin>>s)
    {
        m[s]++;
        if(m[s]==1)
        {
            v.pb(s);
        }
    }

    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i]<<" "<<m[v[i]]<<endl;
    }



    return 0;
}
