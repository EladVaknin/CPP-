#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel {
    class Board {
        private :
            vector<vector<char>> board;
        
        public :
            void post (unsigned int row, unsigned int column, Direction Direction, string data);

            string read (unsigned int row, unsigned int column, Direction direction, unsigned int length);
            
            void show ();
    };
}