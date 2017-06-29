#include "Data.h"

using namespace std;

Data::Data(int d, int m) {

	if (m > 12 || m < 1)
		throw DataInvalida();
	if (m == 2) {
		if (d > 29)
			throw DataInvalida();
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d < 1 || d > 30)
			throw DataInvalida();
	} else if (d < 1 || d > 31)
		throw DataInvalida();

	time_t now;
	time(&now);

	tm *ltm = localtime(&now);

	dia = d;
	mes = m;
	ano = ltm->tm_year + 1900;

}

Data::Data(int d, int m, int a) {
	if (m > 12 || m < 1)
		throw DataInvalida();
	if (m == 2) {
		if (d > 29)
			throw DataInvalida();
	}
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d < 1 || d > 30)
			throw DataInvalida();
	} else if (d < 1 || d > 31)
		throw DataInvalida();

	dia = d;
	mes = m;
	ano = a;
}

int Data::getAno() const {
	return ano;
}

int Data::getMes() const {
	return mes;
}

int Data::getDia() const {
	return dia;
}

bool Data::operator <(Data d2) {

	if (this->ano < d2.getAno())
		return true;
	else if (this->ano == d2.getAno() && this->mes < d2.getMes())
		return true;
	else if (this->ano == d2.getAno() && this->mes == d2.getMes()
			&& this->dia < d2.getDia())
		return true;
	else
		return false;
}

bool Data::operator <=(Data d2) {

	if (this->mes <= d2.getMes())
		return true;
	else if (this->mes == d2.getMes() && this->dia <= d2.getDia())
		return true;
	else
		return false;
}

ostream & operator <<(ostream &os, const Data &d) {

	os << d.getDia() << "/" << d.getMes() << "/" << d.getAno();
	return os;

}

