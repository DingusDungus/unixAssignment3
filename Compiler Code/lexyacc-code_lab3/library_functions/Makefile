SRCDIR=src
OBJDIR=object
LIBDIR=lib

LIBTEST=test
LIBFACT=fact
LIBLNTWO=lntwo
LIBGCD=gcd


all: libShared

run:
	LD_LIBRARY_PATH=$(PWD)/lib ./test

objectTest:
	gcc -Wall -fPIC -c $(SRCDIR)/add_one.s -o $(OBJDIR)/add_one.o
objectFact:
	gcc -Wall -fPIC -c $(SRCDIR)/$(LIBFACT).s -o $(OBJDIR)/$(LIBFACT).o
objectLntwo:
	gcc -Wall -fPIC -c $(SRCDIR)/$(LIBLNTWO).s -o $(OBJDIR)/$(LIBLNTWO).o
objectGcd:
	gcc -Wall -fPIC -c $(SRCDIR)/$(LIBGCD).s -o $(OBJDIR)/$(LIBGCD).o

sharedTest: objectTest
	gcc -shared -Wl,-soname,libtest.so -o $(LIBDIR)/libtest.so $(OBJDIR)/add_one.o
sharedFact: objectFact
	gcc -shared -Wl,-soname,libtest.so -o $(LIBDIR)/libtest.so $(OBJDIR)/add_one.o
sharedLntwo: objectLntwo
	gcc -shared -Wl,-soname,libtest.so -o $(LIBDIR)/libtest.so $(OBJDIR)/add_one.o
sharedGcd: objectGcd
	gcc -shared -Wl,-soname,libtest.so -o $(LIBDIR)/libtest.so $(OBJDIR)/add_one.o

test: sharedTest
	gcc -Wall -L./lib -l$(LIBTEST) $(LIBTEST).cpp -lstdc++ -o $(LIBTEST).out
fact: sharedFact
	gcc -Wall -L./lib -l$(LIBFACT) $(LIBFACT).cpp -lstdc++ -o $(LIBFACT).out
lntwo: sharedLntwo
	gcc -Wall -L./lib -l$(LIBLNTWO) $(LIBLNTWO).cpp -lstdc++ -o $(LIBLNTWO).out
gcd: sharedGcd
	gcc -Wall -L./lib -l$(LIBGCD) $(LIBGCD).cpp -lstdc++ -o $(LIBGCD).out

clean:
	rm -f $(OBJDIR)/*.o $(LIBDIR)/*.so
