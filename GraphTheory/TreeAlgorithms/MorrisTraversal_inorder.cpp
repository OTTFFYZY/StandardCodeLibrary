#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int val=0,TreeNode *left=NULL, TreeNode *right=NULL)
	    :val(val),left(left),right(right){}
}

void morris(TreeNode *root)
{
	TreeNode *cur=root,*pre;
	while(cur!=NULL)
	{
		if(cur->left==NULL)
		{
			cout<<(cur->val)<<" ";
			cur=cur->right;
			continue;
		}
		pre=cur->left;
		while(pre->right!=NULL && pre->right!=cur)
			pre=pre->right;
		if(pre->right==NULL)
		{
			pre->right=cur;
			cur=cur->left;
		}
		else
		{
			cout<<(cur->val)<<" ";
			pre->right=NULL;
			cur=cur->right;
		}
	}
}

int main()
{
	return 0;
}