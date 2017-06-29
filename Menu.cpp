#include "Menu.h"

void graphCreator(Graph<Cidade> &mapa, map<string, Cidade> &mapCidade) {

	ifstream fileC("Cidade.txt");

	if (fileC.is_open()) {

		string line;
		while (getline(fileC, line)) {
			string nomeCid, epoca;
			stringstream ss;

			ss << line;
			getline(ss, nomeCid, ';');
			getline(ss, epoca);

			Cidade c = Cidade(nomeCid, epoca);
			mapCidade.insert(pair<string, Cidade>(nomeCid, c));
		}
	} else
		cout << "Erro a abrir o ficheiro de Cidades" << endl;

	ifstream fileA("Alojamento.txt");
	vector<Alojamento> vecAlojamento;

	if (fileA.is_open()) {

		string line;
		while (getline(fileA, line)) {
			string nome, quartos_pisoS, nr_pisosS, precoS, estrelasS, cidade;
			int quartos_piso, nr_pisos, preco, estrelas;
			stringstream ss;
			ss << line;
			getline(ss, nome, ';');
			getline(ss, quartos_pisoS, ';');
			quartos_piso = atoi(quartos_pisoS.c_str());
			getline(ss, nr_pisosS, ';');
			nr_pisos = atoi(nr_pisosS.c_str());
			getline(ss, precoS, ';');
			preco = atoi(precoS.c_str());
			getline(ss, estrelasS, ';');
			estrelas = atoi(estrelasS.c_str());
			getline(ss, cidade);

			for (map<string, Cidade>::iterator it = mapCidade.begin();
					it != mapCidade.end(); it++)
				if (it->first == cidade) {
					it->second.addAlojamento(
							new Alojamento(nome, quartos_piso, nr_pisos, preco,
									estrelas));
				}
		}

	} else
		cout << "Erro a abrir o ficheiro de Alojamentos" << endl;

	ifstream fileP("Pontos_Interesse.txt");
	vector<string> vecPontos;

	if (fileP.is_open()) {

		string line;
		while (getline(fileP, line)) {
			string ponto, cidade;
			stringstream ss;
			ss << line;
			getline(ss, ponto, ';');
			getline(ss, cidade);

			for (map<string, Cidade>::iterator it = mapCidade.begin();
					it != mapCidade.end(); it++)
				if (it->first == cidade) {
					it->second.addAPontoInteresse(ponto);
				}
		}

		for (map<string, Cidade>::iterator it = mapCidade.begin();
				it != mapCidade.end(); it++)
			mapa.addVertex(it->second);
	} else
		cout << "Erro a abrir o ficheiro de Pontos de Interesse" << endl;

}

