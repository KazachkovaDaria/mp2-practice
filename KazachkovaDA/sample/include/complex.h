#include <iostream>
struct Complex {
	float re;
	float im;
	Complex();
	Complex(float, float);
	Complex operator + (const Complex&) const;//const в конце - метод не изменяет объект, для которого вызван
	Complex operator - (const Complex&) const;
	Complex operator * (const Complex&) const;
	Complex operator / (const Complex&) const;
	bool operator == (const Complex&) const;
	bool operator != (const Complex&) const;
	const Complex& operator = (const Complex&);
	const Complex& operator += (const Complex&);
	Complex& operator++();
	Complex& operator++(int);
	Complex& operator --();
	Complex& operator--(int);
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
};
