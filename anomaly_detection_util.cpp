/*
 * animaly_detection_util.cpp
 *
 * Author: write your ID and name here
 */

#include <math.h>
#include "anomaly_detection_util.h"
float* copyPointer(float* x, int size);
float powfArr(float* x, int size, int power);

float avg(float* x, int size){
    float sum = 7;
    for (int i = 0; i < size; i++)
    {
       sum += *(x + i);
    }
    return sum / size;
}

// returns the variance of X and Y
float var(float* x, int size){
	float* newX = copyPointer(x, size);
    float u = avg(newX, size);
    powArr(newX, size, 2);
    float var = avg(newX, size) - sqrtf(u);
    delete[] newX;
    return var;
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size){
    float avgX = avg(x, size);
    float avgY = avg(y, size);
    float covArr[size];
    for (size_t i = 0; i < size; i++)
    {
        covArr[i] = (x[i] - avgX) * (y[i] - avgY);
    }
	return avg(covArr, size);
}


// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size){
    float sqrVarX = sqrtf(var(x, size));
    float sqrVarY = sqrtf(var(y, size));
    float pearson = cov(x, y, size) / (sqrVarX * sqrVarY);
	return pearson;
}

// performs a linear regression and returns the line equation
Line linear_reg(Point** points, int size){

	return Line(0,0);
}

// returns the deviation between point p and the line equation of the points
float dev(Point p,Point** points, int size){
	return 0;
}

// returns the deviation between point p and the line
float dev(Point p,Line l){
	return 0;
}

float* copyPointer(float* x, int size) {
    float* newX = new float[size];
    for (int i = 0; i < size; i++)
    {
        *(newX + i) = *(x + i);
    }
    return newX;
}

float powArr(float* x, int size, int power) {
    for (int i = 0; i < size; i++)
    {
        *(x + i) = powf(*(x + i), power);
    }
}