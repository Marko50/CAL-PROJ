#ifndef DATA_H_
#define DATA_H_

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

class Data {
	int ano;
	int mes;
	int dia;
public:
	/**
	 * @brief construtor da classe Data vazio
	 */
	Data() {
	}
	;
	/**
	 * @brief construtor da classe Data com parametros
	 * @param d - dia
	 * @param m - mes
	 */
	Data(int d, int m);

	/**
	 * @brief construtor da classe Data com parametros
	 * @param dia - dia
	 * @param mes - mes
	 * @param ano - ano
	 */
	Data(int ano, int mes, int dia);

	/**
	 * @brief funcao para obter ano
	 * @return ano
	 */
	int getAno() const;

	/**
	 * @brief funcao para obter mes
	 * @return mes
	 */
	int getMes() const;

	/**
	 * @brief funcao para obter dia
	 * @return dia
	 */
	int getDia() const;
	/*
	 * @brief overload ao operador <
	 * @param d2- Data a comparar
	 * @return retorna se e menor ou nao
	 */
	bool operator <(Data d2);
	/*
	 * @brief overload ao operador <=
	 * @param d2- Data a comparar
	 * @return retorna se e menor ou igual ou nao
	 */
	bool operator <=(Data d2);
	friend ostream & operator <<(ostream &os, const Data &d);
};

class DataInvalida {
public:
	/*
	 * @brief Imprime mensagem de que a data e invalida
	 */
	void dataErrada() {
		cout << "Data invalida" << endl;
	}

};

#endif /* DATA_H_ */
