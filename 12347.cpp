#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

class bst_node
{
public:
    ll data;
    bst_node *left,*right;
};

bst_node *root=NULL;

void preorder_insert(ll value)
{
    bst_node *ptr=new bst_node();
    ptr->data=value;
    ptr->left=NULL;
    ptr->right=NULL;

    bst_node *srt=root,*temp=root;

    if(root==NULL)
    {
        root=ptr;
        return;
    }

    while(srt!=NULL)
    {
        temp=srt;
        if(value<srt->data)
            srt=srt->left;
        else
            srt=srt->right;
    }
    if(value<temp->data)
        temp->left=ptr;
    else
        temp->right=ptr;

   return;

}

void postorder_traverse(bst_node *curr)
{
    if(curr==NULL) return;
    postorder_traverse(curr->left);
    postorder_traverse(curr->right);
    cout<<curr->data<<endl;
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll value;
    while(cin>>value)
    {
        preorder_insert(value);
    }

    postorder_traverse(root);
    return 0;
}

