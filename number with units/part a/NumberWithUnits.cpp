#include "NumberWithUnits.hpp"
#include <iostream>
using namespace std;
using namespace ariel;




namespace ariel
{
  NumberWithUnits::NumberWithUnits(double amount, string unit_type){}   

  void NumberWithUnits::read_units(ifstream &units_file) {
     if (units_file.fail()){
         throw invalid_argument ("Failed to read the file") ;
     }
 }
      // + - oprerators 
   NumberWithUnits NumberWithUnits::operator+ (NumberWithUnits &other_num) {
        NumberWithUnits ans (1, "km");
        return ans;
    }
    // prefix ++n
       NumberWithUnits & NumberWithUnits::operator++ () {  
        return *this;
    }
    // postfix n++ 
        NumberWithUnits NumberWithUnits::operator++ (int) {
        return *this;
    }
    // Subtraction action between two objects
    NumberWithUnits NumberWithUnits::operator- (NumberWithUnits &other_num) {
        NumberWithUnits ans(1, "km");
        return ans;
    }

    NumberWithUnits NumberWithUnits::operator- () const {
        NumberWithUnits ans(1, "km");
        return ans;
    }
    // prefix --n
     NumberWithUnits & NumberWithUnits::operator-- () {
        return *this;
    }
    // postfix n-- 
     NumberWithUnits NumberWithUnits::operator-- (int) {
        return *this;
    }

    // -= , += operators.
    NumberWithUnits& NumberWithUnits::operator+= (const NumberWithUnits &num) {
        return *this;
    }
    NumberWithUnits& NumberWithUnits::operator-= (const NumberWithUnits &num) {
        return *this;
    }
    // * operator
    NumberWithUnits NumberWithUnits::operator* (double factor) {
        NumberWithUnits ans(1, "km");
        return ans;
    }
    NumberWithUnits operator* (double factor, const NumberWithUnits) {
        NumberWithUnits ans(1, "km");
        return ans;
    }
    // < > = operators

    bool NumberWithUnits::operator> (const NumberWithUnits &other_num) const {
        return true;
    }
    bool NumberWithUnits::operator< (const NumberWithUnits &other_num) const {
        return true;
    }
    bool NumberWithUnits::operator== (const NumberWithUnits &other_num) const {
        return true;
    }
    bool NumberWithUnits::operator<= (const NumberWithUnits &other_num) const {
        return true;
    }
    bool NumberWithUnits::operator>= (const NumberWithUnits &other_num) const {
        return true;
    }
    bool NumberWithUnits::operator!= (const NumberWithUnits &other_num) const {
        return true;
    }
   
   // << >> operators

    ostream& operator<< (ostream& stream, const NumberWithUnits& num) {
        return stream;
    }
    istream& operator>> (istream& stream, const NumberWithUnits& num) {
        return stream;
    }



}