#include <iostream>
#include <string>
#include<windows.h>   			  //clrs
#include<conio.h>    			 //getch

using namespace std;
class Railway                 //main class

{
private:
    struct Train
    {
        int id;
        string name;
        string source;
        string destination;
        int capacity;
        int availableSeats;
        int price;
        Train* next; 
    };

    Train* head = NULL;

public:
    class Admin     	//sub-classes 
    {
    public:													//functions calling by reference 
        void adminPanel(Railway& railway);
        void addTrain(Railway& railway);
        void updateTrain(Railway& railway);
        void deleteTrain(Railway& railway);
        void searchTrain(Railway& railway);
       // void showTrainRecords(Railway& railway);
    };

    class User
    {
    public:
        void userPanel(Railway& railway);
        void bookTicket(Railway& railway);
        void checkTrain(Railway& railway);
        void issueTicket(Railway& railway);
        void validateTicket(Railway& railway);
    };

    class Staff
    {
    public:
    	void showTrainRecords(Railway& railway);
        void staffPanel(Railway& railway);
        void generateRevenueReport(Railway& railway); 
        void generateOccupancyReport(Railway& railway);
     
    };
    void admin();
    void user();
    void staff(); 
};

void Railway::Admin::adminPanel(Railway& railway)					//admin menu
{
    string username;
    int pass;
    bool loggedIn = false;
    
    system("cls");
    system("Color 0C");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    		cout << "\t\t\t       Welcome to Admin Panel    " << endl;     
    		cout << "\t\t\t----------------------------------------" << endl << endl;
    cout << endl << "\t--- Login to Admin Panel ---" << endl << endl;

    while (!loggedIn)
    {
        cout << "\tEnter your Username: ";
        cin >> username;

        if (username == "admin")
        {
            cout << "\tNow enter your Password: ";
            cin >> pass;

            if (pass == 1234)
            {
                loggedIn = true;
                break;
            }
            else
            {
                cout << "\tYou entered the wrong password!" << endl;
            }
        }
        else
        {
            cout << "\tYou entered the wrong username!" << endl;
        }
    }

    if (loggedIn)
    {
    
        system("cls");
        int choice;
         system("Color 09");
        cout << endl << "\t\t\t----------------------------------------" << endl;
        cout << "\t\t\t             Admin Panel    " << endl;       
        cout << "\t\t\t----------------------------------------" << endl << endl;
        cout << "\t 1. Add Train" << endl;
        cout << "\t 2. Update Train" << endl;
        cout << "\t 3. Delete Train" << endl;
        cout << "\t 4. Search Train" << endl;
       // cout << "\t 5. Show Train Records" << endl;
        cout << "\t 5. Back" << endl;
        cout << "\t 6. Exit" << endl << endl;
        cout << " Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTrain(railway);
                break;
            case 2:
                updateTrain(railway);
                break;
            case 3:
                deleteTrain(railway);
                break;
            case 4:
                searchTrain(railway);
                break;
            case 5:
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
   
}

void Railway::Admin::addTrain(Railway& railway)			//add train info
{
  
   system("cls");
   system("Color 0D");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t         Add New Train    " << endl;					 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    Train* newTrain = new Train;

    cout << "\tEnter Train ID: ";
    cin >> newTrain->id;
    cout << "\tEnter Train Name: ";
    cin.ignore();
    getline(cin, newTrain->name);
    cout << "\tEnter Source Station: ";
    getline(cin, newTrain->source);
    cout << "\tEnter Destination Station: ";
    getline(cin, newTrain->destination);
    cout << "\tEnter Train Capacity: ";
    cin >> newTrain->capacity;
    cout<<"\tEnter price per ticket: $";
	cin>>newTrain->price;
    newTrain->availableSeats = newTrain->capacity;
    newTrain->next = NULL;

    if (railway.head == NULL)
    {
        railway.head = newTrain;
    }
    else
    {
        Train* temp = railway.head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTrain;
    }

    cout << endl << "\t\tTrain added successfully!" << endl;
    cout<<"\nPress any key to continue "<<endl;
    getch();
}

void Railway::Admin::updateTrain(Railway& railway)		//update train info
{
   
	 system("cls");
	 system("Color 08");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t        Update Train    " << endl;						 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "\tEnter the Train ID to update: ";
    cin >> trainID;

    Train* temp = railway.head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        cout << "\tEnter new Train Name: ";
        cin.ignore();
        getline(cin, temp->name);
        cout << "\tEnter new Source Station: ";
        getline(cin, temp->source);
        cout << "\tEnter new Destination Station: ";
        getline(cin, temp->destination);
        cout << "\tEnter new Train Capacity: ";
        cin >> temp->capacity;
        cout << "\tEnter new Ticket price: $";
        cin >> temp->price;

        cout << endl << "\t\tTrain updated successfully!" << endl;
    }
    else
    {
        cout << "\tTrain not found!" << endl;
    }
   cout<<"\nPress any key to continue "<<endl;
    getch();
}

