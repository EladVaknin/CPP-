#include <iostream>
#include <fstream>
using namespace std;



namespace ariel {
    class NumberWithUnits {
        public :
            NumberWithUnits(double amount, string unit_type);
            static void read_units(ifstream &units_file) ;
             // + - 
            NumberWithUnits operator+ () const; 
            NumberWithUnits & operator++ ();
            NumberWithUnits operator++ (int);
            NumberWithUnits operator+ (NumberWithUnits &other_num);
            NumberWithUnits operator- (NumberWithUnits &other_num);
            NumberWithUnits & operator-- ();
            NumberWithUnits operator-- (int);
            NumberWithUnits operator- () const;
            NumberWithUnits& operator+= (const NumberWithUnits &num);
            NumberWithUnits& operator-= (const NumberWithUnits &num);
            // *
            NumberWithUnits operator* (double factor);
            friend NumberWithUnits operator* (double factor, const NumberWithUnits);
            // < > = 
            bool operator> (const NumberWithUnits &other_num) const;
            bool operator< (const NumberWithUnits &other_num) const;
            bool operator== (const NumberWithUnits &other_num) const;
            bool operator<= (const NumberWithUnits &other_num) const;
            bool operator>= (const NumberWithUnits &other_num) const;
            bool operator!= (const  NumberWithUnits &other_num) const;
            // << >> 
            friend ostream& operator<< (ostream& stream, const NumberWithUnits& num);
            friend istream& operator>> (istream& stream, const NumberWithUnits& num);

    };
}

