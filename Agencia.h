#ifndef AGENCIA_H_
#define AGENCIA_H_

#include <algorithm>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include "Graph.h"
#include "Cidade.h"
#include "Hora.h"
#include "Data.h"
#include "Viagem.h"
#include "Alojamento.h"
#include "matcher.h"

using namespace std;

class Agencia {
	string nome;
	Graph<Cidade> mapa;
public:

	/**
	 * @brief Cria agencia vazia
	 */
	Agencia();

	/**
	 * @brief Cria agencia
	 * @param nome - Nome da agencia
	 * @param grp - Grafo de cidades utilizado pela agencia
	 */
	Agencia(string nome, Graph<Cidade> grp);

	/**
	 * @brief Obtem o mapa
	 * @return retorno o grafo representando o mapa sobre a qual a agencia trabalha
	 */
	Graph<Cidade> getMapa();

	/**
	 * @brief Define o mapa
	 * @param m - Grafo sobre a qual a agencia trabalhara
	 */
	void setMapa(Graph<Cidade> m);

	/**
	 * @brief Faz a viagem mais barata entre cidades
	 * @param origem - Cidade origem da viagem
	 * @param destino - Cidade destino da viagem
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 * @return A viagem entre origem e destino
	 */
	Viagem fazerViagemMenorCusto(Cidade* origem, Cidade* destino, Data d,
			Hora h, int nrPesso, int estrelas);

	/**
	 * @brief Faz a viagem mais rapida entre cidades
	 * @param origem - Cidade origem da viagem
	 * @param destino - Cidade destino da viagem
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 * @return A viagem entre origem e destino
	 */
	Viagem fazerViagemMaisRapida(Cidade* origem, Cidade* destino, Data d,
			Hora h, int nrPesso, int estrelas);

	/**
	 * @brief Faz a viagem mais barata entre cidades num certo tempo limite
	 * @param origem - Cidade origem da viagem
	 * @param destino - Cidade destino da viagem
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param limite - Duracao maxima da viagem
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 * @return A viagem entre origem e destino
	 */
	Viagem fazerViagemMenorCustoDentroTempo(Cidade* origem, Cidade* destino,
			Data d, Hora h, int nrPesso, int limite, int estrelas);

	/**
	 * @brief Mostra o itinerario entre uma cidade origem e destino
	 * @param ori - Cidade origem da viagem
	 * @param dest - Cidade destino da viagem
	 */
	void obterItinerarioViagemMenorCusto(Cidade ori, Cidade dest);

	/**
	 * @brief Faz a viagem mais barata entre as varias cidades dadas
	 * @param loc - Vetor com as cidades pretendidas
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 */
	void fazerViagemMenorcustoDestinos(vector<Cidade> loc, Data d, Hora h,
			int nrPesso, int estrelas);

	/**
	 * @brief Faz a viagem mais rapida entre as varias cidades dadas
	 * @param loc - Vetor com as cidades pretendidas
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 */
	void fazerViagemMaisRapidaDestinos(vector<Cidade> loc, Data d, Hora h,
			int nrPesso, int estrelas);

	/**
	 * @brief Faz a viagem mais barata entre as varias cidades dadas por ordem
	 * @param loc - Vetor com as cidades pretendidas
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 */
	void fazerViagemMenorcustoDestinosOrde(vector<Cidade> loc, Data d, Hora h,
			int nrPesso, int estrelas);

	/**
	 * @brief Faz a viagem mais rapida entre as varias cidades dadas por ordem
	 * @param loc - Vetor com as cidades pretendidas
	 * @param d - Data na qual a viagem se realiza
	 * @param h - Hora na qual a viagem se realiza
	 * @param nrPesso - Nr de pessoas que viajam
	 * @param estrelas - Nr de estrelas do hotel (ou valor pre-definido para estas)
	 */
	void fazerViagemMaisRapiDestinosOrde(vector<Cidade> loc, Data d, Hora h,
			int nrPesso, int estrelas);

	/**
	 * @brief Procura em que cidade se encontra o ponto de interesse dado ou pontos de interesse com nome semelhante
	 * @param ponto - Ponto de interesse pretendido
	 */
	void procuraPontoInteresse(string ponto);

};

#endif /* Agencia_H_ */
