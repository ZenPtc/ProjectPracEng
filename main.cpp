#include"func.h"
using namespace sf;

int main()
{
    //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);

    //create button and set position
    Bton A(100,50,200,325);
    RectangleShape bton(Vector2f(A.Lx,A.Ly));
    bton.setPosition(A.posx,A.posy);

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bton);
        window.display();
    }

    return 0;
}
