#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
int Set(int n,int pos){return n=n | (1<<pos);}
int reset(int n,int pos){return n=n & ~(1<<pos);}
bool check(int n,int pos){return (bool)(n & (1<<pos));}
/*------------------------------------------------*/

ll n;
ll arr[]={2,3,5,7,11,13,17,19,23,29,31,37};
bool vis[100];

void go(ll id,ll mask,vector<ll>v,ll last)
{
    if(id>=n)
    {
        if(vis[last+1]==0) return;

        cout<<v[0];
        for(ll i=1;i<n;i++)
        {
            cout<<" "<<v[i];
        }
        cout<<endl;
    }

    for(ll i=1;i<=n;i++)
    {
        if(!check(mask,i) && vis[last+i])
        {
            vector<ll>temp=v;
            temp.pb(i);
            go(id+1,Set(mask,i),temp,i);
        }
    }
}

int main()
{
    ll k=0;
    for(ll i=0;i<12;i++)
        vis[arr[i]]=1;
    while(cin>>n)
    {
        if(k++) cout<<endl;

        cout<<"Case "<<k<<":"<<endl;
        vector<ll>v;
        v.pb(1);
        go(1,Set(0,1),v,1);
    }
    return 0;
}

