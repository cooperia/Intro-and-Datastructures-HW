#include "Complex.h"


Complex::Complex(double real,double imag) {
  _real = real;
  _imag = imag;
}

Complex::Complex() {
  _real = 0;
  _imag = 0;
}

double Complex::RealPart() const {
  return _real;
}

void Complex::SetRealPart(double real) {
  _real = real;

}

double Complex::ImagPart() const {
  return _imag;
}

void Complex::SetImagPart(double imag) {
  _imag= imag;
}


Complex operator+(const Complex& z,const Complex& w) {
  Complex v; //this will hold the sum
  v.SetRealPart(z.RealPart() + w.RealPart());
  v.SetImagPart(z.ImagPart() + w.ImagPart());
  return v;
}

Complex operator-(const Complex& z) {
  Complex v(-z._real,-z._imag);
  return v;
}
