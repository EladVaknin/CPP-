
#include<iostream>
#include<stdexcept>
#include <array>
using namespace std ;

    const array<string,4> hat ={"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
    const array<string,4> nose  = {",",".","_"," "};
    const array<string,4>  eyes  =  {".","o","O","-"};
    const array<string,4>  leftarm  = {"<","'\'","/"," "};
    const array<string,4>  rightarm  = {">","/","'\'"," "};
    const array<string,4> torso  = {" : ","] [","> <","   "};
    const array<string,4>  base  = {" : ","\" \"","___","   "};
    const int hat2=0, nose2=1, left_eye=2, right_eye=3, leftarm2=4, rightarm2=5, torso2=6, base2=7;
    const int minimum = 1, maximun = 4, tenBase=10 , lenght = 8;
    

namespace ariel
{
    string printHat (int n) {
        if (n==1){
            return hat [0];
        }
        if (n==2){
            return hat [1];
        }
        if (n==3){
            return hat [2];
        }
        return hat [3] ;  // if n == 4

    }

    string printNose (int n) {
        if (n==1){
            return nose [0];
        }
        if (n==2){
            return nose [1];
        }
        if (n==3){
            return nose [2];
        }
        return nose [3] ;  // if n == 4

    }

    string printEyes (int n) {
        if (n==1){
            return eyes [0];
        }
        if (n==2){
            return eyes [1];
        }
        if (n==3){
            return eyes [2];
        }
        return eyes [3] ;  // if n == 4

    }

    string printTorso (int n) {
        if (n==1){
            return torso [0];
        }
        if (n==2){
            return torso [1];
        }
        if (n==3){
            return torso [2];
        }
        return torso [3] ;  // if n == 4

    }

    string printBase (int n) {
        if (n==1){
            return base [0];
        }
        if (n==2){
            return base [1];
        }
        if (n==3){
            return base [2];
        }
        return base [3] ;  // if n == 4

    }

        string print(int nose, int left, int right, int x, int y) {    // print line 2/3 and  the frame "()" for line 3 in the snowman
        string string;
        if (x == 2) {    // for the case that left arm is up
            string = "\\";
        }
        else {
            string = " ";
        }
        string = string + "(";
        string = string + printEyes(left);
        string = string + printNose(nose);
        string = string + printEyes(right);
        string = string + ")";
        if (y == 2) {        // for the case that right arm is up
            string = string + "/";
        }
        else {
            string = string + " ";
        }
        string = string + "\n";
        return string;
    }

    string print2(int x, int y, int torso2) {    // print line 3/4 and the frame "()" for line 4 in the snowman
        string string;
        // print left arm 
        if (x == 1) {
            string = "<";
        }
        if (x == 2 || x == 4) {
            string = " ";
        }
        if (x == 3) {
            string = "/";
        }
        string = string + "(";
        string = string + printTorso(torso2);
        string = string + ")";
        // print right arm
        if (y == 1) {
            string = string + ">";
        }
        if (y == 2 || y == 4) {
            string = string + " ";
        }
        if (y == 3) {
            string = string + "\\";
        }
        string = string + "\n";
        return string;
    }
    /*
     HHHHH
     HHHHH
    X(LNR)Y
    X(TTT)Y
     (BBB)
*/

     // the main function
    string snowman(int num) {
        array<int,lenght> arr = {};
        for (int i = lenght-1; i >= 0; i--) {           // check if the input is vaild 
            if (num % tenBase >= minimum && num % tenBase <= maximun) {  // if num in the range 1-4 
                arr.at(i) = num % tenBase;  
                num = num/tenBase;             // To move to the next bit in the num
            } 
            else {               
                throw out_of_range{"Bad code"};
            }
           }
          if (num%tenBase!=0) {                // for know if we still have bits un the num
            throw out_of_range{"Bad code"};
           }

        // build the snowman string
        string snowmanStd = printHat(arr.at(hat2)) + "\n" ;
        snowmanStd = snowmanStd + print(arr.at(nose2), arr.at(left_eye), arr.at(right_eye),arr.at(leftarm2), arr.at(rightarm2));
        snowmanStd = snowmanStd + print2(arr.at(leftarm2), arr.at(rightarm2), arr.at(torso2));
        snowmanStd = snowmanStd + "(" +printBase(arr.at(base2)) +")";
        return snowmanStd;
    }

} 

