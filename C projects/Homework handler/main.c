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
    char* end_str;
    char buffer[100];
    int array_number = 0;
    int line_count = 0;
    while(fgets(buffer,100,input) != NULL) //Begin reading in file
    {
        line_count++;
        int count = 0;
        token = strtok_r(buffer,",",&end_str);
            while(token)
            {
                char* end_tok;
                if(count == 0) //Class name
                {
                    strcpy(assignments[array_number].class_name,token);
                }
                else if(count == 1) //assignment name
                {
                    strcpy(assignments[array_number].assignment_name,token);
                }
                else if(count == 2) //Due date
                {
                    char* time_token;
                    time_token = strtok_r(token,"/",&end_tok);
                    struct tm time;
                    memset(&time, 0, sizeof(struct tm));
                    time.tm_sec = 0;
                    time.tm_min = 0;
                    int time_count = 0;
                    while(time_token)
                    {
                        if(time_count == 0)
                        {
                            time.tm_mon = atoi(time_token) - 1;
                        }
                        else if(time_count == 1)
                        {
                            time.tm_mday = atoi(time_token);
                        }
                        else if(time_count == 2)
                        {
                            time.tm_year = atoi(time_token) - 1900;
                        }
                        else if(time_count == 3)
                        {
                            time.tm_hour = atoi(time_token);
                        }
                        time_token = strtok_r(NULL,"/",&end_tok);
                        time_count++;

                    }
                    assignments[array_number].due = mktime(&time);
                }
                else if(count == 3) //status
                {
                    strcpy(assignments[array_number].status,token);
                }
                count++;
                token = strtok_r(NULL,",",&end_str);
            }
            array_number++;
    }
    int x = 0;
    char menu_input[10];
    while(x == 0) //Begin main loop
        {
             printf("To-do:\n");
             printf("=======================\n");
             for(int i = 0; i < line_count; i++)
             {
                if(strcmp(assignments[i].status,"todo\n") == 0)
                {
                    printf("%s\t %s\t Due: %s\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                }
             }
             printf("\n\n");

             printf("Completed:\n");
             printf("=======================\n");
                for(int i = 0; i < line_count; i++)
             {
                if(strcmp(assignments[i].status,"completed\n") == 0)
                {
                    printf("%s\t %s\t Due: %s\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                }
             }
             printf("\n\n");



             printf("1. Move assignment to complete\n");
             printf("2. Move assignment to TODO\n");
             printf("3. Change due date\n");
             printf("4. Remove completed assignments\n");

             fgets(menu_input,10,stdin);

             if(atoi(menu_input) == 1)
             {

             }
             else if(atoi(menu_input) == 2)
             {

             }
             else if(atoi(menu_input) == 3)
             {

             }
             else if(atoi(menu_input) == 4)
             {

             }
        }
        fclose(input);
        return 0;
}
