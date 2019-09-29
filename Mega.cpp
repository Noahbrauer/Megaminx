#include "Mega.h"
#include <cmath>

using namespace std;

void Mega::ResetMegaColors() {
	megaminx[0].InitializeSide(0);
	megaminx[1].InitializeSide(1);			//White
	megaminx[2].InitializeSide(2);			//Blue
	megaminx[3].InitializeSide(3);			//Red
	megaminx[4].InitializeSide(4);			//Green
	megaminx[5].InitializeSide(5);			//Purple
	megaminx[6].InitializeSide(6);			//Yellow
	megaminx[7].InitializeSide(7);			//Lgreen
	megaminx[8].InitializeSide(8);			//Pink
	megaminx[9].InitializeSide(9);			//Tan
	megaminx[10].InitializeSide(10);		//LBlue
	megaminx[11].InitializeSide(11);		//Orange
	megaminx[12].InitializeSide(12);		//Grey
}

void Mega::TurnTopClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].TopRow[i];
		megaminx[1].initTopRow(megaminx[6].TopRightRow);
		megaminx[6].initTopRightRow(megaminx[11].BotLeftRow);
		megaminx[11].initBotLeftRow(megaminx[10].BotRightRow);
		megaminx[10].initBotRightRow(megaminx[4].TopLeftRow);
		megaminx[4].initTopLeftRow(Temp);
		megaminx[5].clockTurn();
		break;
	case (2):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[2].TopRow[i];
		megaminx[2].initTopRow(megaminx[6].TopRow);
		megaminx[6].initTopRow(megaminx[5].TopRow);
		megaminx[5].initTopRow(megaminx[4].TopRow);
		megaminx[4].initTopRow(megaminx[3].TopRow);
		megaminx[3].initTopRow(Temp);
		megaminx[1].clockTurn();
		break;
	case (7):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[7].TopRow[i];
		megaminx[7].initTopRow(megaminx[8].TopRow);
		megaminx[8].initTopRow(megaminx[9].TopRow);
		megaminx[9].initTopRow(megaminx[10].TopRow);
		megaminx[10].initTopRow(megaminx[11].TopRow);
		megaminx[11].initTopRow(Temp);
		megaminx[12].clockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].TopRow[i];
		megaminx[12].initTopRow(megaminx[7].TopRightRow);
		megaminx[7].initTopRightRow(megaminx[2].BotLeftRow);
		megaminx[2].initBotLeftRow(megaminx[3].BotRightRow);
		megaminx[3].initBotRightRow(megaminx[9].TopLeftRow);
		megaminx[9].initTopLeftRow(Temp);
		megaminx[8].clockTurn();
		break;
	}
}
void Mega::TurnTopCountClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].TopRow[i];
		megaminx[1].initTopRow(megaminx[4].TopLeftRow);
		megaminx[4].initTopLeftRow(megaminx[10].BotRightRow);
		megaminx[10].initBotRightRow(megaminx[11].BotLeftRow);
		megaminx[11].initBotLeftRow(megaminx[6].TopRightRow);
		megaminx[6].initTopRightRow(Temp);
		megaminx[5].countclockTurn();
		break;
	case (2):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[2].TopRow[i];
		megaminx[2].initTopRow(megaminx[3].TopRow);
		megaminx[3].initTopRow(megaminx[4].TopRow);
		megaminx[4].initTopRow(megaminx[5].TopRow);
		megaminx[5].initTopRow(megaminx[6].TopRow);
		megaminx[6].initTopRow(Temp);
		megaminx[1].countclockTurn();
		break;

	case (7):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[7].TopRow[i];
		megaminx[7].initTopRow(megaminx[11].TopRow);
		megaminx[11].initTopRow(megaminx[10].TopRow);
		megaminx[10].initTopRow(megaminx[9].TopRow);
		megaminx[9].initTopRow(megaminx[8].TopRow);
		megaminx[8].initTopRow(Temp);
		megaminx[12].countclockTurn();
		break;
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].TopRow[i];
		megaminx[12].initTopRow(megaminx[9].TopLeftRow);
		megaminx[9].initTopLeftRow(megaminx[3].BotRightRow);
		megaminx[3].initBotRightRow(megaminx[2].BotLeftRow);
		megaminx[2].initBotLeftRow(megaminx[7].TopRightRow);
		megaminx[7].initTopRightRow(Temp);
		megaminx[8].countclockTurn();
		break;
	}
}

