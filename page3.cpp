/*#include"func.h"
using namespace sf;

    //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);

    //create button and set position
    Bton Back(100,40,80,50);
    Bton choice1(170,50,w_width/3,600);
    Bton choice2(170,50,w_width/3+170,600);
    RectangleShape btonBack(Vector2f(Back.Lx,Back.Ly));
    btonBack.setPosition(Back.posx,Back.posy);
    btonBack.setOrigin(Back.Lx/2,Back.Ly/2);
    RectangleShape btonchoice1(Vector2f(choice1.Lx,choice1.Ly));
    btonchoice1.setPosition(choice1.posx,choice1.posy);
    btonchoice1.setOrigin(choice1.Lx/2,choice1.Ly/2);
    RectangleShape btonchoice2(Vector2f(choice2.Lx,choice2.Ly));
    btonchoice2.setPosition(choice2.posx,choice2.posy);
    btonchoice2.setOrigin(choice2.Lx/2,choice2.Ly/2);

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(btonBack);
        window.draw(btonchoice1);
        window.draw(btonchoice2);
        window.display();
    }
*/
