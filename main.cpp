#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;


int main()
{
    RenderWindow window(VideoMode(500, 700), "COOL GAME",Style::Default);
    window.setFramerateLimit(60);

    Font font;
    if (!font.loadFromFile("Fonts/Metropolian-Display.ttf"))
        throw("CLOUD NOT LOAD FONT!");

    Text text1;
    Text text2;
    Text text3;
    Text text4;
    Text text5;

    text1.setFont(font);
    text1.setCharacterSize(20);
    text1.setColor(Color::Red);
    text1.setStyle(Text::Bold);
    text1.setString("TIME");
    text1.setOrigin(text1.getGlobalBounds().width /2,text1.getGlobalBounds().height /2);
    textTime.setPosition(70,660);

    text2.setString("RandomWord");
    text2.setOrigin(textC1.getGlobalBounds().width /2,textC1.getGlobalBounds().height /2);
    text2.setPosition(Choice1.posx,Choice1.posy-5);
    text2.setString("RandomWord");
    text2.setOrigin(textC2.getGlobalBounds().width /2,textC2.getGlobalBounds().height /2);
    text2.setPosition(Choice2.posx,Choice2.posy-5);

    text3.setString("RandomWord");
    text3.setOrigin(textC1.getGlobalBounds().width /2,textC1.getGlobalBounds().height /2);
    text3.setPosition(Choice1.posx,Choice1.posy-5);
    text3.setString(RandomWord");
    text3.setOrigin(textC2.getGlobalBounds().width /2,textC2.getGlobalBounds().height /2);
    text3.setPosition(Choice2.posx,Choice2.posy-5);

    text4.setFont(font);
    text4.setCharacterSize(20);
    text4.setColor(Color::Red);
    text4.setStyle(Text::Bold);
    text4.setString("                                          ");
    text4.setOrigin(text3.getGlobalBounds().width /2,text3.getGlobalBounds().height /2);
    text4.setPosition(window.getSize().x/2,window.getSize().y/2+20);

    text5.setFont(font);
    text5.setCharacterSize(20);
    text5.setColor(Color::Red);
    text5.setStyle(Text::Bold);
    text5.setString("BACK");
    text5.setOrigin(text4.getGlobalBounds().width /2,text4.getGlobalBounds().height /2);
    text5.setPosition(80, 50);



    while(window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.display();

    }
    return 0;
}
