#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Creating the structure to hold the tiles/colors for each side. 
//After that I initialize each side with the initialize size function.
class Side {
public:
	int Center;
	int TopRow[3];
	int TopLeftRow[3];
	int BotLeftRow[3];
	int BotRightRow[3];
	int TopRightRow[3];


	void initTopRow(int* values);
	void initTopLeftRow(int* values);
	void initTopRightRow(int* values);
	void initBotRightRow(int* values);
	void initBotLeftRow(int* values);

	void clockTurn();

	void countclockTurn();

	void InitializeSide(int color);

};