#include <stdio.h>
#include <string.h>

void RotationEncrypt(char *message, int key);
void RotationDecrypt(char *message, int key);
void SubstitutionEncrypt(char *message, char *encryptionKey);
void SubstitutionDecrypt(char *message, char *encryptionKey);
void RotationDecrypt_NO_Key(char *message, int key);

int main()
{

    char message[100];
    int key=0;
    int operation;
    char encryptionKey[27];

    printf("Enter text to be encrypted or decrypted: \n"); 
    scanf("%[^\n]", message);
    printf("Select operation to be completed: \n"); 
    printf("1. Encryption of a message with a rotation cipher given the message text and rotation amount. \n");
    printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount. \n");
    printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution. \n");
    printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions. \n");
    printf("5. Decryption of a message encrypted with a rotation cipher given cipher text only. \n");

    scanf("%d", &operation);
    printf("Read %d\n", operation);

        switch (operation) 
        {
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
    
            case 5:         
                    RotationDecrypt_NO_Key(message, key);
                        break;
    
            default:
                    printf("Please enter an integer between 1 and 5");
                        break;
        }

 return 0;
} 


void RotationEncrypt(char *message, int key) 
{
  
    printf("Enter key: (Key must be a number between -25 and 25)\n");
    scanf("%d",&key);
    printf("Read %d\n", key);
    int iteration;
    char letter;
    int rotation;
                	
        for(iteration = 0; message[iteration] != '\0'; iteration++)
        {
            letter = message[iteration];
                		
                if(letter >= '`' && letter <= 'z')
                {
                    letter = letter - 32;
                }
                        rotation = letter + key;
                		
                        if(rotation >'Z')
                        {
                            letter = rotation - 26;
                            
                		}
                			 
                            else if(rotation >= 'A' && rotation <= 'Z')
                            {
                                letter = rotation;
                            }
                			
                			    message[iteration] = letter;
       }
                                printf("Ciphertext message: %s", message);
}
                	


void RotationDecrypt(char *message, int key) 
{
    
    printf("Enter key: (Key must be a number between -25 and 25)\n");
    scanf("%d", &key);
    int iteration;
    char letter;
    int rotation;
                	
        for(iteration = 0; message[iteration] != '\0'; iteration++)
        {
            letter = message[iteration];
                		
                if(letter >= 'a' && letter <= 'z') // THIS CONVERTS LOWER-CASE LETTERS INTO UPPER-CASE.
                { 
                    letter = letter - 32;
                }
                    rotation = letter - key;
                		
                	    if(rotation >'Z')
                		{
                		    letter = rotation - 26;
                		}
                			 
                		    else if(rotation >= 'A' && rotation <= 'Z')
                		    {
                		        letter = rotation;
                		    }           
                			
                		            message[iteration] = letter;
        }
                			        printf("Ciphertext message: %s", message);
}
                	    
                	    
                	    
                	    
                	    /*
                	    
                	    for(iteration = 0; message[iteration] != '\0'; ++iteration){
                		letter = message[iteration];
                		
                		if(letter >= 97 && letter <= 122){
                			letter = letter - key;
                			
                			if(letter < 97){
                				letter = letter + 26;
                			}
                			
                			message[iteration] = letter - 32;
                		}
                			
                		
                			//else if(letter >= 65 && letter <= 90){
                		    else if(letter >= 65 && letter <= 90){
                			letter = letter - key;
                			
                			if(letter < 65){
                				letter = letter + 26;
                			}
                			
                			message[iteration] = letter;
                		}
                		
                		
                	}
                	
                	printf("Plaintext message: %s", message);
                	*/
                   //} // End Function Void RotationDecrypt
                   
   

void SubstitutionEncrypt(char *message, char *encryptionKey) 
{
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

void SubstitutionDecrypt(char*message, char*encryptionKey) 
{
    int iteration;
    int iterationTwo = 0;
    int letter;
    printf("Enter a encryption key: \n");
    scanf("%s", encryptionKey);

        for (iteration = 0; message[iteration] != '0'; iteration++) 
        {
            letter = message[iteration];
                if (letter >= 96 && letter <= 'z') 
                {
                    letter = letter - 32;
                }
                        if(letter >= 'A' && letter <= 'Z') 
                        {
                            for (iterationTwo = 0; iterationTwo < 27; iterationTwo++) 
                            {
                                if(message[iteration] == encryptionKey[iterationTwo]) 
                                {
                                    break;
                        
                                } 
                    
                            }
                                        message[iteration] = iterationTwo + 'A';
                        }
    
        }
                                        printf("PlainText message: %s\n", message);
   
} 


void RotationDecrypt_NO_Key(char *message, int key) 
{
    int iteration;
    char letter;
    int count = 1;
        for (count = 1; count <=26; count++)  
        {
            for(iteration = 0; message[iteration] != '\0'; ++iteration)
            {
                letter = message[iteration];
                key = 1;
                    if(letter >= 'A' && letter <= 'Z')
                    {
                        letter = letter - key;
                			
                		    if(letter < 'A')
                		    {
                				letter = letter + 'Z' - 'A' + 1;
                			}
                			
                			        message[iteration] = letter;
                	}
                	
                		                else if(letter >= 'a' && letter <= 'z')
                		                {
                			                letter = letter - key;
                			
                			                    if(letter < 'a')
                			                    {
                				                    letter = letter + 'z' - 'a' + 1;
                			                    }
                			
                			                            message[iteration] = letter;
                		                }
                		
                		                                    key = key++;
            }
                	
                	                    printf("Plaintext message: %s  Key Number:  %d\n", message, count); 
        }
                	
                	                    printf("Check the decoded text outputs. Find the output that is English plain text. Note the key number for the English plain text.\n");
                                        printf("Enter the full message with correct key number into operation 2. The CipherText text will be decoded.");
}
                	
                	
                
                	
             



