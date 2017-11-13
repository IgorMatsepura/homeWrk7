#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_NUMBER 1000       // Variable Max input Letters
#define FIRST_SMALL_LETTER 'a'  // First letter small in alphabet
#define FIRST_BIG_LETTER 'A'    // First letter big in alphabet
#define LETTERS_ALPHABET 26     // Number of letters in alphabet

void encryptLetters(char input[], int keyNumber);   //function code letter
void decryptLetters(char* input, int keyNumber);    // function decode letter

int main()
{
char inputWords[INPUT_NUMBER];
int enterNumb = 0;

    for (;;){
        memset(inputWords,0,sizeof(inputWords));
        printf("Input words...and input Number of code(decode)...: ");
        scanf("%s %d", inputWords, &enterNumb);
        // code letters in word
        encryptLetters(inputWords, enterNumb);
        // decode letters in word
        decryptLetters(inputWords, enterNumb);
    continue;
    }
}

 //function code letter
void encryptLetters(char input[], int keyNumber){
    int i = 0;

    for (i = 0; i < strlen(input); i++){
        if (islower(input[i])){
            input[i] = (input[i] - FIRST_SMALL_LETTER + keyNumber) %LETTERS_ALPHABET;
            input[i] = input[i] + FIRST_SMALL_LETTER;
        } else {
            input[i] = (input[i] - FIRST_BIG_LETTER + keyNumber) %LETTERS_ALPHABET;
            input[i] = input[i] + FIRST_BIG_LETTER;
        }
    }
    printf("new encrypt words is - ");
    for (i = 0; i < strlen(input); i++){
        printf("%c", input[i]);
    }
    printf("\n");
}

// function decode letter
void decryptLetters(char* input, int keyNumber){
  int i = 0;
  int countWordsAscii;

    for (i = 0; i < strlen(input); i++){
        if (islower(input[i])){
            countWordsAscii = int(input[i])-int(FIRST_SMALL_LETTER);
                input[i] = (input[i] - FIRST_SMALL_LETTER - keyNumber + LETTERS_ALPHABET ) %LETTERS_ALPHABET ;
                input[i] = input[i] + FIRST_SMALL_LETTER;
        } else {
            input[i] = (input[i] - FIRST_BIG_LETTER - keyNumber + LETTERS_ALPHABET) %LETTERS_ALPHABET;
            input[i] = input[i] + FIRST_BIG_LETTER;
        }
    }
    printf("new decode words is - ");
    for (i = 0; i < strlen(input); i++){
        printf("%c", input[i]);
    }
    printf("\n");
}
