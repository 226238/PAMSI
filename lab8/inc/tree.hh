#ifndef TREE_HH
#define TREE_HH

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
	int min;

public:

	void run();
	void add(int n, leaf *start);
	void find(leaf *start);
	void guard(leaf *start);

	leaf *rotation_RR(leaf *start, leaf *A);
	leaf *rotation_LL(leaf *start, leaf *A);
	leaf *rotation_RL(leaf *start, leaf *A);
	leaf *rotation_LR(leaf *start, leaf *A);

};//..........................................

#endif