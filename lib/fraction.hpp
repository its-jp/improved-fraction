#pragma once
#include <iostream>
#include <vector>
class Fraction{
  private:
    int numerator;
    int denominator;
       
  public:
    Fraction(int n=1, int d=1): numerator(n), denominator(d) {} //they are being initialized, not an assignment!
    
    Fraction operator+(const Fraction& f) const; //const at the end of the method allow a const this given object to call it!
    Fraction operator-(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;


    Fraction& operator++();
    Fraction& operator--();
    
    Fraction operator++(int);
    Fraction operator--(int);
    
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    std::string toString();
    
    static std::vector<Fraction> normalize(const Fraction& f1, const Fraction& f2);
    static void simplify(Fraction& f);
    static int removeSignal(const int num);
};