void Mega::TurnTopLeftClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].TopLeftRow[i];
		megaminx[1].initTopLeftRow(megaminx[5].TopRightRow);
		megaminx[5].initTopRightRow(megaminx[10].BotLeftRow);
		megaminx[10].initBotLeftRow(megaminx[9].BotRightRow);
		megaminx[9].initBotRightRow(megaminx[3].TopLeftRow);
		megaminx[3].initTopLeftRow(Temp);
		megaminx[4].clockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].TopLeftRow[i];
		megaminx[12].initTopLeftRow(megaminx[8].TopRightRow);
		megaminx[8].initTopRightRow(megaminx[3].BotLeftRow);
		megaminx[3].initBotLeftRow(megaminx[4].BotRightRow);
		megaminx[4].initBotRightRow(megaminx[10].TopLeftRow);
		megaminx[10].initTopLeftRow(Temp);
		megaminx[9].clockTurn();
		break;
	}
}
void Mega::TurnTopLeftCountClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].TopLeftRow[i];
		megaminx[1].initTopLeftRow(megaminx[3].TopLeftRow);
		megaminx[3].initTopLeftRow(megaminx[9].BotRightRow);
		megaminx[9].initBotRightRow(megaminx[10].BotLeftRow);
		megaminx[10].initBotLeftRow(megaminx[5].TopRightRow);
		megaminx[5].initTopRightRow(Temp);
		megaminx[4].countclockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].TopLeftRow[i];
		megaminx[12].initTopLeftRow(megaminx[10].TopLeftRow);
		megaminx[10].initTopLeftRow(megaminx[4].BotRightRow);
		megaminx[4].initBotRightRow(megaminx[3].BotLeftRow);
		megaminx[3].initBotLeftRow(megaminx[8].TopRightRow);
		megaminx[8].initTopRightRow(Temp);
		megaminx[9].countclockTurn();
		break;
	}
}

void Mega::TurnBotLeftClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].BotLeftRow[i];
		megaminx[1].initBotLeftRow(megaminx[4].TopRightRow);
		megaminx[4].initTopRightRow(megaminx[9].BotLeftRow);
		megaminx[9].initBotLeftRow(megaminx[8].BotRightRow);
		megaminx[8].initBotRightRow(megaminx[2].TopLeftRow);
		megaminx[2].initTopLeftRow(Temp);
		megaminx[3].clockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].BotLeftRow[i];
		megaminx[12].initBotLeftRow(megaminx[9].TopRightRow);
		megaminx[9].initTopRightRow(megaminx[4].BotLeftRow);
		megaminx[4].initBotLeftRow(megaminx[5].BotRightRow);
		megaminx[5].initBotRightRow(megaminx[11].TopLeftRow);
		megaminx[11].initTopLeftRow(Temp);
		megaminx[10].clockTurn();
		break;
	}
}
void Mega::TurnBotLeftCountClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].BotLeftRow[i];
		megaminx[1].initBotLeftRow(megaminx[2].TopLeftRow);
		megaminx[2].initTopLeftRow(megaminx[8].BotRightRow);
		megaminx[8].initBotRightRow(megaminx[9].BotLeftRow);
		megaminx[9].initBotLeftRow(megaminx[4].TopRightRow);
		megaminx[4].initTopRightRow(Temp);
		megaminx[3].countclockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].BotLeftRow[i];
		megaminx[12].initBotLeftRow(megaminx[11].TopLeftRow);
		megaminx[11].initTopLeftRow(megaminx[5].BotRightRow);
		megaminx[5].initBotRightRow(megaminx[4].BotLeftRow);
		megaminx[4].initBotLeftRow(megaminx[9].TopRightRow);
		megaminx[9].initTopRightRow(Temp);
		megaminx[10].countclockTurn();
		break;
	}
}

