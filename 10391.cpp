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
    string s;
    vector<string>v;
    map<string,ll>m;
    while(cin>>s)
    {
        v.pb(s);
        m[s]++;
    }

    for(ll i=0;i<v.size();i++)
    {
        string first,second;
        for(ll j=1;j<v[i].size()-1;j++)
        {
            first=v[i].substr(0,j);
            second=v[i].substr(j,v[i].size());
            if(m[first]&&m[second])
            {
                cout<<v[i]<<endl;
                break;
            }
        }
    }
    return 0;
}




