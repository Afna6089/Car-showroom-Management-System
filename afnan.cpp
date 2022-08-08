#include<iostream>
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<vector> /* for car models */
#include<windows.h> /*for display and other functions like delete , rename etc */
#include<string> /* for basic string operation */
using namespace std;
class car /* this is car class with members which represents its imformation */
{
private :
    int    year ;
	string brand ;
    string model ;
    string color ;
    int  price ;
public :
    car(int x, string a , string s , string d  , int e) ; /* constructor for the car */
    void disp() ;
};
car::car(int x, string a , string s , string d  , int e) /*initialize members */
    {
        year = x ;
        brand = a ;
        model = s ;
        color  = d ;
        price = e ;
    }
    void car::disp() /*displaying members */
    {
      cout<<"year : "<<year<<" " ;
      cout<<"brand : "<<brand<<" " ;
      cout<<"model : "<<model<<" " ;
      cout<<"color : "<<color<<" " ;
      cout<<"price : "<<price<<"\n" ; ;
    }
class person /* person class with its members to represent the class */
{
private :
    string name ;
    int age ;
    string cnic ;
    string contact ;
    string address ;
public :
    person(string s1 , int x , string a , string s , string d) ; /*constructor */
    void disp(); /* this function displays its members information */
};
person::person(string s1 , int x , string a , string s , string d) /*initialize members */
    {
    name =  s1 ;
    age = x ;
    cnic  = a ;
    contact = s ;
    address = d ;
    }
    void person::disp() /*display members */
    {
        cout<<"\nNAME: "<<name<<"\n" ;
        cout<<"AGE: "<<age<<"\n" ;
        cout<<"CNIC:"<<cnic<<"\n" ;
        cout<<"CONTACT: "<<contact<<"\n" ;
        cout<<"ADDRESS: "<<address<<"\n" ;
    }
class customer : public person /* customer class with its members to represent it */
{                              /* here customer class inherits perosn class */
private :
    string date_purchase ;
    string brand_choice ;
    string model_choice ;
    string color_choice ;
    int price_choice ;
    int year_choice ;
    public :
       customer(string s1 , int x , string s2 , string s3 , string s4); /*constructor */
       void set(string a , string s ,string d , string f , int z , int x ) ; /*function to initialize class members */
       void disp() ; /* this function is override and displays the class members and
                      its inherited class members */
} ;
customer::customer(string s1 , int x , string s2 , string s3 , string s4): person(s1,x,s2,s3,s4){} ;
void customer::set(string a , string s ,string d , string f , int z , int x )
	   {
           date_purchase = a ;
           brand_choice = s ;
           model_choice = d ;
           color_choice = f ;
           price_choice = z ;
           year_choice = x ;
       }
       void customer::disp() /*displaying members */
       {
          person::disp() ;
          cout<<"\n" ;
          cout<<"DATE OF PURCHASE : "<<date_purchase<<"\n" ;
          cout<<"BRAND CHOICE : "<<brand_choice<<"\n" ;
          cout<<"MODEL CHOICE : "<<model_choice<<"\n" ;
          cout<<"COLOR CHOICE: "<<color_choice<<"\n" ;
          cout<<"PRICE CHOICE: "<<price_choice<<"\n" ;
          cout<<"YEAR CHOICE: "<<year_choice<<"\n" ;
       }
class salesman :  public person /*this class inherits person class */
{
private :
   int salary ;   /* these are its members which represents it */
   int id ;
   string designation ;
public :
    salesman(int x , int y , string sal , string a ,int q , string st1 , string st2 , string st3);
    void disp() ;
    /* here , there is class salesman constructor and a display overrided function
      which displays derived and base class member's information */
};
 salesman::salesman(int x , int y , string sal ,string a ,int q , string st1 , string st2 , string st3):person(a,q,st1,st2,st3),salary(x) , id(y) , designation(sal)
	{   } /* initialize members */
void salesman::disp() /*displaying members */
    {
        person::disp() ;
        cout<<"\n" ;
        cout<<"SALARY : "<<salary<<"\n" ;
        cout<<"I.D : "<<id<<"\n" ;
        cout<<"DESIGNATION : "<<designation<<"\n" ;
    }
