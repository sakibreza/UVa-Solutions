#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll n=8,cnt=0,a,b;
ll row[10];

bool check(ll r,ll c)
{
    for(ll i=0;i<c;i++)
    {
        if(row[i]==r||abs(row[i]-r)==abs(i-c))
            return false;
    }

    return true;
}

void solve(ll col)
{
    if(col==n && row[b]==a)
    {
        printf("%2lld      %lld",++cnt,row[0]+1);

        for(ll i=1;i<n;i++)
        {
            cout<<" "<<row[i]+1;
        }
        cout<<endl;
    }

    for(ll i=0;i<n;i++)
    {
        if(check(i,col))
        {
            row[col]=i;
            solve(col+1);
        }
    }
}


int main()
{
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>a>>b;
        a--;b--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(0);
        if(t) cout<<endl;
    }
}


