#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

/* 
make sure User only feeds one key; that key is 26 characters long; that all characters are alphabetical
*/

    if (argc != 2)
        {
            printf("We need --one-- key with 26 unique alphabetic characters to proceed.\n");
            return(1);
        }

    if ((strlen(argv[1])) != 26)
        {
            printf("We need one key with --26-- unique alphabetic characters to proceed.\n");
            return(1);
        }

    for (int z = 0; z < 26; z++)
        {
            if (!isalpha(argv[1][z]))
            {
                printf("We need one key with 26 unique --alphabetic-- characters to proceed.\n");
                return(1);
            }
        }

/* 
make sure that every letter of the alphabet is included in the 26-digit key

abc[abcIndex] will cycle through all 26 of the key's values, seeking a match for "A"
if a match is identified, "matches" is incremented to count toward 26 and abcIndex is incremented to start looking for "B"
keyIndex is reset to -1 because the ++ in the "for" will bring it to 0, where we must begin
if every entity in abc (the whole alphabet, once) can be matched (26 matches) against argv[1], key is valid
*/

    string abc = "abcdefghijklmnopqrstuvwxyz";
    int matches = 0;
    int abcIndex = 0;

    for (int keyIndex = 0; keyIndex < 26; keyIndex++)
        {
            if (tolower(argv[1][keyIndex]) == abc[abcIndex])
                {
                    matches++;
                    abcIndex++;
                    keyIndex = -1;           
                }
        }

    if ((matches != 26))
                {
                    printf("We need one key with 26 --unique-- alphabetic characters to proceed.\n");
                    return(1);
                }
    
    string key = argv[1];
    string plaintext = get_string("plaintext: ");
    int cipherAlphabetLocation = 0;
    printf("ciphertext: ");

    for (int b = 0; b < strlen(plaintext); b++)
        {
            if (isupper(plaintext[b]))
                {
                    cipherAlphabetLocation = plaintext[b] - 65;
                    printf("%c", toupper(key[cipherAlphabetLocation]));
                }

            if (islower(plaintext[b]))
                {
                            cipherAlphabetLocation = plaintext[b] - 97;
                            printf("%c", tolower(key[cipherAlphabetLocation]));
                }
            
            if (!isalpha(plaintext[b]))
                {
                    printf("%c", plaintext[b]);
                }
        }
        printf("\n");
}
