#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned Piels, Coors, Bud, Iron_City;
    int Val=0;
    short ch=0; 
    printf("\nEnter the Inventory :\nNo. of Piels cases : ");
    scanf("%u",&Piels);
    printf("\nNo. of Coors cases : ");
    scanf("%u",&Coors);
    printf("\nNo. of Bud cases : ");
    scanf("%u",&Bud);
    printf("\nNo. of Iron City cases : ");
    scanf("%u",&Iron_City);
    while (1)
    {
        printf("\n\nEnter the brand ID : ");
        scanf("%hi",&ch);
        printf("\nEnter the Amount sold or purchased : ");
        scanf("%d",&Val);
        switch (ch)
        {
            case 1:
            {
                if((Piels+Val)>0)
                    Piels+=Val;
                else
                    printf("\nThere is not enough stock of Piels.\nCurrent Stock : %u",Piels) ;      
                break;
            }
            case 2:
            {
                if((Coors+Val)>0)
                    Coors+=Val;
                else
                    printf("\nThere is not enough stock of Coors.\nCurrent Stock : %u",Coors) ;      
                break;
            }
            case 3:
            {
                if((Bud+Val)>0)
                    Bud+=Val;
                else
                    printf("\nThere is not enough stock of Buds.\nCurrent Stock : %u",Bud) ;      
                break;
            }
            case 4:
            {
                if((Iron_City+Val)>0)
                    Iron_City+=Val;
                else
                    printf("\nThere is not enough stock of Iron City.\nCurrent Stock : %u",Iron_City) ;      
                break;
            }
            default:
                printf("\nERROR!!\nEnter a proper value!");
                continue;
        }
    }
    printf("\n\t\t##### Inventory #####\nNo. of Piels cases : %u\nNo. of Coors cases : %u\nNo. of Bud cases : %u\nNo. of Iron City cases : %u",Piels,Coors,Bud,Iron_City);
    return 0;
}