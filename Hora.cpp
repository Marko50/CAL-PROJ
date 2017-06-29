#include "Hora.h"

Hora::Hora() {
}

Hora::Hora(int hor, int mi) {
	if (hor < 0 || hor > 23)
		throw HoraInvalida();
	if (mi < 0 || mi > 59)
		throw HoraInvalida();

	hora = hor;
	min = mi;
}

int Hora::getHora() const {
	return hora;
}

int Hora::getMin() const {
	return min;
}

bool Hora::operator <(Hora d2) {

	if (this->hora < d2.getHora())
		return true;
	else if (this->hora == d2.getHora() && this->min < d2.getMin())
		return true;
	else
		return false;

}

ostream & operator <<(ostream &os, const Hora &d) {

	os << d.getHora() << ":" << d.getMin();
	return os;

}

