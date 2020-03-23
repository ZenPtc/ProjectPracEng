#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(800, 600), "COOL GAME",Style::Default);
    window.setFramerateLimit(60);

    Font font;
    if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
        throw("CLOUD NOT LOAD FONT!");

    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setColor(Color::Blue);
    text.setStyle(Text::Bold);
    text.setString("MEAYCHA KON NAH HEE");
    text.setPosition(250.f, window.getSize().y /2);
    text.move(0.1f,0.f);


    while(window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(text);
        window.display();

    }
    return 0;
}
