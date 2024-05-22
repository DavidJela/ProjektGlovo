#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>


int main(void) {

	srand((unsigned)time(NULL));

	int choice = 1;

	createFile("data.bin");


	while (choice) {
		choice = mainMenu("data.bin");
	}
    //OVO MI JE FRAN BASIC POMOGAO SA PRVE GODINE <3
	printf("Thank you for using glovo calculator!\n");
    printf("\033[0;33m");
    printf("                                                                                               @@@@@@@     \n");
    printf("                                                                                            @@@@@@@@@@@@@  \n");
    printf("               OVAJ LOGO MI JE POMOGAO FRAN BASIC   <3                                     @@@@@@@@@@@@@@@ \n");
    printf("                                                                                          @@@@@@     @@@@@@\n");
    printf("                                                                                          @@@@@       @@@@@\n");
    printf("        @@@@@@@@@@         @@@                                                            @@@@@       @@@@@\n");
    printf("      @@@@@@@@@@@@@@      @@@@@                                                            @@@@@     @@@@@ \n");
    printf("   @@@@@@@@@@@@@@@@@@@    @@@@@                                                             @@@@@   @@@@@  \n");
    printf("  @@@@@@@        @@@@@    @@@@@                                                               @@@@@@@@@@   \n");
    printf(" @@@@@@                   @@@@@       @@@@@@@@@@@   @@@@@           @@@@@    @@@@@@@@@@@       @@@@@@@@    \n");
    printf("@@@@@@                    @@@@@    @@@@@@@@@@@@@@@@  @@@@@         @@@@@  @@@@@@@@@@@@@@@@      @@@@@@     \n");
    printf("@@@@@       @@@@@@@@@@    @@@@@   @@@@@@      @@@@@@  @@@@@       @@@@@  @@@@@@      @@@@@@      @@@@      \n");
    printf("@@@@@       @@@@@@@@@@@   @@@@@  @@@@@@         @@@@@  @@@@@     @@@@@  @@@@@@         @@@@@     @@@@      \n");
    printf("@@@@@@       @@@@@@@@@@   @@@@@  @@@@@          @@@@@   @@@@@   @@@@@   @@@@@          @@@@@     @@@@      \n");
    printf(" @@@@@@           @@@@@   @@@@@  @@@@@          @@@@@    @@@@@ @@@@@    @@@@@          @@@@@               \n");
    printf(" @@@@@@@          @@@@@   @@@@@   @@@@@        @@@@@      @@@@@@@@@      @@@@@        @@@@@      @@@@      \n");
    printf("   @@@@@@@@@@@@@@@@@@@@   @@@@@    @@@@@@@@@@@@@@@@@       @@@@@@@        @@@@@@@@@@@@@@@@@     @@@@@@     \n");
    printf("     @@@@@@@@@@@@@@@@@    @@@@@     @@@@@@@@@@@@@@          @@@@@          @@@@@@@@@@@@@@       @@@@@@     \n");
    printf("        @@@@@@@@@          @@@         @@@@@@@@              @@@              @@@@@@@@@          @@@@      \n");
    printf("\033[0m");
	return 0;
}