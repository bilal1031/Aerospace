#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>


//GLOBAL VARIABLES
int width = 0, height = 0;
int x = 50 / 2.1, y = 11 / 2; //x_ship,y_ship
int score = 0;
int game = 0;
int enemyship_removal = 0;
int x_bullet , y_bullet ; //x_bullet,y_bullet
int x_enemy , y_enemy ; //x_enemy,y_enemy
int e_bulletx , e_bullety ;

//PROTOTYPES
void intro();
void gamestart();
void aerogame();
void fire();
void enemy_fire();
void keys();
void endgame();


//MAIN FUNCTION
int main()
{

    intro();
    gamestart();


    return 0;
}




// custom delay function //taken from Internet
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}



void intro()
{
     srand(time(0));


    for (int i = 0; i < 5; i++)
    {
        printf("\n");
    }
    printf("                     |----------|\n");
    printf("                     |AERO SPACE|\n");
    printf("                     |----------|\n");
    printf("\n\n                   Press P to play!");
    printf("\n\n                   Press Q to quit!");
    printf("\n\n                   Press E to fire!");

}
void gamestart()
{
    int intro_key;
    x_bullet = x + 3, y_bullet = y - 1; //x_bullet,y_bullet
    x_enemy = rand() % 40, y_enemy = 0; //x_enemy,y_enemy
    e_bulletx = x_enemy + 2, e_bullety = y_enemy + 1;

    intro_key = getch();
    if (intro_key == 'p')
    {
        system("CLS");
        aerogame();
        getch();

    }
    else
    {
        system("CLS");
        printf("\nPress the key from given options.");
    }
}

//GAME SETUP
void aerogame() {

    printf("            Made By Bilal Naeem         Score:%d\n\n", score);

    //Setup

    for (height = 0; height < 10; height++)

    { //left boundary
        printf("|\n");

        for (width = 0; width < 50; width++)
        {
            //Aero Coordinate looping All about aero

            if (height == y && width == x)
            {
                printf("<==O==>");
                width = width + 7;

            }

            if (height == y_enemy && width == x_enemy)
            {
                //REAPEARENCE OF ENEMY AFTER DEATH
                if ((x_bullet == x_enemy || x_bullet == x_enemy + 1 || x_bullet == x_enemy + 2 || x_bullet == x_enemy + 3 || x_bullet == x_enemy + 4 || x_bullet == x_enemy + 5) && y_enemy == y_bullet - 2)
                {
                    printf("  ");
                    enemyship_removal = 1;
                    score = score + 10;
                    x_enemy = (rand() % width) + 8;
                    y_enemy = rand() % 5;
                    enemyship_removal = 0;
                    e_bullety = e_bullety + 1;
                    e_bulletx = e_bulletx + 2;

                }
                else if (enemyship_removal == 0)
                {

                    printf("-*0*-");

                    width = width + 5;

                }

            }
            if (height == e_bullety && width == e_bulletx)
            {
                printf("|");
                //goto enemy_fire;
                width = width + 1;

            }

            //  BULLET FIRE CONDITION
            if (height == y_bullet && width == x_bullet)
            {

                printf("|");

            }
            else
            {

                printf(" ");
            }

        }
        //right boundary
        printf("|\n");

        //Going out of boundary so game overs


    }
    //lower boundary part
    for (int i = 0; i <= 50; i++)
    {
        printf("-");
    }

    printf("\nPress 'Q' to exit.    Press 'R'  to restart.");

    //Going out of boundary so game overs
    if (x > 43 || y > 9 || x < 1 || y < 0)
        {
            endgame();
        }

    //GameOver when bullet hits enemy:

    if ((e_bulletx == x + 3 || e_bulletx == x + 2 || e_bulletx == x + 1 || e_bulletx == x + 4 || e_bulletx == x + 5 || e_bulletx == x + 6 || e_bulletx == x + 7) && e_bullety == y + 1)
    {
        //game = 1;
        delay(500);
        endgame();


    }
    keys();


}


void goback(){
    aerogame();
}


void keys(){

char key;

while(game!=1){
        //keys input
        if (kbhit())
        {

            key = getch();

            switch (key)
            {
            case 'a':
                x = x - 3;
                system("CLS");
                goback();
                break;
            case 'd':
                x = x + 3;
                system("CLS");
                goback();
                break;
            case 'w':
                y = y - 1;
                system("CLS");
                goback();
                break;
            case 's':
                y = y + 1;
                system("CLS");
                goback();
                break;
            case 'e':
                y_bullet = y - 1;
                x_bullet = x + 3;
                fire();
                break;
            case 'q':
                endgame();
                break;
            case 'r':
                system("CLS");
                score = 0;
                x = 50 / 2.1, y = 11 / 2; //x_ship,y_ship
                x_bullet = x + 3, y_bullet = y - 1; //x_bullet,y_bullet
                x_enemy = rand() % 40, y_enemy = 0;
                break;
            }

        }

        fire();
        enemy_fire();




    }
}
void fire(){

    while (y_bullet != -1)
            {
                if(game == 1){
                    break;
                    }
                y_bullet = y_bullet - 1;
                delay(20);
                system("CLS");
                goback();


            }
}

void enemy_fire(){
            while (e_bullety != 11)
            {   if(game == 1){
                    break;
                    }
                e_bullety = e_bullety + 1;
                delay(20);
                system("CLS");
                if (e_bullety > 11)
                {
                    e_bulletx = x_enemy + 2;
                    e_bullety = y_enemy + 1;
                }
                goback();
            }

}
void endgame(){

        system("CLS");
        printf("                GAME OVER!");
        printf("\n                Score: %d", score);
        game = 1;

}



