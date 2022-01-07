#include <simplecpp>
#include <stdlib.h>
#include <iostream>
#include <cstdio>

using namespace std;

class button                     //Buttons to play/help/choose level etc.
{
public:
    Circle  r;
    Text  t;
    void hide()
    {
        r.hide();
        t.hide();
    }
    void show()
    {
        r.show();
        t.show();
    }

};


class maze_1 : public Rectangle              //creating different mazes starts here
{

    Rectangle r1,r2,r3,r4;
public:
    maze_1()
    {
        r1.reset(660,10,1320,20); r1.setFill(); r1.setColor(COLOR(255,255,255));
        r2.reset(660,720,1320,20); r2.setFill(); r2.setColor(COLOR(255,255,255));
        r3.reset(10,360,20,720); r3.setFill(); r3.setColor(COLOR(255,255,255));
        r4.reset(1310,360,20,720); r4.setFill(); r4.setColor(COLOR(255,255,255));
    }

    void imprint1()
    {
        r1.imprint();
        r2.imprint();
        r3.imprint();
        r4.imprint();
    }

    void hidet()
    {
        r1.hide();
        r2.hide();
        r3.hide();
        r4.hide();
    }
       void display(){
    r1.show();
    r2.show();
    r3.show();
    r4.show();


    }

};


class maze_2 :public Rectangle
{
Rectangle r1,r2,r3,r4;
public:
    maze_2()
    {
        r1.reset(660,10,1320,20); r1.setFill(); r1.setColor(COLOR(255,255,255));
        r2.reset(660,720,1320,20); r2.setFill(); r2.setColor(COLOR(255,255,255));
        r3.reset(10,360,20,720); r3.setFill(); r3.setColor(COLOR(255,255,255));
        r4.reset(1310,360,20,720); r4.setFill(); r4.setColor(COLOR(255,255,255));
    }
    void imprint1()
    {
    r1.imprint();
    r2.imprint();
    r3.imprint();
    r4.imprint();
    }

    void hidet()
    {
    r1.hide();
    r2.hide();
    r3.hide();
    r4.hide();
    }
    void display(){
    r1.show();
    r2.show();
    r3.show();
    r4.show();
    }

};


class maze_3 : public Rectangle
{
   Rectangle r1,r2,r3,r4;
   Circle maze31,maze32,maze33,maze34,maze35;
public:
    maze_3()
    {
        r1.reset(660,10,1320,20); r1.setFill(); r1.setColor(COLOR(255,255,255));
        r2.reset(660,720,1320,20); r2.setFill(); r2.setColor(COLOR(255,255,255));
        r3.reset(10,360,20,720); r3.setFill(); r3.setColor(COLOR(255,255,255));
        r4.reset(1310,360,20,720); r4.setFill(); r4.setColor(COLOR(255,255,255));
        maze31.reset(800,600,70); maze31.setColor(COLOR(20,40,60)); maze31.setFill(true);
        maze32.reset(800,120,70); maze32.setColor(COLOR(40,20,60)); maze32.setFill(true);
        maze34.reset(1240,380,70);maze34.setColor(COLOR(60,20,40)); maze34.setFill(true);
        maze35.reset(800,380,70); maze35.setColor(COLOR(20,60,40)); maze35.setFill(true);
    }
    void hidet()
    {
        r1.hide();
        r2.hide();
        r3.hide();
        r4.hide();
        maze31.hide();
        maze32.hide();
        maze34.hide();
        maze35.hide();
    }



};                                         //creating different mazes ends



