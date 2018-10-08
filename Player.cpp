#include "Player.h"
#include<algorithm>
using namespace std;
string toLower(string str)
{
	for(int i=0;i<str.length();++i)
	{
		if((int)str[i]>=65 && (int)str[i]<=90)
		{	
			str[i] = str[i]+32;
		}
	}
	return str;
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
	string lower = move;
	lower = toLower(lower);
	string has;
	std :: set<Tile*> has_tiles_set = this->getHandTiles();
	std::set<Tile*> :: iterator it;
	Tile *p;
	for(it = has_tiles_set.begin();it!= has_tiles_set.end();it++)
	{
		p = *it;
		has.insert(has.end(),p->getLetter());
	}
	for (int i = 0; i < lower.length(); ++i)
	{
		if(lower[i] == '?' && resolveBlanks == true)
		{
			size_t found = has.find(lower[i]);
			if(found != string::npos)
				{	
					i++;
					continue;
				}
			else
			{
				return false;
			}
		}
		else
		{
			size_t found = has.find(lower[i]);
			if(found != string::npos)
				continue;
			else
				return false;
		}
	}
	return true;
}
