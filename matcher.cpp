#include "matcher.h"

void pre_kmp(string pattern, vector<int> & prefix) {
	int m = pattern.length();
	prefix[0] = -1;
	int k = -1;
	for (int q = 1; q < m; q++) {
		while (k > -1 && pattern[k + 1] != pattern[q])
			k = prefix[k];
		if (pattern[k + 1] == pattern[q])
			k = k + 1;
		prefix[q] = k;
	}
}

bool kmp(string text, string pattern) {
	int num = 0;
	int m = pattern.length();
	vector<int> prefix(m);
	pre_kmp(pattern, prefix);

	int n = text.length();

	int q = -1;
	for (int i = 0; i < n; i++) {
		while (q > -1 && pattern[q + 1] != text[i])
			q = prefix[q];
		if (pattern[q + 1] == text[i]) {
			q++;
		}
		if (q == m - 1) {
			//cout <<"pattern occurs with shift" << i-m+1 << endl;
			num++;
			q = prefix[q];
		}
	}
	 if(num!=0)
		 return true;
	 else
		 return false;
}


string numStringMatching(string filename, string toSearch, bool &encontrado) {
	ifstream fich(filename.c_str());
	if (!fich) {
		cout << "Erro a abrir ficheiro de leitura\n";
		return 0;
	}

	string ponto, cidade;

	while (!fich.eof()) {
		getline(fich, ponto, ';');
		getline(fich, cidade);
		/*if(ponto==toSearch)
			encontrado=true;*/
		encontrado = kmp(toSearch, ponto);
		if(encontrado)
			break;
	}
	fich.close();
	return cidade;
}

int editDistance(string pattern, string text) {
	int n = text.length();
	vector<int> d(n + 1);
	int old, neww;
	for (int j = 0; j <= n; j++)
		d[j] = j;
	int m = pattern.length();
	for (int i = 1; i <= m; i++) {
		old = d[0];
		d[0] = i;
		for (int j = 1; j <= n; j++) {
			if (pattern[i - 1] == text[j - 1])
				neww = old;
			else {
				neww = min(old, d[j]);
				neww = min(neww, d[j - 1]);
				neww = neww + 1;
			}
			old = d[j];
			d[j] = neww;
		}
	}
	return d[n];
}


vector<string> numWords(string text){
	stringstream aux(text);
	vector<string> ret;
	string auxWord;
	while(!aux.eof()){
		aux >> auxWord;
		if(auxWord != "do" && auxWord != "da" && auxWord != "dos" && auxWord != "das" && auxWord != "de")
			ret.push_back(auxWord);
	}
	return ret;
}

map<string, string> numApproximateStringMatching(string filename, string toSearch) {
	map<string, string> res;
	ifstream fich(filename.c_str());
	if (!fich) {
		cout << "Erro a abrir ficheiro de leitura\n";
		return res;
	}
	string line1, word1, ponto, cidade;
	int numAux = INT_MAX;
	int numAux2 ;
	vector<string> toSearchDivided = numWords(toSearch);
	vector<string> pontoDivided;
	bool noice;
	while (!fich.eof()) {
		noice = true;
		getline(fich, ponto, ';');
		getline(fich, cidade);
		pontoDivided = numWords(ponto);
		for(unsigned int i = 0; i < toSearchDivided.size(); i++)
		{
			numAux = INT_MAX;
			for(unsigned int j = 0; j < pontoDivided.size(); j++){
				numAux2 = editDistance( toSearchDivided.at(i), pontoDivided.at(j));
				if(numAux2 < numAux){
					numAux = numAux2;
				}
			}
			if(numAux <= 1 )
			{
				noice = true;
				break;
			}
			else if(numAux > MODIFICATIONS_MAX)
			{
				noice = false;
			}
		}
		if(noice){
				res.insert(pair<string, string>(ponto, cidade));
		}
	}
	fich.close();
	return res;
}
