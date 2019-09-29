#pragma once

#include "Side.h"
using namespace std;

class Mega{
private:
	Side megaminx[13];
	const int edgeStickers[12][12] = {
		{0,1,1,1,1,1,2,2,2,2,2,4},
		{1,0,1,2,2,1,1,1,2,4,2,2},
		{1,1,0,1,2,2,2,1,1,2,4,2},
		{1,2,1,0,1,2,4,2,1,1,2,2},
		{1,2,2,1,0,1,2,4,2,1,1,2},
		{1,1,2,2,1,0,1,2,4,2,1,2},
		{2,1,2,4,2,1,0,1,2,2,1,1},
		{2,1,1,2,4,2,1,0,1,2,2,1},
		{2,2,1,1,2,4,2,1,0,1,2,1},
		{2,4,2,1,1,2,2,2,1,0,1,1},
		{2,2,4,2,1,1,1,2,2,1,0,1},
		{4,2,2,2,2,2,1,1,1,1,1,0}
	};
	const int cornerStickers[12][12] = {
		{0,1,1,1,1,1,2,2,2,2,2,3},
		{1,0,1,2,2,1,1,1,2,3,2,2},
		{1,1,0,1,2,2,2,1,1,2,3,2},
		{1,2,1,0,1,2,3,2,1,1,2,2},
		{1,2,2,1,0,1,2,3,2,1,1,2},
		{1,1,2,2,1,0,1,2,3,2,1,2},
		{2,1,2,3,2,1,0,1,2,2,1,1},
		{2,1,1,2,3,2,1,0,1,2,2,1},
		{2,2,1,1,2,3,2,1,0,1,2,1},
		{2,3,2,1,1,2,2,2,1,0,1,1},
		{2,2,3,2,1,1,1,2,2,1,0,1},
		{3,2,2,2,2,2,1,1,1,1,1,0}
	};
public:

	//The next function initializes/resets the Mega to the correct
	//colors without actually solving.
	void ResetMegaColors();

	//The next functions are used to turn a side of the Mega. 
	//They require an input of the Mega and all its sides, as well
	//as the current color of the center piece.
	void TurnTopClock(const int CurrColor);
	void TurnTopCountClock(const int CurrColor);

	void TurnTopLeftClock(const int CurrColor);

	void TurnTopLeftCountClock(const int CurrColor);

	void TurnBotLeftClock(const int CurrColor);

	void TurnBotLeftCountClock(const int CurrColor);

	void TurnBotRightClock(const int CurrColor);

	void TurnBotRightCountClock(const int CurrColor);

	void TurnTopRightClock(const int CurrColor);

	void TurnTopRightCountClock(const int CurrColor);

	//This function uses spaces and tabes to precisly position the 
	//output in the correct way.
	void DisplayMega();

	//The next function is used to randomize the orientation of
	//the megaminx. It creates two random numbers used to choose a
	//direction to turn and what side to use the the turn on. 
	void RotationRandomizer(int k);

	//Next function returns the manhatten distance by using the search tables above it
	double retHval();

	//Equal to operator for two megaminx arrays
	bool operator==(const Mega & mega) const;
	bool operator!=(const Mega & mega) const;
	void operator = ( Mega & mega);

};