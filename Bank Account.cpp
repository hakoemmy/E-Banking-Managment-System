/* Abank account that uses the following features in C++
1.OOPS(Classes).
2.Functions
3.Arrays
4.LOOPs
5.Switch case Constructs
@@@H.Emmauel, The Software Developer At Heart.
....i assure that, its simple and well documented. 
*/
#include <iostream>
#include <conio.h>
#include<stdlib.h>
int reply;// avariable to handle global choice among our banking
//services.
char confirm;//avariable to allow control statements like goto.
//functionality.
long int array[4];//array to help us handle info to every transa
//action made by client.
using namespace std;
//defining a bank account class to handle account(all stuffs).
class bank_account{
private:
//class data members to be used in our system.
// these are dynamically changing as user made achange
long int balance;
string passcode;
string account_holder;
string username;
public:
//member functions to make every action i.e: to access data members and 
// use them.
void print_menu(){
cout<<"1.Deposit"<<endl;
cout<<"2.Withdraw"<<endl;
cout<<"3.check balance"<<endl;
cout<<"4.Money Transfer"<<endl;
cout<<"5.Mini statement"<<endl;
cout<<"\n\nPlease Reply with choice"<<endl;
cin>>reply;
}
void regist();// for bank registration;
void login();// for logging in as real user.
void deposit ();
void withdraw();
void check_balance();
void money_transfer();
void mini_statement();
};
int main(){
bank_account account1;
account1.regist();
account1.login();
go: account1.print_menu();
// this is switch case construct to handle user replies and 
//calling the corresponding function out of main function.
switch(reply)
{
case 1:
account1.deposit();
if(confirm =='y' || confirm == 'Y'){
	goto go;  
  }else if(confirm =='n' || confirm == 'N'){
break;
  }
  else{
cout<<"Wrong Reply??, Try one more time!!\n\n";
goto go;
  }
break;
case 2:
account1.withdraw();
if(confirm =='y' || confirm == 'Y'){
	goto go;  
  }else if(confirm =='n' || confirm == 'N'){
break;
  }else{
cout<<"Wrong Reply??, Try one more time!!\n\n";
goto go;
  }
break;
case 3:
account1.check_balance();
if(confirm =='y' || confirm == 'Y'){
	goto go;  
  }else if(confirm =='n' || confirm == 'N'){
break;
  }else{
cout<<"Wrong Reply??, Try one more time!!\n\n";
goto go;
  }
break;
case 4:
account1.money_transfer();
if(confirm =='y' || confirm == 'Y'){
	goto go;  
  }else if(confirm =='n' || confirm == 'N'){
break;
  }else{
cout<<"Wrong Reply??, Try one more time!!\n\n";
goto go;
  }
 break;
case 5:
account1.mini_statement();
if(confirm =='y' || confirm == 'Y'){
	goto go;  
  }else if(confirm =='n' || confirm == 'N'){
break;
  }else{
cout<<"Wrong Reply??, Try one more time!!\n\n";
goto go;
  }
	break;
default:
cout<<"Wrong Reply, Try again!.\n";
goto go;
	break;
}

getch();
return 0;
}
/* Function definition part, here i am gonna define all functions
declared in my class bank_account.*/
//Bank registration system in function definition.
void bank_account::regist(){
string name;
string account;
string password;
cout<<"WELCOME TO E-Banking Developed>>H.Emmanuel, The Software Developer at Heart\n\n";
cout<<"Enter your username:";
cin>>name;
cout<<"Enter an Account:";
cin>>account;
cout<<"Choose Password:";
cin>>password;
username = name;
account_holder = account;
passcode = password;
cout<<"You have successfully registered, with us!!\n\n";
cout<<"Welcome to E-Banking["<<username<<"]"<<endl;
cout<<"You can Login to continue??\n\n";
return;
}
//logging in the system.
void bank_account::login(){
string password;
retry: cout<<"Login(Password):";
cin>>password;
if(password == passcode){
cout<<"You have successfully login in as["<<username<<"]"<<endl<<endl;	
cout<<"Enjoy our E-Banking services!!,here is Menu Below\n\n"; 
}else{
cout<<"OOPs!, it's not you, Try one more time";
goto retry;	
}
return;
}
//defining deposit account to updating bank account
void bank_account::deposit(){
string password;
long int amount;
retry: cout<<"Provide Password:";
cin>>password;
if(password == passcode){
cout<<"\nEnter Amount of money to deposit:\n";
cin>>amount;
balance = balance + amount;
array[0]= balance;
cout<<"thank you, you have deposited: "<< amount<<"RwF\n\n";
cout<<"Do you want to perform another transaction?? type (y/Y for yes or N/n for no:";
cin>>confirm;	
}else{
cout<<"Wrong Password??, Try one more time!!!, ";
goto retry;	
}

return;
}

//withdraw function definition to make withdraw transaction.
void bank_account::withdraw(){
long int amount;
string password;
retry: cout<<"provide Password??:";
cin>>password;
if(password == passcode){
cout<<"Enter Amount of money to withdraw:\n";
cin>>amount;
if(amount != 0 && amount >0 && amount<= balance){
balance = balance - amount;	
array[1] = balance;
cout<<"thank you, you have successfully withdrawn: "<< amount<<"RwF\n\n";
cout<<"Do you want to perform another transaction??(y/Y for yes or N/n for no:";
}else{
cout<<"Transaction failed?? during your withdraw, try again\n";
cout<<"Type (y/Y) for yes to retry or (n/N) for no escape:";
}	
}else
{
cout<<"Wrong Password, try one more time!!";
goto retry;
}

cin>>confirm;
return;
}

//checking balance function definition.
void bank_account::check_balance(){
string password;
retry: cout<<"Provide Password:";
cin>>password;
if(password == passcode){
cout<<"Your current account is :"<< balance<<"RWF"<<endl;
cout<<"\n\n Thank you for banking with us!!\n\n";
cout<<"Do you want to perform another transaction??(y/Y for yes or N/n for no:";
cin>>confirm;
}else{
cout<<"Wrong password, Try one more time???:";
goto retry;	
}
return;
}
//money transfer function definition to transfer money.
void bank_account::money_transfer(){
long int amount;
string account;
string password;
retry: cout<<"provide Password??:";
cin>>password;
if(password == passcode){
cout<<"Enter Amount of money to transfer:\n";
cin>>amount;
if(amount != 0 && amount >0 && amount<= balance){
cout<<"Enter Recipient account number:";
cin>>account;
balance = balance - amount;	
array[2] = balance;
cout<<"you have successfully transfered: "<< amount<<"RwF to [";
cout<<account<<"] Bank Account"<<endl;
cout<<"\nThank you for banking with us!!\n";
cout<<"Do you want to perform another transaction??(y/Y for yes or N/n for no:";
}else{
cout<<"Transaction failed?? during your withdraw, try again\n";
cout<<"Type (y/Y) for yes to retry or (n/N) for no escape:";
}	
}else
{
cout<<"Wrong Password, try one more time!!";
goto retry;
}

cin>>confirm;
return;
}
//mini statement , to show up few transactions of the bank account

void bank_account::mini_statement(){
int index;
cout<<"Retrieved informations are:";
for(index = 0; index<3;index++){
cout<<array[index]<<endl<<endl;	
}
cout<<"\nThank you for banking with us!!\n";
cout<<"Do you want to perform another transaction??(y/Y for yes or N/n for no:";
cin>>confirm;
return;
}
/* it's coded by HAKORIMANA Emmanuel from College of
Science and Technology(CST)-Nyarugenge Campus in Computer
and software Engineering> */