void addEdgestoGraph(Graph<Cidade> &mapa, map<string, Cidade> mapCidade) {

	mapa.addEdge(mapCidade.at("Porto"), mapCidade.at("Lisboa"), 60, 30);
	mapa.addEdge(mapCidade.at("Lisboa"), mapCidade.at("Porto"), 60, 30);
	mapa.addEdge(mapCidade.at("Porto"), mapCidade.at("Madrid"), 100, 60);
	mapa.addEdge(mapCidade.at("Madrid"), mapCidade.at("Porto"), 100, 60);
	mapa.addEdge(mapCidade.at("Porto"), mapCidade.at("Londres"), 300, 120);
	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Porto"), 300, 120);
	mapa.addEdge(mapCidade.at("Porto"), mapCidade.at("Madeira"), 105, 70);
	mapa.addEdge(mapCidade.at("Madeira"), mapCidade.at("Porto"), 105, 70);
	mapa.addEdge(mapCidade.at("Porto"), mapCidade.at("Paris"), 250, 140);
	mapa.addEdge(mapCidade.at("Paris"), mapCidade.at("Porto"), 250, 140);

	mapa.addEdge(mapCidade.at("Madeira"), mapCidade.at("Acores"), 45, 20);
	mapa.addEdge(mapCidade.at("Acores"), mapCidade.at("Madeira"), 45, 20);

	mapa.addEdge(mapCidade.at("Lisboa"), mapCidade.at("Madrid"), 90, 50);
	mapa.addEdge(mapCidade.at("Madrid"), mapCidade.at("Lisboa"), 90, 50);
	mapa.addEdge(mapCidade.at("Lisboa"), mapCidade.at("Londres"), 200, 110);
	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Lisboa"), 200, 110);
	mapa.addEdge(mapCidade.at("Lisboa"), mapCidade.at("Paris"), 350, 130);
	mapa.addEdge(mapCidade.at("Paris"), mapCidade.at("Lisboa"), 350, 130);

	mapa.addEdge(mapCidade.at("Paris"), mapCidade.at("Londres"), 240, 35);
	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Paris"), 240, 35);
	mapa.addEdge(mapCidade.at("Paris"), mapCidade.at("Bruxelas"), 150, 25);
	mapa.addEdge(mapCidade.at("Bruxelas"), mapCidade.at("Paris"), 150, 25);
	mapa.addEdge(mapCidade.at("Paris"), mapCidade.at("Berlim"), 205, 95);
	mapa.addEdge(mapCidade.at("Berlim"), mapCidade.at("Paris"), 205, 95);
	mapa.addEdge(mapCidade.at("Paris"), mapCidade.at("Amsterdao"), 170, 40);
	mapa.addEdge(mapCidade.at("Amsterdao"), mapCidade.at("Paris"), 170, 40);

	mapa.addEdge(mapCidade.at("Berlim"), mapCidade.at("Frankfurt"), 87, 45);
	mapa.addEdge(mapCidade.at("Frankfurt"), mapCidade.at("Berlim"), 87, 45);

	mapa.addEdge(mapCidade.at("Bruxelas"), mapCidade.at("Berlim"), 116, 75);
	mapa.addEdge(mapCidade.at("Berlim"), mapCidade.at("Bruxelas"), 116, 75);
	mapa.addEdge(mapCidade.at("Bruxelas"), mapCidade.at("Londres"), 90, 40);
	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Bruxelas"), 90, 40);
	mapa.addEdge(mapCidade.at("Bruxelas"), mapCidade.at("Lisboa"), 400, 150);
	mapa.addEdge(mapCidade.at("Lisboa"), mapCidade.at("Bruxelas"), 400, 150);
	mapa.addEdge(mapCidade.at("Bruxelas"), mapCidade.at("Moscovo"), 600, 270);
	mapa.addEdge(mapCidade.at("Moscovo"), mapCidade.at("Bruxelas"), 600, 270);

	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Nova Iorque"), 1200,
			615);
	mapa.addEdge(mapCidade.at("Nova Iorque"), mapCidade.at("Londres"), 1200,
			615);
	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Varsovia"), 450, 180);
	mapa.addEdge(mapCidade.at("Varsovia"), mapCidade.at("Londres"), 450, 180);
	mapa.addEdge(mapCidade.at("Londres"), mapCidade.at("Rio de Janeiro"), 1600,
			720);
	mapa.addEdge(mapCidade.at("Rio de Janeiro"), mapCidade.at("Londres"), 1600,
			720);

	mapa.addEdge(mapCidade.at("Nova Iorque"), mapCidade.at("Miami"), 220, 120);
	mapa.addEdge(mapCidade.at("Miami"), mapCidade.at("Nova Iorque"), 220, 120);

}

Menu::Menu() {
	Graph<Cidade> mapa;
	graphCreator(mapa, mapCidade);
	addEdgestoGraph(mapa, mapCidade);
	agencia = Agencia("FEUP_Viagens", mapa);
	menuEscolhas();
}

