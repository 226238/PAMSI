#ifndef TREE_HH
#define TREE_HH

#include <cstdlib>

#include "itree.hh"
#include "irunnable.hh"

using namespace std;

class leaf{

public:
	int data, balance;
	leaf *up;
	leaf *left;
	leaf *right;
};


class tree : public itree, public irunnable {//.............................

private:

	leaf *root = NULL;
	int count;
	int min;

public:

	void run();

	bool insert(leaf *n);
	void add(tree * T,int ile_wezlow);
	int find_min(leaf * x);

	leaf *rotation_RR(leaf *A);
	leaf *rotation_LL(leaf *A);
	leaf *rotation_RL(leaf *A);
	leaf *rotation_LR(leaf *A);

};//..........................................

#endif