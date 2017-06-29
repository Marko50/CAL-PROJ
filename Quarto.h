#ifndef QUARTO_H_
#define QUARTO_H_


#include <iostream>

using namespace std;

class Quarto {
	int nome;
	int piso;
	int capacidade;
	bool ocupado;
	float preco_por_noite;
public:

	/**
	 * @brief Construtor de Quarto
	 * @param nome - nome do quarto
	 * @param piso - piso do quarto
	 * @param capacidade - capacidade do quarto
	 * @param preco - preco do quarto
	 */
	Quarto(int nome, int piso, int capacidade, float preco);

	/**
	 * @brief Ocupa ou liberta o quarto
	 * @param oc - verdadeiro ou falso
	 */
	void setOcupacao(bool oc);

	/**
	 * @brief
	 * @return retorna a capacidade do quarto
	 */
	int getCapacidade() const;

	/**
	 * @brief
	 * @return retorna o piso do quarto
	 */
	int getPiso() const;

	/**
	 * @brief
	 * @return retorna o nome do quarto
	 */
	int getNome() const;

	/**
	 * @brief
	 * @return retorna se o quarto ta ocupado ou nao
	 */
	bool getOcupacao() const;

	/**
	 * @brief
	 * @return retorna o preco do quarto
	 */
	int getPreco() const;

	/*
	 * @brief overload ao operador <
	 * @param q2 - Quarto a comparar
	 * @return retorna se e menor ou nao
	 */
	bool operator <(Quarto q2);
	friend ostream & operator <<(ostream &os, const Quarto &d);

};
#endif /* QUARTO_H_ */
