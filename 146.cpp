#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 40000

bool check(ll n)
{
    while(n%2==0||n%3==0||n%5==0)
    {
//        cout<<">>"<<n<<endl;
        if(n%2==0)n/=2;
        if(n%3==0)n/=3;
        if(n%5==0)n/=5;
        if(n==1)return true;
    }
    return false;
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s[0]=='#')break;

        if(next_permutation(s.begin(),s.end()))
        {
            cout<<s<<endl;
        }

        else cout<<"No Successor"<<endl;
    }
    return 0;
}

/**
5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
**/

