#include "Alojamento.h"

bool compareQuartoPointer(Quarto* q1, Quarto* q2) {
	if (*q1 < *q2)
		return true;
	else
		return false;
}

Alojamento::Alojamento(string nome, int quartos_piso, int nr_pisos, int preco,
		int estrelas) {

	this->nome = nome;
	int piso = 1;
	for (int i = 0; i < nr_pisos; i++) {
		int quarto = 0;
		for (int j = 0; j < quartos_piso; j++) {
			int capacidade = rand() % 2 + 4;
			quartos.push_back(
					new Quarto(piso * 100 + quarto, piso, capacidade,
							capacidade * preco));
			quarto++;
		}
		piso++;
	}
	this->estrelas = estrelas;
	this->cheio = false;
	sort(quartos.begin(), quartos.end(), compareQuartoPointer);
}

int Alojamento::getCapacidadeLivre() {

	int res = 0;

	for (unsigned int i = 0; i < quartos.size(); i++)
		if (quartos[i]->getOcupacao() == false)
			res += quartos[i]->getCapacidade();
	return res;
}

vector<Quarto*> Alojamento::getQuartos() const {
	return this->quartos;
}

int Alojamento::getCapacidadeMaxima() {

	int res = 0;
	for (unsigned int i = 0; i < quartos.size(); i++)
		if (quartos[i]->getCapacidade() > res)
			res = quartos[i]->getCapacidade();
	return res;
}

double Alojamento::precoMinimo() {

	double res = INT_MAX;
	for (unsigned int i = 0; i < quartos.size(); i++)
		if (quartos[i]->getPreco() < res)
			res = quartos[i]->getPreco();
	return res;
}

vector<Quarto*> Alojamento::preencheQuarto(int nr_Pessoas) {

	vector<Quarto*> q;

	int n = nr_Pessoas;

	if (n > this->getCapacidadeLivre())
		throw AlojamentoCheio();

	while (this->getCapacidadeMaxima() < n) {

		n -= this->getCapacidadeMaxima();

		for (unsigned int i = 0; i < quartos.size(); i++)
			if (quartos[i]->getOcupacao() == false
					&& quartos[i]->getCapacidade()
							>= this->getCapacidadeMaxima()) {

				quartos[i]->setOcupacao(true);
				q.push_back(quartos[i]);
				break;
			}
	}

	for (unsigned int i = 0; i < quartos.size(); i++)
		if (quartos[i]->getOcupacao() == false
				&& quartos[i]->getCapacidade() >= n) {

			quartos[i]->setOcupacao(true);
			q.push_back(quartos[i]);
			break;
		}

	return q;
}

string Alojamento::getNome() const {
	return nome;
}

int Alojamento::getEstrelas() const {
	return estrelas;
}

bool Alojamento::operator ==(Alojamento a2) {
	if (this->nome == a2.getNome() && this->estrelas == a2.getEstrelas())
		return true;
	else
		return false;
}

bool Alojamento::operator <(Alojamento a2) {

	if (this->precoMinimo() < a2.precoMinimo())
		return true;
	else
		return false;
}

void Alojamento::mostrarQuartos() {
	for (unsigned int i = 0; i < quartos.size(); i++)
		cout << *quartos[i] << endl;

}

ostream & operator <<(ostream &os, const Alojamento &v) {

	os << v.getNome() << " de " << v.getEstrelas() << " estrelas ";

	return os;
}

