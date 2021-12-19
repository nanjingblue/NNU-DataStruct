//
// Created by cherry on 2021/12/14.
//
#include "gen_render.h"

void getRanderArray(int a[], int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 999;
    }
}