int Menu::fazerViagem2Cidades(string &origem, string &destino, int &h, int &m,
		int &dia, int &mes, int &ano, int &nrPesso, int &estrelas) {

	estrelas = VALOR_ESTRELAS_INEXISTENTE
	;

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	string res;
	cout << "Qual é a cidade de onde vai sair? ";
	getline(cin, origem);
	try {
		mapCidade.at(origem);
	} catch (const out_of_range &oor) {
		cout << endl
				<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "

				<< origem << endl;
		int contador = 1, opcao;
		map<string, string> teste = numApproximateStringMatching("Cidade.txt",
				origem);
		if (teste.empty()) {
			cout << "Nao ha cidades encontradas semelhantes ao que escreveu!\n";
			return 1;
		}
		map<string, string>::iterator it = teste.begin();
		for (; it != teste.end(); ++it) {
			cout << contador << "." << it->first << endl;
			contador++;
		}
		cout << "Seria uma destas a cidade pretendida? (s ou n) ";
		cin >> res;
		if (res == "n")
			return 1;
		else
			cout << "Escolha entao: ";
		cin >> opcao;
		it = teste.begin();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (opcao - 1 > 0) {
			it++;
			opcao--;
		}
		origem = it->first;
	}

	cout << "Qual é o seu destino? ";
	getline(cin, destino);
	try {
		mapCidade.at(destino);
	} catch (const out_of_range &oor) {
		cout << endl
				<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "

				<< destino << endl;
		int contador = 1, opcao;
		map<string, string> teste = numApproximateStringMatching("Cidade.txt",
				destino);
		if (teste.empty()) {
			cout << "Nao ha cidades encontradas semelhantes ao que escreveu!\n";
			return 1;
		}
		map<string, string>::iterator it = teste.begin();
		for (; it != teste.end(); ++it) {
			cout << contador << "." << it->first << endl;
			contador++;
		}
		cout << "Seria uma destas a cidade pretendida? (s ou n) ";
		cin >> res;
		if (res == "n")
			return 1;
		else
			cout << "Escolha entao: ";
		cin >> opcao;
		it = teste.begin();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (opcao - 1 > 0) {
			it++;
			opcao--;
		}
		destino = it->first;
	}
	cout << "Digite as horas a que a viagem comeca:" << endl << "Horas: ";
	cin >> h;
	cout << "Minutos: ";
	cin >> m;

	cout << "Digite o dia em que a viagem ocorre:" << endl << "Dia: ";
	cin >> dia;
	cout << "Mes: ";
	cin >> mes;
	cout << "Ano: ";
	cin >> ano;

	cout << "Quantas pessoas são? ";
	cin >> nrPesso;

	string resposta;
	do {
		cout
				<< "Quer especificar o numero de estrelas do hotel onde ficara? (s/n) ";
		cin >> resposta;
	} while (resposta != "s" && resposta != "n");

	if (resposta == "n") {
		return 0;
	}

	do {
		cout
				<< "De quantas estrelas é o hotel que pretende (de 2 a 5 estrelas)? ";
		cin >> estrelas;
	} while (estrelas < 2 || estrelas > 5);

	return 0;
}


int Menu::verCidadeAquandoVariasCidades(vector<Cidade> &locations) {

	string origem, destino, res;

	cin.ignore(INT_MAX, '\n');
	cout << "De onde deseja partir? ";
	getline(cin, origem);

	try {
		mapCidade.at(origem);
	} catch (const out_of_range &oor) {
		cout << endl
				<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "
				<< origem << endl;

		int contador = 1, opcao;
		map<string, string> teste = numApproximateStringMatching("Cidade.txt",
				origem);
		if (teste.empty()) {
			cout << "Nao ha cidades encontradas semelhantes ao que escreveu!\n";
			return 1;
		}
		map<string, string>::iterator it = teste.begin();
		for (; it != teste.end(); ++it) {
			cout << contador << "." << it->first << endl;
			contador++;
		}
		cout << "Seria uma destas a cidade pretendida? (s ou n) ";
		cin >> res;
		if (res == "n")
			return 1;
		else
			cout << "Escolha entao: ";
		cin >> opcao;
		it = teste.begin();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (opcao - 1 > 0) {
			it++;
			opcao--;
		}
		origem = it->first;
	}

	locations.push_back(mapCidade.at(origem));
	cout << "Escolha os destinos que quer: ";
	bool sair = true;
	while (sair == true) {
		res = " ";
		getline(cin, destino);
		if (destino != "q") {
			try {
				mapCidade.at(destino);
			} catch (const out_of_range &oor) {
				cout << endl
						<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "

						<< destino << endl;
				int contador = 1, opcao;
				map<string, string> teste = numApproximateStringMatching(
						"Cidade.txt", destino);
				if (teste.empty()) {
					cout
							<< "Nao ha pontos de interesse encontrados semelhantes ao que escreveu!\n";

				} else {
					map<string, string>::iterator it = teste.begin();
					for (; it != teste.end(); ++it) {
						cout << contador << "." << it->first << endl;
						contador++;
					}
					cout << "Seria uma destas a cidade pretendida? (s ou n) ";
					cin >> res;
					if (res == "s") {

						cout << "Escolha entao: ";
						cin >> opcao;
						it = teste.begin();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						while (opcao - 1 > 0) {
							it++;
							opcao--;
						}
						destino = it->first;
					}
				}
			}
			locations.push_back(mapCidade.at(destino));
			cout
					<< "Proxima cidade (ou pressione q se nao quiser mais cidades) ";
		} else
			sair = false;
	}

	return 0;
}