void Mega::TurnBotRightClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].BotRightRow[i];
		megaminx[1].initBotRightRow(megaminx[3].TopRightRow);
		megaminx[3].initTopRightRow(megaminx[8].BotLeftRow);
		megaminx[8].initBotLeftRow(megaminx[7].BotRightRow);
		megaminx[7].initBotRightRow(megaminx[6].TopLeftRow);
		megaminx[6].initTopLeftRow(Temp);
		megaminx[2].clockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].BotRightRow[i];
		megaminx[12].initBotRightRow(megaminx[10].TopRightRow);
		megaminx[10].initTopRightRow(megaminx[5].BotLeftRow);
		megaminx[5].initBotLeftRow(megaminx[6].BotRightRow);
		megaminx[6].initBotRightRow(megaminx[7].TopLeftRow);
		megaminx[7].initTopLeftRow(Temp);
		megaminx[11].clockTurn();
		break;
	}
}
void Mega::TurnBotRightCountClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].BotRightRow[i];
		megaminx[1].initBotRightRow(megaminx[6].TopLeftRow);
		megaminx[6].initTopLeftRow(megaminx[7].BotRightRow);
		megaminx[7].initBotRightRow(megaminx[8].BotLeftRow);
		megaminx[8].initBotLeftRow(megaminx[3].TopRightRow);
		megaminx[3].initTopRightRow(Temp);
		megaminx[2].countclockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].BotRightRow[i];
		megaminx[12].initBotRightRow(megaminx[7].TopLeftRow);
		megaminx[7].initTopLeftRow(megaminx[6].BotRightRow);
		megaminx[6].initBotRightRow(megaminx[5].BotLeftRow);
		megaminx[5].initBotLeftRow(megaminx[10].TopRightRow);
		megaminx[10].initTopRightRow(Temp);
		megaminx[11].countclockTurn();
		break;
	}
}

void Mega::TurnTopRightClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].TopRightRow[i];
		megaminx[1].initTopRightRow(megaminx[2].TopRightRow);
		megaminx[2].initTopRightRow(megaminx[7].BotLeftRow);
		megaminx[7].initBotLeftRow(megaminx[11].BotRightRow);
		megaminx[11].initBotRightRow(megaminx[5].TopLeftRow);
		megaminx[5].initTopLeftRow(Temp);
		megaminx[6].clockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].TopRightRow[i];
		megaminx[12].initTopRightRow(megaminx[11].TopRightRow);
		megaminx[11].initTopRightRow(megaminx[6].BotLeftRow);
		megaminx[6].initBotLeftRow(megaminx[2].BotRightRow);
		megaminx[2].initBotRightRow(megaminx[8].TopLeftRow);
		megaminx[8].initTopLeftRow(Temp);
		megaminx[7].clockTurn();
		break;
	}
}
void Mega::TurnTopRightCountClock(const int CurrColor) {
	int Temp[3];
	switch (CurrColor) {
	case (1):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[1].TopRightRow[i];
		megaminx[1].initTopRightRow(megaminx[5].TopLeftRow);
		megaminx[5].initTopLeftRow(megaminx[11].BotRightRow);
		megaminx[11].initBotRightRow(megaminx[7].BotLeftRow);
		megaminx[7].initBotLeftRow(megaminx[2].TopRightRow);
		megaminx[2].initTopRightRow(Temp);
		megaminx[6].countclockTurn();
		break;
	case (12):
		for (int i = 0; i < 3; i++)
			Temp[i] = megaminx[12].TopRightRow[i];
		megaminx[12].initTopRightRow(megaminx[8].TopLeftRow);
		megaminx[8].initTopLeftRow(megaminx[2].BotRightRow);
		megaminx[2].initBotRightRow(megaminx[6].BotLeftRow);
		megaminx[6].initBotLeftRow(megaminx[11].TopRightRow);
		megaminx[11].initTopRightRow(Temp);
		megaminx[7].countclockTurn();
		break;
	}
}


