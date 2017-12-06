#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

map<string,vector<string> >graph;
map<string,bool>vis;
map<string,ll>level;
map<string,string>par;

void bfs(string src,string des)
{
    vis[src]=true;
    par[src]="-1";
    queue<string>q;
    q.push(src);
    while(!q.empty())
    {
        string curr=q.front();
        q.pop();
        for(ll i=0;i<graph[curr].size();i++)
        {
            string temp=graph[curr][i];
//            cout<<temp<<endl;
            if(!vis[temp])
            {
                vis[temp]=true;
                level[temp]=level[curr]+1;
//                cout<<temp<<" "<<curr<<" "<<level[temp]<<" "<<level[curr]+1<<endl;
                par[temp]=curr;
                q.push(temp);
            }
        }
    }

    if(!level[des])
    {
        cout<<"No route";
        return;
    }

    vector<string>path;
    path.pb(des);
    while(des!="-1")
    {
        des=par[des];
        path.pb(des);
    }

    for(ll i=path.size()-2;i>=1;i--)
    {
        cout<<path[i]<<" "<<path[i-1];
        if(i!=1)cout<<endl;
    }
    graph.clear();
    vis.clear();
    level.clear();
    par.clear();
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,cnt=0;
    while(cin>>n)
    {
        if(cnt)cout<<endl<<endl;
        cnt++;
        while(n--)
        {
            string a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        string a,b;
        cin>>a>>b;
        bfs(a,b);
    }
    cout<<endl;

    return 0;
}
