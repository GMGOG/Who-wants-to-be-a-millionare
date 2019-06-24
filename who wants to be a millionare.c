#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QUESTIONS 7

//function prototypes

void promptPlayerForName (char [50]);
void printWelcomeMessage (char  [50]);
int  calculateCurrentAward (int ,int);
void popUpCurrentQuestion4choices (int);
char askPlayerForLifeLine (void);
void popUpCurrentQuestion2choices (int);
char acceptPlayersFinalAnswer (void);
bool isCorrectFinalAnswer (char, int, char [MAX_QUESTIONS]);
void generateRandomGreeting (char [20]);
int calculateReducedAward (int, int);

int main(){

    char allCorrectAnswers [MAX_QUESTIONS + 1] = "CBCBACA";   // for my set of questions
    char greet [20];
    char nameForGame[50];
    int lifeLineUsed = 0;
    int questionNumber = 1;
    char playersResponseLifeLine;
    char finalAnswer;
    int currentAwardAmount ;
    int reducedAmount;

    promptPlayerForName(nameForGame);

    printWelcomeMessage(nameForGame);

    while (questionNumber <= MAX_QUESTIONS)
    {

        currentAwardAmount = calculateCurrentAward(questionNumber, currentAwardAmount);

        popUpCurrentQuestion4choices(currentAwardAmount);

        if (lifeLineUsed == 0)
        {
            playersResponseLifeLine = askPlayerForLifeLine();

            if (playersResponseLifeLine == 'Y' || playersResponseLifeLine == 'y')
            {

                popUpCurrentQuestion2choices(currentAwardAmount);
                lifeLineUsed ++;
                printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
            }
        }

        finalAnswer = acceptPlayersFinalAnswer ();

        if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers) )
        {

            generateRandomGreeting(greet);
            printf("%s - You just won $ %d\n", greet, currentAwardAmount);

            if (questionNumber <= MAX_QUESTIONS)
            {
                printf("Let us play the next question now\n\n");
            }
        }

        else {
            printf  ("Oops - that was incorrect.");

            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

            printf("You still won %d. Well done.\n\n", reducedAmount);

            questionNumber = MAX_QUESTIONS;
        }
        questionNumber ++;
    }

    printf("It was fun playing with you \n\n");

    return 0;

}
void promptPlayerForName (char fullName[50])
{   char last[25];
    printf("Enter your first name: ");
    scanf("%s",fullName);
    printf("Enter your last name: ");
    scanf("%s",last);
    strcat(fullName," ");
    strcat(fullName,last);
}
void printWelcomeMessage(char fullName[50])
{
    printf("*\n**\n***\n");
    for(int i=0;i<strlen(fullName)+8;i++)
        printf("*");
    printf("\nWelcome ");
    puts(fullName);
    printf("Let us play WDWM!\n");
    for(int i=0;i<strlen(fullName)+8;i++)
        printf("*");
    printf("\n***\n**\n*");
}
int calculateCurrentAward(int questionNumber, int awardPreviousQuestion)
{
    switch(questionNumber)
    {
        case 1: return 100;break;
        case 2: return 500;break;
        case 3: return 1000;break;
        case 4: return 5000;break;
        case 5: return 10000;break;
        case 6: return 50000;break;
        case 7: return 100000;break;
    }
  
}
void popUpCurrentQuestion4choices (int currentAwardAmount)
{
    switch(currentAwardAmount) {
        case 100:{
            printf("\n1. Which of the following programming language is taught in CIS1500 at the University of Guelph?\n"
                   "A. Python          B. Cobra \n"
                   "C. C               D. Java");

            break;}
        case 500:{
            printf("\n2. Which Canadian chain first opened in Hamilton in 1964?\n"
                   "A. McDonalds       B. Tim Hortons \n"
                   "C. Wendys          D. Mr. Sub ");

            break;}
        case 1000:{
            printf("\n3. What is Canada's national sport? \n"
                   "A. Hockey                   B. Lacrosse \n"
                   "C. Hockey and Lacrosse      D. Baseball");

            break;}
        case 5000:{
            printf(
                   "\n"
                   "4. Which Canadian city ranks as the most educated in the country?\n"
                   "A. Montreal           B. Ottawa \n"
                   "C. Vancouver          D. Toronto");

            break;}
        case 10000:{
            printf("\n"
                   "5. What is Canada's highest mountain?\n"
                   "A. Mount Logan, Yukon         B. Whistler Mountain, BC \n"
                   "C. Mont Tremblant, Quebec     D. Tip Top Mountain, Ontario");

            break;}
        case 50000:{
            printf("\n"
                   "6. What is the easternmost province of Canada? \n"
                   "A. Ontario             B. Prince Edward Island\n"
                   "C. Newfoundland        D. Nova Scotia ");

            break;}
        case 100000:{
            printf("\n"
                   "7. The southernmost point of mainland Canada is called Point Pelee. What province is it in? \n"
                   "A. Ontario              B. Quebec\n"
                   "C. Newfoundland         D. Nova Scotia ");

            break;}
    }
}
char askPlayerForLifeLine(void)
{   char C;
    printf("\nWould you like to use a lifeline (50 – 50)?\n"
           "Enter Y or y, N or n:");
    scanf(" %c",&C);
     while(C!='y'&& C!='Y'&& C!='n'&& C!='N')
    {
        
	printf("\nInvalid Answer.\nEnter valid Answer\n C Equals %c", C);
        scanf(" %c",&C);
    }
    return C;
}
void popUpCurrentQuestion2choices (int currentAwardAmount)
{
    switch(currentAwardAmount) {
        case 100: {
            printf("\n1. Which of the following programming language is taught in CIS1500 at the University of Guelph?\n"
                   "A. Python\n"
                   "C. C\n");
        }
            break;
        case 500: {
            printf("\n"
                   "2. Which Canadian chain first opened in Hamilton in 1964?\n"
                   "A. McDonalds \n"  
                    "B. Tim Hortons \n");
        }
            break;
        case 1000: {
            printf("\n3. What is Canada's national sport? \n"
                   "A. Hockey \n"
                   "C. Hockey and Lacrosse\n");
        }
            break;
        case 5000: {
            printf("\n"
                   "4. Which Canadian city ranks as the most educated in the country?\n"
                   "B. Ottawa \n"
                   "D. Toronto\n");
        }
            break;
        case 10000: {
            printf("\n"
                   "5. What is Canada's highest mountain?\n"
                   "A. Mount Logan, Yukon\n"
                   "C. Mont Tremblant, Quebec");
        }
            break;
        case 50000: {
            printf("\n"
                   "6. What is the easternmost province of Canada? \n"
                   "A. Ontario\n"
                   "C. Newfoundland\n");
        }
            break;
        case 100000: {
            printf("\n"
                   "7. The southernmost point of mainland Canada is called Point Pelee. What province is it in? \n"
                   "A. Ontario\n"
                   "C. Newfoundland\n");
        }
            break;
    }
}
char acceptPlayersFinalAnswer(void)
{
    char A;
    printf("\nEnter the final answer: ");
    scanf(" %c",&A);
    while(A!='A'&& A!='B'&& A!='C'&& A!='D')
    {
        printf("\nInvalid Answer.\nEnter valid Answer");
        scanf(" %c",&A);
    }
    return A;
}
bool isCorrectFinalAnswer (char finalAnswer, int questionNumber, char allCorrectAnswers[MAX_QUESTIONS])
{
    if(finalAnswer==allCorrectAnswers[questionNumber-1])
        return 1;
    else
        return 0;
}
void generateRandomGreeting (char greet[20])
{
    int ran;
    ran = rand()%(5);
    switch(ran)
    {
        case 1:  printf("Bravo");break;
        case 2:  printf("Congrats");break;
        case 3:  printf("Well done");break;
        case 4:  printf("Very nice");break;
        case 5:  printf("Proud of you");break;
    }
}
int calculateReducedAward (int questionNumber, int currentAwardAmount)
{
    if(questionNumber%2==0)
    {
        currentAwardAmount=currentAwardAmount/5;
    }
    else
    {
        currentAwardAmount=currentAwardAmount/2;
    }
    return currentAwardAmount;
}



