#include "Board.h"
#include<fstream>
#include<iostream>
#include "ConsolePrinter.h"
using namespace std;
Board :: Board(std::string board_file_namey)
{
	fstream fp;
	fp.open(board_file_namey);
	fp>>num_of_col>>num_of_row>>starting_x>>starting_y;
	sq.resize(num_of_row);
	char a;
	for(int i = 0; i < num_of_row; i++)
		for(int j = 0;j < num_of_col; j++)
		{
			fp>>a;
			if(i == starting_x-1 && j == starting_y-1)
			{
				if(a == '.')
				{
					Square s(1,1,true);
					sq[i].push_back(s);
				}
				else if(a == '2')
				{
					Square s(2,1,true);
					sq[i].push_back(s);
				}
				else if(a == '3')
				{
					Square s(3,1,true);
					sq[i].push_back(s);
				}
				else if(a == 'd')
				{
					Square s(1,2,true);
					sq[i].push_back(s);
				}
				else if(a == 't')
				{
					Square s(1,3,true);
					sq[i].push_back(s);
				}
			}

			else
			{
				if(a == '.')
				{
					Square s(1,1,false);
					sq[i].push_back(s);
				}
				else if(a == '2')
				{
					Square s(2,1,false);
					sq[i].push_back(s);
				}
				else if(a == '3')
				{
					Square s(3,1,false);
					sq[i].push_back(s);
				}
				else if(a == 'd')
				{
					Square s(1,2,false);
					sq[i].push_back(s);
				}
				else if(a == 't')
				{
					Square s(1,3,false);
					sq[i].push_back(s);
				}
			}
		}
}
Board :: ~Board()
{

}
Square * Board :: getSquare (size_t x, size_t y)
{
	return &sq[y-1][x-1];
}
size_t Board :: getRows() const
{
	return num_of_row;
}
size_t Board :: getColumns() const
{
	return num_of_col;
}
// int main(int argc, char const *argv[])
// {
// 	/* code */
	
// 	Square *ptr;
	
// 	// for(int i = 0; i < 15; i++)
// 	// {
// 	// 	for(int j = 0;j < 15; j++)
// 	// 	{
// 	// 		ptr = board.getSquare(i,j);
// 	// 		cout<<ptr->getLMult()*(ptr->getWMult())<<" ";
// 	// 	}
// 	// 	cout<<endl;
// 	// }
// 	return 0;
// }