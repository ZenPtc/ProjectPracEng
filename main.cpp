#include"func.h"
using namespace sf;

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

            if((float)mousePos.x<A.posx+(A.Lx/2) && (float)mousePos.x>A.posx-(A.Lx/2)){
                if((float)mousePos.y<A.posy+(A.Ly/2) && (float)mousePos.y>A.posy-(A.Ly/2)){
                    btonA.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 1;
                    }
                }
            }
            if((float)mousePos.x<B.posx+(B.Lx/2) && (float)mousePos.x>B.posx-(B.Lx/2)){
                if((float)mousePos.y<B.posy+(B.Ly/2) && (float)mousePos.y>B.posy-(B.Ly/2)){
                    btonB.setFillColor(Color::Green);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 2;
                    }
                }
            }
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

            window.clear();
            window.display();
        }else if(screen==2){ //card screen

            window.clear();
            window.display();
        }else if(screen==3){ //play screen

            window.clear();
            window.display();
        }
    }

    return 0;
}
