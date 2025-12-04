#include <stdio.h>
#include <string.h>

enum Week{Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7, Invalid = 8};
struct Day {
    int weekday;
    char weather[15];
    int incidents;
    float windspeed;
    char author[15];
};

int main() {
    int todaynum;
    enum Week today;
    printf("Welcome to the SilverPlains today's registry, please enter the following data: \n- Enter the day of the week (1 belongs to Monday, 2 belongs to Tuesday...): ");
    do {
        scanf("%d", &todaynum);
        switch (todaynum) {
            case 1: today = Monday;
                    break;
            case 2: today = Tuesday;
                    break;
            case 3: today = Wednesday;
                    break;
            case 4: today = Thursday;
                    break;
            case 5: today = Friday;
                    break;
            case 6: today = Saturday;
                    break;
            case 7: today = Sunday;
                    break;
            default: today = Invalid;
                     break;
        }
    } while (todaynum <= 0 || todaynum >= 8);
    struct Day todayslog;
    todayslog.weekday = today;
    char temp[15];
    printf("\n- Enter today's weather: ");
    scanf("%s", &temp);
    strcpy(todayslog.weather, temp);
    printf("\n- Enter the number of incidents that you have encountered today: ");
    scanf("%d", &todayslog.incidents);
    printf("\n- Enter today's wind speed in knots: ");
    scanf("%f", &todayslog.windspeed);
    printf("\n- And, last but not least, enter your name: ");
    scanf("%s", &temp);
    strcpy(todayslog.author, temp);
    char response;
    printf("\nDone! Thank you for your report, do you want to output it in a file? (Y/N): ");
    scanf("%c", &response);
    if (response = 'Y') {
        FILE *pF = fopen("silverplainsreport.txt", "w");
        char daystring[15];
        switch (todayslog.weekday) {
            case 1: daystring = {'M', 'o', 'n','d','a','y'};
                    break;
            case 2: daystring = {'T','u','e','s','d','a','y'};
                    break;
            case 3: daystring = {'W', 'e', 'd', 'n', 'e', 's', 'd', 'a', 'y'};
                    break;
            case 4: daystring = {'T', 'h', 'u', 'r', 's', 'd', 'a', 'y'};
                    break;
            case 5: daystring = {'F', 'r', 'i', 'd', 'a', 'y'};
                    break;
            case 6: daystring = {'S', 'a', 't', 'u', 'r', 'd', 'a', 'y'};
                    break;
            case 7: daystring = {'S', 'u', 'n', 'd', 'a', 'y'};
                    break;
            default: daystring = {'n','/','a'};
                     break;
        }
        fprintf(pF, "Today is: %s\nToday's weather: %s\nIncidents: %d\nWindspeed: %f knots\n[Reported by: %s]", daystring, todayslog.weather, todayslog.incidents, todayslog.windspeed, todayslog.author);
        fclose(pF);
        printf("\nDone! Do you want to read it? (Y/N): ");
        scanf("%c", &response);
        if (response = 'Y') {
            printf("\n\nToday is: %s\nToday's weather: %s\nIncidents: %d\nWindspeed: %f knots\n[Reported by: %s]", todayslog.weekday, todayslog.weather, todayslog.incidents, todayslog.windspeed, todayslog.author);
        }
    }
    printf("\nBye!!");
}
