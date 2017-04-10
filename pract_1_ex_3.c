#include <stdio.h>

 const int ENDSEQ = 0;
 const int NO_SUBJECT = -1;
 const float NO_PERCENTAGE = 0.0;
 typedef enum {FALSE,TRUE} bool;
 
 void readSubject ( int idSubject, int idStudent);
 void processStudent (int idStudent,float *studentMark,float *bestMark, bool *found);


int main(int argc, char **argv)
{
	int idStudent, idSubject, idChair;
	
	scanf("%d", &idStudent);
	scanf("%d", &idChair);
	scanf("%d", &idSubject);
	
	
	while (idSubject != ENDSEQ) {
		readSubject (idSubject, idStudent);
		scanf("%d", &idSubject);
		}
	printf("%c", ' ');
    printf("%d", ENDSEQ);


	return 0;
}

void readSubject ( int idSubject, int idStudent ){

int numStudents,K;
float studentMark,bestMark,Mmark;
bool found;

found=FALSE;
bestMark=0;

scanf("%d", &numStudents);
printf ("%d", idSubject);
printf("%c", ' ');
K=1;
while (K<=numStudents){
		processStudent (idStudent, &studentMark, &bestMark, &found);
		K=K+1;
}

if (found==TRUE) {
	printf("%.2f", studentMark);
	Mmark=100.0*studentMark/bestMark;
	printf("%c", ' ');
    printf("%.2f", Mmark);
	printf("%c", ' ');}

else
{

printf("%d", NO_SUBJECT);
printf("%c", ' ');
printf("%.2f", NO_PERCENTAGE);	
}
}

void processStudent (int idStudent,float *studentMark,float *bestMark, bool *found){
	int id;
	float marks;

scanf("%d", &id);
scanf("%f", &marks);
if (id == idStudent){
*found=TRUE;
*studentMark= marks;
	}
else if (marks > bestMark){
	*bestMark=marks;
}
}



