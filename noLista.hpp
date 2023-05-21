#pragma once



class noLista {
private:
	int info;
	noLista *prox;
	noLista *ant;


public:
	// Builders
	noLista(int info);
	
	// Setters
	
	void setInfo(int Ninfo);
	void setProx(noLista* Nprox);
	void setAnt(noLista* ant);


	// Getters
	int getInfo();
	noLista *getProx();
	noLista* getAnt();

};