#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void SinglePlayer(void);
void TwoPlayer(void);
void Manual(void);

int main() {


	int play_input;

    char charr;

	srand((unsigned int) time(NULL));


    printf("%14s","Welcome To Fekr o Bekr Game\n");

    printf("** Please Enter The 'Number' Of Your Intrested Item **\n\n\n");

    printf("Game Menu:\n");
    printf("1. Single Player Mode\n");
    printf("2. Two Player Mode\n");
    printf("3. Manual\n");
    printf("4. Exit\n");

	// get the user input

	scanf("%d", &play_input);



    switch (play_input)
    {
        case 1:
            SinglePlayer();

        case 2:
            TwoPlayer();

        case 3:
            Manual();
            charr = getchar();
            main();

        case 4:{

            printf("Hope We See You Later Bro!\n");
            return(0);
    }


}


}

void SinglePlayer(void){


    char turn_input [4];
    int checked_computer [4];
    int checked_player [4];
    char again [4];
    int repeat;
    int turn;
    int found = 0;
    char computer_choice [4];
    int correct_place;
    int correct_color;
    int color_print[4] = {0};
    int i;
    int j;


    do {

        // random initializing for single player mode

        for (i = 0; i < 4; i++) {
            int value = rand() % (6-1 + 1) + 1 ;
            if (value == 1) {
                computer_choice [i] = 'r';		// Red
            }
            else if (value == 2) {
                computer_choice [i] = 'o';		// Orange
            }
            else if (value == 3) {
                computer_choice [i] = 'y';		// Yellow
            }
            else if (value == 4) {
                computer_choice [i] = 'g';		// Green
            }
            else if (value == 5) {
                computer_choice [i] = 'b';		// Blue
            }
            else {
                computer_choice [i] = 'p';		// Purple
            }
        }

        // Reset number of turns
        turn = 1;

        printf("\nHere are your options: \n");
        printf("r (Red)\no (Orange)\ny (Yellow)\ng (Green)\nb (Blue)\np (Purple)\n\n");
        printf("Enter your guess as four lowercase characters.\n");

        // Begin turns

        do {

            // Reset correct
            correct_place = 0;
            correct_color = 0;

            // Reset checked arrays
            for (i = 0; i < 4; i++) {
                checked_computer [i] = 0;
                checked_player[i] = 0;

            }

            printf("Enter guess number %d: ", turn);
            scanf("%s", turn_input);
            printf("\n");

            // Check guess
            for (i = 0; i < 4; i++) {

                // If correct position, mark 1 in computer and player arrays
                if (computer_choice[i] == turn_input[i]) {
                    correct_place++;
                    checked_computer[i] = 1;
                    checked_player[i] = 1;
                    color_print[i] = 1;
                }
            }

            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {

                    // Check incorrect positions for color correctness
                    if (computer_choice[i] == turn_input[j] && !checked_computer[i] && !checked_player[j]) {
                        correct_color++;
                        checked_computer[i] = 1;
                        checked_player[j] = 1;
                        color_print[i] = 2;
                    }

                }
            }

            for(int y=0;y<4;y++){
                if(!checked_computer[y])
                    color_print[y]=0;
            }


            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

            for(int z=0 ; z<4 ; z++) {

                if (color_print[z]==0)
                    printf("\x1B[31m" "Ⓞ\t" "\x1B[0m");
                if(color_print[z]==1)
                    printf("\x1B[32m" "Ⓞ\t" "\x1B[0m");
                if(color_print[z]==2)
                    printf("Ⓞ\t" "\x1B[0m");
            }

            puts("");

            printf("Colors in the correct place: %d\n", correct_place);
            printf("Colors correct but in wrong position: %d\n\n\n", correct_color);




            turn++;

            // Check for win
            if (correct_place == 4) {
                printf("\x1B[31m" "\nCongrats! You win!\n\n" "\x1B[0m");
                found = 1;
            }
        } while (!found && turn <= 10);

        // If more than 10 turns, lose
        if (turn > 10) {
            printf("Sorry, you lost.\n");
            printf("The correct answer was ");
            for (i = 0; i < 4; i++) {
                printf("%c", computer_choice[i]);
            }
            printf("\n");
        }

        printf("Would you like to play again? (yes, no) ");
        scanf("%s", again);

        // If user wants to play again, set repeat flag to 1
        if (strcmp(again, "yes") == 0 || strcmp(again, "YES") == 0 || strcmp(again, "y") == 0) {

            repeat = 1;
        }

        if(strcmp(again, "no") == 0 || strcmp(again, "NO") == 0 || strcmp(again, "n"))  {
            repeat = 0;
        }
        printf("WTF Man?! This was a simple question and its answer is yes or no, not bullshit.");


    } while (repeat);
}

