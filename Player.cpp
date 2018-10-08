#include "Player.h"
#include<algorithm>
using namespace std;
void toLower(string str)
{
	for(int i=0;i<str.length();++i)
	{
		if((int)str[i]>=65 && (int)str[i]<=90)
		{	
			str[i] = str[i]+32;
		}
	}
}	
Player :: Player(std::string const & name, size_t maxTiles):_name(name),_maxTiles(maxTiles),_score(0){ }
Player :: ~Player()
{

}
void Player :: addTiles(std::vector<Tile*> const & tilesToAdd)
{
	this->_playerTiles = tilesToAdd;
}
std::set<Tile*> Player :: getHandTiles() const
{
	set<Tile*> s(_playerTiles.begin(),_playerTiles.end());
	return s;
}
bool Player :: hasTiles(std::string const & move, bool resolveBlanks) const
{
	move = toLower(move);
	string has;
	std::vector<Tile*> :: iterator it;
	Tile *p;
	for(it = _playerTiles.begin();it!= _playerTiles.end();it++)
	{
		p = *it;
		has.insert(p->getLetter());
	}
	for (int i = 0; i < move.length(); ++i)
	{
		if(move[i] == '?' && resolveBlanks == true)
		{
			size_t found = has.find(move[i]);
			if(found != string::npos)
				{	
					i++;
					continue;
				}
		}
		else
		{
			size_t found = has.find(move[i]);
			if(found != string::npos)
				continue;
			else
				return false;
		}
	}
	return true;
}