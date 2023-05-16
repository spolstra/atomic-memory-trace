all: libannotation.a

libannotation.a: annotation.o
	ar rcs libannotation.a annotation.o

annotation.o: ../src/annotation.cpp
	g++ -c ../src/annotation.cpp

clean:
	rm -f *.a *.o
