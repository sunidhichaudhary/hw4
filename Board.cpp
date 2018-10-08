#include "Board.h"
#include<fstream>
#include<iostream>
using namespace std;
Board :: Board(std::string board_file_namey)
{
	fstream fp;
	fp.open(board_file_namey);
	fp>>x>>y>>ix>>iy;
	sq.resize(x);
	char a;
	for(int i = 0; i < x; i++)
		for(int j = 0;j < y; j++)
		{
			fp>>a;
			if(i == ix && j == iy)
			{
				if(a == '.')
				{
					Square s(1,1,true);
					sq[i].push_back(s);
				}
				if(a == '2')
				{
					Square s(2,1,true);
					sq[i].push_back(s);
				}
				if(a == '3')
				{
					Square s(3,1,true);
					sq[i].push_back(s);
				}
				if(a == 'd')
				{
					Square s(1,2,true);
					sq[i].push_back(s);
				}
				if(a == 't')
				{
					Square s(3,1,true);
					sq[i].push_back(s);
				}
			}
			
			if(a == '.')
			{
				Square s(1,1,false);
				sq[i].push_back(s);
			}
			if(a == '2')
			{
				Square s(2,1,false);
				sq[i].push_back(s);
			}
			if(a == '3')
			{
				Square s(3,1,false);
				sq[i].push_back(s);
			}
			if(a == 'd')
			{
				Square s(1,2,false);
				sq[i].push_back(s);
			}
			if(a == 't')
			{
				Square s(3,1,false);
				sq[i].push_back(s);
			}
		}
}
Board :: ~Board()
{

}
Square * Board :: getSquare (size_t x, size_t y)
{
	return &sq[x][y];
}
size_t Board :: getRows() const
{
	return x;
}
size_t Board :: getColumns() const
{
	return y;
}
// int main(int argc, char const *argv[])
// {
// 	/* code */
// 	Board board("board.txt");
// 	Square *ptr;
// 	for(int i = 0; i < 15; i++)
// 	{
// 		for(int j = 0;j < 15; j++)
// 		{
// 			ptr = board.getSquare(i,j);
// 			cout<<ptr->getLMult()*(ptr->getWMult())<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	return 0;
// }