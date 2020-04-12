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
   
    
    
    //Bton::Bton(RectangleShape n,float lx,float ly,float px,float py){
    //    rectan=n; Lx=lx; Ly=ly; posx=px; posy=py;
     //   rectan.setSize(Vector2f(Lx,Ly));
    //    rectan.setOrigin(Lx/2,Ly/2);
    //    rectan.setPosition(posx,posy);
 //   }


    
    RectangleShape btonA,btonB,btonC,btonBack,btonT,btonF,btonChoice1,btonChoice2,
                    btonIELTS,btonTOEIC,btonTOELF,btonNext,btonTime,
                    nameRect,catRect,moneyRect,tarRect,pawRect;

  //Money(moneyRect,77,75,367.5,50);
    moneyRect.setSize(Vector2f(77,75));
   moneyRect.setOrigin(77/2,75/2);
    moneyRect.setPosition(367.5,50);
   //Cat(catRect,225,245,window.getSize().x/2,400);
    catRect.setSize(Vector2f(225,245));
    catRect.setOrigin(225/2,245/2);
     catRect.setPosition(window.getSize().x/2,400);
   //Target(tarRect,99,68,xTar,yTar);
    tarRect.setSize(Vector2f(99,68));
    tarRect.setOrigin(99/2,68/2);
    tarRect.setPosition(window.getSize().x/2,150);
   //Paw(pawRect,49,46,xPaw,yPaw);
    pawRect.setSize(Vector2f(49,46));
    pawRect.setOrigin(49/2,46/2);
    pawRect.setPosition(window.getSize().x/2,250);
    
    Texture nameTexture,moneyTexture,tarTexture,pawTexture;
    nameTexture.loadFromFile("program name.png");
    name.setTexture(&nameTexture);
    
    nameTexture.loadFromFile("program name.png");
    moneyTexture.loadFromFile("score.png");
    tarTexture.loadFromFile("fish.png");
    pawTexture.loadFromFile("paw.png");
    name.setTexture(&nameTexture);
    Cat.setTexture(&catTexture);
    Money.setTexture(&moneyTexture);
    Target.setTexture(&tarTexture);
    Paw.setTexture(&pawTexture);

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
