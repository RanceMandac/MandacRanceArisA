#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct dataGame
{
	char Topic[20];
	int QuestionNum;
	char Question[150];
	char Choice1[30];	
	char Choice2[30];
	char Choice3[30];
	char Answer[30];
};

void AddRecords(struct dataGame dataRecords[], int *nData)
{
	char topicArray[20];
    char Choice1Array[30];
    char Choice2Array[30];
    char Choice3Array[30];
    char answerArray[30];
    int questionNum;
    char questionSearch[30]; // changed from int to char array
    char answerSearch[30]; // changed from int to char array

    // Get user input for new record
    printf("\n\t---ADD RECORD---\n");
    printf("\n\tEnter question below: ");
    scanf(" %29[^\n]", questionSearch); // using a format string to read a whole line of input
    printf("\n\tEnter answer below: ");
    scanf(" %29[^\n]", answerSearch); // using a format string to read a whole line of input

    // Check if question and answer already exist in records
    for (int i = 0; i < *nData; i++) // changed nData to *nData to access the value pointed to by the pointer
    {
        if (strcmp(questionSearch, dataRecords[i].Question) == 0 && strcmp(answerSearch, dataRecords[i].Answer) == 0) // corrected variable name from 'answer' to 'answerSearch'
        {
            printf("\n\tThe question and answer pair already exists in the records:\n");
            printf("\n\tTopic: %s\n", dataRecords[i].Topic);
            printf("\tQuestion Number: %d\n", dataRecords[i].QuestionNum);
            printf("\tQuestion: %s\n", dataRecords[i].Question);
            printf("\tChoice 1: %s\n", dataRecords[i].Choice1);
            printf("\tChoice 2: %s\n", dataRecords[i].Choice2);
            printf("\tChoice 3: %s\n", dataRecords[i].Choice3);
            printf("\tAnswer: %s\n",dataRecords[i].Answer);
            return;
        }
    }

    // Get remaining input for new record
    printf("\n\tEnter topic: ");
    scanf("%s", topicArray); // added a width specifier to avoid buffer overflow
    printf("\n\tEnter 1st choice:");
    scanf("%s", Choice1Array);
    printf("\n\tEnter 2nd choice:");
    scanf("%s", Choice2Array);
    printf("\n\tEnter 3rd choice:");
    scanf("%s", Choice3Array);
    printf("\n\tEnter answer: ");
    scanf("%s", answerArray); // added width specifier

    // Get question number based on topic and assign to new record
    questionNum = 1;
    for (int i = 0; i < *nData; i++) // changed nData to *nData to access the value pointed to by the pointer
    {
        if (strcmp(topicArray, dataRecords[i].Topic) == 0 && dataRecords[i].QuestionNum >= questionNum)
        {
            questionNum = dataRecords[i].QuestionNum + 1;
        }
    }

	 // Add new record to array
	strcpy(dataRecords[*nData].Topic, topicArray); // changed dataList to dataRecords and added '*' to access the value pointed to by the pointer
	dataRecords[*nData].QuestionNum = questionNum;
	strcpy(dataRecords[*nData].Question, questionSearch); // changed question to questionSearch
	strcpy(dataRecords[*nData].Choice1, Choice1Array); // changed choice1 to Choice1Array
	strcpy(dataRecords[*nData].Choice2, Choice2Array); // fixed typo (added 2)
	strcpy(dataRecords[*nData].Choice3, Choice3Array);
	strcpy(dataRecords[*nData].Answer, answerArray);
	printf("\n\tRecord added successfully!\n");

	(*nData)++; // increment nData to reflect the addition of a new record
	return;
}

int displayMenu()
{
	int menuNum;
	printf("\n\n");
	printf("	Welcome to the Quiz Game!\n\n");
	printf("	Enter a number to proceed!\n");
	printf("	[1] Manage Data!\n");
	printf("	[2] Proceed to game!\n");
	printf("	[3] End Program!\n\n");
	printf("	Input Number Here: ");
	scanf("%d",&menuNum);
	return(menuNum);
}

