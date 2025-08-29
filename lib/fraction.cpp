#include "fraction.hpp"
#include <iostream>


void Fraction::simplify(){
  //TODO: Search how to simplify a fraction in code!
}
Fraction& Fraction::operator++(){
  this->numerator += this->denominator;
  return *this;
}

Fraction& Fraction::operator--(){
  this->numerator -= this->denominator;
  return *this;
}

Fraction& Fraction::operator+(Fraction f){
  Fraction* newF = new Fraction();
  if(this->denominator != f.denominator){
    //TODO: Get the denominator of f, so the multiplication can work!
  }
}

std::string Fraction::toString(){
  return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}



