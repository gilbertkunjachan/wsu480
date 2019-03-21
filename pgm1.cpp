//AUTHOR: GILBERT KUNJACHAN
//WSU ID: Y822D995
//PROGRAM NUMBER: 1
//PROGRAM DESCRIPTION: Keep track of the books who read.
//DATE: JANUARY 26,2087 

#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>

using namespace std;//jfgjkgkk


struct book_list {
    int book;
    string book;
    string author;
    string description;
    int month;
    int year;
    int rating;

};
void printmenu();
int getuserchoice();
void printbook(book_list booklist[], int size);
void createbook(book_list booklist[],int size);
void modifybook(book_list booklist[],int size);
void numberofbooks(book_list booklist[],int size);
void bookrating(book_list booklist[],int size);
int main()
{
   int choice,i,numberbook=0;
   string buffer;
   book_list booklist[500];
   ifstream readfile;
   readfile.open("reading_list.txt");
   if(readfile.is_open()) {
        getline(readfile,buffer);
        numberbook=atoi(buffer.c_str());
        for(i=0;i<numberbook;i++) {
            getline(readfile,buffer);
            booklist[i].booknum=atoi(buffer.c_str());
            getline(readfile,booklist[i].booktitle);
            getline(readfile,booklist[i].author);
            getline(readfile,booklist[i].description);
            getline(readfile,buffer);
            booklist[i].month=atoi(buffer.c_str());
            getline(readfile,buffer);
            booklist[i].year=atoi(buffer.c_str());
            getline(readfile,buffer);
            booklist[i].rating=atoi(buffer.c_str());

        }
   }
   
   
   
   do
   {
   printmenu();
   choice=getuserchoice();
   switch(choice){
   case 1 :
        printbook( booklist, numberbook);
        cout<<endl<<endl;
        break;
   case 2:
        createbook(booklist, numberbook);
        numberbook++;
        cout<<endl<<endl;
       break;
   case 3:modifybook(booklist,numberbook);
   cout<<endl<<endl;
       break;
   case 4:numberofbooks(booklist,numberbook);
   cout<<endl<<endl; 
       break;
   case 5:bookrating(booklist,numberbook);
   cout<<endl<<endl;
       break;
   case 6:return 0;
       break;
    default:
        cout<<"invalid"<<endl;
    
   }
}while(choice != 6);
}

void printmenu()
{
    cout<<"1.Print book"<<endl;
    cout<<"2.Enter a new book"<<endl;
    cout<<"3.Modify a book"<<endl;
    cout<<"4.How many books"<<endl;
    cout<<"5.Certain rating"<<endl;
    cout<<"6.Exit the program"<<endl;
    cout<<"**********************"<<endl;
    cout<<endl<<endl;
    return;
}
int getuserchoice()
{
 int choice;

 do{
     cout<<"Enter your choice:"<<endl;
     cin>>choice;
     if(choice<1||choice>6) {
        cout<<"INVALID CHOICE!!! TRY A VALID CHOICE"<<endl;
     }
 } while(choice<1||choice>6);

 return choice;
}
void printbook(book_list booklist[], int size)
{
    if(size==0){
        cout<<"Nothing to print"<<endl;
        return ;
    }

    for(int i=0;i<size;i++) {
        cout<<booklist[i].booknum<<endl;
        cout<<booklist[i].booktitle<<endl;
        cout<<booklist[i].author<<endl;
        cout<<booklist[i].description<<endl;
        cout<<booklist[i].month<<"/";
        cout<<booklist[i].year<<endl;
        cout<<booklist[i].rating<<endl;

    }
}
void createbook(book_list booklist[],int size)
{
	string buffer;
    booklist[size].booknum=size+1;
    cout<<"Enter title:";
    cout<<endl<<endl;
    cin.clear();
    cin.ignore();
    getline(cin,booklist[size].booktitle);
    cout<<"Enter author:";
    cout<<endl<<endl;
    getline(cin,booklist[size].author);
    cout<<"Enter description:";
    cout<<endl<<endl;
    getline(cin,booklist[size].description);
    cout<<"Enter month:";
    cout<<endl<<endl;
    getline(cin,buffer);
    booklist[size].month=atoi(buffer.c_str());
    cout<<"Enter year:";
    cout<<endl<<endl;
    getline(cin,buffer);
    booklist[size].year=atoi(buffer.c_str());
    cout<<"Enter rating:";
    cout<<endl<<endl;
    getline(cin,buffer);
    booklist[size].rating=atoi(buffer.c_str());
    return;
}

void modifybook(book_list booklist[],int size)
{
    int choice;

 do{
     cout<<"Enter part to modify:"<<endl;
     cin>>choice;
     if(choice<1||choice>size) {
        cout<<"invalid"<<endl;
     }
 } while(choice<1||choice>size);

        cout<<booklist[choice-1].booknum<<endl;
        cout<<booklist[choice-1].booktitle<<endl;
        cout<<booklist[choice-1].author<<endl;
        cout<<booklist[choice-1].description<<endl;
        cout<<booklist[choice-1].month<<"/";
        cout<<booklist[choice-1].year<<endl;
        cout<<booklist[choice-1].rating<<endl;
    
        
        	string buffer;
    cout<<"Enter title:";
    cout<<endl<<endl;
    cin.clear();
    cin.ignore();
    getline(cin,booklist[choice-1].booktitle);
    cout<<"Enter author:";
    cout<<endl<<endl;
    getline(cin,booklist[choice-1].author);
    cout<<"Enter description:";
    cout<<endl<<endl;
    getline(cin,booklist[choice-1].description);
    cout<<"Enter month:";
    cout<<endl<<endl;
    getline(cin,buffer);
    booklist[choice-1].month=atoi(buffer.c_str());
    cout<<"Enter year:";
    cout<<endl<<endl;
    getline(cin,buffer);
    booklist[choice-1].year=atoi(buffer.c_str());
    cout<<"Enter rating:";
    cout<<endl<<endl;
    getline(cin,buffer);
    booklist[choice-1].rating=atoi(buffer.c_str());
    return;
}
void numberofbooks(book_list booklist[],int size)
{
     cout<<"Total number of books:"<<size<<endl;
}
void bookrating(book_list booklist[],int size)
{
	int rating;
	cout<<"Enter rating:";
	cin>>rating;
	
for(int i=0;i<size;i++){
	
	if(booklist[i].rating==rating){
	

        cout<<booklist[i].booknum<<endl;
        cout<<booklist[i].booktitle<<endl;
        cout<<booklist[i].author<<endl;
        cout<<booklist[i].description<<endl;
        cout<<booklist[i].month<<"/";
        cout<<booklist[i].year<<endl;
        cout<<booklist[i].rating<<endl;

}
	}
}
