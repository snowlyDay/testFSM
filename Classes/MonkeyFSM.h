//#ifndef __MONKEY_FSM_H__
//#define __MONKEY_FSM_H__
//#include "State.h"
//#include  "cocos2d.h"
//USING_NS_CC;
// 
//class Monkey;
//class MonkeyFSM :public Node{
//public:
//	MonkeyFSM(){
//
//		_monkey = 0;
//		_state = 0;
//		log("monkeyFSM()");
//	}
//	static MonkeyFSM *createObject(Monkey *mk){
//
//		MonkeyFSM *fsm = new MonkeyFSM();
//		fsm->initWithMonkey(mk);
//	}
//	bool initWithMonkey(Monkey *mk){
//		_monkey = mk;
//		return true;
//	}
//	void changeState(State *newState){
//		State *oldState = _state;
//		_state = newState;
//		if (oldState){
//			delete oldState;
//		}
//
//	}
//
//	virtual void update(float dt){
//		if (_state){
//			_state->execute(_monkey);
//		}
//	}
//private:
//	State *_state;
//	Monkey* _monkey;
//
//};
//
//#endif