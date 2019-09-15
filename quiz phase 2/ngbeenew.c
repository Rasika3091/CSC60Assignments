#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "md5.c"


int loginUser(){
  char userID[16]  ;
  char calculatedMD5[33] ;
  char name[10], md5[33];
  FILE *fp;

  printf ( "Please enter a user id \n");
  scanf ( "%s", userID );


  int i, j;
  MDStringVersion2 ( userID,  calculatedMD5  ) ;
   
  char buffer[255];
  char *result;
  result = NULL;
  fp = fopen("md5.data", "r");
  while(fgets(buffer, 255, (FILE*) fp)) {
  result = strstr(buffer, calculatedMD5);
    if (result != NULL) {
       printf("\n Login successful !! \n");
       return 1;
       break;
    }     
  }

  fclose(fp);  
  
  if(result == NULL) {
    printf("\n Login unsuccessful !! \n");
    return 0;
  }
}

struct _question {
        char question [ 1024 ] ;
        char answer1 [128 ] ;
        char answer2 [128 ] ;
        char answer3 [128 ] ;
        char answer4 [128 ] ;
        int correctAnswer ;
        int userTypedAnswer ;
}   ;

int ngbee(){
	struct _question questionSet[5];
	 FILE *fp;
	 char buffer[255];
	 char *result;
	 result = NULL;
	 fp = fopen("questions.txt", "r");
	 int i,j;

	 for(i=0;i<5;i++) {
 		 for(j=0;j<6;j++){
  			 fgets(buffer, 255, (FILE*) fp);
        
      			 switch(j){
         			 case 0 :
                		 strcpy(questionSet[i].question,buffer);
                		 break;
         			 case 1 :
                		 strcpy(questionSet[i].answer1,buffer);
                		 break;
         			 case 2 :
                		 strcpy(questionSet[i].answer2,buffer);
                		 break;
         			 case 3 :
                		 strcpy(questionSet[i].answer3,buffer);
                		 break;
         			 case 4 :
                		 strcpy(questionSet[i].answer4,buffer);
                		 break;
         			 case 5 :
                		 questionSet[i].correctAnswer = (buffer[0] - '0');  //convert to integer 
                		 break;
      		 	}
 	 	}
	 }
 
 int totalScore = 0;
 for(i=0;i<5;i++)
 {
    
    printf(" \n\n Question : %s", questionSet[i].question);
    printf(" \n %s", questionSet[i].answer1);
    printf(" \n %s", questionSet[i].answer2);
    printf(" \n %s", questionSet[i].answer3);
    printf(" \n %s", questionSet[i].answer4);
 
    printf(" \n Please enter 1,2,3 or 4 : \n");
    scanf("%d", &questionSet[i].userTypedAnswer);

    if (questionSet[i].userTypedAnswer == questionSet[i].correctAnswer) {
        totalScore++;
        printf("\n Correct. Your current score is %d",totalScore);
    } else {
        printf("\n Sorry. The correct answer is %d",questionSet[i].correctAnswer);
    }
 }

 printf("\nThank you for taking the test!!\n");
 return totalScore;
}


int main ( )
{
	int login = loginUser();
        if(login == 1){ // if login successful start with quiz
           printf("\n Lets start with the NGBEE QUIZ :: \n");
           int totalscore = ngbee();

           char subj[64] = "Results of NGBEE ";
           char emailaddress[64] = "rasikakulkarni@csus.edu" ;
           char body[1024] = "You performed fantastic in Nat Geo Bee. Your total score is : ";
           char totalscorebuf[12];
           sprintf(totalscorebuf, "%d", totalscore);

           strcat(body, totalscorebuf);
           printf("%s",body);
           // send email to user
           execlp ( "./mail_script.sh",
                    "mail_script.sh",
                    subj,
                    emailaddress,
                    body,
                    NULL );          
        }
}

