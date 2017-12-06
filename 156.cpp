#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007


string process(string s)
{
    for(ll i=0;i<s.size();i++)
    {
        s[i]=tolower(s[i]);
    }

    sort(s.begin(),s.end());
    return s;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    map<string,ll>m;
    vector<pair<string,string> >v;
    string s;
    while(cin>>s&&s!="#")
    {
        string ps=process(s);
        m[ps]++;
        v.pb(mp(s,ps));
    }

    sort(v.begin(),v.end());

    for(ll i=0;i<v.size();i++)
    {
        if(m[v[i].second]==1)
            cout<<v[i].first<<endl;
    }
    return 0;
}

