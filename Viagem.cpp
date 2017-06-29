#include "Viagem.h"

Viagem::Viagem() {
}

Viagem::Viagem(Data dat, Hora hor, int duracao, Cidade* orig, Cidade* dest,
		int n, int estrelas, double precoAloInter) {

	data = dat;
	hora = hor;
	this->duracao = duracao;
	this->origem = orig;
	this->destino = dest;
	this->precoViagem = 0;
	this->precoAlojaInterm = precoAloInter;
	this->nrPessoas = n;
	int i = 0;
	int test = -1;
	while (test == -1) {
		try {
			if (estrelas == 15)
				al = destino->getAlojamentoMaisBarato(i);
			else
				al = destino->getAlojamentoMaisBaratoDentroEstrelas(i,
						estrelas);

			quarto = al->preencheQuarto(nrPessoas);
			test = 0;
		} catch (AlojamentoCheio &x) {
			x.AlojamentoCheioInc(i, test);
		}
	}
}

void Viagem::setPreco(double precViagem) {

	precoViagem = precViagem;

}

Cidade* Viagem::getOrigem() const {
	return origem;
}

Cidade* Viagem::getDestino() const {
	return destino;
}

Data Viagem::getData() const {
	return data;
}

Hora Viagem::getHora() const {
	return hora;
}

double Viagem::getPrecoVi() const {
	return precoViagem;
}

double Viagem::getPrecoAlojInter() const {
	return precoAlojaInterm;
}

int Viagem::getNrPess() const {
	return nrPessoas;
}

string Viagem::mostrarMinutosemHoras(int min) const {

	stringstream ss;
	int horas = min / 60;

	int minutos = min % 60;

	if (minutos == 0)
		ss << horas << " horas";
	else
		ss << horas << " horas e " << minutos << " minutos";

	return ss.str();

}

string Viagem::getDuracao() const {
	return mostrarMinutosemHoras(duracao);
}

Alojamento* Viagem::getAlojamento() const {
	return al;
}

vector<Quarto*> Viagem::getQuarto() const {
	return quarto;
}

ostream & operator <<(ostream &os, const Viagem &v) {

	Cidade dest = *(v.getDestino());
	os << "Viagem global entre: " << *(v.getOrigem()) << " -> " << dest
			<< " no dia " << v.getData() << " começando as " << v.getHora()
			<< " demora " << v.getDuracao() << " com o custo de "
			<< v.getPrecoVi()
			<< " euros por cada bilhete de Aviao, ficando no hotel: "
			<< *(v.getAlojamento()) << "no(s) quarto(s) " << endl;

	double precoTotal = v.getPrecoVi()*v.getNrPess();
	for (unsigned int i = 0; i < v.getQuarto().size(); i++) {
		double precoAloj = (v.getQuarto()[i])->getPreco();
		;
		if (dest.getEpocaCara().emEpoca(v.getData()))
			precoAloj *= PERCENTAGEM_EPOCA_ALTA
		;
		os << *(v.getQuarto()[i]) << " com o custo de " << precoAloj
				<< " euros por noite" << endl;
		precoTotal += precoAloj;
	}

	precoTotal += v.getPrecoAlojInter();
	os << "Preco total a pagar: " << precoTotal << " euros" << endl;
	return os;
}
