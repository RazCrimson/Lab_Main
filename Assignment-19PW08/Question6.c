#include <stdio.h>
#include <stdlib.h>

// Driver Not yet complete

typedef struct
{
    int hh, mm;
    float ss;
} TIME_info;

TIME_info Read()
{
    TIME_info var;
    int hh, mm;
    float ss;
    printf("\nEnter the time in hh:mm:ss.sss format : ");
    scanf("%d:%d:%f", &hh, &mm, &ss);
    if (hh >= 24 || mm >= 60 || ss > 60)
    {
        printf("\nERROR!\nInvalid Time");
        exit(0);
    }
    var.hh = hh;
    var.mm = mm;
    var.ss = ss;
    return var;
}

void print(TIME_info var)
{
    printf("%d:%d:%.3f",var.hh, var.mm, var.ss);
}


TIME_info convertTime(double realTime)
{
    TIME_info var;
    int hh=0,mm=0;
    while(realTime-3600>0)
    {
        realTime=realTime-3600;
        hh+=1;
    }
    while(realTime-60>0)
    {
        realTime=realTime-60;
        mm+=1;
    }
    var.hh = hh;
    var.mm = mm;
    var.ss = realTime;
    return var;
}

TIME_info addTimes(TIME_info one, TIME_info two)
{
    TIME_info var;
    int hh, mm;
    float ss;
    hh=one.hh+two.hh;
    mm=one.mm+two.mm;
    ss=one.ss+two.ss;
    var.hh=hh%24;
    var.hh+=mm/60;
    var.mm=mm%60; 
    var.mm+=(int)(ss/60);
    while(ss>60)
        ss-=60;
    var.ss=ss;
    return var;
}