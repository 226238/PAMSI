#include <cstdlib>
#include <iostream>
#include <ctime>
#include "tree.hh"
#include "measure.hh"

using namespace std;

void tree::add(tree * T, int ile_wezlow)
{
	srand(time(NULL));

 	leaf *x;

	cout << "Liczba wezlow drzewa: " << T -> count << endl << endl;

	for(int i = 0 ; i < ile_wezlow ; i++)
	{
		x = new leaf;
		x -> data = rand()%100000 + 1;
		T -> insert(x);      
	}
  
	cout << endl;
	cout << "Liczba wezlow drzewa: " << T -> count << endl << endl;      
}

bool tree::insert(leaf * n)
{
	leaf * x = root;
	leaf * y = root;
	leaf * z = root;

	y = n -> left = n -> right = NULL;
	n -> balance = 0;

	while(x)
	{
		if(x -> data == n -> data)
    	{
    		delete n;
    		return false;
    	}

		y = x;
		x = (n -> data < x -> data) ? x -> left : x -> right;
	}
  
	count++;
  
	if(!(n -> up = y))
	{
		root = n;
		return true;
	}

	if(n -> data < y -> data) 
	{
		y -> left = n; 
	}

	else y -> right = n;
	
	if(y -> balance)
	{
		y -> balance = 0;
		return true;
	}

	y -> balance = (y -> left == n) ? 1 : -1;
	z = y -> up;

	while(z)
	{
		if(z -> balance) 
		{
			break;
		}

		z -> balance = (z -> left == y) ? 1 : -1;
		y = z; z = z -> up;
	}

	if(!z) 
	{
		return true;
	}

	if(z -> balance == 1)
	{
		if(z -> right == y)
		{
			z -> balance = 0;
			return true;
		}

		if(y -> balance == -1) 
		{	
			rotation_LR(z); 
		}
		else 
		{
			rotation_LL(z);
    	}

    	return true;
  	}

	else
	{
		if(z -> left == y)
		{
			z -> balance = 0;
			return true;
		}

		if(y -> balance == 1) 
		{
			rotation_RL(z); 
		}

		else 
		{
			rotation_RR(z);
		}

		return true;
	}
}

leaf *tree::rotation_RR(leaf *A)
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
		root = B;
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

leaf *tree::rotation_LL(leaf *A)
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
		root = B;
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

leaf *tree::rotation_RL(leaf *A)
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
		root = C;
	}

	A -> balance = (C -> balance == -1) ? 1 : 0;
	B -> balance = (C -> balance == 1) ? -1 : 0;

	return C;
}

leaf *tree::rotation_LR(leaf *A)
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
		root = C;
	}

	A -> balance = (C -> balance == 1) ? -1 : 0;
	B -> balance = (C -> balance == -1) ? 1 : 0;

	return C;
}


int tree::find_min(leaf * x)
{
	while(x -> left) x = x -> left;

	return x -> data;  
}

void tree::run()
{
	srand(time(NULL));
	tree *T = new tree();
	measure m;

	int ile;

	cout << "Ile danych wprowadzic ?";
	cin >> ile;

	add(T,ile);

	cout << "search min " << find_min(T -> root) << endl;
}