#ifndef MEASURE_HH
#define MEASURE_HH

#include "imeasure.hh"
#include "irunnable.hh"

#include <ctime>

/*
	klasa measure
*/

class measure : public imeasure{
public:
	void start();
	void stop();
	void gauge(irunnable & test_obj);

private:
	clock_t czas;
};

#endif