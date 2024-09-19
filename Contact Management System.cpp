#include<iostream>
using namespace std;
const int Max_contacts=100;
class contacts{
    private:
        string name[Max_contacts];
        string phoneNumbers[Max_contacts];
        int count;
         void DefaultContact() {
            if (count < Max_contacts) {
                name[count] = "Abdullah Azhar";
                phoneNumbers[count] = "03140632577";
                count++;
            }
        }
    public:
        contacts():count(0){
            DefaultContact();
        }
        void viewcontacts(){
            if(count==0){
                cout<<"No contacts found..."<<endl;
            }
            else{
                for(int i=0;i<count;i++)
                {
                    cout<<i+1<< ". Name: "<<name[i]<<", Phone Number: "<<phoneNumbers[i]<<endl;

                }
            }
        }
        void addcontacts(){
            if(count<Max_contacts){
            cout<<"Enter the name: "<<endl;
            cin.ignore();
            getline(cin,name[count]);
            cout<<"Enter the phone number: "<<endl;
            cin.ignore();
            getline(cin,phoneNumbers[count]);
            count++;
            }
            else{
                cout<<"Contact list is full..."<<endl;
            }
        }
         void deleteContact(){
         	string nameToDelete;
         	cout<<"Enter the Name of contact to delete"<<endl;
         	contacts::viewcontacts();
         	cin>>nameToDelete;
            int index=-1;
            for(int i=0;i<count;i++){
                if(name[i]==nameToDelete){
                    index=i;
                    break;
                }
            }
            if(index==-1){
                cout<<"Contact not found..."<<endl;
            }
            else{
                for(int i=index;i<count-1;i++){
                    name[i]=name[i+1];
                    phoneNumbers[i]=phoneNumbers[i+1];
                }
                count--;
                cout<<"Contact deleted successfully..."<<endl;
            }
        }
        void menu(){
        	cout<<"****************************************"<<endl;
        	cout<<"* Welcome to contacts Management system*"<<endl;
        	cout<<"****************************************"<<endl;
        	while(true)
        		{
                    start:
                    cout<<"------------------------------------------------------------------------------------------"<<endl;
        			cout<<"Choose from following index numbers to continue:"<<endl;
        			cout<<"1.Viewcontacts"<<endl;
                    cout<<"2.Add contacts"<<endl;
                    cout<<"3.Delete contacts"<<endl;
                    cout<<"4.Clear screen"<<endl;
                    cout<<"5.Exit"<<endl;
                    int choice;
                    cout<<"Enter your choice: ";
                    cin>>choice;
                    switch(choice){
                        case 1:
                            viewcontacts();
                            break;
                        case 2:
                            addcontacts();
                            break;
                        case 3:
                            deleteContact();
                            break;
                        case 4:
                            system("cls");
							goto start;	
                        case 5:
                        	cout<<"Exiting... Thank you for using the Contact Management System!"<<endl;
                            exit(0);
                        default:
                            cout<<"Invalid choice...Please Enter between 1-5"<<endl;
                            goto start;
                    }
                    cout<<endl;
                    cout<<"Do you want to continue?"<<endl;;
                    cout<<"1.Yes"<<endl;;
                    cout<<"2.No"<<endl;;
                    int choice2;
                    cin>>choice2;
                    switch(choice2){
                        case 1:
                        	system("cls");
                            goto start;
                        case 2:
                            exit(0);
                        default:
                            cout<<"Invalid choice...Please enter 1 or 2"<<endl;
                            break;
                    }
                }
        			
				}

};
int main(){
	contacts C;
	C.menu();
}