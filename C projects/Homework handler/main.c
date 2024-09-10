#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Read in from file and put in stuct
//read out new data to homework.txt

struct homework
{
    char class_name[100];
    char assignment_name[100];
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
    int array_number = 0;
    while(fgets(buffer,100,input) != NULL) //Begin reading in file
    {
        int count = 0;
        token = strtok(buffer,",");
            while(token)
            {
                if(count == 0) //Class name
                {
                    strcpy(assignments[array_number].class_name,token);
                    count++;
                    token = strtok(NULL,",");
                }
                else if(count == 1) //assignment name
                {
                    strcpy(assignments[array_number].assignment_name,token);
                    count++;
                    token = strtok(NULL,",");
                }
                else if(count == 2) //Due date
                {
                    char* time_token;
                    time_token = strtok(token,"/");
                    struct tm time;
                    int time_count = 0;
                    while(time_token)
                    {
                        if(time_count == 0)
                        {
                            time.tm_mon = atoi(time_token);
                            time_token = strtok(NULL,"/");
                            time_count++;
                        }
                        else if(time_count == 1)
                        {
                            time.tm_mday = atoi(time_token);
                            time_token = strtok(NULL,"/");
                            time_count++;
                        }
                        else if(time_count == 2)
                        {
                            time.tm_year = atoi(time_token);
                            time_token = strtok(NULL,"/");
                            time_count++;
                        }
                        else if(time_count == 3)
                        {
                            time.tm_hour = atoi(time_token);
                            time_token = strtok(NULL,"/");
                            time_count++;
                        }

                    }
                    assignments[array_number].due = mktime(&time);

                    count++;
                    printf("Token before moving on: %s\n",token);
                    token = strtok(NULL,",");
                    printf("Token after moving on: %s\n",token);
                }
                else if(count == 3) //status
                {
                    printf("HELLO");
                    strcpy(assignments[array_number].status,token);
                    count++;
                    token = strtok(NULL,",");

                }

            }
            array_number++;

    }

    int x = 0;
    char menu_input[10];
    while(x == 0) //Begin main loop
        {
             printf("TODO:\n");
             printf("=======================\n");
             for(int i = 0; i < array_number; i++)
             {
                if(strncmp(assignments[i].status,"TODO",4) == 0)
                {
                    printf("%s",assignments[i].assignment_name);
                }
             }

             printf("Completed:\n");
             printf("=======================\n");
             for(int j = 0; j < array_number; j++)
             {
                if(strncmp(assignments[j].status,"Completed",4) == 0)
                {

                }
             }

             printf("1. Move assignment to complete\n");
             printf("2. Move assignment to TODO\n");
             printf("3. Change due date\n");
             printf("4. Remove completed assignments\n");

             fgets(menu_input,10,stdin);

             if(menu_input == 1)
             {

             }
             else if(menu_input == 2)
             {

             }
             else if(menu_input == 3)
             {

             }
             else if(menu_input == 4)
             {

             }
        }
}
