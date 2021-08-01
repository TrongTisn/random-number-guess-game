#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    //variables declaration
    //create random number
    int MAX;
    const MIN = 1;
    int ranNum;
    int userInput;
    int playAgain = 1;
    int gameMode;
    int levelType;
    int guessCount = 0;
    int resetScore;
    //green console
    system("color a");
    //game function
    void gameProcessor() {
           do {
            //ask random number
        printf("\nWhat is the random number?\n");
        printf("Your anwser: ");
        scanf("%d",&userInput);
        printf("\n");
            //check anwser
        if (ranNum < userInput) {
            printf("Number %d is too BIG ! Again", userInput);
            printf("\n\n");
            guessCount++;
        } else if (ranNum > userInput) {
            printf("Number %d is too SMALL ! Again", userInput);
            printf("\n\n");
            guessCount++;
        } else {
            printf("<<<<< You have found it, the number is %d >>>>>\n", ranNum);
            printf("Your score: %d\n",guessCount);
            //reset score
            printf("Do you want to reset your score? (1/0): ");
            scanf("%d",&resetScore);
            if (resetScore) {
                guessCount = 0;
            }
            //some more stuffs
            printf("Do you want to play again? (1/0): ");
            scanf("%d",&playAgain);
            printf("\n");
        }
    } while (userInput != ranNum);
    }
    //program ui
    //welcome

    printf("----- RANDOM NUMBER GAME -----\n");
    printf("Credit: Tin Nguyen Trong\n");
    printf("https://www.facebook.com/T1mpleo/ \n\n");

    printf("RULE: \n");
    printf("The lowest score, wins.\n");
    printf("Make a 'guess in one' and you will win the game \n\n");
    while (playAgain) {
    //2 player mode
    printf("GAME MODE: \n");
    printf("1.VS Computer\n");
    printf("2.Two Player\n");
    printf("Select game mode: ");
    scanf("%d",&gameMode);

    if (gameMode == 1) {
            //level
            printf("\n--- CHOOSE A LEVEL ----\n");
            printf("1.Easy (1 - 10)\n");
            printf("2.Normal (1 - 100)\n");
            printf("3.Hard (1 - 500)\n");
            printf("4.Extreme (1 - 1000)\n");
            printf("5.Bat tu cmnr (1 - 10000)\n");
            printf("Select level: ");
            scanf("%d",&levelType);
        //number MAX created depend on user input
            if (levelType > 0 && levelType <= 5) {
                switch(levelType) {
            case 1:
                MAX = 10;
                break;
            case 2:
                MAX = 100;
                break;
            case 3:
                 MAX = 500;
                 break;
            case 4:
                  MAX = 1000;
                  break;
            default:
                    MAX = 10000;
                    break;
            }
            } else {
             printf("\nYou entered an unsupported level, please try again!\n\n");
            }
            //create random number
            srand (time(NULL));
           ranNum = (rand()%(MAX - MIN + 1)) + MIN;
           //game function
            gameProcessor();
    } else if (gameMode == 2) {
            printf("\nPlease input the random number: ");
            scanf("%d",&ranNum);
            printf("\n");
            system("cls");
            gameProcessor();

    } else {
     printf("\nYou entered an unsupported game mode, please try again!\n\n");
    }
}
}
