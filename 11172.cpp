#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b;
    int t;
    cin>>t;
    for(int x=0;x<t;x++)
    {
        cin>>a>>b;
        if(a>b)cout<<">"<<endl;
        else if(a<b)cout<<"<"<<endl;
        else cout<<"="<<endl;
    }

    return 0;
}

