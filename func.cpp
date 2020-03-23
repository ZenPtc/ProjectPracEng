#include"func.h"

Bton::Bton(RectangleShape n,float lx,float ly,float px,float py){
    rectan=n; Lx=lx; Ly=ly; posx=px; posy=py;
    rectan.setSize(Vector2f(Lx,Ly));
    rectan.setOrigin(Lx/2,Ly/2);
    rectan.setPosition(posx,posy);
}
