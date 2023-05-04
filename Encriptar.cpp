#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "bits.hpp"

using namespace std;

int main() {
    // Abrir o arquivo de texto para leitura
    ifstream file("Entrada.txt");
    if (!file.is_open()) {
        cout << "Falha ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    // Ler o conteúdo do arquivo de texto
    string texto;
    string::iterator it;
    getline(file, texto);
    file.close();

    cout << "Texto original: " << texto << endl;

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
    
    // Encriptar o texto carácter a carácter
    ofstream encriptado("encriptado.txt");
    if (encriptado.is_open()) {
    Bits c_binario,aux,res;

    for (it = texto.begin(); it != texto.end(); it++){  //enquanto existir texto no ficheiro
        c_binario.strbin(*it);
        res = Bits();
		for (int i = 0; i < 8;i++) {
			aux = c_binario>(7-v[i]);//fixada uma posição, "empurra" esta para a direita até à ultima posição do bits
			aux = aux<7;//fixada uma posição, "empurra" esta para a esquerda até à primeira posição do bits
			aux = aux>i;//"empurra" a posição fixada até à sua nova posição
			res = res|aux;//faz a disjunção da variavel aux (calculada anteriormente) com a variavel res
		}
        encriptado << res << "\n";//escreve em ficheiro os caracteres encriptado
    }
    encriptado.close();
    cout << "Texto encriptado gravado em encriptado.txt" << endl;
    } else {
        cout << "Falha ao abrir o arquivo de saída." << endl;
    }
    return 0;
}
