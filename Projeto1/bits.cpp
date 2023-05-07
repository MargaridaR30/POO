#include <iostream>
#include "bits.hpp"
#include <math.h>
#include <string>

using namespace std;

Bits::Bits(){
	for (int i = 0; i < 8; i++){
		bits[i] = false; //inicializa-se todas os elementos de bits a 0
	}
};

Bits::~Bits(){}

Bits operator & (Bits a, Bits b){
	Bits resultado;
	for(int i=0;i<8;i++){
		resultado.bits[i]=a.bits[i]&b.bits[i];//atribui valor 1 se ambos forem 1
	}
	return resultado;
}

Bits operator ^ (Bits a, Bits b){
	Bits resultado;
	for(int i=0;i<8;i++){
		resultado.bits[i]=a.bits[i]^b.bits[i];//atribui valor 1 se um for 0 e outro for 1
	}
	return resultado;
}

Bits operator | (Bits a, Bits b){
	Bits resultado;
	for (int i = 0; i < 8; i++) {
		resultado.bits[i] = (a.bits[i] || b.bits[i]); //atribui valor 1 se um dos dois for 1
	}
	return resultado;
}		

Bits operator~(Bits a){
    Bits resultado;
    for(int i = 0; i < 8; i++){
        resultado.bits[i] = !a.bits[i]; //atribui o valor oposto
    }
    return resultado;
}

Bits operator>(Bits a, int n){
	Bits resultado;
	n = n % 8;
	for (int i = 7 - n; i >= 0; i--){
		resultado.bits[i + n] = a.bits[i]; // atribui à posição i+n o valor da posição i
	}

	for (int i = 0; i < n; i++){
		resultado.bits[i] = false; // atribui aos espaços que resultaram da deslocação o valor 0
	}
	return resultado;
}

Bits operator<(Bits a, int n){
	Bits resultado;
	n = n % 8;
	for (int i = n; i < 8; i++){
		resultado.bits[i - n] = a.bits[i]; // atribui à posição i-n o valor da posição i
	}
	for (int i = 7; i > 7 - n; i--){
		resultado.bits[i] = false; // atribui aos espaços que resultaram da deslocação o valor 0
	}
	return resultado;
}

void Bits::strbits(string s){
	for (int i = 0; i < 8; i++){// Loop para percorrer cada caractere da string
	if (s[i] == '0') { // Se o caractere atual for '0'
        bits[i]=0;// Armazena o valor 0 em 'bits' na posição correspondente
    } else bits[i]=1;} //Armazena o valor 1 em 'bits' na posição correspondente
}

void Bits::strbin(char c){
	int n = (int)c, i = 7;	//Transforma um caracter num inteiro
	while (n > 0){
		bits[i] = (n % 2 == 1);	//se o resto da divisão for um, para o valor em i, bits[i] toma o valor de verdade
		n =n/2;	//faz a divisão de n por 2
		i--;	//decremento do índice 
	}
	for (int j = i; j >= 0; j--){
		bits[j] = false; //as posições que não ficam com nenhum valor atribuído do ciclo while, tomam o valor falso
	}
}
	
char Bits::binstr(){
	int n = 0;
	for (int i = 7; i >=0; i--){
		n = n +((int)bits[i]*pow(2,7-i)); //o booleano bits é convertido a inteiro, e cada valor multiplica pela potência de 2 elevada à posição i, a soma de todos estes valores fica guardado em sum									
	}return (char)n;//é retornado o valor de num convertido a caracter
};

ostream& operator<<(ostream& os, const Bits& a) {
    // Escrever cada bit do array bits no fluxo de saída
    for (int i = 0; i < 8; i++) {
        os << a.bits[i];}
    return os;
}
