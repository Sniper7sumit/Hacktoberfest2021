// Diameter of binary tree is the longest path between two nodes


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node{
    int data;
    struct node*left;
    struct node*right;
// constructor
    node(int val){
        data=val;
        left=right=NULL;
    }
};

//optimized approach
int findia(struct node*root, int *height){
    int lh=-1, rh=-1;
    int ld=0,rd=0;
    if(root==NULL){
        *height=-1;
        return 0;

    }
     ld=findia(root->left, &lh);
     rd=findia(root->right, &rh);
     *height=max(lh,rh)+1;
      return max(max(ld,rd), lh+rh+2);

}

int main() 
{
struct node*root= new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right= new node(5);
 int height=-1;
 int ans=findia2(root,&height);
 cout<<ans<<"\n";


return 0;
}

// Time complexity---O(n) where n is no of nodes in binary tree.
