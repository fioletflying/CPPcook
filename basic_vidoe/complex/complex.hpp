#ifndef __COMPLEX__
#define __COMPLEX__

#include<iostream>
using namespace std;



complex& __doapl(complex *, const complex &);

class complex
{

public:
    complex(double r = 0, double i = 0):real(r),imag(i){}

    double get_real() const{return real;} 
    double get_imag() const{return imag;}

public:

    complex & operator+=(const complex& rhs);
    // complex& operator += (const complex& rhs)
    // {
    //     this->real += rhs.real;
    //     this->imag += rhs.imag;

    //     return *this;
    // }

    // complex operator + (const complex rhs)
    // {
    //     return complex( real+ rhs.real, imag + rhs.imag);
    // }

    // complex operator+ (double a)
    // {
    //     return complex( real + a, imag);
    // }

    // 这个是无法实现成员函数，因为操作符作用在类的左边
    // 一般操作符作用在类的右边的时候可以考虑使用成员函数来实现
    // complex operator-()
    // {
    //     return complex(-this->real, -this->imag);
    // }

    // bool operator ==(const complex& rhs)
    // {
    //     return (this->real == rhs.real && this->imag == rhs.imag);
    // }





private:
	double real;
	double imag;

    friend complex& __doapl(complex*, const complex &);
// friend complex __doapl(complex)
};

inline complex& complex::operator+=(const complex& rhs)
{
    return __doapl(this, rhs);
}

complex& __doapl(complex *lhs, const complex& rhs)
{
    lhs->real += rhs.real;
    lhs->imag += rhs.imag;

    return *lhs;
}

complex operator- (const complex& rhs)
{
    return complex(- rhs.get_real(), - rhs.get_imag());
}

bool operator== (const complex& lhs, const complex& rhs)
{
    return (lhs.get_real() == rhs.get_real() && lhs.get_imag() == rhs.get_imag());
}

inline complex operator+ (const complex& a, const complex& b)
{
    return complex( a.get_real() + b.get_real(), a.get_imag() + b.get_imag());
}

complex operator+( const complex& a, double b)
{
    return complex(a.get_real() + b, a.get_imag() );
}

complex operator+ ( double b, const complex& a)
{
    return complex(a.get_real() + b, a.get_imag() );
}

ostream& operator<< (ostream& os, const complex & rhs)
{
    return os << "(" << rhs.get_real() << "," << rhs.get_imag() << ")";
    
}

#endif