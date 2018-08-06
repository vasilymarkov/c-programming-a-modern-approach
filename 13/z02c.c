#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 
#define MSG_LEN 60

int read_line(char msg_str[], int n);

int main(void)
{
    char reminders[MAX_REMIND] [MSG_LEN+3];
    char day_str[15], msg_str[MSG_LEN+1];
    int i, j, month, day, hrs, min, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month, day, time and reminder: ");
        scanf("%2d", &month);
        if (month == 0)
            break;
        scanf("/%2d", &day);
        scanf("%2d:%2d", &hrs, &min);
        sprintf(day_str, "%.2d/%.2d %.2d:%.2d", month, day, hrs, min);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char msg_str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            msg_str[i++] = ch;
    msg_str[i] = '\0';

    return i;
}
