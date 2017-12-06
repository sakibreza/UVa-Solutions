#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

ll n=8,cnt=0,a,b,res=0,grid[10];
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

void solve(ll col,ll w)
{
    if(col==n)
    {
//        cout<<w<<endl;
        res=min(res,w);
    }

    for(ll i=0;i<n;i++)
    {
        if(check(i,col))
        {
            ll temp=w;
            if(i+1!=grid[col]) temp++;
//            cout<<abs(i-grid[col])<<endl;
            row[col]=i;
            solve(col+1,temp);
        }
    }
}


int main()
{
//    freopen("output.txt","w",stdout);
    ll t,ks=0;
    while(cin>>grid[0])
    {
        ks++;
        res=1e12;
        for(ll i=1;i<n;i++)
        {
            cin>>grid[i];
        }
        solve(0,0);
        printf("Case %lld: %lld\n",ks,res);
    }
}

/**
2
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
**/


