#include"func.h"

int main()
{
    //set render window
    RenderWindow window(VideoMode(500,700), "English Easy",Style::Close);
    int screen = 0; //start at main screen

    //variable for collect word and describe
    vector<string> word;
    vector<string> des;
    int count=0; //count word
    int ranNUM=0; //set stater for random
    bool CHW = false; //check have word?

    while (window.isOpen())
    {
        srand(time(0));
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
        RectangleShape btonIELTS,btonTOEIC,btonTOELF,btonNext;
        Bton A(btonA,350,70,window.getSize().x/2,310);
        Bton B(btonB,350,70,window.getSize().x/2,A.posy+125);
        Bton C(btonC,350,70,window.getSize().x/2,B.posy+125);
        Bton Back(btonBack,100,40,80,50);
        Bton T(btonT,70,50,window.getSize().x/4,600);
        Bton F(btonF,70,50,window.getSize().x/2+window.getSize().x/4,600);
        Bton Choice1(btonChoice1,170,50,window.getSize().x/3,600);
        Bton Choice2(btonChoice2,170,50,window.getSize().x/3+170,600);
        Bton IELTS(btonIELTS,350,70,window.getSize().x/2,250);
        Bton TOEIC(btonTOEIC,350,70,window.getSize().x/2,IELTS.posy+150);
        Bton TOELF(btonTOELF,350,70,window.getSize().x/2,TOEIC.posy+150);
        Bton Next(btonNext,100,40,420,650);
        /////////////////////////////////////set text////////////////////////////////////////////////
        Font font,font2;
        if (!font.loadFromFile("C://windows/fonts/coopbl.ttf"))
            throw("CLOUD NOT LOAD FONT!");
        if (!font2.loadFromFile("C://windows/fonts/humnst777 blkcn bt black.ttf"))
            throw("CLOUD NOT LOAD FONT!");
        Text textA,textB,textC,textBack,textT,textF,textIELTS,textTOEIC,textTOELF,textL,textNext,textDes;
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
        //IELTS
        textIELTS.setFont(font);
        textIELTS.setCharacterSize(20);
        textIELTS.setColor(Color::Black);
        textIELTS.setString("IELTS");
        textIELTS.setOrigin(textIELTS.getGlobalBounds().width /2,textIELTS.getGlobalBounds().height /2);
        textIELTS.setPosition(window.getSize().x/2,245);
        //TOEIC
        textTOEIC.setFont(font);
        textTOEIC.setCharacterSize(20);
        textTOEIC.setColor(Color::Black);
        textTOEIC.setString("TOEIC");
        textTOEIC.setOrigin(textTOEIC.getGlobalBounds().width /2,textTOEIC.getGlobalBounds().height /2);
        textTOEIC.setPosition(window.getSize().x/2,395);
        //TOELF
        textTOELF.setFont(font);
        textTOELF.setCharacterSize(20);
        textTOELF.setColor(Color::Black);
        textTOELF.setString("TOELF");
        textTOELF.setOrigin(textTOELF.getGlobalBounds().width /2,textTOELF.getGlobalBounds().height /2);
        textTOELF.setPosition(window.getSize().x/2,545);
        //learn word
        textL.setFont(font);
        textL.setCharacterSize(50);
        textL.setColor(Color::White);
        //Next
        textNext.setFont(font);
        textNext.setCharacterSize(20);
        textNext.setColor(Color::Black);
        textNext.setString("Next");
        textNext.setOrigin(textNext.getGlobalBounds().width /2,textNext.getGlobalBounds().height /2);
        textNext.setPosition(420,645);
        //text describe
        textDes.setFont(font2);
        textDes.setCharacterSize(20);
        textDes.setColor(Color::White);
        ////////////////////////////////////////////////////////////////////////////////////////////////
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
            if(CHW){
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
            }else{
                sf::Color Gray(100,100,100);
                B.rectan.setFillColor(Gray);
                C.rectan.setFillColor(Gray);
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
            //IELTS
            if((float)mousePos.x<IELTS.posx+(IELTS.Lx/2) && (float)mousePos.x>IELTS.posx-(IELTS.Lx/2)){
                if((float)mousePos.y<IELTS.posy+(IELTS.Ly/2) && (float)mousePos.y>IELTS.posy-(IELTS.Ly/2)){
                    IELTS.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        CHW = true;
                        system("cls"); //clear screen
                        word.clear();
                        des.clear();
                        ifstream source("IELTS");
                        string textline;
                        count=0;
                        while(getline(source,textline)){
                            cout << textline << endl;
                            word.push_back(textline.substr(0,textline.find_first_of("\t")-0));
                            des.push_back(textline.substr(textline.find_last_of("\t")+1,textline.find_first_of(".")-0));
                            count++;
                        }
                        source.close();
                        sleep_for(150ms);
                    }
                }
            }
            //TOEIC
            if((float)mousePos.x<TOEIC.posx+(TOEIC.Lx/2) && (float)mousePos.x>TOEIC.posx-(TOEIC.Lx/2)){
                if((float)mousePos.y<TOEIC.posy+(TOEIC.Ly/2) && (float)mousePos.y>TOEIC.posy-(TOEIC.Ly/2)){
                    TOEIC.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        CHW = true;
                        system("cls"); //clear screen
                        word.clear();
                        des.clear();
                        ifstream source("TOEIC");
                        string textline;
                        count=0;
                        while(getline(source,textline)){
                            cout << textline << endl;
                            word.push_back(textline.substr(0,textline.find_first_of("\t")-0));
                            des.push_back(textline.substr(textline.find_last_of("\t")+1,textline.find_first_of(".")-0));
                            count++;
                        }
                        source.close();
                        sleep_for(150ms);
                    }
                }
            }
            //TOELF
            if((float)mousePos.x<TOELF.posx+(TOELF.Lx/2) && (float)mousePos.x>TOELF.posx-(TOELF.Lx/2)){
                if((float)mousePos.y<TOELF.posy+(TOELF.Ly/2) && (float)mousePos.y>TOELF.posy-(TOELF.Ly/2)){
                    TOELF.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        CHW = true;
                        system("cls"); //clear screen
                        word.clear();
                        des.clear();
                        ifstream source("TOELF");
                        string textline;
                        count=0;
                        while(getline(source,textline)){
                            cout << textline << endl;
                            word.push_back(textline.substr(0,textline.find_first_of("\t")-0));
                            des.push_back(textline.substr(textline.find_last_of("\t")+1,textline.find_first_of(".")-0));
                            count++;
                        }
                        source.close();
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.draw(textBack);
            window.draw(IELTS.rectan);
            window.draw(TOEIC.rectan);
            window.draw(TOELF.rectan);
            window.draw(textIELTS);
            window.draw(textTOEIC);
            window.draw(textTOELF);
            window.display();
        }else if(screen==2){ //learn screen
            textL.setString(word[ranNUM]);
            textL.setOrigin(textL.getGlobalBounds().width /2,textL.getGlobalBounds().height /2);
            textL.setPosition(window.getSize().x/2,window.getSize().y/2-55);

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
                        ranNUM = rand()%(count);
                        textL.setString(word[ranNUM]);
                        textL.setOrigin(textL.getGlobalBounds().width /2,textL.getGlobalBounds().height /2);
                        textL.setPosition(window.getSize().x/2,window.getSize().y/2-55);
                        sleep_for(150ms);
                    }
                }
            }
            //Press Don't know
            if((float)mousePos.x<F.posx+(F.Lx/2) && (float)mousePos.x>F.posx-(F.Lx/2)){
                if((float)mousePos.y<F.posy+(F.Ly/2) && (float)mousePos.y>F.posy-(F.Ly/2)){
                    F.rectan.setFillColor(Color::Red);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 4;
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
            window.draw(textL);
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
                    Choice1.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        sleep_for(150ms);
                    }
                }
            }
            //Press Choice2
            if((float)mousePos.x<Choice2.posx+(Choice2.Lx/2) && (float)mousePos.x>Choice2.posx-(Choice2.Lx/2)){
                if((float)mousePos.y<Choice2.posy+(Choice2.Ly/2) && (float)mousePos.y>Choice2.posy-(Choice2.Ly/2)){
                    Choice2.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
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
        }else if(screen==4){  //don't know word screen
            //word
            textL.setString(word[ranNUM]);
            textL.setOrigin(textL.getGlobalBounds().width /2,textL.getGlobalBounds().height /2);
            textL.setPosition(window.getSize().x/2,window.getSize().y/2-70);
            //text describe
            textDes.setString(des[ranNUM]);
            if(des[ranNUM].size()>40) textDes.setCharacterSize(17);
            textDes.setOrigin(textDes.getGlobalBounds().width /2,textDes.getGlobalBounds().height /2);
            textDes.setPosition(window.getSize().x/2,window.getSize().y/2+20);

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
            //Press next
            if((float)mousePos.x<Next.posx+(Next.Lx/2) && (float)mousePos.x>Next.posx-(Next.Lx/2)){
                if((float)mousePos.y<Next.posy+(Next.Ly/2) && (float)mousePos.y>Next.posy-(Next.Ly/2)){
                    Next.rectan.setFillColor(Color::Cyan);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 2;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(Back.rectan);
            window.draw(textBack);
            window.draw(Next.rectan);
            window.draw(textNext);
            window.draw(textL);
            window.draw(textDes);
            window.display();
        }
    }

    return 0;
}