void Railway::Admin::deleteTrain(Railway& railway)			//delte train
{
  
    system("cls");
    system("Color 0B");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t         Delete Train    " << endl;							 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "\tEnter the Train ID to delete: ";
    cin >> trainID;

    Train* temp = railway.head;
    Train* prev = NULL;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (found)
    {
        if (prev == NULL)
        {
            railway.head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;

        cout << endl << "\t\tTrain deleted successfully!" << endl;
    }
    else
    {
        cout << "\tTrain not found!" << endl;
    }
    cout<<"\nPress any key to continue "<<endl;
    getch();
}

void Railway::Admin::searchTrain(Railway& railway)			//search train
{
   
   system("cls");
   system("Color 0C");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t        Search Train    " << endl;							 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "\tEnter the Train ID to search: ";
    cin >> trainID;

    Train* temp = railway.head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        cout << endl << "\t Train ID: " << temp->id << endl;
        cout << "\t Train Name: " << temp->name << endl;
        cout << "\t Source Station: " << temp->source << endl;
        cout << "\t Destination Station: " << temp->destination << endl;
        cout << "\t Train Capacity: " << temp->capacity << endl;
        cout << "\t Available Seats: " << temp->availableSeats << endl;
        cout << "\t Ticket Price: $" << temp->price << endl;

    }
    else
    {
        cout << "Train not found!" << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}



void Railway::User::userPanel(Railway& railway)			//user menu
{
    
	system("cls");
    int choice;
    system("Color 0A");
    cout << endl << "\t\t\t ----------------------------------------" << endl;
    cout << "\t\t\t             User Panel    " << endl;						 
    cout << "\t\t\t----------------------------------------" << endl << endl;
    cout << "\t 1. Book Ticket" << endl;
    cout << "\t 2. Check Train" << endl;
    cout << "\t 3. Issue Ticket" << endl;
    cout << "\t 4. Validate Ticket" << endl;
    cout << "\t 5. Back" << endl;
    cout << "\t 6. Exit" << endl << endl;
    cout << "\t   Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            bookTicket(railway);
            break;
        case 2:
            checkTrain(railway);
            break;
        case 3:
            issueTicket(railway);
            break;
        case 4:
            validateTicket(railway);
            break;
        case 5:
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}

void Railway::User::bookTicket(Railway& railway)		//ticket book
{
    
	system("cls");
	system("Color 09");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t          Book Ticket    " << endl;							 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "\tEnter the Train ID: ";
    cin >> trainID;

    Train* temp = railway.head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        if (temp->availableSeats > 0)
        {
            temp->availableSeats--;
            cout << endl << "\t\tTicket booked successfully!" << endl;
        }
        else
        {
            cout << "\tNo seats available on this train!" << endl;
        }
    }
    else
    {
        cout << "\tTrain not found!" << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}

void Railway::User::checkTrain(Railway& railway)			//check train available or not 
{
   
	system("cls");
	system("Color 0D");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t         Check Train    " << endl;						 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "\tEnter the Train ID to check: ";
    cin >> trainID;

    Train* temp = railway.head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        cout << endl << "\tTrain ID: " << temp->id << endl;
        cout << "\tTrain Name: " << temp->name << endl;
        cout << "\tSource Station: " << temp->source << endl;
        cout << "\tDestination Station: " << temp->destination << endl;
        cout << "\tTrain Capacity: " << temp->capacity << endl;
        cout << "\tAvailable Seats: " << temp->availableSeats << endl;
        cout << "\tTicket Price: $" << temp->price << endl;

    }
    else
    {
        cout << "Train not found!" << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}

void Railway::User::issueTicket(Railway& railway)			//generate ticket 
{
    
	system("cls");
	system("Color 0C");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t         Issue Ticket    " << endl;						 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "\tEnter the Train ID: ";
    cin >> trainID;

    Train* temp = railway.head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        if (temp->availableSeats > 0)
        {
            temp->availableSeats--;
        
        cout<<"\n\t*************************************"<<endl;
            cout << "\t Train ID: " << temp->id << endl;
            cout << "\t Train Name: " << temp->name << endl;
            cout << "\t Source Station: " << temp->source << endl;
            cout << "\t Destination Station: " << temp->destination << endl;
            cout << "\t Train Capacity: " << temp->capacity << endl;
            cout << "\t Available Seats: " << temp->availableSeats << endl;
            cout << "\t Ticket Price: $" << temp->price << endl<< endl;
        cout<<"\n\t*************************************"<<endl;
		cout  << "\t Ticket issued successfully!" <<endl;
        }
        else
        {
            cout << "\tNo seats available on this train!" << endl;
        }
    }
    else
    {
        cout << "Train not found!" << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}

void Railway::User::validateTicket(Railway& railway)			//check ticket valid or not 
{
   
	system("cls");
	system("Color 0F");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t        Validate Ticket    " << endl;					 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    int trainID;
    cout << "Enter the Train ID: ";
    cin >> trainID;

    Train* temp = railway.head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->id == trainID)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        cout << endl << "\t\tTicket validated successfully!" << endl;
    }
    else
    {
        cout << "\tTrain not found!" << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}

