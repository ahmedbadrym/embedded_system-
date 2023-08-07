/*
 *

 *
 *  Created on: Aug
 5, 2023
 *      Author: THE GHOST
 */
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"conio.h"
#define Dprintf(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin); }
#define print printf("          ============================               \n");


int glopaltemp;
struct STUDENT
{int id;
char name[40];
  float heigth;
struct STUDENT* nextstudent;

};
struct STUDENT* gpfirststudent=NULL;
void add(){
	char x[50];

	//creating new member to put data to it
	struct STUDENT* newstudent;// here we declare it without actual meomery
	struct STUDENT* laststudent;
	//check empty
	if(!gpfirststudent)
	{newstudent= (struct STUDENT* ) malloc(sizeof(struct STUDENT));
	gpfirststudent=newstudent;
	}
	else{
		laststudent=gpfirststudent;
		//navigate until reach null
		while(laststudent->nextstudent){
			laststudent=laststudent->nextstudent;
		}
		newstudent= (struct STUDENT*) malloc(sizeof(struct STUDENT));
		laststudent->nextstudent=newstudent;

	}
	Dprintf("enter id:\n");
	gets(x);
	newstudent->id=atoi(x);
	Dprintf("enter name:\n");
	gets(newstudent->name);
	Dprintf("enter heigth:\n");
	gets(x);
	newstudent->heigth=atof(x);

	newstudent->nextstudent=NULL;

}
int delete()
	{


	int ID;
	Dprintf("enter id of the student :\n");
	scanf("%d",&ID);
	if(!gpfirststudent)
   printf("empty list\n");
   else
   {



	struct STUDENT* prev=NULL;
	struct STUDENT* selected= gpfirststudent;
	while(selected)
	{
		if(selected->id==ID)
		{
			if(prev)
			{
				prev->nextstudent=selected->nextstudent;
				free(selected);
				Dprintf("deleted successfully \n");

				return 1;
			}
			else
			{
				gpfirststudent=selected->nextstudent;
				free(selected);
				Dprintf("deleted successfully \n");

				return 1;
			}
		}


		prev=selected;
		selected=selected->nextstudent;
	}

	Dprintf("wrong id\n");
	return 0;
	}

															}
void view()
{
	int count=0;
	struct STUDENT* p;
	p=gpfirststudent;
	if(!gpfirststudent)
	{
	    print
		Dprintf("empty list\n");
		print
	}
	else
	{
		while(p)
		{
		   print
			Dprintf("student number %d\n",count+1);
			Dprintf("name is: %s\n",p->name);
			Dprintf("heigth: %f\n",p->heigth);
			Dprintf("id: %d\n",p->id);
			print
			p=p->nextstudent;
			count++;
		}
	}
}
void delete_all()
{
	struct STUDENT* temp;
	if(!gpfirststudent)
	{
		Dprintf("emopy list\n");
	}
	else
	{
		temp=gpfirststudent;
		gpfirststudent=gpfirststudent->nextstudent;
		free(temp);
	}
	gpfirststudent=NULL;
}
int index()
{
   struct STUDENT* pdy=gpfirststudent;
   int count=1,x;
   printf("enter the index u want to find\n");
   scanf("%d",&x);
   if(!gpfirststudent)
   printf("empty list\n");
   else
    {

   while(pdy)
   {
      if (count==x)
      {
      print
       printf("the  name for this node is:%s \n",pdy->name);
       print
       return 1;
      }
       else
       {
        pdy=pdy->nextstudent;
        count++;


       }

   }
  printf("there is no index matching\n");
    }
}
void Len()
{
    int* temp=&glopaltemp;
    struct STUDENT* l=gpfirststudent;
    int count=0;
     if(!gpfirststudent)
   printf("length is zero\n");
   else
   {
    while(l)
    {
    l=l->nextstudent;
        count++;
    }

    *temp=count;
    printf("length is: %d\n",count);
   }

}
int element_from_behind()
{
    struct STUDENT* x=gpfirststudent;
    struct STUDENT* y=gpfirststudent;
    int count;
     int count2=0;
     if(!gpfirststudent)
     {
        print
   printf("there is no elements \n");
      print
   return 1;
     }
    printf("enter the number of element frome behind \n");
    scanf("%d",&count);
     printf("to perform this proccess we must first  calculate length of linked list\n",glopaltemp);
     Len();
      if (count<=glopaltemp&&count!=0)
      {
    if(1)
   {

    while(y->nextstudent)
    {

    y=y->nextstudent;
    count2++;
    if(count2==count)
    {
    x=x->nextstudent;
    count++;
    }
    }
    print
    printf("element number %d from behind is: %s\n",count,x->name);
  print
     return 1;
   }

    }
    else
        printf("cant not proccessed\n");
         return 1;
}


void main()
{
	char h[10];
	while(1)
	{
		Dprintf("choose the option u want with a number\n");
		Dprintf(" to choose add student press 1 \n");
		Dprintf(" to choose delete student press 2 \n");
		Dprintf(" to choose delete all students press 3 \n");
		Dprintf(" to choose view all students press 4 \n");
		Dprintf(" to choose search for index  press 5 \n");
		Dprintf(" to choose detect length  press 6 \n");
		Dprintf(" to choose  find the element from behind press 7 \n");
		gets(h);
		switch(atoi(h))
		{
		case(1):
								add();
		break;
		case(2):
								delete();
		break;
		case(3):
								delete_all();
		break;
		case(4):
								view();
		break;
		case(5):
								index();
		break;
		case(6):
								Len();
		break;
		case(7):
								element_from_behind();
		break;
		}


	}
}



