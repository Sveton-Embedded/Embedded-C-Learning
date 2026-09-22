#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char data[] = "5.2 , 12.1 , 80";

    char *token = strtok(data, ",");
    float temperature = atof(token);

    token = strtok(NULL, ",");
    float voltage = atof(token);

    token = strtok(NULL, ",");
    float percentage = atof(token);

    printf("Temperature: %.1f\n", temperature);
    printf("Voltage: %.1f\n", voltage);
    printf("Percentage: %.1f\n", percentage);

    return 0;

}