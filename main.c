/*
This program can encrypt and decrypt a rotation cipher with a known numerical key. 
This program can encrypt and decrypt a substitution cipher with a known numerical key.
This program can decrypt a rotation cipher with an unknown numerical key.

User interface notes - The program first requires the user to enter the text to be encrypted or decrypted.
The program then offers the user a menu detailing possible operations.
A number between 1 and 5 is entered by the user matching the operation the user wishes to execute.
The user is then prompted for a key. The length and nature of the key is specified by the program for the users conveniance. 

Program uses scanf() statements which can be controlled in Eclipse Che by entering ./a.out into the terminal. 

Flow control - Program is controlled via main. User is prompted to enter a number between 1 and 5 which executes desired option. 
This is controlled via a switch case statement. 
The switch case statement directs to program to the relevant function. 
The function is then run. The result of the operations within the function is printed to the terminal via a printf() statement.
The program then returns to main, where a break statement in the switch case operation ends the program. 

USER INSTRUCTIONS FOR PROGRAM FIVE ARE LOCATED IN THE COMMENTS ABOVE IT.
*/

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
/*
This function encrypts plaintext with a rotation cipher with a known key. 
The inputs are plaintext, and a numerical key between 1 and 25.
The return value is ciphertext.
The function achieves this by taking each individual letter from the plaintext and adding the value of the key to it. 
If the value of this 'overflows' (i.e Z plus 6 overflows from the alphabet) the overflow is trasferred back to A at the start of the alphabet.
Each letter is converted to ciphertext. The message is then iterated and the next letter becomes encrypted. This continous until the entire message has been encrypted.
The message must be 99 characters or less (including spaces). 
*/

