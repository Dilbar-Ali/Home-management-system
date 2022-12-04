#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
const int s=100;
class Expenses
{
	private:
		string month;
		int income;
		int gros;
		int edu;
		int med;
		int bill;
		int misc;
		int tax;
		int total;
		int saving;
		friend class Home;
};
class Home
{
	Expenses exp[s];
	int count;
	public:
		Home():count(0){	}
	void addexpeses()
	{ system("cls");
	 char ch;
	 do{
        
		 cout<<"\n enter Month \n";
         cin>>exp[count].month;
         cout<<"\n Enter Total income \n";
         cin>>exp[count].income;
         cout<<"\n Enter Total Groceries Expenses \n ";
         cin>>exp[count].gros;
         cout<<"\n Enter Educational expenses \n ";
         cin>>exp[count].edu;
         cout<<"\n Enter Bills Expenses \n";
         cin>>exp[count].bill;
         cout<<"\n Enter Medical Expenses \n ";
         cin>>exp[count].med;
         cout<<"\n Enter Other Expenses \n ";
         cin>>exp[count].misc;
         cout<<"\n Enter Tax Paid \n ";
         cin>>exp[count].tax;
         exp[count].total=exp[count].gros+exp[count].edu+exp[count].bill+exp[count].med+exp[count].misc+exp[count].tax;
         exp[count].saving=exp[count].income-exp[count].total;
         count++;
         cout<<"\nDO YOU ANT TO ADD ANOTHER ";
         cin>>ch;
         	}while(ch=='y' or ch=='Y');
         	cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
        
	}
	void display()
    { 
        system("cls");
        if (count != 0)
        {    	cout.flags(ios::left);
		cout<<setw(6)<<"Month"<<setw(10)<<"income"<<setw(25)<<"Grocery Expense"<<setw(25)<<"Educational Expenses"<<setw(15)<<"Bill Expense"<<setw(25)<<"Medical Expenses"<<setw(10)<<"Tax"<<setw(20)<<"total Expenses "<<setw(10)<<"saving"<<endl;
             
        	for(int i=0;i<count;i++)
        	{
        		cout.flags(ios::left);
                cout<<setw(6)<<exp[i].month<<setw(10)<<exp[i].income<<setw(25)<<exp[i].gros<<setw(25)<<exp[i].edu<<setw(15)<<exp[i].bill<<setw(25)<<exp[i].med<<setw(10)<<exp[i].tax<<setw(20)<<exp[i].total<<setw(10)<<exp[i].saving<<endl;

			}
		}
		else
		{
            cout << "No data is entered" << endl;
        }
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
        
    }
	   void searchexpense()
    {   system("cls");
        if (count != 0)
        {
            string m;
            cout << "Enter month of which you want to search the expense" << endl;
            cin >> m;
            int f = -1;
            for (int i = 0; i <count; i++)
            {
                if (exp[i].month == m)
                {
                    f =i;
                    system("cls");
                    cout << "\nExpense of Month " <<exp[i].month << endl;
                    cout << "INCOME of Month " <<exp[i].income << endl;

                    cout << "GROCERY EXPENSE " << exp[i].gros << endl;
                    cout << "EDUCATIONAL EXPENSE: " << exp[i].edu << endl;
                    cout << "MRDICAL EXPENSE: " << exp[i].med << endl;
                    cout << "BILLS: " << exp[i].bill << endl;
                    cout << "OTHER EXPENSE: " << exp[i].misc << endl;
                    cout << "TOTAL: " << exp[i].total << endl;
                    cout << "SAVINGS: " << exp[i].saving << endl;

                }
            }
            if(f == -1){
                cout << "No data is Found" << endl;
            }
        }
        else
        {

            cout << "No data is entered" << endl;
        }
        cout<<"--------------------------------------"<<endl;
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
        
    }
    void editexpense()
    {   system("cls");
        if (count != 0)
        {
            string m;
            cout << "Enter MOnth which you want to update/Edit" << endl;
            cin >> m;
            int f = -1;
            for (int i = 0; i < count; i++)
            {
                if (exp[i].month == m)
                {
                    f = i;
                    system("cls");
                    cout<<"------------------:)--------------------"<<endl;
                    cout<<"\n enter Month \n";
			         cin>>exp[f].month;
			         cout<<"\n Enter Total income \n";
			         cin>>exp[f].income;
			         cout<<"\n Enter Total Groceries Expenses \n ";
			         cin>>exp[f].gros;
			         cout<<"\n Enter Educational expenses \n ";
			         cin>>exp[f].edu;
			         cout<<"\n Enter Bills Expenses \n";
			         cin>>exp[f].bill;
			         cout<<"\n Enter Medical Expenses \n ";
			         cin>>exp[f].med;
			         cout<<"\n Enter Other Expenses \n ";
			         cin>>exp[f].misc;
			         cout<<"\n Enter Tax Paid \n ";
			         cin>>exp[f].tax;
			         exp[f].total=exp[f].gros+exp[f].edu+exp[f].bill+exp[f].med+exp[f].misc+exp[f].tax;
			         exp[f].saving=exp[f].income-exp[f].total;
					
                    break;
                }
            }
            if(f ==-1){
                cout << "No expense is Found" << endl;
            }
        }
        else
        {
            cout << "No expense is entered" << endl;
        }
        cout<<"------------------:)--------------------"<<endl;
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
    }
     void delet()
    {   system("cls");
        if (count != 0)
        {
            int op = 0;
            cout << "Press 1 to delete any month expense" << endl;
            cout << "Press 2 to delete All expenses" << endl;
            cin >> op;
            if (op== 1)
            {   system("cls");
                string m; int f = -1;
                cout << "Enter Month To Delete" << endl;
                cin >> m;

                for (int i = 0; i < count; i++)
                {
                    if (exp[i].month == m){
                        f = i;
                        break;
                    }
                }
                if(f == -1){
                        cout << "No such record found" << endl;
                }
                else{
                    for (int i = f; i <count-1; i++)
                        exp[i] = exp[i+1];
                    cout << "Deleted Successfully" << endl;
                    count--;                    
                }
            }
            else if (op == 2)
            {
                count = 0;
                cout << "All Expenses deleted:)" << endl;
            }
            
        }
        else
        {
            cout << "No data is entered:)" << endl;
        }
        cout << "Press Enter to continue...." << endl;
        cin.get();
        cin.ignore();
    }
};
    void menu()
 {   system("cls");
     cout<<"\n\t\tMain Menu\n";
     cout<<"\n 1: ADD EXPENSE";
     cout<<"\n 2: SEARCH ANY MONTH EXPENSES";
     cout<<"\n 3: DELETE EXPENSES";
     cout<<"\n 4: EDIT EXPENSES";
	cout<<"\n 5: DISPLAY EXPENSES";
    cout<<"\n 6: Exit";

 }