void checkfoodeaten(Circle &food, int &fx, int &fy, Circle* &snake, int &lengthofsnake, int &head, char &previnstrn, int &score)
{
    if(snake[head].getX()==fx && snake[head].getY()==fy)
    {
        score+=5;              //score increases for eating food
        food.hide();

        //START of LEngth Increase

        Circle *temp=new Circle[++lengthofsnake];
        cout<<"111";
        if(temp==NULL)
        {
            closeCanvas();
            cout<<"Technical glitch. Please restart the game";
            return;
        }
        cout<<"112";
        for(int i=1; i<lengthofsnake; i++)
        {temp[i]=snake[(head+i-1)%lengthofsnake];}
        cout<<"113";

        temp[0]=snake[head];
        cout<<"114";

             if(previnstrn=='w')
        {temp[0].move(0,-40);}
        else if(previnstrn=='s')
        {temp[0].move(0,40);}
        else if(previnstrn=='a')
        {temp[0].move(-40,0);}
        else if(previnstrn=='d')
        {temp[0].move(40,0);}
                 cout<<"115";
        for(int i=0;i<lengthofsnake-1;i++){
           snake[i].hide();
        }
                  cout<<"116";

        temp[0].setColor(COLOR(0,30,0));
        temp[0].setFill(true);
        snake=temp;
                  cout<<"117";
        head = 0;
                  cout<<"118";

        for(int i=0; i<lengthofsnake+1; i++)        //initialisation of snake
    {
        snake[lengthofsnake-i].setColor(COLOR(0,30,0));
        snake[lengthofsnake-i].setFill(true);
    }

        return;
    }


}

//function to move
void move(char &previnstrn,char &nextinstrn,Circle snake[],int lengthofsnake,int head)
{
    int tail=(head+lengthofsnake-1)%lengthofsnake;

    if(nextinstrn=='a'&&previnstrn!='d')                   //A snake moving right cannot be given the command to move left!
    {
        snake[tail].moveTo(snake[head].getX()-40,snake[head].getY());
        previnstrn='a';
        return;
    }
    else if(nextinstrn=='d'&&previnstrn!='a')
    {
        snake[tail].moveTo(snake[head].getX()+40,snake[head].getY());
        previnstrn='d';
        return;
    }
    else if(nextinstrn=='w'&&previnstrn!='s')
    {
        snake[tail].moveTo(snake[head].getX(),snake[head].getY()-40);
        previnstrn='w';
        return;
    }
    else if(nextinstrn=='s'&&previnstrn!='w')
    {
        snake[tail].moveTo(snake[head].getX(),snake[head].getY()+40);
        previnstrn='s';
        return;
    }

    else                                 //if no command given or invalid command given
    {                                    //move according to prev instruction
        if(previnstrn=='a')
        {
            snake[tail].moveTo(snake[head].getX()-40,snake[head].getY());
            return;
        }
        else if(previnstrn=='d')
        {
            snake[tail].moveTo(snake[head].getX()+40,snake[head].getY());
            return;
        }
        else if(previnstrn=='w')
        {
            snake[tail].moveTo(snake[head].getX(),snake[head].getY()-40);
            return;
        }
        else if(previnstrn=='s')
        {
            snake[tail].moveTo(snake[head].getX(),snake[head].getY() + 40);
            return;
        }
        return;
    }
}


//function for checking death
//the boolean value returned decides whether to run the loop again or end the game.


bool checkmoves(int mazeno,int head,int &lengthofsnake, Circle snake[], int &score)
{                      //   checks death on hitting boundary
    if(snake[head].getX()<40 || snake[head].getX()>1280 || snake[head].getY()<40 || snake[head].getY()>640)
    {
        cout<<"\nGAME OVER\n Score="<<score;
        return false;

    }
    for(int i=0; i<lengthofsnake; i++)          //checks death on colliding with itself
    {

        if(i==head) continue;
        else if(i!=head)
            if(snake[head].getX()==snake[i].getX() && snake[head].getY()==snake[i].getY() )
            {
                cout<<"\nGAME OVER\n Score="<<score;
                return false;
            }


    }

    return true;
}


int dist(int x1,int x2,int y1,int y2)        //created to check position of click in buttons
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double foodx(int &mazeno)                   //food appears at random points within bounds of canvas
{
    int a=rand() % 32;
    return a;
}
double foody(int &mazeno)
{
    int a=rand() % 17;
    return a;
}



