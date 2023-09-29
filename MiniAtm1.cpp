#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<vector>
using namespace std;

//This Code is Not Perfect, it is Still in Testing and Under-Development//

struct Account {
    string fullName;
    string pin;
    double balance;
};

vector<Account> accounts;

void login();
void registr();
void saveUserData();
void loadUserData();
int findAccount(const string& user, const string& pass);

int main ()

{
    char choic;
    loadUserData();
    while(true)
    {
    cout<<"Welcome To MiniATM ^_^"<<endl;
    cout<<"\nYour Money iS 101% safe here!!"<<endl;
    cout<<"\n1.Login"<<endl;
    cout<<"2.Register Your Account"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"\nEnter Your Choice 1/3:"<<endl;
    cin>>choic;
    cout<<endl;

    system("cls");

    switch(choic)
    {
        case '1':
        login();
        break;

        case '2':
        registr();
        break;

        case '3':
        cout<<"Thank You"<<endl;
        system("cls");
        saveUserData();
        return 0;
		break;

        default:
        cout<<"Invalid Choice"<<endl;
        break;
    }

    return 0;
    
}  
}

void login()
{
    
    string user,pass;
    cout<<"Enter Your Full Name (NoSpace)"<<endl;
    cin>>user;
    cout<<"Enter Pin"<<endl;
    cin>>pass;

    int index = findAccount(user, pass);

    
    

    if (index != -1) {
        system("cls");
    
    char choice;
    double deposit, withdraw;
    


    while(true)
    {  
    cout << "\nWelcome " << accounts[index].fullName <<" ^_^ "<<endl;   
    cout<<"\nSelect Option!!"<<endl;
    cout<<"1.Deposit Money"<<endl;
    cout<<"2.Withdraw Money"<<endl;
    cout<<"3.Check Balance"<<endl;
    cout<<"4.Logout"<<endl;
    cin>>choice;

    if(choice=='4')
    {
        cout<<"\nLogOUt SucessFully!! "<<endl;
        system("cls");
        main();
        break;
    }
    switch(choice)
    {
        case '1':
        cout<<"Enter Amount to Deposit"<<endl;
        cin>>deposit;
        accounts[index].balance+=deposit;
        cout<<"Your Amount "<<deposit <<" INR Has Deposited"<<endl;
        cout<<"Your Balance "<<accounts[index].balance<<" INR"<<endl;
    
        break;

        case '2':
        cout<<"Enter Amount To Withdraw (Max Amount 20000 INR) "<<endl;
        cin>>withdraw;
        if(accounts[index].balance<withdraw)
        {
            cout<<"Transaction Error!! You Dont Have Suffcient Amount "<<endl<<"Your Balance is "<<accounts[index].balance<<endl;
        }
        else if(withdraw>20000)
        {
            cout<<"Transaction Error!! You've entered Amount "<<withdraw<<" INR is Greater than Limit (20000 INR)" <<endl<<"Your Balance is "<<accounts[index].balance<<endl;
        }
        else
        {
        accounts[index].balance-=withdraw;
        cout<<"Your Amount "<<withdraw <<" INR Has Withdrawed"<<endl;
        cout<<"Your Balance INR "<<accounts[index].balance<<" INR"<<endl;
        }
        break;
        
        case '3':
        cout<<"Your Balance is "<<accounts[index].balance<<" INR"<<endl;
        break;

        default:
        cout<<"Invalid Choice 1/4"<<endl;
        break;



}
    
    }
    }
    else
    {
        cout<<"Wrong UserName/Pin"<<endl;
        
    }
   
}

void registr()
{
    string reguser,regpass;
    cout<<"Enter Your Full Name (Use Nospace) "<<endl;
    cin>>reguser;
    cout<<"Enter Pin"<<endl;
    cin>>regpass;

    accounts.push_back({reguser, regpass, 0.0});
    system("cls");

    cout<<"Account "<<reguser<<" Has Registered Sucessfully, \nYour Pin is "<<regpass<<endl;
    main();

}

void saveUserData()
{
    ofstream outfile("BankInfo.txt");

    if (outfile.is_open()) {
        for (const Account &acc : accounts) {
            outfile << acc.fullName << " " << acc.pin << " " << acc.balance << endl;
        }
        outfile.close();
    }
}

void loadUserData()
{
    ifstream infile("BankInfo.txt");


    if (infile.is_open()) {
         // Clear existing account data
        string name, pin;
        double balance;
        while (infile >> name >> pin >> balance) {
            accounts.push_back({name, pin, balance});
        }
        infile.close();
    }
}

int findAccount(const string& user, const string& pass) {
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].fullName == user && accounts[i].pin == pass) {
            return i;
        }
    }
    return -1; 
}

//Stage://
//Finalizing and Testing The code//
