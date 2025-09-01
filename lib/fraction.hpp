#pragma once
#include <iostream>
#include <vector>
class Fraction{
  private:
    int numerator;
    int denominator;
       
  public:
    Fraction(int n=1, int d=1): numerator(n), denominator(d) {}
    
    Fraction operator+(const Fraction& f);
    Fraction operator-(const Fraction& f);
    Fraction operator/(const Fraction& f);
    Fraction operator*(const Fraction& f);


    Fraction& operator++();
    Fraction& operator--();
    
    Fraction operator++(int);
    Fraction operator--(int);

    std::string toString();

    static std::vector<Fraction> normalize(const Fraction& f1, const Fraction& f2);
    static void simplify(Fraction& f);
};
