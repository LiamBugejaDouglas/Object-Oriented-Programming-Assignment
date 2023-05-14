#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>

std::string defineOdd(std::string n);
std::string divideByTwo(std::string n);
std::string decimalStringToBinary(std::string n);
std::vector<bool> binaryStringToVectorBool(std::string n, int size);
std::vector<bool> twosComplement(std::vector<bool> result);
std::vector<bool> addition(std::vector<bool>num1, std::vector<bool>num2);

template <int T>
class myuint
{

private:

    int bits = T;
    std::vector<bool> binaryNumVec;

public:

    myuint();
    myuint(int num);
    myuint(std::string num);

    std::vector<bool> getVectorBool();
    void setNumber(std::vector<bool> binary);

    myuint<T> operator<<(int num);
    myuint<T> operator>>(int num);

    myuint<T> operator+(myuint<T> num);
    myuint<T> operator-(myuint<T> num);

    bool operator==(myuint<T> num);
    bool operator>(myuint<T> num);

    myuint<T> operator-=(myuint<T> num);

    myuint<T> operator*(myuint<T> num);
    myuint<T> operator/(myuint<T> num);
    myuint<T> operator%(myuint<T> num);

    template <typename type>
    type convert();
};