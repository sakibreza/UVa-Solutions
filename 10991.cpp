#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        double r1,r2,r3;
        cin>>r1>>r2>>r3;
        double a,b,c;
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        double s=(a+b+c)/2.0;
        double A,B,C;
        C=acos((a*a+b*b-c*c)/(2*a*b));
        A=acos((b*b+c*c-a*a)/(2*b*c));
        B=acos((c*c+a*a-b*b)/(2*c*a));
        double area1=sqrt(s*(s-a)*(s-b)*(s-c));
        double area2=(r1*r1*B+r2*r2*C+r3*r3*A)/2.0;
        cout<<fixed<<setprecision(6)<<area1-area2<<endl;
    }
    return 0;
}

