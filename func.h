#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
using namespace std;
using namespace sf;

struct Bton{
    //data members
    float Lx; //length x of button
    float Ly; //length y of button
    float posx; //position of x of button
    float posy; //position of y of button
    //member functions
    Bton(float,float,float,float);
};

#endif // FUNC_H_INCLUDED
