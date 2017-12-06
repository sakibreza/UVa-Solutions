#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e18

string word[1001][200];
ll mxlen[200];

ll c=0,r=0;
string s;

void preprocess()
{
    while(getline(cin,s))
    {
        c=0;
        stringstream ss(s);
        while(ss>>word[r][c])
        {
            mxlen[c]=max(mxlen[c],(ll)word[r][c].size());
            c++;
        }
        word[r][c]="sesh";
        r++;
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    preprocess();
    for(ll i=0;i<r;i++)
    {
        for(ll j=0;word[i][j]!="sesh";j++)
        {
            cout<<word[i][j];
            if(word[i][j+1]!="sesh")
            {
                for(ll space=0;space<=mxlen[j]-word[i][j].size();space++)
                {
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}





