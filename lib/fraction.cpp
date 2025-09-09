#include "fraction.hpp"
#include <iostream>
#include <vector>

void Fraction::simplify(Fraction& f){
  //TODO: Search how to simplify a fraction in code!

}

std::vector<Fraction> Fraction::normalize(const Fraction& f1, const Fraction& f2){
  std::vector<Fraction> normalizedFractions;

  //Verify if it is already normalized
  if(f1.denominator == f2.denominator){
    normalizedFractions.push_back(Fraction(f1.numerator, f1.denominator));
    normalizedFractions.push_back(Fraction(f2.numerator, f2.denominator));
  }
  else{

    //First fraction being normalized
    normalizedFractions.push_back(
      Fraction(
        f1.numerator * f2.denominator,
        f1.denominator * f2.denominator
      )
    );
    
    //Second fraction being normalized
    normalizedFractions.push_back(
      Fraction(
        f1.numerator * f2.denominator,
        f1.denominator * f2.denominator
      )
    );
  }

  return normalizedFractions;
}
Fraction& Fraction::operator++(){
  this->numerator += this->denominator;
  return *this;
}

Fraction& Fraction::operator--(){
  this->numerator -= this->denominator;
  return *this;
}

Fraction Fraction::operator++(int){
  Fraction temp = Fraction(this->numerator, this->denominator);
  ++(*this);
  return temp;
}

Fraction Fraction::operator--(int){
  Fraction temp = Fraction(this->numerator, this->denominator);
  --(*this);
  return temp;
};

Fraction Fraction::operator+(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return Fraction(
    normalizedFractions.at(0).numerator + normalizedFractions.at(1).numerator, 
    normalizedFractions.at(0).denominator
  );
}

Fraction Fraction::operator-(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return Fraction(
    normalizedFractions.at(0).numerator - normalizedFractions.at(1).numerator,
      normalizedFractions.at(0).denominator
  );
}

Fraction Fraction::operator*(const Fraction& f) const {
  return Fraction(
    this->numerator * f.numerator,
    this->denominator * f.denominator
  );
}
Fraction Fraction::operator/(const Fraction& f) const {
  return Fraction(
    this->numerator * f.denominator,
    this->denominator * f.numerator
  );
}
//Verify if the fractions are equivalent!
bool Fraction::operator==(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return normalizedFractions.at(0).numerator == normalizedFractions.at(1).numerator;
}


bool Fraction::operator!=(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return normalizedFractions.at(0).numerator != normalizedFractions.at(1).numerator;
}


bool Fraction::operator<=(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return normalizedFractions.at(0).numerator <= normalizedFractions.at(1).numerator;
}

bool Fraction::operator>=(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return normalizedFractions.at(0).numerator >= normalizedFractions.at(1).numerator;
}

std::string Fraction::toString(){
  return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}



