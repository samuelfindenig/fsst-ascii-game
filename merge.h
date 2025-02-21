#ifndef MERGE_H
#define MERGE_H
#include <iostream>
#include <Windows.h>
class Merge{
    void shiftRight(int* map, int width, int height, int i) {
        for (int k = 0; k < width - 1; k++)
            for (int j = width - 1; j > 0; j--)
                if (map[i * width + j] == 0) {
                    map[i * width + j] = map[i * width + j - 1];
                    map[i * width + j - 1] = 0;
                }
    }

    void right(int* map, int width, int height) {
        for (int i = 0; i < height; i++) {
            shiftRight(map, width, height, i);

            for (int j = width - 1; j > 0; j--)
                if (map[i * width + j] == map[i * width + j - 1] && map[i * width + j] != 0) {
                    map[i * width + j] *= 2;
                    map[i * width + j - 1] = 0;
                }

            shiftRight(map, width, height, i);
        }
    }

    void shiftLeft(int* map, int width, int height, int i) {
        for (int k = 0; k < width - 1; k++)
            for (int j = 0; j < width - 1; j++)
                if (map[i * width + j] == 0) {
                    map[i * width + j] = map[i * width + j + 1];
                    map[i * width + j + 1] = 0;
                }
    }

    void left(int* map, int width, int height) {
        for (int i = 0; i < height; i++) {
            shiftLeft(map, width, height, i);

            for (int j = 0; j < width - 1; j++)
                if (map[i * width + j] == map[i * width + j + 1] && map[i * width + j] != 0) {
                    map[i * width + j] *= 2;
                    map[i * width + j + 1] = 0;
                }
            shiftLeft(map, width, height, i);
        }
    }

    void shiftUp(int* map, int width, int height, int j) {
        for (int k = 0; k < height - 1; k++) {
            for (int i = 0; i < height - 1; i++) {
                if (map[i * width + j] == 0) {
                    map[i * width + j] = map[(i + 1) * width + j];
                    map[(i + 1) * width + j] = 0;
                }
            }
        }
    }

    void up(int* map, int width, int height) {
        for (int j = 0; j < width; j++) {
            shiftUp(map, width, height, j);

            for (int i = 0; i < height - 1; i++) {
                if (map[i * width + j] == map[(i + 1) * width + j] && map[i * width + j] != 0) {
                    map[i * width + j] *= 2;
                    map[(i + 1) * width + j] = 0;
                }
            }

            shiftUp(map, width, height, j);
        }
    }

    void shiftDown(int* map, int width, int height, int j) {
        for (int k = 0; k < height - 1; k++)
            for (int i = height - 1; i > 0; i--)
                if (map[i * width + j] == 0) {
                    map[i * width + j] = map[(i - 1) * width + j];
                    map[(i - 1) * width + j] = 0;
                }

    }

    void down(int* map, int width, int height) {
        for (int j = 0; j < width; j++) {
            shiftDown(map, width, height, j);

            for (int i = height - 1; i > 0; i--)
                if (map[i * width + j] == map[(i - 1) * width + j] && map[i * width + j] != 0) {
                    map[i * width + j] *= 2;
                    map[(i - 1) * width + j] = 0;
                }

            shiftDown(map, width, height, j);
        }
    }

public:
    void merge(int* map, int width, int height) {
        while (true) {

            if (GetAsyncKeyState(VK_UP)) {
                up(map, width, height);
                return;
            }
            else if (GetAsyncKeyState(VK_DOWN)) {
                down(map, width, height);
                return;
            }
            else if (GetAsyncKeyState(VK_LEFT)) {
                left(map, width, height);
                return;
            }
            else if (GetAsyncKeyState(VK_RIGHT)) {
                right(map, width, height);
                return;
            }
        }
    }
};


#endif