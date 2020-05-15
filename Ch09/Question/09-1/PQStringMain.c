#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * str1, char * str2)
{
    printf("d1[%d]: %s, d2[%d]: %s \n", strlen(str1), str1, strlen(str2), str2);
    printf("result of subtraction %d\n\n", strlen(str2) - strlen(str1));
    return strlen(str2) - strlen(str1);
}

int main(void)
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq, "Good morning");
    PEnqueue(&pq, "I am a boy");
    PEnqueue(&pq, "Priority Queue");
    PEnqueue(&pq, "Do you like coffee");
    PEnqueue(&pq, "I am so happy");

    while(!PQIsEmpty(&pq))
        printf("%s \n", PDequeue(&pq));

    return 0;
}
