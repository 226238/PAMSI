#ifndef ILIST_HH
#define ILIST_HH

/*
	interfejs ilist
*/

class ilist{
public:
	virtual void add() = 0;
	virtual void remove() = 0;
	virtual void size() = 0;
	virtual void find() = 0;
};

#endif