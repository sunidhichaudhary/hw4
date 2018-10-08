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
		players.push_back(p);
	}
}