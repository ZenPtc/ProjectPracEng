#include"func.h"

int main()
{
    //set render window
    RenderWindow window(VideoMode(500,700), "EngJoy",Style::Close);
    int screen = 0; //start at main screen

    //variable for collect word and describe
    vector<string> word;
    vector<string> des;
    int count=0; //count word
    int ranNUM1=0,ranNUM2=1,ranChoice=0,ranTar=0,ranPaw=2; //set stater for random
    bool CHW = false; //check have word?
    int highscore=0,score=0;
    int xTar=window.getSize().x/2, yTar=150;
    int xPaw=window.getSize().x/2, yPaw=250;
    int Ptime=350;

    //set background
    Texture bg1Texture,bg2Texture,bg3Texture,bg4Texture,bg5Texture;
    if (!bg1Texture.loadFromFile("topic.png"))
        cout << "cannot load background" << endl;
    if (!bg2Texture.loadFromFile("3choices.png"))
        cout << "cannot load background" << endl;
    if (!bg3Texture.loadFromFile("vocab.png"))
        cout << "cannot load background" << endl;
    if (!bg4Texture.loadFromFile("game.png"))
        cout << "cannot load background" << endl;
    if (!bg5Texture.loadFromFile("end.png"))
        cout << "cannot load background" << endl;
    Sprite background1(bg1Texture),
            background2(bg2Texture),
            background3(bg3Texture),
            background4(bg4Texture),
            background5(bg5Texture);
    //set music
    Music gameMusic,ingameMusic,loseMusic;
    if(!gameMusic.openFromFile("main song.ogg"))
        std::cout << " " << std::endl;
    if(!ingameMusic.openFromFile("in game song.ogg"))
        std::cout << " " << std::endl;
    if(!loseMusic.openFromFile("game over song.ogg"))
        std::cout << " " << std::endl;
    gameMusic.play();
    gameMusic.setVolume(10);
    ingameMusic.setVolume(7);
    loseMusic.setVolume(10);
    //set color
    sf::Color Brown(138,56,15);
    sf::Color Gray(118,109,105);
    sf::Color lightBlue(112,216,245);
    sf::Color Pink(255,150,86);

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
        RectangleShape btonA,btonB,btonC,btonBack,btonT,btonF,btonChoice1,btonChoice2,
                        btonIELTS,btonTOEIC,btonTOELF,btonNext,btonTime,
                        nameRect,catRect,moneyRect,tarRect,pawRect;
        Bton Name(nameRect,302.5,163.5,window.getSize().x/2,165);
        Bton Money(moneyRect,77,76,367.5,50);
        Bton Cat(catRect,225,245,window.getSize().x/2,400);
        Bton A(btonA,350,70,window.getSize().x/2,Name.posy+170);
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
        btonTime.setSize(Vector2f(Ptime,20));
        btonTime.setFillColor(Brown);
        btonTime.setPosition(115,657);

        ranTar = (rand()%10+rand()%5)%3;
        if(ranTar==0){
            xTar = window.getSize().x/2;
            yTar = 150;
        }else if(ranTar==1){
            xTar = window.getSize().x/2-130;
            yTar = 170;
        }else if(ranTar==2){
            xTar = window.getSize().x/2+130;
            yTar = 170;
        }
        //cat
        Texture catTexture;
        ranPaw = (rand()%8+rand()%3)%3;
        if(ranPaw==0){
            xPaw = window.getSize().x/2;
            yPaw = 250;
            catTexture.loadFromFile("catMid.png");
        }else if(ranPaw==1){
            xPaw = window.getSize().x/2-130;
            yPaw = 270;
            catTexture.loadFromFile("catLeft.png");
        }else if(ranPaw==2){
            xPaw = window.getSize().x/2+130;
            yPaw = 270;
            catTexture.loadFromFile("catRight.png");
        }
        Bton Target(tarRect,99,68,xTar,yTar);
        Bton Paw(pawRect,49,46,xPaw,yPaw);
        ///////////////set texture///////////////
        Texture nameTexture,moneyTexture,tarTexture,pawTexture;
        nameTexture.loadFromFile("program name.png");
        moneyTexture.loadFromFile("score.png");
        tarTexture.loadFromFile("fish.png");
        pawTexture.loadFromFile("paw.png");
        Name.rectan.setTexture(&nameTexture);
        Cat.rectan.setTexture(&catTexture);
        Money.rectan.setTexture(&moneyTexture);
        Target.rectan.setTexture(&tarTexture);
        Paw.rectan.setTexture(&pawTexture);
        /////////////////////////////////////set text////////////////////////////////////////////////
        Font font,font2,font3;
        if (!font.loadFromFile("C://windows/fonts/coopbl.ttf"))
            throw("CLOUD NOT LOAD FONT!");
        if (!font2.loadFromFile("C://windows/fonts/humnst777 blkcn bt black.ttf"))
            throw("CLOUD NOT LOAD FONT!");
        if (!font3.loadFromFile("C://windows/fonts/framd.ttf"))
            throw("CLOUD NOT LOAD FONT!");
        Text textA,textB,textC,textBack,textT,textF,textIELTS,textTOEIC,textTOELF,
                textL,textNext,textDes,textC1,textC2,textLOSE,textHS,textYS,textCheer,
                textSscore,textTime;
        //cheer up!
        textCheer.setFont(font3);
        textCheer.setCharacterSize(25);
        textCheer.setColor(Color::Black);
        textCheer.setString("May the force be with you.");
        textCheer.setOrigin(textCheer.getGlobalBounds().width /2,textCheer.getGlobalBounds().height /2);
        textCheer.setPosition(window.getSize().x/2,window.getSize().y/3+250);
        //your score
        textYS.setFont(font3);
        textYS.setCharacterSize(25);
        textYS.setStyle(Text::Bold);
        textYS.setColor(Color::Black);
        //high score
        textHS.setFont(font3);
        textHS.setCharacterSize(25);
        textHS.setStyle(Text::Bold);
        textHS.setColor(Color::Black);
        //game over
        textLOSE.setFont(font);
        textLOSE.setCharacterSize(50);
        textLOSE.setColor(Color::Black);
        textLOSE.setString("GAME OVER");
        textLOSE.setOrigin(textLOSE.getGlobalBounds().width /2,textLOSE.getGlobalBounds().height /2);
        textLOSE.setPosition(window.getSize().x/2,window.getSize().y/4+30);
        //Choice1
        textC1.setFont(font);
        textC1.setCharacterSize(20);
        textC1.setColor(Color::Black);
        //Choice2
        textC2.setFont(font);
        textC2.setCharacterSize(20);
        textC2.setColor(Color::Black);
        //back
        textBack.setFont(font);
        textBack.setCharacterSize(20);
        textBack.setColor(Color::Black);
        textBack.setString("BACK");
        textBack.setOrigin(textBack.getGlobalBounds().width /2,textBack.getGlobalBounds().height /2);
        textBack.setPosition(80,Back.posy-5);
        //word
        textA.setFont(font);
        textA.setCharacterSize(20);
        textA.setColor(Color::Black);
        textA.setString("WORD");
        textA.setOrigin(textA.getGlobalBounds().width /2,textA.getGlobalBounds().height /2);
        textA.setPosition(window.getSize().x /2,A.posy-5);
        //learn
        textB.setFont(font);
        textB.setCharacterSize(20);
        textB.setColor(Color::Black);
        textB.setString("LEARN");
        textB.setOrigin(textB.getGlobalBounds().width /2,textB.getGlobalBounds().height /2);
        textB.setPosition(window.getSize().x /2,B.posy-5);
        //play
        textC.setFont(font);
        textC.setCharacterSize(20);
        textC.setColor(Color::Black);
        textC.setString("PLAY");
        textC.setOrigin(textC.getGlobalBounds().width /2,textC.getGlobalBounds().height /2);
        textC.setPosition(window.getSize().x /2,C.posy-5);
        //known
        textT.setFont(font);
        textT.setCharacterSize(35);
        textT.setColor(Color::Black);
        textT.setString("O");
        textT.setOrigin(textT.getGlobalBounds().width /2,textT.getGlobalBounds().height /2);
        textT.setPosition(window.getSize().x /4,T.posy-10);
        //not yet
        textF.setFont(font);
        textF.setCharacterSize(35);
        textF.setColor(Color::Black);
        textF.setString("X");
        textF.setOrigin(textF.getGlobalBounds().width /2,textF.getGlobalBounds().height /2);
        textF.setPosition(window.getSize().x/2+window.getSize().x/4,F.posy-10);
        //IELTS
        textIELTS.setFont(font);
        textIELTS.setCharacterSize(20);
        textIELTS.setColor(Color::Black);
        textIELTS.setString("IELTS");
        textIELTS.setOrigin(textIELTS.getGlobalBounds().width /2,textIELTS.getGlobalBounds().height /2);
        textIELTS.setPosition(window.getSize().x/2,IELTS.posy-5);
        //TOEIC
        textTOEIC.setFont(font);
        textTOEIC.setCharacterSize(20);
        textTOEIC.setColor(Color::Black);
        textTOEIC.setString("TOEIC");
        textTOEIC.setOrigin(textTOEIC.getGlobalBounds().width /2,textTOEIC.getGlobalBounds().height /2);
        textTOEIC.setPosition(window.getSize().x/2,TOEIC.posy-5);
        //TOELF
        textTOELF.setFont(font);
        textTOELF.setCharacterSize(20);
        textTOELF.setColor(Color::Black);
        textTOELF.setString("TOELF");
        textTOELF.setOrigin(textTOELF.getGlobalBounds().width /2,textTOELF.getGlobalBounds().height /2);
        textTOELF.setPosition(window.getSize().x/2,TOELF.posy-5);
        //learn word
        textL.setFont(font);
        textL.setCharacterSize(50);
        textL.setColor(Color::Black);
        //Next
        textNext.setFont(font);
        textNext.setCharacterSize(20);
        textNext.setColor(Color::Black);
        textNext.setString("Next");
        textNext.setOrigin(textNext.getGlobalBounds().width /2,textNext.getGlobalBounds().height /2);
        textNext.setPosition(420,Next.posy-5);
        //text describe
        textDes.setFont(font2);
        textDes.setCharacterSize(20);
        textDes.setColor(Color::Black);
        //show score
        textSscore.setFont(font2);
        textSscore.setCharacterSize(60);
        textSscore.setColor(Color::Black);
        textSscore.setOrigin(textSscore.getGlobalBounds().width /2,textSscore.getGlobalBounds().height /2);
        textSscore.setPosition(422.5,10);
        //text time
        textTime.setFont(font);
        textTime.setCharacterSize(20);
        textTime.setColor(Color::Black);
        textTime.setString("TIME :");
        textTime.setOrigin(textTime.getGlobalBounds().width/2,textTime.getGlobalBounds().height/2);
        textTime.setPosition(70,660);
        //////////////////////////////////////////////////////////////////////////////////////////////
        if(screen==0){ //main screen
            //Press word
            if((float)mousePos.x<A.posx+(A.Lx/2) && (float)mousePos.x>A.posx-(A.Lx/2)){
                if((float)mousePos.y<A.posy+(A.Ly/2) && (float)mousePos.y>A.posy-(A.Ly/2)){
                    A.rectan.setFillColor(lightBlue);
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
                        B.rectan.setFillColor(lightBlue);
                        if(Mouse::isButtonPressed(Mouse::Left)){
                            screen = 2;
                            sleep_for(150ms);
                        }
                    }
                }
                //Press play
                if((float)mousePos.x<C.posx+(C.Lx/2) && (float)mousePos.x>C.posx-(C.Lx/2)){
                    if((float)mousePos.y<C.posy+(C.Ly/2) && (float)mousePos.y>C.posy-(C.Ly/2)){
                        C.rectan.setFillColor(lightBlue);
                        if(Mouse::isButtonPressed(Mouse::Left)){
                            screen = 3;
                            sleep_for(150ms);
                            ingameMusic.play();
                        }
                    }
                }
            }else{
                B.rectan.setFillColor(Gray);
                C.rectan.setFillColor(Gray);
            }

            window.clear();
            window.draw(background1);
            window.draw(Name.rectan);
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
                    Back.rectan.setFillColor(lightBlue);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }
            //IELTS
            if((float)mousePos.x<IELTS.posx+(IELTS.Lx/2) && (float)mousePos.x>IELTS.posx-(IELTS.Lx/2)){
                if((float)mousePos.y<IELTS.posy+(IELTS.Ly/2) && (float)mousePos.y>IELTS.posy-(IELTS.Ly/2)){
                    IELTS.rectan.setFillColor(Pink);
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
                    TOEIC.rectan.setFillColor(Pink);
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
                    TOELF.rectan.setFillColor(Pink);
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
            window.draw(background2);
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
            textL.setString(word[ranNUM1]);
            textL.setOrigin(textL.getGlobalBounds().width /2,textL.getGlobalBounds().height /2);
            textL.setPosition(window.getSize().x/2,window.getSize().y/2-55);

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(lightBlue);
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
                        ranNUM1 = rand()%(count);
                        textL.setString(word[ranNUM1]);
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
            window.draw(background3);
            window.draw(Back.rectan);
            window.draw(T.rectan);
            window.draw(F.rectan);
            window.draw(textBack);
            window.draw(textT);
            window.draw(textF);
            window.draw(textL);
            window.display();
        }else if(screen==3){ //play screen
            gameMusic.stop();
            loseMusic.stop();
            Ptime-=2; //time-2
            if(Ptime<=0){
                screen=5;
                sleep_for(150ms);
                loseMusic.play();
            }

            while(ranNUM2==ranNUM1) ranNUM2 = rand()%(count);

            if(ranChoice==0){
                if(word[ranNUM1].size()>12) textC1.setCharacterSize(16);
                if(word[ranNUM2].size()>12) textC2.setCharacterSize(16);
                textC1.setString(word[ranNUM1]);
                textC1.setOrigin(textC1.getGlobalBounds().width /2,textC1.getGlobalBounds().height /2);
                textC1.setPosition(Choice1.posx,Choice1.posy-5);
                textC2.setString(word[ranNUM2]);
                textC2.setOrigin(textC2.getGlobalBounds().width /2,textC2.getGlobalBounds().height /2);
                textC2.setPosition(Choice2.posx,Choice2.posy-5);
            }else if(ranChoice==1){
                if(word[ranNUM1].size()>12) textC2.setCharacterSize(16);
                if(word[ranNUM2].size()>12) textC1.setCharacterSize(16);
                textC1.setString(word[ranNUM2]);
                textC1.setOrigin(textC1.getGlobalBounds().width /2,textC1.getGlobalBounds().height /2);
                textC1.setPosition(Choice1.posx,Choice1.posy-5);
                textC2.setString(word[ranNUM1]);
                textC2.setOrigin(textC2.getGlobalBounds().width /2,textC2.getGlobalBounds().height /2);
                textC2.setPosition(Choice2.posx,Choice2.posy-5);
            }

            textDes.setString(des[ranNUM1]);
            if(des[ranNUM1].size()>40) textDes.setCharacterSize(17);
            textDes.setOrigin(textDes.getGlobalBounds().width /2,textDes.getGlobalBounds().height /2);
            textDes.setPosition(window.getSize().x/2,522+10);

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(lightBlue);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        score=0;
                        screen = 0;
                        Ptime=350;
                        sleep_for(150ms);
                        ingameMusic.stop();
                    }
                }
            }
            //Press Choice1
            if((float)mousePos.x<Choice1.posx+(Choice1.Lx/2) && (float)mousePos.x>Choice1.posx-(Choice1.Lx/2)){
                if((float)mousePos.y<Choice1.posy+(Choice1.Ly/2) && (float)mousePos.y>Choice1.posy-(Choice1.Ly/2)){
                    Choice1.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        if(ranChoice==0){
                            if(ranTar==ranPaw){
                                score++;
                                Ptime=350;
                                ranChoice = rand()%2;
                                ranNUM1 = rand()%(count);
                                ranNUM2 = rand()%(count);
                                while(ranNUM2==ranNUM1) ranNUM2 = rand()%(count);
                            }else Ptime-=30;
                        }else{
                            screen=5;
                            sleep_for(150ms);
                            loseMusic.play();
                        }
                        sleep_for(150ms);
                    }
                }
            }
            //Press Choice2
            if((float)mousePos.x<Choice2.posx+(Choice2.Lx/2) && (float)mousePos.x>Choice2.posx-(Choice2.Lx/2)){
                if((float)mousePos.y<Choice2.posy+(Choice2.Ly/2) && (float)mousePos.y>Choice2.posy-(Choice2.Ly/2)){
                    Choice2.rectan.setFillColor(Color::Yellow);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        if(ranChoice==1){
                            if(ranTar==ranPaw){
                                score++;
                                Ptime=350;
                                ranChoice = rand()%2;
                                ranNUM1 = rand()%(count);
                                ranNUM2 = rand()%(count);
                                while(ranNUM2==ranNUM1) ranNUM2 = rand()%(count);
                            }else Ptime-=30;
                        }else{
                            screen=5;
                            sleep_for(150ms);
                            loseMusic.play();
                        }
                        sleep_for(150ms);
                    }
                }
            }
            char Sscore[10];
            sprintf(Sscore,"%d",score);
            textSscore.setString(Sscore);

            window.clear();
            window.draw(background4);
            window.draw(Back.rectan);
            window.draw(Cat.rectan);
            window.draw(Money.rectan);
            window.draw(Target.rectan);
            window.draw(Paw.rectan);
            window.draw(Choice1.rectan);
            window.draw(Choice2.rectan);
            window.draw(btonTime);
            window.draw(textSscore);
            window.draw(textDes);
            window.draw(textBack);
            window.draw(textC1);
            window.draw(textC2);
            window.draw(textTime);
            window.display();
        }else if(screen==4){  //don't know word screen
            //word
            textL.setString(word[ranNUM1]);
            textL.setOrigin(textL.getGlobalBounds().width /2,textL.getGlobalBounds().height /2);
            textL.setPosition(window.getSize().x/2,window.getSize().y/2-70);
            //text describe
            textDes.setString(des[ranNUM1]);
            if(des[ranNUM1].size()>40) textDes.setCharacterSize(17);
            textDes.setOrigin(textDes.getGlobalBounds().width /2,textDes.getGlobalBounds().height /2);
            textDes.setPosition(window.getSize().x/2,window.getSize().y/2+20);

            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(lightBlue);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                    }
                }
            }
            //Press next
            if((float)mousePos.x<Next.posx+(Next.Lx/2) && (float)mousePos.x>Next.posx-(Next.Lx/2)){
                if((float)mousePos.y<Next.posy+(Next.Ly/2) && (float)mousePos.y>Next.posy-(Next.Ly/2)){
                    Next.rectan.setFillColor(lightBlue);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 2;
                        sleep_for(150ms);
                    }
                }
            }

            window.clear();
            window.draw(background3);
            window.draw(Back.rectan);
            window.draw(textBack);
            window.draw(Next.rectan);
            window.draw(textNext);
            window.draw(textL);
            window.draw(textDes);
            window.display();
        }else if(screen==5){  //game over screen.
            gameMusic.stop();
            ingameMusic.stop();
            Ptime=350;
            //Press back
            if((float)mousePos.x<Back.posx+(Back.Lx/2) && (float)mousePos.x>Back.posx-(Back.Lx/2)){
                if((float)mousePos.y<Back.posy+(Back.Ly/2) && (float)mousePos.y>Back.posy-(Back.Ly/2)){
                    Back.rectan.setFillColor(lightBlue);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 0;
                        sleep_for(150ms);
                        loseMusic.stop();
                        score=0;
                    }
                }
            }
            //Press next
            if((float)mousePos.x<Next.posx+(Next.Lx/2) && (float)mousePos.x>Next.posx-(Next.Lx/2)){
                if((float)mousePos.y<Next.posy+(Next.Ly/2) && (float)mousePos.y>Next.posy-(Next.Ly/2)){
                    Next.rectan.setFillColor(lightBlue);
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        screen = 3;
                        sleep_for(150ms);
                        loseMusic.stop();
                        score=0;
                        ingameMusic.play();
                    }
                }
            }

            string Yscore = "YOUR SCORE : ";
            string Hscore = "HIGH SCORE : ";
            if(score>highscore) highscore = score;
            char Sscore[10],SHscore[10];
            sprintf(Sscore,"%d",score);
            sprintf(SHscore,"%d",highscore);
            Yscore += Sscore;
            Hscore += SHscore;
            //high score
            textHS.setString(Hscore);
            textHS.setOrigin(textHS.getGlobalBounds().width /2,textHS.getGlobalBounds().height /2);
            textHS.setPosition(window.getSize().x/2,window.getSize().y/2-42);
            //your score
            textYS.setString(Yscore);
            textYS.setOrigin(textYS.getGlobalBounds().width /2,textYS.getGlobalBounds().height /2);
            textYS.setPosition(window.getSize().x/2,window.getSize().y/2+42);

            window.clear();
            window.draw(background5);
            window.draw(Back.rectan);
            window.draw(textBack);
            window.draw(Next.rectan);
            window.draw(textNext);
            window.draw(textLOSE);
            window.draw(textHS);
            window.draw(textYS);
            window.draw(textCheer);
            window.display();
        }
        //play background sound
        if(gameMusic.getStatus()==Sound::Status::Stopped&&
           ingameMusic.getStatus()==Sound::Status::Stopped&&
           loseMusic.getStatus()==Sound::Status::Stopped){
            gameMusic.play();
        }
    }

    return 0;
}
