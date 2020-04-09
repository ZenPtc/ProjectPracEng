/*#include"func.h"
using namespace sf;

    //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);

    //create button and set position
    Bton Back(100,40,80,50);
    Bton T(70,50,w_width/4,600);
    Bton F(70,50,w_width/2+w_width/4,600);
    RectangleShape btonBack(Vector2f(Back.Lx,Back.Ly));
    btonBack.setPosition(Back.posx,Back.posy);
    btonBack.setOrigin(Back.Lx/2,Back.Ly/2);
    RectangleShape btonT(Vector2f(T.Lx,T.Ly));
    btonT.setPosition(T.posx,T.posy);
    btonT.setOrigin(T.Lx/2,T.Ly/2);
    RectangleShape btonF(Vector2f(F.Lx,F.Ly));
    btonF.setPosition(F.posx,F.posy);
    btonF.setOrigin(F.Lx/2,F.Ly/2);

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
        window.draw(btonT);
        window.draw(btonF);
        window.display();
    }
*/
