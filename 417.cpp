#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

ll cnt=1;
queue<string>q;
map<string,ll>m;

void precal()
{
    for(char c='a';c<='z';c++)
    {
        string s;
        s.pb(c);
        q.push(s);
    }
    string temp;
    while(!q.empty()&&temp.size()<=5)
    {
//        cout<<temp<<" "<<temp.size()<<endl;
        temp=q.front();
        q.pop();

        m[temp]=cnt++;

        if(temp.size()<=5)
            for(char i=temp[temp.size()-1]+1;i<='z';i++)
            {
//                cout<<temp[i]<<endl;
                string temp2=temp;
                temp2.pb(i);
                q.push(temp2);
            }

    }
}

int main()
{
    precal();
    string s;
    while(cin>>s)
    {
        cout<<m[s]<<endl;
    }
    return 0;
}

