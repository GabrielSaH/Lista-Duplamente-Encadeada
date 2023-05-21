
#include "list.hpp"


//	Builder

list::list() :
	prime(nullptr)
{

};


// Funçoes membros

void list::insere(int info) {
	if (prime == nullptr) {
		prime = new noLista(info);
	}

	else {
		prime->setAnt(new noLista(info));
		prime->getAnt()->setProx(prime);
		prime = prime->getAnt();

	}


}

void list::insereFim(int info) {
	if (prime == nullptr) {
		prime = new noLista(info);
	}

	else {
		noLista* ponteiro = prime;


		while (ponteiro->getProx() != nullptr) {
			ponteiro = ponteiro->getProx();
		}

		ponteiro->setProx(new noLista(info));
		ponteiro->getProx()->setAnt(ponteiro);

	};

}

void list::retira(int alvo) {
	if (prime == nullptr) return;

	noLista* ponteiro = prime;
	
	if (prime->getInfo() == alvo) {
		prime = prime->getProx();
		delete ponteiro;
		return;
	}

	while (ponteiro->getProx() != nullptr && ponteiro->getInfo() != alvo) {
		ponteiro = ponteiro->getProx();
	};

	if (ponteiro->getInfo() == alvo) {
		
		if (ponteiro->getProx() != nullptr) {
			ponteiro->getAnt()->setProx(ponteiro->getProx());
			ponteiro->getProx()->setAnt(ponteiro->getAnt());
		}
		else {
			ponteiro->getAnt()->setProx(nullptr);
		}
		delete ponteiro;
	}

}

void list::libera() {

	if (prime == nullptr) return;

	if (prime->getProx() == nullptr) {
		delete prime;
		return;
	}

	noLista* ponteiro1 = prime;
	noLista* ponteiro2 = prime->getProx();

	while (ponteiro2->getProx() != nullptr) {

		delete ponteiro1;
		ponteiro1 = ponteiro2;
		ponteiro2 = ponteiro2->getProx();


	}

	delete ponteiro1;
	delete ponteiro2;

	prime = nullptr;

}



bool list::vazia() {
	if (prime == nullptr) return true;
	
	else return false;
	
}

bool list::igual(list alvo) {

	noLista* lista1Ponteiro = prime;
	noLista* lista2Ponteiro = alvo.prime;

	if (lista1Ponteiro == nullptr && lista2Ponteiro == nullptr) return true;

	if (lista1Ponteiro == nullptr || lista2Ponteiro == nullptr) return false;

	while (lista1Ponteiro->getProx() != nullptr && lista2Ponteiro->getProx() != nullptr) {
		if (lista1Ponteiro->getInfo() != lista2Ponteiro->getInfo()) {
			return false;
		};

		lista1Ponteiro = lista1Ponteiro->getProx();
		lista2Ponteiro = lista2Ponteiro->getProx();
	}

	if (lista1Ponteiro->getProx() != nullptr or lista2Ponteiro->getProx() != nullptr) return false;

	return true;



}



int list::comprimento() {
	if (prime == nullptr) return 0;

	int contador = 1;
	noLista* ponteiro = prime;

	while (ponteiro->getProx() != nullptr) {
		contador++;
		ponteiro = ponteiro->getProx();
	}

	return contador;
}


noLista* list::busca(int alvo) {
	noLista* ponteiro = prime;

	while (ponteiro != nullptr) {
		if (ponteiro->getInfo() == alvo) {
			return ponteiro;
		};

		ponteiro = ponteiro->getProx();

	};

	return nullptr;
}

noLista* list::ultimo() {
	if (vazia()) return nullptr;

	noLista* ponteiro = prime;

	while (ponteiro->getProx() != nullptr) {
		ponteiro = ponteiro->getProx();
	}

	return ponteiro;

}

noLista* list::getPrime() {
	return prime;
}

list list::merge(list& alvo) {
	list resultado = list();

	noLista* ponteiroL1 = prime;
	noLista* ponteiroL2 = alvo.getPrime();

	while (ponteiroL1 != nullptr || ponteiroL2 != nullptr) {
		
		if (ponteiroL1 != nullptr) {
			resultado.insereFim(ponteiroL1->getInfo());
			ponteiroL1 = ponteiroL1->getProx();
		};

		if (ponteiroL2 != nullptr) {
			resultado.insereFim(ponteiroL2->getInfo());
			ponteiroL2 = ponteiroL2->getProx();
		}
	}

	return resultado;
}

// Funcoes amigas

std::ostream& operator<<(std::ostream& os, const list list) {

	if (list.prime == nullptr) {
		os << "[]";

		return os;
	}


	noLista* ponteiro = list.prime;

	os << "[";

	if (ponteiro != nullptr) {
		os << ponteiro->getInfo();
		ponteiro = ponteiro->getProx();
	}

	while (ponteiro != nullptr) {
		os << ", " << ponteiro->getInfo();

		ponteiro = ponteiro->getProx();
	};

	os << "]";

	return os;

}

std::ostream& operator<<(std::ostream& os, const list* list) {

	if (list->prime == nullptr) {
		os << "[]";

		return os;
	}


	noLista* ponteiro = list->prime;

	os << "[";

	if (ponteiro != nullptr) {
		os << ponteiro->getInfo();
		ponteiro = ponteiro->getProx();
	}

	while (ponteiro != nullptr) {
		os << ", " << ponteiro->getInfo();

		ponteiro = ponteiro->getProx();
	};

	os << "]";

	return os;

}
