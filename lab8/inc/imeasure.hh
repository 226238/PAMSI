#ifndef IMEASURE_HH
#define IMEASURE_HH

#include "irunnable.hh"

/*
	interfejs imeasure
*/

class imeasure{
public:
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void gauge(irunnable & test_obj) = 0;
};

#endif