main_program
{
    int mazeno=1;
    int level;

    initCanvas("snake",1320,720);                  //creating canvas and displaying buttons to play/get help etc.
    Text t1(660,100,"WELCOME TO THE SNAKE GAME");

    button play;
    play.r.reset(660,250,50);
    play.t.reset(660,250,"PLAY");
    play.r.setFill(true);
    play.r.setColor(COLOR(0,255,0));

    button instrns;
    instrns.r.reset(660,350,50);
    instrns.t.reset(660,350,"HELP");
    instrns.r.setFill(true);
    instrns.r.setColor(COLOR(0,255,255));

    button about;
    about.r.reset(660,450,50);
    about.t.reset(660,450,"ABOUT");
    about.r.setFill(true);
    about.r.setColor(COLOR(0,0,255));

    button exit;
    exit.r.reset(660,550,50);
    exit.t.reset(660,550,"EXIT");
    exit.r.setFill(true);
    exit.r.setColor(COLOR(255,0,0));

    while(1)                       //detecting click position and accordingly going ahead.
    {
        int a=getClick();
        int x=a/65536;
        int y=a%65536;
        if(dist(x,660,y,250)<50)
        {
            t1.hide();
            play.hide();
            instrns.hide();
            about.hide();

            Text mazenos(660,150,"CHOOSE THE MAZE YOU WANNA PLAY..!!");

            button maze1;
            maze1.r.reset(660,250,50);
            maze1.t.reset(660,250,"MAZE 1");
            maze1.r.setFill();
            maze1.r.setColor(COLOR(0,0,100));

            button maze2;
            maze2.r.reset(660,350,50);
            maze2.t.reset(660,350,"MAZE 2");
            maze2.r.setFill();
            maze2.r.setColor(COLOR(0,0,175));

            button maze3;
            maze3.r.reset(660,450,50);
            maze3.t.reset(660,450,"MAZE 3");
            maze3.r.setFill();
            maze3.r.setColor(COLOR(0,0,250));

            while(1)
            {
                int click3=getClick();
                int x3=click3/65536;
                int y3=click3%65536;
                if(dist(x3,660,y3,250)<50)
                {
                    mazeno=1;
                    break;
                }
                else if(dist(x3,660,y3,350)<50)
                {
                    mazeno=2;
                    break;
                }
                else if(dist(x3,660,y3,450)<50)
                {
                    mazeno=3;
                    break;
                }
                else
                {
                    return 0;
                }


            }

            Text leveltype(660,100,"CHOOSE THE LEVEL YOU WANNA PLAY..!!");//USING SAME OBJECTS maze 1,maze 2,maze 3,for level 1,level 2,level
            mazenos.hide();

            maze1.t.reset(660,250,"EASY");

            maze2.t.reset(660,350,"NORMAL");

            maze3.t.reset(660,450,"TOUGH");

            while(1)
            {
                int click3=getClick();
                int x3=click3/65536;
                int y3=click3%65536;
                if(dist(x3,660,y3,250)<50)
                {
                    level=1;
                    break;
                }
                else if(dist(x3,660,y3,350)<50)
                {
                    level=2;
                    break;
                }
                else if(dist(x3,660,y3,450)<50)
                {
                    level=3;
                    break;
                }
                else
                {
                    return 0;
                }

            }


            maze1.hide();
            maze2.hide();
            maze3.hide();
            about.hide();
            leveltype.hide();
            mazenos.hide();
            exit.hide();



            break;

        }

        else if(dist(x,660,y,350)<50)
        {
            t1.hide();
            play.hide();
            instrns.hide();
            exit.hide();
            Text a(660,200,"Press w to move ABOVE.");
            Text b(660,220,"Press s to move DOWN. ");
            Text c(660,240,"Press a to move LEFT.");
            Text d(660,260,"Press d to move RIGHT.");
            Text e(660,280,"Do NOT turn CAPSLOCK ON.");
            Text f(660,300,"Make the snake eat food and do not let it collide into wall or itself.");
            button backtomm;
            backtomm.r.reset(660,450,50);
            backtomm.t.reset(660,450,"Back To Main Menu");
            backtomm.r.setFill();
            backtomm.r.setColor(COLOR(0,250,0));

            while(1)
            {
                int click2 =getClick();
                int x2=click2/65536;
                int y2=click2%65536;
                if(dist(x2,660,y2,440)<50)
                {
                    a.hide();
                    b.hide();
                    c.hide();
                    d.hide();
                    e.hide();
                    f.hide();
                    backtomm.hide();
                    break;
                }
            }
            t1.show();
            play.show();
            instrns.show();
            exit.show();
            continue;


        }
        else if(dist(x,660,y,450)<50)
        {
            t1.hide();
            play.hide();
            instrns.hide();
            exit.hide();
            Text a(660,200,"This is version 1.0 of snake.");
            Text b(660,220,"This has been developed by ");
            Text c(660,240,"Pratham Shah");
            Text d(660,260,"Rudra Kande");
            Text e(660,280,"Sanjana Vernekar");
            Text f(660,300,"Nimisha ");
            button backtomm;
            backtomm.r.reset(660,450,50);
            backtomm.t.reset(660,450,"Back To Main Menu");
            backtomm.r.setFill();
            backtomm.r.setColor(COLOR(0,250,0));

            while(1)
            {
                int click2 =getClick();
                int x2=click2/65536;
                int y2=click2%65536;
                if(dist(x2,660,y2,440)<50)
                {
                    a.hide();
                    b.hide();
                    c.hide();
                    d.hide();
                    e.hide();
                    backtomm.hide();
                    break;
                }
            }
            t1.show();
            play.show();
            instrns.show();
            exit.show();
            continue;


        }

        else if(dist(x,660,y,550)<50)
        {
            return 0;

        }
    }


    int head=0;
    int lengthofsnake=7;

    Circle *snake;                             //dynamic allocation so tht size of snake can be increased in future
    snake=new Circle[lengthofsnake];
    if(snake==NULL)
    {
        closeCanvas(); cout<<"Memory Allocation Error. Please restart the game.";
    }

    for(int i=0; i<lengthofsnake; i++)        //initialisation of snake
    {
        snake[lengthofsnake-i-1].reset(120+40*i,400,20);
        snake[lengthofsnake-i-1].setColor(COLOR(0,30,0));
        snake[lengthofsnake-i-1].setFill(true);
    }

    char previnstrn='d',nextinstrn='d';

    int time=0;

    int fx=foodx(mazeno)*40;          //initialisation of food
    int fy=foody(mazeno)*40;
    Circle food(fx, fy, 10);
    food.setColor(COLOR(220,0,0));
    food.setFill(true);
    food.hide();
    bool showfood=true;

    int score=0;                                   //initialisation of score
    Text sc(620,710,"Score:");
    Text s(660,710,score);
    int foodtimer=((4-level)*25);

    while(checkmoves(mazeno,head,lengthofsnake,snake,score))         //loop for playing the game
    {

        if(time%foodtimer==1)                 //periodic occurence of food
        {
            fx=foodx(mazeno)*40;
            fy=foody(mazeno)*40;
            food.reset(fx,fy,10);
            if (showfood)
            {
                food.show();
            }
            else
            {
                food.hide();
            }
            showfood=(!showfood);

        }

        XEvent next;
        if(checkEvent(next) && keyPressEvent(next))
        {
            nextinstrn= charFromEvent(next);
        }

        move(previnstrn,nextinstrn,snake,lengthofsnake,head);      //call to move function

        head=(head+lengthofsnake-1)%lengthofsnake;                 //redefining new head
        time++;
        if(time%35==0)
        {
            score++;                                              //score increases for staying in game
        };
        s.reset(660,710,score);

        checkfoodeaten(food,fx,fy,snake,lengthofsnake,head,previnstrn,score);  //call to function

        if (level==1) wait(0.4);
        else if (level==2) wait(0.2);                             //to vary speed of snake in different levels
        else if (level==3) wait(0.05);
    }
}












