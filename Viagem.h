#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Data.h"
#include "Cidade.h"
#include "Hora.h"

using namespace std;

#define PERCENTAGEM_EPOCA_ALTA 1.4;

class Viagem {
	vector<Quarto*> quarto;
	Alojamento* al;
	double precoViagem;
	double precoAlojaInterm;
	Data data;
	Hora hora;
	int duracao; //duracao em minutos
	Cidade* origem;
	Cidade* destino;
	int nrPessoas;

public:

	/**
	 * @brief Construtor de Viagem vazio
	 */
	Viagem();

	/**
	 * @brief Construtor de Viagem
	 * @param data - data da viagem
	 * @param hora - hora da viagem
	 * @param duracao - duracao da viagem
	 * @param orig - cidade origem da viagem
	 * @param dest - cidade destino da viagem
	 * @param n - nr de pessoas que viajam
	 * @param estrelas - estrelas do alojamento onde se ira ficar (valor pre definido de 15)
	 * @param precoAloInter - estrelas do(s) alojamento(s) onde se ficou (valor pre definido de 0)
	 */
	Viagem(Data data, Hora hora, int duracao, Cidade* orig, Cidade* dest, int n,
			int estrelas = 15, double precoAloInter = 0);

	/**
	 * @brief Define o preco da viagem
	 * @param precViagem - preco da viagem
	 */
	void setPreco(double precViagem);

	/**
	 * @brief
	 * @return retorna a cidade origem da viagem
	 */
	Cidade* getOrigem() const;

	/**
	 * @brief
	 * @return retorna a cidade destino da viagem
	 */
	Cidade* getDestino() const;

	/**
	 * @brief
	 * @return retorna a data da viagem
	 */
	Data getData() const;

	/**
	 * @brief
	 * @return retorna a hora da viagem
	 */
	Hora getHora() const;

	/**
	 * @brief
	 * @return retorna o preco da viagem
	 */
	double getPrecoVi() const;

	/**
	 * @brief
	 * @return retorna o preco do alojamento ate agora
	 */
	double getPrecoAlojInter() const;

	/**
	 * @brief
	 * @return retorna o nr de pessoas que viaja
	 */
	int getNrPess() const;

	/**
	 * @brief Transforma os minutos em horas e minutos correspondentes
	 * @param min - minutos
	 * @return retorna uma string com o tempo emm horas e minutos
	 */
	string mostrarMinutosemHoras(int min) const;

	/**
	 * @brief
	 * @return retorna a duracao da viagem
	 */
	string getDuracao() const;

	/**
	 * @brief
	 * @return retorna o alojamento onde se acaba a viagem
	 */
	Alojamento* getAlojamento() const;

	/**
	 * @brief
	 * @return retorna o quarto onde se acaba a viagem
	 */
	vector<Quarto*> getQuarto() const;

	friend ostream & operator <<(ostream &os, const Viagem &d);

};

class ViagemInvalida {
public:

	/*
	 * @brief Indica que nao e possivel realizar a viagem naquele tempo.
	 */
	void ViagemErrada() {
		cout << "Nao e possivel realizar tal viagem nesse tempo" << endl;
	}

};

#endif /* VIAGEM_H */
