#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<fstream>

struct node
{
	int info;
	struct node *left,*right,*pnt;
};
typedef struct node NODE;
NODE *root=NULL;
NODE *loc, *par;
NODE *stack[1000];

int height(NODE *ptr)
{
	if(ptr==NULL)
        return 0;
	int ldepth=height(ptr->left);
	int rdepth=height(ptr->right);
	if(ldepth>rdepth)
        return (ldepth+1);
	else return (rdepth+1);
}

void find(int x)
{
	NODE *ptr=root, *save=NULL;
	while(ptr!=NULL)
	{
		if(x>ptr->info)
		{
			save=ptr;
			ptr=ptr->right;
		}
		else if(x<ptr->info)
		{
			save=ptr;
			ptr=ptr->left;
		}
		else
		{
			par=save;
			loc=ptr;
			return;
		}
	}
	loc=NULL;
	par=save;
}
void ll(NODE *j, NODE *child)
{
	if(j->pnt==NULL)
        root=child;
	NODE *temp=child->right;
	child->pnt=j->pnt;
	if(j->pnt!=NULL)
	{
		if(j->pnt->left==j)
		{
			j->pnt->left=child;
		}
		else j->pnt->right=child;
	}
	j->pnt=child;
	child->right=j;
	j->left=temp;
	if(temp!=NULL)
        temp->pnt=j;
}
void rr(NODE *j, NODE *child)
{
	if(j->pnt==NULL)
        root=child;
	NODE *temp=child->left;
	child->pnt=j->pnt;
	if(j->pnt!=NULL)
	{
		if(j->pnt->left==j)
            j->pnt->left=child;
		else j->pnt->right=child;
	}
	j->pnt=child;
	child->left=j;
	j->right=temp;
	if(temp!=NULL)
        temp->pnt=j;
}
void lr(NODE *j, NODE *child, NODE *gndchild)
{
	rr(child, gndchild);
	ll(j, gndchild);
}
void rl(NODE *j, NODE *child, NODE *gndchild)
{
	ll(child, gndchild);
	rr(j, gndchild);
}
int bfactor(NODE *j, NODE *child, NODE *gndchild)
{
	int l=height(j->left);
	int r=height(j->right);
	int diff=l-r;
	if(diff>-1 && diff<1)
        return 0;
	if(diff>1)
	{
		if(gndchild==child->left)
            ll(j, child);
		else lr(j, child, gndchild);
	}
	if(diff<-1)
    {
        if(gndchild==child->right)
            rr(j,child);
        else rl(j, child, gndchild);
    }
    return 1;
}
void insert(int x)
{
	find(x);
	if(loc!=NULL)
	{
		printf("Already inserted\n");
		return;
	}
	
	NODE *ptr=(NODE *)(malloc(sizeof(NODE)));
	ptr->info=x;
	ptr->left=NULL;
	ptr->right=NULL;
	if(par==NULL)
	{
		root=ptr;
		ptr->pnt=NULL;
	}
	else
	{
		if(x>par->info)
		{
			par->right=ptr;
			ptr->pnt=par;
		}
		else
		{
			par->left=ptr;
			ptr->pnt=par;
		}
	}
	NODE *j=ptr->pnt;
	NODE *child=ptr;
	NODE *gndchild=NULL;
	while(j!=NULL)
	{
		int k=bfactor(j,child,gndchild);
		if(k==1)
            break;
		gndchild=child;
		child=j;
		j=j->pnt;
	}
}
void casea()
{
	NODE *child;
	if(loc->left==NULL && loc->right==NULL)
        child=NULL;
	else if(loc->left!=NULL)
        child=loc->left;
	else child=loc->right;
	if(par==NULL)
	{
		root=child;
		child->pnt=NULL;
	}
	else
	{
		if(par->left==loc)
		{
			par->left=child;
		}
		else par->right=child;
	}
	child->pnt=par;
	{
        NODE *j=loc->pnt;
        NODE *child=loc, *gndchild=NULL;
        while(j!=NULL)
        {
            int k=bfactor(j, child, gndchild);
            gndchild=child;
            child=j;
            j=j->pnt;
        }
    }
}
void caseb()
{
	NODE *suc=loc->right;
	NODE *parsuc=loc;
	while(suc->left!=NULL)
	{
		parsuc=suc;
		suc=suc->left;
	}
	NODE *par1=par;
	NODE *loc1=loc;
	par=parsuc;
	loc=suc;
	casea();
	if(par1==NULL)
        root=suc;
	else
	{
		if(par1->left==loc1)
		{
			par1->left=suc;
		}
		else par1->right=suc;
	}
	suc->left=loc1->left;
	suc->right=loc1->right;
	suc->pnt=par1;
}
void del(int x)
{
	find(x);
	if(loc==NULL)
	{
		printf("Not found\n");
		return;
	}
	if(loc->left!=NULL && loc->right!=NULL)
        caseb();
	else casea();
}

int findkth(int k)
{
    
}

int main()
    {
        insert(14);
        insert(10);
        insert(17);
        insert(12);
        insert(10);
        insert(11);
        insert(20);
        insert(12);
        insert(18);
        insert(25);
        insert(20);
        insert(8);
        insert(22);
        insert(11);
        insert(23);
        del(20);
        return 0;
    }

