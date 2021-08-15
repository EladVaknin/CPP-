
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <math.h>
#include <string>
#include <algorithm>
using namespace std;


/*
    const string hat [4]  = {"_===_", " --- \n.....", "  -  \n /_'\'","----\n(_*_)"};
    const string nose [4] = {",",".","_"," "};
    const string eyes [4] = {".","o","O","-"};
    const string leftarm [4] = {"<","'\'","/"," "};
    const string rightarm [4] = {">","/","'\'"," "};
    const string torso [4] = {"  :  ","]   [",">   <"," "};
    const string base [4] = {"  :  ","\"   \"","_____"," "};
*/



TEST_CASE("Good snowman code") {
    // The shape should be mach the code.

    CHECK((snowman(11114411)) == ("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(snowman(33233124) == string("   _\n  /_\\\n (o_O) \n/(] [)>\n (   )\n"));
    CHECK(snowman(41113422) == string ("  ___  \n (_*_) \n (.,.) \n/(] [) \n (\" \") \n")); 
    CHECK(snowman(12341424) == string("      \n _===_\n (O.-) \n<(] [) \n (   )"));
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(12232212) == string ("       \n _===_ \n\\(o.O)/\n ( : ) \n (\" \") \n")); 
    CHECK(snowman(12311111) == string("      \n _===_\n (O..) \n<( : )>\n ( : )"));
    CHECK(snowman(11111111)== string(" _===_\n (.,.) \n<( : )>\n ( : )\n"));
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/\n<( : ) \n (\" \")"));
    CHECK(snowman(33241234) == string ( "   _   \n  /_\\ \n (o_-)/\n<(> <) \n (   ) \n")); 
    CHECK(snowman(22222222)== string("  ---\n .....\n\\(o.o)/\n (] [) \n (\" \")\n"));
    CHECK(snowman(33333333)== string("   -\n  /_\\\n (O_O) \n/(> <)\\\n (___)\n"));
    CHECK(snowman(22413124) == string ("  ___  \n ..... \n (-..) \n/(] [)>\n (   ) \n")); 
    CHECK(snowman(44444444)== string("  ---\n (_*_)\n (- -) \n (   ) \n (   )\n"));
    CHECK(snowman(44123211) == string ("  ___  \n (_*_) \n (. o)/\n/( : ) \n ( : ) \n")); 
    CHECK(snowman(21114411) == string("  ___ \n .....\n (.,.) \n ( : ) \n ( : )"));
    CHECK((snowman(21213444)) == string ("  ___ \n .....\n (o,.) \n/(   ) \n (   ) "));
    CHECK(snowman(12341111) == string("      \n _===_\n (O.-) \n<( : )>\n ( : )"));
    CHECK(snowman(13412143) == string ("       \n _===_ \n\\(-_.) \n (   )>\n (___) \n")); 
    CHECK(snowman(33414214) == string ("   _   \n  /_\\ \n (-_.)/\n ( : ) \n (   ) \n")); 
    CHECK(snowman(13412143) == string ("       \n _===_ \n\\(-_.) \n (   )>\n (___) \n")); 
    CHECK(snowman(34211342) == string ("   _   \n  /_\\ \n (o .) \n<(   )\\\n (\" \") \n")); 
    CHECK(snowman(24114324) == string ("  ___  \n ..... \n (. .) \n (] [)\\\n (   ) \n")); 


     // A lot of random tests with different combinations in a loop.         
     for (int i = 0; i < 4; ++i) {
            int num = 11111111+i*10000000;
            int num2 = 11111111+i*00011000;
            int num3 = 11111111+i*10101010;
            int num4 = 11111111+i*00110011;
           CHECK((snowman(num)) == string  (hat[i-1]+"\n"+rightarm[i-1]+eyes[i-1]+nose[i-1]+eyes[i-1]+leftarm[i-1]+"\n"+torso[i-1]+"\n"+base[i-1] )) ; 
           CHECK((snowman(num2)) == string ( hat[i-1]+"\n"+rightarm[i-1]+eyes[i-1]+nose[i-1]+eyes[i-1]+leftarm[i-1]+"\n"+torso[i-1]+"\n"+base[i-1] )) ; 
           CHECK((snowman(num3)) == string ( hat[i-1]+"\n"+rightarm[i-1]+eyes[i-1]+nose[i-1]+eyes[i-1]+leftarm[i-1]+"\n"+torso[i-1]+"\n"+base[i-1] )) ; 
           CHECK((snowman(num4)) == string ( hat[i-1]+"\n"+rightarm[i-1]+eyes[i-1]+nose[i-1]+eyes[i-1]+leftarm[i-1]+"\n"+torso[i-1]+"\n"+base[i-1] )) ; 

     }

    CHECK((snowman(12222212)) == string ( hat[0]+"\n"+rightarm[1]+eyes[1]+nose[1]+eyes[1]+leftarm[1]+"\n"+torso[0]+"\n"+base[1] )) ; 
    CHECK((snowman(44444432)) == string ( hat[3]+"\n"+rightarm[3]+eyes[3]+nose[3]+eyes[3]+leftarm[3]+"\n"+torso[2]+"\n"+base[1] ));
    CHECK((snowman(11111111)) == string ( hat[0]+"\n"+rightarm[0]+eyes[0]+nose[0]+eyes[0]+leftarm[0]+"\n"+torso[0]+"\n"+base[0] ));
    CHECK((snowman(22222222)) == string ( hat[1]+"\n"+rightarm[1]+eyes[1]+nose[1]+eyes[1]+leftarm[1]+"\n"+torso[0]+"\n"+base[1] ));
    CHECK((snowman(33333333)) == string ( hat[2]+"\n"+rightarm[2]+eyes[2]+nose[2]+eyes[2]+leftarm[2]+"\n"+torso[2]+"\n"+base[2] ));
    CHECK((snowman(44444444)) == string ( hat[3]+"\n"+rightarm[3]+eyes[3]+nose[3]+eyes[3]+leftarm[3]+"\n"+torso[3]+"\n"+base[3] ));
    CHECK(snowman(12341234) == string ( hat[0]+"\n"+rightarm[1]+eyes[2]+nose[3]+eyes[0]+leftarm[1]+"\n"+torso[2]+"\n"+base[3] ));
        

        

    // These loops do not pass the tests due to the limited complication time.

    // for (int i = 1; i < 4; i++)
    // {
    //     for (int j = 2; i < 3; j++)
    //     {
         
    //         string tmp = to_string (i+j+i+j+i+j+i+j);
    //         int tmp2 = stoi(tmp);
    //         CHECK((snowman(tmp2)) == string ( hat[i-1]+"\n"+rightarm[j-1]+eyes[i-1]+nose[j-1]+eyes[i-1]+leftarm[j-1]+"\n"+torso[i-1]+"\n"+base[j-1] )) ; 

    //         string tmp3 = to_string (i+i+i+i+i+i+i+i);
    //         int tmp4 = stoi(tmp3);
    //         CHECK((snowman(tmp4)) == string ( hat[i-1]+"\n"+rightarm[i-1]+eyes[i-1]+nose[i-1]+eyes[i-1]+leftarm[i-1]+"\n"+torso[i-1]+"\n"+base[i-1] )) ; 

    //         string tmp5 = to_string (i+i+i+j+j+i+i+i);
    //         int tmp6 = stoi(tmp5);
    //         CHECK((snowman(tmp6)) == string ( hat[i-1]+"\n"+rightarm[i-1]+eyes[i-1]+nose[j-1]+eyes[j-1]+leftarm[i-1]+"\n"+torso[i-1]+"\n"+base[i-1] )) ; 


    //     }
    // }

}

TEST_CASE("Bad snowman length") {
    // Valid lenght - the length should be  8 bits.
    CHECK_THROWS(snowman(555)) ;
    CHECK_THROWS(snowman(0)) ;
    CHECK_THROWS(snowman(1)) ;
    CHECK_THROWS(snowman(123456789)) ;
    CHECK_THROWS(snowman(2222222)) ;
    CHECK_THROWS(snowman(1114442211)) ; 
    CHECK_THROWS(snowman(111199111)) ;
    

}
TEST_CASE ("Valid numbers") {
    // Valid numbers - the range need to be 1 btween 4.
    CHECK_THROWS(snowman(1111-2333)) ;
    CHECK_THROWS(snowman(-555)) ;
    int tmp = 11111111;
    for (int i = 4; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            CHECK_THROWS(snowman(tmp+i*pow(10,j)));
        }
    }


     
}

