#include <iostream>
struct Complex {
	float re;
	float im;
	Complex(float, float);
	Complex operator + (const Complex&) const;
	Complex operator - (const Complex&) const;
	Complex operator * (const Complex&) const;
	Complex operator / (const Complex&) const;
	bool operator == (const Complex&) const;
	bool operator != (const Complex&) const;
	const Complex& operator = (const Complex&);
	const Complex& operator += (const Complex&);
	Complex& operator++();
	Complex& operator --();
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istringstream is, Complex& c);
};
