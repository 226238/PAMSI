#ifndef ISTACK_HH
#define ISTACK_HH

/*
	interfejs istack
*/

class istack{
public:
	virtual void push() = 0;
	virtual void pop() = 0;
	virtual void size() = 0;
	virtual void wykonaj_algorytm() = 0;
};

#endif