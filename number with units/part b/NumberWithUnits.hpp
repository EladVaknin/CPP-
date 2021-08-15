#include <iostream>
#include <fstream>
#include <string>

using namespace std;



namespace ariel {
    class NumberWithUnits {

        private :  
        double val;
        string type;
    
        public :
            NumberWithUnits(double val, const string &type);
            static void read_units(ifstream &units_file) ;
             // + - 
            NumberWithUnits operator+ () const; 
            NumberWithUnits operator- () const;
            NumberWithUnits operator+ (const NumberWithUnits &other_num)const;
            NumberWithUnits operator- (const NumberWithUnits &other_num)const ;
            //prefix and postfix 
            NumberWithUnits & operator++ ();
            NumberWithUnits operator++ (int);
            NumberWithUnits & operator-- ();
            NumberWithUnits operator-- (int);
            //
            NumberWithUnits& operator+= (const NumberWithUnits &num);
            NumberWithUnits& operator-= (const NumberWithUnits &num);
            // *
            NumberWithUnits operator* (double factor) const;
            friend NumberWithUnits operator* (double factor, const NumberWithUnits &num);
            // < > = 
            bool operator> (const NumberWithUnits &other_num) const;
            bool operator< (const NumberWithUnits &other_num) const;
            bool operator== (const NumberWithUnits &other_num) const;
            bool operator<= (const NumberWithUnits &other_num) const;
            bool operator>= (const NumberWithUnits &other_num) const;
            bool operator!= (const  NumberWithUnits &other_num) const;
            // << >> 
            friend ostream& operator<< (ostream& stream, const NumberWithUnits& num);
            friend istream& operator>> (istream& stream, NumberWithUnits& num);
            double con(double val,const string& type,const string& wttype) const ;

    };
}

