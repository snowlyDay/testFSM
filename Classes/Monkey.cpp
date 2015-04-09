// Monkey.cpp  
//  
#include "Monkey.h"  

#include <time.h>  
#include <assert.h>  


void Monkey::exit()
{
	this->unscheduleAllCallbacks();
	cocos2d::log("exit()");
}


bool Monkey::init()
{
	_step = 1;
	_curPos = 0;
	_curTime = time(0);

	// _sprite = Sprite::create("monkey.png");  
	// addChild(_sprite);  

	_fsm = new MonkeyContext(*this);
	assert(_fsm);

	_fsm->setDebugFlag(true);
	_fsm->enterStartState();
	

	return true;
}


void Monkey::stop()
{
	_curTime = time(0);

	cocos2d::log("stop(): pos=%d", _curPos);

	this->schedule(schedule_selector(Monkey::onIdleStop), 0.1f);
}


void Monkey::walk()
{
	_curTime = time(0);

	cocos2d::log("walk(): pos=%d", _curPos);

	this->schedule(schedule_selector(Monkey::onIdleWalk), 0.1f);
}


void Monkey::turn()
{
	_step *= -1;
	cocos2d::log("turn(): step=%d", _step);

	this->schedule(schedule_selector(Monkey::onIdleTurn), 0.1f);
}