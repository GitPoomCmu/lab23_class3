#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0){
	real = x; imag = y;
}

double ComplexNumber::abs(){
    return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
	double a =atan2(imag,real)*57.2957795;
	return a; 
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}
ComplexNumber operator+(double num, const ComplexNumber &c){
    return ComplexNumber(c.real+num, c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber operator-(double num, const ComplexNumber &c){
    return ComplexNumber(num-c.real, 0-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber(((real)*(c.real))-((imag)*(c.imag)),((real)*(c.imag))+((c.real)*(imag)));
}
ComplexNumber operator*(double num, const ComplexNumber &c){
    return ComplexNumber(c.real*num, c.imag*num);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber((((real)*(c.real))+((imag)*(c.imag)))/(pow(c.real,2)+pow(c.imag,2)),(((c.real)*(imag))-((real)*(c.imag)))/((pow(c.real,2)+pow(c.imag,2))));
}
ComplexNumber operator/(double s, const ComplexNumber &c){
    return ComplexNumber((((s)*(c.real))+((0)*(c.imag)))/(pow(c.real,2)+pow(c.imag,2)),(((c.real)*(0))-((s)*(c.imag)))/((pow(c.real,2)+pow(c.imag,2))));
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real == c.real && imag == c.imag) return true;
	else return false;
}
bool operator==(double num, const ComplexNumber &c){
	if(num == c.real && num == c.imag) return true;
	else return false;
}

ostream & operator <<(ostream &os , const ComplexNumber &c){
	if(c.imag <0){
		if(c.real == 0)return os << c.imag << "i";
		else return os << c.real << c.imag << "i";
	}
	if(c.imag == 0)return os << c.real;
	if(c.imag > 0){
		if(c.real == 0)return os << c.imag << "i";
		else return os << c.real << "+" << c.imag << "i";
	}
	return os;
}