void Mega::DisplayMega() {
	cout << "\n\n";
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << megaminx[10].BotLeftRow[2] << "\t" << megaminx[10].BotLeftRow[1] << "\t"
		<< megaminx[10].BotLeftRow[0] << "\t\t\t\t" << megaminx[9].BotRightRow[2] << "\t" << megaminx[9].BotRightRow[1]
		<< "\t" << megaminx[9].BotRightRow[0] << endl;
	cout << "\t\t\t\t\t\t" << megaminx[4].BotLeftRow[2] << endl;
	cout << "\t\t\t\t\t" << megaminx[4].BotRightRow[1] << "\t\t" << megaminx[4].BotLeftRow[1] << "\t\t\t\t\t\t    "
		<< megaminx[10].BotRightRow[1] << "\t\t\t    " << megaminx[10].TopLeftRow[1] << "\t\t\t    " << megaminx[9].TopRightRow[1]
		<< "\t\t\t    " << megaminx[9].BotLeftRow[1] << endl;
	cout << "\t\t\t\t" << megaminx[4].BotRightRow[2] << "\t\t\t\t" << megaminx[4].BotLeftRow[0]
		<< "\t\t\t\t\t\t\t" << megaminx[10].Center << "\t\t\t\t\t\t" << megaminx[9].Center << endl;
	cout << "\t\t\t\t\t\t" << megaminx[4].Center << "\t\t\t\t\t\t\t" << megaminx[10].BotRightRow[2]
		<< "\t\t\t\t" << megaminx[10].TopLeftRow[0] << "\t\t" << megaminx[9].TopRightRow[2] << "\t\t\t\t"
		<< megaminx[9].BotLeftRow[0] << endl;
	cout << "\t\t" << megaminx[3].TopLeftRow[2] << "\t\t    " << megaminx[4].TopRightRow[1] << "\t\t\t    "
		<< megaminx[4].TopLeftRow[1] << "\t\t\t" << megaminx[5].BotRightRow[2] << "\t\t\t\t" << megaminx[10].TopRightRow[1]
		<< "\t\t" << megaminx[10].TopRow[1] << "\t\t" << megaminx[12].TopLeftRow[2] << "\t\t" << megaminx[9].TopRow[1]
		<< "\t\t" << megaminx[9].TopLeftRow[1] << endl;
	cout << "\t" << megaminx[3].BotLeftRow[1] << "\t\t" << megaminx[3].TopLeftRow[1] << "\t\t\t\t\t\t"
		<< megaminx[5].TopRightRow[1] << "\t\t" << megaminx[5].BotRightRow[1] << "\t\t\t\t" << megaminx[10].TopRow[0]
		<< "\t\t" << megaminx[12].BotLeftRow[1] << "\t\t" << megaminx[12].TopLeftRow[1] << "\t\t" << megaminx[9].TopRow[2] << endl;
	cout << megaminx[3].BotLeftRow[2] << "\t\t\t\t" << megaminx[3].TopRow[2] << "\t" << megaminx[4].TopRow[0] << "\t"
		<< megaminx[4].TopRow[1] << "\t" << megaminx[4].TopRow[2] << "\t" << megaminx[5].TopRow[0] << "\t\t\t\t"
		<< megaminx[5].BotRightRow[0] << "\t\t\t\t" << megaminx[12].BotLeftRow[2] << "\t\t\t\t" << megaminx[12].TopRow[2] << endl;
	cout << "\t\t" << megaminx[3].Center << "\t\t\t" << megaminx[1].TopLeftRow[2] << "\t" << megaminx[1].TopLeftRow[1]
		<< "\t" << megaminx[1].TopLeftRow[0] << "\t\t\t" << megaminx[5].Center << "\t\t\t" << megaminx[11].TopLeftRow[2]
		<< "\t" << megaminx[11].TopLeftRow[1] << "\t" << megaminx[11].TopLeftRow[0] << "\t\t\t" << megaminx[12].Center
		<< "\t\t\t" << megaminx[8].TopRightRow[2] << "\t" << megaminx[8].TopRightRow[1] << "\t" << megaminx[8].TopRightRow[0]
		<< endl;
	cout << "    " << megaminx[3].BotRightRow[1] << "\t\t\t    " << megaminx[3].TopRow[1] << "\t\t\t\t\t    "
		<< megaminx[5].TopRow[1] << "\t\t\t    " << megaminx[5].BotLeftRow[1] << "\t\t\t\t\t    " << megaminx[12].BotRightRow[1]
		<< "\t\t\t    " << megaminx[12].TopRow[1] << endl;
	cout << "\t\t\t\t    " << megaminx[1].BotLeftRow[1] << "\t\t\t    " << megaminx[1].TopRow[1] << "\t\t\t\t\t    "
		<< megaminx[11].BotLeftRow[1] << "\t\t\t    " << megaminx[11].TopRow[1] << "\t\t\t\t\t    " << megaminx[8].TopRow[1]
		<< "\t\t\t    " << megaminx[8].BotRightRow[1] << endl;
	cout << "\t" << megaminx[3].TopRightRow[0] << "\t" << megaminx[3].TopRightRow[1] << "\t" << megaminx[3].TopRightRow[2]
		<< "\t\t\t" << megaminx[1].Center << "\t\t\t" << megaminx[5].TopLeftRow[0] << "\t" << megaminx[5].TopLeftRow[1] << "\t"
		<< megaminx[5].TopLeftRow[2] << "\t\t\t" << megaminx[11].Center << "\t\t\t" << megaminx[12].TopRightRow[0] << "\t"
		<< megaminx[12].TopRightRow[1] << "\t" << megaminx[12].TopRightRow[2] << "\t\t\t" << megaminx[8].Center << endl;
	cout << "\t\t\t\t" << megaminx[1].BotRightRow[0] << "\t\t\t\t" << megaminx[1].TopRightRow[2] << "\t\t\t\t"
		<< megaminx[11].BotRightRow[0] << "\t\t\t\t" << megaminx[11].TopRightRow[2] << "\t" << megaminx[7].TopRow[2] << "\t"
		<< megaminx[7].TopRow[1] << "\t" << megaminx[7].TopRow[0] << "\t" << megaminx[8].TopLeftRow[0] << "\t\t\t\t"
		<< megaminx[8].BotLeftRow[2] << endl;
	cout << "\t\t\t" << megaminx[2].TopRow[2] << "\t\t" << megaminx[1].BotRightRow[1] << "\t\t" << megaminx[1].TopRightRow[1]
		<< "\t\t" << megaminx[6].TopRow[0] << "\t\t\t\t" << megaminx[11].BotRightRow[1] << "\t\t" << megaminx[11].TopRightRow[1]
		<< "\t\t\t\t\t\t" << megaminx[8].TopLeftRow[1] << "\t\t" << megaminx[8].BotLeftRow[1] << endl;
	cout << "\t\t" << megaminx[2].TopLeftRow[1] << "\t\t" << megaminx[2].TopRow[1] << "\t\t" << megaminx[1].TopRightRow[0]
		<< "\t\t" << megaminx[6].TopRow[1] << "\t\t" << megaminx[6].TopRightRow[1] << "\t\t\t\t" << megaminx[11].BotRightRow[2]
		<< "\t\t    " << megaminx[7].TopLeftRow[1] << "\t\t\t    " << megaminx[7].TopRightRow[1] << "\t\t\t"
		<< megaminx[8].TopLeftRow[2] << endl;
	cout << "\t" << megaminx[2].TopLeftRow[2] << "\t\t\t\t" << megaminx[2].TopRow[0] << "\t\t" << megaminx[6].TopRow[2]
		<< "\t\t\t\t" << megaminx[6].TopRightRow[0] << "\t\t\t\t\t\t\t" << megaminx[7].Center << endl;
	cout << "\t\t\t" << megaminx[2].Center << "\t\t\t\t\t\t" << megaminx[6].Center << "\t\t\t\t\t\t\t" << megaminx[7].TopLeftRow[2]
		<< "\t\t\t\t" << megaminx[7].TopRightRow[0] << endl;
	cout << "\t    " << megaminx[2].BotLeftRow[1] << "\t\t\t    " << megaminx[2].TopRightRow[1] << "\t\t\t    "
		<< megaminx[6].TopLeftRow[1] << "\t\t\t    " << megaminx[6].BotRightRow[1] << "\t\t\t\t\t\t\t" << megaminx[7].BotLeftRow[1]
		<< "\t\t" << megaminx[7].BotRightRow[1] << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << megaminx[7].BotLeftRow[2] << endl;
	cout << "\t\t" << megaminx[2].BotRightRow[0] << "\t" << megaminx[2].BotRightRow[1] << "\t" << megaminx[2].BotRightRow[2]
		<< "\t\t\t\t" << megaminx[6].BotLeftRow[0] << "\t" << megaminx[6].BotLeftRow[1] << "\t" << megaminx[6].BotLeftRow[2]
		<< endl;
}

