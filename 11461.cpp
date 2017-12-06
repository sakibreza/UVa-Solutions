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
//    freopen("output.txt","w",stdout);
    ll a,b;
    while(cin>>a>>b&&a!=0&&b!=0)
    {
        cout<<(ll)sqrt(b)-(ll)sqrt(a-1)<<endl;
    }
    return 0;
}


