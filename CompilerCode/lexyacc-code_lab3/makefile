SRCDIR=./library_functions/src
OBJDIR=./library_functions/object
LIBDIR=./library_functions/lib

LIBTEST=test
LIBFACT=fact
LIBLNTWO=lntwo
LIBGCD=gcd

COMPILER=y.tab.o lex.yy.o calc3i.c -o calc3i.exe

LIBS=-l$(LIBTEST) -l$(LIBFACT)

all: libShared main

main:
	bison -y -d calc3.y
	flex calc3.l
	gcc -c y.tab.c lex.yy.c
	gcc y.tab.o lex.yy.o calc3i.c -o calc3i.exe

libShared: libTest libFact libLntwo libGcd

objectTest:
	gcc -Wall -c $(SRCDIR)/add_one.s -o $(OBJDIR)/add_one.o
objectFact:
	gcc -Wall -c $(SRCDIR)/$(LIBFACT).s -o $(OBJDIR)/$(LIBFACT).o
objectLntwo:
	gcc -Wall -c $(SRCDIR)/$(LIBLNTWO).s -o $(OBJDIR)/$(LIBLNTWO).o
objectGcd:
	gcc -Wall -c $(SRCDIR)/$(LIBGCD).s -o $(OBJDIR)/$(LIBGCD).o

libTest: objectTest
	ar rcs -o $(LIBDIR)/lib$(LIBTEST).a $(OBJDIR)/add_one.o
libFact: objectFact
	ar rcs -o $(LIBDIR)/lib$(LIBFACT).a $(OBJDIR)/$(LIBFACT).o
libLntwo: objectLntwo
	ar rcs -o $(LIBDIR)/lib$(LIBFACT).a $(OBJDIR)/$(LIBLNTWO).o
libGcd: objectGcd
	ar rcs -o $(LIBDIR)/lib$(LIBFACT).a $(OBJDIR)/$(LIBGCD).o

test:
	gcc -Wall -L./lib $(LIBS) $(LIBTEST).cpp -lstdc++ -o $(LIBTEST).out
clean:
	rm *.exe *.o ./library_functions/object/*.o ./library_functions/lib/* 