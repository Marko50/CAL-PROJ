#ifndef MATCHER_H_
#define MATCHER_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>
#include <climits>

using namespace std;

#define MODIFICATIONS_MAX 2

void pre_kmp(string pattern, vector<int> & prefix);


bool kmp(string text, string pattern);


string numStringMatching(string filename,string toSearch, bool &encontrado);


int editDistance(string pattern, string text);

vector<string> numWords(string text);

map<string, string> numApproximateStringMatching(string filename,string toSearch);

#endif /* MATCHER_H_ */
