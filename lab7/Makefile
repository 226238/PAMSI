#
#  To sa opcje dla kompilacji
#
CPPFLAGS = -c -g -Iinc -Wall -pedantic

benchmark.out: obj/main.o obj/irunnable.o obj/imeasure.o obj/measure.o obj/itable.o obj/table.o
	g++ -Wall -pedantic -o benchmark.out obj/main.o obj/irunnable.o obj/imeasure.o obj/measure.o obj/itable.o obj/table.o

obj/main.o: src/main.cpp inc/irunnable.hh inc/imeasure.hh inc/measure.hh inc/itable.hh inc/table.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/irunnable.o: src/irunnable.cpp inc/irunnable.hh
	g++ ${CPPFLAGS} -o obj/irunnable.o src/irunnable.cpp

obj/imeasure.o: src/imeasure.cpp inc/imeasure.hh
	g++ ${CPPFLAGS} -o obj/imeasure.o src/imeasure.cpp

obj/measure.o: src/measure.cpp inc/measure.hh
	g++ ${CPPFLAGS} -o obj/measure.o src/measure.cpp

obj/itable.o: src/itable.cpp inc/itable.hh
	g++ ${CPPFLAGS} -o obj/itable.o src/itable.cpp

obj/table.o: src/table.cpp inc/table.hh
	g++ ${CPPFLAGS} -o obj/table.o src/table.cpp

clean:
	rm -f obj/*.o benchmark.out
