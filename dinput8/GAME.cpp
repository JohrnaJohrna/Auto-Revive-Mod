#include "GAME.h"

GAME::GAME() 
{
	_CHRINS = new CHR_INS();
	_CHRDBG = new CHR_DBG();
	_Event = new GEvent();
}

GAME::~GAME()
{
	delete _CHRINS;
	delete _CHRDBG;
	delete _Event;
}