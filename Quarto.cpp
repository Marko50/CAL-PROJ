#include "Quarto.h"

Quarto::Quarto(int nome, int piso, int capacidade, float preco) {

	this->nome = nome;
	this->piso = piso;
	this->capacidade = capacidade;
	ocupado = false;
	preco_por_noite = preco;
}

void Quarto::setOcupacao(bool oc) {

	ocupado = oc;
}

int Quarto::getCapacidade() const {

	return capacidade;
}

int Quarto::getPiso() const {

	return piso;
}

int Quarto::getNome() const {

	return nome;
}

bool Quarto::getOcupacao() const {

	return ocupado;
}

int Quarto::getPreco() const {

	return preco_por_noite;
}

bool Quarto::operator <(Quarto q2) {
	if (preco_por_noite < q2.getPreco())
		return true;
	else
		return false;

}

ostream & operator <<(ostream &os, const Quarto &d) {
	os << d.getNome() << " Piso: " << d.getPiso();


	return os;
}

