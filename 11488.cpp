#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

ll res;

class node
{
public:
    ll out_degree;
    node* next[2];
    node()
    {
        out_degree=0;
        for(ll i=0;i<2;i++)
            next[i]=NULL;
    }
};

node *root;

void Insert(string s)
{
    node* curr=root;
    for(ll i=0;i<s.size();i++)
    {
        ll id=s[i]-'0';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
        ++curr->out_degree;
        res=max(res,curr->out_degree*(i+1));
    }
}

void del(node* curr)
{
    for(ll i=0;i<2;i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main()
{
    ll t;
    cin>>t;
    for(ll k=1;k<=t;k++)
    {
        res=0;
        root=new node();
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            Insert(s);
        }
        cout<<res<<endl;
        del(root);
    }
    return 0;
}

