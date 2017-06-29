#include "Cidade.h"

bool compareAlojamentoPointer(Alojamento* a1, Alojamento* a2) {
	if (*a1 < *a2)
		return true;
	else
		return false;
}

Cidade::Cidade() {
}

Cidade::Cidade(string nome, string periodoMaisCaro) {
	this->nome = nome;
	this->periodoMaisCaro = Epoca(periodoMaisCaro);

}

Cidade::Cidade(vector<Alojamento*> alojamentos, string nome,
		string periodoMaisCaro) {

	this->alojamentos = alojamentos;
	this->nome = nome;
	this->periodoMaisCaro = Epoca(periodoMaisCaro);
}

string Cidade::getNome() const {
	return nome;
}

Epoca Cidade::getEpocaCara() {
	return periodoMaisCaro;
}

void Cidade::addAlojamento(Alojamento* a) {
	this->alojamentos.push_back(a);
	sort(alojamentos.begin(), alojamentos.end(), compareAlojamentoPointer);
}

Alojamento* Cidade::getAlojamentoMaisBaratoDentroEstrelas(int i, int estrelas) {
	if (i > alojamentos.size())
		throw CidadeCheia();
	for (unsigned int i = 0; i < alojamentos.size(); i++) {
		if (this->alojamentos[i]->getEstrelas() == estrelas)
			return this->alojamentos[i];
	}

}

Alojamento* Cidade::getAlojamentoMaisBarato(int i) {
	if (i > alojamentos.size())
		throw CidadeCheia();
	return this->alojamentos[i];
}

void Cidade::mostraAlojamentos() {
	for (unsigned int i = 0; i < alojamentos.size(); i++) {
		cout << *alojamentos[i] << endl;
	}

}

vector<Alojamento*> Cidade::getAlojamentos() {
	return alojamentos;
}


void Cidade::mostraPontosInteresse() {
	for (unsigned int i = 0; i < pontos_interesse.size(); i++) {
		cout << pontos_interesse[i] << endl;
	}

}

vector<string> Cidade::getPontosInteresse() {
	return pontos_interesse;
}

void Cidade::addAPontoInteresse(string s) {
	this->pontos_interesse.push_back(s);
}

bool Cidade::operator ==(Cidade c) {

	if (this->nome == c.getNome()) {
		return true;
	} else
		return false;
}

bool Cidade::operator !=(Cidade c) {

	if (this->nome != c.getNome()) {
		return true;
	} else
		return false;
}

ostream & operator <<(ostream &os, const Cidade &v) {

	os << v.getNome();
	return os;

}
