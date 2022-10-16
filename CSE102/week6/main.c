#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void arrcopy(char arr[15][15], char copy[15][15]);      /*copies two arrays*/
void print(char arr[15][15]);                           /*prints the table*/
void switchDir(int *dir, int *dirx, int *diry);         /*includes direction values*/
int randomizer(FILE *);                                /*goes to a random line in the file*/
char *samecheck(FILE *dictionary, int sameline[8], int line, char tempWord[10]);        /*checks if the same word has been written or not*/

int main()
{
    FILE *dictionary;
    char arr[15][15] = {}, copy[15][15] = {};
    
    int drawArrFlag = 7;                                /*draws this much numbers on the table*/
    char word[10] = {};
    char tempWord[10] = {};
    int x = 0, y = 0, dir = 0, dirx = 0, diry = 0, tempx = 0, tempy = 0;
    int i = 0, j = 0, temp = 0;
    char *randTemp = NULL;
    char random;
    int points = 0, turn = 3;
    int sameline[8] = {};
    int line = 0, lineIndex = 0;

    dictionary = fopen("wordlist.txt", "r+");
    srand(time(NULL));

    while(drawArrFlag)
    {
        
        x = rand() % 15;
        y = rand() % 15;
        dir = rand() % 8;   /*sets word direction*/
        tempx = x;
        tempy = y;
        arrcopy(arr, copy); /*array is being backupped in case if something goes wrong. if that happens array is ready to be recovered.*/
        
        temp = randomizer(dictionary);

        fscanf(dictionary, " %s", word);            /*reading the word to be written*/

        samecheck(dictionary, sameline, temp, tempWord);
        if(strcmp(tempWord, word) == 0)                 /*if the random word is a word saved in the sameline array(word line indexes are saved), it starts over.*/
                continue;
        else if(lineIndex < 7)
        {
            sameline[lineIndex] = temp;
            lineIndex++;
        }

        temp = 0; /*just for safety*/
        switchDir(&dir, &dirx, &diry);              /*determines direction*/
        i = 0;
        while(word[i])
        {
            if(arr[y + diry][x + dirx] == '\0')
                {

                    if(!(dirx == 1 && x == 14) && !(dirx == -1 && x == 0) && !(diry == 1 && y == 14) && !(diry == -1 && y == 0))    /*borders are being handled.*/
                    {
                        arr[y + diry][x + dirx] = word[i];  /*always adding the direction values. if the cursor does not move in a direction it does not matter since the direction value will be +0*/
                        y += diry;
                        x += dirx;
                        i++;
     
                        if(word[i] == '\0')        /*if we come to the end in this if statement, it means that word has ended and it is time to move on.*/         
                            drawArrFlag--;          /*flag is the word count.*/
                        
                        if(drawArrFlag == 0)        /*if all words are written, get out.*/
                            break;
                    }
                    else
                    {
                        arrcopy(copy, arr);         /*if there is some problem in writing to array, program recovers the array's last state and starts over again.*/
                        break;
                    }
                }
            else
            {
                arrcopy(copy, arr);                 /*if there is some problem in writing to array, program recovers the array's last state and starts over again.*/
                break;
            }
        }
    }
    arrcopy(arr, copy);
    print(arr);
    
    dir = 0;
    drawArrFlag = 7;
    while(drawArrFlag)
    {
        printf("\nEnter the coordinates and word: ");
        scanf("%[^\n]%*c", tempWord);                   /*scanning until a '\n' is encountered, so the string includes spaces. I used this because ':q' works better this way since there are 2 input formats.*/
        if(strcmp(tempWord, ":q") == 0)                 /*first input format: ':q' and secon input format is : "%d %d %s". this way I can handle both.*/
            {
                printf("Exiting...");
                fclose(dictionary);
                return 0;
            }

        sscanf(tempWord, "%d %d %s", &x, &y, word);     /*spliting the string into x,y and word*/
        dir = 0;
        temp = 1;                                       /*this is a counter. if whe entered word matches the dictionary, program proceeds to the next mission: searching*/
        rewind(dictionary);
        while(!feof(dictionary))
        {
            fscanf(dictionary, " %s", tempWord);        /*as said, this loop look for a match fow our entered word.*/
            temp = strcmp(tempWord, word);
            if(temp == 0)
                break;
        }
        i = 0;
        while(word[i] && !temp)
        {
            switchDir(&dir, &dirx, &diry);
            if(arr[y][x] == word[i])    /*since we always control the next place, the initial x,y values should be controlled in a special way.*/
            {
                arr[y][x] = 'X';
                i++;
            }
            if(!(dirx == 1 && x == 14) && !(dirx == -1 && x == 0) && !(diry == 1 && y == 14) && !(diry == -1 && y == 0) && arr[y + diry][x + dirx] == word[i]) /*boundary and equality check*/
            {
                arr[y + diry][x + dirx] = 'X';
                y += diry;
                x += dirx;
                i++;

                if(word[i] == '\0') /*this only is true when words match int the correct place.*/
                {
                    arrcopy(arr,copy);
                    print(arr);
                    points += 2;
                    printf("\nFound! You've got 2 points. Your total points: %d", points);
                    if(points == 14)
                        {
                            printf("\nCONGRATS YOU WON!");
                            fclose(dictionary);
                            return 0;
                        }
                    drawArrFlag--;
                }
                if(drawArrFlag == 0)
                    break;
            }
            else
            {
                dir++;          /*searching direcction always changes until it matches the word or all directions have been scanned.*/
                if(dir == 8)    /*end of direction scan in here means that all directions have been loked but no match has been found.*/
                {
                    turn--;         /*decreasing the chance*/
                    if(turn != 0)
                        printf("\nWrong choice! You have only %d left.(Invalid place)\n", turn);  
                    else
                    {
                        printf("\nWrong choice! There are no chances left. You lost the game.\n");
                fclose(dictionary);
                        return 0;
                    }
                    break;
                }
                else
                {
                    i = 0;              /*if there are directions to look and the word still couldn't been matched, program starts over by recovering the array to its old state and reseting the index of the word.*/
                    arrcopy(copy, arr);
                }
            }
        }
        
        if(temp != 0)
        turn--;                 /*this only happens when the input format is wrong or the entered word is unmatched*/
        if(word[i] != '\0')
        {
        if(turn != 0)
            printf("\nWrong choice! You have only %d left.(Invalid word)\n", turn);   
        else
        {
            printf("\nWrong choice! There are no chances left. You lost the game.\n");
            fclose(dictionary);
            return 0;
        }
        }
    }
    
    fclose(dictionary);
    return 0;
}

