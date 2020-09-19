#include "functions.c"

int main()
{
    printf("\t\t\tWELCOME TO THE PORTAL.");
    int i;
    int choice;

    fp=fopen("library.txt","r+");

    if(fp==NULL)
    {
        fp=fopen("library.txt","w");
        fclose(fp);
        fp=fopen("library.txt","r+");
    }

do{
    printf("\n\t 1:LIST");
    printf("\n\t 2:ADD");
    printf("\n\t 3:SEARCH");
    printf("\n\t 4:MODIFY");
    printf("\n\t 5:EXIT");
    printf("\n\t ENTER CHOICE\t");
    scanf("%d",&i);
    switch(i)
    {

    case 1:list();
           break;
    case 2:newstudent();
            break;
    case 3:search();
            break;
    case 4:modify();
            break;
    }
   }
   while(choice!=5);
    fclose(fp);
return 0;

}	
