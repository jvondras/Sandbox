#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Read in from file and put in stuct
//read out new data to homework.txt

struct homework
{
    char class_name[256];
    char assignment_name[256];
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
    char buffer[256];
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
                            time.tm_hour = atoi(time_token) - 1;
                        }
                        else if(time_count == 4)
                        {
                            time.tm_min = atoi(time_token);
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
    time_t current_time;
    while(x == 0) //Begin main loop
        {
            time(&current_time);
            printf("Current Time: %s\n\n",ctime(&current_time));
             printf("To-do:\n");
             printf("=======================\n");
             for(int i = 0; i < line_count; i++)
             {
                if(strcmp(assignments[i].status,"todo\n") == 0)
                {
                    if(difftime(assignments[i].due,current_time) > 604800)
                    {
                        printf("%s\t %s\t\t Due: \033[0;32m%s\033[0m\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                    }
                    else if((difftime(assignments[i].due,current_time) > 86400) && (difftime(assignments[i].due,current_time) < 604800))
                    {
                        printf("%s\t %s\t\t Due: \033[0;33m%s!\033[0m\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                    }
                    else if(difftime(assignments[i].due,current_time) < 86400)
                    {
                        printf("%s\t %s\t\t Due: \033[0;31m%s!!\033[0m\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                    }

                }
             }
             printf("\n\n");

             printf("Completed:\n");
             printf("=======================\n");
                for(int i = 0; i < line_count; i++)
             {
                if(strcmp(assignments[i].status,"completed\n") == 0)
                {
                    printf("%s\t %s\t\t Due: %s\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));

                }
             }
             printf("\n\n");



             printf("1. Move assignment to completed\n");
             printf("2. Move assignment to TODO\n");
             printf("3. Change due date\n");
             printf("4. Remove completed assignments\n");

             fgets(menu_input,10,stdin);

             if(atoi(menu_input) == 1)
             {
                char search[50];
                int found = 0;
                printf("Enter Assignment Name: \n");
                fgets(search,50,stdin);
                for(int i = 0; i < line_count;i++)
                {
                    if(strncmp(search,assignments[i].assignment_name,strlen(assignments[i].assignment_name)) == 0)
                    {
                        strcpy(assignments[i].status,"completed\n");
                        found = 1;
                    }

                }
                if(found != 1)
                {
                    printf("Match not found!\n");
                }
             }
             else if(atoi(menu_input) == 2)
             {
                 char search[50];
                int found = 0;
                printf("Enter Assignment Name: \n");
                fgets(search,50,stdin);
                for(int i = 0; i < line_count;i++)
                {
                    if(strncmp(search,assignments[i].assignment_name,strlen(assignments[i].assignment_name)) == 0)
                    {
                        strcpy(assignments[i].status,"todo\n");
                        found = 1;
                    }

                }
                if(found != 1)
                {
                    printf("Match not found!\n");
                }
             }
             else if(atoi(menu_input) == 3)
             {
                 char search[50];
                int found = 0;
                printf("Enter Assignment Name: \n");
                fgets(search,50,stdin);
                for(int i = 0; i < line_count;i++)
                {
                    if(strncmp(search,assignments[i].assignment_name,strlen(assignments[i].assignment_name)) == 0)
                    {
                        //Change time information here
                    }

                }
                if(found != 1)
                {
                    printf("Match not found!\n");
                }
             }
             else if(atoi(menu_input) == 4)
             {

             }
        }
        fclose(input);
        return 0;
}
