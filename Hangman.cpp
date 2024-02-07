#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <corecrt_math.h>
#include <corecrt_wio.h>
#include <Windows.h>
#include <conio.h>


/*

1 - EASY
2 - MEDIUM
3 - HARD

*/


int begin(int menuchoice) {
    char enter;

    scanf("%d", &menuchoice);
    scanf("%c", &enter);

    while (menuchoice < 1 || menuchoice > 3) {
        printf("Please choose from 1 - 3\n\n");

        scanf("%d", &menuchoice);
        scanf("%c", &enter);
    }

    return menuchoice;
}

int settingschoice(int casescenario) {

    char enter;

    scanf("\n%d", &casescenario);
    scanf("%c", &enter);

    while (casescenario < 1 || casescenario > 4) {
        printf("Please choose from 1 - 4\n\n");

        scanf("%d", &casescenario);
        scanf("%c", &enter);
    }

    return casescenario;
}

int difficultychoice () {
    int casescenario;
    char enter;

    scanf("\n%d", &casescenario);
    scanf("%c", &enter);

    while (casescenario < 1 || casescenario > 3) {
        printf("Please choose from 1 - 3\n\n");

        scanf("%d", &casescenario);
        scanf("%c", &enter);
    }

    return casescenario;
}

int colourchoice(int colourmap) {

    char enter;
   
    printf("\n\n            1. Red\n            2. Purple\n            3. Green\n            4. White\n            5. Blue\n");

    scanf("%d", &colourmap);
    scanf("%c", &enter);

    while (colourmap < 1 || colourmap > 5) {
        printf("Please choose from 1 - 5\n\n");

        scanf("%d", &colourmap);
        scanf("%c", &enter);
    }

    return colourmap;
}

int oneortwo(int multiplayer) {

    char enter;

    scanf("%d", &multiplayer);
    scanf("%c", &enter);

    while (multiplayer < 1 || multiplayer > 2) {
        printf("Please choose from 1 - 2\n\n");

        scanf("%d", &multiplayer);
        scanf("%c", &enter);
    }

    return multiplayer;
}

int easyrandomizer() {

    int randomnumbers[30];
    int i = 0;

    time_t t;
    int random;

        srand((unsigned)time(&t));
        randomnumbers[i] = rand() % 4 + 1;
        randomnumbers[1] = rand() % 4 + 1;

        while (randomnumbers[i] == randomnumbers[1]){

            randomnumbers[i] = rand() % 4 + 1;
            randomnumbers[1] = rand() % 4 + 1;

        }

            return randomnumbers[1];
                
    }

    


int mediumrandomizer() {

    int randomnumbers[30];
    int i = 0;
    time_t t;
    int random;

    srand((unsigned)time(&t));
    randomnumbers[i] = rand() % 9 + 1;
    randomnumbers[1] = rand() % 9 + 1;

    while (randomnumbers[i] == randomnumbers[1]) {

        randomnumbers[i] = rand() % 9 + 1;
        randomnumbers[1] = rand() % 9 + 1;

    }

    return randomnumbers[1];
}

int hardrandomizer() {

    int randomnumbers[30];
    int i = 0;
    time_t t;
    int random;

    srand((unsigned)time(&t));
    randomnumbers[i] = rand() % 19 + 1;
    randomnumbers[1] = rand() % 19 + 1;

    while (randomnumbers[i] == randomnumbers[1]) {

        randomnumbers[i] = rand() % 19 + 1;
        randomnumbers[1] = rand() % 19 + 1;

    }

    return randomnumbers[1];
}

int playerclublegendmix (int max, int min) {

    time_t t;
    int random;

    srand((unsigned)time(&t));
    random = rand() % max + min;

    return random;
}

void underscoring(char hangmanword[], int wordsize) {
    int i = 0;
    for (i = 0; i < wordsize; i++) {
        hangmanword[i] = '_';
    }
    hangmanword[i] = '\0';
}

int userguesses(char hangmanword[15], char name[20], int wordsize) {

    char usersinput[20];
    int i = 0;
    int incorrect = 0;
    char enter;
    int flag = 0;

   while (incorrect < 7) {

       printf("\n\nNumber of mistakes: %d\n\n", incorrect);

       scanf("%s", usersinput);
       scanf("%c", &enter);
       
       if (strlen(usersinput) > 1) {
           printf("User has input a  word %s\n", usersinput);
           if (strcmp(name, usersinput) == 0) {
               printf("\n\nYou have guessed correctly!\nThe word is %s\n\n\n", name);
               break;
           }
           else {
               printf("\n\nUser has not guessed correctly try again!");
               incorrect++;
           }
           
       }
       else {
           printf("User has input a character %c\n", usersinput[0]);
           for (i = 0; i < wordsize; i++) {

               if (usersinput[0] == name[i]) {
                   hangmanword[i] = usersinput[0];
                   flag = 1;
                   }
               
           }
           if (flag == 0) {
               incorrect++;
           }
           else {
               flag = 0;
           }
           printf("\n\n%s", hangmanword);
       }
       }
   if (incorrect == 7) {
       printf("\n\nThe word was %s\n\n\n", name);
   }
    return 0;
}



