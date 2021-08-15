#include "NumberWithUnits.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace ariel;
const double epsilon = 0.00001;

unordered_map<string,unordered_map<string, double>> convert;


namespace ariel
{
    // consturactor
  NumberWithUnits::NumberWithUnits(double val, const string &type){
      if (convert.count(type) == 0)
        {
            throw invalid_argument("The type not called"+type);
        }
        this->val = val;
        this->type = type;
  }   

  void NumberWithUnits::read_units(ifstream &units_file) {
     if (units_file.fail()){
         throw invalid_argument ("Failed to read the file") ;
     }
     double val1 = 0 , val2=0;
     string type1 ,type2; 
     string comper;
     while (units_file>>val1>>type1>>comper>>val2>>type2){
        convert[type1][type2] = val2;
        convert[type2][type1] = 1 / val2;
        // insert - type 1 type 2 
        for (auto &map : convert[type1]){
            double val = convert[type1][type2] * map.second;
            convert[type1][map.first] = val;
            convert[map.first][type1] = 1 / val;
        }
        // insert - type 2 type 1 
         for (auto &map : convert[type2]){
            double val = convert[type2][type1] * map.second;
            convert[type2][map.first] = val;
            convert[map.first][type2] = 1 / val;
         }
        }
     }
    // binary operators
    NumberWithUnits NumberWithUnits::operator+ (const NumberWithUnits &num) const {
      double x = con(num.val, num.type, this->type);
        return NumberWithUnits(this->val + x, this->type);
    }
    NumberWithUnits NumberWithUnits::operator- (const NumberWithUnits &num) const {
        double x = con(num.val, num.type, this->type);
        return NumberWithUnits(this->val - x, this->type);
    }
    // unary operators 
    NumberWithUnits NumberWithUnits::operator+ () const {
        NumberWithUnits ans (this->val, this->type);
       return ans;

    }
    NumberWithUnits NumberWithUnits::operator- () const {
        NumberWithUnits ans ((-1)*this->val, this->type);
       return ans;
    }
    // prefix ++n
       NumberWithUnits & NumberWithUnits::operator++ () {  
           ++(this->val);
        return *this;
    }
    // postfix n++ 
        NumberWithUnits NumberWithUnits::operator++ (int) {
            NumberWithUnits ans (this->val++ ,this->type);
        return ans;
    }
  
    // prefix --n
     NumberWithUnits & NumberWithUnits::operator-- () {
         --(this->val);
        return *this;
    }
    // postfix n-- 
     NumberWithUnits NumberWithUnits::operator-- (int) {
          NumberWithUnits ans (this->val-- ,this->type);
        return ans;
    }

    // -= , += operators.
    NumberWithUnits &NumberWithUnits::operator += (const NumberWithUnits &num) {
        this->val += con(num.val, num.type, this->type);
        return *this;        
    }
    
    NumberWithUnits &NumberWithUnits::operator -= (const NumberWithUnits &num) {
        this->val -= con(num.val, num.type, this->type);
        return *this;  
    }
    // * operator
    NumberWithUnits NumberWithUnits::operator* (double factor) const {
        return factor*(*this);
    }
    NumberWithUnits operator* (double factor, const NumberWithUnits &num) {
         NumberWithUnits ans(factor*(num.val), num.type);
        return ans;
    }
    
    // < > = operators

    bool NumberWithUnits::operator > (const NumberWithUnits &num) const {
        double x = con(num.val, num.type, this->type);
        return (this->val > x); 
    }
    bool NumberWithUnits::operator < (const NumberWithUnits &num) const {
          double x = con(num.val, num.type, this->type);
        return (this->val < x); 
    }
    bool NumberWithUnits::operator == (const NumberWithUnits &num) const {
         double x = (abs(this->val-con(num.val,num.type, this->type)));
         return (x <= epsilon);
    }
    bool NumberWithUnits::operator <= (const NumberWithUnits &num) const {
        return !(*this > num);
    }
    bool NumberWithUnits::operator >= (const NumberWithUnits &num) const {
        return !(*this < num);
    }
    bool NumberWithUnits::operator!= (const NumberWithUnits &num) const {
        return !(*this == num);
    }
   
   // << >> operators
    ostream& operator << (ostream& stream, const NumberWithUnits& num) {
                stream << num.val << "[" << num.type << "]";
        return stream;
    }
    std::istream& operator>> (std::istream &stream, NumberWithUnits &n) {
        double valu=0;
        string types;
        char c=' ';
        stream >> valu;
        stream >> c ;
        while(c!=']'){
            if(c!='['){
                types.insert(types.end(),c);
            }
            stream>>c;
        }
       if(convert[types].empty()){throw invalid_argument{"unit doesnt exist"};};
        n.val=valu;
        n.type=types;
        return stream;
    }


    double con(double val,const string& typer,const string& wttype) 
    {
        if (typer == wttype) // case that the units is same type.
        {
            return val;
        }
        try{
            return val * convert.at(typer).at(wttype);
        }
        catch(const exception& e) {
            throw invalid_argument{"this types can not connected"};
        }
    }
    


}
