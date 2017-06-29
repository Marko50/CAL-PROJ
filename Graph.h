/*
 * Graph.h, onde a maioria das funcoes foi retirada das solucoes das aulas TP de CAL
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <cmath>
#include <sstream>
#include <iostream>
#include "Viagem.h"
using namespace std;

template<class T> class Edge;
template<class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;
/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template<class T>
class Vertex {
	T info;
	vector<Edge<T> > adj;
	bool visited;
	bool processing;
	int indegree;
	double dist;
	bool queueIndex = false;
	int duracao;
public:

	Vertex(T in);
	friend class Graph<T> ;
	void addEdge(Vertex<T> *dest, double w);
	void addEdge(Vertex<T> *dest, double w, int dur);
	bool removeEdgeTo(Vertex<T> *d);
	T getInfo() const;
	void setInfo(T info);
	double getDist() const;
	int getIndegree() const;
	Vertex* path;
	int getDuracao() const;
};

template<class T>
struct vertex_greater_than {
	bool operator()(Vertex<T> * a, Vertex<T> * b) const {
		return a->getDist() > b->getDist();
	}
};

template<class T>
struct vertex_faster_than {
	bool operator()(Vertex<T> * a, Vertex<T> * b) const {
		return a->getDuracao() > b->getDuracao();
	}
};

template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it = adj.begin();
	typename vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

//atualizado pelo exercício 5
template<class T>
Vertex<T>::Vertex(T in) :
		info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest, w);
	adj.push_back(edgeD);
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w, int dur) {
	Edge<T> edgeD(dest, w, dur);
	adj.push_back(edgeD);
}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template<class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template<class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

template<class T>
int Vertex<T>::getDuracao() const {
	return this->duracao;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template<class T>
class Edge {
	Vertex<T> * dest;
	double weight;
	int duracao;
public:
	Edge(Vertex<T> *d, double w);
	Edge(Vertex<T> *d, double w, int dur);
	friend class Graph<T> ;
	friend class Vertex<T> ;
};

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w) :
		dest(d), weight(w), duracao(0) {
}

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w, int dur) :
		dest(d), weight(w), duracao(dur) {
}

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template<class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;

	//exercicio 5
	int numCycles;
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();
	void getPathTo(Vertex<T> *origin, list<T> &res);

public:
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool addEdge(const T &sourc, const T &dest, double w, int dur);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> *> getVertexSet() const;
	int getNumVertex() const;

	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
	int getNumCycles();
	vector<T> topologicalOrder();
	vector<T> getPath(const T &origin, const T &dest);
	void unweightedShortestPath(const T &v);
	bool isDAG();
	void bellmanFordShortestPath(const T &s);
	void dijkstraShortestPath(const T &s);

	double travelShortestPath(const T &s, const T &dest, int &duracao);
	vector<T> LocationsShortestPathUnorderedGreedy(vector<T> &locations,
			int &duracao, int &custo, stringstream &ss);
	vector<T> LocationsShortestPathOrdered(vector<T> &locations, int &duracao,
			int &custo, stringstream &ss);
	vector<T> LocationsFastestPathUnorderedGreedy(vector<T> &locations,
			int &duracao, int &custo, stringstream &ss);
	vector<T> LocationsFastestPathOrdered(vector<T> &locations, int &duracao,
			int &custo, stringstream &ss);
	int travelFastestPath(const T &s, const T &dest, double &custo);
	int PathWithinTime(const T &s, const T &dest, int duracao, double &custo);
	bool testConnectivity();


};

template<class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template<class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

template<class T>
int Graph<T>::getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}

template<class T>
bool Graph<T>::isDAG() {
	return (getNumCycles() == 0);
}

template<class T>
bool Graph<T>::addVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in)
			return false;
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);
	return true;
}

template<class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) {
			Vertex<T> * v = *it;
			vertexSet.erase(it);
			typename vector<Vertex<T>*>::iterator it1 = vertexSet.begin();
			typename vector<Vertex<T>*>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename vector<Edge<T> >::iterator itAdj = v->adj.begin();
			typename vector<Edge<T> >::iterator itAdje = v->adj.end();
			for (; itAdj != itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++;
	vS->addEdge(vD, w);

	return true;
}

template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w, int dur) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++;
	vS->addEdge(vD, w, dur);

	return true;
}

template<class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template<class T>
vector<T> Graph<T>::dfs() const {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	vector<T> res;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfs(*it, res);
	return res;
}

template<class T>
void Graph<T>::dfs(Vertex<T> *v, vector<T> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T> >::iterator it = (v->adj).begin();
	typename vector<Edge<T> >::iterator ite = (v->adj).end();
	for (; it != ite; it++)
		if (it->dest->visited == false) {
			dfs(it->dest, res);
		}
}

template<class T>
vector<T> Graph<T>::bfs(Vertex<T> *v) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge<T> >::iterator it = v1->adj.begin();
		typename vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}
	return res;
}

template<class T>
int Graph<T>::maxNewChildren(Vertex<T> *v, T &inf) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	queue<int> level;
	int maxChildren = 0;
	inf = v->info;
	q.push(v);
	level.push(0);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l = level.front();
		level.pop();
		l++;
		int nChildren = 0;
		typename vector<Edge<T> >::iterator it = v1->adj.begin();
		typename vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}
		if (nChildren > maxChildren) {
			maxChildren = nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}

template<class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v)
			return vertexSet[i];
	return NULL;
}

template<class T>
void Graph<T>::resetIndegrees() {
	//colocar todos os indegree em 0;
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		vertexSet[i]->indegree = 0;

	//actualizar os indegree
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		//percorrer o vector de Edges, e actualizar indegree
		for (unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].dest->indegree++;
		}
	}
}

template<class T>
vector<Vertex<T>*> Graph<T>::getSources() const {
	vector<Vertex<T>*> buffer;
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->indegree == 0)
			buffer.push_back(vertexSet[i]);
	}
	return buffer;
}

template<class T>
void Graph<T>::dfsVisit() {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfsVisit(*it);
}

template<class T>
void Graph<T>::dfsVisit(Vertex<T> *v) {
	v->processing = true;
	v->visited = true;
	typename vector<Edge<T> >::iterator it = (v->adj).begin();
	typename vector<Edge<T> >::iterator ite = (v->adj).end();
	for (; it != ite; it++) {
		if (it->dest->processing == true)
			numCycles++;
		if (it->dest->visited == false) {
			dfsVisit(it->dest);
		}
	}
	v->processing = false;
}

template<class T>
vector<T> Graph<T>::topologicalOrder() {
	//vector com o resultado da ordenacao
	vector<T> res;

	//verificar se é um DAG
	if (getNumCycles() > 0) {
		cout << "Ordenacao Impossivel!" << endl;
		return res;
	}

	//garantir que os "indegree" estao inicializados corretamente
	this->resetIndegrees();

	queue<Vertex<T>*> q;

	vector<Vertex<T>*> sources = getSources();
	while (!sources.empty()) {
		q.push(sources.back());
		sources.pop_back();
	}

	//processar fontes
	while (!q.empty()) {
		Vertex<T>* v = q.front();
		q.pop();

		res.push_back(v->info);

		for (unsigned int i = 0; i < v->adj.size(); i++) {
			v->adj[i].dest->indegree--;
			if (v->adj[i].dest->indegree == 0)
				q.push(v->adj[i].dest);
		}
	}

	//testar se o procedimento foi bem sucedido
	if (res.size() != vertexSet.size()) {
		while (!res.empty())
			res.pop_back();
	}

	//garantir que os "indegree" ficam atualizados ao final
	this->resetIndegrees();

	return res;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) {

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);
	buffer.push_front(v->info);
	while (v->path != NULL && v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if (v->path != NULL) {
		buffer.push_front(v->path->info);
	}
	vector<T> res;
	while (!buffer.empty()) {
		res.push_back(buffer.front());
		buffer.pop_front();
	}
	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &s) {

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	queue<Vertex<T>*> q;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (w->dist == INT_INFINITY) {
				w->dist = v->dist + 1;
				w->path = v;
				q.push(w);
			}
		}
	}
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &s) {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	queue<Vertex<T>*> q;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (w->dist > v->dist + v->adj[i].weight) {
				w->dist = v->dist + v->adj[i].weight;
				w->path = v;
				q.push(w);
			}
		}
	}
}

template<class T>
void Graph<T>::dijkstraShortestPath(const T &s) {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->visited = false;
	}

	vector<Vertex<T>*> aux;

	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	aux.push_back(v);

	make_heap(aux.begin(), aux.end(), vertex_greater_than<T>());
	while (!aux.empty()) {

		v = aux.front();
		pop_heap(aux.begin(), aux.end());
		aux.pop_back();

		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;

			if (v->dist + v->adj[i].weight < w->dist) {
				w->dist = v->dist + v->adj[i].weight;
				w->path = v;
				if (w->visited == false) {
					aux.push_back(w);
					w->visited = true;
				}
			}
		}

		make_heap(aux.begin(), aux.end(), vertex_greater_than<T>());
	}
}

template<class T>
double Graph<T>::travelShortestPath(const T &s, const T &dest, int &duracao) {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->duracao = INT_INFINITY;
		vertexSet[i]->visited = false;
	}
	vector<Vertex<T>*> aux;
	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	v->duracao = 0;
	aux.push_back(v);
	make_heap(aux.begin(), aux.end(), vertex_greater_than<T>());
	while (!aux.empty()) {
		v = aux.front();
		pop_heap(aux.begin(), aux.end());
		aux.pop_back();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (v->dist + v->adj[i].weight < w->dist) {
				w->dist = v->dist + v->adj[i].weight;
				w->duracao = v->duracao + v->adj[i].duracao;
				w->path = v;
				if (w->visited == false) {
					aux.push_back(w);
					w->visited = true;
				}
			}
		}
		make_heap(aux.begin(), aux.end(), vertex_greater_than<T>());
	}

	duracao = this->getVertex(dest)->getDuracao();
	return this->getVertex(dest)->getDist();
}

template<class T>
vector<T> Graph<T>::LocationsShortestPathUnorderedGreedy(vector<T>& locations,
		int& duracao, int &custo, stringstream &ss) {
	vector<T> aux;
	vector<T> aux2;
	int dur2 = 0;
	int dur3 = 0;
	aux.push_back(locations.at(0));
	T temp3;
	double temp = INT_MAX;
	double temp2;
	int indOrigem = 0;
	for (unsigned int i = 0; i < locations.size() - 1; i++) {
		for (unsigned int j = i + 1; j < locations.size(); j++) {
			temp2 = travelShortestPath(locations.at(i), locations.at(j), dur3);
			if (temp2 <= temp) {
				dur2 = dur3;
				temp = temp2;
				indOrigem = j;
				temp3 = locations.at(j);
				aux2 = this->getPath(locations.at(i), temp3);
			}
		}
		duracao += dur2;
		custo += temp;
		aux2.erase(aux2.begin());
		for (unsigned int z = 0; z < aux2.size(); z++) {
			aux.push_back(aux2.at(z));
		}
		locations.erase(locations.begin() + indOrigem);
		locations.insert(locations.begin() + (i + 1), temp3);
		temp = INT_MAX;
	}

	ss << "Itinerario da viagem: ";

	for (unsigned int i = 0; i < aux.size(); i++) {
		if (i == aux.size() - 1)
			ss << aux.at(i);
		else
			ss << aux.at(i) << " -> ";
	}

	return aux;
}

template<class T>
vector<T> Graph<T>::LocationsShortestPathOrdered(vector<T>& locations,
		int &duracao, int &custo, stringstream &ss) {
	vector<T> aux;
	aux.push_back(locations.at(0));
	double c;
	for (unsigned int i = 0; i < locations.size() - 1; i++) {
		int dur;
		c = this->travelShortestPath(locations.at(i), locations.at(i + 1), dur);
		vector<T> aux2 = this->getPath(locations.at(i), locations.at(i + 1));
		duracao += dur;
		custo += c;
		for (unsigned int z = 1; z < aux2.size(); z++) {
			aux.push_back(aux2.at(z));
		}
	}

	ss << "Itinerario da viagem: ";
	for (unsigned int z = 0; z < aux.size(); z++) {
		if (z == aux.size() - 1)
			ss << aux.at(z);
		else
			ss << aux.at(z) << " -> ";
	}

	return aux;
}

template<class T>
vector<T> Graph<T>::LocationsFastestPathUnorderedGreedy(vector<T>& locations,
		int& duracao, int &custo, stringstream &ss) {
	vector<T> aux;
	vector<T> aux2;
	int dur2 = INT_MAX;
	int dur3 = INT_MAX;
	aux.push_back(locations.at(0));
	T temp3;
	double temp = INT_MAX;
	double temp2;
	int indOrigem = 0;
	for (unsigned int i = 0; i < locations.size() - 1; i++) {
		for (unsigned int j = i + 1; j < locations.size(); j++) {
			dur3 = travelFastestPath(locations.at(i), locations.at(j), temp2);
			if (dur3 <= dur2) {
				dur2 = dur3;
				temp = temp2;
				indOrigem = j;
				temp3 = locations.at(j);
				aux2 = this->getPath(locations.at(i), temp3);
			}
		}
		duracao += dur2;
		custo += temp;
		aux2.erase(aux2.begin());
		for (unsigned int z = 0; z < aux2.size(); z++) {
			aux.push_back(aux2.at(z));
		}
		locations.erase(locations.begin() + indOrigem);
		locations.insert(locations.begin() + (i + 1), temp3);
		temp = INT_MAX;
		dur2 = INT_MAX;
	}

	ss << "Itinerario da viagem: ";

	for (unsigned int i = 0; i < aux.size(); i++) {
		if (i == aux.size() - 1)
			ss << aux.at(i);
		else
			ss << aux.at(i) << " -> ";
	}

	return aux;
}

template<class T>
vector<T> Graph<T>::LocationsFastestPathOrdered(vector<T>& locations,
		int &duracao, int &custo, stringstream &ss) {
	vector<T> aux;
	aux.push_back(locations.at(0));
	double c;
	for (unsigned int i = 0; i < locations.size() - 1; i++) {
		int dur;
		dur = this->travelFastestPath(locations.at(i), locations.at(i + 1), c);
		vector<T> aux2 = this->getPath(locations.at(i), locations.at(i + 1));
		duracao += dur;
		custo += c;
		for (unsigned int z = 1; z < aux2.size(); z++) {
			aux.push_back(aux2.at(z));
		}
	}

	ss << "Itinerario da viagem: ";
	for (unsigned int z = 0; z < aux.size(); z++) {
		if (z == aux.size() - 1)
			ss << aux.at(z);
		else
			ss << aux.at(z) << " -> ";
	}

	return aux;
}

template<class T>
int Graph<T>::travelFastestPath(const T &s, const T &dest, double &custo) {

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->duracao = INT_INFINITY;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->visited = false;
	}
	vector<Vertex<T>*> aux;
	Vertex<T>* v = getVertex(s);
	v->duracao = 0;
	v->dist = 0;
	aux.push_back(v);
	make_heap(aux.begin(), aux.end(), vertex_faster_than<T>());
	while (!aux.empty()) {
		v = aux.front();
		pop_heap(aux.begin(), aux.end());
		aux.pop_back();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (v->duracao + v->adj[i].duracao < w->duracao) {
				w->duracao = v->duracao + v->adj[i].duracao;
				w->dist = v->dist + v->adj[i].weight;
				w->path = v;
				if (w->visited == false) {
					aux.push_back(w);
					w->visited = true;
				}
			}
		}
		make_heap(aux.begin(), aux.end(), vertex_faster_than<T>());
	}

	custo = this->getVertex(dest)->getDist();
	return this->getVertex(dest)->getDuracao();
}

template<class T>
int Graph<T>::PathWithinTime(const T &s, const T &dest, int duracao,
		double &custo) {

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->duracao = INT_INFINITY;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->visited = false;
	}
	vector<Vertex<T>*> aux;
	Vertex<T>* v = getVertex(s);
	v->duracao = 0;
	v->dist = 0;
	aux.push_back(v);
	make_heap(aux.begin(), aux.end(), vertex_greater_than<T>());
	while (!aux.empty()) {
		v = aux.front();
		pop_heap(aux.begin(), aux.end());
		aux.pop_back();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (v->duracao + v->adj[i].duracao <= duracao
					&& v->dist + v->adj[i].weight < w->dist) {
				w->duracao = v->duracao + v->adj[i].duracao;
				w->dist = v->dist + v->adj[i].weight;
				w->path = v;
				if (w->visited == false) {
					aux.push_back(w);
					w->visited = true;
				}
			}
		}
		make_heap(aux.begin(), aux.end(), vertex_greater_than<T>());
	}

	custo = this->getVertex(dest)->getDist();
	int dur = this->getVertex(dest)->getDuracao();
	if (dur > duracao)
		throw ViagemInvalida();

	else
		return dur;
}



template<class T>
bool Graph<T>::testConnectivity(){

	unsigned int num = vertexSet.size();

	for (unsigned int i = 0; i < num; i++) {
			vertexSet[i]->visited = false;
		}

	for (unsigned int i = 0; i < num; i++) {
		unsigned int comp = this->bfs(vertexSet[i]).size();
		//cout<<"Comp de: "<<vertexSet[i]->info<<" "<<comp<<endl;
		if(num > comp )
			return false;

		for (unsigned int i = 0; i < num; i++) {
					vertexSet[i]->visited = false;
				}
	}

return true;
}

#endif /* GRAPH_H_ */
