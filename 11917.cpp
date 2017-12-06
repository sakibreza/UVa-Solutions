#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 40000

int main()
{
    ll t,k=0;
    cin>>t;
    while(t--)
    {
        k++;
        map<string,ll>m;
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            string s;
            ll c;
            cin>>s>>c;
            m[s]=c;
        }

        string s;ll c;
        cin>>c>>s;
        cout<<"Case "<<k<<": ";
        if(m[s]&&m[s]<=c)cout<<"Yesss"<<endl;
        else if(m[s] && m[s]<=c+5) cout<<"Late"<<endl;
        else cout<<"Do your own homework!"<<endl;
    }

    return 0;
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

