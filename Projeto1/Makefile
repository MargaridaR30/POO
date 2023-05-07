# Makefile para os programas dos apontamentos
CC     = g++
FLAGS  = -lm

.PHONY: clean all


all: Encriptar Desencriptar

clean:
	-rm *.o Encriptar Desencriptar

Encriptar: Encriptar.cpp bits.o
	${CC} -o $@ $@.cpp bits.o
	
Desencriptar: Desencriptar.cpp bits.o
	${CC} -o $@ $@.cpp bits.o
