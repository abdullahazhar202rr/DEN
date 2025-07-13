#include<iostream>
#include<string>
using namespace std;
const int MAX_BOOKS=10;
const int MAX_PERSONS=8;
class Book{
public:
    string name;
    string author;
    string publisher;
    string iban;
    int price; 
    int publishingYear;
    int copiesInLibrary;
     Book():name(""),author(""),publisher(""),iban(""),price(0),publishingYear(0),copiesInLibrary(0){}
    Book(string name,string author,string publisher,int price,int publishingYear,int copiesInLibrary,string iban)
    :name(name),author(author),publisher(publisher),price(price),publishingYear(publishingYear),copiesInLibrary(copiesInLibrary),iban(iban){}
};
class Person{
public:
    string type;
    string roll_number;
    int age;
    string gender;
    Person():type(""),roll_number(""),age(0),gender(""){}
    Person(string type,string roll_number,int age,string gender):type(type),roll_number(roll_number),age(age),gender(gender){}
};
class LibraryManagementSystem{
private:
    Book books[MAX_BOOKS];
    int bookCount=0;
    Person persons[MAX_PERSONS];
    int personCount=0;
public:
    void addBook(string name,string author,string publisher,int price,int publishingYear,int copiesInLibrary,string iban) 
	{
        if (bookCount<MAX_BOOKS)
		{
            books[bookCount++]=Book(name,author,publisher,price,publishingYear,copiesInLibrary,iban);
        } 
		else
		{
            cout<<"Library is full. Cannot add more books."<<endl;
        }
    }
    void addPerson(string type,string roll_number,int age,string gender) 
	{
        if (personCount<MAX_PERSONS)
		{
            persons[personCount++]=Person(type, roll_number, age, gender);
        } 
		else
		{
            cout<<"Library is full. Cannot add more persons."<<endl;
        }
    }
    void showpersons()
	{
        cout<<"======================================================="<<endl;
        cout<<"Registered Persons:"<<endl;
        cout<<"======================================================="<<endl;
        for (int i=0;i<bookCount;++i)
		{
            cout<<"Type: "<<persons[i].type<<endl;
            cout<<"Roll Number: "<<persons[i].roll_number<<endl;
            cout<<"Age: "<<persons[i].age<<endl;
            cout<<"Gender: "<<persons[i].gender<<endl;
            cout<<"-------------------------------------------------------"<<endl;
        }
    }
    void displayBooks()
	{
        cout<<"======================================================="<<endl;
        cout<<"We Have Following Books in Library:"<<endl;
        cout<<"======================================================="<<endl;
        for (int i=0;i<bookCount;++i) {
            cout<<"Book:"<<books[i].name<<" , ";
            cout<<"Iban No.:"<<books[i].iban<<endl;
        }
    }
    void displayBookDetails(string iban) 
	{
        for (int i=0;i<bookCount;++i) 
		{
            if (books[i].iban==iban)
			 {
                cout<<"\nThe Name of the Book is:             "<<books[i].name<<endl;
                cout<<"The Author of the Book is:           "<<books[i].author<<endl;
                cout<<"The Publisher of the Book is:        "<<books[i].publisher<<endl;
                cout<<"The Price of the Book is:            "<<books[i].price<<endl;
                cout<<"The Publishing Year of the Book is:  "<<books[i].publishingYear<<endl;
                cout<<"We Have "<<books[i].copiesInLibrary<<" Copies of this Book in Library."<<endl;
               return;
            }
        }
        cout<<"Book not found."<<endl;
    }
    void issueBook(string iban,int quantity,string roll_number) 
	 {
        bool memberFound=false;
        for(int i=0;i<personCount;++i)
		 {
            if(persons[i].roll_number==roll_number)
			 {
                memberFound=true;
                break;
            }
        }
        if (!memberFound)
		{
            cout<<"Member not found."<<endl;
            return;
        }
        for (int i=0;i<bookCount;++i)
		 {
            if (books[i].iban==iban&&books[i].copiesInLibrary>=quantity&&quantity > 0) 
			 {
                books[i].copiesInLibrary-=quantity;
                cout<<"Issued "<<quantity<<" copies of "<<books[i].name<<" successfully."<<endl;
               return;
            }
        }
        cout<<"Book not found or insufficient quantity."<<endl;
    }
    void returnBook(string iban,int quantity,string roll_number)
	 {
        bool memberFound=false;
        for (int i=0;i<personCount;++i)
		{
            if (persons[i].roll_number==roll_number)
			{
                memberFound=true;
                break;
            }
        }
        if (!memberFound)
		{
            cout<<"Member not found."<<endl;
            return;
        }
        for (int i=0;i<bookCount;++i) 
		{
            if (books[i].iban==iban) 
			{
                books[i].copiesInLibrary+=quantity;
                cout<<"Returned "<<quantity<<" copies of "<<books[i].name<<" successfully."<<endl;
                return;
            }
        }
        cout<<"Book not found."<<endl;
    }
};
int main() {
    cout<<"=========================="<<endl;
    cout<<"Welcome to Library."<<endl;
    cout<<"=========================="<<endl;
    cout<<"Books are only Issuable to students and teachers."<<endl;
    LibraryManagementSystem lms;
    lms.addPerson("Abdullah Azhar","150",18,"Male");
    lms.addPerson("Abdullah Mehfooz","170",18,"Male");
    lms.addPerson("Hassan","176",18,"Male");
    lms.addPerson("Rihab","177",18,"Male");
    lms.addPerson("Tayyab","160",18,"Male");
    lms.addPerson("Ahtisham","166",18,"Male");
    lms.addPerson("Miss. Alina","112-lab",25,"Female");
    lms.addPerson("Dr. Kashif","112",35,"Male");
    lms.addBook("Sahih al-Bukhari","Muhammad al-Bukhari    ","Darussalam",100,2000,4,"10");
    lms.addBook("Sahih Muslim    ","Muslim ibn al-Hajjaj   ","Darussalam",150,2010,5,"20");
    lms.addBook("Sunan Abu Dawood","Abu Dawood","Darussalam",200,2020,6,"30");
    lms.addBook("Jami at-Tirmidhi","Tirmidhi","Darussalam  ",500,1992,4,"40");
    lms.addBook("Sunan an-Nasa'i ","An-Nasa'i","Darussalam ",450,1995,5,"50");
    lms.addBook("Sunan Ibn Majah ","Ibn Majah","Darussalam ",400,1998,3,"60");
   start:
    char p;
    cout<<"================================================================================"<<endl;
    cout<<"Enter p to get details about registered persons and b to get details about books: "<<endl;
    cin>>p;
    if(p=='p')
    {
    	lms.showpersons();
	}
	if(p=='b')
	{
    lms.displayBooks();
    cout<<"======================================================="<<endl;
    cout<<"Enter Iban No. for Complete Details of the Book:";
    string iban;
    cin>>iban;
    lms.displayBookDetails(iban);
    char action;
    cout<<"======================================================="<<endl;
    cout<<"Enter 'y' if you want to issue a book, or 'n' if you want to return a book:";
    cin>>action;
    if (action=='y')
	{
        int quantity;
        cout<<"======================================================="<<endl;
        cout<<"Enter Iban No. of the Book You Want to Issue:";
        cin>>iban;
        cout<<"Enter Your Roll No. (Student/Teacher):";
        string roll_number;
        cin>>roll_number;
        cout<<"How Many Copies of the Book You Want to Issue:";
        cin>>quantity;
        lms.issueBook(iban,quantity,roll_number);
    }else if(action=='n')
	{
        int quantity;
        cout<<"Enter Iban No. of the Book You Want to Return:";
        cin>>iban;
        cout<<"Enter Your Roll No. (Student/Teacher):";
        string roll_number;
        cin>>roll_number;
        cout<<"How Many Copies of the Book You Want to Return:";
        cin>>quantity;
        lms.returnBook(iban,quantity,roll_number);
    }else{
        cout<<"Invalid input. Please enter 'y' or 'n'."<<endl;
    }
}
cout<<"\nWould You Like to continue?\n"<<endl;
	cout<<"1-Yes\n";
	cout<<"2-No\n";
	cout<<"Selection: ";
	int ip;
	cin>>ip;
	if(ip==1){
	system("cls");
	goto start;
}
    return 0;
}