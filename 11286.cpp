#include<bits/stdc++.h>

using namespace std;

int main()
{
    map <string,int> m;
    vector <int> ans;
    string s;
    int t;

    while(cin>>t&&t!=0)
    {
        int c=0;

        for(int x=0;x<t;x++)
        {
            for(int y=0;y<5;y++)
            {
                cin>>s;
                m[s]++;
            }
        }

        for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        {
            if(it->second==t)c++;
        }

        ans.push_back(c);
    }

    for(int x=0;x<ans.size();x++)
    {
        cout<<ans[x]<<endl;
    }
}
