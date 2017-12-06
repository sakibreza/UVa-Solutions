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
    ll n;
    while(cin>>n)
    {
        string s[101];
        ll mxlen=0;
        for(ll i=0;i<n;i++)
        {
            cin>>s[i];
            mxlen=max(mxlen,(ll)s[i].size());
        }

        sort(s,s+n);

        ll col=(60-mxlen)/(mxlen+2) + 1;
        ll adjust=mxlen+2;
        ll row=ceil((double)n/col);
//        cout<<mxlen<<" "<<row<<endl;

        for(ll i=0;i<60;i++) cout<<"-";
        cout<<endl;

        for(ll i=0;i<row;i++)
        {
            for(ll j=i;j<n;j+=row)
            {
                cout<<s[j];
                if(j+row<n)
                {
                    for(ll k=s[j].size();k<adjust;k++)
                    {
                        cout<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}



