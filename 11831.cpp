#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;


string grid[101];

int main()
{
    ll n,m,s;
    while(cin>>n>>m>>s)
    {
        if(n==0&&m==0&&s==0) break;

        ll res=0;
        char dir;
        ll ix,iy;
        string cmd;
        for(ll i=0;i<n;i++)
        {
            cin>>grid[i];
            for(ll j=0;j<n;j++)
            {
                if(grid[i][j]=='N'
                   ||grid[i][j]=='S'
                   ||grid[i][j]=='L'
                   ||grid[i][j]=='O')
                {
                    dir=grid[i][j];
                    ix=i;
                    iy=j;
                }
            }
        }
        cin>>cmd;

        for(ll i=0;i<cmd.size();i++)
        {
            if(cmd[i]=='F')
            {
                int tempx,tempy;
                tempx=ix;
                tempy=iy;
                if(dir=='N') tempx=ix-1;
                else if(dir=='L') tempy=iy+1;
                else if(dir=='S') tempx=ix+1;
                else if(dir=='O') tempy=iy-1;
                if(tempx>=0&&tempy>=0&&tempx<n&&tempy<m)
                {

                    if(grid[tempx][tempy]!='#')
                    {
                        if(grid[tempx][tempy]=='*')
                        {
                            res++;
                            grid[tempx][tempy]='@';
                        }
                        ix=tempx, iy=tempy;
                    }
                }
            }

            else if(cmd[i]=='D')
            {
                if(dir=='N') dir='L';
                else if(dir=='L') dir='S';
                else if(dir=='S') dir='O';
                else if(dir=='O') dir='N';
            }

            else if(cmd[i]=='E')
            {
                if(dir=='L') dir='N';
                else if(dir=='S') dir='L';
                else if(dir=='O') dir='S';
                else if(dir=='N') dir='O';
            }
        }
        cout<<res<<endl;
    }
}