void twoplayerfunction(char hangmanword[15], char name[20], int wordsize, int finalscore[]) {

    char playeroneinput[20];
    char playertwoinput[20];
    char enter;

    int i = 0;
    int incorrect = 0;
    int flag = 0;
    int turn = 1;
    int playeronemistakes = 0;
    int playertwomistakes = 0;
    int playeronepoints = 0;
    int playertwopoints = 0;
    int letterCounter = 0;
    int wordGuessed = 0;

    while (playeronepoints >= 10 || playertwopoints >= 10 || playeronemistakes < 7 || playertwomistakes < 7) {

        printf("\n\nPlayer one mistakes: %d\n\n", playeronemistakes);

        printf("\n\nPlayer two mistakes: %d\n\n", playertwomistakes);

        scanf("%s", playeroneinput);
        scanf("%c", &enter);

        if (strlen(playeroneinput) > 1) {
            printf("User has input a word %s\n", playeroneinput);
            if (strcmp(name, playeroneinput) == 0) {
                printf("\n\nYou have guessed correctly!\nThe word is %s\n\n\n", name);
                if (turn == 1) {
                    playeronepoints += 3;
                    turn = 2;
                }
                else {
                    playertwopoints += 3;
                    turn = 1;
                }
                
                break;
            }
            else {
                printf("\n\nUser has not guessed correctly!");

                if (turn == 1) {
                    playeronemistakes++;
                    turn = 2;
                }
                else {
                    playertwomistakes++;
                    turn = 1;
                }

            }

        }
        else {
            printf("\n\nUser has input a character %c", playeroneinput[0]);
            for (i = 0; i < wordsize; i++) {

                if (playeroneinput[0] == name[i]) {
                    hangmanword[i] = playeroneinput[0];
                    if (turn == 1) {
                        if (letterCounter == 0) {
                            playeronepoints++;
                            letterCounter = 1;
                        } 
                        
                    }
                    else {
                        if (letterCounter == 0) {
                            playertwopoints++;
                            letterCounter = 1;
                        }
                    }
                    
                    if (strcmp(hangmanword, name) == 0) {
                        wordGuessed = 1;
                        break;
                    }
                }

            }
            printf("\n\nPlayer one points :%d", playeronepoints);

            printf("                    Player two points :%d\n", playertwopoints);

            if (wordGuessed == 1) {
                break;
            }

            if (letterCounter == 0) {
                if (turn == 1) {
                    playeronemistakes++;
                }

                else {
                    playertwomistakes++;
                }
            }
            else {
                letterCounter = 0;
            }
 
            if (turn == 1) {
                turn = 2;
            }
            else {
                turn = 1;
            }


            printf("\n\n%s", hangmanword);
        }
        if (playeronemistakes == 7 || playertwomistakes == 7) {
            printf("\n\nThe word was %s\n\n\n", name);
        }
    }

    finalscore[0] = playeronepoints + finalscore[0];
    finalscore[1] = playertwopoints + finalscore[1];
   
}

