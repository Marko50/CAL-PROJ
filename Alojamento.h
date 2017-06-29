#ifndef ALOJAMENTO_H_
#define ALOJAMENTO_H_

#include <algorithm>
#include <stdlib.h>
#include <string>
#include <climits>
#include "Quarto.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Alojamento {
	string nome;
	vector<Quarto*> quartos;
	int estrelas;
	bool cheio;
public:
	/**
	 * @brief Cria um alojamento
	 * @param nome - Nome da agencia
	 * @param quartos_piso - Nr de quartos por cada piso
	 * @param nr_pisos - Nr de pisos
	 * @param preco - Preco base do alojamento
	 * @param estrelas - Nr de estrelas que tem
	 */
	Alojamento(string nome, int quartos_piso, int nr_pisos, int preco,
			int estrelas);

	/**
	 * @brief
	 * @return a capacidade livre do alojamento
	 */
	int getCapacidadeLivre();

	/**
	 * @brief
	 * @return a capacidade maxima por quarto do alojamento
	 */
	int getCapacidadeMaxima();

	/**
	 * @brief
	 * @return o preco minimo que um quarto tem
	 */
	double precoMinimo();

	/**
	 * @brief
	 * @param nr_Pessoas - Nr de pessoas que vao ocupar quarto(s)
	 * @return retorna um vetor com os quartos ocupados
	 */
	vector<Quarto*> preencheQuarto(int nr_Pessoas);

	/**
	 * @brief
	 * @return retorna nome do alojamento
	 */
	string getNome() const;

	/**
	 * @brief
	 * @return retorna estrelas do alojamento
	 */
	int getEstrelas() const;

	/**
	 * @brief
	 * @return retorna quartos do alojamento
	 */
	vector<Quarto*> getQuartos() const;

	/*
	 * @brief overload ao operador ==
	 * @param a2 - alojamento a comparar
	 * @return retorna se e igual ou nao
	 */
	bool operator ==(Alojamento a2);
	/*
	 * @brief overload ao operador <
	 * @param a2 - alojamento a comparar
	 * @return retorna se e menor ou nao
	 */
	bool operator <(Alojamento a2);

	/**
	 * @brief Mostra todos os quartos do alojamento
	 */
	void mostrarQuartos();

	friend ostream & operator <<(ostream &os, const Alojamento &v);
};

class AlojamentoCheio {
public:

	void AlojamentoCheioInc(int &i, int test) {
		i++;
		test = -1;
	}

};

#endif /* ALOJAMENTO_H_ */
