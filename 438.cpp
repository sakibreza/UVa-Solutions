#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
int main()
{
    double x1,x2,x3,y1,y2,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        double a,b,c,r;
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        double s=(a+b+c)/2.0;
        r=(a*b*c)/(4*sqrt(s*(s-a)*(s-b)*(s-c)));

        double res=2*PI*r;
        cout<<fixed<<setprecision(2)<<res<<endl;
    }
    return 0;
}

