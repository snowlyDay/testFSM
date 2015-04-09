#pragma once
#ifndef __MONKEY_H__
#define __MONKEY_H__
#include  <time.h>
#include "cocos2d.h"
#include "Monkey_sm.h"
USING_NS_CC;
#define MAX_STOP_TIME 10
#define MAX_WALK_TIME 10

#define MAX_WALK_DIST 100

class Monkey  :public Node
{ 


public:
	Monkey(){
		log("Monkey(");
	}
	CREATE_FUNC(Monkey);
	virtual bool init();
	void stop();
	void walk(); 
	void turn();
	void exit();
private:
	MonkeyContext * _fsm;
	int  _step;
	int  _curPos;
	time_t _curTime;

private:
	void onIdleStop(float dt)
	{
		int d = (int)(time(0) - _curTime);
		if (d > MAX_STOP_TIME) {
			_fsm->walk();
		}
	}


	void onIdleWalk(float dt)
	{
		if (_curPos > MAX_WALK_DIST || _curPos < -MAX_WALK_DIST) {
			_fsm->turn();
		}

		int d = (int)(time(0) - _curTime);
		if (d > MAX_WALK_TIME) {
			_fsm->stop();
		
		}

		_curPos += _step;
	}


	void onIdleTurn(float dt)
	{
		_fsm->walk();
	}

};

#endif