#include <stdio.h>


// this is the file for my assesment. dont mess with it. 

int main() {

char message[100];
char letter;
//char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z'};
int key;
int iteration;
int operation;
 
scanf("%[^\n]%*c",message);
 
printf("1. Encryption of a message with a rotation cipher given the message text and rotation amount\n");
printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");

scanf("%d", &operation);


printf("Read %d\n", operation);

switch (operation) {
    case 1: 
                    printf("Enter plaintext to be encypted: ");
                	//gets(message); // insert comment explaining gets.
                	printf("%s\n", message);
                	
                	printf("Enter key:\n ");
                	scanf("%d",&key);
                	printf("Read %d\n", key);
                	
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
                	
                	return 0;
                
                    break;
    
    case 2: 
                    printf("Enter ciphertext to decrypt: ");
                    printf("%s", message);
                	printf("Enter key: ");
                	scanf("%d", &key);
                	
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
                	
                	return 0;
                
                    break;
    
    case 3: // operation 3
    break;
    
    case 4: // operation 4
    break;
    
    default:
    printf("Please enter an integer between 1 and 4");
    break;
        
} // end switch case






 return 0;
} // end main