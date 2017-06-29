#ifndef CIDADE_H_
#define CIDADE_H_

#include <vector>
#include <queue>
#include <string>
#include "Alojamento.h"
#include "Epoca.h"

using namespace std;

class Cidade {
	vector<Alojamento*> alojamentos;
	string nome;
	Epoca periodoMaisCaro;
	vector<string> pontos_interesse;

public:

	/**
	 * @brief Cria uma cidade
	 */
	Cidade();

	/**
	 * @brief Cria uma cidade
	 * @param nome - Nome da cidade
	 * @param periodoMaisCaro - Nome da Epoca mais cara para ser alojado
	 */
	Cidade(string nome, string periodoMaisCaro);

	/**
	 * @brief Cria uma cidade
	 * @param alojamentos - Alojamentos da cidade
	 * @param nome - Nome da cidade
	 * @param periodoMaisCaro - Nome da Epoca mais cara para ser alojado
	 */
	Cidade(vector<Alojamento*> alojamentos, string nome,
			string periodoMaisCaro);

	/**
	 * @brief
	 * @return o nome da cidade
	 */
	string getNome() const;

	/**
	 * @brief
	 * @return a epoca mais cara
	 */
	Epoca getEpocaCara();

	/**
	 * @brief Adiciona alojamento a cidade
	 * @param a - alojamento que sera adicionado
	 */
	void addAlojamento(Alojamento* a);

	/**
	 * @brief Vai buscar o alojamento com certas estrelas mais barato
	 * @param i - posicao do vetor de onde se vai retirar o alojamento
	 * @param estrelas - estrelas pretendidas para o alojamento
	 * @return pointer para alojamento achado
	 */
	Alojamento* getAlojamentoMaisBaratoDentroEstrelas(int i, int estrelas);

	/**
	 * @brief Vai buscar o alojamento mais barato
	 * @param i - posicao do vetor de onde se vai retirar o alojamento
	 * @return pointer para alojamento achado
	 */
	Alojamento* getAlojamentoMaisBarato(int i);

	/**
	 * @brief Mostra todos os alojamentos
	 */
	void mostraAlojamentos();

	/**
	 * @brief
	 * @return vetor de alojamentos
	 */
	vector<Alojamento*> getAlojamentos();

	/**
	 * @brief Mostra todos os pontos de interesse
	 */
	void mostraPontosInteresse();

	/**
	 * @brief
	 * @return vetor de strings contendo os pontos de interesse da cidade
	 */
	vector<string> getPontosInteresse();

	/**
	 * @brief Adiciona ponto de interesse a cidade
	 * @param a - ponto de interesse que sera adicionado
	 */
	void addAPontoInteresse(string s);

	bool operator ==(Cidade c);
	bool operator !=(Cidade c);
	friend ostream & operator <<(ostream &os, const Cidade &v);
};

class CidadeCheia {
public:
	/*
	 * @brief Imprimie mensagem de que os hoteis estao cheios
	 */
	void CidadeChei() {
		cout << "Todos os hoteis da cidade estao cheios, pedimos desculpa"
				<< endl;
	}

};

#endif /* CIDADE_H_ */
