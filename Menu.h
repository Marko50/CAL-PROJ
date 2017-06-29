#ifndef MENU_H_
#define MENU_H_

#include <map>
#include <sstream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <string>
#include "graphviewer.h"
#include "Alojamento.h"
#include "Cidade.h"
#include "Graph.h"
#include "Agencia.h"
#include "matcher.h"


using namespace std;

#define VALOR_ESTRELAS_INEXISTENTE 15;

class Menu {
	map<string, Cidade> mapCidade;
	Agencia agencia;
public:
	/*
	 * @brief construtor de Menu
	 */
	Menu();
	/*
	 * @brief Apresenta as escolhas do menu no ecra
	 */
	void menuEscolhas();
	/*
	 * @brief Fazer a viagem entre duas cidades
	 * @param origem - nome da cidade de origem
	 * @param destino - nome da cidade de destino
	 * @param h - hora de partida
	 * @param m - minuto de partida
	 * @param dia - dia da partida
	 * @param mes - mes da partida
	 * @param ano - ano da viagem
	 * @param nrPesso - numero de viajantes
	 * @param estrelas - estrelas do hotel
	 * @return retorna 0 no caso de sucesso e 1 no caso de erro
	 */
	int fazerViagem2Cidades(string &origem, string &destino, int &h, int &m, int &dia, int &mes, int &ano, int &nrPesso, int &estrelas);
	/*
	 * @brief
	 * @param locations -
	 * @return retorna 0 em sucesso e 1 em insucesso
	 */
	int verCidadeAquandoVariasCidades(vector<Cidade> &locations);
	/*
	 * @brief Opcao de fazer viagem por varias cidades
	 * @param h - hora da viagem
	 * @param m - minutos da viagem
	 * @param dia - dia da viagem
	 * @param mes - mes da viagem
	 * @param ano - ano da viagem
	 * @param nrPesso - numero de viajantes
	 * @param estrelas - estrelas do hotel
	 * @return retorna 0 em sucesso e 1 no caso de insucesso
	 */
	void fazerViagemVariasCidades(int &h, int &m, int &dia, int &mes, int &ano, int &nrPesso, int &estrelas);
	/*
	 * @brief Opcao de fazer a viagem de menor custo entre duas cidades
	 */
	void fazerViagemMenorCusto2Cidades();
	/*
	 * @brief Opcao de fazer a viagem mais rapida entre duas cidades
	 */
	void fazerViagemRapida2Cidades();
	/*
	 * @brief Opcao de fazer a viagem de menor custo entre determinado tempo limite
	 */
	void fazerViagemMenorCustoEntreLimite();
	/*
	 * @brief Opcao de fazer a viagem de menor custo entre varios destinos
	 */
	void fazerViagemMenorcustoDestinos();
	/*
	 * @brief Opcao de fazer a viagem mais rapida entre varios destinos desordenados
	 */
	void fazerViagemMaisRapidaDestinos();
	/*
	 * @brief  Opcao de fazer a viagem mais rapida entre varios ordenados ordenados
	 */
	void fazerViagemMenorcustoDestinosOrdenados();
	/*
	 * @brief Opcao de fazer a viagem mais rapida entre destinos ordenados
	 */
	void fazerViagemMaisRapidaDestinosOrdenados();
	/*
	 * @brief Opcao de mostrar todas as cidades disponiveis
	 */
	void mostrarCidadesDisponiveis();
	/*
	 * @brief Opcao de mostrar os alojamentos de uma cidade
	 */
	void mostrarAlojamentosdeCidade();
	/*
	 * @brief Opcao de mostrar ponstos de interesse de uma cidade
	 */
	void mostrarPontosInteressedeCidade();
	/*
	 * @brief Opcao de procurar uma cidade com pontos de interesse
	 */
	void procurarCidadecomPontoInteresse();
	/*
	 * @brief Opcao de mostrar o grafo de cidades
	 */
	void mostrarGrafo();
	/*
	 * @brief Opcao de avaliar a conectividade do grafo
	 */
	void connectivity();
	/*
	 * @brief Opcao de fazer viagem quando o utilizador indica pontos de interesse
	 */
	void fazerViagemPontosDeInteresse();

};


class OpcaoErrada {
public:
	/*
	 * @brief Imprime mensagem de erro de opcao
	 */
	int alertaErro() {
		cout << "Opcao errada, tente outra vez" << endl;
		return 1;
	}
	;
};


#endif /* MENU_H_ */
