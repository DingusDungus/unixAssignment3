SRCDIR=./library_functions/src
OBJDIR=./library_functions/object
LIBDIR=./library_functions/lib

LIBTEST=test
LIBFACT=fact
LIBLNTWO=lntwo
LIBGCD=gcd

COMPILER=y.tab.o lex.yy.o calc3i.c -o calc3i.exe

LIBS=-l$(LIBTEST) -l$(LIBFACT)

all: lib main

main:
	bison -y -d calc3.y
	flex calc3.l
	gcc -c y.tab.c lex.yy.c
	gcc y.tab.o lex.yy.o calc3i.c -o calc3i.exe

objectFact:
	gcc -Wall -c $(SRCDIR)/$(LIBFACT).s -o $(OBJDIR)/$(LIBFACT).o
objectLntwo:
	gcc -Wall -c $(SRCDIR)/$(LIBLNTWO).s -o $(OBJDIR)/$(LIBLNTWO).o
objectGcd:
	gcc -Wall -c $(SRCDIR)/$(LIBGCD).s -o $(OBJDIR)/$(LIBGCD).o

lib: objectFact objectLntwo objectGcd
	ar rcs -o $(LIBDIR)/calc_lib.a $(OBJDIR)/$(LIBFACT).o $(OBJDIR)/$(LIBLNTWO).o $(OBJDIR)/$(LIBGCD).o

test:
	gcc -Wall -L./lib $(LIBS) $(LIBTEST).cpp -lstdc++ -o $(LIBTEST).out
clean:
	rm *.exe *.o ./library_functions/object/*.o ./library_functions/lib/* *.s 