void DisplayRecords(struct dataGame dataRecords[], int nData)
{
    printf("\n\t---RECORDS---\n"); 	// PRINT EACH RECORD
    for (int i = 0; i < nData; i++)
    {
    	printf("\n\t---RECORDS #%d---\n",i+1); 	// PRINT EACH RECORD
        printf("	Topic: %s\n", dataRecords[i].Topic);
        printf("	Question Num: %d\n", dataRecords[i].QuestionNum);
        printf("	Question: %s\n", dataRecords[i].Question);
        printf("	Choice #1: %s\n", dataRecords[i].Choice1);
        printf("	Choice #2: %s\n", dataRecords[i].Choice2);
        printf("	Choice #3: %s\n", dataRecords[i].Choice3);
        printf("	Answer: %s\n\n", dataRecords[i].Answer);
    }
}

void displayUniqueTopics(struct dataGame *dataRecords, int *nData)
{
    char uniqueTopics[100][20]; 		// Assuming there are no more than 100 unique topics, each with 20 characters or less
    int nUniqueTopics = 0;
    
    									// Find all unique topics in the dataRecords array
    for (int i = 0; i < *nData; i++)
    {
        								// Check if the current record's topic is already in the uniqueTopics array
        int newTopic = 1;
        for (int j = 0; j < nUniqueTopics; j++)
        {
            if (strcmp(dataRecords[i].Topic, uniqueTopics[j]) == 0)
            {
                newTopic = 0;
            }
        }
        
        // If the current record's topic is not in the uniqueTopics array, add it
        if (newTopic)
        {
            strcpy(uniqueTopics[nUniqueTopics], dataRecords[i].Topic);
            nUniqueTopics++;
        }
    }
    
    printf("Available topics:\n"); // Display all unique topics
    for (int i = 0; i < nUniqueTopics; i++)
    {
        printf("%d. %s\n", i + 1, uniqueTopics[i]);
    }
}

void displayEdit(struct dataGame dataRecords[], int questionNum)
{
	printf("\n\t---RECORD #%d---\n", questionNum);  // PRINT EACH RECORD
    printf("\tTopic: %s\n", dataRecords[questionNum-1].Topic);
    printf("\tQuestion Num: %d\n", dataRecords[questionNum-1].QuestionNum);
    printf("\tQuestion: %s\n", dataRecords[questionNum-1].Question);
    printf("\tChoice #1: %s\n", dataRecords[questionNum-1].Choice1);
    printf("\tChoice #2: %s\n", dataRecords[questionNum-1].Choice2);
    printf("\tChoice #3: %s\n", dataRecords[questionNum-1].Choice3);
    printf("\tAnswer: %s\n\n", dataRecords[questionNum-1].Answer);
}

