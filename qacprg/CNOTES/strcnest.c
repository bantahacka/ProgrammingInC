/* Structures and Unions -  Accessing Nested Data Structures             */

#include <stdio.h>

struct Date
{
	int day;
	int month;
	int year;
};

struct Student
{
	char name[30 + 1];
	struct Date birthday;
	char married_flag;
	struct Date enrolment_date;
	int exam_marks[10];
};

struct Student me =
	{
		"Jo Bloggs",
		{ 1, 1, 1960 },
		'N',
		{ 13, 12, 1992 },
		{ 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }
	};


int main(void)
{
	int i;

	me.married_flag = 'Y' ; /* Gets married */
	printf("First character is %c\n", me.name[0]);
	printf("Full name is %s\n", me.name);
	i = me.birthday.day;
	printf("Birthday is on day %d\n", i);

	i = me.enrolment_date.day;
	printf("Enrolment date is on day %d\n", i);

	for (i = 0; i < 10 ; i++)
		printf("Exam mark %d is %d\n", i + 1, me.exam_marks[i]);

    return 0;
}





