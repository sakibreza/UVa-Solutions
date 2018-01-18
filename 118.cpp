#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007
#define inf 1e12

using namespace std;

ll grid[60][60];
bool vis[60][60];
ll n, m, ix, iy;
bool dead=0;
char d;

void command(char c)
{
    if(c=='R')
    {
        if(d=='N')
            d = 'E';
        else if(d=='E')
            d = 'S';
        else if(d=='S')
            d = 'W';
        else if(d=='W')
            d = 'N';
    }

    else if(c=='L')
    {
        if(d=='N')
            d = 'W';
        else if(d=='E')
            d = 'N';
        else if(d=='S')
            d = 'E';
        else if(d=='W')
            d = 'S';
    }

    else if(c=='F')
    {
        if(d=='N')
        {
            if(iy+1>m && vis[ix][iy]==0)
            {
                vis[ix][iy]=1;
                dead=1;
            }

            else if(iy+1<=m)
                iy++;
        }

        if(d=='S')
        {
            if(iy-1<0 && vis[ix][iy]==0)
            {
                vis[ix][iy]=1;
                dead=1;
            }

            else if(iy-1>=0)
                iy--;
        }

        if(d=='E')
        {
            if(ix+1>n && vis[ix][iy]==0)
            {
                 vis[ix][iy]=1;
                 dead=1;
            }

            else if(ix+1<=n)
                ix++;
        }

        if(d=='W')
        {
            if(ix-1<0 && vis[ix][iy]==0)
             {
                 vis[ix][iy]=1;
                 dead=1;
             }

            else if(ix-1>=0)
                ix--;
        }


    }
}

int main()
{
    cin>>n>>m;
    while(cin>>ix>>iy>>d)
    {
        dead=0;
        string s;
        cin>>s;
        for(ll i=0;i<s.size();i++)
        {
//            cout<<d<<endl;
            command(s[i]);
//            cout<<s[i]<<">> "<<ix<<" "<<iy<<endl;
            if(dead==1)break;
        }

        if(dead) cout<<ix<<" "<<iy<<" "<<d<<" LOST"<<endl;
        else cout<<ix<<" "<<iy<<" "<<d<<endl;
    }

    return 0;
}


