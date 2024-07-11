#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct emp
{
   char name[48];
   int age;
   int bas_sal;
};

struct node
{
    struct emp data;
    struct node *next;
};
struct node *head = NULL;

int main(void)
{
    loadDataFromFile(&head);
    display_record (head);

    int A, B;
    char N[48];
    char choice;

   do
    {
        printf("\n\n\t\----------------------------------------------------\n");
        printf("\t\t     Welcome to Employees Database\n");
        printf("\t\--------------------------------------------------------\n");

        printf("\n\nWhat would you like to do?\n\n");
        printf("\n1.Search record by Name");
        printf("\n2.Search record by Age");
        printf("\n3.Search record by Basic salary");
        printf("\n4.Sort the list");
        printf("\n5.Modify Employee records");
        printf("\n6.Text to binary");
        printf("\n7.Display Employee record");
        printf("\n8.Exit\n");

        printf("\nPlease enter your choice (1-8):- ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
            case 1:
                {
                    printf("\nSEARCH EMPLOYEE BY NAME");
                    printf("\n\nEnter the name:- ");
                    scanf("%s", &N[48]);

                    searchDataByName(head, N[48]);
                    break;
                }

            case 2:///Search record by Age
                  {
                    int A;
                    printf("\nSEARCH EMPLOYEE BY AGE");
                    printf("\n\nEnter the age:- ");
                    scanf("%d", &A);

                    printf("\nRecord found!\n");
                    searchDataByage(head, A);
            break;
                  }

            case 3: ///Search record by Basic salary
            {
                int B;
                    printf("\nSEARCH EMPLOYEE BY BASIC SALARY");
                    printf("\n\nEnter the Basic salary:- ");
                    scanf("%d", &B);

                    printf("\nRecord found!\n");
                    SearchDataByBasicSalary(head, B);
                break;
            }

            case 4:
                {
                    printf("\nThe data of the employees is sorted in ascending order below:\n");
                    Sort_By_Age();
                    display_record(head);
                break;
                }

            case 5:  modifyrecord();
            break;

            case 6:
                {
                    printf("File converted from text to binary format");
                    textFile_to_BinaryFile();
            break;
                }

            case 7:  display_record(head);
            break;

            case 8:  End();
            break;

            default:
                printf("\nInvalid! Please choose again from (1-8)!");
        }
    }while(choice!=8);

return 0;
}

//This function is made to store the employees data in the linked list
void insert_record_at_end(struct node **head, struct emp data)
{
    struct node *temp = *head;
    struct node *new_node;

    new_node = calloc(sizeof(struct node),1);
    new_node->data = data;

    if((*head) == NULL)
    {
        (*head) = new_node;
        new_node->next = NULL;
        return;
    }

    while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next  = NULL;
}

//This function displays the employee record
void display_record(struct node *head)
{
    struct node *temp;
    temp  = head;
    if(head == NULL)
    {
        printf("\nNo record available");
        return;
    }

    printf("\nEMPLOYEE DETAILS:\n");
    while(temp != NULL)
    {
    printf("\n%s\n",temp->data.name);
    printf("%d\n",temp->data.age);
    printf("%d\n",temp->data.bas_sal);
       temp = temp->next;
    }
    return;
}

//This function loads the data from file
void loadDataFromFile(struct node **head)
 {
    FILE *fp = NULL;
    fp = fopen("employee_records.dat", "r");

    struct emp data;
    while(fscanf(fp, "%[^\n] %d %d\n", &data.name, &data.age, &data.bas_sal) != EOF)
      {
        insert_record_at_end(head, data);
      }
    fclose(fp);
}

int searchDataByName(struct node * head, char N[48])
{

    struct node * temp = head;
    while((strcmp(temp->data.name,N[48]) == 0) && ((temp->next) != NULL))
    {

            printf("\nEMPLOYEE DETAILS:\n");
            printf("\n%s\n",temp->data.name);
            printf("%d\n",temp->data.age);
            printf("%d\n",temp->data.bas_sal);
    }
        temp = temp->next;
}

int searchDataByage(struct node * head, int A)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->data.age == A)
        {
            printf("\nEMPLOYEE DETAILS:\n");
            printf("\n%s\n",temp->data.name);
            printf("%d\n",temp->data.age);
            printf("%d\n",temp->data.bas_sal);
        }
         temp = temp->next;
    }
}

int SearchDataByBasicSalary(struct node * head, int B)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->data.bas_sal == B)
        {
            printf("\nEMPLOYEE DETAILS:\n");
            printf("\n%s\n",temp->data.name);
            printf("%d\n",temp->data.age);
            printf("%d\n",temp->data.bas_sal);
        }
        temp = temp->next;
    }
}

//This function sorts the data in ascending order on the basis of age
void Sort_By_Age()
{
    struct node *temp, *ptr;
    int x;
    temp = head;

    while (temp->next != NULL)
    {
        ptr = temp->next;
        while(ptr != NULL)
        {
            if((temp->data.age) > (ptr->data.age))
            {
                x = temp->data.age;
                (temp->data.age) = (ptr->data.age);
                (ptr->data.age) = x;
            }
            ptr = ptr->next;
        }
        temp = temp->next;
    }
}

void modifyrecord()
{
    FILE *fp;
int age;
char ch,c;
printf("\nEnter age. \n");
scanf("%d", &age);

    struct emp data;
     fscanf(fp, "%[^\n] %d %d  \n", &data.name, &data.age, &data.bas_sal);
    if(data.age==age)
    {
        printf("\nDo you want to change the name? (y/n)\n");
        scanf("%c",&ch);
        if(ch=='y')
        {
            printf("\nEnter new name\n");
            scanf("%s", data.name);
        }
        printf("\nDo you want to change the basic salary? (y/n)\n");
        scanf("%c",&ch);

        if(ch=='y')
        {
            printf("\nenter new basic salary");
            scanf("%s", data.bas_sal);
        }
        printf("\nDo you want to change the age? (y/n)\n");
        scanf("%c", &ch);
        if(ch=='y')
        {
            printf("\nEnter new age\n");
            scanf("%s", data.age);
        }
        fseek(fp,sizeof(struct emp) ,SEEK_SET);
 }    fprintf(fp, "%[^\n] %d %d  \n", data.name, data.age, data.bas_sal);
 fclose(fp);
}

void textFile_to_BinaryFile()
{
    FILE *fp = NULL;
    FILE *fptr = NULL;
    fp = fopen("employee_records.dat", "r");

    fptr = fopen("employee.dat", "wb");
    struct emp data;

    while(fscanf(fp, "%[^\n] %d %d \n", &data.name, &data.age, &data.bas_sal) != EOF)
        fwrite(&data, 10, 1, fptr);

        fclose(fp);
        fclose(fptr);
}

End()
{
    system("cls");
    printf("\t ----Project Made By Shiza & Nazma----");
}
