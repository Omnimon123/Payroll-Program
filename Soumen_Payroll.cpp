//Preprocessor Directives
#include <iostream>
#include <iomanip> 
using namespace std;


int main()
{
    //Variable Declarations:
    int employeeNum=0; //Varible that stores the number of employees
    int option=0; //Varible that stores the user's option
    int employee=0; //Varible that stores the employee number
    int change=0; //Varible that stores the number that the user choose
    int infinite=1; //Variable that stores an arbritray number to allow the do while loop to be infinite
    //Function Body
    cout<<"How many pay slips would you like to produce?"<<endl; //Displays the words in quotations
    cin>>employeeNum; //Accepts user input
    while (!cin.good())  //While the  user didn't enter a number, their input will not be accepted
	{
		cout<<"Invalid Entry"<<endl<<endl; 
		cout<<"Please enter the number of pay slips that you would like to prduce: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin>>employeeNum;	
	}
    float paySlip[employeeNum][8]; //declares the variable that stores the user input and the output
    for (int i=0; i<employeeNum; i++) //For loop for accepting the user input
    {
    	cout<<"Please Enter the Employee Number: "; //Displays the words in quotations
		cin>>paySlip[i][0];
		while (!cin.good())  //While the  user didn't enter a number, their input will not be accepted	
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the the Employee Number: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>paySlip[i][0];	
		}
		while (paySlip[i][0]<0) //Their input will not be accepted while the user entered a negative number
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the the Employee Number: ";
			cin>>paySlip[i][0];
		}
		for (int v=0; v<employeeNum; v++) //For loop that checks if the user entered the same employee number before
		{
				while (paySlip[i][0]==paySlip[v][0] && v!=i) 
				{
					cout<<"The same employee number can't be entered twice"<<endl;
					cout<<"Please Enter the Employee Number: ";
					cin>>paySlip[i][0];
				}
		}
		cout<<"Please Enter the Employee Hourly Rate: $"; //Displays the words in quotations
		cin>>paySlip[i][1]; //Accepts user input
		while (!cin.good())  //While the  user didn't enter a number, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the Employee Hourly Rate: $";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>paySlip[i][1];	
		}
		while (paySlip[i][1]<=0) //Their input will not be accepted while the user entered a negative number or if he or she entered 0
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the Employee Hourly Rate: $";
			cin>>paySlip[i][1];
		}
		cout<<"Please Enter the Number of Hours Worked: "; //Displays the words in quotations
		cin>>paySlip[i][2]; //Accepts user input
		while (!cin.good())  //While the  user didn't enter a number, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the Number of Hours Worked: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>paySlip[i][2];	
		}
		while (paySlip[i][2]<0 || paySlip[i][2]>335) //While the user entered a number in the incorretc range, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please enter the Number of Hours Worked: ";
			cin>>paySlip[i][2];
		}
		//Displays the words in quotations
		cout<<"Enter United Way Contribution: "<<endl; 
		cout<<"0\tNo Contribution"<<endl; 
		cout<<"1\tYes Contribution"<<endl;
		cout<<"Contribution: ";
		cin>>paySlip[i][3]; //Accepts user input
		while (!cin.good())  //While the  user didn't enter a number, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the United Way Contribution: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>paySlip[i][3];	
		}
		while (paySlip[i][3]<0 || paySlip[i][3]>1) //While the user entered a number in the incorrect range, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please Enter the United Way Contribution: ";
			cin>>paySlip[i][3];
		}
		//Caclucaltes the united way deductions based on user input
		if (paySlip[i][2]<=80) 
		{
			paySlip[i][4] = paySlip[i][1]*paySlip[i][2];
		} 	
		else if (paySlip[i][2]>80)
		{
			paySlip[i][4] = (paySlip[i][2]-80)*(paySlip[i][1]*1.5)+(paySlip[i][1]*80);
		}
		//Calculates tax deductions based on the user's input
		if (paySlip[i][3]==0)
		{
			paySlip[i][5]=0;
		}
		else if (paySlip[i][3]==1)
		{
			paySlip[i][5]=20;
		}
		if (paySlip[i][4]<96)
		{
			paySlip[i][6]=0;
		}
		else if (paySlip[i][4]>=96 && paySlip[i][4]<480)
		{
			paySlip[i][6]= 0.1 * paySlip[i][4];
		}
		else if (paySlip[i][4]>=480 && paySlip[i][4]<1656)
		{
			paySlip[i][6]=(0.15 * paySlip[i][4]) + 38.4;
		}
		else if (paySlip[i][4]>=1656 && paySlip[i][4]<3877)
		{
			paySlip[i][6]=(0.25 * paySlip[i][4]) + 214.8;
		}
		else if (paySlip[i][4]>=3877 && paySlip[i][4]<7983)
		{
			paySlip[i][6]=(0.28 * paySlip[i][4]) + 770.05;
		}
		else if (paySlip[i][4]>7983)
		{
			paySlip[i][6]=(0.33 * paySlip[i][4]) + 1919.73; 
		}
		//Calculates the net pay
		paySlip[i][7]= paySlip[i][4] - (paySlip[i][5] + paySlip[i][6]);
		cout<<endl;	
		cout<<fixed;
		//Displays the words in quotations and their assigned value
		cout<<"Gross Pay"<<endl;
		cout<<"$"<<setprecision(2)<<paySlip[i][4]<<endl;
		cout<<"United Way Deductions"<<endl;
		cout<<"$"<<setprecision(2)<<paySlip[i][5]<<endl;
		cout<<"Tax Deductions"<<endl;
		cout<<"$"<<setprecision(2)<<paySlip[i][6]<<endl;
		cout<<"Net Pay"<<endl;
		cout<<"$"<<setprecision(2)<<paySlip[i][7]<<endl;
		cout<<endl;
	}  
	
	do 
	{
		//Displays the statements in quotations
		cout<<"Choose an option below:"<<endl;
		cout<<"1) View the information of any employee's account"<<endl;
		cout<<"2) Edit information for a certain employee's account"<<endl;
		cout<<"3) Delete an employee's record"<<endl;
		cout<<"4) Exit"<<endl;
		cout<<"Option: ";
		cin>>option; //Accepts user input
		cout<<endl;
		while (!cin.good())  //While the user didn't enter a number, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please press one of the numbers above: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>option;
			cout<<endl<<endl;	
		}
		while (option<1 || option>4) //While the user entered a number in the incorrect range, their input will not be accepted
		{
			cout<<"Invalid Entry"<<endl<<endl;
			cout<<"Please press one of the numbers above: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin>>option;	
		}
		switch(option)
		{
			case 1: //If the user entered 1 then
			cout<<"Please enter the employee number\nof the acctount that you would like to view: "; //Displays the words in quotations
			cin>>employee;
			cout<<endl;
			while (!cin.good())  //While the  user didn't enter a number, they will be asked to enter a number.
			{
				cout<<"Invalid Entry"<<endl<<endl;
				cout<<"Please enter the employee number: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin>>employee;	
			}
			for (int n=0; n<employeeNum; n++)
			{
				if (employee==paySlip[n][0])
				{
					//The user will not be able to do to view a deleted account
					if (paySlip[n][1]==0)
					{
						cout<<"The account for employee "<<employee<<" does not exist"<<endl;
						cout<<endl;
					}
					else 
					{
						//The information for the account that the user chose to recall will be displayed
						cout<<fixed;
						cout<<"Gross Pay"<<endl;
						cout<<"$"<<setprecision(2)<<paySlip[n][4]<<endl;
						cout<<"United Way Deductions"<<endl;
						cout<<"$"<<setprecision(2)<<paySlip[n][5]<<endl;
						cout<<"Tax Deductions"<<endl;
						cout<<"$"<<setprecision(2)<<paySlip[n][6]<<endl;
						cout<<"Net Pay"<<endl;
						cout<<"$"<<setprecision(2)<<paySlip[n][7]<<endl;
						cout<<endl;
					}
				}
			}		
			break;
			case 2: //If the user entered 2 then
				cout<<"Please enter the employee number \nof the account that you would like to edit: ";
				cin>>employee;
				cout<<endl;
				while (!cin.good())  //While the  user didn't enter a number, they will be asked to enter a number.
				{
					cout<<"Invalid Entry"<<endl<<endl;
					cout<<"Please enter the employee number: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin>>employee;	
				}

				for (int r=0; r<employeeNum; r++)
				{
					if (employee==paySlip[r][0])
					{
						//The user will not be able to do to view a deleted account
						if (paySlip[r][1]==0)
						{
							cout<<"The account for employee "<<employee<<" does not exist"<<endl;
							cout<<endl;
						}
						else 
						{
							//Displays the words in quotations
							cout<<"What would you like to change?"<<endl;
							cout<<"1) The employee number"<<endl;
							cout<<"2) The employee hourly rate"<<endl;
							cout<<"3) The number of hours worked"<<endl;
							cout<<"4) United Way contribution"<<endl;
							cout<<"Please press one of the numbers above: ";
							cin>>change;
							while (!cin.good())  //While the user didn't enter a number, their input will not be accepted
							{
								cout<<"Invalid Entry"<<endl<<endl;
								cout<<"Please press one of the numbers above: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin>>change;	
							}
							cout<<endl; //Ends the line
							//Replaces the values of the array that were preiously entered by the new values that were entered
							if (change==1)
							{
								cout<<"The employee number is: ";
								cin>>paySlip[r][0];
								cout<<endl;
							}
							else if (change==2)
							{
								cout<<"The employee hourly rate is: $";
								cin>>paySlip[r][1];
								cout<<endl;
							}
							else if (change==3)
							{
								cout<<"The number of hours worked is: ";
								cin>>paySlip[r][2];
								cout<<endl;
							}
							else if (change=4)
							{
								cout<<"The united way contribution is: ";
								cin>>paySlip[r][3];
								cout<<endl;
							}
							//Caclucaltes the united way deductions based on user input
							if (paySlip[r][2]<=80)
							{
								paySlip[r][4] = paySlip[r][1]*paySlip[r][2];
							} 	
							else if (paySlip[r][2]>80)
							{
								paySlip[r][4] = (paySlip[r][2]-80)*(paySlip[r][1]*1.5)+(paySlip[r][1]*80);
							}
							//Calculates tax deductions based on the user's input
							if (paySlip[r][3]==0)
							{
								paySlip[r][5]=0;
							}
							else if (paySlip[r][3]==1)
							{
								paySlip[r][5]=20;
							}
							if (paySlip[r][4]<96)
							{
								paySlip[r][6]=0;
							}
							else if (paySlip[r][4]>=96 && paySlip[r][4]<480)
							{
								paySlip[r][6]= 0.1 * paySlip[r][4];
							}
							else if (paySlip[r][4]>=480 && paySlip[r][4]<1656)
							{
								paySlip[r][6]=(0.15 * paySlip[r][4]) + 38.4;
							}
							else if (paySlip[r][4]>=1656 && paySlip[r][4]<3877)
							{
								paySlip[r][6]=(0.25 * paySlip[r][4]) + 214.8;
							}
							else if (paySlip[r][4]>=3877 && paySlip[r][4]<7983)
							{
								paySlip[r][6]=(0.28 * paySlip[r][4]) + 770.05;
							}
							else if (paySlip[r][4]>7983)
							{
								paySlip[r][6]=(0.33 * paySlip[r][4]) + 1919.73; 
							}
							//Calculates the net pay
							paySlip[r][7]= paySlip[r][4] - (paySlip[r][5] + paySlip[r][6]);	
							cout<<endl;
						}
					}
				}			
				break;
			case 3://If the user entered 3 then
				cout<<"Please enter the employee number \nof the acctount that you would like to delete: "; //Displays the words in quotations
				cin>>employee;
				while (!cin.good())  //While the user didn't enter a number, their input will not be accepted
				{
					cout<<"Invalid Entry"<<endl<<endl;
					cout<<"Please enter the employee number: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin>>employee;	
				}
				cout<<endl; //Ends the line
				//Sets the values of some values in the array to 0 and notifies the user that the account that they chose to be deleted was deleted
				for (int t=0; t<employeeNum; t++)
				{
					if (employee==paySlip[t][0])
					{
						paySlip[t][1]=0;
						paySlip[t][2]=0;
						paySlip[t][3]=0;
						cout<<"Employee "<<employee<<"'s account has been deleted"<<endl<<endl;
					}
				}
				break;
			case 4: //If the user entered 3 then:
			{
				system("cls"); //Clears the screen
				cout<<"Thank you for using the program. Goodbye!"; //Displays the statement in quotations
				exit(0); //Exits the program with a return value of 0
				break; 
				
			}
		}
	} while (infinite==1);	
    return 0;
}
//end function main

