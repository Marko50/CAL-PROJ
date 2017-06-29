#ifndef EPOCA_H_
#define EPOCA_H_

#include <string>
#include "Data.h"


using namespace std;

class Epoca {
	string nome;
	Data dataInicio;
	Data dataFim;

public:
	/**
	 * @brief Construtor de Epoca vazio
	 */
	Epoca();

	/**
	 * @brief Construtor de Epoca
	 * @param nome - nome da epoca
	 */
	Epoca(string nome);

	/**
	 * @brief Ve se certa data faz parte de Epoca ou nao
	 * @param d - data
	 * @return booleano
	 */
	bool emEpoca(Data d);
};

#endif /* EPOCA_H_ */
