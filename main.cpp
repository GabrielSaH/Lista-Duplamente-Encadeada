#include <iostream>

#include "list.hpp"


void interface() {
	std::cout << "Ola, oque gostaria de testar?" << std::endl;
	std::cout << "1: void insere(int info):" << std::endl;
	std::cout << "2: void insereFim(int info):" << std::endl;
	std::cout << "3: void retira(int alvo):" << std::endl;
	std::cout << "4: void libera():" << std::endl;
	std::cout << "5: bool vazia():" << std::endl;
	std::cout << "6: bool igual(list alvo):" << std::endl;
	std::cout << "7: list merge(list& alvo): " << std::endl;
	std::cout << "8: Criar outra lista:" << std::endl;
	std::cout << "9: mudar a lista atual:" << std::endl;
	std::cout << "10: mostrar todas as listas:" << std::endl;
	std::cout << "0: Sair:" << std::endl;

}

int main() {

	int opcao = 999;

	list arrayListas[10];

	int contadorDeListas = 0;

	arrayListas[0] = list();

	list* listaAtual = &arrayListas[0];
	list* listaAux = &arrayListas[0];

	
	// Variaveis de caso
	int intAux = 0;
	char certeza = 'N';




	while (opcao != 0) {
		interface();
		std::cout << std::endl;
		std::cout << listaAtual << std::endl;
		std::cin >> opcao;


		switch (opcao) {
		case 1:

			std::cout << std::endl << "Qual valor voce gostaria de adicionar no inicio da lista: ";
			std::cin >> intAux;

			listaAtual->insere(intAux);

			break;

		case 2:
			std::cout << std::endl << "Qual valor voce gostaria de adicionar no fim da lista: ";
			std::cin >> intAux;

			listaAtual->insereFim(intAux);

			break;

		case 3:
			std::cout << std::endl << "Qual valor voce gostaria de retirar da lista: ";
			std::cin >> intAux;

			listaAtual->retira(intAux);

			break;

		case 4:
			std::cout << std::endl << std::endl << "tem certeza que quer deletar a lista? [S/N]";
			std::cin >> certeza;

			if (certeza == 'S') {
				listaAtual->libera();
			}

			break;

		case 5:
			if (listaAtual->vazia()) {
				std::cout << std::endl << "A sua lista esta vazia!!";
			}

			else {
				std::cout << std::endl << "A sua lista nao esta vazia!!";
			};
			break;

		case 6:
			if (contadorDeListas == 0) {
				std::cout << std::endl << "Voce deve criar outra lista antes!" << std::endl;
			}

			else {
				std::cout << std::endl << "Qual lista voce gostaria de comparar com a atual: ";
				std::cin >> intAux;
				
				if (intAux > contadorDeListas) {
					std::cout << std::endl << "Voce ainda nao criou essa lista.";
					break;
				}

				if (listaAtual->igual(arrayListas[intAux])) {
					std::cout << std::endl << "Suas listas sao iguais!!";
				}

				else {
					std::cout << std::endl << "Suas listas sao diferentes!!";
				}
			
				std::cout << std::endl << listaAtual;
				std::cout << std::endl << arrayListas[intAux];

			}
			break;
		
		case 7:
			if (contadorDeListas == 9) {
				std::cout << std::endl << "Sinto muito, esse sistema auxiliar suporta apenas 10 listas, opere manualmente para mais";
				break;
			}

			std::cout << "Com qual lista voce gostaria de dar o merge? [0 - " << contadorDeListas << "]: ";
			std::cin >> intAux;

			contadorDeListas++;
			arrayListas[contadorDeListas] = listaAtual->merge(arrayListas[intAux]);
			std::cout << std::endl << "Merge concluido e lista resultante armazenada na lista " << contadorDeListas
				<< " Gostaria de manipular ela agora? [S/N] : ";
			std::cin >> certeza;

			if (certeza == 'S') {
				listaAtual = &arrayListas[contadorDeListas];
			}
			
			break;

		case 8:
			if (contadorDeListas == 9) {
				std::cout << std::endl << "Sinto muito, esse sistema auxiliar suporta apenas 10 listas, opere manualmente para mais";
			}

			else {
				contadorDeListas++;
				std::cout << std::endl << "A lista de numero " << contadorDeListas << " Foi criada, gostaria de manipular ela agora? [S/N]";
				std::cin >> certeza;

				if (certeza == 'S') {
					listaAtual = &arrayListas[contadorDeListas];
				};
			}

			break;

		case 9:
			std::cout << "Qual lista voce gostaria de manipular agora? [0 - " << contadorDeListas << "] :";
			std::cin >> intAux;

			if (intAux > contadorDeListas) {
				std::cout << "Numero invalido, tente novamente" << std::endl;
				break;
			}

			listaAtual = &arrayListas[intAux];
			break;

		case 10:
			std::cout << std::endl;

			for (int i(0); i < contadorDeListas + 1; i++) {
				std::cout << i << ": " << arrayListas[i] << std::endl;
			}

			break;
		}
	
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	}

	

	return 0;
}