#include "fraction.hpp"
#include <iostream>
#include <vector>


int Fraction::removeSignal(const int n){
  int mask = n >> 31;
  return (n ^ mask) - mask;
}

void Fraction::simplify(Fraction& f){
  //TODO: Search how to simplify a fraction in code!

    int unsigned_denominator = Fraction::removeSignal(f.denominator);
  int unsigned_numerator = Fraction::removeSignal(f.numerator);
  int min_number = unsigned_denominator < unsigned_numerator ? unsigned_denominator: unsigned_numerator;
  int possible_divisor = 2;
  while(possible_divisor <= min_number){
    if(f.numerator % possible_divisor == 0 && f.denominator % possible_divisor== 0){
      f.numerator /= possible_divisor;
      f.denominator /= possible_divisor;
      min_number /= possible_divisor;
      possible_divisor = 1;
    }
    possible_divisor++;
  }
}

std::vector<Fraction> Fraction::normalize(const Fraction& f1, const Fraction& f2){
  std::vector<Fraction> normalizedFractions;
  Fraction normalizedF1;
  Fraction normalizedF2;
  //Verify if it is already normalized
  if(f1.denominator == f2.denominator){
    normalizedF1 = Fraction(f1.numerator, f1.denominator);
    normalizedF2 = Fraction(f2.numerator, f2.denominator);
    normalizedFractions.push_back(normalizedF1);
    normalizedFractions.push_back(normalizedF2);
  }
  else{

    //First fraction being normalized
    normalizedF1 = Fraction(
        f1.numerator * f2.denominator,
        f1.denominator * f2.denominator
    );
    normalizedFractions.push_back(normalizedF1);
    
    //Second fraction being normalized
    normalizedF2 =  Fraction(
        f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    );
    normalizedFractions.push_back(normalizedF2);
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
  Fraction simplified_fraction = Fraction(normalizedFractions.at(0).numerator + normalizedFractions.at(1).numerator, 
    normalizedFractions.at(0).denominator
  );
  Fraction::simplify(simplified_fraction);
  return simplified_fraction;
}

Fraction Fraction::operator-(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  Fraction simplified_fraction = Fraction(
    normalizedFractions.at(0).numerator - normalizedFractions.at(1).numerator,
      normalizedFractions.at(0).denominator
  );
  Fraction::simplify(simplified_fraction);
  return simplified_fraction;
  
}

Fraction Fraction::operator*(const Fraction& f) const {
  Fraction simplified_fraction = Fraction(
    this->numerator * f.numerator,
    this->denominator * f.denominator
  );
  Fraction::simplify(simplified_fraction);
  return simplified_fraction;

}
Fraction Fraction::operator/(const Fraction& f) const {
  Fraction simplified_fraction = Fraction(
    this->numerator * f.denominator,
    this->denominator * f.numerator
  );
  Fraction::simplify(simplified_fraction);
  return simplified_fraction;
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

bool Fraction::operator>(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  return normalizedFractions.at(0).numerator > normalizedFractions.at(1).numerator;
}


bool Fraction::operator<(const Fraction& f) const {
  std::vector<Fraction> normalizedFractions = Fraction::normalize(*this, f);
  std::cout << "Fracao 0 normalizada: " << normalizedFractions.at(0).toString() << "\n";
  std::cout << "Fracao 1 normalizada: " << normalizedFractions.at(1).toString() << "\n";
  return normalizedFractions.at(0).numerator < normalizedFractions.at(1).numerator;

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



