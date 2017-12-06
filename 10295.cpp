#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 10001
#define PI acos(-1.0)
#define M (ll)1e9+7

int main()
{
    ll m,n;
    cin>>m>>n;
    map<string,ll>mp;
    for(ll i=0;i<m;i++)
    {
        string s;
        ll v;
        cin>>s>>v;
        mp[s]=v;
    }

    for(ll i=0;i<n;i++)
    {
        string s;
        ll res=0;
        while(cin>>s&&s!=".")
        {
           res+=mp[s];
        }
        cout<<res<<endl;
    }

    return 0;
}
