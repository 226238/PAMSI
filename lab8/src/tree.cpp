#include <cstdlib>
#include <iostream>
#include <ctime>
#include "tree.hh"

using namespace std;

void tree::guard(leaf *start)
{
	//if(start -> balance == -1) rotation_RL(root, start);
	if (start -> balance == -2) rotation_RR(root, start);
	//if(start -> balance == 1) rotation_LR(root, start);
	if (start -> balance == 2) rotation_LL(root, start);

	if(start -> left != NULL)
	guard(start -> left);

	if(start -> right != NULL)
	guard(start -> right);
}

void tree::add(int n, leaf *start)
{
	if (root == NULL)
	{
		root = new leaf;
		root -> data = n;
		root -> left = NULL;
		root -> right = NULL;
		root -> up = NULL;
		root -> balance = 0;
	}

	else if(n < start -> data)
	{
		if(start -> left != NULL)
		{
			add(n,start -> left);
		}

		else
		{
			leaf *_new = new leaf;
			start -> left = _new;
			_new -> data = n;
			_new -> left = NULL;
			_new -> right = NULL;
			_new -> up = start;
			_new -> balance = 0;
			start -> balance += 1;

			if(start -> up)
			{
				if(_new == start -> left) start -> up -> balance += 1;
			}
		}
	}

	else
	{     
		if(start -> right != NULL)
		{
			add(n,start -> right);
		}    

		else
		{
			leaf *_new = new leaf;
			start -> right = _new;
			_new -> data = n;
			_new -> left = NULL;
			_new -> right = NULL;
			_new -> up = start;
			_new -> balance = 0;
			start -> balance += -1;

			if(start -> up)
			{
				if(_new == start -> right) start -> up -> balance += -1;
			}
		}
	}

	//guard(root);
}

leaf *tree::rotation_RR(leaf *start, leaf *A)
{
	leaf *B = A -> right;
	leaf *P = A -> up;

	A -> right = B -> left;
	
	if(A -> right)
	{
		A -> right -> up = A;
	}

	B -> left = A;
	B -> up = P;
	A -> up = B;

	if(P)
	{
		if(P -> left == A)
		{
			P -> left = B;
		}

		else
		{
			P -> right = B;
		}
	}

	else
	{
		start = B;
	}

	if(B -> balance == -1)
	{
		A -> balance = B -> balance = 0;
	}

	else
	{
		A -> balance = -1;
		B -> balance = 1;
	}

	return B;
}

leaf *tree::rotation_LL(leaf *start, leaf *A)
{
	leaf *B = A -> left;
	leaf *P = A -> up;

	A -> left = B -> right;
	
	if(A -> left)
	{
		A -> left -> up = A;
	}

	B -> right = A;
	B -> up = P;
	A -> up = B;

	if(P)
	{
		if(P -> left == A)
		{
			P -> left = B;
		}

		else
		{
			P -> right = B;
		}
	}

	else
	{
		start = B;
	}

	if(B -> balance == 1)
	{
		A -> balance = B -> balance = 0;
	}

	else
	{
		A -> balance = 1;
		B -> balance = -1;
	}

	return B;
}

leaf *tree::rotation_RL(leaf *start, leaf *A)
{
	leaf *B = A -> right;
	leaf *C = B -> left;
	leaf *P = A -> up;

	B -> left = C -> right;

	if(B -> left)
	{
		B -> left -> up = B;
	}

	A -> right = C -> left;

	if(A -> right)
	{
		A -> right -> up = A;
	}

	C -> left = A;
	C -> right = B;
	A -> up = B -> up = C;
	C -> up = P;

	if(P)
	{
		if(P -> left == A)
		{
			P -> left = C;
		}

		else
		{
			P -> right = C;
		}
	}

	else
	{
		start = C;
	}

	A -> balance = (C -> balance == -1) ? 1 : 0;
	B -> balance = (C -> balance == 1) ? -1 : 0;

	return C;
}

leaf *tree::rotation_LR(leaf *start, leaf *A)
{
	leaf *B = A -> left;
	leaf *C = B -> right;
	leaf *P = A -> up;

	B -> right = C -> left;

	if(B -> right)
	{
		B -> right -> up = B;
	}

	A -> left = C -> right;

	if(A -> left)
	{
		A -> left -> up = A;
	}

	C -> right = A;
	C -> left = B;
	A -> up = B -> up = C;
	C -> up = P;

	if(P)
	{
		if(P -> left == A)
		{
			P -> left = C;
		}

		else
		{
			P -> right = C;
		}
	}

	else
	{
		start = C;
	}

	A -> balance = (C -> balance == 1) ? -1 : 0;
	B -> balance = (C -> balance == -1) ? 1 : 0;

	return C;
}


void tree::in_order_tree_walk(leaf *start)
{
	if(start -> left != NULL)
	in_order_tree_walk(start -> left);
 
	cout << start -> data;

 
	if(start -> right != NULL)
	in_order_tree_walk(start -> right);
}

void tree::run()
{
	int q,ile;
	cout << "ile";
	cin >> ile;

	for(int i=0;i<ile;i++)
	{
		cin >> q;
		add(q,root);
		cout << "root balance " << root -> balance << endl;
	}

	cout << "root balance " << root -> balance << endl;

	//in_order_tree_walk(root);
}