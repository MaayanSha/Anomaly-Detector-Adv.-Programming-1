//
// Created by Maayan Shavit on 24/10/2021.
//

/*
 * animaly_detection_util.cpp
 *
 * Author: write your ID and name here
 */

#include <math.h>
#include "anomaly_detection_util.h"

float* copyPointer(float* x, int size);
void powfArr(float* x, int size, int power);

float avg(float* x, int size){
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(x + i);
    }
    return (sum / size);
}

// returns the variance of X and Y
float var(float* x, int size){
    float* newX = copyPointer(x, size);
    float u = avg(newX, size);
    powfArr(newX, size, 2);
    float var = avg(newX, size) - pow(u, 2);
    delete[] newX;
    return var;
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size){
    float avgX = avg(x, size);
    float avgY = avg(y, size);
    float covArr[size];
    for (size_t i = 0; i < size; i++) {
        covArr[i] = (x[i] - avgX) * (y[i] - avgY);
    }
    return avg(covArr, size);
}


// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size){
    float sqrVarX = sqrt(var(x, size));
    float sqrVarY = sqrt(var(y, size));
    float pearson = cov(x, y, size) / (sqrVarX * sqrVarY);
    return pearson;
}

float* copyPointer(float* x, int size) {
    float* newX = new float[size];
    for (int i = 0; i < size; i++)
    {
        newX[i] = x[i];
    }
    return newX;
}

void powfArr(float* x, int size, int power) {
    for (int i = 0; i < size; i++)
    {
        x[i] = pow(x[i], power);
    }
}
// performs a linear regression and return s the line equation
Line linear_reg(Point** points, int size) {
    Line reg;
    float xArr[size];
    float yArr[size];
    for (size_t i = 0; i < size; i++) {
        xArr[i] = points[i]->x;
        yArr[i] = points[i]->y;
    }

    float a = ((cov(xArr,yArr, size))/(var(xArr,size)));

    float avrgX = avg(xArr, size);
    float avrgY = avg(yArr, size);
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

