#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct student
{
 char name[3];
 int arrival;
 int burst;
 int wait;
 int turnaround;
};

struct faculty
{
 char name[3];
 int arrival;
 int burst;
 int wait;
 int turnaround;
};

int main()
{
 system("clear");
 int m,n,queryTime=0;
 printf("total student queries : ");
 scanf("%d", &m);
 struct student s[m];
 printf("total faculty queries : ");
 scanf("%d", &n);
 struct faculty f[n];
 int i;
 for(i=0; i<m; i++)
 {
  printf("\nSudhesh will login bet 10am - 12am (that is 840 mins)\nOnly queries with arrival time less than 840 can be resolved\n");
  printf("\nStudent query no. %d (S%d)\n-----------------\n", i+1, i+1);
  sprintf(s[i].name, "S%d", i+1);
  printf("arrival time : ");
  scanf("%d", &(s[i].arrival));
  printf("query duration (burst time) : ");
  scanf("%d", &(s[i].burst));
  system("clear");
  printf("\nsudhesh will login bet 10am - 12am (that is 840 mins)\n");
  printf("\n\t\t\tStudent\n\t\t\t--------\n\n");
  printf("Query\t\tBurst Time\t\tArrival Time\n");
  printf("-----\t\t----------\t\t------------\n");
  int j;
  for(j=0; j<=i; j++)
  {
   printf(" %s  \t\t    %d    \t\t     %d    \n", s[j].name, s[j].burst, s[j].arrival);
  }
 }

 for(i=0; i<n; i++)
 {
  printf("\n\nFaculty query no. %d (F%d)\n-----------------\n", i+1, i+1);
  sprintf(f[i].name, "F%d", i+1);
  printf("arrival time : ");
  scanf("%d", &(f[i].arrival));
  printf("query duration (burst time) : ");
  scanf("%d", &(f[i].burst));
  system("clear");
  printf("\n\t\t\tStudent\n\t\t\t--------\n\n");
  printf("Query\t\tBurst Time\t\tArrival Time\n");
  printf("-----\t\t----------\t\t------------\n");
  int j;
  for(j=0; j<m; j++)
  {
   printf(" %s  \t\t    %d    \t\t     %d    \n", s[j].name, s[j].burst, s[j].arrival);
  }
  printf("\n\t\t\tFaculty\n\t\t\t--------\n\n");
  printf("Query\t\tBurst Time\t\tArrival Time\n");
  printf("-----\t\t----------\t\t------------\n");
  for(j=0; j<=i; j++)
  {
   printf(" %s  \t\t    %d    \t\t     %d    \n", f[j].name, f[j].burst, f[j].arrival);
  }
 }

 for(i=m-1; i>0; i--)
 {
  int j;
  for(j=0; j<i; j++)
  {
   if(s[j].arrival>s[j+1].arrival)
   {
    struct student temp;
    temp=s[j];
    s[j]=s[j+1];
    s[j+1]=temp;
   }
  }
 }

 for(i=n-1; i>0; i--)
 {

  int j;
  for(j=0; j<i; j++)
  {

   if(f[j].arrival>f[j+1].arrival)
   {
    struct faculty temp;
    temp=f[j];
    f[j]=f[j+1];
    f[j+1]=temp;
   }

  }

 }

 int sumS=0, sumF=0;
 system("clear");

 printf("\n\t\t\tStudent\n\t\t\t--------\n\n");
 printf("Query\t\tBurst Time\t\tArrival Time\n");
 printf("-----\t\t----------\t\t------------\n");
 int j;
 for(j=0; j<m; j++)
 {
  printf(" %s  \t\t    %d    \t\t     %d    \n", s[j].name, s[j].burst, s[j].arrival);
  sumS=sumS+s[j].burst;
 }
 printf("\n\t\t\tFaculty\n\t\t\t--------\n\n");
 printf("Query\t\tBurst Time\t\tArrival Time\n");
 printf("-----\t\t----------\t\t------------\n");
 for(j=0; j<n; j++)
 {
  printf(" %s  \t\t    %d    \t\t     %d    \n", f[j].name, f[j].burst, f[j].arrival);
  sumF=sumF+f[j].burst;
 }

 printf("sumS = %d\nsumF = %d", sumS, sumF);
 int time=0, q=-1, countq=0, count=0;
 while(time<840 && (sumS!=0 || sumF!=0))
 {
  if(m!=0 || n!=0)
  while(q==-1)
  {
   if(f[0].arrival<=time)
   {
    q=1;
   }
   while(f[0].arrival>time && s[0].arrival<=time)
   {
	int done=0;
	if(s[0].burst==0)
	{
	 done=1;
	}
	if(s[0].arrival<=time && s[0].burst!=0)
	{
	 printf("\n(%d - ", time);
	}
	count=0;
    while(count!=4 && time!=120 && f[0].arrival>time && sumS!=0 && s[0].burst!=0)		//execute until faculty is not available or until its time to switch to other
    {
	 queryTime++;
     s[0].burst--;
     sumS--;
     count++;
     time++;
    }
    if(s[0].arrival<=time)
    {
	 if(done==0)
	 {
	  sleep(1);
	  printf("%d)\t\t%s\n", time, s[0].name);
	 }
	 done=1;
     int k;
     struct student temp;
     temp=s[0];
     for(k=0; k<m-1; k++)
     {
      s[k]=s[k+1];
     }
     s[m-1]=temp;
    }
    if(sumS==0 && f[0].arrival>840)
    {
	 break;
    }
    while(f[0].arrival>time)
    {
     time++;
    }
   }
   
  }

  if(n!=0)
  while(q==1)
  {
   countq=0;
   while(countq<10)
   {
	int done=0;
	if(f[0].burst==0)
	{
	 done=1;
	}
	if(f[0].arrival<=time && f[0].burst!=0)
	{
	 printf("\n(%d - ", time);
	}
	count=0;
    while(countq<10 && count<4 && f[0].arrival<=time && time<120 && sumF!=0 && f[0].burst!=0)
    {
	 queryTime++;
     count++;
     countq++;
     time++;
     sumF--;
     f[0].burst--;
    }
	if(f[0].arrival<=time)											//if faculty is available or not
	{
	 if(done==0)
	 {
	  sleep(1);
	  printf("%d)\t\t%s\n", time, f[0].name);
	 }
	 done=1;
     int k;
     struct faculty temp;
     temp=f[0];
     for(k=0; k<n-1; k++)
     {
      f[k]=f[k+1];
     }
     f[n-1]=temp;
	}
	if(f[0].arrival>time && s[0].arrival<=time)									//if faculty not available but student available
    {
     break;
    }
	while((f[0].arrival>time || sumF==0)&& s[0].arrival>time && countq<10)		//if faculty not available and student not available
    {
     time++;
     countq++;
    }
	if(sumF==0)
	{
	 break;
	}
   }
   if(sumF==0 && sumS==0)
   {
	break;
   }
   q=0;
  }

  if(m!=0)
  while(q==0)
  {
   countq=0;
   while(countq<10)
   {
	int done=0;
	if(s[0].burst==0)
	{
	 done=1;
	}
	if(s[0].arrival<=time && s[0].burst!=0)
	{
	 printf("\n(%d - ", time);
	}
	count=0;
    while(countq<10 && count<4 && time<120 && sumS!=0 && s[0].burst!=0 && s[0].arrival<=time)
    {
	 queryTime++;
     count++;
     countq++;
     time++;
     sumS--;
     s[0].burst--;
    }
	if(s[0].arrival<=time)
	{
	 if(done==0)
	 {
	  sleep(1);
	  printf("%d)\t\t%s\n", time, s[0].name);
	 }
	 done=1;
	 int k;
     struct student temp;
     temp=s[0];
     for(k=0; k<m-1; k++)
     {
      s[k]=s[k+1];
     }
     s[m-1]=temp;
	}
	if(s[0].arrival>time && f[0].arrival<=time)									//if student not available but faculty available
    {
     break;
    }
    while((s[0].arrival>time || sumS==0) && f[0].arrival>time && countq<10)		//if student not available and faculty not available
    {
     time++;
     countq++;
    }
	if(sumS==0)
	{
	 break;
	}	
   }
   if(sumS==0 && sumF==0)
   {
	break;
   }
   q=1;
  }
 }
 /*printf("\n\t\t\tStudent\n\t\t\t--------\n\n");
 printf("Query\t\tBurst Time\t\tArrival Time\n");
 printf("-----\t\t----------\t\t------------\n");
 for(j=0; j<m; j++)
 {
  printf(" %s  \t\t    %d    \t\t     %d    \n", s[j].name, s[j].burst, s[j].arrival);
 }
 printf("\n\t\t\tFaculty\n\t\t\t--------\n\n");
 printf("Query\t\tBurst Time\t\tArrival Time\n");
 printf("-----\t\t----------\t\t------------\n");
 for(j=0; j<n; j++)
 {
  printf(" %s  \t\t    %d    \t\t     %d    \n", f[j].name, f[j].burst, f[j].arrival);
 }*/
 if(m==0 && n==0)
 printf("\nno queries today\n");
 else
 printf("\nFinal time at the end = %d mins\nTime spent in handling query = %d mins\nAverage time on each query = %.2f mins\n", time, queryTime, (float)(queryTime/(m+n)));
}


