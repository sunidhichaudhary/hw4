#include "Player.h"
using namespace std;
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