void Mega::RotationRandomizer(int k) {
	srand((unsigned)time(0));
	int Random_Rotation;
	for (int index = 0; index < k; index++) {
		Random_Rotation = (rand() % 11);
		if (Random_Rotation == 11) {
			TurnTopClock(7);
		}
		if (Random_Rotation == 10) {
			TurnTopRightClock(12);
		}
		if (Random_Rotation == 9) {
			TurnBotRightClock(12);
		}
		if (Random_Rotation == 8) {
			TurnBotLeftClock(12);
		}
		if (Random_Rotation == 7) {
			TurnTopLeftClock(12);
		}
		if (Random_Rotation == 6) {
			TurnTopClock(12);
		}
		if (Random_Rotation == 5) {
			TurnTopClock(2);
		}
		if (Random_Rotation == 4) {
			TurnTopRightClock(1);
		}
		if (Random_Rotation == 3) {
			TurnBotRightClock(1);
		}
		if (Random_Rotation == 2) {
			TurnBotLeftClock(1);
		}
		if (Random_Rotation == 1) {
			TurnTopLeftClock(1);
		}
		if (Random_Rotation == 0) {
			TurnTopClock(1);
		}
		//cout << retHval() << "\t" << Random_Rotation << "\n";
	}
}

double Mega::retHval() {
	double h = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 9; j >= 0; j--) {
			if (j == 9) {
				h += cornerStickers[megaminx[i].TopRow[0] - 1][i - 1];
			}
			else if (j == 8) {
				h += edgeStickers[megaminx[i].TopRow[1] - 1][i - 1];
			}
			else if (j == 7) {
				h += cornerStickers[megaminx[i].TopLeftRow[0] - 1][i - 1];
			}
			else if (j == 6) {
				h += edgeStickers[megaminx[i].TopLeftRow[1] - 1][i - 1];
			}
			else if (j == 5) {
				h += cornerStickers[megaminx[i].BotLeftRow[0] - 1][i - 1];
			}
			else if (j == 4) {
				h += edgeStickers[megaminx[i].BotLeftRow[1] - 1][i - 1];
			}
			else if (j == 3) {
				h += cornerStickers[megaminx[i].BotRightRow[0] - 1][i - 1];
			}
			else if (j == 2) {
				h += edgeStickers[megaminx[i].BotRightRow[1] - 1][i - 1];
			}
			else if (j == 1) {
				h += cornerStickers[megaminx[i].TopRightRow[0] - 1][i - 1];
			}
			else if (j == 0) {
				h += edgeStickers[megaminx[i].TopRightRow[1] - 1][i - 1];
			}

		}
	}
	h = ceil(h / 15);
	return h;
}

