#include <iostream>
using namespace std;


struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};


Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}


Node* kthSmallest(Node* root, int& k)
{
	
	if (root == NULL)
		return NULL;

	
	Node* left = kthSmallest(root->left, k);

	
	if (left != NULL)
		return left;

	k--;
	if (k == 0)
		return root;

	
	return kthSmallest(root->right, k);
}


void printKthSmallest(Node* root, int k)
{
	
	Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout<<"Element is: " << res->data;
}


int main()
{
	Node* root = NULL;
	int keys[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
	int x;
	
	for(x=0;x<=14;x++)
	{
		
		root = insert(root,keys[x]);
	}
	int k;
	cin>>k;
	printKthSmallest(root, k);
	return 0;
}

