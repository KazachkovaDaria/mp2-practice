#include "complex.h"

Complex::Complex() : re(0.0), im(0.0) {};
Complex::Complex(float _re, float _im) : re(_re), im(_im) {};
Complex Complex::operator + (const Complex& c) const
{
	return Complex (re + c.re, im + c.im);
}

Complex Complex::operator - (const Complex& c) const
{
	return Complex(re - c.re, im - c.im);
}

Complex Complex::operator * (const Complex& c) const
{
	return Complex(re*c.re - im*c.im, re*c.im + c.re*im);
}

Complex Complex::operator / (const Complex& c) const
{
	return Complex((re * c.re + im * c.im)/(c.re*c.re+c.im*c.im),
		(im*c.re-re*c.im)/ (c.re * c.re + c.im * c.im));
}

bool Complex::operator == (const Complex& c) const
{
	return ((re == c.re) && (im == c.im));
}

bool Complex::operator != (const Complex& c) const
{
	return ((re != c.re) && (im != c.im));
}

const Complex& Complex::operator = (const Complex& c)
{
	if (this == &c)
		return *this;
	if (re != c.re)
		re = c.re;
	if (im != c.im)
		im = c.im;
	return *this;
}
const Complex& Complex::operator += (const Complex& c)//через полученную ссылку нельзя будет изменить объект
{
	re += c.re;
	im += c.im;
	return *this;
}

Complex& Complex::operator++()
{
	re += 1;
	return *this;
}

Complex& Complex::operator++(int)
{
	Complex old = *this;
	re += 1;
	return old;
}

Complex& Complex::operator --()
{
	re -= 1;
	return *this;
}

Complex& Complex::operator--(int)
{
	Complex old = *this;
	re -= 1;
	return old;
}
std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << c.re;
	if (c.im < 0)
		os << "-" << c.im << "i";
	if (c.im > 0)
		os << "+" << c.im << "i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
	is >> c.re >> c.im;
	return is;
}