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
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    vector<string>v;
    map<string,ll>m;
    string s;
    while(cin>>s)
    {
        string p;
        for(ll i=0;i<=s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                p.pb(tolower(s[i]));
            }

            else if(p.size())
            {
                if(!m[p]) v.pb(p);
                m[p]=1;
                p.clear();

            }
        }

    }

    sort(v.begin(),v.end());
    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}

