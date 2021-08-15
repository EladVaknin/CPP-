
#include "Direction.hpp"
#include <string>
#include <map>

using ariel::Direction;
using namespace std;

namespace ariel{

    class Board
    {
    private:
        typedef pair <unsigned int,unsigned int> palce_board;

        map < palce_board, char> message_board; 
        
    public:

        Board(/* args */);

        void post(unsigned int row,unsigned int colum,Direction direction,string st);

        string read(unsigned int row,unsigned int colum,Direction direction,unsigned int len);

        void show();

    };
    

}