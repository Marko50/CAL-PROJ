#ifndef HORA_H_
#define HORA_H_

#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Hora {
	int hora;
	int min;
public:

	/**
	 * @brief construtor da classe Hora vazio
	 */
	Hora();

	/**
	 * @brief construtor da classe Hora com parametros
	 * @param hor - hora
	 * @param mi - minuto
	 */
	Hora(int hor, int mi);

	/**
	 * @brief funcao para obter hora
	 * @return hora
	 */
	int getHora() const;

	/**
	 * @brief funcao para obter minutos
	 * @return minutos
	 */
	int getMin() const;

	bool operator <(Hora d2);
	friend ostream & operator <<(ostream &os, const Hora &d);

};

class HoraInvalida {
public:

	void HoraErrada() {
		cout << "Hora invalida" << endl;
	}
};

#endif /* HORA_H_ */
