#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    while(cin>>t&&t!=0)
    {
        int p,q;
        cin>>p>>q;
        for(int x=0;x<t;x++)
        {
            int a,b;
            cin>>a>>b;
            if(a==p||b==q) cout<<"divisa"<<endl;
            else if(a>p&&b>q) cout<<"NE"<<endl;
            else if(a<p&&b>q) cout<<"NO"<<endl;
            else if(a<p&&b<q) cout<<"SO"<<endl;
            else cout<<"SE"<<endl;
        }
    }
    return 0;
}
