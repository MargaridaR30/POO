#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "bits.hpp"

using namespace std;

int main() {
    // Abrir o ficheiro encriptado para leitura
    ifstream input("encriptado.txt");

    // Verificar se o arquivo foi aberto com sucesso
    if (!input.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
    
	int tamanho = 8;
	vector<int> v(tamanho);
	cout << "Digite uma permutação dos 8 elementos:"; // Pede ao utilizador a nova ordem dos elementos 
	for (int i = 0; i < tamanho; i++) {
		int valor;
		cin >> valor;
		// Verifica se o valor está dentro do intervalo válido (1 a 8)
		while (valor < 1 || valor > 8) {
			cout << "Valor inválido. Digite novamente (entre 1 e 8): ";
			cin >> valor;
		}
		v[i] = valor - 1; // Subtrai 1 para obter o índice correto do vetor
	}
    
	string linha;
    // Criar o arquivo desencriptado para escrita
    ofstream output("desencriptado.txt");
    	if (output.is_open() && input.is_open()){//se ambos os ficheiros estiverem abertos
		Bits c_binario,aux,res;
		while (getline(input,linha)){ //enquanto estiver a ler texto
			c_binario.strbits(linha);//transforma as srings de binários no tipo Bits
			res = Bits(); //reinicializa a variavél res a 0, usando para isso o construtor da class Bits
			for (int i = 0; i < 8 ; i++) { //este processo repete-se para cada uma das oito elementos do Bits
				aux = c_binario>(7-i); //fixada uma posição, "empurra" esta para a direita até à ultima posição do bits 
				aux = aux<7; //fixada uma posição, "empurra" esta para a esquerda até à primeira posição do bits
				aux = aux>v[i]; //"empurra" a posição fixada até à sua posição original
				res = res|aux; //faz a disjunção da variavel aux (calculada anteriormente) com a variavel res
		}
		output << res.binstr(); //escreve em ficheiro os caracteres
		}
		output.close(); //fecho do ficheiro
		input.close(); //fecho do ficheiro encriptado
	}
	else { //caso contrário escreve no ecrã "Não foi possível abrir os ficheiros"
		cout << "Não foi possível abrir os ficheiros" << endl;
	}
	    cout << "Texto desencriptado gravado em desencriptado.txt" << endl;
    return 0;
}
