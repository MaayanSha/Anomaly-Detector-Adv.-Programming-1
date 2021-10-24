//
// Created by Maayan Shavit on 21/10/2021.
//
#include "Line.h"

class Line{
public:
    float a,b;
    Line():a(0),b(0){}
    Line(float a, float b):a(a),b(b){}
    float f(float x){
        return a*x+b;
    }
};