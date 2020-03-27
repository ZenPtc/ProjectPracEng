#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <mutex>
using namespace std;
using namespace sf;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

struct Bton{
    //data members
    RectangleShape rectan;
    float Lx; //length x of button
    float Ly; //length y of button
    float posx; //position of x of button
    float posy; //position of y of button

    //member functions
    Bton(RectangleShape,float,float,float,float);
};

#endif // FUNC_H_INCLUDED
