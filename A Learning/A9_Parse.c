#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    float voltage;
} Motor;

void parseCommand(Motor *m, char *command)
{
    char *cmdName = strtok(command, " ");

    if (cmdName == NULL)
    {
        printf("Error: empty command\n");
        return;
    }

    if (strcmp(cmdName, "SET_VOLTAGE") == 0)
    {
        char *valueStr = strtok(NULL, " ");

        if (valueStr == NULL)
        {
            printf("Error: SET_VOLTAGE requires a value\n");
            return;
        }

        float value = atof(valueStr);
        m->voltage = value;
        printf("Voltage set to %.1f\n", m->voltage);
    }
    else
    {
        printf("Error: unknown command '%s'\n", cmdName);
    }
}

int main(void)
{
    Motor m;
    m.voltage = 0.0f;

    char cmd1[] = "SET_VOLTAGE 12.5";
    parseCommand(&m, cmd1);

    char cmd2[] = "SET_VOLTAGE";   
    parseCommand(&m, cmd2);

    char cmd3[] = "UNKNOWN_CMD 5";   
    parseCommand(&m, cmd3);

    return 0;
}