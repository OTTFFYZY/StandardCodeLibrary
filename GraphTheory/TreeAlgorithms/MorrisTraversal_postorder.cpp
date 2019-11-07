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

TreeNode* reverse(TreeNode *head)
{
	TreeNode *pre=NULL,*cur=head,*nxt=head->right;
	while(true)
	{
		cur->right=pre;
		if(nxt==NULL) break;
		pre=cur;
		cur=nxt;
		nxt=nxt->right;
	}
	return cur;
}

void printRightChain(TreeNode *head)
{
	TreeNode *cur=head=reverse(head);
	while(cur!=NULL)
	{
		cout<<(cur->val)<<" ";
		cur=cur->right;
	}
	reverse(head);
}

void morris(TreeNode *root)
{
	TreeNode *dummy=new TreeNode(-1);
	dummy->left=root;
	TreeNode *cur=dummy,*pre;
	while(cur!=NULL)
	{
		if(cur->left==NULL)
		{
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
			pre->right=NULL;
			printRightChain(cur->left);
			cur=cur->right;
		}
	}
	delete dummy;
}

int main()
{

	return 0;
}