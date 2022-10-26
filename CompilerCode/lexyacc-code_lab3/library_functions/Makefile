SRCDIR=src
OBJDIR=object
LIBDIR=lib

LIBTEST=test
LIBFACT=fact
LIBLNTWO=lntwo
LIBGCD=gcd

LIBS=-l$(LIBTEST) -l$(LIBFACT) -l$(LIBLNTWO)

all: libShared

test:
	gcc -Wall -L./lib $(LIBS) $(LIBTEST).cpp -lstdc++ -o $(LIBTEST).out

libShared: sharedTest sharedFact sharedLntwo sharedGcd

objectTest:
	gcc -Wall -fPIC -c $(SRCDIR)/add_one.s -o $(OBJDIR)/add_one.o
objectFact:
	gcc -Wall -fPIC -c $(SRCDIR)/$(LIBFACT).s -o $(OBJDIR)/$(LIBFACT).o
objectLntwo:
	gcc -Wall -fPIC -c $(SRCDIR)/$(LIBLNTWO).s -o $(OBJDIR)/$(LIBLNTWO).o
objectGcd:
	gcc -Wall -fPIC -c $(SRCDIR)/$(LIBGCD).s -o $(OBJDIR)/$(LIBGCD).o

sharedTest: objectTest
	gcc -shared -Wl,-soname,lib$(LIBTEST).so -o $(LIBDIR)/lib$(LIBTEST).so $(OBJDIR)/add_one.o
sharedFact: objectFact
	gcc -shared -Wl,-soname,lib$(LIBFACT).so -o $(LIBDIR)/lib$(LIBFACT).so $(OBJDIR)/$(LIBFACT).o
sharedLntwo: objectLntwo
	gcc -shared -Wl,-soname,lib$(LIBLNTWO).so -o $(LIBDIR)/lib$(LIBLNTWO).so $(OBJDIR)/$(LIBLNTWO).o
sharedGcd: objectGcd
	gcc -shared -Wl,-soname,lib$(LIBGCD).so -o $(LIBDIR)/lib$(LIBGCD).so $(OBJDIR)/$(LIBGCD).o

clean:
	rm -f $(OBJDIR)/*.o $(LIBDIR)/*.so
