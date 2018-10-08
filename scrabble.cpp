#include<bits/stdc++.h>
#include "Player.h"
#include "Bag.h"
#include "Board.h"
#include "ConsolePrinter.h"
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
	// Reading the config file	
	read_config(argv[1]);

	// Bag containing all the tiles
	Bag bag(tiles,seed);
	int num_of_players;

	cout<<"Enter the number of players."<<endl;
	cin>>num_of_players;

	// Input names of all the players
	string names[num_of_players];
	cout<<"Enter the name of players,each name followed by the return"<<endl;
	cin.ignore();

	// Take input of names
	for(int i=0;i<num_of_players;i++)
	{
		getline(cin,names[i]);
	}

	// Initialize each player and provide handsize number of tiles to it
	std::vector<Player> players;
	for(int i=0;i<num_of_players;i++)
	{
		Player p(names[i],handsize);
		p.addTiles(bag.drawTiles(handsize));
		players.push_back(p);
	}

	// Initialize a board
	Board brd(board);

	// Initialize a console printer object
	ConsolePrinter cp;

	// Round robin working of players
	while(1) {

		// Each player's turn
		for(int i=0; i<num_of_players; i++) {

			// Show current Status of the board
			cp.printBoard(brd);

			Player player = players[i];

			// Show the tiles player has
			cp.printHand(player);
			// set<Tile*> handTiles = player.getHandTiles();
			// set<Tile*> :: iterator it;
			// cout << "Current tiles in player's hand are: ";
			// for(it = handTiles.begin(); it!=handTiles.end(); it++)
			// {
			// 	Tile *p;
			// 	p = *it;
			// 	cout<<p->getLetter()<<" ";
			// }
			// cout << endl;

			// Current Score of all the players in the game

			// Query player for his/her turn: PASS, EXCHANGE, PLACE

			// Apply Move: place word on the board 

			// Show results of the move: words formed, points earned, new letters picked up

			// wait until press enter
			// cin.ignore();

		}

		// Will remove it 
		break;

		// End a game when all the players passes and show winners

		// End a game when bag is empty and show winners
	}

	// For testing purpose only
	// for(int i=0;i<num_of_players;i++)
	// {
	// 	Player p =players[i];
	// 	set<Tile*> t = p.getHandTiles();
	// 	set<Tile*> :: iterator it;
	// 	cout<<p.getName()<<" "<<p.getScore()<<" ";
	// 	for(it = t.begin();it!=t.end();it++)
	// 	{
	// 		Tile *p;
	// 		p = *it;
	// 		cout<<p->getLetter()<<" ";
	// 	}
	// 	cout<<endl;
	// }

	//testing of hasTiles
	// cout<<players[1].hasTiles("o?z",1)<<endl;
}