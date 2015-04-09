//#include "WalkState.h"
//#include "StopState.h"
//#include "TurnState.h"
//
//void  WalkState::execute(Monkey * ml){
//	ml->walk();
//	if (ml->isWalkOutBorder())	{
//		ml->ChangeState(new TurnState());
//		ml->turn();
//	}
//	else if (ml->isWalKTimeout()	){
//		ml->ChangeState(new StopState());
//		ml->stop();
//	}
//}