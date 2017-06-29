#include "Epoca.h"

Epoca::Epoca(){};

Epoca::Epoca(string nome) {

	this->nome = nome;
	if (nome == "Verao") {
		dataInicio =  Data(21, 6);
		dataFim =  Data(20, 10);
	} else if (nome == "Inverno") {
		dataInicio =  Data(21, 12);
		dataFim =  Data(19, 3);
	} else if (nome == "Primavera") {
		dataInicio =  Data(20, 3);
		dataFim =  Data(20, 10);
	} else {
		dataInicio =  Data(21, 10);
		dataFim =  Data(20, 12);
	}

}

bool Epoca::emEpoca(Data d) {

	if (dataInicio <= d && d <= dataFim)
		return true;
	else
		return false;
}