bool Mega::operator == (const Mega& mega) const{
	for (int j = 12; j >= 1; j--) {
		for (int i = 0; i < 3; i++) {
			if (megaminx[j].TopRow[i] != mega.megaminx[j].TopRow[i]) {
				return false;
			}
			if (megaminx[j].TopLeftRow[i] != mega.megaminx[j].TopLeftRow[i]) {
				return false;
			}
			if (megaminx[j].BotLeftRow[i] != mega.megaminx[j].BotLeftRow[i]) {
				return false;
			}
			if (megaminx[j].BotRightRow[i] != mega.megaminx[j].BotRightRow[i]) {
				return false;
			}
			if (megaminx[j].TopRightRow[i] != mega.megaminx[j].TopRightRow[i]) {
				return false;
			}
		}
	}
	return true;
}

bool Mega::operator!=(const Mega & mega) const
{
	for (int j = 12; j >= 1; j--) {
		for (int i = 0; i < 3; i++) {
			if (megaminx[j].TopRow[i] == mega.megaminx[j].TopRow[i]) {
				return false;
			}
			if (megaminx[j].TopLeftRow[i] == mega.megaminx[j].TopLeftRow[i]) {
				return false;
			}
			if (megaminx[j].BotLeftRow[i] == mega.megaminx[j].BotLeftRow[i]) {
				return false;
			}
			if (megaminx[j].BotRightRow[i] == mega.megaminx[j].BotRightRow[i]) {
				return false;
			}
			if (megaminx[j].TopRightRow[i] == mega.megaminx[j].TopRightRow[i]) {
				return false;
			}
		}
	}
	return true;
}


void Mega::operator = ( Mega& mega) {
	for (int j = 12; j >= 1; j--) {
		for (int i = 0; i < 3; i++) {
			(megaminx)[j].TopRow[i] = mega.megaminx[j].TopRow[i];
			(megaminx)[j].TopLeftRow[i] = mega.megaminx[j].TopLeftRow[i];
			(megaminx)[j].BotLeftRow[i] = mega.megaminx[j].BotLeftRow[i];
			(megaminx)[j].BotRightRow[i] = mega.megaminx[j].BotRightRow[i];
			(megaminx)[j].TopRightRow[i] = mega.megaminx[j].TopRightRow[i];
		}
		(megaminx)[j].Center = mega.megaminx[j].Center;
	}
}