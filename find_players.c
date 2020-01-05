//@Author: Oisin Wilson  
//GCC was used to compile this application using "gcc find_players.c -o find_players".
//To run type "./find_players" and press return.
 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Constants definitions
#define NUMBER_OF_PLAYERS 5
#define MAX_NUMBER_OF_ACHIEVEMENTS 4
#define NUMBER_OF_VALIDATE_ACHIEVEMENTS 14
#define BUFFER_SIZE 10

const char * RUN_TEST_USE_CASES = "TEST";

const char * VALIDATE_ACHIEVEMENTS [] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3",
					 "D1", "D2", "D3", "E", "F", "NG"};

// Data type player
typedef struct  {
    char * name;
    char * gamerTag;
    int points;
    char * achievements[MAX_NUMBER_OF_ACHIEVEMENTS]; 
} Player; 

// Load lobby with users function
void lobby(Player players[NUMBER_OF_PLAYERS]); 

// Validate the entered achievement function
bool validate_achievement(char * achievement); 

// Enters achievement from the console
bool enter_achievement(char * achievement);

// Converts strings to uppercase characters
void to_uppercase(char * achievement);

// Displays players who have particular achievement
void display_achievements(Player players[NUMBER_OF_PLAYERS], char * achievement);

// Is this a unit test execution run
bool is_unit_test(char * achievement);

// This function executes predefined unit tests which emulates user inputs
void execute_unit_test(Player players[NUMBER_OF_PLAYERS]);


// Application entry point 
int main() {
  Player players[NUMBER_OF_PLAYERS];
  char find_achievement[BUFFER_SIZE];   
  lobby(players);

  do {
    printf("\n\nEnter achievement [or 'TEST' to run unit tests or Ctrl+C to quit]:");
    if (enter_achievement(find_achievement)) {
      display_achievements(players, find_achievement);
    } else if (is_unit_test(find_achievement)) {
      execute_unit_test(players);
    } else {
      printf("Invalid Achievement:[A1,A2,B1,B2,B3,C1,C2,C3,D1,D2,D3,E,F,NG]\n");
    }
  } while (true);

  return 0;
}



// Lobby is a function which sets up all players and their achievements
void lobby(Player players[NUMBER_OF_PLAYERS])
{
   players[0].name = "Joe";
   players[0].gamerTag = "KillJoe";
   players[0].points = 100;
   players[0].achievements[0]="A1";
   players[0].achievements[1]="B1";
   players[0].achievements[2]="A2";
   players[0].achievements[3]="B3";
   players[1].name = "Jack";
   players[1].gamerTag = "KillJack";
   players[1].points = 100;
   players[1].achievements[0]="A1";
   players[1].achievements[1]="B2";
   players[1].achievements[2]="B3";
   players[1].achievements[3]="C1";
   players[2].name = "Jim";
   players[2].gamerTag = "KillJim";
   players[2].points = 85;
   players[2].achievements[0]="A1";
   players[2].achievements[1]="A2";
   players[2].achievements[2]="C1";
   players[2].achievements[3]="C2";
   players[3].name = "Jill";
   players[3].gamerTag = "KillJill";
   players[3].points = 75;
   players[3].achievements[0]="A2";
   players[3].achievements[1]="B1";
   players[3].achievements[2]="B3";
   players[3].achievements[3]="";
   players[4].name = "Bill";
   players[4].gamerTag = "KillBill";
   players[4].points = 100;
   players[4].achievements[0]="A1";
   players[4].achievements[1]="A2";
   players[4].achievements[2]="B1";
   players[4].achievements[3]="B2";
   return;
}



// This function accepts an entered achievement from the console
bool enter_achievement(char * achievement)
{
   fgets(achievement, BUFFER_SIZE, stdin);
   int new_line = strlen(achievement) -1;
   if (achievement[new_line] == '\n') {
      achievement[new_line] = '\0'; // Remove new line.
   }
   to_uppercase(achievement);
   fflush(stdin); // Flush stdin from any unusual entries.
    
   return validate_achievement(achievement);
}



