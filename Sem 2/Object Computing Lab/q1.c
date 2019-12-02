#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"



void write_def(sqlite3 *db)
{
    int res=0;
    char *err,*sql = "CREATE TABLE IF NOT EXISTS Items(\
    ID INT UNIQUE,\
    Name TEXT NOT NULL,\
    Price TEXT NOT NULL);";
    res  = sqlite3_exec(db,sql,NULL,0,&err);

    if (res != SQLITE_OK)
    {
        printf("SQLITE Table CREATION ERROR");
        sqlite3_free(err);
    }

    sql = "CREATE TABLE IF NOT EXISTS Bills(\
    ID UNIQUE AUTOINCREMENT,\
    Customer_Name TEXT NOT NULL,\
    Item_Bought TEXT NOT NULL,\
    Quantity INT,\
    Price INT);";
    res  = sqlite3_exec(db,sql,NULL,0,&err);

    if (res != SQLITE_OK)
    {
        printf("SQLITE Table CREATION ERROR");
        sqlite3_free(err);
    }
}

int add_item(int id,char *itemName,int price)
{
    char query[1000]=0;
    strcat(query,"INSERT INTO Items VALUES(");
    strcat(query,())
}

int main()
{
    int i = 0;
    sqlite3 *db;
    sqlite3_open("db",&db);
    write_def(&db);

    

       
    return 0;

}