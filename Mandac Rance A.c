#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


/*********************************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have constructed the functions and their respective algorithms and corresponding code by myself. The
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole or
otherwise plagiarized the work of other students and/or persons.
Rance Aris Mandac, DLSU ID# 12208019
*********************************************************************************************************/

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

struct quizData
{
	char Topic[20];
	int QuestionNum;
	char Question[150];
	char Choice1[30];	
	char Choice2[30];
	char Choice3[30];
	char Answer[30];
};

struct dataPlayer
{
	char playerName[30];
	int playerScore;
};

/*  resetRecords - a function that resets the number of data records to zero
	@param nData - a pointer to the integer variable storing the number of data records
	@return none
	Pre-condition: nData points to a valid integer variable
*/

void resetRecords(int *nData) 
{
    *nData = 0;
}

/*
	Function Name: AddRecords
	Description:
	This function allows the user to add a new record to an array of dataGame structures.
	It prompts the user to enter a question and answer pair, checks if the pair already exists
	in the records, and prompts the user to enter remaining information for the new record.
	It also assigns a question number to the new record based on the topic.
	
	@param dataRecords - an array of dataGame structures containing existing records
	@param nData - a pointer to the number of existing records in dataRecords array
	
	Local Variables:
	topicArray: A character array of size 20 to store the topic of the new record.
	Choice1Array: A character array of size 30 to store the first choice of the new record.
	Choice2Array: A character array of size 30 to store the second choice of the new record.
	Choice3Array: A character array of size 30 to store the third choice of the new record.
	answerArray: A character array of size 30 to store the answer of the new record.
	questionNum: An integer variable to store the question number of the new record.
	questionSearch: A character array of size 30 to store the question entered by the user when searching for an existing record.
	answerSearch: A character array of size 30 to store the answer entered by the user when searching for an existing record.
*/
void AddRecords(struct dataGame dataRecords[], int *nData)
{
    char topicArray[20];
    char Choice1Array[30];
    char Choice2Array[30];
    char Choice3Array[30];
    char answerArray[30];
    int questionNum;
    char questionSearch[30];
    char answerSearch[30];
    int i;

  										  // Get user input for new record
    printf("\n	ADD RECORD TO DATA\n");
    printf("\n\tEnter question below: ");
    scanf(" %[^\n]", questionSearch); 	 // read a whole line of input including spaces
    printf("\n\tEnter answer below: ");
    scanf(" %[^\n]", answerSearch); 	 // read a whole line of input including spaces

   										 // Check if question and answer already exist in records
    for (i = 0; i < *nData; i++)
    {
        if (strcmp(questionSearch, dataRecords[i].Question) == 0 && strcmp(answerSearch, dataRecords[i].Answer) == 0)
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
    scanf(" %[^\n]", topicArray); 	  // read a whole line of input including spaces
    printf("\n\tEnter 1st choice:");
    scanf(" %[^\n]", Choice1Array);   // read a whole line of input including spaces
    printf("\n\tEnter 2nd choice:");
    scanf(" %[^\n]", Choice2Array);   // read a whole line of input including spaces
    printf("\n\tEnter 3rd choice:");
    scanf(" %[^\n]", Choice3Array);   // read a whole line of input including spaces
    printf("\n\tEnter answer: ");
    scanf(" %[^\n]", answerArray);    // read a whole line of input including spaces
    
    								  // Get question number based on topic and assign to new record
    questionNum = 1;
    for (i = 0; i < *nData; i++)
    {
        if (strcmp(topicArray, dataRecords[i].Topic) == 0 && dataRecords[i].QuestionNum >= questionNum)
        {
            questionNum = dataRecords[i].QuestionNum + 1;
        }
    }

    								   // Add new record to array
    strcpy(dataRecords[*nData].Topic, topicArray);
    dataRecords[*nData].QuestionNum = questionNum;
    strcpy(dataRecords[*nData].Question, questionSearch);
    strcpy(dataRecords[*nData].Choice1, Choice1Array);
    strcpy(dataRecords[*nData].Choice2, Choice2Array);
    strcpy(dataRecords[*nData].Choice3, Choice3Array);
    strcpy(dataRecords[*nData].Answer, answerArray);
    printf("\n\tRecord added successfully!\n");

    (*nData)++;
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
	int i;
    printf("\n	RECORDS IN DATA:\n"); 							// PRINT EACH RECORD
    if(nData == 0)
    {
    	printf("\n	There are no records found please Add or Import Data!\n\n");
	}
    for (i = 0; i < nData; i++)
    {
    	printf("\n	RECORD #%d\n",i+1); 						// PRINT EACH RECORD
        printf("	Topic: %s\n", dataRecords[i].Topic);
        printf("	Question Num: %d\n", dataRecords[i].QuestionNum);
        printf("	Question: %s\n", dataRecords[i].Question);
        printf("	Choice #1: %s\n", dataRecords[i].Choice1);
        printf("	Choice #2: %s\n", dataRecords[i].Choice2);
        printf("	Choice #3: %s\n", dataRecords[i].Choice3);
        printf("	Answer: %s\n\n", dataRecords[i].Answer);
    }
}

/*
	This function displays all unique topics in the given dataRecords array.
	@param dataRecords: pointer to an array of dataGame struct representing game data records
	@param nData: pointer to an integer indicating the number of data records in the array
	@return None
	Local Variables:
	uniqueTopics: a 2D character array used to store unique topics found in the dataRecords array
	nUniqueTopics: integer indicating the number of unique topics found
	i, j: integers used for loop iteration
	newTopic: integer indicating whether the current record's topic is new or already exists in uniqueTopics array
*/
void displayUniqueTopics(struct dataGame *dataRecords, int *nData)
{
    char uniqueTopics[100][20]; 		// Assuming there are no more than 100 unique topics, each with 20 characters or less
    int nUniqueTopics = 0;
    int i;
    int j;
    
    									// Find all unique topics in the dataRecords array
    for (i = 0; i < *nData; i++)
    {
        								// Check if the current record's topic is already in the uniqueTopics array
        int newTopic = 1;
        for (j = 0; j < nUniqueTopics; j++)
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
    
    printf("	Available topics:\n"); // Display all unique topics
    for (i = 0; i < nUniqueTopics; i++)
    {
        printf("	%d. %s\n", i + 1, uniqueTopics[i]);
    }
}

/*
	This function finds all unique topics in the quizRecords array and displays them to the user.
	@param quizRecords: array of quizData structures containing quiz records
	@param nQuizData: integer pointer to the number of quiz records in the array
	@return None
	Local Variables:
	
	uniqueTopics: 2D character array used to store unique topics
	nUniqueTopics: integer indicating the number of unique topics found
	i: integer used for loop iteration
	isNewTopic: integer indicating whether the current record's topic is new or not
	j: integer used for indexing uniqueTopics array
*/
void displayUniqueTopicsQuiz(struct quizData quizRecords[], int *nQuizData) 
{
    char uniqueTopics[100][20]; // Assuming there are no more than 100 unique topics, each with 20 characters or less
    int nUniqueTopics = 0;
    int i;
    int j;
    
    // Find all unique topics in the quizRecords array
    for (i = 0; i < *nQuizData; i++)
    {
        // Check if the current record's topic is already in the uniqueTopics array
        int isNewTopic = 1;
        for (j = 0; j < nUniqueTopics; j++)
        {
            if (strcmp(quizRecords[i].Topic, uniqueTopics[j]) == 0)
            {
                isNewTopic = 0;
            }
        }
        
        // If the current record's topic is not in the uniqueTopics array, add it
        if (isNewTopic)
        {
            strcpy(uniqueTopics[nUniqueTopics], quizRecords[i].Topic);
            nUniqueTopics++;
        }
    }
    
    printf("Available topics:\n"); // Display all unique topics
    for (i = 0; i < nUniqueTopics; i++)
    {
        printf("%d. %s\n", i + 1, uniqueTopics[i]);
    }
}

void displayEdit(struct dataGame dataRecords[], int questionNum)
{

	printf("\n	RECORD #%d\n\n", questionNum);  // PRINT EACH RECORD
    printf("	Topic: %s\n", dataRecords[questionNum-1].Topic);
    printf("	Question Num: %d\n", dataRecords[questionNum-1].QuestionNum);
    printf("	Question: %s\n", dataRecords[questionNum-1].Question);
    printf("	Choice #1: %s\n", dataRecords[questionNum-1].Choice1);
    printf("	Choice #2: %s\n", dataRecords[questionNum-1].Choice2);
    printf("	Choice #3: %s\n", dataRecords[questionNum-1].Choice3);
    printf("	Answer: %s\n\n", dataRecords[questionNum-1].Answer);
}

/* editRecords is a function that allows the administrator to modify an existing record in the dataRecords array.
		@param dataRecords - an array of struct dataGame containing all the records
		@param nData - a pointer to the number of records stored in the array
		@returns nothing
		
		Local Variables:
		topicChoice: An integer variable used to store the admin's choice of topic number to edit a question from.
		count: An integer variable used to keep track of the number of records with the selected topic.
		questionNums: An integer array of size nData used to store the question numbers of all records with the selected topic.
		questionChoice: An integer variable used to store the admin's choice of question number to edit.
		fieldChoice: An integer variable used to store the admin's choice of field to modify.
*/
void editRecords(struct dataGame dataRecords[], int *nData)
{
	int i;
    // Display all unique topics
    displayUniqueTopics(dataRecords, nData);

    // Ask the admin which topic to edit a question from
    printf("\n	Enter the number of the topic to edit a question from: ");
    int topicChoice;
    scanf("%d", &topicChoice);

    // Find all records with the selected topic and display their question numbers and questions
    printf("\n	Questions on topic '%s':\n", dataRecords[topicChoice - 1].Topic);
    int count = 0;
    int questionNums[*nData];
    for (i = 0; i < *nData; i++)
    {
        if (strcmp(dataRecords[i].Topic, dataRecords[topicChoice - 1].Topic) == 0)
        {
            count++;
            questionNums[count - 1] = i + 1;
            printf("	%d. %s\n", count, dataRecords[i].Question);
        }
    }

    // Ask the admin which question to edit
    printf("\n	Enter the number of the question to edit: ");
    int questionChoice;
    scanf("%d", &questionChoice);

    // Display the chosen record
    displayEdit(dataRecords, questionNums[questionChoice - 1]);

    // Ask the admin which field to modify
    printf("	Which field would you like to modify?\n");
    printf("	1. Topic\n");
    printf("	2. Question\n");
    printf("	3. Choice #1\n");
    printf("	4. Choice #2\n");
    printf("	5. Choice #3\n");
    printf("	6. Answer\n");
    printf("	Enter the number of the field to modify: ");
    int fieldChoice;
    scanf("%d", &fieldChoice);

    // Modify the chosen field
    switch (fieldChoice)
    {
        case 1:
            printf("	Enter the new topic: ");
            scanf(" %[^\n]", dataRecords[questionNums[questionChoice - 1] - 1].Topic);
            break;
        case 2:
            printf("	Enter the new question: ");
            scanf(" %[^\n]", dataRecords[questionNums[questionChoice - 1] - 1].Question);
            break;
        case 3:
            printf("	Enter the new choice #1: ");
            scanf(" %[^\n]", dataRecords[questionNums[questionChoice - 1] - 1].Choice1);
            break;
        case 4:
            printf("	Enter the new choice #2: ");
            scanf(" %[^\n]", dataRecords[questionNums[questionChoice - 1] - 1].Choice2);
            break;
        case 5:
            printf("	Enter the new choice #3: ");
            scanf(" %[^\n]", dataRecords[questionNums[questionChoice - 1] - 1].Choice3);
            break;
        case 6:
            printf("	Enter the new answer: ");
            scanf(" %[^\n]", dataRecords[questionNums[questionChoice - 1] - 1].Answer);
            break;
        default:
            printf("	Invalid field choice.\n");
            printf("	Only Select From 1 - 6.\n");
            return;
    }

    printf("Record updated.\n");
}

/*
	deleteRecords is a function that allows the administrator to delete a record from the dataRecords array.
	@param dataRecords - an array of struct dataGame containing all the records
	@param nData - a pointer to the number of records stored in the array
	@returns nothing
	
	Local Variables:
	topicChoice - an integer variable used to store the admin's choice of topic number to delete a question from.
	numQuestionsToDelete - an integer variable used to store the number of questions to delete.
	questionIndicesToDelete - an integer array of size 100 used to store the indices of the questions to delete.
	questionChoice - an integer variable used to store the admin's choice of question number to delete.
	confirmChoice - a character array of size 5 used to store the admin's confirmation choice.
*/
void deleteRecords(struct dataGame dataRecords[], int *nData)
{
	int i;
    // Display all unique topics
    displayUniqueTopics(dataRecords, nData);
    
    // Ask the admin which topic to delete a question from
    printf("\n	Enter the number of the topic to delete a question from: ");
    int topicChoice;
    scanf("%d", &topicChoice);
    
    // Find all records with the selected topic and display their question numbers and questions
    printf("\n	Questions on topic '%s':\n", dataRecords[topicChoice - 1].Topic);
    int numQuestionsToDelete = 0;
    int questionIndicesToDelete[100];
    for (i = 0; i < *nData; i++)
    {
        if (strcmp(dataRecords[i].Topic, dataRecords[topicChoice - 1].Topic) == 0)
        {
            printf("%d. %s\n", i + 1, dataRecords[i].Question);
            numQuestionsToDelete++;
            questionIndicesToDelete[numQuestionsToDelete - 1] = i;
        }
    }
    
    // Ask the admin which question to delete
    printf("\n	Enter the number of the question to delete: ");
    int questionChoice;
    scanf("%d", &questionChoice);
    
    // Confirm deletion with the admin
    printf("\n	Are you sure you want to delete the following question?\n	%s\n\nEnter Y to confirm deletion or N to cancel: ", dataRecords[questionIndicesToDelete[questionChoice - 1]].Question);
    char confirmChoice[5];
    scanf("%s", confirmChoice);
    
    // If the admin confirms deletion, delete the record and display success message
    if (strcmp(confirmChoice, "Y") == 0 || strcmp(confirmChoice, "y") == 0)
    {
        int questionNumToDelete = dataRecords[questionIndicesToDelete[questionChoice - 1]].QuestionNum;
        for (i = questionIndicesToDelete[questionChoice - 1]; i < *nData - 1; i++)
        {
            dataRecords[i] = dataRecords[i + 1];
            if (dataRecords[i].QuestionNum > questionNumToDelete)
            {
                dataRecords[i].QuestionNum--;
            }
        }
        (*nData)--;
        printf("\n	Record deleted successfully!\n");
    }
}

/*
	Import data from a text file into the dataRecords array.
	@param dataRecords - an array of struct dataGame containing all the records
	@param nData - a pointer to the number of records stored in the array
	@return  0 if the data is successfully imported, and 1 if there is an error opening the file
*/
int importData(struct dataGame dataRecords[], int *nData)
{
    char filename[31];
    printf("Enter the filename of the text file to load: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
	{
        printf("Error: cannot open file\n");
        return 1;
    }

    char line[100];
    int record_count = *nData;

    while (fgets(line, sizeof(line), fp)) 
	{
        if (line[strlen(line) - 1] == '\n') 
		{
            line[strlen(line) - 1] = '\0';
        }

        if (line[0] >= '0' && line[0] <= '9') 
		{
            int question_number = atoi(line);
            fgets(dataRecords[record_count].Question, sizeof(dataRecords[record_count].Question), fp);
            dataRecords[record_count].Question[strlen(dataRecords[record_count].Question) - 1] = '\0';

        	fgets(dataRecords[record_count].Choice1, sizeof(dataRecords[record_count].Choice1), fp);
			dataRecords[record_count].Choice1[strlen(dataRecords[record_count].Choice1) - 1] = '\0';
			
			fgets(dataRecords[record_count].Choice2, sizeof(dataRecords[record_count].Choice2), fp);
			dataRecords[record_count].Choice2[strlen(dataRecords[record_count].Choice2) - 1] = '\0';
			
			fgets(dataRecords[record_count].Choice3, sizeof(dataRecords[record_count].Choice3), fp);
			dataRecords[record_count].Choice3[strlen(dataRecords[record_count].Choice3) - 1] = '\0';


            fgets(dataRecords[record_count].Answer, sizeof(dataRecords[record_count].Answer), fp);
            dataRecords[record_count].Answer[strlen(dataRecords[record_count].Answer) - 1] = '\0';

            dataRecords[record_count].QuestionNum = question_number;
            record_count++;
        } 
        
		else 
		{
            strcpy(dataRecords[record_count].Topic, line);
        }
    }

    fclose(fp);

    *nData = record_count;
    printf("\n\n\n\n	Data Imported successfully... ");

    return 0;
}
/*
	Export data to a text file with the contents of the dataRecords array
	@param dataRecords - an array of struct dataGame containing all the records
	@param nData - a pointer to the number of records stored in the array
	@return  0 if the data is successfully imported, and 1 if there is an error opening the file or there are no records
*/
int exportData(struct dataGame dataRecords[], int *nData, char *filename) 
{ 
	int i;
	if (*nData == 0) {
        printf("	Cannot export data: no records found.\n");
        return 1;
    }
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("	Error: cannot create file\n");
        return 1;
    }

    for (i = 0; i < *nData; i++) 
	{
        // write topic if present
        if (strlen(dataRecords[i].Topic) > 0) {
            fprintf(fp, "%s\n", dataRecords[i].Topic);
        }

        // write question and choices
        fprintf(fp, "%d\n", dataRecords[i].QuestionNum);
        fprintf(fp, "%s\n", dataRecords[i].Question);
        fprintf(fp, "%s\n", dataRecords[i].Choice1);
        fprintf(fp, "%s\n", dataRecords[i].Choice2);
        fprintf(fp, "%s\n", dataRecords[i].Choice3);
        fprintf(fp, "%s\n", dataRecords[i].Answer);
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("	Data exported successfully to filename: %s.\n", filename);
    return 0;
}

/*
	Import data from a text file into the quizRecords array.
	@param dataRecords - an array of struct dataGame containing all the records
	@param nData - a pointer to the number of records stored in the array
	@param filename - filename of the exported txt file to be read
	@param quizRecords - an array of struct quizData containing all the records
	@return  0 if the data is successfully imported, and 1 if there is an error opening the file
*/
int importQuizData(struct dataGame dataRecords[], struct quizData quizRecords[], int *nData, char *filename) 
{
	int i;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }

     char line[100];
    int record_count = *nData;

    while (fgets(line, sizeof(line), fp)) 
	{
        if (line[strlen(line) - 1] == '\n') 
		{
            line[strlen(line) - 1] = '\0';
        }

        if (line[0] >= '0' && line[0] <= '9') 
		{
            int question_number = atoi(line);
            fgets(dataRecords[record_count].Question, sizeof(dataRecords[record_count].Question), fp);
            dataRecords[record_count].Question[strlen(dataRecords[record_count].Question) - 1] = '\0';

        	fgets(dataRecords[record_count].Choice1, sizeof(dataRecords[record_count].Choice1), fp);
			dataRecords[record_count].Choice1[strlen(dataRecords[record_count].Choice1) - 1] = '\0';
			
			fgets(dataRecords[record_count].Choice2, sizeof(dataRecords[record_count].Choice2), fp);
			dataRecords[record_count].Choice2[strlen(dataRecords[record_count].Choice2) - 1] = '\0';
			
			fgets(dataRecords[record_count].Choice3, sizeof(dataRecords[record_count].Choice3), fp);
			dataRecords[record_count].Choice3[strlen(dataRecords[record_count].Choice3) - 1] = '\0';


            fgets(dataRecords[record_count].Answer, sizeof(dataRecords[record_count].Answer), fp);
            dataRecords[record_count].Answer[strlen(dataRecords[record_count].Answer) - 1] = '\0';

            dataRecords[record_count].QuestionNum = question_number;
            record_count++;
        } 
        
		else 
		{
            strcpy(dataRecords[record_count].Topic, line);
        }
    }
    
    *nData = record_count;

    fclose(fp);

    for (i = 0; i < 100; i++) 
	{
        strcpy(quizRecords[i].Topic, dataRecords[i].Topic);
        quizRecords[i].QuestionNum = dataRecords[i].QuestionNum;
        strcpy(quizRecords[i].Question, dataRecords[i].Question);
        strcpy(quizRecords[i].Choice1, dataRecords[i].Choice1);
        strcpy(quizRecords[i].Choice2, dataRecords[i].Choice2);
        strcpy(quizRecords[i].Choice3, dataRecords[i].Choice3);
        strcpy(quizRecords[i].Answer, dataRecords[i].Answer);
    }

    return 0;
}

void displayQuiz(struct quizData quizRecords[], int nData)
{
	int i;
    printf("\n\t---RECORDS---\n"); 	// PRINT EACH RECORD
    for (i = 0; i < nData; i++)
    {
    	printf("\n\t---RECORD #%d---\n",i+1); 	// PRINT EACH RECORD
        printf("	Topic: %s\n", quizRecords[i].Topic);
        printf("	Question Num: %d\n", quizRecords[i].QuestionNum);
        printf("	Question: %s\n", quizRecords[i].Question);
        printf("	Choice #1: %s\n", quizRecords[i].Choice1);
        printf("	Choice #2: %s\n", quizRecords[i].Choice2);
        printf("	Choice #3: %s\n", quizRecords[i].Choice3);
        printf("	Answer: %s\n\n", quizRecords[i].Answer);
    }
}

void playQuiz(struct quizData quizRecords[], struct dataPlayer playerRecords[], int *nQuizData, int *nPlayer) 
{
	int i;
	system("cls");
    char answer[30];
    int answeredQuestions[100] = {0}; // initialize all to 0
    int numAnswered = 0; // keep track of how many questions have been answered
 	printf("\n\n");
    printf("	Please enter your name: ");
    scanf("%s", playerRecords[*nPlayer].playerName);
    playerRecords[*nPlayer].playerScore = 0;
    
    int gameEnded = 0;
    int allQuestionsAnswered = 0;
    while (!gameEnded && !allQuestionsAnswered) 
    {
    	system("cls");
        // Display available topics
        printf("\n\n");
        displayUniqueTopicsQuiz(quizRecords, nQuizData);
        printf("\n\n");
        int topicChoice = 0;
        printf("	Please choose a topic (enter the number): ");
        scanf("%d", &topicChoice);
    
        if (topicChoice < 1 || topicChoice > *nQuizData) 
        {
            printf("	Invalid topic choice.\n");
            return; // Exit the function if the choice is invalid
        }
        
        int topicQuestionsRemaining = 0;
        for (i = 0; i < *nQuizData; i++) 
        {
            if (strcmp(quizRecords[i].Topic, quizRecords[topicChoice - 1].Topic) == 0 && !answeredQuestions[i]) 
            {
                topicQuestionsRemaining++;
            }
        }
        
        if (topicQuestionsRemaining == 0) 
		{
            printf("	No questions remaining in this topic. Please select another topic.\n");
        } 
		else 
		{
            int questionAnswered = 0;
            
            while (!questionAnswered) 
            {
                // Find a random unanswered question from the chosen topic
                int randomIndex = rand() % *nQuizData;
                if (strcmp(quizRecords[randomIndex].Topic, quizRecords[topicChoice - 1].Topic) == 0 && !answeredQuestions[randomIndex]) 
                {
                    printf("	Question: %s\n", quizRecords[randomIndex].Question);
                    printf("	A:    %s\n", quizRecords[randomIndex].Choice1);
                    printf("	B:    %s\n", quizRecords[randomIndex].Choice2);
                    printf("	C:    %s\n", quizRecords[randomIndex].Choice3);
                    printf("	Answer: ");
                    scanf("%s", answer);
                    if (strcmp(answer, quizRecords[randomIndex].Answer) == 0) 
                    {
                        printf("	Correct, you gain one point!\n");
                        playerRecords[*nPlayer].playerScore = playerRecords[*nPlayer].playerScore + 1;
                        numAnswered++;
                        answeredQuestions[randomIndex] = 1;
                        questionAnswered = 1;
                    } 
					else 
					{
                        printf("	Incorrect. You can try again later!\n");
                        questionAnswered = 1; // Exit the inner loop
                    }
                    printf("    	Your current score is: %d\n", playerRecords[*nPlayer].playerScore);
                }
            }
        }
        
        allQuestionsAnswered = (numAnswered == *nQuizData);
        if (allQuestionsAnswered) 
        {
            printf("\n\n	Congratulations! You answered all questions.\n");
            gameEnded = 1;
        }
        
		printf("\n	Enter 'exit' to quit the game and save your score, or any other key to continue playing: ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) 
        {
        printf("	Exiting game...\n");
        gameEnded = 1;
  		}
    }
    (*nPlayer)++; // Update player
}

/*
viewScores reads player scores from a file, sorts them in descending order,
and displays the sorted scores on the screen.
@param playerRecords - an array of dataPlayer structures that holds player names and scores
@param nPlayer - the number of players in the playerRecords array
@return 0 if scores were successfully printed, 1 if no scores were found or there was an error opening the file
*/
int viewScores(struct dataPlayer playerRecords[], int *nPlayer) 
{
	int i;
	int j;
	
	system("cls");
	printf("\n\n");
   		 // Open the file in read mode
    FILE *fp = fopen("scores.txt", "r");
    if (fp == NULL) {
        printf("	Error: cannot open file\n");
        printf("	File not found!\n");
        return 1;
    }

   		 // Read the player names and scores from the file
    int record_count = *nPlayer;
    char line[100];
    while (fgets(line, sizeof(line), fp)) 
	{
        // Remove newline character from the end of the line
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') 
		{
            line[len-1] = '\0';
        }

        // Check if the line contains a player name
        if (strlen(line) > 0) {
            strcpy(playerRecords[record_count].playerName, line);
            // Read the next line containing the score
            if (fgets(line, sizeof(line), fp)) 
			{
                sscanf(line, "%d", &playerRecords[record_count].playerScore);
                record_count++;
            }
        }
    }

    	// Close the file
    fclose(fp);

    	// Update the number of players
    *nPlayer = record_count;

    	// Sort the scores in descending order using bubble sort
    for (i = 0; i < record_count-1; i++) 
	{
        for (j = 0; j < record_count-i-1; j++)
		 {
            if (playerRecords[j].playerScore < playerRecords[j+1].playerScore) 
			{
                struct dataPlayer temp = playerRecords[j];
                playerRecords[j] = playerRecords[j+1];
                playerRecords[j+1] = temp;
            }
        }
    }

   	// Print the scores if there are any
    if (record_count > 0) 
	{
        printf("	Player Name	Score\n");
        for (i = 0; i < record_count; i++) 
		{
            printf("	 %s		 %d\n", playerRecords[i].playerName, playerRecords[i].playerScore);
        }
        return 0;
    } 
	else 
	{
        printf("	No scores found.\n");
        return 1;
    }
}

/*
	exportScores function exports player scores to a file
	@param playerRecords - An array of dataPlayer structures containing player names and scores
	@param nPlayer - A pointer to the number of players in playerRecords
	@return 0 if the scores are successfully exported, otherwise 1
*/
int exportScores(struct dataPlayer playerRecords[], int *nPlayer) 
{
	int i;
    // Open the file in write mode
    FILE *fp = fopen("scores.txt", "w");
    if (fp == NULL) 
	{
        printf("	Error: The file cannot be created at the moment...\n");
        return 1;
    }

    // Write the player names and scores to the file
    for (i = 0; i < *nPlayer; i++) 
	{
        fprintf(fp, "%s\n	%d\n\n", playerRecords[i].playerName, playerRecords[i].playerScore);
    }

    // Close the file
    fclose(fp);
    return 0;
}

/*
	This function prompts the user for the admin password and checks if it is correct.
	@param None
	@return -1 if the password is incorrect, 1 if the password is correct
	
	Local Variables:
	password: character array used to store the password entered by the user
	maxAttempts: integer indicating the maximum number of attempts allowed to enter the password
	i: integer used for loop iteration
	passwordAccess: integer indicating whether the password is correct or not, initialized to false
	j: integer used for indexing password array
	ch: character used for getting input from user and hiding password input with asterisks
*/
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

void printScore(struct dataPlayer playerRecords[], int nPlayer) 
{
	int i;
    printf("Player scores:\n");
    for (i = 0; i < nPlayer; i++) 
	{
        printf("%s: %d\n", playerRecords[i].playerName, playerRecords[i].playerScore);
    }
}


int main()
{
    struct dataGame dataRecords[100]; // 100 STRUCTS OR 100 QUESTIONS FOR QUIZ GAME 
    struct quizData quizRecords[100];
    struct dataPlayer playerRecords[50];
    char returnMenu;                  // Y OR N IN ORDER TO RETURN TO MENU
    int menuOption;                   // MAIN MENU OPTIONS
    int DataMenu;                     // DATA MENU OPTIONS
    int dataPassword = -1;            // INITIALIZE TO INVALID VALUE SUCH AS -1 FIRST. THIS WILL MAKE SURE THAT 
                                      // WHEN THE USER WANTS TO ENTER THE PASSWORD AGAIN THEY WILL NOT BE ASKED TO ENTER THE PASSWORD
    int nData;
    int nQuizData;
    char addMore;
    char editMore;
    char deleteMore;
    char returnManage;
    int playerMenu;
    int nPlayer;

    do
    {
    	system("cls");
    	nQuizData = nData;
    	resetRecords(&nData);
        menuOption = displayMenu();
        switch(menuOption) 
        {
            case 1:
			    do
			    {
			        dataPassword = adminPassword(); // prompt user to enter password
			        if (dataPassword == 1)          // if password is correct
			        {
			            system("cls");
			            printf("\n\n");
			            printf("	Manage Data Menu!\n\n");
			            printf("	Enter a number to proceed!\n");
			            printf("	[1] Add Record!\n");
			            printf("	[2] Edit Records!\n");
			            printf("	[3] Delete Record!\n");
			            printf("	[4] Import Data!\n");
			            printf("	[5] Export Data\n");
			            printf("	[6] Return to Main Menu!\n\n");
			            printf("	Input Number Here: ");
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
		                      		system("cls");
		                      		DisplayRecords(dataRecords, nData); // Display all records after adding
		                            break;
		                        case 2:
		                        	
		                        	if (nData == 0) 
									{
										system("cls");
										printf("\n\n	Error!\n");
									    printf("	No records found.\n\n");
									} 
									else 
									{
									    do
										{
									        system("cls");
									        DisplayRecords(dataRecords, nData);
									        editRecords(dataRecords, &nData);
									        DisplayRecords(dataRecords, nData);
									        printf("\n	Do you want to edit more records? (y/n): ");
									        scanf(" %c", &editMore);
									    }while(editMore == 'Y' || editMore == 'y');
									system("cls");
									DisplayRecords(dataRecords, nData); // Display all records after editing
									}
									break;
		                        case 3: 
		                        	if (nData == 0) 
									{
										system("cls");
										printf("\n\n	Error!\n");
									    printf("	No records found.\n\n");
									} 
									else 
									{
										do
										{
											system("cls");
											DisplayRecords(dataRecords,nData);
				                            deleteRecords(dataRecords,&nData);
				                            DisplayRecords(dataRecords,nData);
				                            printf("\n	Do you want to delete more records? (y/n): ");
											scanf(" %c", &deleteMore);
										}while(deleteMore == 'Y' || deleteMore == 'y');
									system("cls");
									DisplayRecords(dataRecords, nData); // Display all records after deleting
		                       		}
		                            break;
		                          case 4:
		                        	system("cls");
									importData(dataRecords,&nData);
									system("cls");
									printf("\n\n	Data Imported successfully... \n\n\n");
									DisplayRecords(dataRecords, nData); // Display all records after deleting
		                            break;
		                       case 5:
								    {
								    char filename[31];
								    printf("\n	Enter the filename to export (up to 30 characters): ");
								    scanf("%30s", filename);
								    strcat(filename, ".txt");
								    exportData(dataRecords, &nData, filename);
								    resetRecords(&nData);
								    importQuizData(dataRecords,quizRecords, &nData, filename);
								    break;
								    }
		                        case 6:
		                        	printf("\n	Are you sure you want to exit?: ");
		                            break;
		                        default:
		                            printf("\n\tInvalid input! Please try again.\n");
		                            break;
		                    }
		                printf("\n	Return to Manage Data Menu?: ");
       					printf("\n	Entering [y] or [Y] will Return to Manage Data Menu!(y/n):  ");
       					scanf(" %c", &returnManage); 
       					}
	                }while(returnManage == 'y' || returnManage == 'Y');
	                
	        	break;
            case 2:
            	system("cls");
            	printf("\n\n");
                printf("	Welcome to the Quiz Game!\n\n");
			    printf("	[1] View Scores!\n");
			    printf("	[2] Proceed to game!\n");
			    printf("	[3] Exit!\n\n");
			    printf("	Input Number Here: ");
                scanf("%d", &playerMenu);

                switch(playerMenu)
                {
                	case 1:
                	viewScores(playerRecords,&nPlayer);
                	break;
                	
                	case 2:
                	system("cls");	
                	if (nQuizData == 0) 
					{
  				 		printf("	No Quiz Records Found.\n");
  				 		printf("	Please Export Data First.\n");
					}
					else
					{
						playQuiz(quizRecords, playerRecords, &nQuizData, &nPlayer);
					}
                	break;	
                	
                	case 3:
                		exportScores(playerRecords, &nPlayer);
                	break;
				}
                break;
            case 3:
                printf("\n	END PROGRAM\n");
                return 0;
                
            default:
                printf("\n	Invalid input! Please try again.\n");
                break;
        }
        
        printf("\n	Return to Main Menu?: ");
        printf("\n	Entering [n] will end the program");
        printf("\n	Entering [y] or [Y] will Return to Main Menu!(y/n): ");
        scanf(" %c", &returnMenu); 
    } while (returnMenu == 'y' || returnMenu == 'Y');
    
    printf("\n\tTerminating Program..... ");

    return 0;
}
