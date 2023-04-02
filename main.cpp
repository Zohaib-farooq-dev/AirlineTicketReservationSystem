//A Complete Project using basic concepts of programming
//The Title of the project is Flight Reservation System
//It Includes the use of Functions,Arrays,File Handling
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//prototypes of the functions
void display();
void wschedule();
void ticket();
void urgentticket();
void tcancel();
void admin();
void watch();
void add();
void update();

//defining a structure
struct detail
{
    string cname;
    string day;
    int hour;
    int minute;
    string meridiem;
    string company;
    string fcode;
    string airportname;
};
struct info
{
    string fname;
    string lname;
    long long id;
    long long contactno;
};


int main()
{
    //declaring variables
    int num;
    char bool1='y';
    char bool2;
    char bool3;
    //Just printing the title of Program and name of creator of program
    cout<<setw(100)<<endl;
    cout<<setw(100)<<endl;
    cout<<setw(66)<<" Welcome to Flight Reservation System"<<endl;
    cout<<"\t\t\t"<<setfill('/')<<setw(50)<<"/"<<endl;
    cout<<"\t\t\t\t"<<" Created by Muhammad Zohaib Ali"<<endl;
    cout<<"\t\t\t"<<setfill('/')<<setw(50)<<"/"<<endl;
    cout<<endl;


    //Now asking the user what he wants to do
    //See the flights schedule
    //Book a ticket
    //Cancel the ticket
    //Login as Admin to update schedule and other things in the system
    do
    {
        cout<<"Enter :"<<endl
            <<"1 to see schedule"<<endl
            <<"2 to book a regular ticket"<<endl
            <<"3 to book an urgent ticket"<<endl
            <<"4 to cancel the ticket"<<endl
            <<"5 to login as admin"<<endl;

        cout<<endl;
        cin>>num;

        //if-else condition to do the task what user wants to d
            if(num==1)
           {
              display();//function to display the schedule
           }
            else if(num==2)
           {
              cout<<"Ticket will be reserved if that flight you want is in the schedule."<<endl
                  <<"Do you want to see a schedule"<<endl
                  <<"Enter 'y' for yes and 'n' to exit"<<endl;
              cin>>bool2;

             if(bool2=='y')//if-else condition to differentiate that which function should be called
            {
               display();//function to display schedule
            }
             else
            {
               ticket();//function to take user credentials to book his/her ticket
            }
          }
            else if(num==3)
           {
              cout<<"Ticket will be reserved if that flight you want is in the schedule."<<endl
                  <<"Do you want to see a schedule"<<endl
                  <<"Enter 'y' for yes and 'n' to exit"<<endl;
              cin>>bool3;

              if(bool3=='y')//if-else condition to differentiate that which function should be called
             {
                 display();//function to display schedule
             }
              else
             {
                urgentticket();//function to take user credentials to book his/her ticket
             }

           }
           else if(num==4)
           {
               tcancel();//calling the function to cancel the reserved ticket
           }
           else if(num==5)
           {
              string username,password;

              cout<<"Enter Username:"<<endl;//asking the username
              cin>>username;
              cout<<"Enter password:"<<endl;//asking the password from the admin
              cin>>password;

              if(username=="zohaib"&&password=="Zohaib595")
              {
                 admin();//calling the function to login as admin
              }
              else
              {
                  cout<<"Incorrect Username &Password"<<endl;
              }

           }

           //asking the user that he wants to use another feature of the software or not
        cout<<"Do you want to use any other feature"<<endl
            <<"Enter 'y' for yes and 'n' to exit"<<endl;
        cin>>bool1;
    }
    while(bool1=='y');

    return 0;
}
void display()//function to display the flights schedule
{
    ifstream fsin;//declaring a variable which will be used to open the file
    string schedule;//string type variable
    detail arr[100];//array of struct type
    int i=0;

    //asking the user whether he/she wants to see today schedule or weekly schedule
    cout<<" Do you want to see Today's schedule or  weekly schedule"<<endl;
    cin>>schedule;

    if(schedule=="today")//if-else condition for today or weekly schedule
    {

      fsin.open("airport.txt");//opening the file which has data
      if(!fsin.is_open())//validating the file opening
      {
          cout<<"Trouble in opening the file"<<endl;
      }
      else
      {
          cout<<"File is open"<<endl;
      }
      cout<<"Following Flights are available"<<endl;
      do//loop to read entries from the file till end
      {
          //reading data from the file
          fsin>>arr[i].cname;
          fsin>>arr[i].day;
          fsin>>arr[i].hour;
          fsin>>arr[i].minute;
          fsin>>arr[i].meridiem;
          fsin>>arr[i].company;
          fsin>>arr[i].fcode;
          getline(fsin,arr[i].airportname);


          //printing the available flight details
        cout<< arr[i].cname<<"\t"<<arr[i].day<<"\t"<<arr[i].hour<<":"
            <<arr[i].minute<<arr[i].meridiem<<"\t"<<arr[i].company
            <<"\t"<<arr[i].fcode<<"\t"<<arr[i].airportname<<endl;

          cout<<endl;
          i++;
        }
        while(!fsin.eof());
      fsin.close();//closing the file
    }

    else if(schedule=="weekly")
    {
         wschedule();//calling the function to display weekly schedule
    }
}
void wschedule()
{
    ifstream fsin;//file stream variable to write the data in the file
    detail arr1[100];//array of struct type
    int i=0;


      fsin.open("airport1.txt");//opening the file which has data
      if(!fsin.is_open())//validating the file opening
      {
          cout<<"Trouble in opening the file"<<endl;
      }
      else
      {
          cout<<"File is open"<<endl;
          cout<<endl;
      }
      cout<<"Following Flights are available in this week"<<endl;
      cout<<endl;
      do//loop to read entries from the file till end
      {
          //reading data from the file
          fsin>>arr1[i].cname;
          fsin>>arr1[i].day;
          fsin>>arr1[i].hour;
          fsin>>arr1[i].minute;
          fsin>>arr1[i].meridiem;
          fsin>>arr1[i].company;
          fsin>>arr1[i].fcode;
          getline(fsin,arr1[i].airportname);

        //printing the details of flight
        cout<< arr1[i].cname<<"\t"<<arr1[i].day<<"\t"<<arr1[i].hour<<":"
            <<arr1[i].minute<<arr1[i].meridiem<<"\t"<<arr1[i].company
            <<"\t"<<arr1[i].fcode<<"\t"<<arr1[i].airportname<<endl;
        cout<<endl;
          i++;
        }
        while(!fsin.eof());
      fsin.close();//closing the file
}

