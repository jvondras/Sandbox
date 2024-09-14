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
time_t atot(char ascii_time[20])
{
//String Format YYYY-MM-DDThh:mm:ss where T is a delimiter
//              0123456789ABCDEFGHI
time_t specified_time;

struct tm atot_struct;
memset(&atot_struct, 0, sizeof(struct tm));

char string_year[5];
char string_month[3];
char string_day[3];

strncpy(string_year,ascii_time,4);
string_year[4] = '\0';
strncpy(string_month,&ascii_time[5],2);
string_month[2] = '\0';
strncpy(string_day,&ascii_time[8],2);
string_day[2] = '\0';

atot_struct.tm_year = atoi(string_year) - 1900;
atot_struct.tm_mon = atoi(string_month) - 1;
atot_struct.tm_mday = atoi(string_day);


char string_hour[3];
char string_minute[3];
char string_seconds[3];

strncpy(string_hour,&ascii_time[11],2);
string_hour[2] = '\0';
strncpy(string_minute,&ascii_time[14],2);
string_minute[2] = '\0';
strncpy(string_seconds,&ascii_time[18],2);
string_seconds[2] = '\0';

atot_struct.tm_hour = atoi(string_hour);
atot_struct.tm_min = atoi(string_minute);
atot_struct.tm_sec = atoi(string_seconds);

atot_struct.tm_isdst = -1;

specified_time = mktime(&atot_struct);



return specified_time;
}

int main()
{
    struct homework assignments[150];

    FILE* input;
    input = fopen("homework.txt","r+");
    if(input == NULL)
    {
        perror("ERROR: ");
    }
    char* token;
    char buffer[256];
    int array_number = 0;
    int line_count = 0;
    while(fgets(buffer,256,input) != NULL) //Begin reading in file
    {
        line_count++;
        int count = 0;
        token = strtok(buffer,",");
            while(token)
            {
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
                    assignments[array_number].due = atot(token);
                }
                else if(count == 3) //status
                {
                    strcpy(assignments[array_number].status,token);
                }
                count++;
                token = strtok(NULL,",");
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
                    if(difftime(assignments[i].due,current_time) > 604800) //less then seven days
                    {
                        printf("%-30s %30s Due: \033[0;32m%40s\033[0m\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                    }
                    else if((difftime(assignments[i].due,current_time) > 86400) && (difftime(assignments[i].due,current_time) < 604800))
                    {
                        printf("%-30s %30s Due: \033[0;33m%40s!\033[0m\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
                    }
                    else if(difftime(assignments[i].due,current_time) < 86400) //less then three days
                    {
                        printf("%-30s %30s Due: \033[0;31m%40s!!\033[0m\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));
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
                    printf("%-30s %30s Due: %40s\n",assignments[i].class_name,assignments[i].assignment_name,ctime(&assignments[i].due));

                }
             }
             printf("\n\n");



             printf("1. Move assignment to completed\n");
             printf("2. Move assignment to TODO\n");
             printf("3. Remove completed assignments\n");
             printf("4. Change due date\n");
             printf("5. Save & Quit\n");

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

                for(int i = 0; i < line_count;i++)
                {
                    if(strcmp("completed\n",assignments[i].status) == 0)
                    {
                        strcpy(assignments[i].status,"NULL");//Change time information here
                    }

                }

             }
             else if(atoi(menu_input) == 4)
             {

                char search[50];
                int found = 0;
                printf("Enter Assignment Name: \n");
                fgets(search,50,stdin);
                for(int i = 0; i < line_count;i++)
                {
                    if(strncmp(search,assignments[i].assignment_name,strlen(assignments[i].assignment_name)) == 0)
                    {
                        struct tm new_time;
                        memset(&new_time, 0, sizeof(struct tm));
                        char buffer_time[10];

                        printf("Enter month:\n");
                        strcpy(buffer_time,fgets(buffer_time,10,stdin));
                        new_time.tm_mon = atoi(buffer_time) -1;
                        printf("Enter day:\n");
                        strcpy(buffer_time,fgets(buffer_time,10,stdin));
                        new_time.tm_mday = atoi(buffer_time);
                        printf("Enter year:\n");
                        strcpy(buffer_time,fgets(buffer_time,10,stdin));
                        new_time.tm_year = atoi(buffer_time) - 1900;
                        printf("Enter Hours (military time):\n");
                        strcpy(buffer_time,fgets(buffer_time,10,stdin));
                        new_time.tm_hour = atoi(buffer_time) - 1;
                        printf("Enter Minutes:\n");
                        strcpy(buffer_time,fgets(buffer_time,10,stdin));
                        new_time.tm_min = atoi(buffer_time);

                        new_time.tm_isdst = - 1;

                        assignments[i].due = mktime(&new_time);
                        found = 1;
                    }

                }

                if(found != 1)
                {
                    printf("Match not found!\n");
                }

             }
             else if(atoi(menu_input) == 5)
             {
                fclose(input);
                FILE* output;
                output = fopen("output.txt","w");
                char formated_string[256];


                for(int i; i < line_count; i++)
                {
                    char formated_time[20];
                    strftime(formated_time,sizeof(formated_time),"%Y-%m-%dT%H:%M:%S",localtime(&assignments[i].due));
                    sprintf(formated_string,"%s,%s,%s,%s",assignments[i].class_name,assignments[i].assignment_name,formated_time,assignments[i].status);
                    fputs(formated_string,output);

                }
                fclose(output);
                remove("Homework.txt");
                const char* old = "output.txt";
                const char* newer = "Homework.txt";
                int value = rename(old,newer);
                remove("output.txt");
                return 0;
             }
        }

}
