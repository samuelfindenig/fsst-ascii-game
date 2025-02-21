#include <iostream>
#include "map.h"
#include "merge.h"

#define HIGHT 4
#define WIDTH 4

class Game {
	int width = WIDTH;
	int hight = HIGHT;
	int map[WIDTH * HIGHT] = {};

	int randomInt(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	void cursorGoToXY(int spalte, int zeile) {
		COORD coord;
		coord.X = spalte;
		coord.Y = zeile;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	bool numToMap() {
		int freespacesIndex[HIGHT * WIDTH];
		int freespace = 0;
		
		for (int i = 0; i < HIGHT * WIDTH; i++) 
			if (map[i] == 0) {
				freespacesIndex[freespace] = i;
				freespace++;
			}

		if (freespace == 0)
			return false;

		map[freespacesIndex[randomInt(0, freespace-1)]] = randomInt(1, 2) * 2;
		return true;
	}

	public:
		Game() {
			while (numToMap()) {
				Map().print(map, width, hight);
				Sleep(250);
				Merge().merge(map, width, hight);
				cursorGoToXY(0, 0);
			}
			cout << "Game Over";
		}
		
};



void cursorVisible(bool visible){
	CONSOLE_CURSOR_INFO info;
	HANDLE out;
	info.bVisible = visible;
	info.dwSize = 1;
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(out, &info);
}

void Init() {
	srand(time(NULL));
	cursorVisible(false);
}


int main() {
	Init();
	Game();

	return 0;
}