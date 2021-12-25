					#include <stdio.h>
					#include <stdlib.h>
					#include <time.h>
					#include <math.h>
					#include <stdbool.h>
					#include <string.h>
					
					
					typedef struct
					{
					    int day;
					    int month;
					    int year;
					}date;
					
					typedef struct
					{
					      int account_number;
					      char full_name[20];
					      date date_of_birth;
					      char address[100];
					      char tel_number[20];
					      double balance;
					}customer;
					
					typedef struct
					{
					     
					      char full_name[20];
					      char user_name[10];
					      char password[10];
					}teller;
					
					FILE *cust,*tell;
					
					customer Customer[10];
					int k=0;
					void menu();
					void back_to_menu();
					void ListCustomers();
					void AddNewCustomer();
					void ShowCustomer();
					void DeleteCustomer();
					void DepositMoney();
					void WithdrawMoney();
					
					void Array_to_File();
					void File_to_Array();
					
					void line(int n)
					{
						for(int i=0;i<n;i++)
						{
							printf("\n");
						}
					}
					void space(int n)
					{
						for(int i=0;i<n;i++)
						{
							printf("\t");
						}
					}	
					
					
					int control=0;
					int main()
					{
						system("cls");
						if(control==3)
						{
							line(6);
							space(5);
							printf("Thank you for attempting");
							line(3);
						}
						else
						{
						
								tell=fopen("teller.txt","w");
								fprintf(tell,"%s %s %s\n","Mark_Burry","Mark@Br","MB57doc");
								fprintf(tell,"%s %s %s\n","Cyrille_Hanouna","TPMP@235","Ch5486");
								fprintf(tell,"%s %s %s\n","Jason_Parker","EricNson","RM0101NS");
								fprintf(tell,"%s %s %s\n","Charlie_Chaplin","Charlot","CD001cD");
								
								fclose(tell);
								char login_fullname[21];
								char namelog[21];
								char username[10],password[10];
								int matches=0;
								char un[10],pw[10];
								line(5);
								space(6);
								printf("HELLO!WELCOME TO OUR BANK\n\n");
								space(5);
								printf("Enter your username and your password to log in");
								line(1);
								space(6);
								printf("username: ");
								gets(username);
								space(6);
								printf("password: ");
								gets(password);
								tell=fopen("teller.txt","r");
								while(!feof(tell))
								{
									fscanf(tell,"%s",login_fullname);
									fscanf(tell,"%s",un);
									fscanf(tell,"%s",pw);	
									if(strcmp(un,username)==0 && strcmp(pw,password)==0)
									{
										matches=1;
										strcpy(namelog,login_fullname);
									}
								}
								if(matches==1)
								{
									line(3);
									space(6);
									printf("You successfully log in");
									line(1);
									space(6);
									printf("Welcome %s !!!\n",namelog);
									back_to_menu();	
								}
								else
								{
									control++;
									line(3);
									space(6);
									printf("Try again");
									line(3);
									main();
								}
						}
							
					    return 0;
					}
					void menu()
					{
									File_to_Array();
									system("cls");
									int choice=0;
									printf("\n\n\n===============================================================================================================\n\n\n\n\n\n\n");
									printf("\t\t\t\t\t\t1.List of Customers\n\t\t\t\t\t\t2.Add a New Customer\n\t\t\t\t\t\t3.Show a Customer\n\t\t\t\t\t\t4.Delete a Customer\n\t\t\t\t\t\t5.Deposit Money\n\t\t\t\t\t\t6.Withdraw Money\n");
									printf("\n\n\t\t\t\t\t\tChoice: ");
									scanf("%d",&choice);
									switch(choice)
									{
										case 1:
											ListCustomers();break;
										case 2:
											AddNewCustomer();break;
										case 3:
											ShowCustomer();break;
										case 4: 
											DeleteCustomer();break;
										case 5:
											DepositMoney();break;
										case 6:
											WithdrawMoney();break;
										default:
											line(3);
											space(4);
											printf("You have to choose a number that corresponds to one of the options");
											back_to_menu();
											break;
									}
									
						
					}
					void back_to_menu()
					{
							int ch;
							line(3);
							space(5);
							printf("Enter 0 and press ENTER to access the MENU  ");
							scanf("%d",&ch);
							if(ch==0)
							{
								menu();
							}
							else
							{
								system("cls");
								back_to_menu();
							}
						
					}
					void ListCustomers()
					{
								system("cls");
								line(5);
								for(int i=0;i<10;i++)
								{
									space(6);
									printf("%d\t%s\t%lf\n",Customer[i].account_number,Customer[i].full_name,Customer[i].balance);		
								}
								back_to_menu();
					}
					void AddNewCustomer()
					{
						system("cls");
						char fullname[21];
						srand(time(NULL));
						int number=0;
						int day=0, month=0, year=0;
						char address[100];
						char phone_number[10]; 
						double balance=0.000;
						line(5);
						space(6);
						printf("Enter the customer full name: ");
						fflush(stdin);
						gets(fullname);
						space(6);
						printf("Enter the customer date of birth\n\t\t\t\t\t\tDay: ");
						scanf("%d",&day);
						space(6);
						printf("month: ");
						scanf("%d",&month);
						space(6);
						printf("year: ");
						scanf("%d",&year);
						space(6);
						printf("Enter the adress of the customer: ");
						fflush(stdin);
						gets(address);
						space(6);
						printf("Enter the customer telephone number: ");
						fflush(stdin);
						gets(phone_number);
						space(6);
						printf("Enter the customer balance: ");
						scanf("%lf",&balance);
						number=1000+rand()%8999;
						Customer[k++];
						strcpy(Customer[k].full_name,fullname);
						Customer[k].account_number=number;
						Customer[k].date_of_birth.day=day;
						Customer[k].date_of_birth.month=month;
						Customer[k].date_of_birth.year=year;
						Customer[k].balance=balance;
						strcpy(Customer[k].address,address);
						strcpy(Customer[k].tel_number,phone_number);
						Array_to_File();
						line(3);
						space(6);
						printf("You have succesfully create an account");
						line(2);
						back_to_menu();	
					}
					void ShowCustomer()
					{
						int num;
						system("cls");
						line(5);
						space(6);
						printf("Enter the account number of the customer: ");
						scanf("%d",&num);
						for(int i=0;i<10;i++)
						{
							if(num==Customer[i].account_number)
							{
								space(5);
								printf("%d\t%s\t%lf",Customer[i].account_number,Customer[i].full_name,Customer[i].balance);
							}
						}
						back_to_menu();
						
					}
					void DeleteCustomer()
					{
						int num;
						system("cls");
						line(5);
						space(6);
						printf("Enter the account number of the customer: ");
						scanf("%d",&num);
						for(int i=0;i<10;i++)
						{
							if(num==Customer[i].account_number)
							{
								Customer[i].account_number=0;
								strcpy(Customer[i].address,"");
								Customer[i].balance=0;
								Customer[i].date_of_birth.day=0;
								Customer[i].date_of_birth.month=0;
								Customer[i].date_of_birth.year=0;
								strcpy(Customer[i].full_name,"");
								strcpy(Customer[i].tel_number,"");
							}
						}
						Array_to_File();
						back_to_menu();
					}
					void DepositMoney()
					{
						int num;
						double money;
						system("cls");
						line(5);
						space(6);
						printf("Enter the account number of the customer: ");
						scanf("%d",&num);
						space(6);
						printf("Enter the amount of money for the deposit: ");
						scanf("%lf",&money);
						for(int i=0;i<10;i++)
						{
							if(num==Customer[i].account_number)
							{
								Customer[i].balance=Customer[i].balance+money;	
							}
						}
						Array_to_File();
						back_to_menu();
					}
					
					void WithdrawMoney()
					{
						int num;
						double money;
						system("cls");
						line(5);
						space(6);
						printf("Enter the account number of the customer: ");
						scanf("%d",&num);
						space(6);
						printf("Enter the amount of money you want to withdraw: ");
						scanf("%lf",&money);
						for(int i=0;i<10;i++)
						{
							if(num==Customer[i].account_number)
							{
								Customer[i].balance=Customer[i].balance-money;	
							}
						}
						Array_to_File();
						back_to_menu();
					}
					
					void Array_to_File()//to transfert customers'informations from the array to the file
					{
								cust=fopen("customer.txt","w");
								int i=0;
								for(i;i<=10;i++)
								{
									fprintf(cust,"%d %s %d %d %d %s %s %lf\n",Customer[i].account_number,Customer[i].full_name,Customer[i].date_of_birth.day,Customer[i].date_of_birth.month,Customer[i].date_of_birth.year,Customer[i].address,Customer[i].tel_number,Customer[i].balance);
								}
								fclose(cust);
						
					}
					
					void File_to_Array()//to transfert customers'informations from the file to the array
					{
								char fullname[21]="",address[100]="",phone_number[10]="";
								int day=0, month=0, year=0; 
								double balance=0.00;
								int number=0;
								cust=fopen("customer.txt","r");
								for(int i=0;i<10;i++)
								{
										if(!feof(cust))
										{
											fscanf(cust,"%d %s %d %d %d %s %s %lf\n",&number,fullname,&day,&month,&year,address,phone_number,&balance);
											strcpy(Customer[i].full_name,fullname);
											Customer[i].account_number=number;
											Customer[i].date_of_birth.day=day;
											Customer[i].date_of_birth.month=month;
											Customer[i].date_of_birth.year=year;
											Customer[i].balance=balance;
											strcpy(Customer[i].address,address);
											strcpy(Customer[i].tel_number,phone_number);	
										}
								}
								fclose(cust);
						
					}
					
					
					
					

