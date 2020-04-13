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

    text1.setFont(font);
    text1.setCharacterSize(20);
    text1.setColor(Color::Black);
    text1.setString("Next");
    text1.setOrigin(textNext.getGlobalBounds().width /2,textNext.getGlobalBounds().height /2);
    text1.setPosition(420,Next.posy-5);

    text2.setFont(font);
    text2.setCharacterSize(20);
    text2.setColor(Color::Red);
    text2.setStyle(Text::Bold);
    text2.setString("Random");
    text2.setOrigin(text2.getGlobalBounds().width /2,text2.getGlobalBounds().height /2);


    text3.setFont(font);
    text3.setCharacterSize(20);
    text3.setColor(Color::Red);
    text3.setStyle(Text::Bold);
    text3.setString("                     ");
    text3.setOrigin(text3.getGlobalBounds().width /2,text3.getGlobalBounds().height /2);
    textDes.setPosition(window.getSize().x/2,window.getSize().y/2+20);

    text4.setFont(font);
    text4.setCharacterSize(20);
    text4.setColor(Color::Red);
    text4.setStyle(Text::Bold);
    text4.setString("BACK");
    text4.setOrigin(text4.getGlobalBounds().width /2,text4.getGlobalBounds().height /2);
    text4.setPosition(80, 50);



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
        window.display();

    }
    return 0;
}
