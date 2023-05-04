#include <iostream>

#ifndef BITS
#define BITS

using namespace std;

class Bits{
	private:
	bool bits[8];
	public:
	Bits(); //construtor
	~Bits();//destrutor
	friend Bits operator& (Bits,Bits); //Conjunção Binária
	friend Bits operator^ (Bits,Bits); //Disjunção exclusiva Binária
	friend Bits operator| (Bits,Bits); //Disjunção Binária
	friend Bits operator~ (Bits); //Negação
	friend Bits operator> (Bits,int); //Deslizamento Binário para a Direita
	friend Bits operator< (Bits,int); //Deslizamento Binário para a Esquerda
	void strbin(char); //transforma uma string em binário
	void strbits(string); //transforma uma string binária no tipo Bits 
	char binstr(); //transforma um string em binário
	friend ostream& operator<<(ostream& os, const Bits& a);
};
	
#endif
	
	
