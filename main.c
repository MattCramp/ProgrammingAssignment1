#include <stdio.h>
#include <string.h>

// FIRST PROCESS IS CORRECT AND GOOD TO GO
// SECOND PROCESS IS CORRECT AND GOOD TO GO
// THIRS PROCESS IS GOOD TO GO
// CODE NEEDS COMMENTS TO BE ADDED
// ARE SOME OF THE VARIABLES DECLARED IN INT MAIN UNNCESSARY AS THEY GET DECLARED IN FUCNTIONS??
// CAPITALS?
// FUCNTION 5 NOW WORKS


void RotationEncrypt(char *message, int key);
void RotationDecrypt(char *message, int key);
void SubstitutionEncrypt(char *message, char *encryptionKey);
void SubstitutionDecrypt(char *message, char *encryptionKey);
void RotationDecrypt_NO_Key(char *message, int key);


int main()
{

char message[100];


//char letter;
//char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'Y', 'Z'};
int key;
//int iteration;
int operation;
char encryptionKey[27];
int c;
int k;
 
printf("Enter text to be encrypted or decrypted: \n"); 
scanf("%[^\n]%*c",message); 

printf("Select operation to be completed\n"); 
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
                    SubstitutionEncrypt(message, encryptionKey);
                        break;
    
    case 4: 
                    SubstitutionDecrypt(message, encryptionKey);
                        break;
    
    case 5:         RotationDecrypt_NO_Key(message, key);
                        break;
    
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
                   
   

void SubstitutionEncrypt(char *message, char *encryptionKey) {
    int iteration = 0;
    printf("Enter Encryption Key: \n");
    scanf("%s", encryptionKey);
     
      
       for (iteration = 0; iteration < strlen(message); iteration++)
        {
            char letter = message[iteration];
            if (letter >= 'A' && letter <= 'Z')
                {
            
                letter = encryptionKey[letter - 'A'];
                }

                    message[iteration] = letter;
        }
                        printf("CipherText message: %s\n", message);
}

void SubstitutionDecrypt(char*message, char*encryptionKey) {
int iteration;
int iterationTwo = 0;
int letter;

printf("Enter a encryption key: \n");
scanf("%s", encryptionKey);

for (iteration = 0; message[iteration] != '0'; iteration++) {
    letter = message[iteration];
    if (letter >= 96 && letter <= 'z') {
        letter = letter - 32;
            }// end if loop
            if(letter >= 'A' && letter <= 'Z') {
                for (iterationTwo = 0; iterationTwo < 27; iterationTwo++) {
                    if(message[iteration] == encryptionKey[iterationTwo]) {
                        break;
                        
                    } // end if loop
                    
                }// end for loop
                message[iteration] = iterationTwo + 'A';
            }// end if loop
    
}// end for loop
   printf("PlainText message: %s\n", message);
   
} // End Function Void SubstitutionDecrypt


void RotationDecrypt_NO_Key(char *message, int key) {
 //printf("Enter ciphertext to decrypt: \n");
                    
                	int iteration;
                	char letter;
                	int count = 1;
                	char messageFull[100];
                	
                	for (count = 1; count <=26; count++)  {
                	  
                	    for(iteration = 0; message[iteration] != '\0'; ++iteration){
                		letter = message[iteration];
                		    key = 1;
                		
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
                		
                		key = key++;
                	}
                	
                	printf("Plaintext message: %s  Key Number:  %d\n", message, count); 
                	}// END OF FOR LOOP
                	
                	printf("Check the decoded text outputs. Find the output that is English plain text. Note the key number for the English plain text.\n");
                	printf("Enter the full message with correct key number into operation 2. The English plain text will be decoded.");
                	}// END OF FUNCTION
                	
                	
                
                	
             



