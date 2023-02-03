#include"headers.h"

char *randomWord(const char *fileLocation)
{
    srand(time(NULL));
    static char randomWord[100];
    FILE *file = NULL;
    file = fopen(fileLocation, "r");
    if (file != NULL)
    {
        int lineNum[500] = {0};
        int i = 0;
        int j = 1;
        char curChar = 0;

        // MAKE INDEX "LINE_NUMBER"
        for ( i = 0; curChar != EOF; i++)
        {
            curChar = fgetc(file);
            if (curChar == '\n')
            {
                lineNum[j] = i+1;
                j++;
            }
        }
        j--;

        // RANDOM WORD FROM FILE BY INDEX
        fseek(file, lineNum[rand()%j], SEEK_SET);
        fgets(randomWord, 100, file);

        // CONVERT '\n' TO '\0'
        for (int i = 0; randomWord[i] != '\0'; i++)
        {
            if (randomWord[i] == '\n')
            {
                randomWord[i] = '\0';
            }
        }

        // CLOSE FILE
        fclose(file);
    }

    // CAN'T OPEN FILE !
    else
    {
        printf("\a\n<!> ERROR: CAN'T OPEN FILE! <!> \n");
        exit(1);
    }
    return randomWord;
}

int countChar(const char *word)
{
    int i=0;
    for (i = 0; word[i] != '\0'; i++);
    return i;
}

char * hide(int size)
{
    int i=0;
    char * hide = NULL;
    hide = (char*)malloc(size + 1);
    if (hide == NULL)
    {
    	printf("\a\n<!> ERROR WITH MEMORY! <!>\n");
        exit(1);
    }
    
    for (i = 0; i < size; i++)
    {
        hide[i] = '*';
    }
    hide[i] = '\0';
    return hide;
}

char inputChar(int index ,char *entered)
{
    char inputchar= 0;
    inputchar = getchar ();
    inputchar = toupper (inputchar);
    while (getchar() != '\n');
    entered[index]=inputchar;
    return inputchar;
}

void checkChar(const char *word, char *hiddenWord, int size, int *countTrue, int *hp, char inputChar)
{
    Bool tmp = False;
    for (int i = 0; i < size; i++)
    {
        if (inputChar == word[i])
        {
            // Check Char if it input again!
            if (inputChar == hiddenWord[i])
            {
                tmp = False;
                break;
            }
            // Check and replace the same Char
            else
            {
                hiddenWord[i] = word[i];
                *countTrue = *countTrue + 1;
                tmp = True;
            }
        }
    }
    // -1 HP if incorrect
    if (tmp == False)
    {
        *hp = *hp - 1;
    }
}

void printGame(char * hiddenWord, int hp, char *entered)
{
    printf("Ban con %d luot doan. ", hp);
    printf("(Cac tu da nhap: %s)\n\n", entered);
    printf("TU BI AN LA GI? %s\n", hiddenWord);
    printf("\nHay doan mot chu cai: ");
}

