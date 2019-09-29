#include "Side.h"

void Side::initTopRow(int* values)
{
	for (int i = 0; i < 3; i++)
		TopRow[i] = values[i];
	TopRightRow[2] = TopRow[0];
	TopLeftRow[0] = TopRow[2];
}

void Side::initTopLeftRow(int * values)
{
	for (int i = 0; i < 3; i++)
		TopLeftRow[i] = values[i];
	TopRow[2] = TopLeftRow[0];
	BotLeftRow[0] = TopLeftRow[2];
}
void Side::initTopRightRow(int* values)
{
	for (int i = 0; i < 3; i++)
		TopRightRow[i] = values[i];
	BotRightRow[2] = TopRightRow[0];
	TopRow[0] = TopRightRow[2];
}
void Side::initBotRightRow(int* values)
{
	for (int i = 0; i < 3; i++)
		BotRightRow[i] = values[i];
	BotLeftRow[2] = BotRightRow[0];
	TopRightRow[0] = BotRightRow[2];
}
void Side::initBotLeftRow(int* values)
{
	for (int i = 0; i < 3; i++)
		BotLeftRow[i] = values[i];
	TopLeftRow[2] = BotLeftRow[0];
	BotRightRow[0] = BotLeftRow[2];
}
void Side::clockTurn() {
	int Temp[3];
	for (int i = 0; i < 3; i++) 
		Temp[i] = TopRow[i];
	initTopRow(TopLeftRow);
	initTopLeftRow(BotLeftRow);
	initBotLeftRow(BotRightRow);
	initBotRightRow(TopRightRow);
	initTopRightRow(Temp);
}
void Side::countclockTurn() {
	int Temp[3];
	for (int i = 0; i < 3; i++)
		Temp[i] = TopRow[i];
	initTopRow(TopRightRow);
	initTopRightRow(BotRightRow);
	initBotRightRow(BotLeftRow);
	initBotLeftRow(TopLeftRow);
	initTopLeftRow(Temp);
}

void Side::InitializeSide(int color) {
	int Colors[3] = { color,color,color };
	Center = color;
	initTopRow(Colors);
	initTopLeftRow(Colors);
	initTopRightRow(Colors);
	initBotRightRow(Colors);
	initBotLeftRow(Colors);
}