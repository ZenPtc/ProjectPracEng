#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(500, 700), "COOL GAME",Style::Default);
    window.setFramerateLimit(60);

    Music music;
    if(!music.openFromFile("Credits.ogg"))
    {
        std::cout << " " << std::endl;
    }

    music.play();

    while(window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();

        window.display();

    }
    return 0;
}
