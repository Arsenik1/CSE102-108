#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap();
int dice();
int startGame();

int main()
{
    int p1, p2;                   /*p1 and p2 holds dice values of players*/
    int x1 = 1,x2 = 3,y1 = 1,y2 = 3;            /*these x and y values hold where the players were in previous moves*/
    int dirx1 = 1,dirx2 = 1,diry1 = 0,diry2 = 0;    /*These are direction multipliers. The condition of these variable are changed when players encounter with a corner.*/
    int draw = 0; /*checks draw*/
    srand(time(NULL));                              /*By default these direction values' directions are to the right as y always differs by '0' and x differs by '+1'.*/
char arr[15][30]={"..............................",         /*Initializing the array*/
                  ":1            X              :",
                  ":_.......................... :",
                  ": :2      X       X        : :",
                  ": :_...................... : :",
                  ": : :                    :X: :",
                  ": : :                    : : :",
                  ": : :                    : :X:",
                  ": : :                    : : :",
                  ": : :                    : : :",
                  ": : ......................X: :",
                  ": :       X       X        : :",
                  ": .......................... :",
                  ":             X              :",
                  "..............................",};
    printMap(arr);
    int first = startGame();                                /*this variable will determine which player will start*/
    int turn = 1;               /*This variable is being used for the dice rolls at every round.*/
    while(1)
    {
        turn = 1;
        while(1)
        {
            if(first == 1)
                {
                    printf("\n\033[0;33mPLAYER 1... press ENTER to dice"); while(getchar() != '\n');
                    p1 = dice();
                    printf("\nDICE: %d\033[0;37m",p1);
                    turn++;                                 /*When turn = 3, it means that two dices have been rolled.*/
                    first = 2;                              /*'first' variable always swings between 1 and 2 symbolizing player 1 and 2.*/
                }
            else if(first == 2)
            {
                printf("\n\033[0;34mPLAYER 2... press ENTER to dice"); while(getchar() != '\n');
                p2 = dice();
                printf("\nDICE: %d\033[0;37m",p2);
                turn++;
                first = 1;
            }
            if(turn == 3)   /*This condition is being met when both players have rolled their dices.*/
                break;
        }

        while(p1 > 0)
        {
            if(x1 == 1 && y1 == 2)  /*This condition will widely be used in p2 loop which is below this current loop*/
                {
                    draw = 1;
                    break;
                }
            else if((x2 == 3 && y2 == 4) && (x1 == 1 && y1 == 2))                   /*If both have passed the end, it is draw.*/
            {
                printf("\nDRAW");
                return 0;
            }
            if(x1 == 28 && y1 == 1) /*top right, new direction is south*/
            {
                dirx1 = 0;
                diry1 = 1;
            }
            else if(x1 == 28 && y1 == 13) /*bottom right, new direction is west*/
            {
                dirx1 = -1;
                diry1 = 0;
            }
            else if(x1 == 1 && y1 == 13) /*bottom left, new direction is north*/
            {
                dirx1 = 0;
                diry1 = -1;
            }
            if(arr[y1 + diry1][x1 + dirx1] == 'X' && p1 == 1)       /*if 'X' is in the next box and at the end of the move*/
            {
                arr[y1 - diry1][x1 - dirx1] = '1';                  /*X is one box ahead so we should put our position one box behind*/
                printf("\n\033[0;31m\nPenalty for Player 1...\033[0;37m");
                arr[y1][x1] = ' ';
                y1 -= 2*diry1;          /*these should be decreased by 1 times the direction but since we inrease coordinate values by 1 in 99 and 100'th lines*/
                x1 -= 2*dirx1;          /*the should be decreased by 1 more.                                                                                   */
            }
            else
                {
                    arr[y1 + diry1][x1 + dirx1] = '1';
                    arr[y1][x1] = ' ';
                }
            y1 += diry1;
            x1 += dirx1;
            p1--;
        }


        while(p2 > 0)
        {
            if((x2 == 3 && y2 == 4) && draw == 0)   /*'draw' flag hasn't been activated which means p1 couldn't reach the finish line but p2 did.*/
                {
                    printf("\n\033[0;34m***Player 2 WON THE GAME***\033[0;37m");
                    printMap(arr);
                    return 0;
                }
            else if((x2 == 3 && y2 == 4) && draw == 1)          /*This means both have won*/
                {
                    printf("\n\033[0;33m***DRAW***\033[0;37m");
                    printMap(arr);
                    return 0;
                }
            else if(draw == 1)                      /*'draw' flag hasn been activated which means p1 could reach the finish line but p2 did't.*/
                {
                    printf("\n\033[0;33m***Player 1 WON THE GAME***\033[0;37m");
                    printMap(arr);
                    return 0;
                }
            if(x2 == 26 && y2 == 3) /*top right*/
            {
                dirx2 = 0;
                diry2 = 1;
            }
            else if(x2 == 26 && y2 == 11) /*bottom right*/
            {
                dirx2 = -1;
                diry2 = 0;
            }
            else if(x2 == 3 && y2 == 11) /*bottom left*/
            {
                dirx2 = 0;
                diry2 = -1;
            }
            if(arr[y2 + diry2][x2 + dirx2] == 'X' && p2 == 1)
            {
                arr[y2 - diry2][x2 - dirx2] = '2';
                printf("\n\033[0;31m\nPenalty for Player 2...\033[0;37m");
                arr[y2][x2] = ' ';
                y2 -= 2*diry2;
                x2 -= 2*dirx2;
            }
            else
                {  
                    arr[y2 + diry2][x2 + dirx2] = '2';
                    arr[y2][x2] = ' ';
                }
            y2 += diry2;
            x2 += dirx2;
            p2--;
        }
        arr[1][14] = 'X'; arr[3][10] = 'X'; arr[3][18] = 'X'; arr[10][26] = 'X'; arr[11][18] = 'X';     /*program removes passed 'X's so I put them back.*/
        arr[13][14] = 'X'; arr[7][28] = 'X'; arr[5][26] = 'X'; arr[11][10] = 'X';
        printMap(arr);
    }

    return 0;
}

