#include "noLista.hpp"
#include <iostream>


//Builders
noLista::noLista(int info) :
	info(info),
	prox(nullptr),
	ant(nullptr)
	
{

}


// Setters

void noLista::setInfo(int Ninfo) {
	info = Ninfo;
};


void noLista::setProx(noLista* Nprox) {
	if (Nprox == nullptr) this->prox = nullptr;
	this->prox = Nprox;
};

void noLista::setAnt(noLista* ant) {
	this->ant = ant;
};

// Getters

int noLista::getInfo() {
	return info;
};

noLista* noLista::getAnt() {
	if (ant == nullptr) return nullptr;

	return ant;
};

noLista *noLista::getProx() {
	if (prox == nullptr) return nullptr;
	
	return prox;
};