void twoplayerfunctioncategorybased(char hangmanword[15], char name[20], int wordsize, int finalscore[]) {

    char playeroneinput[20];
    char playertwoinput[20];
    char enter;

    int i = 0;
    int incorrect = 0;
    int flag = 0;
    int turn = 1;
    int playeronemistakes = 0;
    int playertwomistakes = 0;
    int playeronepoints = 0;
    int playertwopoints = 0;

    int wordGuessed = 0;

    while (playeronepoints >= 10 || playertwopoints >= 10 || playeronemistakes < 7 || playertwomistakes < 7) {

        printf("\n\nPlayer one mistakes: %d\n\n", playeronemistakes);

        printf("\n\nPlayer two mistakes: %d\n\n", playertwomistakes);

        scanf("%s", playeroneinput);
        scanf("%c", &enter);

        if (strlen(playeroneinput) > 1) {
            printf("User has input a word %s\n", playeroneinput);
            if (strcmp(name, playeroneinput) == 0) {
                printf("\n\nYou have guessed correctly!\nThe word is %s\n\n\n", name);
                if (turn == 1) {
                    playeronepoints += 3;
                }
                else {
                    playertwopoints += 3;
                }
                printf("\n\nPlayer one points :%d", playeronepoints);

                printf("                    Player two points: %d\n\n", playertwopoints);
                break;
            }
            else {
                printf("\n\nUser has not guessed correctly!");

                if (turn == 1) {
                    playeronemistakes++;
                }

                else {
                    playertwomistakes++;
                }
            }

        }
        else {
            printf("\n\nUser has input a character %c", playeroneinput[0]);
            for (i = 0; i < wordsize; i++) {

                if (playeroneinput[0] == name[i]) {
                    hangmanword[i] = playeroneinput[0];
                    if (turn == 1) {
                        playeronepoints++;
                    }
                    else {
                        playertwopoints++;
                    }
                    printf("\n\nPlayer one points :%d", playeronepoints);

                    printf("                    Player two points :%d", playertwopoints);
                    if (strcmp(hangmanword, name) == 0) {
                        wordGuessed = 1;
                        break;
                    }
                    flag = 1;
                }

            }

            if (wordGuessed == 1) {
                break;
            }

            if (flag == 0) {
                if (turn == 1) {
                    playeronemistakes++;
                }

                else {
                    playertwomistakes++;
                }
            }
            else {
                flag = 0;
            }

            if (turn == 1) {
                turn = 2;
            }
            else {
                turn = 1;
            }


            printf("\n\n%s", hangmanword);
        }
        if (playeronemistakes == 7 || playertwomistakes == 7) {
            printf("\n\nThe word was %s\n\n\n", name);
        }
    }

    finalscore[0] = playeronepoints + finalscore[0];
    finalscore[1] = playertwopoints + finalscore[1];

}

