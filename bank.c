#include<stdio.h>
#include<stdlib.h>
int i,j;
int main_exit;   //Take input to exit or re-enter when user has entered wrong password  
void menu();
void edit();
void see();
void transact();
struct date{
    int month,day,year;
};

struct {

    char name[60],pass[20],pass1[30];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,update,check,delet,transaction;
    
    
  
  
 void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close()
{
	printf("\n\n\t-----------------------------------------\n");
    printf("\t\tThanks for visiting!\n");
    printf("\t-----------------------------------------\n");
    
}

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tPASSWORD\t\t\tADDRESS\t\t\tPHONE\n");
	
    while(fscanf(view,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.pass,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.pass,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls"); 
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            Login_admin();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void delete_record()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter your account no.:");
    scanf("%d",&delet.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=delet.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
				test++;
            	printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            Login_admin();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            delete_record();
        else
        {
			printf("\nInvalid!\a");
            goto erase_invalid;
		}
    }
    else
    {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }

}


Login_admin()
{
	int choice;
	
	char pass[10],password[10]="sumant";
    int i=0;
    printf("\n\n\t-----------------------------------------\n");
    printf("\t\tWELCOME TO LENA DENA BANK\n");
    printf("\t-----------------------------------------\n");
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
    {
		printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            delay(100000000);
            printf(".");
        }
        menu_try:
	    system("cls");
	    printf("\n\n\t-----------------------------------------\n");
	    printf("\t\tWELCOME TO LENA DENA BANK\n");
	    printf("\t-----------------------------------------\n");
	    printf("\n\n\n\t\t\t MAIN MENU");
	    printf("\n\n\t\t1.View customer's list\n\t\t2.Removing existing account\n\t\t3.Exit\n\n\n\n\n\t\t Enter your choice:");
	    fflush(stdin);
		choice = getche();
	
	    system("cls");
	    switch(choice)
	    {
	        case '1':
				view_list();
	        	break;
	        case '2':
				delete_record();
	        	break;
	        case '3':
				close();
	        	break;
	        default:
	        	printf("\nInvalid option! Try again");
	        	delay(1000000000);
            	system("cls");
	        	goto menu_try;
	
	    }
	}
	else
	{
		printf("\n\nWrong password!!");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        fflush(stdin);
		main_exit = getche();
        if (main_exit=='1')
		{
			fflush(stdin);
            system("cls");
            main();
        }

        else if (main_exit=='0')
    	{
            system("cls");
            close();
		}
        else
        {
			printf("\nInvalid option!");
            delay(1000000000);
            system("cls");
            goto login_try;
		}

	}
} 

void create_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t ADD RECORD");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,add.pass,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            delay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnetr password:");
    scanf("%s",add.pass);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
		
        fprintf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.pass,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    fflush(stdin);
	main_exit = getche();
    system("cls");
    if (main_exit=='1')
        menu();
    else if(main_exit=='0')
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}


void customer_login_menu()
{
	int choice;
    system("cls");
    printf("\n\n\t-----------------------------------------\n");
    printf("\t\tWELCOME TO LENA DENA BANK\n");
    printf("\t-----------------------------------------\n");
    printf("\n\n\n\t\t\t MAIN MENU");
    printf("\n\n\t\t1.Update information\n\t\t2.For transactions\n\t\t3.Check the details\n\t\t4.Exit\n\n\n\n\n\t\t Enter your choice:");
    fflush(stdin);
	choice = getche();

    system("cls");
    switch(choice)
    {
        case '1':
			edit();
        	break;
        case '2':
			transact();
        	break;
        case '3':
			see();
        	break;
        case '4':
			close();
        	break;
    }
}

void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter your account no.:");
    scanf("%d",&update.acc_no);
    while(fscanf(old,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,add.pass,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==update.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
           	fflush(stdin);
			choice = getche();
            system("cls");
            if(choice=='1')
                {
					printf("Enter the new address:");
	                scanf("%s",update.address);
	                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,update.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	                system("cls");
	                printf("Changes saved!");
                }
            else if(choice=='2')
                {
                    printf("Enter the new phone number:");
	                scanf("%lf",&update.phone);
	                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,update.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	                system("cls");
	                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

	if(test!=1)
    {   
		system("cls");
    	printf("\nRecord not found!!\a\a\a");
        edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        fflush(stdin);
		main_exit = getche();
        system("cls");
        if(main_exit=='1')
			customer_login_menu();
        else if (main_exit=='2')
   	    	close();
        else if(main_exit=='0')
            edit();
        else
        {
			printf("\nInvalid!\a");
            goto edit_invalid;
		}
    }   
}

void transact()
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    delay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       	printf("\n\nRecord not found!!");
       	transact_invalid:
      	printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      	scanf("%d",&main_exit);
      	system("cls");
      	if (main_exit==0)
        	transact();
    	else if (main_exit==1)
        	customer_login_menu();
    	else if (main_exit==2)
        	close();
    	else
    	{
        	printf("\nInvalid!");
        	goto transact_invalid;
    	}
	}

}

