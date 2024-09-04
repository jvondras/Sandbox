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
 if(x == 0)
 {
     printf("You are standing in front of a DOOR\n\n");
 }
}
void commit_command()
{
    char temp[50];
    char command[2][25];
    printf("----------------\n");
    printf("Enter command:\n");
    fgets(temp,50,stdin);
    char* token;
    token = strtok(temp," ");
    int count = 0;
    while(token)
    {
        if(count == 0)
        {
            strcpy(command[0],token);
            token = strtok(NULL," ");
            count++;
        }
        else if(count == 1)
        {
            strcpy(command[1],token);
            token = strtok(NULL," ");
        }

    }

    make_lowercase(command[0]);
    make_lowercase(command[1]);

    //NOTE THAT COMMAND[1] IS HOLDING BLANKSPACES THAT INTEFERE WITH STRCMP

    if(strcmp(command[0],"inspect") == 0)
    {
        if(strncmp(command[1],"door",4) == 0)
        {
            printf("\nYou inspect the door; it's old and worn and appears to be made of wood.\nThe HINGES holding the door are made of brass just like the DOORKNOB and KEYHOLE\n\n");
        }
        else if(strncmp(command[1],"hinges",6) == 0)
        {
            printf("\nThe HINGES appear to be made of brass, they are heavily scratched and \nclearly very worn but still shine as if they have just been polished\n\n");
        }
        else if(strcmp(command[1],"room") == 0)
        {

        }
        else
        {
            printf("You can't do that!\n\n");
        }

    }
    else if(strcmp(command[0],"open") == 0)
    {

    }
    else if(strcmp(command[0],"look") == 0)
    {
        if(strncmp(command[1],"north",5) == 0)
        {
            printf("\nYou look to the north and see a DOOR, it looks awfully familiar.\nThe DOOR is set into a large grey castle brick wall that extends\nleft and right for what appears to be forever\n\n");
        }
        else if(strncmp(command[1],"west",4) == 0)
        {
            printf("\nYou look to the west and see pitch black nothing\n\n");
        }
        else if(strncmp(command[1],"east",4) == 0)
        {
            printf("\nYou look to the east and see pitch black nothing\n\n");
        }
        else if(strncmp(command[1],"south",5) == 0)
        {
            printf("\nYou look to the south and see pitch black nothing\n\n");
        }
        else
        {
            printf("\nThat's not a direction!\n\n");
        }

    }
    else if(strncmp(command[0],"help",4) == 0)
    {
        printf("\n\n\n");
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
    printf("WELCOME TO DOOR QUEST V.1.\n");
    while(exit_main == 1)
    {
        get_state(main_state);
        commit_command();
    }
}
