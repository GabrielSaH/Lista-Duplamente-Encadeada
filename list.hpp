#pragma once

#include <iostream>

#include "noLista.hpp"


class list {
public:
	noLista* prime;


public:
	
	// Builder
	list();


	// Funçao membro
	void insere(int info);
	void insereFim(int info);
	void retira(int alvo);
	void libera();

	bool vazia();
	bool igual(list alvo);

	int comprimento();
	
	noLista* busca(int alvo);
	noLista* ultimo();
	noLista* getPrime();

	list merge(list& alvo);

	// Index



	// Cout
	friend std::ostream& operator<<(std::ostream& os, const list list);
	friend std::ostream& operator<<(std::ostream& os, const list* list);


};