void Railway::Staff::staffPanel(Railway& railway)       //staff menu
{
    
	system("cls");
    int choice;
    system("Color 08");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t             Staff Panel    " << endl;					 
    cout << "\t\t\t----------------------------------------" << endl << endl;
    cout << "\t 1. Show train records" << endl;
    cout << "\t 2. Generate Revenue report" << endl;
   cout << "\t 3. Generate Occupancy Report of passengers" << endl;
    cout << "\t 4. Back" << endl;
    cout << "\t 5. Exit" << endl << endl;
    cout << " \t    Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
		showTrainRecords(railway);
            break;
      case 2:
            generateRevenueReport(railway);
            break;
            case 3:
            	generateOccupancyReport(railway);
        case 4:
            break;
        case 5:
            exit(0);
			
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
}
void Railway::Staff::showTrainRecords(Railway& railway)			//show all trains
{
		system("cls");
		system("Color 09");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t        Train Records    " << endl;						 
    cout << "\t\t\t----------------------------------------" << endl << endl;

    Train* temp = railway.head;

    if (temp == NULL)
    {
        cout << "\tNo trains available!" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << "\t Train ID: " << temp->id << endl;
            cout << "\t Train Name: " << temp->name << endl;
            cout << "\t Source Station: " << temp->source << endl;
            cout << "\t Destination Station: " << temp->destination << endl;
            cout << "\t Train Capacity: " << temp->capacity << endl;
            cout << "\t Available Seats: " << temp->availableSeats << endl;
            cout << "\t Ticket Price: $" << temp->price << endl<< endl;
            temp = temp->next;
        }
            

    }
    cout<<"\n Press any key to continue "<<endl;
    getch();
    staffPanel(railway);
    
	
}
void Railway::Staff::generateRevenueReport(Railway& railway)		//train revenue
{
    Train* current = railway.head;
    while (current != NULL) {
        double revenue = (current->capacity - current->availableSeats) * current->price;
	 system("Color 0B");
    cout << endl << "\t\t\t----------------------------------------" << endl;
    		cout << "\t\t\t            Revenue Report    " << endl;					 
    		cout << "\t\t\t----------------------------------------" << endl << endl;
        cout << "\tTrain ID: " << current->id << endl;
        cout << "\tRevenue: $" << revenue << endl;
        cout << endl;

        current = current->next;  // Move to the next train
    }
     cout<<"\n Press any key to continue "<<endl;
    getch();
    staffPanel(railway);
}
void::Railway::Staff::generateOccupancyReport(Railway& railway) 		//train occupancy
{
    Train* current = railway.head;
    while (current != NULL) {
        double occupancy = (current->capacity - current->availableSeats) * 100.0 / current->capacity;
     system("Color 0D");
    cout << endl << "\t\t\t----------------------------------------" << endl;
   			cout << "\t\t\t             Occupancy Report    " << endl;					 
   			cout << "\t\t\t----------------------------------------" << endl << endl;
        cout << "\tTrain ID: " << current->id << endl;
        cout << "\tOccupancy: " << occupancy << "%" << endl;
        cout << endl;

        current = current->next;  
    }
     cout<<"\n Press any key to continue "<<endl;
    getch();
    staffPanel(railway);
}

void Railway::admin()
{
    Admin admin;           		  //obj
    admin.adminPanel(*this);	  //call
}

void Railway::user()
{
    User user;
    user.userPanel(*this);
}

void Railway::staff()
{
    Staff staff;
    staff.staffPanel(*this);
}

int main()
{
    Railway railway;
    int choice;

    while (true)
    {
    	
        system("cls");
        system("Color 0F");
        cout << endl << "\t\t\t----------------------------------------" << endl;
        cout << "\t\t\t      Railway Management System    " << endl;
        cout << "\t\t\t----------------------------------------" << endl << endl;
        cout << "\t 1. Admin" << endl;
        cout << "\t 2. User" << endl;
        cout << "\t 3. Staff" << endl;
        cout << "\t 4. Exit" << endl << endl;
        cout << " \t Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                railway.admin();
                break;
            case 2:
                railway.user();
                break;
            case 3:
                railway.staff();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}