// This function displays matching achievements of players
void display_achievements(Player players[NUMBER_OF_PLAYERS], char * achievement)
{
   for (int x=0; x< NUMBER_OF_PLAYERS; x++) {
     for (int y=0; y <  MAX_NUMBER_OF_ACHIEVEMENTS; y++) {
       if (strcmp(achievement, players[x].achievements[y]) == 0) {
	  printf("\nname='%s', gamerTag='%s', points='%d', achievements=",
		 players[x].name,
		 players[x].gamerTag,
		 players[x].points);
	  for (int z=0; z < MAX_NUMBER_OF_ACHIEVEMENTS; z++ ) {
	     printf("'%s'",players[x].achievements[z]);
	  }
          break; // Get out of the loop. 
       }
     }
   }   
}



// Is this a unit test execution run
bool is_unit_test(char * achievement)
{
   if (strcmp(RUN_TEST_USE_CASES, achievement) != 0) {
      return false;
   }

   return true;
}



// This function executes predefined unit tests which emulates user inputs
void execute_unit_test(Player players[NUMBER_OF_PLAYERS])
{
   printf("\n\nThe Execute Unit Test runs 13 different unit tests on 3 different parts of the code.");
   printf("\n\nStart execution of 6 unit tests which emulates valid user entries.");

   printf("\n\nWhen A2 is entered there will be 4 players returned\n");
   display_achievements(players, "A2");

   printf("\n\nWhen B1 is entered there will be 3 players returned\n");
   display_achievements(players, "B1");
   
   printf("\n\nWhen B2 is entered there will be 2 players returned\n");
   display_achievements(players, "B2");

   printf("\n\nWhen B3 is entered there will be 3 players returned\n");
   display_achievements(players, "B3");

   printf("\n\nWhen F is entered there will be 0 players returned\n");
   display_achievements(players, "F");

   printf("\n\nWhen A1 is entered there will be 4 players returned\n");
   display_achievements(players, "A1");

   printf("\n\nEnd execution of 6 unit tests which emulates valid user entries.");
   printf("\n\nStart execution of 2 unit tests which test the uppercase function.");

   char lowercase1[BUFFER_SIZE] = "abfgHi";
   printf("\n\nEmulate %s when passed as a parameter into to_uppercase returns ", lowercase1);
   to_uppercase(lowercase1);
   printf("%s\n", lowercase1);
   
   char lowercase2[BUFFER_SIZE] = "AB123iB";
   printf("\nEmulate %s when passed as a parameter into to_uppercase returns ", lowercase2);
   to_uppercase(lowercase2);
   printf("%s\n", lowercase2);
   
   printf("\nEnd execution of 2 unit tests which test the uppercase function."); 
   printf("\n\nStart execution of 5 unit tests which test the validate_achievement function.");

   printf("\n\nEmulate 'A1' when passed as a parameter into validate_achievement returns %s",
	  validate_achievement("A1") ? "true" : "false");
     
   printf("\n\nEmulate 'A2' when passed as a parameter into validate_achievement returns %s",
	  validate_achievement("A2") ? "true" : "false");

   printf("\n\nEmulate 'F' when passed as a parameter into validate_achievement returns %s",
	  validate_achievement("F") ? "true" : "false");

   printf("\n\nEmulate 'Z' when passed as a parameter into validate_achievement returns %s",
	  validate_achievement("Z") ? "true" : "false");

   printf("\n\nEmulate 'B1' when passed as a parameter into validate_achievement returns %s",
	  validate_achievement("B1") ? "true" : "false");

   printf("\n\nEnd execution of 5 unit tests which test the validate_achievement function.");
   printf("\n\nEnd Execute Unit Test runs 13 different unit tests on 3 different parts of the code.");
}



// This function converts all lowercase characters to uppercase
void to_uppercase(char * buffer)
{
   while (*buffer) {
      *buffer = toupper(*buffer);
      buffer++;
   }
}



// This function validates an entered string to make sure its valid to be used
bool validate_achievement(char * achievement)
{
   for (int x = 0; x < NUMBER_OF_VALIDATE_ACHIEVEMENTS; x++) {
     if (strcmp(VALIDATE_ACHIEVEMENTS[x], achievement) == 0) {
       return true;
     }
   }
   return false;
}
