/*
 * animaly_detection_util.cpp
 *
 * Author: write your ID and name here
 */

#include <math.h>
#include "anomaly_detection_util.h"
float* copy(float* x, int size);
float sum(float* x, int size);
float sqrtfArr(float* x, int size, int power);

float avg(float* x, int size){
	return 0;
}

// returns the variance of X and Y
float var(float* x, int size){
	float* newX = copy(x, size);
    float u = sum(newX, size) / size;
    sqrtfArr(newX, size, 2);
    float var = (sum(newX, size) / size) - sqrtf(u);
    delete[] newX;
    return var;
}

// returns the covariance of X and Y
float cov(float* x, float* y, int size){
	return 0;
}


// returns the Pearson correlation coefficient of X and Y
float pearson(float* x, float* y, int size){
	return 0;
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

float* copy(float* x, int size) {
    float* newX = new float[size];
    for (int i = 0; i < size; i++)
    {
        *(newX + i) = *(x + i);
    }
    return newX;
}

float sum(float* x, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
       sum += *(x + i);
    }
    return sum;
}

float sqrtfArr(float* x, int size, int power) {
    for (int i = 0; i < size; i++)
    {
        *(x + i) = sqrtf(*(x + i));
    }
}


