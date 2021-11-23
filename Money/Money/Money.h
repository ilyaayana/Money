#pragma once

#include <iostream>

using namespace std;

class Money
{
	long long m_half_pens;
	Money(long long);
	void setHalf_pens(long long);
public:
	Money(long long , short, double);
	Money();
	friend ostream& operator<<(ostream&,const Money&);
	friend istream& operator>>(istream&,  Money&);
	Money operator+(const Money&) const;
	Money operator-(const Money&) const;
	Money operator-() const;
	Money operator+=(const Money&);
	Money operator-=(const Money& );
	bool operator<(const Money&);
	bool operator>(const Money&);
	bool operator<=(const Money&);
	bool operator>=(const Money&);
	bool operator ==(const Money&);
	bool operator !=(const Money&);
};

