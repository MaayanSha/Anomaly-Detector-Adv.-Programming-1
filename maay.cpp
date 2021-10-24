#include <iostream>
#include "Line.h"
#include "Point.h"
#include <cmath>

// returns the variance of X and Y
float var(float* x, int size);
// returns the covariance of X and Y
float cov(float* x, float* y, int size);
// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size);

class Line{
public:
    float a,b;
    Line():a(0),b(0){}
    Line(float a, float b):a(a),b(b){}
    float f(float x){
        return a*x+b;
    }
};
class Point{
public:
    float x,y;
    Point(float x, float y):x(x),y(x){}
};

// performs a linear regression and return s the line equation
Line linear_reg(Point** points, int size) {
    Line reg;
    float a = (cov((*points)->x,(*points)->y, size))/var((*points)->x,size);
    float sumX;
    float sumY;

    for (int i = 0; i < size; i++) {
        sumX += (*points + i)->x;
        sumY += (*points + i)->y;
    }
    float avrgX = sumX / size;
    float avrgY = sumY / size;
    float b = avrgY - (avrgX * a);
    reg.a = a;
    reg.b = b;
    return reg;

}
// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size){
    Line lineReg = linear_reg(points,size);
    float deviationP = abs (p.y - lineReg.f(p.x));
    return deviationP;
}
// returns the deviation between point p and the line
float dev(Point p,Line l){
    float deviationP = abs (p.y - l.f(p.x));
    return deviationP;
}