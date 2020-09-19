#include <lms.h>


int compareString(char *string_1, char *string_2)
{
	char compare_1[50];
	strcpy(compare_1,string_1);
	char compare_2[50];
	strcpy(compare_2,string_2);

	int i;
	for (i = 0; i < 50; ++i)
	{
		compare_1[i] = tolower(compare_1[i]);
		compare_2[i] = tolower(compare_2[i]);
	}

	compare_1[strlen(compare_1)-1] = '\0';	

	if (strstr(compare_2,compare_1) == NULL)
	{
		return 0;
	}
	
	return 1;
}

int getCommand(int token)
{

	int command;

	if (token == 1)
	{
		printf("-> ");
		scanf("%d", &command);
		getchar();
		
		while(command != 1 && command != 2 && command != 3 && command != 4)
		{
			printf("Invalid command! type again -> ");
			scanf("%d", &command);
			getchar();
		}
	}
	else if (token == 2)
	{	
		printf("Enter the desired command -> ");
		scanf("%d", &command);
		getchar();
	
		while(command != 1 && command != 2 && command != 3 && command && command !=  4 && command != 5)
		{
			printf("Invalid command! type again -> ");
			scanf("%d", &command);
			getchar();
		}
	}

	return command;
}

char getAnswer(int token)
{
	if (token == 0)
	{
		printf("Book successfully added! Do you want to add another one?");
	}
	else if (token == 1)
	{
		printf("Do you want to consult again?");		
	}
	
	printf(" (s/n) -> ");

	char answer;
	scanf("%c", &answer);
	getchar();
	answer = tolower(answer);
	
	while(answer != 's' && answer != 'n')
	{
		printf("\nInvalid command! type again -> ");
		scanf("%c", &answer);
		getchar();
		answer = tolower(answer);		
	}

	if (answer == 's')
	{
		return 1;
	}
	else if(answer == 'n')
	{
		return 0;
	}
}

void setCategory(char *new_book_category)
{
	printf("\n0 - Generalities\n");
	printf("1 - Philosphy\n");
	printf("2 - Religion\n");
	printf("3 - Social Sciences\n");
	printf("4 - Language\n");
	printf("5 - Pure Science\n");
	printf("6 - Applied Science\n");
	printf("7 - Arts\n");
	printf("8 - Literature\n");
	printf("9 - Geography and History\n\n");

	printf("Enter the Number-> ");

	int category;
	scanf("%d", &category);
	getchar();

	while (category != 0 && category != 1 && category != 2 && category != 3 && category != 4 && 
		category != 5 && category != 6 && category != 7 && category != 8 && category != 9)
	{
		printf("Invalid number, type again -> ");
		scanf("%d", &category);
		getchar();
	}

	switch(category)
	{
		case 0:
		strcpy(new_book_category,"Generalities");
		break;	

		case 1:
		strcpy(new_book_category,"Philosphy");
		break;	

		case 2:
		strcpy(new_book_category,"Religion");
		break;

		case 3:
		strcpy(new_book_category,"Social Science");
		break;	

		case 4:
		strcpy(new_book_category,"language");
		break;	

		case 5:
		strcpy(new_book_category,"Pure Science");
		break;	

		case 6:
		strcpy(new_book_category,"Applied Science");
		break;	

		case 7:
		strcpy(new_book_category,"Arts");
		break;	

		case 8:
		strcpy(new_book_category,"Literature");		
		break;	

		case 9:
		strcpy(new_book_category,"Geography and History");
		break;		
	}
}

struct tm getTime() 
{	    
	time_t t = time(0);
	struct tm *today_time = localtime(&t);
	return *today_time;
}

void addBook()
{
	system("clear");
	
	int isbn;
	char author_name[50];
	char book_title[50];
	char publisher[25];
	char category[20];
	struct tm *today;

	printf("Enter book name: ");
	fgets(book_title,50,stdin);
	printf("Enter the author's name:");
	fgets(author_name,50,stdin);
	printf("Enter the name of the publisher: ");
	fgets(publisher,25,stdin);
	printf("Enter the ISBN number:");
	
	scanf("%d", &isbn);
	getchar();
	
	printf("Choose category\n");
	setCategory(category);
	
	*today = getTime();


	FILE *f = fopen("books//data.txt","a+");
	fprintf(f,"\n%s",book_title);
	fprintf(f,"%s",author_name);
	fprintf(f,"%s",publisher);
	fprintf(f,"%d\n",isbn);
	fprintf(f,"%s\n",category);
	fprintf(f,"%.2d/%.2d/%.2d\n", today->tm_mday, today->tm_mon+1, today->tm_year+1900);
	fclose(f);

	(getAnswer(0)) ? addBook() : showMenu();
}

void showAllBooks()
{
	system("clear");
	
	char book_title[50];
	char author_name[50];
	char publisher[50];
	char isbn[50];
	char category[20];
	char date[15];

	char line[50];
	FILE *f = fopen("books//data.txt","r");

	printf("\n");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);	
		fgets(isbn,50,f);
		fgets(category,20,f);
		fgets(date,15,f);

		printf("Títle: %s", book_title);
		printf("Author: %s", author_name);
		printf("Editor: %s",publisher);
		printf("ISBN: %s", isbn);
		printf("Category: %s", category);
		printf("Registration Date: %s\n", date);
	}

	fclose(f);

	(getAnswer(1)) ? showAllBooks() : showMenu();
}

void checkContent(int command)
{
	system("clear");

	int hasFound = 0;

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char isbn[50];
	char category[20];
	char date[15];

	char *picked_content;
	switch(command)
	{
		case 1:
		printf("Enter the title you want to search: ");
		picked_content = book_title;
		break;

		case 2:
		printf("Enter the author you want to search: ");
		picked_content = author_name;
		break;

		case 3:
		printf("Enter the publisher you want to search: ");
		picked_content = publisher;
		break;

		case 4:
		printf("Enter the category you want to search for: ");
		picked_content = category;
		break;

		case 5:
		showAllBooks();
		break;
	}
	
	char searched_content[50];
	fgets(searched_content,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	char line_break[50];
	while(fgets(line_break,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);
		fgets(isbn,50,f);
		fgets(category,50,f);
		fgets(date,15,f);

		if (compareString(searched_content,picked_content))
		{
			hasFound = 1;
			printf("Títle: %s", book_title);
			printf("Author: %s", author_name);
			printf("Editor: %s",publisher);
			printf("ISBN: %s", isbn);
			printf("Category: %s", category);
			printf("Registration Date: %s\n", date);
		}
	}
	
	fclose(f);

	if (!hasFound)
	{
		printf("We couldn't find results for this search.\n");
	}

	(getAnswer(1)) ? checkContent(command) : showMenu();
}

void eraseBooks()
{
	system("clear");
	fclose(fopen("books//data.txt", "w"));
}

void showMenu()
{ 
	system("clear");

	printf("Bookstore System\n\n");
	printf("1 - Add Book\n");
	printf("2 -Check Book\n");
	printf("3 - Erase data\n");
	printf("4 -Go out\n\n");
	printf("O What do you want? ");
	
	int command = getCommand(1);
	switch(command)
	{
		case 1:
		addBook();
		break;

		case 2:
		showCheckMenu();
		break;

		case 3:
		eraseBooks();
		break;

		case 4:
		system("clear");
		return;
	}
}

void showCheckMenu()
{
	system("clear");
	printf("Deseja consultar por...\n");
	printf("1 - Title\n");
	printf("2 - Author\n");
	printf("3 - Editor\n");
	printf("4 - Category\n");
	printf("5 - All the books\n");

	int command = getCommand(2);
	checkContent(command);
}