int main()
{

    //number variables
    int i;
    int hardfigures = 0;
    int easyfigures = 0;
    int quickplay = 1;
    int menuchoice{};
    int colourmap{};
    int casescenario = 0;
    int exit = 0;
    int multiplayer{};
    int playeronepoints = 0;
    int playertwopoints = 0;
    int finalscore[2] = { 0,0 };

    //word variables/ arrays
    char enter;
    char hangmanword[15];
    char name[20];
    char mediumword[20];
    int difficulty = 1;
    //2d strings
    char easy[5][20] = { "messi", "ronaldo", "guardiola", "klopp", "barcelona" };
    char medium[10][20] = { "messi", "ronaldo", "guardiola", "klopp", "barcelona", "arteta", "everton", "napoli", "lyon", "bundesliga" };
    char hard[20][20] = { "messi", "ronaldo", "guardiola", "klopp", "barcelona", "arteta", "everton", "napoli", "lyon", "bundesliga", "luton", "gervinho", "gibbs", "xavi", "boehly", "zidane", "kewell", "cahill", "edu", "blind" };

    char clubs[15][20] = { "madrid", "bayern", "arsenal", "juventus", "porto", "everton", "napoli", "lyon", "leverkuson", "feyenoord", "bury", "boavista", "como", "utrecht", "bielefeld" };
    char players[15][20] = { "messi", "ronaldo", "xavi", "zidane", "neymar", "cahill", "edu", "blind", "gervinho", "gibbs", "kewell", "drogba", "pepe", "gilberto", "denilson" };
    char legends[15][20] = { "pele", "maradona", "cruyff", "henry", "voller", "kaka", "viera", "ronaldinho", "maldini", "pirlo", "weah", "yashin", "nedved", "shevchenko", "owen" };

    while (exit == 0) {

        printf("\n\n\n           HANGMAN\n\n          1. Start\n          2. Settings\n          3. Exit\n\n\n");

        switch (begin(menuchoice)) {

        case 1:
            printf("            1. One Player\n            2. Two Player\n\n");
            switch (oneortwo(multiplayer)) {

            case 1:
                printf("Welcome\n\nThe rules are as follows\n\n1. A maximum of 6 attempts are allowed\n2. Only enter lowercase letters\n3. Have fun! \n\n\n");

                if (difficulty == 1) {
                    strcpy(name, easy[(easyrandomizer())]);
                    underscoring(hangmanword, strlen(name));
                }

                else if (difficulty == 2) {
                    strcpy(name, medium[mediumrandomizer()]);
                    underscoring(hangmanword, strlen(name));
                }

                else if (difficulty == 3) {
                    strcpy(name, hard[hardrandomizer()]);
                    underscoring(hangmanword, strlen(name));
                }

                printf("We have a word! You can begin by giving me a character...\n\n");

                printf("%s\n", hangmanword);

                userguesses(hangmanword, name, strlen(name));

                break;

            case 2:

                printf("\n\n1. Quickplay\n2. Category based\n");
                scanf("%d", &quickplay);
                scanf("%c", &enter);

                while (quickplay < 1 || quickplay > 2) {
                    printf("Please choose from 1 - 2\n\n");

                    scanf("%d", &quickplay);
                    scanf("%c", &enter);
                }
                printf("Welcome\n\nThe rules are as follows\n1. A maximum of 6 attempts are allowed for each word\n2. Only enter lowercase letters\n3. You win 1 point for each character you get\n4. You win 3 points for each word you guess correctly\n5. 3 Rounds are played and whoever gets the most points wins!\n6. Both players are competing for the same word\n7. Have fun! \n\n\n");

                if (quickplay == 1) {
                    for (int i = 0; i < 3; i++) {


                        if (difficulty == 1) {
                            strcpy(name, easy[easyrandomizer()]);
                            underscoring(hangmanword, strlen(name));
                        }

                        else if (difficulty == 2) {
                            strcpy(name, medium[mediumrandomizer()]);
                            underscoring(hangmanword, strlen(name));
                        }

                        else if (difficulty == 3) {
                            strcpy(name, hard[hardrandomizer()]);
                            underscoring(hangmanword, strlen(name));
                        }

                        printf("\n\nWe have a word! You can begin by giving me a character...\n\n");

                        printf("%s\n", hangmanword);

                        twoplayerfunction(hangmanword, name, strlen(name), finalscore);



                    }
                }
                else {
                    printf("\n\nYou have chosen category based, please select which difficulty you would like.\n1. Easy\n2. Medium\n3. Hard\n");
                    casescenario = difficultychoice();

                    if (casescenario == 1) {
                        easyfigures = 4;
                        hardfigures = 1;

                    }

                    else if (casescenario == 2) {
                        easyfigures = 9;
                        hardfigures = 1;
                    }

                    else if (casescenario == 3) {
                        easyfigures = 14;
                        hardfigures = 1;
                    }

                    strcpy(name, clubs[playerclublegendmix(easyfigures, hardfigures)]);
                    underscoring(hangmanword, strlen(name));

                    printf("\n\nWe have a word under...\n           CLUBS!\n You can begin by giving me a character...\n\n");

                    printf("%s\n", hangmanword);

                    twoplayerfunctioncategorybased(hangmanword, name, strlen(name), finalscore);

                    strcpy(name, players[playerclublegendmix(easyfigures, hardfigures)]);
                    underscoring(hangmanword, strlen(name));

                    printf("\n\nWe have a word under...\n           PLAYERS!\n You can begin by giving me a character...\n\n");

                    printf("%s\n", hangmanword);

                    twoplayerfunctioncategorybased(hangmanword, name, strlen(name), finalscore);


                    strcpy(name, legends[playerclublegendmix(easyfigures, hardfigures)]);
                    underscoring(hangmanword, strlen(name));

                    printf("\n\nWe have a word under...\n           LEGENDS\n You can begin by giving me a character...\n\n");

                    printf("%s\n", hangmanword);

                    twoplayerfunctioncategorybased(hangmanword, name, strlen(name), finalscore);


                }
            }

            if (finalscore[0] > 0) {
                printf("\n\nTotal points for player one: %d", finalscore[0]);

                printf("\n\nTotal points for player two: %d", finalscore[1]);

                if (finalscore[0] > finalscore[1]) {
                    printf("\n\nCongratulations player one you have won!");
                }

                else if (finalscore[0] == finalscore[1]) {
                    printf("\n\nDraw!!\nI guess I'm the winner!");
                }

                else if (finalscore[1] > finalscore[0]) {
                    printf("\n\nCongratulations player two you have won!");
                }
            }
            break;

        case 2:
            printf("           HANGMAN\n\n          SETTINGS\n          1. Easy\n          2. Medium\n          3. Hard\n          4. Change Text Colour\n\n\n");

            switch (settingschoice(casescenario)) {

            case 1:
                printf("\n\nEasy setting applied.\n\n");

                difficulty = 1;

                break;

            case 2:
                printf("\n\nMedium setting applied.\n\n");

                difficulty = 2;

                break;

            case 3:
                printf("\n\nHard setting applied.\n\n");

                difficulty = 3;

                break;

            case 4:

                switch (colourchoice(colourmap)) {
                case 1:
                    printf("\033[1;31m");
                    break;

                case 2:
                    printf("\033[1;35m");
                    break;

                case 3:
                    printf("\033[0;32m");
                    break;

                case 4:
                    printf("\033[0;37m");
                    break;

                case 5:
                    printf("\033[0;34m");
                    break;

                }

                break;
            }
            break;
        case 3:

            printf("Bye!");
            exit = 1;

            break;
        }
        }
        return 0;
    
}

    