class selling /*selling class which maintains cars and money record */
{
private :
   int cars_sold ;
   int total_money_collect ;
public :
   void set1(int z , int x) ; /*this function initializes the members of class selling */
   void cars_money() ; /* it displays number of cars to be sold and total money collcted */
};
 void selling::set1(int z , int x) /* initialize members */
    {
        cars_sold = z ;
        total_money_collect = x ;
    }
    void selling::cars_money() /*displaying members */
    {
        cout<<"\ncars sold : "<<cars_sold<<"\n" ;
        cout<<"total money collected : "<<total_money_collect ;
    }
string case_change(string s) /*function to change case space separated */
{
    if(s[0]>=97 && s[0]<=122 )
    s[0] = s[0] - 32 ;
    int i ;
    for(i=1;i<s.size();i++)
    {
        if(s[i]>=65 && s[i]<=91)
        s[i] = s[i] + 32 ;
    }
    for(i=0;i<s.size();i++)
    {
      if(s[i] == ' ')
      s[i] = '-' ;
    }
    for(i=0;i<s.size();i++)
    {
      if(s[i] == '-' )
      {
        if(s[i+1]>=97 && s[i+1]<=122)
        s[i+1] = s[i+1] - 32 ;
      }
    }
    return s ;
}
string change(string s) /*function to change case */
{
    if(s[0]>=97 && s[0]<=122 )
    s[0] = s[0] - 32 ;
    int i ;
    for(i=1;i<s.size();i++)
    {
        if(s[i]>=65 && s[i]<=91)
        s[i] = s[i] + 32 ;
    }
  return s ;
}
 /* this returns current directory */
