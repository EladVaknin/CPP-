/**
 * Full program for message-board exercise.
 * 
 * Author: Elad Vaknin
 * Since : 2021-04
 */

#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Direction.hpp"
#include "Board.hpp"

using namespace std;
using ariel::Direction;


namespace ariel{
    Board::Board(){}
    
    //Read from the board funcion
    string Board::read(unsigned int row,unsigned int colum, Direction direction,unsigned int len){
        char sign='_';
        string message;

        for (size_t i = 0; i < len; i++)
        {           
          if(message_board[make_pair(row,colum)] > 0){ 
              sign=message_board[make_pair(row,colum)];
          }
          else{
                sign='_'; 
            }
            message+=sign;
            if(Direction::Horizontal==direction){  
                colum++;
            }
            else{
                row++; 
            }   
        }       
        return message;
    }

    // Post funcion
    void Board::post(unsigned int row,unsigned int col,Direction direction,string st){

        for (size_t i = 0; i < st.length(); i++)
        {
            message_board[make_pair(row,col)]=st.at(i); 
            if(Direction::Horizontal==direction){
                col++;
            }
            else{
                row++;    
            }
        }
     cout<< "post" <<endl;
    }

   // Show function
    void Board::show(){

        unsigned int i = 0;
        unsigned int col = 0;

        for(auto elem : message_board){ 

            if(i==0){
                std::cout << elem.second<<endl;
                i++;
                col =elem.first.first; 
            }
            else{
                if(col != elem.first.first){ 
                    std::cout<<endl;
                    std::cout << elem.second;
                    col=elem.first.first;
                }
                else{
                   std::cout << elem.second; 
                }         
            }    
        }
        cout<<endl;
        cout<< "show" <<endl;
    }
}