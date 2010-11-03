CC = gcc
CFLAG = -g -Wextra -Wall -Wshadow -Werror -pedantic -std=c99 -c 
OFLAG = -o
OBJS = EXECUTE.o ARGV.o POLASH.o main.o
DISTC = FILE.c POLAI.c ACCESS.c CONTINU.c WRAP.c main.c POLASH.c ARGV.c EXECUTE.c
DISTH = FILE.h POLAI.h ACCESS.h CONTINU.h WRAP.h POLASH.h ARGV.h EXECUTE.h

all : header libCreate POLALIB exeCreate pola Oclean execMess

POLALIB:
	gcc -c -fPIC FILE.c
	gcc -c -fPIC POLAI.c
	gcc -c -fPIC ACCESS.c
	gcc -c -fPIC CONTINU.c
	gcc -c -fPIC WRAP.c
	gcc -shared -Wl -ldl -o POLALIB.so WRAP.o CONTINU.o ACCESS.o POLAI.o FILE.o
	export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

pola : $(OBJS)
	$(CC) $(OFLAG) pola $(OBJS)
main.o : main.c POLASH.h
	$(CC) $(CFLAG) $<
POLASH.o : POLASH.c ARGV.h
	$(CC) $(CFLAG) $<
ARGV.o : ARGV.c EXECUTE.h
	$(CC) $(CFLAG) $<
EXECUTE.o : EXECUTE.c
	$(CC) $(CFLAG) $<

clean:
	rm pola POLALIB.so

Oclean: 
	rm *.o

dist:
	tar zcvf OBERLE-Stephane-POLA.tar.gz $(DISTC) $(DISTH) makefile

info:   header
	@echo "\t\tOBERLE Stephane\t\t\t    L3S5 informatique"
	@echo "\t\t\t\t\t     Universite de Strasbourg"
	@echo ""


header:
	@echo ""
	@echo "\t\t====================================================="
	@echo "\t\t#### #### ####    # #### #####    #### #### #    ####"
	@echo "\t\t#  # #  # #  #    # #      #      #  # #  # #    #  #"
	@echo "\t\t#### #### #  #    # ###    #      #### #  # #    ####"
	@echo "\t\t#    # #  #  # #  # #      #      #    #  # #    #  #" 
	@echo "\t\t#    #  # #### #### ####   #      #    #### #### #  #"
	@echo "\t\t====================================================="

libCreate:
	@echo ""
	@echo "-----------------------------------------------------------------------------------------------"
	@echo "\t\t>> Creation de la libraire POLALIB"
	@echo "-----------------------------------------------------------------------------------------------"

exeCreate: 
	@echo "- Librairie creee"
	@echo ""
	@echo "-----------------------------------------------------------------------------------------------"
	@echo "\t\t>> Creation de l'executable"
	@echo "-----------------------------------------------------------------------------------------------"

execMess: 
	@echo "- Executable cree"
	@echo ""
	@echo "-----------------------------------------------------------------------------------------------"
	@echo "\t\tCommande pour executer le programme :"
	@echo "\t\t\t./pola"
	@echo "-----------------------------------------------------------------------------------------------"