void print(char arr[15][15])
{
    printf("\n");
    for(int i = 0; i < 15; i++)
            {
                for(int j = 0; j < 15; j++)
                {
                    if(arr[i][j] == 0)
                        arr[i][j] =  '*';            /*fills blank spaces with random words. if you want to see clearly, change (rand() % 26) + 97 to '*'*/
                    printf("%c ", arr[i][j]);
                }
                printf("\n");
            }
}
void arrcopy(char arr[15][15], char copy[15][15])   /*this function is both used for copying the original array and recovering from the copy.*/
{
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            copy[i][j] = arr[i][j];
}

void switchDir(int *dir, int *dirx, int *diry)
{
    switch(*dir)
        {
            case 0:                                 /*-1 means decreasing, 0 means not changing, 1 means increasing in that direction.*/
                *dirx = 1;
                *diry = 0;
                break;
            case 1:
                *dirx = 1;
                *diry = 1;
                break;
            case 2:
                *dirx = 0;
                *diry = 1;
                break;
            case 3:
                *dirx = -1;
                *diry = 1;
                break;
            case 4:
                *dirx = -1;
                *diry = 0;
                break;
            case 5:
                *dirx = -1;
                *diry = -1;
                break;
            case 6:
                *dirx = 0;
                *diry = -1;
                break;
            case 7:
                *dirx = 1;
                *diry = -1;
                break;
        }
}

int randomizer(FILE *dictionary)
{
    char word[20];
    int random = 0;
    rewind(dictionary);
        random = rand() % 50;
        int Return = random;
        while(random > 1)
        {
            fscanf(dictionary, " %s", word);        /*this loop picks a random line in the words file*/
            random--;
        }
    return Return;
}

char *samecheck(FILE *dictionary, int sameline[8], int line, char tempWord[10])
{
    rewind(dictionary);
    for(int i = 0; i < line; i++)
        fscanf(dictionary, " %s", tempWord);
    
    fscanf(dictionary, " %s", tempWord);
}