
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

struct Day {
    char *dayName;
    int date;
    char *activityDescription;
};

struct Day *create(int numDays) {
    struct Day *calendar = (struct Day *)malloc(numDays * sizeof(struct Day));
    
    for (int i = 0; i < numDays; i++) {
        calendar[i].dayName = (char *)malloc(20 * sizeof(char));
        calendar[i].activityDescription = (char *)malloc(100 * sizeof(char));
    }
    return calendar;
}

void read(struct Day *calendar, int numDays) {
    for (int i = 0; i < numDays; i++) {
        printf("Enter the name of the day: ");
        scanf("%s", calendar[i].dayName);
        printf("Enter the date of the day: ");
        scanf("%d", &calendar[i].date);
        printf("Enter the description of the activity: ");
        scanf("%s", calendar[i].activityDescription);
    }
}

void display(struct Day *calendar, int numDays) {
    printf("\nWeek's Activity Details:\n");
    printf("%-15s%-15s%-30s\n", "Day", "Date", "Activity Description");

    for (int i = 0; i < numDays; i++) {
        printf("%-15s%-15d%-30s\n",
               calendar[i].dayName,
               calendar[i].date,
               calendar[i].activityDescription);
    }
}

void freeCalendar(struct Day *calendar, int numDays) {
    for (int i = 0; i < numDays; i++) {
        free(calendar[i].dayName);
        free(calendar[i].activityDescription);
    }
    free(calendar);
}

int main() {
    int numDays;
    printf("Enter the number of days in the week: ");
    scanf("%d", &numDays);

    struct Day *calendar = create(numDays);
    read(calendar, numDays);
    display(calendar, numDays);
    freeCalendar(calendar, numDays);

    return 0;
}
