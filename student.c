#include <stdio.h>
#include <stdlib.h>

#define max_student 2
#define total_sub 5

typedef struct{
    char name[25];
    int age;
    double subject[5];
    double percent;
    double avg;
}student;


int main(void)
{
    student stu[max_student];
    double total_marks=0;
    double sub_avg[5];
    int i,j;

    for (int i = 0; i < max_student; i++)
    {
        total_marks = 0;
        printf("\nEnter student %d name: ",i+1);
        scanf("%s", stu[i].name);
        printf("\nEnter the student %d age: ",i+1);
        scanf("%d", &stu[i].age);
        printf("Enter marks of 5 subjects:\n");
        for (int j = 0; j < total_sub; j++)
        {
            scanf("%lf", &stu[i].subject[j]);
            total_marks += stu[i].subject[j];
        }

        // Calculating average and percent
        stu[i].avg = total_marks/total_sub;
        stu[i].percent = (total_marks/(total_sub*100))*100;
        printf("\n");
    }

    // Display Student details
    for(i=0; i<max_student; i++)
    {
        printf("\n\t\t\tDetails of student no. %d\n",i+1);
        printf("\nName: %s ",stu[i].name);
        printf("\nAge: %d",stu[i].age);
        printf("\nSubject Marks:\n");
        for(int sub = 0; sub < total_sub; sub++)
        {
            printf("%.2lf\t",stu[i].subject[sub]);
        }
        // printf("\nAverage marks: %.2lf",stu[i].avg);   
        printf("\nPercentage Scored: %.2lf %%\n",stu[i].percent);   
    }

    // Calculate the average marks of paticular subject
    for(int sub = 0; sub < total_sub; sub++)
    {
        total_marks = 0;
        for(int i=0; i<max_student; i++)
        {
            total_marks += stu[i].subject[sub];
        }
        sub_avg[sub] = total_marks/max_student;
    }

    printf("\n\t\tAverage subject marks of whole class:\n");
    for(int sub=0; sub<total_sub; sub++)
    {
        printf("Subject %d: %.2lf\n",sub+1,sub_avg[sub]);
    }

	
	return 0;
}