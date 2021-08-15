
#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
using namespace ariel;
using namespace std;

//operator + 
TEST_CASE("operator + and += "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits m(2,"m") , cm(50,"cm"); // dis
    CHECK_EQ(m+cm , NumberWithUnits(2.5,"m"));    
    CHECK_EQ(m+=cm , NumberWithUnits(2.5,"m"));  
    NumberWithUnits ton(1,"ton") ,kg(1,"kg"); // weight
    CHECK_EQ(ton+kg , NumberWithUnits(1.001,"ton"));
    CHECK_EQ(ton+=kg , NumberWithUnits(1.001,"ton"));
    NumberWithUnits min(1,"min") ,sec(5,"sec"); // time 
    CHECK_EQ(min+sec , NumberWithUnits(1.05,"min"));
    CHECK_EQ(min+=sec , NumberWithUnits(1.05,"min"));
}

// operator - 
TEST_CASE("operator - and -= "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits m(2,"m") , cm(50,"cm");   // dis
    CHECK_EQ(m-cm , NumberWithUnits(1.5,"m"));  
    CHECK_EQ(m-=cm , NumberWithUnits(1.5,"m"));  
    NumberWithUnits ton(1,"ton") ,kg(1,"kg");  // weight 
    CHECK_EQ(ton-kg , NumberWithUnits(0.999,"ton"));
    CHECK_EQ(ton-=kg , NumberWithUnits(0.999,"ton"));
    NumberWithUnits min(1,"min") ,sec(5,"sec");  // time
    CHECK_EQ(min-sec , NumberWithUnits(0.55,"min"));
    CHECK_EQ(min-=sec , NumberWithUnits(0.55,"min"));
}

// comper operators - < > = != <= >=
TEST_CASE("operato < and <= "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK(NumberWithUnits(1,"km")<NumberWithUnits(1500,"m"));  // dis
    CHECK(NumberWithUnits(500,"cm")<=NumberWithUnits(6,"m"));
    CHECK(NumberWithUnits(1,"kg")<NumberWithUnits(2,"kg"));   // weight
    CHECK(NumberWithUnits(2,"kg")<=NumberWithUnits(2,"kg"));
    CHECK(NumberWithUnits(1000,"kg")<NumberWithUnits(1.1,"ton"));
    CHECK(NumberWithUnits(1100,"kg")<=NumberWithUnits(1.1,"ton"));
    CHECK_FALSE(NumberWithUnits(60.1,"min")<NumberWithUnits(1,"hour")); // time
    CHECK_FALSE(NumberWithUnits(2,"hour")<= NumberWithUnits(121,"min"));
}

TEST_CASE("operato > and >= "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK(NumberWithUnits(2,"km")>NumberWithUnits(1500,"m"));  // dis
    CHECK(NumberWithUnits(500,"cm")>=NumberWithUnits(4,"m"));
    CHECK(NumberWithUnits(2,"kg")>NumberWithUnits(1,"kg"));   // weight
    CHECK(NumberWithUnits(2,"kg")>=NumberWithUnits(2,"kg"));
    CHECK(NumberWithUnits(1000,"kg")>NumberWithUnits(0.9,"ton"));
    CHECK(NumberWithUnits(1100,"kg")>=NumberWithUnits(1.1,"ton"));
    CHECK_FALSE(NumberWithUnits(60.1,"min")>NumberWithUnits(1,"hour")); // time
    CHECK_FALSE(NumberWithUnits(2,"hour")>= NumberWithUnits(121,"min"));
}
TEST_CASE("operato == and != "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK(NumberWithUnits(1,"km")!=NumberWithUnits(1.1,"km"));  // dis
    CHECK(NumberWithUnits(500,"cm")==NumberWithUnits(5,"m"));
    CHECK(NumberWithUnits(60.1,"min")!=NumberWithUnits(1,"hour")); // time
    CHECK(NumberWithUnits(2,"hour")== NumberWithUnits(120,"min"));
}

//  prefix and profix operators ++ -- 
TEST_CASE("operator ++/--num and num++/--"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits km(1,"km") ,m(25,"m");
    km=km++;
    CHECK(km==NumberWithUnits(2,"km"));
    km=--km;
    CHECK(km==NumberWithUnits(1,"km"));
    m=--m;
    m=m++;
    CHECK (m == NumberWithUnits (25,"m"));

}

// operator * 
TEST_CASE ("operator *"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits km1(1,"km"),km2(1.8,"km") ;
    CHECK ((km1*2)==NumberWithUnits(2,"km"));
    CHECK ((km2*0.5)==NumberWithUnits(0.9,"km"));
}

// Actions from different categories
TEST_CASE ("Different categories") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a (1,"km")  , b (100 ,"kg"); 
    CHECK_THROWS(a+b); //dis + weight 
    NumberWithUnits c(3,"m") , d(5,"sec");
    CHECK_THROWS(c-d); // dis + time 
    
}