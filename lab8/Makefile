#
#  To sa opcje dla kompilacji
#
CPPFLAGS = -c -g -Iinc -Wall -pedantic

benchmark.out: obj/main.o obj/irunnable.o obj/imeasure.o obj/measure.o obj/itree.o obj/tree.o
	g++ -Wall -pedantic -o benchmark.out obj/main.o obj/irunnable.o obj/imeasure.o obj/measure.o obj/itree.o obj/tree.o

obj/main.o: src/main.cpp inc/irunnable.hh inc/imeasure.hh inc/measure.hh inc/itree.hh inc/tree.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/irunnable.o: src/irunnable.cpp inc/irunnable.hh
	g++ ${CPPFLAGS} -o obj/irunnable.o src/irunnable.cpp

obj/imeasure.o: src/imeasure.cpp inc/imeasure.hh
	g++ ${CPPFLAGS} -o obj/imeasure.o src/imeasure.cpp

obj/measure.o: src/measure.cpp inc/measure.hh
	g++ ${CPPFLAGS} -o obj/measure.o src/measure.cpp

obj/itree.o: src/itree.cpp inc/itree.hh
	g++ ${CPPFLAGS} -o obj/itree.o src/itree.cpp

obj/tree.o: src/tree.cpp inc/tree.hh
	g++ ${CPPFLAGS} -o obj/tree.o src/tree.cpp

clean:
	rm -f obj/*.o benchmark.out
