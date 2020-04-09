#include "SFML/Graphics.hpp"
using namespace sf;


int main(){
      //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);


    Texture texture;
    texture.loadFromFile("C://Users/USER/Desktop/ProjectPracEng/pic/AllTu3.png");

    IntRect rectSourceSprite(0, 0, 250, 140);
    Sprite sprite(texture,rectSourceSprite);
    Clock clock;

    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
        }
        if (clock.getElapsedTime().asSeconds() > 0.3f){
            if (rectSourceSprite.left == 250){
                rectSourceSprite.left = 0;
                rectSourceSprite.top += 140;
            if(rectSourceSprite.top == 700)
                rectSourceSprite.top == 0;
            }else{
                rectSourceSprite.left += 250;
            }
            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
    }

        window.clear();
        window.draw(sprite);
        window.display();

    }

    return 0;

}
