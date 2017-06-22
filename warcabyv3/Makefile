CPPFLAGS= -c -g -Iinc -std=c++11

__start__: Warcaby
	./Warcaby

Warcaby: obj/main.o obj/warcaby.o
	g++ -o Warcaby obj/main.o obj/warcaby.o

obj/main.o: src/main.cpp inc/warcaby.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/warcaby.o: src/warcaby.cpp inc/warcaby.hh
	g++ ${CPPFLAGS} -o obj/warcaby.o src/warcaby.cpp

clean:
	rm -f obj/*.o Warcaby

