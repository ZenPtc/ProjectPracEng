#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(500, 700), "COOL GAME",Style::Close);
    RectangleShape name(Vector2f(304.0f,163.5f));
    name.setOrigin(name.getSize().x/2,name.getSize().y/2);
    name.setPosition(window.getSize().x/2,window.getSize().y/2);
    Texture nameTexture;
    nameTexture.loadFromFile("program name.png");
    name.setTexture(&nameTexture);

    while(window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(name);
        window.display();

    }
    return 0;
}
