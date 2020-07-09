#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

typedef struct SONG
{
    char title;
    char artist;
    char album;
    char genre;
    char year;
    char duration;
}SONG;


/////////////////////////////////////                   FILE CHECK                 /////////////////////////////////
int FILE_CHECK_FUNCTION ()
{
    FILE *filepointer = fopen("DATABASE.txt", "r");       // Opening a FILE in READ  Mode.
    {
        {
            if(filepointer == NULL)                       // Checking if FILE EXISTS OR NOT.
            {
                printf("DATABASE DOESN'T EXIST.... Terminating The Program...!!!");
                exit(0);
            }
            else
            {                                                                                                      
                fclose(filepointer);
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////              CLear Console Screen           //////////////////////////////////
int CLEAR_SCREEN()
{
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////               MAIN MENU       //////////////////////////////////////////////
int MAIN_MENU_FUNCTION (int choice)
{
    {
        printf("          >> Welcome to MUSIC DATABASE. Please choose one of the following options:\n\n");
        printf("          1. Load the Existing Database\n");
        printf("          2. Create a New Database*\n");
        printf("          3. Exit                                                   ____________________________________________________________ \n");
        printf("                                                                   | * = Only Choose This Option If No Database Exists Already. |\n");
        printf("                                                                   |____________________________________________________________|\n");
    }

    {
        printf("\n         Answer: ");
        do
        {
            scanf("%d", &choice);
            if ((choice <= 3) && (choice >= 1))
            {
                return choice;
            }
            else
            {
                printf("         Wrong Choice, TRY AGAIN...!!!\n");
                printf("\n         Answer: ");
            }
        }while((choice >= 3) || (choice <= 1));
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////           DATABASE LOADING + SEARCHING MENU      /////////////////////////////
int MAIN_A_FUNCTION (int choice)
{

    {
        printf("\n\n");
        printf("              _____________________________________________\n");
        printf("             |               MUSIC DATABASE                |\n");
        printf("             |_____________________________________________|\n");
        printf("\n\n\n");
        printf("          >> Please choose one of the following options:\n\n");
        printf("          1. Search the Database\n");
        printf("          2. Add a New Entry to the Database\n");
        printf("          3. Show all of the Database\n");
        printf("          4. Return to Main Menu\n");
        printf("          5. Exit\n");
    }

    {
        printf("\n         Answer: ");
        do
        {
            scanf("%d", &choice);
            if ((choice <= 5) && (choice >= 1))
            {
                return choice;
            }
            else
            {
                printf("         Wrong Choice, TRY AGAIN...!!!\n");
                printf("\n         Answer: ");
            }
        }while((choice >= 5) || (choice <= 1));
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////              SONG  SEARCHING  MENU            ///////////////////////////////
int MAIN_A_1_FUNCTION (int choice)
{

    {
            printf("\n\n");
            printf("              _____________________________________________\n");
            printf("             |               MUSIC DATABASE                |\n");
            printf("             |_____________________________________________|\n");
            printf("\n\n\n");

        printf("          >> Please choose one of the following options:\n\n");
        printf("          1. Search by Song's Title\n");
        printf("          2. Search by Song's Artist\n");
        printf("          3. Search by Song's Album\n");
        printf("          4. Search by Song's Release Year\n");
        printf("          5. Search by Song's Genre\n");
        printf("          6. Return to Main Menu\n");
        printf("          7. Exit\n");
    }

    {
        printf("\n         Answer: ");
        do
        {
            scanf("%d", &choice);
            if ((choice <= 7) && (choice >= 1))
            {
                return choice;
            }
            else
            {
                printf("         Wrong Choice, TRY AGAIN...!!!\n");
                printf("\n         Answer: ");
            }
        }while((choice >= 7) || (choice <= 1));
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////              SONG  SEARCHING FUNCTION            /////////////////////////////
int MAIN_A_1_SEARCH_FUNCTION(int choice, int QUERY_CHECK)
{
    printf("\n\n\n");
    fflush(stdin);
    FILE *filepointer = fopen("DATABASE.txt", "r");       // Opening a FILE in READ.
        int QUERY_SIZE = 0;
        int linesize = 0;
        char *OUTPUT = NULL;
        char *line  =NULL;
        char *QUERY_ARRAY = NULL;
        char QUERY;
        char C;
        line = (char*)malloc(linesize*sizeof(char));
        QUERY_ARRAY = (char*)malloc(QUERY_SIZE*sizeof(char));
        QUERY_CHECK = 0;
    
    if(choice == 1)///////////////////////             SEARCH BY SONG TITLE               /////////////////////////////
    {
        fflush(stdin);
        printf("Enter the Song Title: ");
        while((scanf("%c",&QUERY) == 1) && (QUERY != '\n'))
        {
            QUERY = tolower(QUERY);
            QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
            QUERY_ARRAY[QUERY_SIZE] = QUERY;
            QUERY_SIZE++;
        }
        QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
        QUERY_ARRAY[QUERY_SIZE] = '\0';
        printf("\n\n\n SEARCHING.....");
        while((fscanf(filepointer,"%c", &C)) != EOF)
        {
            if(C != '\n')
            {
                line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = C;
                linesize++;
			}
			else if(C == '\n')
			{
				line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = '\0';
                if(strstr(line,QUERY_ARRAY) != NULL)
				{
					printf("\n                  %s\n", line);
                    QUERY_CHECK = 1;
				}
                free(line);
                linesize = 0;
                line = (char*)malloc(linesize*sizeof(char));
			}
        }
        free(line);
        free(QUERY_ARRAY);
    }
    
    else if(choice == 2)//////////////////             SEARCH BY SONG ARTIST              /////////////////////////////
    {
        fflush(stdin);
        printf("Enter the Song Artist: ");
        while((scanf("%c",&QUERY) == 1) && (QUERY != '\n'))
        {
            QUERY = tolower(QUERY);
            QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
            QUERY_ARRAY[QUERY_SIZE] = QUERY;
            QUERY_SIZE++;
        }
        QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
        QUERY_ARRAY[QUERY_SIZE] = '\0';
        printf("\n\n\n SEARCHING.....");
        while((fscanf(filepointer,"%c", &C)) != EOF)
        {
            if(C != '\n')
            {
                line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = C;
                linesize++;
			}
			else if(C == '\n')
			{
				line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = '\0';
                if(strstr(line,QUERY_ARRAY) != NULL)
				{
					printf("\n                  %s\n", line);
                    QUERY_CHECK = 1;
				}
                free(line);
                linesize = 0;
                line = (char*)malloc(linesize*sizeof(char));
			}
        }
        free(line);
        free(QUERY_ARRAY);
    }
    else if(choice == 3)//////////////////             SEARCH BY SONG ALBUM               /////////////////////////////
    {
        fflush(stdin);
        printf("Enter the Song Album: ");
        while((scanf("%c",&QUERY) == 1) && (QUERY != '\n'))
        {
            QUERY = tolower(QUERY);
            QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
            QUERY_ARRAY[QUERY_SIZE] = QUERY;
            QUERY_SIZE++;
        }
        QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
        QUERY_ARRAY[QUERY_SIZE] = '\0';
        printf("\n\n\n SEARCHING.....");
        while((fscanf(filepointer,"%c", &C)) != EOF)
        {
            if(C != '\n')
            {
                line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = C;
                linesize++;
			}
			else if(C == '\n')
			{
				line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = '\0';
                if(strstr(line,QUERY_ARRAY) != NULL)
				{
					printf("\n                  %s\n", line);
                    QUERY_CHECK = 1;
				}
                free(line);
                linesize = 0;
                line = (char*)malloc(linesize*sizeof(char));
			}
        }
        free(line);
        free(QUERY_ARRAY);
    }
    else if(choice == 4)//////////////////             SEARCH BY SONG RELEASE YEAR        /////////////////////////////
    {
        fflush(stdin);
        printf("Enter the Song Release Year: ");
        while((scanf("%c",&QUERY) == 1) && (QUERY != '\n'))
        {
            QUERY = tolower(QUERY);
            QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
            QUERY_ARRAY[QUERY_SIZE] = QUERY;
            QUERY_SIZE++;
        }
        QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
        QUERY_ARRAY[QUERY_SIZE] = '\0';
        printf("\n\n\n SEARCHING.....");
        while((fscanf(filepointer,"%c", &C)) != EOF)
        {
            if(C != '\n')
            {
                line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = C;
                linesize++;
			}
			else if(C == '\n')
			{
				line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = '\0';
                if(strstr(line,QUERY_ARRAY) != NULL)
				{
					printf("\n                  %s\n", line);
                    QUERY_CHECK = 1;
				}
                free(line);
                linesize = 0;
                line = (char*)malloc(linesize*sizeof(char));
			}
        }
        free(line);
        free(QUERY_ARRAY);
    }
    else if(choice == 5)//////////////////             SEARCH BY SONG GENRE               /////////////////////////////
    {
        fflush(stdin);
        printf("Enter the Song Genre: ");
        while((scanf("%c",&QUERY) == 1) && (QUERY != '\n'))
        {
            QUERY = tolower(QUERY);
            QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
            QUERY_ARRAY[QUERY_SIZE] = QUERY;
            QUERY_SIZE++;
        }
        QUERY_ARRAY = (char*)realloc(QUERY_ARRAY,(QUERY_SIZE+1)*sizeof(char));
        QUERY_ARRAY[QUERY_SIZE] = '\0';
        printf("\n\n\n SEARCHING.....");
        while((fscanf(filepointer,"%c", &C)) != EOF)
        {
            if(C != '\n')
            {
                line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = C;
                linesize++;
			}
			else if(C == '\n')
			{
				line = (char*)realloc(line,(linesize+1)*sizeof(char));
                line[linesize] = '\0';
                if(strstr(line,QUERY_ARRAY) != NULL)
				{
					printf("\n                  %s\n", line);
                    QUERY_CHECK = 1;
				}
                free(line);
                linesize = 0;
                line = (char*)malloc(linesize*sizeof(char));
			}
        }
        free(line);
        free(QUERY_ARRAY);
    }
    
    fclose(filepointer);
    return QUERY_CHECK;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////                NEW ENTRY  MENU + INPUT              /////////////////////////
int MAIN_A_2_FUNCTION (int choice)
{
    SONG C;

    FILE *filepointer = fopen("DATABASE.txt", "a+");       // Opening a FILE in READ + APPEND Mode.
    {
        if(filepointer == NULL)                       // Checking if FILE EXISTS OR NOT.
        {
            printf("DATABASE DOESN'T EXIST.");
        }
        else
        {
            printf("\n\n"); 
            char c;
            {////////////////////////////////////////////////
                while ((c = getchar()) != '\n')/////////////         
                {//////////////////////////////////////////
                    c = tolower(c);///////////////////////                            
                    putc(c, filepointer);////////////////                       
                }///////////////////////////////////////
            }//////////////////////////////////////////
            printf("          Enter the Song's Title: ");
            {
                fprintf(filepointer,"%s", "Title: ");
                while ((C.title = getchar()) != '\n')          
                {
                    C.title = tolower(C.title);                            
                    putc(C.title, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Artist: ");
            {
                fprintf(filepointer,"%s", "Artist: ");
                while ((C.artist = getchar()) != '\n')          
                {
                    C.artist = tolower(C.artist);                            
                    putc(C.artist, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Album: ");
            {
                fprintf(filepointer,"%s", "Album: ");
                while ((C.album = getchar()) != '\n')          
                {
                    C.album = tolower(C.album);                            
                    putc(C.album, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Release Year: ");
            {
                fprintf(filepointer,"%s", "Release Year: ");
                while ((C.year = getchar()) != '\n')          
                {
                    C.year = tolower(C.year);                            
                    putc(C.year, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Genre: ");
            {
                fprintf(filepointer,"%s", "Genre: ");
                while ((C.genre = getchar()) != '\n')          
                {
                    C.genre = tolower(C.genre);                            
                    putc(C.genre, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Duration: ");        
            {
                fprintf(filepointer,"%s", "Duration: ");
                while ((C.duration = getchar()) != '\n')          
                {
                    C.duration = tolower(C.duration);                            
                    putc(C.duration, filepointer);                            
                }
                putc('|', filepointer);
            }  
            putc('\n', filepointer);                                                                                                       


            fclose(filepointer);
            choice = 1;
            return choice;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////                PRINT THE DATABASE              ///////////////////////////////
int MAIN_A_3_FUNCTION (int choice)
{
    
    FILE *filepointer = fopen("DATABASE.txt", "r");       // Opening a FILE in READ.
    {
        if(filepointer == NULL)                        // Checking if FILE EXISTS OR NOT.
        {
            printf("DATABASE DOESN'T EXIST.");
        }
        else
        {
            printf("\n\n");
            printf("              _____________________________________________\n");
            printf("             |               MUSIC DATABASE                |\n");
            printf("             |_____________________________________________|\n");
            printf("\n\n\n");
            char C;
            while ((C = getc(filepointer)) != EOF)           //     PRINTING
            {
                if(C == '|')
                {
                    printf("     ");
                }
                else if(C == '\n')
                {
                    printf("\n\n");
                }
                else 
                {
                    printf("%c", C);
                }
                                            //    A FILE
                                             //   TILL THE END.
            }
        }
    }
    fclose(filepointer);

            printf("\n\n\n\n          Do wish to return to Main Menu?   [Y/N]: ");
            char EXIT_CHOICE;
            scanf(" %c", &EXIT_CHOICE);
            if (EXIT_CHOICE == 'y' || EXIT_CHOICE == 'Y')
            {
                choice = 1;
                return choice;
            }
            else if (EXIT_CHOICE == 'N' || EXIT_CHOICE == 'n')
            {
                printf("\n\n          Terminating the program...\n");
                exit;
            }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////               CREATE A NEW DATABASE              /////////////////////////////
int MAIN_B_FUNCTION (int choice)
{
    SONG C;                                              
    FILE *filepointer = fopen("DATABASE.txt", "r");     ///////////////////////////////////////////////////////////
    {                                                  // Checking if FILE EXISTS OR NOT.      ///////////////////
        if(filepointer != NULL)                       // we won't create a new one if one already exists. ///////
        {                                            // It can create 2 conflicts files & we would like  ///////
            printf("\n\n\n\n");                     // to keep all the Song information in one file only.//////
            printf("    DATABASE ALREADY EXISTS.");///////////////////////////////////////////////////////////
            printf("\n\n\n");
            printf("\n               //////////////////////////////////////////////////////////////////////////");
            printf("\n              ////////// we won't create a new database if one already exists. /////////");
            printf("\n             //////////           it can create 2 conflicting files.          /////////");
            printf("\n            //////////////////////////////////////////////////////////////////////////");
            fclose(filepointer);
            printf("\n\n\n\n          Do wish to return to Main Menu?   [Y/N]: ");
            char EXIT_CHOICE;
            scanf(" %c", &EXIT_CHOICE);
            if (EXIT_CHOICE == 'y' || EXIT_CHOICE == 'Y')
            {
                choice = 1;
                return choice;
            }
            else if (EXIT_CHOICE == 'N' || EXIT_CHOICE == 'n')
            {
                printf("\n\n          Terminating the program...\n");
                exit;
            }
        }                                          
        else
        {
            FILE *filepointer = fopen("DATABASE.txt", "a+");
            printf("\n\n"); 
            char c;
            {////////////////////////////////////////////////
                while ((c = getchar()) != '\n')/////////////         
                {//////////////////////////////////////////
                    c = tolower(c);///////////////////////                            
                    putc(c, filepointer);////////////////                       
                }///////////////////////////////////////
            }//////////////////////////////////////////
            printf("          Enter the Song's Title: ");
            {
                while ((C.title = getchar()) != '\n')          
                {
                    C.title = tolower(C.title);                            
                    putc(C.title, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Artist: ");
            {
                while ((C.artist = getchar()) != '\n')          
                {
                    C.artist = tolower(C.artist);                            
                    putc(C.artist, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Album: ");
            {
                while ((C.album = getchar()) != '\n')          
                {
                    C.album = tolower(C.album);                            
                    putc(C.album, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Release Year: ");
            {
                while ((C.year = getchar()) != '\n')          
                {
                    C.year = tolower(C.year);                            
                    putc(C.year, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Genre: ");
            {
                while ((C.genre = getchar()) != '\n')          
                {
                    C.genre = tolower(C.genre);                            
                    putc(C.genre, filepointer);                            
                }
                putc('|', filepointer);
            }
            printf("          Enter the Song's Duration: ");        
            {
                while ((C.duration = getchar()) != '\n')          
                {
                    C.duration = tolower(C.duration);                            
                    putc(C.duration, filepointer);                            
                }
                putc('|', filepointer);
            }  
            putc('\n', filepointer);                                                                                                       
            fclose(filepointer);
            printf("\n\n\n\n          Do wish to return to Main Menu?   [Y/N]: ");
            char EXIT_CHOICE;
            scanf(" %c", &EXIT_CHOICE);
            if (EXIT_CHOICE == 'y' || EXIT_CHOICE == 'Y')
            {
                choice = 1;
                return choice;
            }
            else if (EXIT_CHOICE == 'N' || EXIT_CHOICE == 'n')
            {
                printf("\n\n          Terminating the program...\n");
                exit;
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
