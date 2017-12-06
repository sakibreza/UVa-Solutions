
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
int main()
{
    ll l,w,h,O;
    while(cin>>l>>w>>h>>O)
    {
        double res;
        double O1=O*PI/180.0;
        double y=l/cos(O1);
        double x=sin(O1)*y;
        double dia=sqrt(l*l+h*h);
        if(y<=dia)
        {
            res=l*h-(x*l)/2.0;
            res*=w;
        }
        else
        {
            double x1=h/tan(O1);
            res=x1*h/2.0;
            res*=w;
        }
        cout<<fixed<<setprecision(3)<<res<<" mL"<<endl;
    }
    return 0;
}