string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}
 void contact_verification(string contact)
 {
   int flag2=0;
  for(int i=0;i<contact.length();i++)
  {
   if(contact[i]-48>=0 && contact[i]-48<=9)
   {
     flag2=1;
     continue;
   }
   else
   {
    flag2=0;
    break;
   }
  }
 if(contact.length()==10)
 {
     for(int i=0;i<contact.length();i++)
        if(contact[0]==48)
        {
          cout<<"ENTERED NUMBER IS INVALID"<<endl;
          cout<<"ENTER A VALID NUMBER"<<endl;
          cin>>contact;
          contact_verification(contact);
        }
  cout<<"ENTERED NUMBER IS VALID"<<endl;
 }
 else if(flag2==0)
 {
  cout<<"INVALID NUMBER"<<endl;
  cout<<"ENTER A VALID NUMBER"<<endl;
  cin>>contact;
  contact_verification(contact);
 }
 else
 {
            cout<<"INVALID NUMBER"<<endl;
            cout<<"ENTER A VALID NUMBER"<<endl;
            cin>>contact;
            contact_verification(contact);
 }
}
void contact_verification();
int main()
{
    ifstream fin1 , fin2 , fin3 , sale  ; /*for input file */
    ofstream fout1 , fout2  ,  fout4  ; /*for output file */
    /* members declaration for manipulation */
    int z,x,c,v,b,n,m ,count = 0 , year , price ,age , sal , id1 , money = 0 , cars = 0 , result , xy = 1  , choice , total =  0 ;
    string s1 ,s2 ,s3 ,s4 ,s5 ,s6 ,s7 ,s8 ,s9 , brand , model , name , cnic , address , contact , id , sales , color  , loc , loc1 , loc2 ,loc3 ,c1 , c2 ,c3 , c4  ;
    char ch , ch1 , ch2 , ch3 ;
    ch2 = 'Y' ;
    int cus,cus1;
    int h,zx;
    int flag2=0;
    string hj , password , match  ; /*members for password */
    ofstream pass ;
    cout<<"ENTER YOUR CHOICE";
    cout<<"\n1->ADMIN\n2->CUSTOMER\n";
    cin>>choice;
    if(choice==1)
    {
    cout<<"\nPRESS 1 TO SET OR CHANGE PASSWORD\n\n";
    cout<<"PRESS 2 KEY TO LOGIN \n" ;
    cin>>zx ;
      if(zx == 1)
      {
        cin.sync() ;
        cout<<"ENTER THE PASSWORD TO SET\n" ;
        password ="";
        ch = _getch(); /* here getch and pushback are used to display password as *** on screen */
        while(ch != 13)
        {//character 13 is enter
          if(ch == 8)   // 8 is the ascii code of backspace
          {
              if(password.length() > 0)
              {
                   password.erase(password.length() - 1, 1);
                   //Erase the last Character in password signs
				   cout << '\b' << " " << '\b';
              }
          }
		 else
		 {
	       password.push_back(ch);
           cout << '*';
         }
         ch = _getch();
        }
      pass.open("password.txt") ;
      pass<<password  ;
      pass.close() ;
      cin.sync() ;
      cout<<"\nENTER THE PASSWORD FOR LOGIN \n" ;
      ch = _getch();
      while(ch != 13)
      {//character 13 is enter
        if(ch == 8)   // 8 is the ascii code of backspace
        {
              if(match.length() > 0)
              {
                   match.erase(match.length() - 1, 1);
                   //Erase the last Character in password signs
				   cout << '\b' << " " << '\b';
              }
        }
        else
        {
	       match.push_back(ch);
           cout << '*';
        }
      ch = _getch();
      }
      ifstream fp ;   /* reading password from file */
      fp.open("password.txt") ;
      getline(fp,password) ;
      fp.close() ;
      }
   if(zx==2)
   {
      cin.sync() ;
      cout<<"ENTER THE LOGIN PASSWORD \n" ;
      ch = getch();
      while(ch != 13) // character 13 is enter
      {
        if(ch == 8)   // 8 is the ascii code of backspace
          {
              if(match.length() > 0)
              {
                   match.erase(match.length() - 1, 1);
                   //Erase the last Character in password signs
				   cout << '\b' << " " << '\b';
              }
          }
		 else
		 {
	        match.push_back(ch);
            cout << '*';
	     }
      ch = getch();
      }
      ifstream fp ;   /* reading passowrd from file */
      fp.open("password.txt") ;
      getline(fp,password) ;
      fp.close() ;
   }
  if( match == password ) /*password matching condition */
  {
    cout<<"\n-----------------------------------------------------------------------"<<endl;
    cout<<"\t\tWelcome To Our Car Showroom"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    while(ch2=='Y' || ch2=='y')
   {
   /*main menu options */
    cout<<"\n\n-> 1: SEARCH AND BUY\n\n" ;
    cout<<"-> 2: DETAILS\n\n" ;
    cout<<"-> 3: ADD_DELETE RECORD \n\n"  ;
    cout<<"-> 4: EXIT\n\n" ;
    cin>>z ;
    switch(z)
    {
   /* this case ends the  program */
     case 4 :
     return -1 ;
     break ;
     /* this case gives the searching option */
      break ;
    /* details case */
      case 2:
      cout<<"\n1: SALESMAN DETAILS\n" ;
      cout<<"\n2: SALES_RECORD\n" ;
      cout<<"\n3: MONEY_COLLECTION\n" ;
      cin>>c ;
      switch(c)
      {
 /* salesman details case */
      case 1 :
        fin3.open("salesman.txt") ;
		cout<<"\n1: TO FIND ALL SALESMEN RECORDS \n";
        cout<<"2: TO FIND ONE SALESMAN RECORD \n" ;
        cin>>v ;
         /* THIS CASE IS FOR SALESMAN RECORD */
        if(v == 1)
        {
        while(getline(fin3,s1))
        {
            stringstream sd(s1) ;
            sd>>sal>>id1>>s2>>name>>age>>cnic>>contact>>address ;
            salesman s1(sal,id1,s2,name,age,cnic,contact,address);
            s1.disp() ;
        }
        fin3.close() ;
    }
     else
     if(v == 2)
     {
           cin.sync() ;
		   cout<<"\nENTER THE SALESMAN NAME \n" ;
           getline(cin,s3) ;
           s3 = case_change(s3) ;
           while(getline(fin3,s1))
        {
            stringstream sd(s1) ;
            sd>>sal>>id1>>s2>>name>>age>>cnic>>contact>>address ;
              if(name == s3 )
            {
            salesman s1(sal,id1,s2,name,age,cnic,contact,address);
            s1.disp() ;
            }
        }
        fin3.close() ;
        }
       break ;
       /* end of case1 */
        /* THIS CASE IS FOR SALES RECORD */
        case 2:
         fin2.open("qwery.txt") ;
        cout<<"\n1: TO FIND ONE CUSTOMER RECORD \n" ;
        cout<<"\n2: TO FIND ALL CUSTOMER RECORDS \n " ;
        cin>>choice ;
        if(choice == 2)
        {
         while(getline(fin2,s4))
         {
             cout<<"\n\nCUSTOMER "<<xy<<" RECORD\n" ;
             stringstream as(s4) ;
             as>>year>>brand>>model>>color>>price>>name>>age>>cnic>>contact>>address>>id>>sales ;
             customer cus(name,age,cnic,contact,address) ;
             cus.set(id,brand,model,color,price,year) ;
             cus.disp() ;
             xy++ ;
         }
         fin2.close() ;
         xy = 1 ;
   }
   else
   if(choice == 1 )
   {
   	cin.sync() ;
   	cout<<"\n ENTER THE CUSTOMER'S NAME \n " ;
   	getline(cin,s2) ;
   	s2 = case_change(s2) ;
   	while(getline(fin2,s4))
         {
             stringstream as(s4) ;
             as>>year>>brand>>model>>color>>price>>name>>age>>cnic>>contact>>address>>id>>sales ;
             if(name == s2)
             {
             customer cus(name,age,cnic,contact,address) ;
             cus.set(id,brand,model,color,price,year) ;
             cus.disp() ;
         }
         }
         fin2.close() ;
         }
        break ;
       /* THIS CASE IS FOR MONEY RECORD */
        case 3 :
         fin2.open("qwery.txt") ;
         cout<<"THE CARS SOLD AT :\n\n" ;
         while(getline(fin2,s2)) /* reading file */
         {
            stringstream ss(s2) ;
            ss>>year>>brand>>model>>color>>price>>name>>age>>cnic>>contact>>address>>id>>sales ;
            cout<<brand<<" "<<model<<" IS SOLD AT "<<price<<" BY "<<"SALESMAN: "<<sales<<"\n\n" ; ;
            money+=price ; /* adds money */
            cars++ ; /*adds number of cars */
         }
         selling se ; /*selling class object se declaration */
         se.set1(cars,money) ; /*passing members */
         se.cars_money() ; /*displaying them on screen */
         cars = 0 ;
         price = 0 ;
         break ;
      }
      break ;
       /* ADD OR DELETE RECORD CASE*/
        case 3 :
        cout<<"\n1: TO ADD RECORD \n" ;
        cout<<"2: TO DELETE RECORD \n" ;
        cin>>b ;
        switch(b)
        {
 /* ADD SUB CASE 1 */
       case 1 :
       cout<<"\n1: TO ADD SALESMAN RECORD \n" ;
       cout<<"2: TO ADD CAR RECORD \n" ;
       cin>>n ;
       if(n==1)
       {
          ofstream fout ;
          fout.open("salesman.txt", ios::app) ;
          cin.sync() ;
          cout<<"ENTER THE SALESMAN NAME \n" ;
          getline(cin,name);
          name = case_change(name) ;
          cout<<"ENTER THE SALESMAN AGE \n" ;
          cin>>age ;
          cin.sync() ;
          cout<<"ENTER THE SALESMAN CNIC \n" ;
          getline(cin,cnic) ;
          cnic = case_change(cnic) ;
          cout<<"ENTER THE SALESMAN CONTACT \n" ;
          cin>>contact;
          contact_verification(contact);
          cin.sync();
          cout<<"ENTER THE SALESMAN ADDRESS \n" ;
          getline(cin,address) ;
          address = case_change(address) ;
          cout<<"ENTER THE SALESMAN SALARY \n" ;
          cin>>sal ;
          cin.sync() ;
          cout<<"ENTER THE SALESMAN DESIGNATION \n" ;
          getline(cin,s1) ;
          s1 = case_change(s1) ;
          cout<<"ENTER THE SALESMAN ID \n" ;
          cin>>id1 ;
          fout<<sal<<" "<<id1<<" "<<s1<<" "<<name<<" "<<age<<" "<<cnic<<" "<<contact<<" "<<address<<"\n" ;
          fout.close();
          cout<<"\n YOUR RECORD HAS BEEN ADDED SUCCESSFULLY \n" ;
          loc = ExePath() ;	/* SAVING CURRENT LOCATION */
          loc += "\\salesman.txt" ;
          loc3 = "C:\\Users\\moham\\OneDrive\\salesman.txt" ; /*ONE DRIVE LOCATION */
          const char * c= loc.c_str() ; /* CONVERTING STRING TO CONST CHAR* */
          const char * d= loc3.c_str() ;
             BOOL b = CopyFile(loc.c_str() , loc3.c_str(), 0); /*COPYING FILE */
          if(!b)
          {
            cout << "Error: " << GetLastError() << endl;
          }
          else
          {
            cout << "Okay " << endl;
          }
       }
	else
    if(n==2)
    {
      ofstream fout3 ;
      fout3.open("cars.txt",ios::app) ;
      cout<<"ENTER THE CAR BRAND \n" ;
      cin>>brand ;
      brand = change(brand) ;
	  cout<<"ENTER THE CAR MODEL \n" ;
      cin>>model ;
      model = change(model) ;
      cout<<"ENTER THE CAR COLOR \n" ;
      cin>>color ;
      color = change(color) ;
      cout<<"ENTER THE CAR YEAR \n" ;
      cin>>year ;
      cout<<"ENTER THE CAR PRICE \n" ;
      cin>>price ;
       fout3<<"\n"<<year<<" "<<brand<<" "<<model<<" "<<color<<" "<<price<<"\n" ;
      fout3.close() ;
        cout<<"YOUR REC0RD HAS BEEN ADDED SUCCESFULLY IN THE DATABASE \n";
          loc = ExePath()  ;
        loc += "\\cars.txt" ;
        loc3 = "C:\\Users\\moham\\OneDrive\\cars.txt" ;
        const char * c= loc.c_str() ;
		const char * d= loc3.c_str() ;
             BOOL b = CopyFile(loc.c_str() ,loc3.c_str() , 0);
if(!b)
    {
    cout << "Error: " << GetLastError() << endl;
    }
else
 {
    cout << "Okay " << endl;
}
       }
      break ;
     /* DELETE SUB CASE 2 */
       case 2 :
        cout<<"1: DELETE SALESMEN RECORD \n" ;
        cout<<"2: DELETE CAR RECORD \n" ;
        cin>>m ;
     if(m==1)
     {
     	cin.sync() ;
		cout<<"enter the salesman name \n" ;
        getline(cin,s8) ;
        s8 = case_change(s8) ;
        fin3.open("salesman.txt") ;
        ofstream temp;
        temp.open("temp.txt");
        //fout4.open("temp.txt",ios::app) ;
        while(getline(fin3,s5))
        {
         stringstream rt(s5) ;
         rt>>sal>>id1>>s2>>name>>age>>cnic>>contact>>address ;
         if(name!=s8)
            temp<<sal<<" "<<id1<<" "<<s2<<" "<<name<<" "<<age<<" "<<cnic<<" "<<contact<<" "<<address<<"\n" ;
        }
        fin3.close() ;
        temp.close() ;
        remove("salesman.txt") ;
        rename("temp.txt","salesman.txt") ;
}
 if(m==2)
     {
     	cin.sync() ;
		cout<<"enter the car name \n" ;
        getline(cin,s8) ;
        s8 = case_change(s8) ;
        fin3.open("cars.txt") ;
        fout4.open("temp.txt",ios::app) ;
        while(getline(fin3,s5))
        {
         stringstream rt(s5) ;
         rt>>year>>brand>>model>>age>>color>>price;
         if(name!=s8)
         fout4<<year<<" "<<brand<<" "<<model<<" "<<color<<" "<<price<<"\n ";
        }
        fin3.close() ;
        fout4.close() ;
        remove("cars.txt") ;
        x = rename("temp.txt","cars.txt") ;
        if(x == 0)
          cout<<"DELETED SUCCESFULLY \n" ;
        else
        cout<<"FAILED TO DELETE \n" ;
}
     }
        break ;
        }
  /* CONDTION TO GO TO THE MAIN MENU AGAIN */
  cout<<"************\npress Y to go to the main menu again***********\n";
  cin>>ch2 ;
    }
}
  else
    cout<<"\n\nINVALID PASSWORD \n" ;
  return 0 ;
  }
else
{
    cout<<"ENTER YOUR CHOICE";
    cout<<"\n1.SEARCH AND BUY\n";
       fin1.open("cars.txt") ;
       cout<<"\n\n1: SEARCH BY BRAND AND MODEL\n\n";
       cout<<"2: SEARCH BY BRAND AND YEAR\n\n" ;
       cout<<"3: SEARCH BY BRAND AND PRICE\n\n" ;
       cin>>x ;
       switch(x)
       {
      	/*sub searching case 1 */
         case 1 :
         cin.sync() ;
         cout<<"ENTER YOUR DESIRED BRAND\n" ;
         cin>>brand ;
         brand = change(brand) ;
         cout<<"\nNOW ENTER THE MODEL PLEASE \n " ;
         cin>>model ;
         model = change(model) ;
         while(getline(fin1,s1))
         {
           stringstream ss(s1) ;
           ss>>c>>s2>>s3>>s4>>v ;
           if(s2 == brand && s3 == model )
           {
             car c1(c,s2,s3,s4,v) ;
             c1.disp()  ;
           }
         }
         break ;
   /*end of sub case 1 of search */
     /*start of sub search case 2 */
         case 2 :
         cout<<"ENTER YOUR DESIRED YEAR \n\n" ;
         cin>>year ;
         cout<<"WHAT BRAND DO YOU WANT IN THIS YEAR \n" ;
         cin>>brand ;
         brand = change(brand) ;
         while(getline(fin1,s1))
         {
           stringstream ss(s1) ;
           ss>>c>>s2>>s3>>s4>>v ;
           if(c == year && s2 == brand )
           {
             car c1(c,s2,s3,s4,v) ;
             c1.disp() ;
           }
         }
         break ;
   /*end od case 2 */
  /*sub search case 3 */
         case 3 :
           cout<<"ENTER YOUR DESIRED PRICE \n\n" ;
           cin>>price ;
           cin.sync() ;
           cout<<"FOR WHICH BRAND \n" ;
           cin>>brand ;
           brand = change(brand) ;
           while(getline(fin1,s1))
           {
              stringstream ss(s1) ;
              ss>>c>>s2>>s3>>s4>>v ;
              if(v == price && s2 == brand )
              {
                car c1(c,s2,s3,s4,v) ;
                c1.disp() ;
              }
           }
           break ;
         } /*end search cases */
         fin1.close() ;
   /* buy condition */
         cout<<"Press Y to buy a car from the above searched list\n" ;
         cin>>ch ;
         if(ch=='Y' || ch == 'y')
         {
           fin1.open("cars.txt") ;
  /* taking details for buying the car */
           cout<<"\n\nENTER THE NECCASARY DETAILS FOR A CAR TO BUY\n\n" ;
           cout<<"CAR BRAND:\n\n" ;
           cin>>s6 ;
           s6 = change(s6) ;
           cout<<"CAR MODEL:\n\n" ;
           cin>>s5 ;
           s5 = change(s5) ;
           cout<<"ITS YEAR:\n" ;
           cin>>b ;
           while(getline(fin1,s8))
           {
             stringstream sa(s8) ;
             sa>>c>>s2>>s3>>s4>>v ;
             if( c == b ) /*matching year */
             {
               if( s2 == s6) /*matching brand */
               {
                if(s3 == s5) /*matching model */
                {
                 cout<<"\n\n\n*****************CONGTRAZ CAR IS FOUND IN THE LIST\n\n\n****************" ;
                 count++ ;
        /* registration , taking customers details */
                 cout<<"FOR REGISTRATION :\n" ;
                 cin.sync() ;
                 cout<<"enter the customers name \n " ;
                 getline(cin,name) ;
                 name = case_change(name) ;
                 cout<<"enter the customers age \n " ;
                 cin>>age ;
                 cin.sync() ;
                 cout<<"enter the customers cnic \n " ;
                 getline(cin,cnic) ;
                 cnic = case_change(cnic) ;
                 cout<<"enter the customers contact number \n " ;
                 cin>>contact ;
                 if(contact.length()!=10)
                    cout<<"please enter a valid contact number";
                    cin.sync() ;
                 cout<<"enter the customer's address \n " ;
                 getline(cin,address) ;
                 address = case_change(address) ;
                 cin.sync() ;
                 cout<<"enter the customer's date of purchase \n" ;
                 getline(cin,id) ;
                 id = case_change(id) ;
                 cin.sync() ;
                 cout<<"enter the salesman name who sell the car \n" ;
                 getline(cin,sales) ;
                 sales = case_change(sales) ;
                 fout2.open("qwery.txt",ios::app) ;
                 fout2<<s8<<" "<<name<<" "<<age<<" "<<cnic<<" "<<contact<<" "<<address<<" "<<id<<" "<<sales<<"\n" ;
                 cout<<"\n\n\n******************CONGRATZ THE CAR IS BOUGHT SUCCESFULLY AND ITS RECORD IS ADDED IN DATABASE***********************\n" ;
                 cout<<"\nInvoice : \n" ;
                 customer cus(name,age,cnic,contact,address) ;
                 cus.set(id,s6,s5,s4,v,c) ;
                 cout<<"\nCUSTOMER INFO WHO BUY THE CAR \n\n" ;
                 cus.disp() ;
                 cout<<"SALESMAN NAME : "<<sales ;
                 fout2.close() ;
                 fin1.close() ;
                }
              }
            }
          }
        }
    }

}
