#include"func.h"
using namespace sf;

int main()
{
    //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);

    //create button and set position
    Bton A(350,70,76,275);
    Bton B(350,70,76,400);
    Bton C(350,70,76,525);
    RectangleShape btonA(Vector2f(A.Lx,A.Ly));
    btonA.setPosition(A.posx,A.posy);
    RectangleShape btonB(Vector2f(B.Lx,B.Ly));
    btonB.setPosition(B.posx,B.posy);
    RectangleShape btonC(Vector2f(C.Lx,C.Ly));
    btonC.setPosition(C.posx,C.posy);

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(btonA);
        window.draw(btonB);
        window.draw(btonC);
        window.display();
    }

    return 0;
}
