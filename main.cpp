#include"func.h"

int main()
{
    //set render window
    float w_height=700, w_width=500;
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "English Easy",sf::Style::Close);
    int screen = 0; //start at main screen

    //create button and set position
    Bton A(100,50,250,350);
    sf::RectangleShape bton(sf::Vector2f(A.Lx,A.Ly));
    bton.setOrigin(A.Lx/2,A.Ly/2);
    bton.setPosition(A.posx,A.posy);

    while (window.isOpen())
    {
        ////////////////// do not delete //////////////////
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        ///////////////////////////////////////////////////
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if((float)mousePos.x<A.posx+(A.Lx/2) && (float)mousePos.x>A.posx-(A.Lx/2)){
                if((float)mousePos.y<A.posy+(A.Ly/2) && (float)mousePos.y>A.posy-(A.Ly/2)){
                    bton.setFillColor(sf::Color::Green);
                }
            }
        }else{
            bton.setFillColor(sf::Color::White);
        }

        window.clear();
        ///////////////////////draw////////////////////////
        window.draw(bton);
        ///////////////////////////////////////////////////
        window.display();
    }

    return 0;
}
