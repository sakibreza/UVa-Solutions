#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

ll f91(ll n)
{
    if(n>100) return n-10;
    else return f91(f91(n+11));
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n;
    while(cin>>n&&n)
    {
        printf("f91(%lld) = %lld\n",n,f91(n));
    }
    return 0;
}


