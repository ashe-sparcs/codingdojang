#include <stdio.h>

int isleapyear(int year)
{
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int datetodays(int date)
{
    int i, result, year, month, day;

    result = 0;
    day = date % 100;
    month = ((date/100)%100)-1;
    year = (date / 10000)-1;

    result += year/4;
    result -= year/100;
    result += year/400;
    result += year * 365;

    if (month==0) ;
    else if (month == 1) result += 31;
    else if (month < 8)
    {
        if (isleapyear(year+1)) result++;
        result += 61*(month/2)+31*(month&1)-2;
    }
    else
    {
        if (isleapyear(year+1)) result++;
        month -= 7;
        result += 212+61*(month/2)+31*(month&1);
    }


    result += day;

    return result;
}

int subdate(int date1, int date2)
{
    int temp;

    if (date1==date2)
    {
        return 0;
    }

    if (date1>date2)
    {
        temp = date1;
        date1 = date2;
        date2 = temp;
    }

    if (date1/100 == date2/100)
    {
        return (date2%100 - date1%100);
    }

    else
    {
        return datetodays(date2) - datetodays(date1);
    }
}
    

int main()
{
    int date1, date2;
    int temp;

    scanf("%d %d", &date1, &date2);

    printf("%d sub %d = %d\n", date1, date2, subdate(date1, date2));

    return 0;
}

    
