#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encryptLetters(char input[], int keyNumber);
void decryptLetters(char* input, int keyNumber);

int main()
{
char inputWords[40];
int enterNumb = 0;

for (;;){
    printf("Input words...and input Number of code(decode)...: ");
    scanf("%s %d", inputWords, &enterNumb);

        // code letters in word
        encryptLetters(inputWords, enterNumb);
        // decode letters in word
        decryptLetters(inputWords, enterNumb);
    continue;
    }

}

void encryptLetters(char input[], int keyNumber){
    int i = 0;

    for (i = 0; i < strlen(input); i++){
        if (islower(input[i])){
            input[i] = (input[i] - 'a' + keyNumber) % 26;
            input[i] = input[i] + 'a';
        } else {
            input[i] = (input[i] - 'A' + keyNumber) % 26;
            input[i] = input[i] + 'A';
        }
    }
    printf("new encrypt words is - ");
    for (i = 0; i < strlen(input); i++){
        printf("%c", input[i]);
    }
    printf("\n");
}



void decryptLetters(char* input, int keyNumber){
  int i = 0;
  int countWordsAscii;

    for (i = 0; i < strlen(input); i++){
        if (islower(input[i])){
            countWordsAscii = int(input[i])-int('a');
            if (countWordsAscii >= keyNumber){
                input[i] = (input[i] - 'a' - keyNumber) % 26;
                input[i] = input[i] + 'a';
            } else {
                input[i] = abs((input[i] - 'a' - keyNumber)) % 26;
                input[i] = input[i] + 'a';
            }
        } else {
            input[i] = (input[i] - 'A' - keyNumber) % 26;
            input[i] = input[i] + 'A';
        }
    }
    printf("new decode words is - ");
    for (i = 0; i < strlen(input); i++){
        printf("%c", input[i]);
    }
    printf("\n");
}