void RotationEncrypt(char *message, int key) // Function defintion of option 1. 
{
  
    printf("Enter key - Key must be a number between 1 and 25: \n"); // Prompts user to declare a key for the rotation cipher.
    scanf("%d",&key); // Reads key declared by user and stores it as int key. Int key was initialised in main. 
    printf("Read %d\n", key); // Informs user via stdio standard out of operation they have selected. 
    int iteration; //Declaration of a int variable named iteration. Iteration shall be repeatedly indexed and will run through all possible alphabetical values.
    char letter; // Declares a char named letter. Letter gets modified by the cipher key. Its value is then assigned to an individual element of the message array. This is indexed through the length of the message. 
    int rotation; // Variable of type int that is equal to letter + key. This variable is assigned to letter. This is iterated through all relevant values to alter value of letter. 
                	
        for(iteration = 0; message[iteration] != '\0'; iteration++) // int iteration is initialised at 0. For loop runs until \0 (termination at end of a string) is reached. Iteration is indexed. 
        {
            letter = message[iteration]; // An individual unique letter of message[iteration] is assigned to letter. 
                		
                if(letter >= 'a' && letter <= 'z') // Lower-case letters are converted to upper-case. This detects any values in the ASCII lower-case value range. 
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
            printf("Ciphertext message: %s\n", message); // Message is printed as a string after all required iterations have run. 
}
                	
/*
This function decrypts ciphertext with a rotation cipher with a known key. 
The inputs are ciphertext, and a numerical key between 1 and 25.
The return value is plaintext.
The function achieves this by taking each individual letter from the ciphertext and subtracting the value of the key from it. 
If the value of this 'underflows' (i.e A minus 6 underflows from the alphabet) the underflow is trasferred back to Z at the end of the alphabet.
Each letter is converted to plaintext. The message is then iterated and the next letter becomes decrypted. This continous until the entire message has been decrypted.
The message must be 99 characters or less (including spaces). 
*/

void RotationDecrypt(char *message, int key) // Function definition of option 2. 
{
    
    printf("Enter key - Key must be a number between 1 and 25: \n"); // Prompts user to declare a key for the rotation cipher. 
    scanf("%d", &key); // Reads key declared by user and stores it as int key. Int key was initialised in main. 
    int iteration; //Declaration of a int variable named iteration. Iteration shall be repeatedly indexed and will run through all possible alphabetical values.
    char letter; // Declares a char named letter. Letter gets modified by the cipher key. Its value is then assigned to an individual element of the message array. This is indexed through the length of the message.
                	    
        for(iteration = 0; message[iteration] != '\0'; ++iteration) // int iteration is initialised at 0. For loop runs until \0 (termination at end of a string) is reached. Iteration is indexed.
        {
            letter = message[iteration]; // An individual unique letter of message[iteration] is assigned to letter. 
                		
                if(letter >= 'a' && letter <= 'z') // Lower-case letters are converted to upper-case. This detects any values in the ASCII lower-case value range.
                {
                    letter = letter - key; // The value of letter minus the value of key is assigned to letter. 
                			
                        if(letter < 'a') // If the value of letter is greater than 'a'
                        {
	                        letter = letter + 26; // The value of letter + 26 is assigned to letter. 
                        }
                			
                                message[iteration] = letter - 32; // The value of letter minus 32 is assigned to message. This is repeated for all iterations. 32 is minused to convert from lower case to upper case. 
                }
                			
                		
                			
                                    else if(letter >= 'A' && letter <= 'Z') // This detects any values in ASCII upper-case range.
                                    {
                                        letter = letter - key; // The value of letter minus key is assigned to letter. This removes the rotation and produces plaintext.
                			
                                            if(letter < 'A') // If the value of letter is greater than 'A'
                                            {
                                                letter = letter + 26; // The value of letter plus 26 is assigned to letter. 
                                            }
                			
                                                    message[iteration] = letter; // The value of letter is assigned to message. This is repeated for all iterations. 
                                    }
                		
                		
    }
                	
    printf("Plaintext message: %s\n", message); // Message is printed as a string after all required iterations have run. 
                	
} 
/* 
This function encrypts plaintext with a substitution cipher with a known key. 
The inputs are plaintext and an encryption key. The encryption key is a known string of continous letters that is 26 letters long. The key cannot be longer than this.
The return value is ciphertext. 
The function achieves this by taking each individual letter from the plaintext and swapping it with the correspoding letter from the encryption key alphabet. The nth letter of the plaintext
is associated with the nth letter of the ciphertext. Since they encryption key is generally a random combination of the 26 letters of the alphabet, there are 26! possible combinations. 
The message must be 99 characters or less. 
*/

void SubstitutionEncrypt(char *message, char *encryptionKey) // Function definition of option 3.
{
    int iteration = 0;  //Declaration of a int variable named iteration. Iteration shall be repeatedly indexed and will run through all possible alphabetical values.
    printf("Enter Encryption Key: - Key must be a continous string of 26 upper-case letters \n"); // Prompts user to declare a key for the substitution cipher.
    scanf("%s", encryptionKey); // Reads key declared by user and stores it as char encryptionKey. Char encryptionKey was initialised in main. 
    
        for (iteration = 0; iteration < strlen(message); iteration++) // int iteration is initialised at 0. For loop runs until value is one < the length of the message. Iteration is indexed.
        {
            char letter = message[iteration]; // The value of message[iteration] is assigned to letter. 
            
                if (letter >= 'A' && letter <= 'Z') // Ensures the value of letter is within the ASCII upper-case range.
                {
                letter = encryptionKey[letter - 'A']; // EncryptionKey array of (letter minus 'A') is assigned to letter. This 'substitutes' the two alphabets.
                }
                    message[iteration] = letter; // The value of letter is assigned to message[iteration]. This alters the value of message with each iteration.
        }
            printf("CipherText message: %s\n", message); // Message is printed as a string after all required iterations have run.
}

/* 
This function decrypts ciphertext with a substitution cipher and a known key. 
The inputs are ciphertext and an encryption key. The encryption key is a known string of continous letters that is 26 letters long. The key cannot be longer than this.
The return value is plaintext.
The function achieves this by taking each individual letter from the ciphertext and swapping it with the correspoding letter from the encryption key alphabet. The nth letter of the ciphertext
is associated with the nth letter of the plaintext. Since they encryption key is generally a random combination of the 26 letters of the alphabet, there are 26! possible combinations. 
The message must be 99 characters or less. 
*/

void SubstitutionDecrypt(char*message, char*encryptionKey) // Function definition of option 4.
{
    int iteration; // Declaration of a int variable named iteration. Iteration shall be repeatedly indexed and will run through all possible alphabetical values.
    int iterationTwo = 0; // Declaration of an int variable named iterationTwo. IterationTwo shall be repeatedly indexed and will run through all possible alphabetical values.
    int letter; // int variable named letter. Holds an alphabetical value that is modified.
    printf("Enter a encryption key -Key must be a continous string of 26 upper-case letters \n"); // Prompts user to declare a key for the substitution cipher.
    scanf("%s", encryptionKey); // Reads key declared by user and stores it as char encryptionKey. Char encryptionKey was initialised in main. 

        for (iteration = 0; message[iteration] != '0'; iteration++) // int iteration is initialised at 0; For loop runs until \0 (termination at end of a string) is reached. Iteration is indexed.
        {
            letter = message[iteration]; // Value of message array is assigned to letter. This is iterated with each loop.
                if (letter >= 'a' && letter <= 'z') // Detects message in ASCII lower-case range.
                {
                    letter = letter - 32; // 32 is minused from letter to convert it to upper-case.
                }
                        if(letter >= 'A' && letter <= 'Z') // Detects if message is in ASCII upper-case range.
                        {
                            for (iterationTwo = 0; iterationTwo < 27; iterationTwo++) // For iterationTwo is initilised at 0; iteration two is indexed until < 26 is reached, iterationTwo is indexed with each loop.
                            {
                                if(message[iteration] == encryptionKey[iterationTwo]) // If the value of the particular message iteration is equal to the value of the encryption key for the given iteration
                                {
                                    break; // escape out of loop
                        
                                } 
                    
                            }
                                        message[iteration] = iterationTwo + 'A'; // The value of iterationTwo + 'A' is assigned to message for the given iteration.
                        }
    
        }
            printf("PlainText message: %s\n", message); // Message is printed as a string after all required iterations have run.
   
} 

/*
This function decrypts ciphertext with a rotation cipher. It is intended that this fucntion is used with an unknown key.  
The input is ciphertext.
The return value is plaintext and an encryption key.
The function achieves this by taking each individual letter from the ciphertext and subtracting the value of the key from it. 
If the value of this 'underflows' (i.e A minus 6 underflows from the alphabet) the underflow is trasferred back to Z at the end of the alphabet.
Each letter is converted to plaintext. The message is then iterated and the next letter becomes decrypted. This continous until the entire message has been decrypted.
The above process is executed for a key initialised at one. The key value is indexed until it reaches 25. This is managed via a int variable called count. This ensures that all possible keys are tested. 
The message must be 99 characters or less (including spaces). 


USER INSTRUCTIONS - Enter the first few words of the ciphertext. Execute the program. Look through the output and find the statement with english plaintext. Take note of the decryption key the program used.
Enter the entire message and the decryption key into operation 2. The entire message will be decrypted. 
*/

void RotationDecrypt_NO_Key(char *message, int key) // Function definition of item 5.
{
    int iteration; // Declaration of a int variable named iteration. Iteration shall be repeatedly indexed and will run through all possible alphabetical values.
    char letter; // int variable named letter. Holds an alphabetical value that is modified.
    int count = 1; // Counting variable of type int. This is used to loop the program through all relevant options to find decrypt the cipher text. 
    
        for (count = 1; count <=26; count++)  // Count is initialised at 1, count is iterated until it is <= 26; count is iterated with each location. 
        {
            for(iteration = 0; message[iteration] != '\0'; ++iteration) // int iteration is initialised at 0; For loop runs until \0 (termination at end of a string) is reached. Iteration is indexed.
            {
                letter = message[iteration]; // Value of message array is assigned to letter. This is iterated with each loop
                key = 1; // Key is initialised at 1
                    if(letter >= 'A' && letter <= 'Z') // If key is >= 'A' and letter <= Z
                    {
                        letter = letter - key; // The value of letter minus key is assigned to letter. This decodes the ciphertext.
                			
                		    if(letter < 'A') // If letter < A
                		    {
                				letter = letter + 'Z' - 'A' + 1; // The value of letter plus 'Z' - 'A' + 1 is assigned to letter. 
                				
                			}
                			
                			        message[iteration] = letter; // Modified value of letter is assigned to message for the given iteration. 
                	}
                	
                		                else if(letter >= 'a' && letter <= 'z') // Detects lower-case ASCII values
                		                {
                			                letter = letter - key; // Value of key is minused from letter. This is assigned to letter. This decodes the ciphertext.
                			
                			                    if(letter < 'a') // If letter < 'a'
                			                    {
                				                    letter = letter + 'z' - 'a' + 1; // The value of letter + 'z' - 'a' + 1 is assigned to the letter. 
                				                    
                			                    }
                			
                			                            message[iteration] = letter; // Modified value of letter is assigned to message for the given iteration.
                		                }
                		
                		                                    key = key + 1; // The value of key plus key is assigned to key. This is done to allow for decryption of all possible keys. 
            }
                	
                printf("Plaintext message: %s  Key Number:  %d\n", message, count); // Message is printed as a string after all required iterations have run. The number of each key is given to the user.
        }
                	
            printf("Check the decoded text outputs. Find the output that is English plain text. Note the key number for the English plain text.\n"); // Instructions for the user to decode the remainder of the message.
            printf("Enter the full message with correct key number into operation 2. The CipherText text will be decoded."); // Instructions for the user to decode the remainder of the message by entering the message 
            //into operation 2 with the known key.
}
                	
                	
                
                	
             



