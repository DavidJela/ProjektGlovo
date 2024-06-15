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
    printf("                                                                                           @@@@@@@@@@@@@@@ \n");
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

//if (fgets(input2, sizeof(input2), stdin)) {
//    char* endptr;
//    long choice2 = strtol(input2, &endptr, 10);
//
//    // Ensure that endptr is at the end of the number and any remaining characters are whitespace
//    if (endptr != input2) {
//        while (isspace((unsigned char)endptr)) {
//            endptr++;
//        }
//        if (endptr == '\0' || endptr == '\n') {
//            // Clear input buffer if there is remaining content
//            while (endptr != '\n' && *endptr != '\0') {
//                endptr++;
//            }