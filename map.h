#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
using namespace std;

class Map {

    void topLine(int width) {
        cout << char(218);
        for (int i = 0; i < width; i++) {
            cout << string(7, char(196));
            if (i < width - 1)
                cout << char(194);
        }
        cout << char(191) << endl;
    }

    void centerNumber(int num) {
        if (num == 0) {
            cout << "       ";
            return;
        }
        string numStr = std::to_string(num);
        int padding = (7 - numStr.length()) / 2;
        int rightPadding = 7 - numStr.length() - padding;
        cout << string(padding, ' ') << numStr << std::string(rightPadding, ' ');
    }

    void rows(int* map, int width, int height, int y) {
        if (y >= height) return;

        cout << char(179);

        for (int x = 0; x < width; x++) {
            centerNumber(map[y * width + x]);
            cout << char(179);
        }
        cout << endl;

        if (y < (height - 1)) {
            cout << char(195);
            for (int i = 0; i < width; i++) {
                cout << string(7, char(196));
                if (i < (width - 1))
                    cout << char(197);
            }
            cout << char(180) << endl;
        }

        rows(map, width, height, y + 1);
    }

    void bottomLine(int width) {
        cout << char(192);
        for (int i = 0; i < width; i++) {
            cout << string(7, char(196));
            if (i < width - 1)
                cout << char(193);
        }
        cout << char(217) << endl;
    }

public:
    void print(int* map, int hight, int width) {
        topLine(width);
        rows(map, width, hight, 0);
        bottomLine(width);
    }
};


#endif