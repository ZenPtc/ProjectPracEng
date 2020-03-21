#include"func.h"

int main()
{
    //set render window
    float w_height=700, w_width=500;
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "English Easy",sf::Style::Close);

    //create button and set position
    Bton A(100,50,200,325);
    sf::RectangleShape bton(sf::Vector2f(A.Lx,A.Ly));
    bton.setPosition(A.posx,A.posy);

    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(bton);
        window.display();
    }

    return 0;
}
