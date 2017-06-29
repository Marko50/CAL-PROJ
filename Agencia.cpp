#include "Agencia.h"

Agencia::Agencia() {
}

Agencia::Agencia(string nome, Graph<Cidade> grp) {
	this->nome = nome;
	this->mapa = grp;
}

Graph<Cidade> Agencia::getMapa() {
	return mapa;
}

void Agencia::setMapa(Graph<Cidade> m) {
	this->mapa = m;
}

Viagem Agencia::fazerViagemMenorCusto(Cidade* origem, Cidade* destino, Data d,
		Hora h, int nrPesso, int estrelas) {

	int duracao = 0;
	double precViag = mapa.travelShortestPath(*origem, *destino, duracao);

	Viagem v = Viagem(d, h, duracao, origem, destino, nrPesso, estrelas);

	v.setPreco(precViag);

	return v;
}

Viagem Agencia::fazerViagemMaisRapida(Cidade* origem, Cidade* destino, Data d,
		Hora h, int nrPesso, int estrelas) {

	double precViag = 0;
	int duracao = mapa.travelFastestPath(*origem, *destino, precViag);

	Viagem v = Viagem(d, h, duracao, origem, destino, nrPesso, estrelas);

	v.setPreco(precViag);

	return v;
}

Viagem Agencia::fazerViagemMenorCustoDentroTempo(Cidade* origem,
		Cidade* destino, Data d, Hora h, int nrPesso, int limite,
		int estrelas) {

	double precViag = 0;
	int duracao = mapa.PathWithinTime(*origem, *destino, limite, precViag);
	Viagem v = Viagem(d, h, duracao, origem, destino, nrPesso, estrelas);

	v.setPreco(precViag);

	return v;
}

void Agencia::obterItinerarioViagemMenorCusto(Cidade ori, Cidade dest) {
	vector<Cidade> itinerario = mapa.getPath(ori, dest);

	cout << "Itinerario da viagem: ";

	for (unsigned int i = 0;; i++) {
		cout << itinerario[i];
		if (i == itinerario.size() - 1)
			break;
		cout << " -> ";
	}
}

void Agencia::fazerViagemMenorcustoDestinos(vector<Cidade> loc, Data d, Hora h,
		int nrPesso, int estrelas) {

	int duracao = 0;
	int precViag = 0;
	stringstream ss;

	vector<Cidade> locations;

	locations = mapa.LocationsShortestPathUnorderedGreedy(loc, duracao,
			precViag, ss);

	double precoTotal;

	if (estrelas == 15) {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;
			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBarato(j);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}

	} else {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;
			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBaratoDentroEstrelas(i,
							estrelas);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}
	}

	Viagem v = Viagem(d, h, duracao, &locations[0],
			&locations[locations.size() - 1], nrPesso, estrelas, precoTotal);
	v.setPreco(precViag);

	cout << endl << v << endl;
	cout << ss.str() << endl;

}

void Agencia::fazerViagemMaisRapidaDestinos(vector<Cidade> loc, Data d, Hora h,
		int nrPesso, int estrelas) {

	int duracao = 0;
	int precViag = 0;
	stringstream ss;

	vector<Cidade> locations;
	locations = mapa.LocationsFastestPathUnorderedGreedy(loc, duracao, precViag,
			ss);
	double precoTotal;
	if (estrelas == 15) {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;
			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBarato(j);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}

	} else {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;
			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBaratoDentroEstrelas(i,
							estrelas);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}
	}

	Viagem v = Viagem(d, h, duracao, &locations[0],
			&locations[locations.size() - 1], nrPesso, estrelas, precoTotal);
	v.setPreco(precViag);

	cout << endl << v << endl;
	cout << ss.str() << endl;
}

void Agencia::fazerViagemMenorcustoDestinosOrde(vector<Cidade> loc, Data d,
		Hora h, int nrPesso, int estrelas) {

	int duracao = 0;
	int precViag = 0;
	stringstream ss;

	vector<Cidade> locations;

	locations = mapa.LocationsShortestPathOrdered(loc, duracao, precViag, ss);

	double precoTotal;
	if (estrelas == 15) {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;
			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBarato(j);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}

	} else {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {
			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;

			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBaratoDentroEstrelas(i,
							estrelas);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}
	}

	Viagem v = Viagem(d, h, duracao, &locations[0],
			&locations[locations.size() - 1], nrPesso, estrelas, precoTotal);
	v.setPreco(precViag);

	cout << endl << v << endl;
	cout << ss.str() << endl;

}

void Agencia::fazerViagemMaisRapiDestinosOrde(vector<Cidade> loc, Data d,
		Hora h, int nrPesso, int estrelas) {

	int duracao = 0;
	int precViag = 0;
	stringstream ss;

	vector<Cidade> locations;

	locations = mapa.LocationsFastestPathOrdered(loc, duracao, precViag, ss);

	double precoTotal;
	if (estrelas == 15) {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;

			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBarato(j);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}

	} else {
		for (unsigned int i = 1; i < locations.size() - 1; i++) {

			bool intermediate = false;
			for (unsigned int k = 1; k < loc.size() - 1; k++) {
				if (loc[k] == locations[i])
					intermediate = true;
			}

			if (!intermediate)
				continue;
			int j = 0;
			Alojamento* a;
			vector<Quarto*> q;
			int test = -1;
			while (test == -1) {
				try {
					a = locations[i].getAlojamentoMaisBaratoDentroEstrelas(i,
							estrelas);
					q = a->preencheQuarto(nrPesso);
					test = 0;
				} catch (AlojamentoCheio &x) {
					x.AlojamentoCheioInc(j, test);
				}
			}
			cout << endl << "Alojamento intermedio na cidade " << locations[i]
					<< " no hotel " << *a << "no(s) quarto(s) " << endl;

			for (unsigned int i = 0; i < q.size(); i++) {
				double precoAloj = (q[i])->getPreco();

				if (locations[i].getEpocaCara().emEpoca(d))
					precoAloj *= PERCENTAGEM_EPOCA_ALTA
				;
				cout << *(q[i]) << " com o custo de " << precoAloj
						<< " euros por noite" << endl;
				precoTotal += precoAloj;
			}
		}
	}

	Viagem v = Viagem(d, h, duracao, &locations[0],
			&locations[locations.size() - 1], nrPesso, estrelas, precoTotal);
	v.setPreco(precViag);

	cout << endl << v << endl;
	cout << ss.str() << endl;

}

void Agencia::procuraPontoInteresse(string ponto) {

	bool encontrado;

	string cidade = numStringMatching("Pontos_Interesse.txt", ponto,
			encontrado);
	if (encontrado) {

		cout << "O/A " << ponto << " esta na cidade: " << cidade;

		return;
	}

	//fazer pesquisa aproximada

	map<string, string> aproximados = numApproximateStringMatching(
			"Pontos_Interesse.txt", ponto);

	if (aproximados.empty()) {
					cout
							<< "Nao ha pontos de interesse encontrados semelhantes ao que escreveu!\n";
					return;
				}

	cout
			<< "Nao encontramos o ponto fornecido. Todavia, estes sao os que mais se aproximam: "
			<< endl;

	for (map<string, string>::iterator it = aproximados.begin();
			it != aproximados.end(); it++)
		cout << it->first << " em " << it->second << endl;

}
