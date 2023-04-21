#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

const int MAX_SPACES = 100; // maximum number of parking spaces available

// Structure to store information about a parked vehicle
struct Vehicle {
    string number,type;
    time_t entryTime,exitTime;
	double dayfee,hourfee;
    int bus=0,car=0,bike=0;
};
// prototype for main menu
void PrintMenu(); 

int main() {
    // Initialize an array to store the parked vehicles
    Vehicle parkedVehicles[MAX_SPACES];
    int numVehicles = 0;// variable to keep track of number of parked vehicles
    Vehicle data; 
    
    
	
	
    while (true) 
	{	
        PrintMenu();
        int choice;
        cin >> choice;
        data.dayfee=0;
        data.hourfee=0;
        
        if(choice==1)
        {
        	cout<<"Press 1 for Full Day Parking"<<endl;
			    cout<<"Press 2 for Hours Base Parking"<<endl;
			    cout<<"Enter your choice: ";
			    cin>>choice;
			    
			        // Park a vehicle
			        // Ask the user for the vehicle's number, type, and entry time
			        cin.ignore();
			        cout << "Enter the vehicle's number: ";
			        getline(cin,data.number);
			
			        cout<<"Enter the vehicle's type (Car/Bike/Bus): ";
			        cin >>data.type;
			        
			        //Condition to check heater the car is already parked or not 
			        for(int i=0;i<=numVehicles;i++)
			        {
					
				        if(data.number==parkedVehicles[i].number)
					    {
					    	cout<<"\t\t\tThis Vehicle is already parked! Please try again."<<endl;
						}
					
						else
						{
							
						if(choice==1)
						{
						
						    // Calculate the parking fee based on the vehicle type 
						    if(data.type == "Bus" || data.type == "BUS" || data.type == "bus")
						    {
						        data.dayfee=150;
						        data.bus++;
						        cout << "\t\t\tParking fee for this vehicle is " << data.dayfee<< "RS" << endl;
						    }
						    else if (data.type == "Car" || data.type == "CAR" || data.type == "car") 
						    {
						        data.dayfee= 100;
						        data.car++;
						        cout << "\t\t\tParking fee for this vehicle is " << data.dayfee<< "RS" << endl;
						    } 
						    else if (data.type == "Bike" || data.type == "BIKE" || data.type == "bike") 
						    {
						        data.dayfee = 50;
						        data.bike++;
						        cout << "\t\t\tParking fee for this vehicle is " << data.dayfee<< "RS" << endl;
						    } 
						    else {
						        cout << "\t\t\tInvalid vehicle type. Please enter either 'Car' or 'Bike' or 'Bus'" << endl;    
						    }
						}
						
						else if(choice==2)
						{
							if(data.type == "Bus" || data.type == "BUS" || data.type == "bus")
						    {	
						    	data.hourfee=20;
						    	data.bus++;
						    	cout << "\t\t\tParking fee for this vehicle on hourbase is " << data.hourfee<< "RS" << endl;
						    }
						    else if (data.type == "Car" || data.type == "CAR" || data.type == "car") 
							{	
								
						        data.hourfee=15;
						        data.car++;
						        cout << "\t\t\tParking fee for this vehicle on hourbase is " << data.hourfee<< "RS" << endl;
						    } 
							else if (data.type == "Bike" || data.type == "BIKE" || data.type == "bike") 
							{	
						        data.hourfee=10;
						        data.bike++;
						        cout << "\t\t\tParking fee for this vehicle is on hourbase is " << data.hourfee<< "RS" << endl;
						    }
							else
							{
								cout<< "\t\t\tInvalid vehicle type. Please enter either 'Car' or 'Bike' or 'Bus'" << endl;
								
							 } 
						}
						else
						{
							cout<<"t\t\tInvalid choice. Please try again."<<endl;
						}
					    // Check if there are any available spaces
					    if (numVehicles >= MAX_SPACES) {
					        cout << "t\t\tSorry, the parking lot is full." << endl;
					        break;
					    }
					    //For time and date
					    data.entryTime;
						data.entryTime = time(0);
						char * entryTime = ctime(&data.entryTime);
					
					
					    // Add the vehicle to the parkedVehicles array and increment the numVehicles variable
						parkedVehicles[numVehicles] = {data.number, data.type,data.entryTime, data.exitTime,data.dayfee,data.hourfee};
						numVehicles++; 
					    
					    //file hanling for new entry
					    fstream myfile;
					    myfile.open("Entry_data.txt",ios::app);
					    myfile << "Vehicle number: " << data.number << endl;
						myfile << "Type: " << data.type << endl;
						myfile << "Entry time: " <<entryTime;
						myfile.close();
					}
					break;
					
				}
				
			}
			
		
		else if(choice==2)
		{
			// Check out a vehicle
                // code to ask user for vehicle number, generate receipt, and remove vehicle from the parkedVehicles array
                cin.ignore();
                cout<<"Press 1 for Full Day Parking"<<endl;
			    cout<<"Press 2 for Hours Base Parking"<<endl;
			    cout<<"Enter your choice: ";
			    cin>>choice;
			    
                if(choice==1){
					
					cin.ignore();
	                cout<<"Enter the vehicle number: ";
	                getline(cin,data.number);
	                int index=-1;
	                for(int i=0;i<numVehicles;i++)
	                {
	                    if(parkedVehicles[i].number==data.number)
	                    {
	                        index=i;
	                        break;
	                    }
	                }
	        
	                if(index!=-1)
	                {
	                	
				   		data.exitTime= time(0);
	        			parkedVehicles[index].exitTime = data.exitTime;
				    	
						cout << "Receipt:" << endl;
						cout << "Vehicle number: " << parkedVehicles[index].number << endl;
						cout << "Type: " << parkedVehicles[index].type << endl;
						cout << "Entry time: " << ctime(&parkedVehicles[index].entryTime);
						cout << "Exit time: " << ctime(&parkedVehicles[index].exitTime);
						cout << "Fee: " <<parkedVehicles[index].dayfee << "RS" << endl;
						
						// remove vehicle from the parkedVehicles array
						for (int i = index; i < numVehicles - 1; i++)
						{
						    parkedVehicles[i] = parkedVehicles[i + 1];
						}
						numVehicles--;
						if(parkedVehicles[index].type=="bus"||parkedVehicles[index].type=="Bus"||parkedVehicles[index].type=="BUS")
						{
							data.bus--;
						}
						else if(parkedVehicles[index].type=="car"||parkedVehicles[index].type=="Car"||parkedVehicles[index].type=="CAR")
						{
							data.car--;
						}
						else if(parkedVehicles[index].type=="bike"||parkedVehicles[index].type=="Bike"||parkedVehicles[index].type=="BIKE")
						{
							data.bike--;
						}
						
						 //storing record in files
						 //file handling
		                fstream myfile;
		                myfile.open("Vehicles_Record.txt",ios::app);
		                myfile << "Receipt:" << endl;
						myfile << "Vehicle number: " << parkedVehicles[index].number << endl;
						myfile << "Type: " << parkedVehicles[index].type << endl;
						myfile << "Entry time: " << ctime(&parkedVehicles[index].entryTime);
						myfile << "Exit time: " << ctime(&parkedVehicles[index].exitTime);
						myfile << "Fee: " <<parkedVehicles[index].dayfee << " RS" << endl;
						myfile.close();
						
						
		            }
	                else
	                {
	                    cout<<"\t\t\tNo such vehicle found"<<endl;
	                } 
            	}
            	else if(choice==2)
            	{	
            		cin.ignore();
            		cout<<"Enter the vehicle number: ";
	                getline(cin,data.number);
	                
	                int index=-1;
	                for(int i=0;i<numVehicles;i++)
	                {
	                    if(parkedVehicles[i].number==data.number)
	                    {
	                        index=i;
	                        break;
	                    }
	                }
	                
	                
	                if(index!=-1)
	                {
	                	//for exit time and date
				   		data.exitTime= time(0);
	        			parkedVehicles[index].exitTime = data.exitTime;
	        		
						// for calculating durration
						double seconds = difftime(parkedVehicles[index].exitTime, parkedVehicles[index].entryTime);
						double hours = seconds / 3600;
						double hourfee = hours * parkedVehicles[index].hourfee;
						
						//Receipt
						cout << "Receipt:" << endl;
						cout << "Vehicle number: " << parkedVehicles[index].number << endl;
						cout << "Type: " << parkedVehicles[index].type << endl;
						cout << "Entry time: " << ctime(&parkedVehicles[index].entryTime);
						cout << "Exit time: " << ctime(&parkedVehicles[index].exitTime);
						cout << "Duration: "<<hours<<" Hours"<<endl;
						cout << "Fee: " <<hourfee<< " RS" << endl;
						
						// remove vehicle from the parkedVehicles array
						for (int i = index; i < numVehicles - 1; i++)
						{
						    parkedVehicles[i] = parkedVehicles[i + 1];
						}
						numVehicles--;
						if(parkedVehicles[index].type=="bus"||parkedVehicles[index].type=="Bus"||parkedVehicles[index].type=="BUS")
						{
							data.bus--;
						}
						else if(parkedVehicles[index].type=="car"||parkedVehicles[index].type=="Car"||parkedVehicles[index].type=="CAR")
						{
							data.car--;
						}
						else if(parkedVehicles[index].type=="bike"||parkedVehicles[index].type=="Bike"||parkedVehicles[index].type=="BIKE")
						{
							data.bike--;
						}
		               	//storing record in files
		                //file handling
		                fstream myfile;
		                myfile.open("Vehicles_Record.txt",ios::app);
		                myfile << "Receipt:" << endl;
		                myfile << "Vehicle number: " << parkedVehicles[index].number << endl;
		                myfile << "Type: " << parkedVehicles[index].type << endl;
						myfile << "Entry time: " << ctime(&parkedVehicles[index].entryTime);
						myfile << "Exit time: " << ctime(&parkedVehicles[index].exitTime);
						myfile << "Duration: "<<hours<<" Hours"<<endl;
						myfile << "Fee: " <<hourfee<< " RS" << endl;
						myfile.close(); 
						  
					}  
	                else
	                {
	                    cout<<"\t\t\tNo such vehicle found"<<endl;
	                } 
	            	  
				}
				else
				{
					cout<<"\t\t\tInvaild input try again"<<endl;
				}
		}
		else if(choice==3)
		{
			// View parking availability
            // code to calculate and display the number of available spaces
            cout<<"\t\t\tNumber of available spaces: "<<MAX_SPACES-numVehicles<<endl;
            
		}
		else if(choice==4)
		{
			 // View parked vehicle details
                // code to display details of all parked vehicles
                cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
				cout << setw(4) << "Vehicle number" << setw(22) << "Type" << setw(31)<<"Fullday Fee"<< setw(25) << "Hourbase Fee" << setw(30) << "Entry Time" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
                
                for(int i=0;i<numVehicles;i++)
                {
					cout << parkedVehicles[i].number << "\t\t\t\t|" << parkedVehicles[i].type << "\t\t\t|" << parkedVehicles[i].dayfee<<"\t\t\t|"<<parkedVehicles[i].hourfee<< "\t\t\t\t|" << ctime(&parkedVehicles[i].entryTime) ;  
                }
            
                cout<<endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
                cout<<"|Cars: "<<data.car<<"\t|Bikes: "<<data.bike<<"\t|Buses: "<<data.bus<<"\t|Tottal Vehicles: "<<numVehicles<<endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------\n";
	                
                
		}
		else if(choice==5)
		{
			
            //getting save data from files
            //file handling
			fstream myfile;
			myfile.open("Vehicles_Record.txt",ios::in);
			string s;
			cout<<"Vehicles_Record.txt"<<endl;
			while(!myfile.eof())
			{
				getline(myfile,s);
				cout<<s<<endl;
			}
			myfile.close();
			
		
			
	}
		else if(choice==6)
		{
			 // Reset the system
                // code to reset the system, including clearing the parkedVehicles array and resetting the numVehicles variable
                numVehicles = 0;// reset the number of parked vehicles
				data.bus=0; 
				data.car=0;
				data.bike=0;
                cout<<"\t\t\tSystem has been reset successfully"<<endl;
		}
		else if(choice==7)
		{
				// Exit
                // code to save the data to file before exit the program
                ofstream myfile; //Declare an object of class fstream
				myfile.open("parking_data.txt",ios::app); //open the file using a stream
				myfile << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
				myfile << setw(4) << "Vehicle number" << setw(22) << "Type" << setw(22)<<"Fullday Fee"<< setw(18) << "Hourbase Fee" << setw(28) << "Entry Time"<< setw(31) << endl;
				myfile << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
				for(int i = 0; i < numVehicles; i++) {
                    myfile<< parkedVehicles[i].number << "\t\t\t\t|" << parkedVehicles[i].type << "\t\t|" << parkedVehicles[i].dayfee  <<"\t\t|"<<parkedVehicles[i].hourfee<< "\t\t\t\t|" <<ctime(&parkedVehicles[numVehicles].entryTime);
                }
                //For calculating total fee or balance
                double total;
                for(int j=0;j<numVehicles;j++)
                {
                	total=parkedVehicles[j].dayfee+parkedVehicles[j].hourfee;
				}
                myfile <<endl;
                myfile << "--------------------------------------------------------------------------------------------------------------------------------------\n";
                myfile <<"|Cars: "<<data.car<<"\t|Bikes: "<<data.bike<<"\t|Buses: "<<data.bus<<"\t|Tottal Vehicles: "<<numVehicles<<"\t|Total Balance: "<<total<<endl;
                myfile << "--------------------------------------------------------------------------------------------------------------------------------------\n";
				myfile.close(); //close the file                                                                                                                                 
                cout << "\t\t\tExiting the program. Have a good day!" << endl;
                return 0;
		}
		else
		{
			cout<<"\t\t\tInvalid input please try again!"<<endl;
		}
		cin.ignore();
		cout<<"Press Enter to Continue...."<<endl;
    	cin.ignore();
	}
	
	
	return 0;
}
// Function to print the main menu
void PrintMenu(){
	cout <<"------------------------------------------"<<endl;
    cout << "Welcome to the Parking Management System" << endl;
    cout <<"*************************************"<<endl;
    cout << "1. Park a vehicle" << endl;
    cout << "2. Check out a vehicle" << endl;
    cout << "3. View parking availability" << endl;
    cout << "4. View parked vehicle details" << endl;
    cout << "5. View Record" << endl;
    cout << "6. Reset the system" << endl;
    cout << "7. Exit & Save" << endl;
    cout <<"*************************************"<<endl;
    cout << "Enter your choice: ";
}
