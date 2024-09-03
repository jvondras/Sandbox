#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void make_lowercase(char input[])
{
    for(int i = 0; i < strlen(input);i++)
    {
        input[i] = tolower(input[i]);
    }
}
void get_state(int x)
{
    printf("WELCOME TO DOOR QUEST V1")
 if(x == 0)
 {
     printf("You are standing in front of a door\n\n");
 }
}
void commit_command()
{
    char command[2][25];
    printf("----------------\n");
    printf("Enter command:\n");
    scanf("%s",command); //need to tokenize and delimit by spaces and shove into command array 'COMMAND' 'OBJECT'
    make_lowercase(command);
    make_lowercase(object);

    if(strcmp(command,"inspect") == 0)
    {
        if(strcmp(object,"door") == 0)
        {

        }
        else if(strcmp(object,"room") == 0)
        {

        }
        else
        {
            printf("You can't do that!\n\n");
        }

    }
    else if(strcmp(command,"open" || "use" || "interact") == 0)
    {

    }
    else if(strcmp(command,"look") == 0)
    {

    }
    else
    {
        printf("You can't do that!\n\n");
    }

}

int main(void)
{
    int main_state = 0;
    int exit_main = 1;
    while(exit_main == 1)
    {
        get_state(main_state);
        commit_command();
    }
}
