#include"headers.h"

int main(int argc, char const *argv[])
{
    system("clear");

    // Print Banner
    printf("\t<==================================>\n");
    printf("\t ||                              ||\n");
    printf("\t ||      WORD GUESSING GAME      ||\n");
    printf("\t ||                              ||\n");
    printf("\t<==================================>\n");
    printf("\n\n");

    char * word = randomWord("/home/nltt/Documents/C/GuessWord/folder/words");
    
    // Show the word for... when you want fix some stuff~
		printf("\n\nWord: %s\n\n", word);
    // ^~~ Remember hide it when you play game!!!
    
    int size = countChar(word);     // you can use strlen() !
    char * hiddenWord = hide(size);
    int countTrue = 0;
    int hp = 10;
    int index=0;
    char entered[50];

    // Get from PLAYER and Check and Return!
    while (countTrue != size)
    {
        printGame(hiddenWord, hp, entered);
        checkChar(word, hiddenWord, size, &countTrue, &hp, inputChar(index, entered));
        system("clear");
        if (hp == 0)
        {
            // YOU LOSE !!!
            printf("\a\nTU BI MAT LA: %s\n", word);
            printf("\a\nGAME OVER!!!\n");
            exit(0);
        }
        index++;
    }
    
    // If you WINNNN !!!
    printf("\a\n\n***********************!!! XIN CHUC MUNG !!!***********************\n=> TU BI MAT LA:  %s\n\n*******************************************************************\n\n\n", word);

    // free the variable! DON'T FORGET !!
    free(hiddenWord);

    return 0;
}
// END.
