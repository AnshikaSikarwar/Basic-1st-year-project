#include<iostream>
#include<cstdlib>
#include<ctime>
#include <iomanip>
#include <cstdio>
#ifndef nullptr
#define nullptr NULL
#endif

using namespace std;
class Employee{
	protected:
	int Id,index;
	struct employee{
		string Name,Designation;
		int EmpId,Phone_no;
	}employee[100];
	public:
		Employee()
		{
		index=0;	
		}
		void add_data();
		void show();
		void update();
		void del();
	};
		void Employee::add_data()
		{
			cout<<"Enter data of person"<<endl;
			cout<<"Enter name : ";
            cin>>employee[index].Name;
			cout<<"Enter EmpID : ";
			cin>>employee[index].EmpId;
			cout<<"Enter Designation : ";
			cin>>employee[index].Designation;
			cout<<"Enter Mobile number : ";
			cin>>employee[index].Phone_no;
			index++;
		}
		void Employee::show()
		{
			for(int i=0;i<index;i++){
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<employee[i].Name<<endl;
		cout<<"ID: "<<employee[i].EmpId<<endl;
		cout<<"Designation: "<<employee[i].Designation<<endl;
		cout<<"Contact: "<<employee[i].Phone_no<<endl;    
        }
        cout<<"List is mentioned above";
		}
		void Employee::update()
		{
			cout<<"Enter ID of employee whose data you want to update : ";
			cin>>Id;
			for(int i=0;i<index;i++){
				if(Id==employee[i].EmpId){
					cout<<"Your previous data"<<endl;
					cout<<"Name : "<<employee[i].Name<<endl;
					cout<<"Id : "<<employee[i].EmpId<<endl;
					cout<<"Designation : "<<employee[i].Designation<<endl;
					cout<<"Contact : "<<employee[i].Phone_no<<endl;
					cout<<"Enter new data"<<endl;
					cout<<"Enter Name : ";
					cin>>employee[i].Name;
					cout<<"Enter EmpId : ";
					cin>>employee[i].EmpId;
					cout<<"Enter your designation : ";
					cin>>employee[i].Designation;
					cout<<"Enter your contact no. : ";
					cin>>employee[i].Phone_no;
				}
				else
				cout<<"No record found "<<endl;
			}
		}
		void Employee::del()
		{
			cout<<"Enter id of employee whose data you want to remove"<<endl;
     cin>>Id;
     for(int i=0;i<index;i++){
     	if(Id==employee[i].EmpId){
     		for(int j=i;j<index;j++){
     		employee[j].Name=employee[j+1].Name;
     		employee[j].EmpId=employee[j+1].EmpId;
     		employee[j].Designation=employee[j+1].Designation;
     		employee[j].Phone_no=employee[j+1].Phone_no;
     		index--;
     		cout<<"Your required data is deleted"<<endl;
		}
	}
		else{
		cout<<"No record found"<<endl;
	}
}
}
void exit(){
	cout<<"Exiting the program. THANK YOU!"<<endl;
	exit(0);
}
class Salary:public Employee
{
	protected:
double baseSalary;
    int workingDays;
    int halfDays;
    int overtimeHours;
    int leavesTaken;
    int successfulProjects;
    public:
    		void choice();
    	double calculateSalary();
    };
    void Salary::choice()	
		{
			int i;
			while(1){
			cout<<"\n\n PRESS "<<endl;cout<<"1. FOR ADD NEW EMPLOYEE"<<endl;cout<<"2. VIEW EMPLOYEES LIST"<<endl;
			cout<<"3. UPDATE DETAILS OF EXISTING EMPLOYEE"<<endl;cout<<"4. DELETE AN EXISTING EMPLOYEE ACCOUNT"<<endl;
			cout<<"5. CALCULATE SALARY OF EMPLOYEE"<<endl;cout<<"6. EXIT THE PROGRAM"<<endl;
			cin>>i;
			switch(i){
			case 1:
			add_data();
			break;
			case 2:
			show();
			break;
			case 3:
			update();
			break;
			case 4:
			del();
			break;
			case 5:
			calculateSalary();
			break;
			case 6:
			exit();
			break;
			default:
				cout<<"Not matched with options";
				break;
			}
			//system("cls");
		}
		system("cls");
	}
    double Salary::calculateSalary() {
    int empId;
    cout << "Enter the EmpId of the employee whose salary you want to calculate: ";
    cin >> empId;
    for (int i = 0; i < index; i++) {
        if (employee[i].EmpId == empId)
        {
        	baseSalary = 100000;
    cout << "Enter number of working days: ";
    cin >> workingDays;
    cout << "Enter number of half days: ";
    cin >> halfDays;
    cout << "Enter number of overtime hours: ";
    cin >> overtimeHours;
	 "Enter number of leaves taken: ";
    cin >> leavesTaken;
    cout << "Enter number of successful projects: ";
    cin >> successfulProjects;
        	 double grossSalary = baseSalary;
    grossSalary += (workingDays - halfDays) * (baseSalary / 30);
    grossSalary += overtimeHours * (baseSalary / (30 * 8));
 grossSalary -= leavesTaken * (baseSalary / 30);
    double bonus = successfulProjects * (baseSalary * 0.01);
    return grossSalary + bonus;
		}
		else
		cout<<"Entered EmpId is not registered";
	}
}
int main()
{
	cout<<setw(70)<<"*****************************************"<<endl;
	cout<<setw(70)<<" WELCOME TO EMPLOYEE MANAGEMENT SYSTEM "<<endl;
	cout<<setw(70)<<"*****************************************"<<endl<<endl<<endl;
	cout<<setw(70)<<"Created by - "<<endl;
	cout<<setw(70)<<"Anshika Sikarwar - A60205222369"<<endl;
	time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    char timeString[100];
    strftime(timeString, sizeof(timeString), "%c", localTime);
    cout<<right<<setw(120)<<"Current Date and Time: "<<endl;
	cout<<right<<setw(120) << timeString <<endl;
    cout<<right<<setw(120)<< "Press any key to continue..."<<endl;
    getchar();
    system("cls");
	cout << "Program is now running!";
	Employee E1;
	Salary S;
	S.choice();
	return 0;
}