void Menu::fazerViagemVariasCidades(int &h, int &m, int &dia, int &mes,
		int &ano, int &nrPesso, int &estrelas) {

	cout << "Digite as horas a que a viagem comeca:" << endl << "Horas: ";
	cin >> h;
	cout << "Minutos: ";
	cin >> m;

	cout << "Digite o dia em que a viagem ocorre:" << endl << "Dia: ";
	cin >> dia;
	cout << "Mes: ";
	cin >> mes;
	cout << "Ano: ";
	cin >> ano;

	cout << "Quantas pessoas são? ";
	cin >> nrPesso;

	string res;
	do {
		cout
				<< "Quer especificar o numero de estrelas do hotel onde ficara? (s/n) ";
		cin >> res;
	} while (res != "s" && res != "n");

	if (res == "s") {

		do {
			cout
					<< "De quantas estrelas é o hotel que pretende (de 2 a 5 estrelas)? ";
			cin >> estrelas;
		} while (estrelas < 2 || estrelas > 5);
	}
}

void Menu::fazerViagemMenorCusto2Cidades() {

	string origem, destino;
	int h, m, dia, mes, ano, nrPesso, estrelas;
	if (this->fazerViagem2Cidades(origem, destino, h, m, dia, mes, ano, nrPesso,
			estrelas) == 1)
		return;

	Viagem v = agencia.fazerViagemMenorCusto(&mapCidade.at(origem),
			&mapCidade.at(destino), Data(dia, mes, ano), Hora(h, m), nrPesso,
			estrelas);

	cout << endl << v;

	agencia.obterItinerarioViagemMenorCusto(mapCidade.at(origem),
			mapCidade.at(destino));

}

void Menu::fazerViagemRapida2Cidades() {

	string origem, destino;
	int h, m, dia, mes, ano, nrPesso, estrelas;
	if (this->fazerViagem2Cidades(origem, destino, h, m, dia, mes, ano, nrPesso,
			estrelas) == 1)
		return;
	Viagem v = agencia.fazerViagemMaisRapida(&mapCidade.at(origem),
			&mapCidade.at(destino), Data(dia, mes, ano), Hora(h, m), nrPesso,
			estrelas);

	cout << endl << v;
	agencia.obterItinerarioViagemMenorCusto(mapCidade.at(origem),
			mapCidade.at(destino));

}

void Menu::fazerViagemMenorCustoEntreLimite() {

	string origem, destino;
	int h, m, dia, mes, ano, nrPesso, duracao, estrelas;
	if (this->fazerViagem2Cidades(origem, destino, h, m, dia, mes, ano, nrPesso,
			estrelas) == 1)
		return;

	cout << "Maxima duracao da viagem em minutos? ";
	cin >> duracao;

	Viagem v = agencia.fazerViagemMenorCustoDentroTempo(&mapCidade.at(origem),
			&mapCidade.at(destino), Data(dia, mes, ano), Hora(h, m), nrPesso,
			duracao, estrelas);

	cout << endl << v;
	agencia.obterItinerarioViagemMenorCusto(mapCidade.at(origem),
			mapCidade.at(destino));

}