void see()
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Enter the account number:");
    scanf("%d",&check.acc_no);

    while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==check.acc_no)
        {   
			system("cls");
            test=1;

            printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
            add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            if(strcmpi(add.acc_type,"fixed1")==0)
            {
                time=1.0;
                rate=9;
                intrst=interest(time,add.amt,rate);
                printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
            }
            else if(strcmpi(add.acc_type,"fixed2")==0)
            {
           	    time=2.0;
                rate=11;
                intrst=interest(time,add.amt,rate);
                printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);
			}
            else if(strcmpi(add.acc_type,"fixed3")==0)
            {
                time=3.0;
                rate=13;
                intrst=interest(time,add.amt,rate);
                printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);
			}
            else if(strcmpi(add.acc_type,"saving")==0)
            {
            	time=(1.0/12.0);
                rate=8;
                intrst=interest(time,add.amt,rate);
                printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

            }
            else if(strcmpi(add.acc_type,"current")==0)
            {
                printf("\n\nYou will get no interest\a\a");
			}
			printf("\nEnter 0 to try again,1 to return to menu and 2 to exit:");
	        scanf("%d",&main_exit);
	        system("cls");
	        if (main_exit==1)
	        	customer_login_menu();
	        else if (main_exit==2)
	            close();
	        else if(main_exit==0)
	            see();
	        else
	        {
	            system("cls");
	            printf("\nInvalid!\a");
	            goto see_invalid;
			}

        }
    }
    

    fclose(ptr);
     if(test!=1)
    {   
		system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
        printf("\nEnter 0 to try again,1 to return to menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
        	customer_login_menu();
        else if (main_exit==2)
            close();
        else if(main_exit==0)
            see();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
		}
    }
}



void login()
{
	int flag=0,choice;
	FILE *ptr;
	ptr=fopen("record.dat","a+");
	printf("\n\n\t-----------------------------------------\n");
    printf("\t\tWELCOME TO LENA DENA BANK\n");
    printf("\t-----------------------------------------\n");
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",add.pass1);
    while(fscanf(ptr,"%d %s %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,add.pass,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (strcmp(add.pass,add.pass1)==0)
        {
			flag=1;
        }
    }
    if(flag==1)
    {
    	printf("\n\nPassword Match!\nLOADING");
			for(i=0;i<=6;i++)
        	{
            	delay(100000000);
            	printf(".");
        	}
        	system("cls");
        	customer_login_menu();
	}
    
    else
    {
    	printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        fflush(stdin);
		choice = getche();
        if (choice=='1')
		{
			fflush(stdin);
            system("cls");
            login();
        }

        else if (choice=='0')
        {
        	system("cls");
            close();
		}
        else
        {
			printf("\nInvalid!");
            delay(1000000000);
            system("cls");
            goto login_try;
		}

	}

}

void login_customer()
{
	int choice;
    system("cls");
    printf("\n\n\t-----------------------------------------\n");
    printf("\t\tWELCOME TO LENA DENA BANK\n");
    printf("\t-----------------------------------------\n");
    printf("\n\n\n\t\t\t MAIN MENU");
    printf("\n\n\t\t1.Create new account\n\t\t2.Login\n\t\t3.Exit\n\n\n\n\n\t\t Enter your choice:");
    fflush(stdin);
	choice = getche();

    system("cls");
    switch(choice)
    {
        case '1':
			create_acc();
        	break;
        case '2':
			login();
        	break;
        case '3':
			close();
        	break;

    }
}


void menu()
{   int choice;
    system("cls");
    printf("\n\n\t-----------------------------------------\n");
    printf("\t\tWELCOME TO LENA DENA BANK\n");
    printf("\t-----------------------------------------\n");
    printf("\n\n\n\t\t\t MAIN MENU");
    printf("\n\n\t\t1.Login or signup (Only for admin)\n\t\t2.Login or signup (for customer)\n\t\t3.Exit\n\n\n\n\n\t\t Enter your choice:");
    fflush(stdin);
	choice = getche();

    switch(choice)
    {
        case '1':
        	printf("\n\nPlease wait\nLOADING");
			for(i=0;i<=6;i++)
		        {
		            delay(100000000);
		            printf(".");
		        }
            system("cls");
            Login_admin();
        	break;
        case '2':
        	printf("\n\nPlease wait\nLOADING");
        	for(i=0;i<=6;i++)
		        {
		            delay(100000000);
		            printf(".");
		        }
            system("cls");
			login_customer();
        	break;
        case '3':
        	system("cls");
			close();
        	break;

    }
}

int main ()
{
	menu();
	return 0;
}