void ticket()
{
    //declaring variables
    ofstream fsout;
    int n;
    int price=60000;

    cout<<"How many tickets you want to reserve"<<endl;//asking the  user how many tickets he want to reserve
    cin>>n;
    detail d1[n];//array of struct type
    info arr[n];//array of struct type

    for(int i=0;i<n;i++)//loop to take input from the user for reservation of ticket
    {
        cout<<"---------"<<"Personal Details:"<<"---------"<<endl;
        cout<<"Enter your first name:"<<endl;//first name of the passenger
        cin>>arr[i].fname;
        cout<<"Enter your last name:"<<endl;//last name of the passenger
        cin>>arr[i].lname;
        cout<<"Enter your CNIC without Hyphen '-' "<<endl;//CNIC of the passenger
        cin>>arr[i].id;
        cout<<"Enter your Contact no"<<endl;//contact no of the passenger
        cin>>arr[i].contactno;
        cout<<"---------"<<"Flight Details:"<<"---------"<<endl;
        cout<<"Your Destination"<<endl;//name of the place
        cin>>d1[i].cname;
        cout<<"Day of Flight"<<endl;//day of travelling
        cin>>d1[i].day;
        cout<<"Please tell us the time (hour,minute,AM/PM)"<<endl;//time of travelling
        cin>>d1[i].hour;
        cin>>d1[i].minute;
        cin>>d1[i].meridiem;
        cout<<"Airline Company"<<endl;
        cin>>d1[i].company;
        cout<<"Departure:"<<endl;//departure place
        cin>>d1[i].airportname;
        //getline(cin,d1[i].airportname);


        //printing out  the ticket which is reserved
        cout<<endl;
        cout<<"Here's Your TICKET"<<endl;
        cout<<endl;
        cout<<endl;


        cout<<"\t\t\t\t"<<setw(50)<<"/"<<endl;
        cout<<"\t\t\t\t\t\t"<<"Online Ticket"<<endl
            <<endl
            <<"\t\t\t\t  Passenger Name \t"<<arr[i].fname<<" "<<arr[i].lname<<endl
            <<"\t\t\t\t  CNIC \t\t\t"<<arr[i].id<<endl
            <<"\t\t\t\t  Contact No \t\t"<<arr[i].contactno<<endl
            <<"\t\t\t\t  Place \t\t"<<d1[i].cname<<endl
            <<"\t\t\t\t  Day \t\t\t"<<d1[i].day<<endl
            <<"\t\t\t\t  Time \t\t\t"<<d1[i].hour<<":"<<d1[i].minute<<d1[i].meridiem<<endl
            <<"\t\t\t\t  Airline Company \t"<<d1[i].company<<endl
            <<"\t\t\t\t  Departure\t\t"<<d1[i].airportname<<endl
            <<"\t\t\t\t  Price of the ticket \tRs."<<price<<endl
            <<"\t\t\t\t"<<setw(50)<<"/";
        cout<<endl;

        //writing the data of reserved ticket in the file for future purposes
        fsout.open("Tickets.txt",ios::app);//opening the file to store the data reserved tickets
        fsout<<arr[i].fname<<"\t"<<arr[i].lname<<"\t"<<arr[i].id<<"\t"<<arr[i].contactno<<"\t"<<d1[i].cname
             <<"\t"<<d1[i].day<<"\t"<<d1[i].hour<<"\t"<<d1[i].minute<<"\t"<<d1[i].meridiem
             <<"\t"<<d1[i].company<<"\t"<<price
             <<"\t"<<d1[i].airportname<<endl;
        fsout.close();//closing the file
    }
}
void urgentticket()
{
    //declaring variables
    ofstream fsout;
    int n;
    int price=100000;

    cout<<"How many urgent tickets you want to reserve"<<endl;//asking the  user how many tickets he want to reserve
    cin>>n;
    detail d2[n];//array of struct type
    info arr2[n];//array of struct type

    for(int i=0;i<n;i++)//loop to take input from the user for reservation of ticket
    {
        cout<<"---------"<<"Personal Details:"<<"---------"<<endl;
        cout<<"Enter your first name:"<<endl;//first name of the passenger
        cin>>arr2[i].fname;
        cout<<"Enter your last name:"<<endl;//last name of the passenger
        cin>>arr2[i].lname;
        cout<<"Enter your CNIC without Hyphen '-' "<<endl;//CNIC of the passenger
        cin>>arr2[i].id;
        cout<<"Enter your Contact no"<<endl;//contact no of the passenger
        cin>>arr2[i].contactno;
        cout<<"---------"<<"Flight Details:"<<"---------"<<endl;
        cout<<"Your Destination"<<endl;//name of the place
        cin>>d2[i].cname;
        cout<<"Day of Flight"<<endl;//day of travelling
        cin>>d2[i].day;
        cout<<"Please tell us the time (hour,minute,AM/PM)"<<endl;//time of travelling
        cin>>d2[i].hour;
        cin>>d2[i].minute;
        cin>>d2[i].meridiem;
        cout<<"Airline Company"<<endl;
        cin>>d2[i].company;
        cout<<"Departure"<<endl;//departure place
        cin>>d2[i].airportname;
        //getline(cin,d2[i].airportname);


        //printing the details of urgent ticket reserved
        cout<<endl;
        cout<<"Here's Your TICKET"<<endl;
        cout<<endl;
        cout<<endl;

        cout<<"\t\t\t\t"<<setw(50)<<"/"<<endl;
        cout<<"\t\t\t\t\t"<<"Online Ticket"<<endl
            <<"\t\t\t\t  Passenger Name \t"<<arr2[i].fname<<" "<<arr2[i].lname<<endl
            <<"\t\t\t\t  CNIC  \t\t"<<arr2[i].id<<endl
            <<"\t\t\t\t  Contact No \t\t"<<arr2[i].contactno<<endl
            <<"\t\t\t\t  Place \t\t"<<d2[i].cname<<endl
            <<"\t\t\t\t  Day \t\t\t"<<d2[i].day<<endl
            <<"\t\t\t\t  Time \t\t\t"<<d2[i].hour<<":"<<d2[i].minute<<d2[i].meridiem<<endl
            <<"\t\t\t\t  Airline Company \t"<<d2[i].company<<endl
            <<"\t\t\t\t  Departure\t\t"<<d2[i].airportname<<endl
            <<"\t\t\t\t  Price of the ticket \tRs."<<price<<endl
            <<"\t\t\t\t"<<setw(50)<<"/";
        cout<<endl;

        //writing the data of urgent tickets reserved for future purposes
        fsout.open("UrgentTickets.txt",ios::app);//opening the file to store the data of reserved urgent tickets
        fsout<<arr2[i].fname<<"\t"<<arr2[i].lname<<"\t"<<arr2[i].id<<"\t"<<arr2[i].contactno<<"\t"<<d2[i].cname
             <<"\t"<<d2[i].day<<"\t"<<d2[i].hour<<"\t"<<d2[i].minute<<"\t"<<d2[i].meridiem
             <<"\t"<<d2[i].company<<"\t"<<price
             <<"\t"<<d2[i].airportname<<endl;
        fsout.close();//closing the file
    }

}
void tcancel()//function to cancel the reserved ticket
{
    //declaring variables
    ifstream fsin;
    ofstream fsout;
    int i=0;
    int n;
    string t;
    long long cnic;
    int price;

    //asking the user how many tickets he want to cancel
    cout<<"How many tickets you have reserved you want to cancel"<<endl;
    cin>>n;

    detail d[n];//array of struct type
    info s[n];//array of struct type

    //asking the user that the ticket which he wants to cancel is regular or urgent ticket

    cout<<"You want to cancel your ticket. Is it urgent ticket or regular ticket"<<endl
        <<"Enter urgent(if it is urgent ticket) or regular(if it is regular ticket"<<endl;
    cin>>t;

    //if-else condition to check whether the ticket is regular or urgent
    if(t=="regular")
    {
        //asking the suer its CNIC
        cout<<"What is your CNIC"<<endl;
        cin>>cnic;

        fsout.open("newfile.txt");
        fsin.open("Tickets.txt");

       do
         {
             //reading data of the reserved tickets from the file "Tickets.txt"
            fsin>>s[i].fname;
            fsin>>s[i].lname;
            fsin>>s[i].id;
            fsin>>s[i].contactno;
            fsin>>d[i].cname;
            fsin>>d[i].day;
            fsin>>d[i].hour;
            fsin>>d[i].minute;
            fsin>>d[i].meridiem;
            fsin>>d[i].company;
            fsin>>price;
            getline(fsin,d[i].airportname);


            //if-else condition to compare the cnic user entered with the cnic already in the file
            if(s[i].id==cnic)
            {
                cout<<"Your reserved Ticket is Cancelled"<<endl;
            }
            else if(s[i].id!=cnic)
            {
                //writing the data of reserved ticket in the new file
                fsout<<s[i].fname<<"\t"<<s[i].lname<<"\t"<<s[i].id<<"\t"<<s[i].contactno<<"\t"<<d[i].cname
                     <<"\t"<<d[i].day<<"\t"<<d[i].hour<<"\t"<<d[i].minute<<"\t"<<d[i].meridiem
                     <<"\t"<<d[i].company<<"\t"<<"Rs."<<price
                     <<"\t"<<d[i].airportname<<endl;
            }

              i++;
          }
          while(fsin.eof());

        fsout.close();//closing the file
        fsin.close();

        remove("Tickets.txt");//removing the file
        rename("newfile.txt","Tickets.txt");//renaming the new file

    }
    else if(t=="urgent")
    {
       //asking the suer its CNIC
        cout<<"What is your CNIC"<<endl;
        cin>>cnic;

        //opening the files
        fsout.open("newfile1.txt");
        fsin.open("UrgentTickets.txt");

       do
         {
             //reading data of the reserved tickets from the file "Tickets.txt"
            fsin>>s[i].fname;
            fsin>>s[i].lname;
            fsin>>s[i].id;
            fsin>>s[i].contactno;
            fsin>>d[i].cname;
            fsin>>d[i].day;
            fsin>>d[i].hour;
            fsin>>d[i].minute;
            fsin>>d[i].meridiem;
            fsin>>d[i].company;
            fsin>>price;
            getline(fsin,d[i].airportname);


            //if-else condition to compare the cnic user entered with the cnic already in the file
            if(s[i].id==cnic)
            {
                cout<<"Your reserved Ticket is Cancelled"<<endl;
            }
            else if(s[i].id!=cnic)
            {
                //writing the data of reserved ticket in the new file
                fsout<<s[i].fname<<"\t"<<s[i].lname<<"\t"<<s[i].id<<"\t"<<s[i].contactno<<"\t"<<d[i].cname
                     <<"\t"<<d[i].day<<"\t"<<d[i].hour<<"\t"<<d[i].minute<<"\t"<<d[i].meridiem
                     <<"\t"<<d[i].company<<"\t"<<"Rs."<<price
                     <<"\t"<<d[i].airportname<<endl;
            }

              i++;
          }
          while(fsin.eof());

        fsout.close();//closing the file
        fsin.close();

        remove("UrgentTickets.txt");//removing the file
        rename("newfile1.txt","UrgentTickets.txt");//renaming the new file
    }
}
void admin()
{
    int num;
    //asking the admin what he wants to do
    cout<<"Enter :"<<endl
            <<"1 to see reserved tickets"<<endl
            <<"2 to add any flight in the schedule"<<endl
            <<"3 to update the complete schedule"<<endl;

        cout<<endl;
        cin>>num;

        if(num==1)
        {
            watch();//calling the function to see the reserved tickets
        }
        else if(num==2)
        {
            add();//function to add any flight in the schedule
        }
        else if(num==3)
        {
            update();//function to update the schedule
        }
}
void watch()
{
    //in this function we will print the reserved tickets whether it is regular or urgent
    //declaring variables
    ifstream fsin;
    detail array[100];//array of struct type
    info s[100];//array of struct type
    int price;
    int i=0;

    //opening the file
    fsin.open("Tickets.txt");


    cout<<"Following are regular reserved tickets"<<endl;
    cout<<endl;
    do
    {
        //reading data from the file
            fsin>>s[i].fname;
            fsin>>s[i].lname;
            fsin>>s[i].id;
            fsin>>s[i].contactno;
            fsin>>array[i].cname;
            fsin>>array[i].day;
            fsin>>array[i].hour;
            fsin>>array[i].minute;
            fsin>>array[i].meridiem;
            fsin>>array[i].company;
            fsin>>price;
            getline(fsin,array[i].airportname);

            //printing data of the reserved tickets
            cout<<s[i].fname<<"\t"<<s[i].lname<<"\t"<<s[i].id<<"\t"<<s[i].contactno<<"\t"<<array[i].cname
                <<"\t"<<array[i].day<<"\t"<<array[i].hour<<":"<<array[i].minute<<array[i].meridiem
                <<"\t"<<array[i].company<<"\t"<<"Rs."<<price
                <<"\t"<<array[i].airportname<<endl;
        i++;
    }
    while(!fsin.eof());
    fsin.close();//closing the file


    fsin.open("UrgentTickets.txt");//opening the file

    cout<<"Following are urgent reserved tickets"<<endl;
    cout<<endl;
    do
    {
        //reading the data from the file
            fsin>>s[i].fname;
            fsin>>s[i].lname;
            fsin>>s[i].id;
            fsin>>s[i].contactno;
            fsin>>array[i].cname;
            fsin>>array[i].day;
            fsin>>array[i].hour;
            fsin>>array[i].minute;
            fsin>>array[i].meridiem;
            fsin>>array[i].company;
            fsin>>price;
            getline(fsin,array[i].airportname);

            //printing the data of reserved tickets
            cout<<s[i].fname<<"\t"<<s[i].lname<<"\t"<<s[i].id<<"\t"<<s[i].contactno<<"\t"<<array[i].cname
                <<"\t"<<array[i].day<<"\t"<<array[i].hour<<":"<<array[i].minute<<array[i].meridiem
                <<"\t"<<array[i].company<<"\t"<<"Rs."<<price
                <<"\t"<<array[i].airportname<<endl;
            i++;
    }
    while(!fsin.eof());
    fsin.close();
    cout<<endl;
}
void add()
{
    ofstream fsout;//variable to write the data in the file
    int num;
    string s1;

    //asking the admin that how many flights he want to add on the schedule
    cout<<"How many flights you want to add on the schedule"<<endl;
    cin>>num;

    detail arr[num];

    //asking the admin that in which schedule(today or weekly) he wants to add flight
    cout<<"You wants to add flight in which schedule(today or weekly?)"<<endl;
    cin>>s1;

    if(s1=="today")
    {
       fsout.open("airport.txt",ios::app);//opening the file in append mode

       for(int i=0;i<num;i++)
       {
           //asking the details of the flight from the admin
          cout<<"Enter Destination of the flight "<<endl;//destination of the flight
          cin>>arr[i].cname;
          cout<<"Enter the day of the flight"<<endl;//day of flight
          cin>>arr[i].day;
          cout<<"Enter the time of the flight (hour,minute,meridiem(AM/PM))"<<endl;//time of the flight
          cin>>arr[i].hour;
          cin>>arr[i].minute;
          cin>>arr[i].meridiem;
          cout<<"Enter the company of the Airplane"<<endl;//Airline company of the flight
          cin>>arr[i].company;
          cout<<"Enter the code of flight"<<endl;
          cin>>arr[i].fcode;
          cout<<"Enter Airport name of the departure of flight"<<endl;
          cin>>arr[i].airportname;


          //writing the added flight details in the file
          fsout<< arr[i].cname<<"\t"<<arr[i].day<<"\t"<<arr[i].hour<<":"
               <<arr[i].minute<<arr[i].meridiem<<"\t"<<arr[i].company
               <<"\t"<<arr[i].fcode<<"\t"<<arr[i].airportname<<endl;

       }
       fsout.close();

     }
     else if(s1=="weekly")
     {
         fsout.open("airport1.txt",ios::app);

       for(int i=0;i<num;i++)
       {
           //asking the details of the flight from the admin
          cout<<"Enter Destination of the flight "<<endl;//destination of the flight
          cin>>arr[i].cname;
          cout<<"Enter the day of the flight"<<endl;//day of the flight
          cin>>arr[i].day;
          cout<<"Enter the time of the flight (hour,minute,meridiem(AM/PM))"<<endl;//time of the flight
          cin>>arr[i].hour;
          cin>>arr[i].minute;
          cin>>arr[i].meridiem;
          cout<<"Enter the company of the Airplane"<<endl;//airline company of the flight
          cin>>arr[i].company;
          cout<<"Enter the code of flight"<<endl;
          cin>>arr[i].fcode;
          cout<<"Enter Airport name of the departure of flight"<<endl;
          cin>>arr[i].airportname;


          //writing the added flight details in the file
          fsout<< arr[i].cname<<"\t"<<arr[i].day<<"\t"<<arr[i].hour<<":"
               <<arr[i].minute<<arr[i].meridiem<<"\t"<<arr[i].company
               <<"\t"<<arr[i].fcode<<"\t"<<arr[i].airportname<<endl;

        }
           fsout.close();
       }
}
void update()
{
    ofstream fsout;//variable to write the data in the file
    int n;
    string f;

    //asking the admin that how many flights he want to add on the schedule
    cout<<"How many flights you want to add on the schedule"<<endl;
    cin>>n;

    detail arr[n];

    //asking the admin that in which schedule(today or weekly) he wants to add flight
    cout<<"You wants to add flight in which schedule(today or weekly?)"<<endl;
    cin>>f;

    if(f=="today")
    {
       fsout.open("airport.txt");

       for(int i=0;i<n;i++)
       {
           //asking the details of the flight from the admin
          cout<<"Enter Destination of the flight "<<endl;
          cin>>arr[i].cname;
          cout<<"Enter the day of the flight"<<endl;
          cin>>arr[i].day;
          cout<<"Enter the time of the flight (hour,minute,meridiem(AM/PM))"<<endl;
          cin>>arr[i].hour;
          cin>>arr[i].minute;
          cin>>arr[i].meridiem;
          cout<<"Enter the company of the Airplane"<<endl;
          cin>>arr[i].company;
          cout<<"Enter the code of flight"<<endl;
          cin>>arr[i].fcode;
          cout<<"Enter Airport name of the departure of flight"<<endl;
          cin>>arr[i].airportname;


          //writing the added flight details in the file
          fsout<< arr[i].cname<<"\t"<<arr[i].day<<"\t"<<arr[i].hour<<":"
               <<arr[i].minute<<arr[i].meridiem<<"\t"<<arr[i].company
               <<"\t"<<arr[i].fcode<<"\t"<<arr[i].airportname<<endl;

       }
       fsout.close();//closing the file

     }
     else if(f=="weekly")
     {
         fsout.open("airport1.txt");

       for(int i=0;i<n;i++)
       {
           //asking the details of the flight from the admin
          cout<<"Enter Destination of the flight "<<endl;
          cin>>arr[i].cname;
          cout<<"Enter the day of the flight"<<endl;
          cin>>arr[i].day;
          cout<<"Enter the time of the flight (hour,minute,meridiem(AM/PM))"<<endl;
          cin>>arr[i].hour;
          cin>>arr[i].minute;
          cin>>arr[i].meridiem;
          cout<<"Enter the company of the Airplane"<<endl;
          cin>>arr[i].company;
          cout<<"Enter the code of flight"<<endl;
          cin>>arr[i].fcode;
          cout<<"Enter Airport name of the departure of flight"<<endl;
          cin>>arr[i].airportname;


          //writing the added flight details in the file
          fsout<< arr[i].cname<<"\t"<<arr[i].day<<"\t"<<arr[i].hour<<":"
               <<arr[i].minute<<arr[i].meridiem<<"\t"<<arr[i].company
               <<"\t"<<arr[i].fcode<<"\t"<<arr[i].airportname<<endl;

        }
           fsout.close();//closing the file
       }
}
