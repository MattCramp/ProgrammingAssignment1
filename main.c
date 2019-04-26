#include <stdio.h>
#include <string.h> // <string.h> header allows access to string.h library.

void RotationEncrypt(char *message, int key); //Function prototype for operation 1.
void RotationDecrypt(char *message, int key); //Function prototype for operation 2.
void SubstitutionEncrypt(char *message, char *encryptionKey); // Function prototype for operation 3.
void SubstitutionDecrypt(char *message, char *encryptionKey); // Function prototype for operation 4.
void RotationDecrypt_NO_Key(char *message, int key); // Function prototype for operation 5. 

int main()
{

    char message[100]; // Array of type char to store ciphertext/plaintext message. 
    int key=0; // Declare a variable of type int to store key rotation number for operation 1 and operation 2.
    int operation; // Declare a variable of type int to allow user to choose what operation to complete. 
    char encryptionKey[27]; // Array of type char to store encryption key for operation 3 and operation 4. 
    printf("Enter text to be encrypted or decrypted: \n"); 
    scanf("%[^\n]", message); // Scans input plaintext or ciphertext. Ignores spaces and will read all text until end of line.
    printf("Select operation to be completed: \n"); // Allows user to declare which operation to complete. 
    printf("1. Encryption of a message with a rotation cipher given the message text and rotation amount. \n"); // Option 1 description. 
    printf("2. Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount. \n"); // Option 2 description.
    printf("3. Encryption of a message with a substitution cipher given message text and alphabet substitution. \n"); // Option 3 descritpion.
    printf("4. Decryption of a message encrypted with a substitution cipher given cipher text and substitutions. \n"); // Option 4 descritpion.
    printf("5. Decryption of a message encrypted with a rotation cipher given cipher text only. \n"); // Option 5 descritpion. 

    scanf("%d", &operation); // Reads user input to indicate which option shall be completed. 
    printf("Read %d\n", operation); // Informs user via stdio standard out of operation they have selected. 

        switch (operation) // Switch (operation) takes user input from scanf statement above and begins to execute a function/operation. 
        {
            case 1: 
                   RotationEncrypt(message, key); // Function for option 1. This executes the function body found below main. 
                        break; // Once function has been executed, break will 'jump-out' of the switch statement. This prevents other functions from being executed.
    
            case 2: 
                    RotationDecrypt(message, key); // Function for option 2. This executes the function body found below main. 
                        break; // Once function has been executed, break will 'jump-out' of the switch statement. This prevents other functions from being executed.
    
            case 3:
                    SubstitutionEncrypt(message, encryptionKey); // Function for option 3. This executes the function body found below main. 
                        break; // Once function has been executed, break will 'jump-out' of the switch statement. This prevents other functions from being executed.
    
            case 4: 
                    SubstitutionDecrypt(message, encryptionKey); // Function for option 4. This executes the function body found below main. 
                        break; // Once function has been executed, break will 'jump-out' of the switch statement. This prevents other functions from being executed.
    
            case 5:         
                    RotationDecrypt_NO_Key(message, key); // Function for option 5. This executes the function body found below main. 
                        break; // Once function has been executed, break will 'jump-out' of the switch statement. This prevents other functions from being executed.
    
            default: // This option is only present if user selects a number outside the range of 1-5. If this occurs, default (operation) is executed. 
                    printf("Please enter an integer between 1 and 5"); // Statement prompting user to enter a valid option. 
                        break; // Once function has been executed, break will 'jump-out' of the switch statement. This prevents other functions from being executed.
        } 

 return 0;
} 


void RotationEncrypt(char *message, int key) // Function defintion of option 1. 
{
  
    printf("Enter key: (Key must be a number between 1 and 25)\n"); // Prompts user to declare a key for the rotation cipher.
    scanf("%d",&key); // Reads key declared by user and stores it as int key. Int key was initialised in main. 
    printf("Read %d\n", key); // Informs user via stdio standard out of operation they have selected. 
    int iteration; //Declaration of a int variable named iteration. Iteration shall be repeatedly indexed and will run through all possible alphabetical values.
    char letter; // Declares a char named letter. Letter gets modified by the cipher key. Its value is then assigned to an individual element of the message array. This is indexed through the length of the message. 
    int rotation; // Variable of type int that is equal to letter + key. This variable is assigned to letter. This is iterated through all relevant values to alter value of letter. 
                	
        for(iteration = 0; message[iteration] != '\0'; iteration++) // int iteration is initialised at 0. For loop runs until \0 (termination at end of a string) is reached. Iteration is indexed. 
        {
            letter = message[iteration]; // An individual unique letter of message[iteration] is assigned to letter. 
                		
                if(letter >= '`' && letter <= 'z') // Lower-case letters are converted to upper-case. This detects any values in the ASCII lower-case value range. 
                {
                    letter = letter - 32;  // 32 (difference between lower-case ASCII values and upper-case ASCII values) is minused from these values.
                }
                        rotation = letter + key; // Existing letter has key added to it.
                		
                        if(rotation >'Z') // If the value of rotation is > Z (ie ASCII lower-case and some symbols)
                        {
                            letter = rotation - 26; // Brings the value back to the ASCII upper-case range. Assings this value to letter.
                            
                		}
                			 
                            else if(rotation >= 'A' && rotation <= 'Z') // Else if the value of rotation is already within the ASCII upper-case range. 
                            {
                                letter = rotation; // Value of rotation is assigned to letter. 
                            }
                			
                			    message[iteration] = letter; // The value of letter is assigned to message. This is repeated for all iterations. 
       }
            printf("Ciphertext message: %s", message); // Message is printed as a string after all required iterations have run. 
}
                	


void RotationDecrypt(char *message, int key) // Function definition of option 2. 
{
    
    printf("Enter key: (Key must be a number between 1 and 25\n"); // Prompts user to declare a key for the rotation cipher. 
    scanf("%d", &key);
    int iteration;
    char letter;
    int rotation;
                	
       	    
                	    
                	    
                	    
                	    
                	    
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
                	
                   } // End Function Void RotationDecrypt
                   
   

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
                	
                	
                
                	
             



