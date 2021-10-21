
float* copy(float* x, int size);
float sum(float* x, int size);
float pow(float x, int power);
float powArr(float* x, int size, int power);

float var(float* x, int size) {
    float* newX = copy(x, size);
    float u = (1 / size) * sum(newX, size);
    powArr(newX, size, 2);
    float var = ((1 / size) * sum(newX, size)) - sqr(u, 2);
    delete[] newX;
    return var;
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

float pow(float x, int power) {
    for (int i = 0; i < power; i++)
    {
        x *= x;
    }
    return x;
}

float powArr(float* x, int size, int power) {
    for (int i = 0; i < size; i++)
    {
        *(x + i) = pow(*(x + i), power);
    }
}