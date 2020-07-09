#include "functions_header_file.h"
/*                                                       Songs

    Create a program to store data of songs in a database. 
    For each entry the program should store the following data: title of the song, name of the performer (singer or group), title of the album it was released on, year of release, genre of the music (rock, pop, hip-hop, jazz, classical, etc.), length of song (in minutes and seconds). The program should be able to:

    load existing database into memory (create a new if there is no database yet),
    add new song entry to the database,
    save the database (from the memory) into a file,
    display all songs of a user selected artist (the user may enter the artist, for example “Lady Gaga”),
    display all details of the songs of a user selected album (the user may enter the name of the artist and the title of the album),
    list all songs that were released in a user selected year,
    list all songs (title, performer, album, release year) of a user selected genre (for example: list all hip-hop songs).

*/

int main()
{
START:
    printf("\n\n");
    printf("              _____________________________________________\n");
    printf("             |               MUSIC DATABASE                |\n");
    printf("             |_____________________________________________|\n");
    printf("\n\n\n");

    int choice = MAIN_MENU_FUNCTION(choice); /////      Returns the choice made my user for the Main Menu     ////////////

    if (choice == 1) //////////////////////////////////// User Selected: Load the Existing Database ////////////////////////
    {
        CLEAR_SCREEN();
        FILE_CHECK_FUNCTION();
        int menu_a = MAIN_A_FUNCTION(choice);

        if (menu_a == 1) //////////////////// User Selected: Search for a Song ///////////////////////
        {
            CLEAR_SCREEN();
            int menu_a_1 = MAIN_A_1_FUNCTION(choice);

            if (menu_a_1 == 6) /////User Selected: Return to Main Menu////
            {
                CLEAR_SCREEN();
                goto START;
            }

            if (menu_a_1 == 7) /////User Selected: Exit////
            {
                printf("\n\n          Terminating the program...\n");
                exit;
            }

            else
            {
                int QUERY_CHECK = MAIN_A_1_SEARCH_FUNCTION(menu_a_1, QUERY_CHECK);
                if (QUERY_CHECK == 0)
                {
                    printf("\n\nQuery wasn't found in the Music Database.");
                    printf("\n\n\n\n          Do wish to return to Main Menu?   [Y/N]: ");
                    char EXIT_CHOICE;
                    scanf(" %c", &EXIT_CHOICE);
                    if (EXIT_CHOICE == 'y' || EXIT_CHOICE == 'Y')
                    {
                        CLEAR_SCREEN();
                        goto START;
                    }
                    else if (EXIT_CHOICE == 'N' || EXIT_CHOICE == 'n')
                    {
                        printf("\n\n          Terminating the program...\n");
                        exit;
                    }
                }
                else if (QUERY_CHECK != 0)
                {
                    printf("\n\n\n\n          Do wish to return to Main Menu?   [Y/N]: ");
                    char EXIT_CHOICE;
                    scanf(" %c", &EXIT_CHOICE);
                    if (EXIT_CHOICE == 'y' || EXIT_CHOICE == 'Y')
                    {
                        CLEAR_SCREEN();
                        goto START;
                    }
                    else if (EXIT_CHOICE == 'N' || EXIT_CHOICE == 'n')
                    {
                        printf("\n\n          Terminating the program...\n");
                        exit;
                    }
                }
            }
        }

        if (menu_a == 2) //////////////////// User Selected: Add a New Entry  //////////////////////
        {
            CLEAR_SCREEN();
            int menu_a_2 = MAIN_A_2_FUNCTION(choice);

            if (choice != 0)
            {
                printf("\n\n\n\n          Do wish to return to Main Menu?   [Y/N]: ");
                char EXIT_CHOICE;
                scanf(" %c", &EXIT_CHOICE);
                if (EXIT_CHOICE == 'y' || EXIT_CHOICE == 'Y')
                {
                    CLEAR_SCREEN();
                    goto START;
                }
                else if (EXIT_CHOICE == 'N' || EXIT_CHOICE == 'n')
                {
                    printf("\n\n          Terminating the program...\n");
                    exit;
                }
            }

            if (menu_a_2 == 7) /////User Selected: Exit////
            {
                printf("\n\n          Terminating the program...\n");
                exit;
            }
        }

        if (menu_a == 3) ////////////////////   User Selected: Print all the DATABASE     //////////
        {
            CLEAR_SCREEN();
            choice = MAIN_A_3_FUNCTION(choice);
            if (choice == 1)
            {
                CLEAR_SCREEN();
                goto START;
            }
        }

        if (menu_a == 4) ////////////////////   User Selected: Return to MAIN MENU     ////////
        {
            CLEAR_SCREEN();
            goto START;
        }

        if (menu_a == 5) ////////////////////   User Selected: Exit     ////////////////////////
        {
            printf("\n\n          Terminating the program...\n");
            exit;
        }
    }

    else if (choice == 2) //////////////////////////////////// User Selected: Create a New Database //////////////////////
    {
        choice = MAIN_B_FUNCTION(choice);
        if (choice == 1)
        {
            CLEAR_SCREEN();
            goto START;
        }
    }

    else if (choice == 3) //////////////////////////////////// User Selected: Exit /////////////////////////////////////
    {
        printf("\n\n          Terminating the program...\n");
        exit;
    }

    return 0;
}