int startGame()     /*Nothing to explain here, it is very starightforward.*/
{
    int p1, p2;
    printf("\nTo start to game, players should dice and decide who is going to start first according to it...");
    while(1)
    {
        printf("\n\033[0;33mPLAYER 1... press ENTER to dice"); while(getchar() != '\n');
        p1 = dice();
        printf("\nDICE: %d\033[0;37m",p1);
        printf("\n\033[0;34mPLAYER 2... press ENTER to dice"); while(getchar() != '\n');
        p2 = dice();
        printf("\nDICE: %d\033[0;37m",p2);
        if(p1 < p2)
        {
            printf("\n*** PLAYER 2 will start the game... ***");
            return 2;
        }
        else if(p2 < p1)
        {
            printf("\n*** PLAYER 1 will start the game... ***");
            return 1;
        }
        else
            printf("\nSame dice value... Please try again.");
    }
}
void printMap(char arr[15][30]) /*Printing the map with the corresponding character colors.*/
{
    int i = 0, j = 0;
    printf("\n");
    for(i = 0; i < 15; i++)
        {
            for(j = 0; j < 30; j++)
            {
                if(arr[i][j] == 'X')
                    printf("\033[0;31mX\033[0;37m");
                else if(arr[i][j] == '1')
                    printf("\033[0;33m1\033[0;37m");
                else if(arr[i][j] == '2')
                    printf("\033[0;34m2\033[0;37m");
                else if(arr[i][j] == '_')
                    printf("\033[0;32m_\033[0;37m");
                else
                    printf("%c",arr[i][j]);
            }
            printf("\n");
        }
}
int dice() {return rand() % 6 + 1;} /*dice roll*/
