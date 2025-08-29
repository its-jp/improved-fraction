#pragma once
#include <iostream>

class Fraction{
  private:
    int numerator;
    int denominator;

    void simplify();
   
  public:
    Fraction(int n=0, int d=1): numerator(n), denominator(d) {}
    
    Fraction operator+(Fraction f);
    Fraction operator-(Fraction f);
    Fraction operator/(Fraction f);
    Fraction operator*(Fraction f);


    Fraction& operator++();
    Fraction& operator--();
    
    Fraction operator++(int);
    Fraction operator--(int);

    std::string toString();
};