void Menu::fazerViagemMenorcustoDestinos() {
	vector<Cidade> locations;
	int h, m, dia, mes, ano, nrPesso, estrelas = VALOR_ESTRELAS_INEXISTENTE
	;

	this->fazerViagemVariasCidades(h, m, dia, mes, ano, nrPesso, estrelas);

	if(this->verCidadeAquandoVariasCidades(locations))
		return;

	agencia.fazerViagemMenorcustoDestinos(locations, Data(dia, mes, ano),
			Hora(h, m), nrPesso, estrelas);

}

void Menu::fazerViagemMaisRapidaDestinos() {
	vector<Cidade> locations;
	int h, m, dia, mes, ano, nrPesso, estrelas = VALOR_ESTRELAS_INEXISTENTE
	;

	this->fazerViagemVariasCidades(h, m, dia, mes, ano, nrPesso, estrelas);

	if(this->verCidadeAquandoVariasCidades(locations))
		return;

	agencia.fazerViagemMaisRapidaDestinos(locations, Data(dia, mes, ano),
			Hora(h, m), nrPesso, estrelas);

}

void Menu::fazerViagemMenorcustoDestinosOrdenados() {
	vector<Cidade> locations;
	int h, m, dia, mes, ano, nrPesso, estrelas = VALOR_ESTRELAS_INEXISTENTE
	;

	this->fazerViagemVariasCidades(h, m, dia, mes, ano, nrPesso, estrelas);

	if(this->verCidadeAquandoVariasCidades(locations))
		return;

	agencia.fazerViagemMenorcustoDestinosOrde(locations, Data(dia, mes, ano),
			Hora(h, m), nrPesso, estrelas);

}

void Menu::fazerViagemMaisRapidaDestinosOrdenados() {
	vector<Cidade> locations;
	int h, m, dia, mes, ano, nrPesso, estrelas = VALOR_ESTRELAS_INEXISTENTE
	;

	this->fazerViagemVariasCidades(h, m, dia, mes, ano, nrPesso, estrelas);

	if(this->verCidadeAquandoVariasCidades(locations))
		return;

	agencia.fazerViagemMaisRapiDestinosOrde(locations, Data(dia, mes, ano),
			Hora(h, m), nrPesso, estrelas);

}

void Menu::mostrarCidadesDisponiveis() {

	for (map<string, Cidade>::iterator it = mapCidade.begin();
			it != mapCidade.end(); it++) {

		cout << it->second << endl;
	}

}

void Menu::mostrarAlojamentosdeCidade() {

	cin.ignore(INT_MAX, '\n');
	string cidade;
	cout << "Qual é a cidade da qual deseja ver os hoteis? ";
	getline(cin, cidade);
	cout << endl;
	try {
		mapCidade.at(cidade).mostraAlojamentos();
	} catch (const out_of_range &oor) {
		cout << endl
				<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "
				<< cidade << endl;
		return;
	}

}

void Menu::connectivity() {

	if (agencia.getMapa().testConnectivity())
		cout << endl << "O grafo e conexo" << endl;
	else
		cout << endl << "O grafo nao e conexo" << endl;
}

void Menu::mostrarPontosInteressedeCidade() {

	cin.ignore(INT_MAX, '\n');
	string cidade;
	cout << "Qual é a cidade da qual deseja ver os pontos de interesse? ";
	getline(cin, cidade);
	cout << endl;
	try {
		mapCidade.at(cidade).mostraPontosInteresse();
	} catch (const out_of_range &oor) {
		cout << endl
				<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "
				<< cidade << endl;
		return;
	}

}

void Menu::procurarCidadecomPontoInteresse() {

	cin.ignore(INT_MAX, '\n');
	string ponto;
	cout << "Digite o nome do Ponto de Interesse que deseja encontrar: ";
	getline(cin, ponto);
	cout << endl;

	agencia.procuraPontoInteresse(ponto);

}