void TwoPlayer(void){

    char turn_input [7];
    int checked_computer [4];
    int checked_player [4];
    char again [4];
    int repeat;
    int turn;
    int found = 0;
    char firstplayerchoice [4];
    int correct_place;
    int correct_color;
    int color_print[4] = {0};
    int i;
    int j;


    do {


        puts("**WARNING** Right Now ,Just First Player Look At Screen ,PLease :)");
        printf("First Player Turn:\nPLease Enter Your Color Choices in Order (Example: ropy)  ");


        // first user input the colors in order to begin guessing by other one

        scanf("%s" , firstplayerchoice);





        // Reset number of turns

        turn = 1;

        puts("OK, Now Other Player Can Look :)");

        puts("Second Player Turn:");

        printf("\nHere are your options: \n");

        printf("Enter Your Guess Like This Example:\tropy");

        printf("*If you Forgot The Colors, Feel Free To Type 'colors' Instead Of Guess and Press Enter For Colors Manual");



        // Begin turns
        do {

            // Reset correct
            correct_place = 0;
            correct_color = 0;

            // Reset checked arrays
            for (i = 0; i < 4; i++) {
                checked_computer [i] = 0;
                checked_player [i] = 0;
            }

            printf("Enter guess number %d: ", turn);
            scanf("%s", turn_input);
            if(!strcmp(turn_input,"manual")) {
                Manual();
                scanf("%s", turn_input);
            }
            printf("\n");

            // Check guess
            for (i = 0; i < 4; i++) {

                // If correct position, mark 1 in computer and player arrays
                if (firstplayerchoice[i] == turn_input[i]) {
                    correct_place++;
                    checked_computer [i] = 0;
                    checked_player [i] = 0;
                    color_print[i] = 1;
                }
            }

            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {

                    // Check incorrect positions for color correctness
                    if (firstplayerchoice[i] == turn_input[j] && !checked_computer[i] && !checked_player[j]) {
                        correct_color++;
                        checked_computer[i] = 1;
                        checked_player[j] = 1;
                    }

                }
            }

            for(int y=0;y<4;y++){
                if(!checked_computer[y])
                    color_print[y]=0;
            }








            printf("Colors in the correct place: %d\n", correct_place);
            printf("Colors correct but in wrong position: %d\n", correct_color);


            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

            for(int z=0 ; z<4 ; z++) {

                if (color_print[z]==0)
                    printf("\x1B[31m" "Ⓞ\t" "\x1B[0m");
                if(color_print[z]==1)
                    printf("\x1B[32m" "Ⓞ\t" "\x1B[0m");
                if(color_print[z]==2)
                    printf("Ⓞ\t" "\x1B[0m");
            }

            puts("");

            turn++;

            // Check for win
            if (correct_place == 4) {
                printf("\x1B[31m" "\nCongrats! You win!\n\n" "\x1B[0m");
                found = 1;
            }
        } while (!found && turn <= 10);

        // If more than 10 turns, lose
        if (turn > 10) {
            printf("Sorry, you lost.\n");
            printf("The correct answer was ");
            for (i = 0; i < 4; i++) {
                printf("%c", firstplayerchoice[i]);
            }
            printf("\n");
        }

        printf("Would you like to play again? (yes, no) ");
        scanf("%s", again);

        // If user wants to play again, set repeat flag to 1
        if (strcmp(again, "yes") == 0 || strcmp(again, "YES") == 0 || strcmp(again, "y") == 0) {

            repeat = 1;
        }

        if(strcmp(again, "no") == 0 || strcmp(again, "NO") == 0 || strcmp(again, "n"))  {
            repeat = 0;
        }
        printf("WTF Man?! This was a simple question and its answer is yes or no, not bullshit.");


    } while (repeat);

}

void Manual(void){

    printf("\n\t\t\t\t\t\t\t\t\t"
                   "==========================="
                   "G A M E  M A N U A L"
                   "==========================="
                   "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t "
                   "Welcome To The Manual"
                   "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                   " Available Colors Are:"
                   "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                   " Red ==> r"
                   "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                   " Oragne ==> o"
                   "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                   " Blue ==> b"
                   "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                   " Green ==> g"
                   "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"
                   " Purple ==> p\n ");

}
