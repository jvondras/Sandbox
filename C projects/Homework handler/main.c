#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Read in from file and put in stuct
//read out new data to homework.txt

struct homework
{
    char name[100];
    time_t due;
    char status[25];
};
int main()
{


struct homework assignments[50];
FILE* input;
input = fopen("homework.txt","r+");
char* token;
char buffer[100];
while(fgets(buffer,100,input) != NULL)
{
token = strtok(buffer,",");
    while(token)
    {

    }

}
int x = 0;

while(x == 0)
    {
     printf("TODO:\n");
     printf("=======================\n");

     printf("Completed:\n");
     printf("=======================\n");

     printf("1. Move assignment to complete\n");
     printf("2. Move assignment to TODO\n");
     printf("3. Change due date\n");
     printf("4. Remove completed assignments\n");
    }
}
