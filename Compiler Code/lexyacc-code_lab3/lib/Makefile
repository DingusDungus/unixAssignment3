all: libShared

objectFile:
	gcc -Wall -fPIC -c src/add_one.s -o object/add_one.o

libShared: objectFile
	gcc -shared -Wl,-soname,libTest.so -o libTest.so object/add_one.o

clean:
	rm -f object/*.o *.so