void Menu::mostrarGrafo() {

	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("nos.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	std::string line;

	int idNo;
	int X = 0;
	int Y = 0;
	string cidade;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;

		linestream >> idNo;

		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> X;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> Y;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> cidade;
		gv->addNode(idNo, X, Y);
		gv->setVertexLabel(idNo, cidade);

	}

	inFile.close();

	inFile.open("arestas.txt");

	if (!inFile) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	int idAresta = 0;
	int idNoOrigem = 0;
	int idNoDestino = 0;

	while (std::getline(inFile, line)) {
		std::stringstream linestream(line);
		std::string data;

		linestream >> idAresta;

		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> idNoOrigem;
		std::getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> idNoDestino;
		gv->addEdge(idAresta, idNoOrigem, idNoDestino, EdgeType::UNDIRECTED);

	}

	inFile.close();

	gv->rearrange();
}

void Menu::fazerViagemPontosDeInteresse() {
	cout << "Por favor, indique de que cidade irá sair: ";
	string origem;
	cin.ignore(INT_MAX, '\n');
	getline(cin, origem);
	try {
		mapCidade.at(origem);
	} catch (const out_of_range &oor) {
		cout << endl
				<< "Pedimos desculpa, mas nao fazemos viagens para a cidade "

				<< origem << endl;

		string res;
		int contador = 1, opcao;
		map<string, string> teste = numApproximateStringMatching("Cidade.txt",
				origem);
		if (teste.empty()) {
			cout
					<< "Nao ha cidades encontradas semelhantes ao que escreveu!\n";
			return;
		}
		map<string, string>::iterator it = teste.begin();
		for (; it != teste.end(); ++it) {
			cout << contador << "." << it->first << endl;
			contador++;
		}
		cout << "Seria uma destas a cidade pretendida? (s ou n) ";
		cin >> res;
		if (res == "n")
			return;
		else
			cout << "Escolha entao: ";
		cin >> opcao;
		it = teste.begin();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (opcao - 1 > 0) {
			it++;
			opcao--;
		}
		origem = it->first;
	}
	vector<Cidade> locs;
	locs.push_back(mapCidade.at(origem));
	cout << "Para parar digitar n" << endl;
	cout << "Por favor indique pontos de interesse que pretende visitar: ";
	string ponto = "";
	stringstream ss;
	string cid;
	int contador;
	int opcao;
	while (true) {
		contador = 1;
		cout << "Ponto (Para parar digitar n): ";
		getline(cin, ponto);
		if (ponto == "n")
			break;

		bool encontrado;

		string cidade = numStringMatching("Pontos_Interesse.txt", ponto,
				encontrado);
		if (encontrado) {

			cout << "O/A " << ponto << " esta na cidade: " << cidade << endl;
			locs.push_back(mapCidade.at(cidade));
		} else {

			map<string, string> teste = numApproximateStringMatching(
					"Pontos_Interesse.txt", ponto);
			if (teste.empty()) {
				cout
						<< "Nao ha pontos de interesse encontrados semelhantes ao que escreveu!\n";
				continue;
			}
			map<string, string>::iterator it = teste.begin();
			for (; it != teste.end(); ++it) {
				cout << contador << "." << it->first << " => " << it->second
						<< '\n';
				contador++;
			}
			it = teste.begin();
			cout
					<< "Nao encontramos esse ponto, nao queria antes escolher um destes pontos: ";
			cin >> opcao;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (opcao - 1 > 0) {
				it++;
				opcao--;
			}
			locs.push_back(mapCidade.at(it->second));
		}
	}

	int h, m, dia, mes, ano, nrPesso, estrelas = VALOR_ESTRELAS_INEXISTENTE
	;

	this->fazerViagemVariasCidades(h, m, dia, mes, ano, nrPesso, estrelas);

	cout << "Quer fazer a viagem: " << endl;
	cout << " 1- Mais barata entre destinos" << endl;
	cout << " 2- Mais rapida entre destinos" << endl;
	cout
			<< " 3- Mais barata entre destinos de acordo com a ordem de escolha dos pontos de interesse"
			<< endl;
	cout
			<< " 4- Mais rapida entre destinos de acordo com a ordem de escolha dos pontos de interesse"
			<< endl;

	int opC;

	while (1) {
		try {
			cout << setw(5) << " " << "op: ";
			cin >> opC;

			switch (opC) {
			case 1: {

				agencia.fazerViagemMenorcustoDestinos(locs, Data(dia, mes, ano),
						Hora(h, m), nrPesso, estrelas);
				return;
			}
			case 2: {
				agencia.fazerViagemMaisRapidaDestinos(locs, Data(dia, mes, ano),
						Hora(h, m), nrPesso, estrelas);
				return;
			}
			case 3: {
				agencia.fazerViagemMenorcustoDestinosOrde(locs,
						Data(dia, mes, ano), Hora(h, m), nrPesso, estrelas);

				return;
			}

			case 4: {
				agencia.fazerViagemMaisRapiDestinosOrde(locs,
						Data(dia, mes, ano), Hora(h, m), nrPesso, estrelas);
				return;
			}
			default:
				throw OpcaoErrada();
			}
		} catch (OpcaoErrada &x) {
			x.alertaErro();
			cin.clear();
			cin.ignore();

		}
	}

}

