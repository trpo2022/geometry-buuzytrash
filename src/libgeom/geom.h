#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
    double r;
} krug;

char* get_fig(char* str, char* figure);
void get_numbers(krug* circle, char* str);
int fig_check(char* figure, char* cir);
double perimeter(krug* circle);
double area(krug* circle);
