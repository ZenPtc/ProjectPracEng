#include"func.h"
using namespace sf;

/*int main()
{
    //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);

    //create button and set position
    Bton A(350,70,w_width/2,275);
    Bton B(350,70,w_width/2,400);
    Bton C(350,70,w_width/2,525);
    RectangleShape btonA(Vector2f(A.Lx,A.Ly));
    btonA.setPosition(A.posx,A.posy);
    btonA.setOrigin(A.Lx/2,A.Ly/2);
    RectangleShape btonB(Vector2f(B.Lx,B.Ly));
    btonB.setPosition(B.posx,B.posy);
    btonB.setOrigin(B.Lx/2,B.Ly/2);
    RectangleShape btonC(Vector2f(C.Lx,C.Ly));
    btonC.setPosition(C.posx,C.posy);
    btonC.setOrigin(C.Lx/2,C.Ly/2);


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
*/
