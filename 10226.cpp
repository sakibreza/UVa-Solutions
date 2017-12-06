#include<bits/stdc++.h>

using namespace std;

int main()
{
    map <string,int> m;
    int t;
    string str;

    cin>>t;

    getline(cin,str);
    getline(cin,str);

    for(int x=0;x<t;x++)
    {
        int c=0;

        if(x>0) cout<<endl;

        while(getline(cin,str)&&str.size()!=0)
        {
            m[str]++;
            c++;
        }

        for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        {
            cout<<it->first<<" "<<setprecision(4)<<fixed<<it->second*100.0/c<<endl;
        }

        m.clear();
    }

    return 0;
}