void editRecords(struct dataGame dataRecords[], int *nData)
{
    int questionNum, choice;
    char newValue[100];
    int highestQuestionNum;
    
    printf("\n	Enter the Record number to edit: ");
    scanf("%d", &questionNum);
    
    // Check if question number is valid
    if (questionNum < 1 || questionNum > *nData)
    {
        printf("\nInvalid question number. Please enter a number between 1 and %d.\n", *nData);
        return;
    }
    
    displayEdit(dataRecords, questionNum);
    
    printf("\n	What would you like to edit?\n");
    printf("	1. Topic\n");
    printf("	2. Question\n");
    printf("	3. Choices\n");
    printf("	4. Answer\n");
    printf("		Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) 
    {
        case 1:
            printf("\nEnter the new topic: ");
            scanf("%s", newValue);
            
            // Check for duplicate topics
            highestQuestionNum = dataRecords[questionNum-1].QuestionNum;
            for (int i = 0; i < *nData; i++)
            {
                if (i != questionNum-1 && strcmp(dataRecords[i].Topic, newValue) == 0)
                {
                    if (dataRecords[i].QuestionNum >= highestQuestionNum)
                    {
                        highestQuestionNum = dataRecords[i].QuestionNum + 1;
                    }
                }
            }
            
            dataRecords[questionNum-1].QuestionNum = highestQuestionNum;
            strcpy(dataRecords[questionNum-1].Topic, newValue);
            printf("\nRecord updated.\n");
            break;
            
        case 2:
            printf("\nEnter the new question: ");
            scanf(" %[^\n]s", newValue);
            strcpy(dataRecords[questionNum-1].Question, newValue);
            printf("\nRecord updated.\n");
            break;
        
        case 3:
            printf("\nEnter the new first choice: ");
            scanf("%s", newValue);
            strcpy(dataRecords[questionNum-1].Choice1, newValue);
            printf("\nEnter the new second choice: ");
            scanf("%s", newValue);
            strcpy(dataRecords[questionNum-1].Choice2, newValue);
            printf("\nEnter the new third choice: ");
            scanf("%s", newValue);
            strcpy(dataRecords[questionNum-1].Choice3, newValue);
            printf("\nRecord updated.\n");
            break;
            
        case 4:
            printf("\nEnter the new answer: ");
            scanf("%s", newValue);
            strcpy(dataRecords[questionNum-1].Answer, newValue);
            printf("\nRecord updated.\n");
            break;
            
        default:
            printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
            break;
    }
    printf("\nRecord updated.\n");
}

void deleteRecords(struct dataGame dataRecords[], int *nData)
{
    // Display all unique topics
    displayUniqueTopics(dataRecords, nData);
    
    // Ask the admin which topic to delete a question from
    printf("\nEnter the number of the topic to delete a question from: ");
    int topicChoice;
    scanf("%d", &topicChoice);
    
    // Find all records with the selected topic and display their question numbers and questions
    printf("\nQuestions on topic '%s':\n", dataRecords[topicChoice - 1].Topic);
    for (int i = 0; i < *nData; i++)
    {
        if (strcmp(dataRecords[i].Topic, dataRecords[topicChoice - 1].Topic) == 0)
        {
            printf("%d. %s\n", i + 1, dataRecords[i].Question);
        }
    }
    
    // Ask the admin which question to delete
    printf("\nEnter the number of the question to delete: ");
    int questionChoice;
    scanf("%d", &questionChoice);
    
    // Confirm deletion with the admin
    printf("\nAre you sure you want to delete the following question?\n%s\n\nEnter Y to confirm deletion or N to cancel: ", dataRecords[questionChoice - 1].Question);
    char confirmChoice[5];
    scanf("%s", confirmChoice);
    
    // If the admin confirms deletion, delete the record and display success message
    if (strcmp(confirmChoice, "Y") == 0 || strcmp(confirmChoice, "y") == 0)
    {
        for (int i = questionChoice - 1; i < *nData - 1; i++)
        {
            dataRecords[i] = dataRecords[i + 1];
        }
        (*nData)--;
        printf("\nRecord deleted successfully!\n");
    }
}


int adminPassword()
{
    // ADMIN PASSWORD IS 123
    char password[100];
    int maxAttempts = 3, i;
    int passwordAccess = 0; // INITIALIZE TO FALSE
    int j = 0;
    char ch;

    for (i = 1; i <= maxAttempts; i++)
    {
        printf("	Please enter the password: ");

        while ((ch = getch()) != '\r' && j < 99) // ASTERISKS HIDE
        {
            if (ch == 8) 
			{ 
                if (j > 0) 
				{
                    j--;
                    printf("\b \b"); 			// FOR BACKSPACE INPUT
                }
            } else 
			{
                password[j++] = ch;
                printf("*");
            }
        }
        
        password[j] = '\0';
        printf("\n");
        
        if (strcmp(password, "123") == 0)
        {
            printf("\n	Correct password!\n");
            printf("	Access Granted!\n");
            passwordAccess = 1; // set to true
            i = 3;
        }
        else
        {
            printf("\n	Incorrect password. You have %d attempts left.\n", maxAttempts - i);
            passwordAccess = 0; // set to false
        }
    }

    if (passwordAccess == 0)
    {
        printf("	You have exceeded the maximum number of attempts.\n");
        return -1; // indicate incorrect password
    }
    else
    {
        return 1; // indicate correct password
    }
}

int main()
{
    struct dataGame dataRecords[100]; // 100 STRUCTS OR 100 QUESTIONS FOR QUIZ GAME 
    char returnMenu;                  // Y OR N IN ORDER TO RETURN TO MENU
    int menuOption;                   // MAIN MENU OPTIONS
    int DataMenu;                     // DATA MENU OPTIONS
    int dataPassword = -1;            // INITIALIZE TO INVALID VALUE SUCH AS -1 FIRST. THIS WILL MAKE SURE THAT 
                                      // WHEN THE USER WANTS TO ENTER THE PASSWORD AGAIN THEY WILL NOT BE ASKED TO ENTER THE PASSWORD
    int nData;
    char addMore;
    char editMore;
    char returnManage;

    do
    {
        menuOption = displayMenu();
        
        switch(menuOption) 
        {
            case 1:
                if (dataPassword != 1)             // check if user has entered the correct password before
                {
                    dataPassword = adminPassword();// prompt user to enter password
                }
                if (dataPassword == 1)             // if password is correct
	                {
	                	do
	                	{
	                	system("cls");
	                    printf("\n\t---MANAGE DATA---\n");
	                    printf("\n\t---1 ADD RECORD---\n");
	                    printf("\n\t---2 EDIT RECORD--\n");
	                    printf("\n\t---3 DELETE RECORD---\n");
	                    printf("\n\t---4 IMPORT DATA\n");
	                    printf("\n\t---5 EXPORT DATA\n");
	                    printf("\n\t---6 MAIN MENU\n");
	                    printf("\n\tEnter Number Here: ");
	                    scanf("%d", &DataMenu);
		                    switch(DataMenu) 
		                    {
		                        case 1:
		                        	do
		                        	{
		                        	system("cls");
		                        	DisplayRecords(dataRecords,nData);
		                            AddRecords(dataRecords, &nData); 	// Pass nData to AddRecords
		                            printf("\n	Do you want to add more records? (y/n): ");
		                            scanf(" %c",&addMore);
		                      		}while(addMore == 'y' || addMore == 'Y');
		                      		DisplayRecords(dataRecords, nData); // Display all records after adding
		                            break;
		                        case 2:
		                        	do
		                        	{
		                        	system("cls");
		                        	DisplayRecords(dataRecords,nData);
		                            editRecords(dataRecords,&nData);
		                            DisplayRecords(dataRecords,nData);
		                            printf("\n	Do you want to edit more records? (y/n): ");
		                            scanf(" %c",&editMore);
		                     	   	}while(editMore == 'Y' || editMore == 'y');
		                            break;
		                        case 3: 
		                        	system("cls");
		                        	DisplayRecords(dataRecords,nData);
		                            deleteRecords(dataRecords,&nData);
		                            DisplayRecords(dataRecords,nData);
		                            break;
		                        case 4:
		                            // TODO: Import Data
		                            break;
		                        case 5:
		                            // TODO: Export Data
		                            break;
		                        case 6:
		                            // TODO: Return To Main Menu
		                            break;
		                        default:
		                            printf("\n\tInvalid input! Please try again.\n");
		                            break;
		                    }
		                printf("\n\tReturn to Manage Data Menu?: ");
       					printf("\n\tEntering [y] or [Y] will Return to Manage Data Menu!(y/n):  ");
       					scanf(" %c", &returnManage); 
	                	}while(returnManage == 'y' || returnManage == 'Y');
	          		}
	        	break;
            case 2:
                printf("\n\t---PLAY THE GAME---\n");
                printf("\n\t---GAME GAME GAME---\n");
                break;
                
            case 3:
                printf("\n\t---END PROGRAM---\n");
                return 0;
                
            default:
                printf("\n\tInvalid input! Please try again.\n");
                break;
        }
        
        printf("\n\tReturn to Main Menu?: ");
        printf("\n\tEntering [y] or [Y] will Return to Main Menu!(y/n): ");
        scanf(" %c", &returnMenu); 
    } while (returnMenu == 'y' || returnMenu == 'Y');
    
    printf("\n\tTerminating Program..... ");

    return 0;
}