void Menu::menuEscolhas() {

	while (1) {

		cout << endl << endl << "||FEUP_Viagens||" << endl << setw(5) << " "
				<< setw(5) << "1. Mostrar as Cidades Disponiveis" << endl
				<< setw(5) << " "
				<< "2. Mostrar os hoteis disponiveis numa cidade especifica"
				<< endl << setw(5) << " "
				<< "3. Fazer viagem com menor custo entre 2 cidades" << endl
				<< setw(5) << " "
				<< "4. Fazer viagem mais rapida entre 2 cidades" << endl
				<< setw(5) << " "
				<< "5. Fazer viagem com menor custo dentro de um certo limite de tempo"
				<< endl << setw(5) << " "
				<< "6. Fazer viagem com menor custo entre varios destinos"
				<< endl << setw(5) << " "
				<< "7. Fazer viagem mais rapida entre varios destinos" << endl
				<< setw(5) << " "
				<< "8. Fazer viagem com menor custo entre varios destinos definindo a sua ordem"
				<< endl << setw(5) << " "
				<< "9. Fazer viagem mais rapida entre varios destinos definindo a sua ordem"
				<< endl << setw(5) << " "
				<< "10. Avaliar a conectividade do Grafo" << endl << setw(5)
				<< " " << "11. Mostrar o Grafo" << endl << setw(5) << " "
				<< "12. Mostrar os pontos de interesse de uma cidade especifica"
				<< endl << setw(5) << " "
				<< "13. Procurar um ponto de interesse desejado" << endl
				<< setw(5) << " " << "14. Viagem ponto de interesse desejado"
				<< endl << setw(5) << " " << "15. Sair" << endl;

		int opC;

		try {
			cout << setw(5) << " " << "op: ";
			cin >> opC;

			switch (opC) {
			case 1: {

				mostrarCidadesDisponiveis();
				break;
			}
			case 2: {
				mostrarAlojamentosdeCidade();
				break;
			}
			case 3: {
				fazerViagemMenorCusto2Cidades();
				break;
			}

			case 4: {
				fazerViagemRapida2Cidades();
				break;
			}
			case 5: {
				fazerViagemMenorCustoEntreLimite();
				break;
			}
			case 6: {
				fazerViagemMenorcustoDestinos();
				break;
			}
			case 7: {
				fazerViagemMaisRapidaDestinos();
				break;
			}

			case 8: {
				fazerViagemMenorcustoDestinosOrdenados();
				break;
			}

			case 9: {
				fazerViagemMaisRapidaDestinosOrdenados();
				break;
			}
			case 10: {
				connectivity();
				break;
			}
			case 11: {
				mostrarGrafo();
				break;
			}
			case 12: {
				mostrarPontosInteressedeCidade();
				break;
			}
			case 13: {
				procurarCidadecomPontoInteresse();
				break;
			}
			case 14: {
				fazerViagemPontosDeInteresse();
				break;
			}
			case 15: {
				return;
			}
			default:
				throw OpcaoErrada();
			}
		} catch (OpcaoErrada &x) {
			x.alertaErro();
			cin.clear();
			cin.ignore();

		} catch (ViagemInvalida &x) {
			x.ViagemErrada();

		} catch (CidadeCheia &x) {
			x.CidadeChei();

		} catch (DataInvalida &x) {
			x.dataErrada();

		} catch (HoraInvalida &x) {
			x.HoraErrada();

		}

	}
}

