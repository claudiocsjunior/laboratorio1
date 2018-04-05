#Makefile for "jogoDoDado" C++ application (Cont.)
#Created by Claudio da Cruz Silva Junior 03/04/2018 main.o :
PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -I./include
LDFLAGS = -L./lib 
OBJS = main.o Empresa.o EmpresaConjunto.o Funcionalidades.o Funcionario.o
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp
Empresa.o:./include/Empresa.h
	$(CC) $(CPPFLAGS) -c src/Empresa.cpp
EmpresaConjunto.o:./include/EmpresaConjunto.h
	$(CC) $(CPPFLAGS) -c src/EmpresaConjunto.cpp
Funcionalidades.o:./include/Funcionalidades.h
	$(CC) $(CPPFLAGS) -c src/Funcionalidades.cpp
Funcionario.o:./include/Funcionario.h
	$(CC) $(CPPFLAGS) -c src/Funcionario.cpp	
clean:
	rm -f core $(PROG) $(OBJS) 