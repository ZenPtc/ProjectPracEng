#include"func.h"

int main()
{
    //set render window
    RenderWindow window(VideoMode(500,700), "English Easy",Style::Close);
    int screen = 0; //start at main screen

    while (window.isOpen())
    {
        ////////////////// do not delete //////////////////
        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
        }
        ///////////////////////////////////////////////////
        Vector2i mousePos = Mouse::getPosition(window);
        //create button
        RectangleShape btonA,btonB,btonC,btonBack,btonT,btonF,btonChoice1,btonChoice2;
        Bton A(btonA,350,70,window.getSize().x/2,310);
        Bton B(btonB,350,70,window.getSize().x/2,A.posy+125);
        Bton C(btonC,350,70,window.getSize().x/2,B.posy+125);
        Bton Back(btonBack,100,40,80,50);
        Bton T(btonT,70,50,window.getSize().x/4,600);
        Bton F(btonF,70,50,window.getSize().x/2+window.getSize().x/4,600);
        Bton Choice1(btonChoice1,170,50,window.getSize().x/3,600);
        Bton Choice2(btonChoice2,170,50,window.getSize().x/3+170,600);
        /////////////////////////////////////set text////////////////////////////////////////////////
        Font font;
        if (!font.loadFromFile("C://windows/fonts/coopbl.ttf"))
            throw("CLOUD NOT LOAD FONT!");
        Text textA,textB,textC,textBack,textT,textF;
        //back
        textBack.setFont(font);
        textBack.setCharacterSize(20);
        textBack.setColor(Color::Black);
        textBack.setString("BACK");
        textBack.setOrigin(textBack.getGlobalBounds().width /2,textBack.getGlobalBounds().height /2);
        textBack.setPosition(80, 45);
        //word
        textA.setFont(font);
        textA.setCharacterSize(20);
        textA.setColor(Color::Black);
        textA.setString("WORD");
        textA.setOrigin(textA.getGlobalBounds().width /2,textA.getGlobalBounds().height /2);
        textA.setPosition(window.getSize().x /2, 305);
        //learn
        textB.setFont(font);
        textB.setCharacterSize(20);
        textB.setColor(Color::Black);
        textB.setString("LEARN");
        textB.setOrigin(textB.getGlobalBounds().width /2,textB.getGlobalBounds().height /2);
        textB.setPosition(window.getSize().x /2, 430);
        //play
        textC.setFont(font);
        textC.setCharacterSize(20);
        textC.setColor(Color::Black);
        textC.setString("PLAY");
        textC.setOrigin(textC.getGlobalBounds().width /2,textC.getGlobalBounds().height /2);
        textC.setPosition(window.getSize().x /2, 555);
        //known
        textT.setFont(font);
        textT.setCharacterSize(35);
        textT.setColor(Color::Black);
        textT.setString("O");
        textT.setOrigin(textT.getGlobalBounds().width /2,textT.getGlobalBounds().height /2);
        textT.setPosition(window.getSize().x /4, 590);
        //not yet
        textF.setFont(font);
        textF.setCharacterSize(35);
        textF.setColor(Color::Black);
        textF.setString("X");
        textF.setOrigin(textF.getGlobalBounds().width /2,textF.getGlobalBounds().height /2);
        textF.setPosition(window.getSize().x/2+window.getSize().x/4,590);
        ////////////////////////////////////////////////////////////////////////////////////////////
        if(screen==0){ //main screen

            //Press word
            if((float)mousePos.x<A.posx+(A.Lx/2) && (float)mousePos.x>A.posx-(A.Lx/2)){
                if((float)mousePos.y<A.posy+(A.Ly/2) && (float)mousePos.y>A.posy-(A.Ly/2)){
                    A.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }
            //Press learn
            if((float)mousePos.x<B.posx+(B.Lx/2) && (float)mousePos.x>B.posx-(B.Lx/2)){
                if((float)mousePos.y<B.posy+(B.Ly/2) && (float)mousePos.y>B.posy-(B.Ly/2)){
                    B.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 2;
                        sleep_for(150ms);
                    }
                }
            }
            //Press play
            if((float)mousePos.x<C.posx+(C.Lx/2) && (float)mousePos.x>C.posx-(C.Lx/2)){
                if((float)mousePos.y<C.posy+(C.Ly/2) && (float)mousePos.y>C.posy-(C.Ly/2)){
                    C.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 3;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(A.rectan);
            window.draw(B.rectan);
            window.draw(C.rectan);
            window.draw(textA);
            window.draw(textB);
            window.draw(textC);
            window.display();
        }else if(screen==1){ //word screen

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.draw(textBack);
            window.display();
        }else if(screen==2){ //learn screen

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }
            //Press Known
            if((float)mousePos.x<T.posx+(T.Lx/2) && (float)mousePos.x>T.posx-(T.Lx/2)){
                if((float)mousePos.y<T.posy+(T.Ly/2) && (float)mousePos.y>T.posy-(T.Ly/2)){
                    T.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }
            //Press Don't know
            if((float)mousePos.x<F.posx+(F.Lx/2) && (float)mousePos.x>F.posx-(F.Lx/2)){
                if((float)mousePos.y<F.posy+(F.Ly/2) && (float)mousePos.y>F.posy-(F.Ly/2)){
                    F.rectan.setFillColor(Color::Red);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.draw(T.rectan);
            window.draw(F.rectan);
            window.draw(textBack);
            window.draw(textT);
            window.draw(textF);
            window.display();
        }else if(screen==3){ //play screen

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }
            //Press Choice1
            if((float)mousePos.x<Choice1.posx+(Choice1.Lx/2) && (float)mousePos.x>Choice1.posx-(Choice1.Lx/2)){
                if((float)mousePos.y<Choice1.posy+(Choice1.Ly/2) && (float)mousePos.y>Choice1.posy-(Choice1.Ly/2)){
                    Choice1.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }
            //Press Choice2
            if((float)mousePos.x<Choice2.posx+(Choice2.Lx/2) && (float)mousePos.x>Choice2.posx-(Choice2.Lx/2)){
                if((float)mousePos.y<Choice2.posy+(Choice2.Ly/2) && (float)mousePos.y>Choice2.posy-(Choice2.Ly/2)){
                    Choice2.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.draw(Choice1.rectan);
            window.draw(Choice2.rectan);
            window.draw(textBack);
            window.display();
        }
    }

    return 0;
}
