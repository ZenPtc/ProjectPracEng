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
        if(screen==0){ //main screen
            Bton A(350,70,w_width/2,310);
            Bton B(350,70,w_width/2,A.posy+125);
            Bton C(350,70,w_width/2,B.posy+125);
            RectangleShape btonA(Vector2f(A.Lx,A.Ly));
            RectangleShape btonB(Vector2f(B.Lx,B.Ly));
            RectangleShape btonC(Vector2f(C.Lx,C.Ly));
            btonA.setOrigin(A.Lx/2,A.Ly/2);
            btonB.setOrigin(B.Lx/2,B.Ly/2);
            btonC.setOrigin(C.Lx/2,C.Ly/2);
            btonA.setPosition(A.posx,A.posy);
            btonB.setPosition(B.posx,B.posy);
            btonC.setPosition(C.posx,C.posy);

            //Press word
            if((float)mousePos.x<A.posx+(A.Lx/2) && (float)mousePos.x>A.posx-(A.Lx/2)){
                if((float)mousePos.y<A.posy+(A.Ly/2) && (float)mousePos.y>A.posy-(A.Ly/2)){
                    btonA.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                    }
                }
            }
            //Press learn
            if((float)mousePos.x<B.posx+(B.Lx/2) && (float)mousePos.x>B.posx-(B.Lx/2)){
                if((float)mousePos.y<B.posy+(B.Ly/2) && (float)mousePos.y>B.posy-(B.Ly/2)){
                    btonB.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 2;
                    }
                }
            }
            //Press play
            if((float)mousePos.x<C.posx+(C.Lx/2) && (float)mousePos.x>C.posx-(C.Lx/2)){
                if((float)mousePos.y<C.posy+(C.Ly/2) && (float)mousePos.y>C.posy-(C.Ly/2)){
                    btonC.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 3;
                    }
                }
            }

            window.clear();
            window.draw(btonA);
            window.draw(btonB);
            window.draw(btonC);
            window.display();
        }else if(screen==1){ //word screen
            Bton Back(100,40,80,50);
            RectangleShape btonBack(Vector2f(Back.Lx,Back.Ly));
            btonBack.setOrigin(Back.Lx/2,Back.Ly/2);
            btonBack.setPosition(Back.posx,Back.posy);

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    btonBack.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                    }
                }
            }

            window.clear();
            window.draw(btonBack);
            window.display();
        }else if(screen==2){ //card screen
            Bton Back(100,40,80,50);
            Bton T(70,50,w_width/4,600);
            Bton F(70,50,w_width/2+w_width/4,600);
            RectangleShape btonBack(Vector2f(Back.Lx,Back.Ly));
            RectangleShape btonT(Vector2f(T.Lx,T.Ly));
            RectangleShape btonF(Vector2f(F.Lx,F.Ly));
            btonBack.setOrigin(Back.Lx/2,Back.Ly/2);
            btonT.setOrigin(T.Lx/2,T.Ly/2);
            btonF.setOrigin(F.Lx/2,F.Ly/2);
            btonBack.setPosition(Back.posx,Back.posy);
            btonT.setPosition(T.posx,T.posy);
            btonF.setPosition(F.posx,F.posy);

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    btonBack.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                    }
                }
            }
            //Press Known
            if((float)mousePos.x<T.posx+(T.Lx/2) && (float)mousePos.x>T.posx-(T.Lx/2)){
                if((float)mousePos.y<T.posy+(T.Ly/2) && (float)mousePos.y>T.posy-(T.Ly/2)){
                    btonT.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                    }
                }
            }
            //Press Don't know
            if((float)mousePos.x<F.posx+(F.Lx/2) && (float)mousePos.x>F.posx-(F.Lx/2)){
                if((float)mousePos.y<F.posy+(F.Ly/2) && (float)mousePos.y>F.posy-(F.Ly/2)){
                    btonF.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                    }
                }
            }

            window.clear();
            window.draw(btonBack);
            window.draw(btonT);
            window.draw(btonF);
            window.display();
        }else if(screen==3){ //play screen
            Bton Back(100,40,80,50);
            Bton choice1(170,50,w_width/3,600);
            Bton choice2(170,50,w_width/3+170,600);
            RectangleShape btonBack(Vector2f(Back.Lx,Back.Ly));
            RectangleShape btonchoice1(Vector2f(choice1.Lx,choice1.Ly));
            RectangleShape btonchoice2(Vector2f(choice2.Lx,choice2.Ly));
            btonBack.setOrigin(Back.Lx/2,Back.Ly/2);
            btonchoice1.setOrigin(choice1.Lx/2,choice1.Ly/2);
            btonchoice2.setOrigin(choice2.Lx/2,choice2.Ly/2);
            btonBack.setPosition(Back.posx,Back.posy);
            btonchoice1.setPosition(choice1.posx,choice1.posy);
            btonchoice2.setPosition(choice2.posx,choice2.posy);

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    btonBack.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                    }
                }
            }
            //Press choice1
            if((float)mousePos.x<choice1.posx+(choice1.Lx/2) && (float)mousePos.x>choice1.posx-(choice1.Lx/2)){
                if((float)mousePos.y<choice1.posy+(choice1.Ly/2) && (float)mousePos.y>choice1.posy-(choice1.Ly/2)){
                    btonchoice1.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                    }
                }
            }
            //Press choice2
            if((float)mousePos.x<choice2.posx+(choice2.Lx/2) && (float)mousePos.x>choice2.posx-(choice2.Lx/2)){
                if((float)mousePos.y<choice2.posy+(choice2.Ly/2) && (float)mousePos.y>choice2.posy-(choice2.Ly/2)){
                    btonchoice2.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                    }
                }
            }

            window.clear();
            window.draw(btonBack);
            window.draw(btonchoice1);
            window.draw(btonchoice2);
            window.display();
        }
    }

    return 0;
}
