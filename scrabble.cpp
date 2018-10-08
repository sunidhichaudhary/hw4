#include<bits/stdc++.h>
#include "Player.h"
#include "Bag.h"
using namespace std;
int handsize,seed;
string str,board,tiles,dictionary;
void read_config(char const* c)
{
	fstream fp;
	fp.open(c);
	while(fp >> str)
	{
		if(str == "HANDSIZE:")
			fp>>handsize;
		if(str == "BOARD:")
			fp>>board;
		if(str == "TILES:")
			fp>>tiles;
		if(str == "DICTIONARY:")
			fp>>dictionary;
		if(str == "SEED:")
			fp>>seed;
	}
}
int main(int argc, char const *argv[])
{
	ConsolePrinter printer;
	Board brd("board.txt");
	printer.printBoard(brd);
	read_config(argv[1]);
	Bag bag(tiles,seed);
	int num_of_players;
	cout<<"Enter the number of players."<<endl;
	cin>>num_of_players;
	string names[num_of_players];
	cout<<"Enter the name of players,each name followed by the return"<<endl;
	cin.ignore();
	for(int i=0;i<num_of_players;i++)
	{
		getline(cin,names[i]);
	}
	std::vector<Player> players;
	for(int i=0;i<num_of_players;i++)
	{
		Player p(names[i],handsize);
		p.addTiles(bag.drawTiles(handsize));
		players.push_back(p);
	}	
	// For testing purpose only
	for(int i=0;i<num_of_players;i++)
	{

		Player p =players[i];
		printer.printHand(p);

		// set<Tile*> t = p.getHandTiles();
		// set<Tile*> :: iterator it;
		// cout<<p.getName()<<" "<<p.getScore()<<" ";
		// for(it = t.begin();it!=t.end();it++)
		// {
		// 	Tile *p;
		// 	p = *it;
		// 	cout<<p->getLetter()<<" ";
		// }
		// cout<<endl;
	}
	//testing of hasTiles
	// cout<<players[1].hasTiles("o?z",1)<<endl;
}