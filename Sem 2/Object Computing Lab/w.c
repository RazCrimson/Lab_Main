#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct item
{
    char *name;
    int price,id;
}s[4];

void def()
{
    s[0].name="Book";
    s[0].id = 1;
    s[0].price = 100;
    s[1].name="Grocery";
    s[1].id = 2;
    s[1].price = 300;
    s[2].name="Stationery Set";
    s[2].id = 3;
    s[2].price = 150;
    s[3].name="Snacks";
    s[3].id = 4;
    s[3].price = 200;
}

int do_bill(FILE* ptr)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char name[20]={0};
    int i,id=-1,quan;
    printf("Enter the Customer Name :");
    scanf("%s",name);
    printf("Enter the Item ID :");
    scanf("%d",&id);
    printf("Enter the Quantity :");
    scanf("%d",&quan);
    for(i = 0;i<4;i++)
    {
        if(id == i +1)
            break;
    }
    printf("i = %d, q %d",i,quan);
    if (i == 4 || quan <  0)
    {
        printf("No Matching Item found");
        exit(0);
    }
    int res= fprintf(ptr,"Date:%d/%d/%d\nName : %s\nItem : %s\nQuantity : %d\nPrice : %d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,s[i].name,quan,s[i].price*quan);
    printf("res = %d",res);
}





int main()
{
    FILE *bill_ptr;
    bill_ptr = fopen("Bill.txt","a+");
    def();
    do_bill(bill_ptr);
    fclose(bill_ptr);

}
