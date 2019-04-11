#include <stdio.h>

// this is the file for my assesment. dont mess with it. 

int main() {

 char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z'};
 char message[100];
 int key;
 int operation;
 
 scanf("%s", message)
 
printf("1. Encryption of a message with a rotation cipher given the message text and rotation amount\n");
printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");

scanf("d", &operation);

printf("Read %d\n", operation);

switch (operation) {
    case 1: // operation 1
    break;
    
    case 2: // operation 2
    break;
    
    case 3: // operation 3
    break;
    
    case 4: // operation 4
    break
    
    
} // end switch case






 return 0;
} // end main
