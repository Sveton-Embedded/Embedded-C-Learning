#include <stdio.h>
#include <string.h>

typedef struct
{
    const char *eventName;
    void (*handler)(void);
}Event;

void onButtonPress(void)
{
    printf("Button was pressed!\n");
}

void onTimerExpired(void)
{
    printf("Timer expired!\n");
}

void onSensorTriggered(void)
{
    printf("Sensor triggered!\n");
}

Event eventTable[] =
{
    {"ButtonPress", onButtonPress},
    {"TimerExpired", onTimerExpired},
    {"SensorTriggered", onSensorTriggered}
};

void triggerEvent(const char *name)
{
    int count = sizeof(eventTable) / sizeof(eventTable[0]);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(eventTable[i].eventName, name) == 0)
        {
            eventTable[i].handler();  
            return;
        }
    }

    printf("Event '%s' not found!\n", name);   
}

int main(void)
{
    triggerEvent("ButtonPress");
    triggerEvent("TimerExpired");
    triggerEvent("UnknownEvent");   

    return 0;
}