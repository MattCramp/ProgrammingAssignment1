#include <stdio.h>
#include <string.h>

// FIRST PROCESS IS CORRECT AND GOOD TO GO
// SECOND PROCESS IS CORRECT AND GOOD TO GO
// CODE NEEDS COMMENTS TO BE ADDED
// ARE SOME OF THE VARIABLES DECLARED IN INT MAIN UNNCESSARY AS THEY GET DECLARED IN FUCNTIONS??
// CAPITALS?

void RotationEncrypt(char *message, int key);
void RotationDecrypt(char *message, int key);
void SubstitutionEncrypt(char *message, char *key);
//void SubstitutionDecrypt(char *message, char *k;
//void RotationDecryptNoKey;

int main() {

char message[100];
//char letter;
//char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z'};
int key;
//int iteration;
int operation;
 
scanf("%[^\n]%*c",message);
 
printf("1. Encryption of a message with a rotation cipher given the message text and rotation amount\n");
printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");
printf("5. Decryption of a message encrypted with a rotation cipher given cipher text only \n");

scanf("%d", &operation);

printf("Read %d\n", operation);

switch (operation) {
    case 1: 
                   RotationEncrypt(message, key);
                   break;
    
    case 2: 
                    RotationDecrypt(message, key);
                    break;
    
    case 3:
                    SubstitutionEncrypt(message, key);
    break;
    
    //case 4: // operation 4
    break;
    
    //case 4: // operation 5
    
    default:
    printf("Please enter an integer between 1 and 5");
    break;
        
} // end switch case

 return 0;
} // end main


void RotationEncrypt(char *message, int key) {
    printf("Enter plaintext to be encypted: ");
                	printf("%s\n", message);
                	printf("Enter key:\n ");
                	scanf("%d",&key);
                	printf("Read %d\n", key);
                	int iteration;
                	char letter;
                	
                	for(iteration = 0; message[iteration] != '\0'; ++iteration){
                		letter = message[iteration];
                		
                		if(letter >= 'A' && letter <= 'Z'){
                			letter = letter + key;
                			
                			if(letter > 'Z'){
                				letter = letter - 'Z' + 'A' - 1;
                			}
                			
                			message[iteration] = letter;
                		}
                		
                		
                		 else if(letter >= 'a' && letter <= 'z'){
                			letter = letter + key;
                			
                			if(letter > 'z'){
                				letter = letter - 'z' + 'a' - 1;
                			}
                			
                			message[iteration] = letter;
                			
                			}
                			
                			}
                	
                	
                	printf("Ciphertext message: %s", message);
                	
                                
           
} // End Function Void RotationEncrypt

void RotationDecrypt(char *message, int key) {
    printf("Enter ciphertext to decrypt: \n");
                    printf("%s\n", message);
                	printf("Enter key: \n");
                	scanf("%d", &key);
                	int iteration;
                	char letter;
                	
                	    for(iteration = 0; message[iteration] != '\0'; ++iteration){
                		letter = message[iteration];
                		
                		
                			if(letter >= 'A' && letter <= 'Z'){
                			letter = letter - key;
                			
                			if(letter < 'A'){
                				letter = letter + 'Z' - 'A' + 1;
                			}
                			
                			message[iteration] = letter;
                		}
                		
                		
                		else if(letter >= 'a' && letter <= 'z'){
                			letter = letter - key;
                			
                			if(letter < 'a'){
                				letter = letter + 'z' - 'a' + 1;
                			}
                			
                			message[iteration] = letter;
                		}
                		
                		
                	}
                	
                	printf("Plaintext message: %s", message);
                	
                   } // End Function Void RotationDecrypt
                   
void SubstitutionEncrypt(char *message, char *key) {
printf("Enter ciphertext to decrypt: \n");
printf("%s\n", message);
int iteration;
char letter;
    
}// End Function Void SubstitutionEncrypt


