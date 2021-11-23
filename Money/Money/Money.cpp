#include "Money.h"
#include <iostream>
#include <cmath>

using namespace std;

const long long MAX_POUNDS = 1000000000;
const short MAX_SHILLINGS = 20;
const short MAX_PENS = 12;

Money::Money(long long pounds, short shillings, double pens) {
	if ((abs(shillings) >= MAX_SHILLINGS) || (abs(pens) >= MAX_PENS) || ((pens / 0.5) != int(pens / 0.5)) || (abs(pounds) > MAX_POUNDS) || (abs(pounds) == MAX_POUNDS)&&(shillings || pens))
		throw exception("Wrong inputs.");
	m_half_pens = ((MAX_PENS * MAX_SHILLINGS * pounds) + (shillings * MAX_PENS) + pens) * 2 ;

}
void Money::setHalf_pens(long long half_pens) {
	if (half_pens > (MAX_SHILLINGS * MAX_POUNDS * MAX_PENS*2))
		throw exception("<Too big value>");
	m_half_pens = half_pens;
}
Money::Money():Money(0){};
Money::Money(long long half_pens) {
	setHalf_pens(half_pens);
}
ostream& operator<<(ostream& out, const Money& m) {
	if (m.m_half_pens < 0)
		out << "-";
	long long half_pens = abs(m.m_half_pens);
	long long pounds = half_pens / 2 / MAX_SHILLINGS / MAX_PENS;
	half_pens -=  MAX_SHILLINGS * MAX_PENS * pounds * 2;
	short shillings =half_pens / 2  / 12;
	half_pens -=  MAX_PENS * shillings * 2;
	if (pounds) 
		out << pounds << "pd.";
	if (shillings)
		out << shillings << "sh.";
	if((!shillings && !pounds && !half_pens) || half_pens)
	    out << half_pens/2.0 << "p.";
	return out;
}
istream& operator>>(istream& in, Money& m) {

	int pounds, shillings; double pens;
	in >> pounds >> shillings >> pens;
	m = Money(pounds,shillings,pens);
	return in;
}
Money Money::operator+(const Money& m) const {
	return Money(m_half_pens+m.m_half_pens);
}
Money Money::operator-(const Money& m) const {
	Money tmp = -m;
	return Money(this->operator+(tmp));
}
Money Money::operator-() const {
	return Money(-m_half_pens);
}
Money Money::operator+=(const Money& m) {
	
	setHalf_pens(m_half_pens + m.m_half_pens);
	return *this;
}
Money Money::operator-=(const Money& m) {
	setHalf_pens(m_half_pens - m.m_half_pens);
	return *this;
}
bool Money::operator==(const Money& m) {
	return(m_half_pens == m.m_half_pens);
}
bool Money::operator!=(const Money& m) {
	return(!this->operator==(m));
}
bool Money::operator<(const Money& m) {
	return(m_half_pens < m.m_half_pens);
}
bool Money::operator>(const Money& m) {
	return(m_half_pens > m.m_half_pens);
}
bool Money::operator<=(const Money& m) {
	return(!this->operator>(m));
}
bool Money::operator>=(const Money& m) {
	return(!this->operator<(m));
}