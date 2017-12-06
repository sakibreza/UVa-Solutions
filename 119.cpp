#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 40000

int main()
{
    vector<string>v;
    map<string,ll>m;
    ll n,k=0;
    while(cin>>n)
    {
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.pb(s);
        }

        string s1,s2;
        ll a,b;
        for(ll i=0;i<n;i++)
        {
            cin>>s1;
            cin>>a>>b;
            if(b!=0)
            {
                ll x=a/b;
                ll y=x*b;
                m[s1]-=y;
                while(b--)
                {
                    cin>>s2;
                    m[s2]+=x;
                }
            }

        }
        if(k!=0)cout<<endl;
        for(ll i=0;i<v.size();i++)
        {
            cout<<v[i]<<" "<<m[v[i]]<<endl;
        }
        v.clear();
        m.clear();
       k++;
    }
}

/**
5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
**/
