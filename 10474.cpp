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
    ll n,q,cnt=0;
    while(cin>>n>>q&&n!=0&&q!=0)
    {
        cnt++;
        cout<<"CASE# "<<cnt<<":"<<endl;
        vector<ll>v;
        for(ll i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            v.pb(a);
        }

        sort(v.begin(),v.end());

        for(ll i=0;i<q;i++)
        {
            ll qr;
            cin>>qr;
            bool flag=false;
            for(ll i=0;i<v.size();i++)
            {
                if(v[i]==qr)
                {
                    cout<<qr<<" found at "<<i+1<<endl;
                    flag=true;
                    break;
                }
            }
            if(!flag) cout<<qr<<" not found"<<endl;
        }
    }
    return 0;
}

