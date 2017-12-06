#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
int main()
{
//        freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    double r,n;
    while(cin>>r>>n)
    {
        double res=0.5*n*r*r*sin((2*PI)/n);
        cout<<fixed<<setprecision(3)<<res<<endl;
    }
    return 0;
}


