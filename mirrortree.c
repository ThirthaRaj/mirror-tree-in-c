#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct node *root=NULL;
struct node *create(struct node *root,int );
void inorder(struct node *root);
void mirror(struct node *root);

main()
{
	int key,choice;
	while(1)
	{
		printf("\nENTER\n1.to create\n2.inorder display\n3.mirror image\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nenter the key to create\n");
				scanf("%d",&key);
				root=create(root,key);
				break;
			case 2:
				inorder(root);
			    break;
			case 3:
				mirror(root);
				inorder(root);
				break;
			default:
				printf("\nInvalid choice\n");
				
		}
	}
}

struct node *create(struct node *root,int key)
{
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=key;
		root->left=root->right=NULL;
		return root; 
	}
	
	if(key<root->data)
	  root->left=create(root->left,key);
	else if(key>root->data)
	  root->right=create(root->right,key);
	else
	  printf("\nduplicate nodes not allowed\n");
	  
	  return root;
}

void inorder(struct node *root)
{
	if(root==NULL)
	  return;
	  
	inorder(root->left);
	  printf("%d\t",root->data);
	inorder(root->right);
}

void mirror(struct node *root)
{
	struct node *temp;
	if(root==NULL)
	 return;
	 
	 mirror(root->left);
	 mirror(root->right);
	 temp=root->left;
	 root->left=root->right;
	 root->right=temp;
	 //mirror(root->right);
	 
}
