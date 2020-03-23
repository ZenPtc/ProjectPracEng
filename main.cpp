#include"func.h"

int main()
{
    //set render window
    float w_height=700, w_width=500;
    RenderWindow window(VideoMode(w_width, w_height), "English Easy",Style::Close);
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
        RectangleShape btonA,btonB,btonC,btonBack,btonT,btonF,btonchoice1,btonchoice2;
        Bton A(btonA,350,70,w_width/2,310);
        Bton B(btonB,350,70,w_width/2,A.posy+125);
        Bton C(btonC,350,70,w_width/2,B.posy+125);
        Bton Back(btonBack,100,40,80,50);
        Bton T(btonT,70,50,w_width/4,600);
        Bton F(btonF,70,50,w_width/2+w_width/4,600);
        Bton choice1(btonchoice1,170,50,w_width/3,600);
        Bton choice2(btonchoice2,170,50,w_width/3+170,600);

        if(screen==0){ //main screen

            //Press word
            if((float)mousePos.x<A.posx+(A.Lx/2) && (float)mousePos.x>A.posx-(A.Lx/2)){
                if((float)mousePos.y<A.posy+(A.Ly/2) && (float)mousePos.y>A.posy-(A.Ly/2)){
                    A.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }
            //Press learn
            if((float)mousePos.x<B.posx+(B.Lx/2) && (float)mousePos.x>B.posx-(B.Lx/2)){
                if((float)mousePos.y<B.posy+(B.Ly/2) && (float)mousePos.y>B.posy-(B.Ly/2)){
                    B.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 2;
                        sleep_for(150ms);
                    }
                }
            }
            //Press play
            if((float)mousePos.x<C.posx+(C.Lx/2) && (float)mousePos.x>C.posx-(C.Lx/2)){
                if((float)mousePos.y<C.posy+(C.Ly/2) && (float)mousePos.y>C.posy-(C.Ly/2)){
                    C.rectan.setFillColor(Color::Green);
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
            window.display();
        }else if(screen==1){ //word screen

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.display();
        }else if(screen==2){ //learn screen

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(Color::Green);
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
                    F.rectan.setFillColor(Color::Green);
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
            window.display();
        }else if(screen==3){ //play screen

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }
            //Press choice1
            if((float)mousePos.x<choice1.posx+(choice1.Lx/2) && (float)mousePos.x>choice1.posx-(choice1.Lx/2)){
                if((float)mousePos.y<choice1.posy+(choice1.Ly/2) && (float)mousePos.y>choice1.posy-(choice1.Ly/2)){
                    choice1.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }
            //Press choice2
            if((float)mousePos.x<choice2.posx+(choice2.Lx/2) && (float)mousePos.x>choice2.posx-(choice2.Lx/2)){
                if((float)mousePos.y<choice2.posy+(choice2.Ly/2) && (float)mousePos.y>choice2.posy-(choice2.Ly/2)){
                    choice2.rectan.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.draw(choice1.rectan);
            window.draw(choice2.rectan);
            window.display();
        }
    }

    return 0;
}