int main()
{

    cout << "\n\n\t\tHome Management System" << endl;
    int opt;
    Home h;
    
     while (true)
    {   
        menu();
        cin>>opt;
         switch (opt)
        {
        case 1:
            {
            	h.addexpeses();
            cout<<"\nADDED SUCCESSFULLY ";
            ofstream fiwrite;
					fiwrite.open("E:\\home.txt",ios::binary);
					if(fiwrite.fail()==true)
					{
					cout<<"File not opened"<<endl;
					exit(1);
					}
					fiwrite.write((char*)&h, sizeof(h));
					fiwrite.close();
            break;
			}
        case 2:
           {
           		ifstream firead;
			firead.open("E:\\home.txt",ios::binary);
			if(firead.fail()==true)
			{
			cout<<"File not found"<<endl;
			exit(1);
			}
			firead.read((char*)&h, sizeof(h));
			h.searchexpense();

			firead.close();	

            break;
			} 
        case 3:
          {  h.delet();

            break;
		  }
        case 4:
           {
           	 h.editexpense();
           	 ofstream fiwrite;
					fiwrite.open("E:\\home.txt",ios::binary);
					if(fiwrite.fail()==true)
					{
					cout<<"File not opened"<<endl;
					exit(1);
					}
					fiwrite.write((char*)&h, sizeof(h));
					fiwrite.close();
            cout<<"\nEDITED SUCCESSFULLY ";

            break;
		   }
        case 5:
        	{
        		ifstream firead;
			firead.open("E:\\home.txt",ios::binary);
			if(firead.fail()==true)
			{
			cout<<"File not found"<<endl;
			exit(1);
			}
			firead.read((char*)&h, sizeof(h));
		
			firead.close();	
            	h.display();
            break;
			}
        case 6:
           {
           	 exit(1);
        
		   }
        }
        
    }
    return 0;
}