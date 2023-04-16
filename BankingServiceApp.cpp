#include<iostream>
#include<string.h>
using namespace std;

class Account;
class Loan;
class SavingsAcc;
class CurrentAcc;
class Card;
class CreditCard;
class DebitCard;
class Payment;
class Rewards;
class Bill;
class Recharge;
class UPI;
class Booking;
class MyException;


class Loan
{
public:
    float sourceOfIncome; //takes source of income
    Loan(float sourceOfIncome)
    {

    }
    void tosanctionLoan()  //sanctions loan based on the source of income
    {
        int ch;
        cout<<"1-Education loan\n";
        cout<<"2-Farming Loan\n";
        cout<<"3-Home Loan\n";
        cout<<"4-Gold loan\n";
        cout<<"5-Vehicle loan\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            if(sourceOfIncome<=50000&&sourceOfIncome>10000)
            {
                cout<<"Loan Provided will be 30000\n";
            }
            else if(sourceOfIncome<100000&&sourceOfIncome>50000)
            {
                cout<<"Loan Provided will be 70000\n";
            }
            else if(sourceOfIncome<200000&&sourceOfIncome>100000)
            {
                cout<<"Loan Provided will be 150000\n";
            }
            else if(sourceOfIncome<10000)
            {
                cout<<"No loan will be sactioned\n";
            }
            break;
        case 2:
             if(sourceOfIncome<=300000&&sourceOfIncome>700000)
            {
                cout<<"Loan Provided will be 50000\n";
            }
            else if(sourceOfIncome<400000&&sourceOfIncome>120000)
            {
                cout<<"Loan Provided will be 100000\n";
            }
            else if(sourceOfIncome<600000&&sourceOfIncome>200000)
            {
                cout<<"Loan Provided will be 1400000\n";
            }
            else if(sourceOfIncome<20000)
            {
                cout<<"No loan will be sanctioned\n";
            }
            break;
        case 3:
             if(sourceOfIncome<=50000&&sourceOfIncome>10000)
            {
                cout<<"Loan Provided will be 30000\n";
            }
            else if(sourceOfIncome<100000&&sourceOfIncome>50000)
            {
                cout<<"Loan Provided will be 70000\n";
            }
            else if(sourceOfIncome<200000&&sourceOfIncome>100000)
            {
                cout<<"Loan Provided will be 150000\n";
            }
            else if(sourceOfIncome<10000)
            {
                cout<<"No loan will be sanctioned\n";
            }
            break;
        case 4:
             if(sourceOfIncome<=50000&&sourceOfIncome>10000)
            {
                cout<<"Loan Provided will be 30000\n";
            }
            else if(sourceOfIncome<100000&&sourceOfIncome>50000)
            {
                cout<<"Loan Provided will be 70000\n";
            }
            else if(sourceOfIncome<200000&&sourceOfIncome>100000)
            {
                cout<<"Loan Provided will be 150000\n";
            }
            else if(sourceOfIncome<10000)
            {
                cout<<"No loan will be sactioned\n";
            }
            break;
        case 5:
             if(sourceOfIncome<=50000&&sourceOfIncome>10000)
            {
                cout<<"Loan Provided will be 30000\n";
            }
            else if(sourceOfIncome<100000&&sourceOfIncome>50000)
            {
                cout<<"Loan Provided will be 70000\n";
            }
            else if(sourceOfIncome<200000&&sourceOfIncome>100000)
            {
                cout<<"Loan Provided will be 150000\n";
            }
            else if(sourceOfIncome<10000)
            {
                cout<<"No loan will be sanctioned\n";
            }
            break;
        default :
            break;
        }
    }


};






class Customer
{
public:
    string custName;
    string address;
    long long int phNo;
    string email;
    string password;
    Account *acc;  //Customer has account
    //Customer():custName(" "),address(" "),phNo(0),email(" "),password(" "){}
    Customer(string custName, string address, long long int phNo, string email,string password)
    {
        this->custName=custName;
        this->address=address;
        this->phNo=phNo;
        this->email=email;
       this-> password=password;
    }
    void login()   //The system asks for the password, if the password matches then the user will login
    {
        string psswrd;

        cout<<"Enter the password : ";
        cin>>psswrd;
        if(psswrd==password)
        {
            cout<<"\n\n.........Login Successful.........\n\n";
        }
        else
            cout<<"\n\n Failed to login";

    }
    void logout()   //The user logouts when called
    {
        cout<<"\n\n........Logout Successful...........\n\n";
    }
    void loan(Loan L)  //Loan class is called
    {
        L.tosanctionLoan();

    }
};
class Payment
{
public:
    int paymentId;
    string date;
    float paymentAmt;
    Rewards *R;   //Payment has Rewards
    Payment():paymentId(0),date(" "),paymentAmt(0)
    {
    }
    Payment(int paymentId,string date,float paymentAmt)
    {

    }
};

class Bill : public Payment
{
public:
    int paymentId;
    string date;
    float paymentAmt;
    Bill(int paymentId,string date,float paymentAmt)
    {
        this->paymentId=paymentId;
        this->date=date;
        this->paymentAmt=paymentAmt;
    }
    float bill()
    {
    float amt;
    cout<<"\nEnter the debit amount for bill :\n";
    cin>>amt;
    return amt;   //returns the debit amount
    }
};

class Recharge : public Payment
{
public:
     Recharge(int paymentId,string date,float paymentAmt):Payment(paymentId,date,paymentAmt){}
    float recharge()
    {
    float amt;
    cout<<"\nEnter the debit amount for recharge :\n";
    cin>>amt;
    return amt;   //returns the debit amount
    }
};

class UPI : public Payment
{
public:
     UPI(int paymentId,string date,float paymentAmt):Payment(paymentId,date,paymentAmt){}
    float upi()
    {
    float amt;
    cout<<"\nEnter the debit amount for UPI :\n";
    cin>>amt;
    return amt;         //returns the debit amount
    }
};

class Booking : public Payment
{
public:
     Booking(int paymentId,string date,float paymentAmt):Payment(paymentId,date,paymentAmt){}
    float booking()
    {
    float amt;
    cout<<"\nEnter the debit amount for Booking :\n";
    cin>>amt;
    return amt;   //returns the debit amount
    }
};

class Rewards
{
    static Rewards *instance;   //Singleton design pattern
public:
    static Rewards *getInstance()
    {
        if(!instance)
            instance=new Rewards;
        return instance;
    }
    void reward(Bill B, Recharge R,UPI U,Booking Bk)  //Rewards are given based on the amount being debitted
    {
     if(B.bill()>500)
        cout<<"\n\n Get upto 50% off on Puma website "<<endl;
    if(R.recharge()>300)
        cout<<"\n\n Get 50% off on Myntra E-Voucher "<<endl;
    if(U.upi()>800)
        cout<<"\n\n Get 50% off on Pizza-Hut E-Voucher "<<endl;
    if(Bk.booking()>1000)
        cout<<"\n\n Get Rs.300 off + Free shipping on purchase of Rs.1199 on AJIO "<<endl;
    else
        cout<<"\n\n No rewards.......Better luck next time..."<<endl;
    }
};
Rewards *Rewards :: instance = 0;

class Card
{
public:
    int cardNo;
    int cvv;
    string expiryDate;
    virtual ~Card(){}
    Card():cardNo(0),cvv(0),expiryDate(" ")
    {}
    Card(int cardNo,int cvv,string date)
    {
        cardNo=cardNo;
        cvv=cvv;
        expiryDate=date;
    }
    virtual void afterPayment()
   {}
};

class CreditCard : public Card
{
public:

    CreditCard(): Card()
    {
    }
    int cardNo;
    int cvv;
    string expiryDate;
    float CCamt;  //The amount in credit card
    CreditCard(int cardNo,int cvv,string expiryDate,float CCamt)
    {
        this->cardNo=cardNo;
        this->cvv=cvv;
        this->expiryDate=expiryDate;
        this->CCamt=CCamt;
    }

    void issueCredit() //The credit card is being issued to the user
    {
     cout<<"\n\nThe credit card of rs."<<CCamt<<" is issued to the customer"<<endl;
    }
     void afterPayment( Bill b,Recharge r,UPI u,Booking bk) //The amount in credit card after payment
    {
        int option;
        cout<<"The payment options are --- \n"<<"\n1. Bill\n"<<"\n2.Recharge\n"<<"\n3.UPI\n"<<"\n4.Booking\n"<<endl;
        cout<<"\n your option is ?"<<endl;
        cin>>option;
        if(option==1)
        {
            CCamt=CCamt-b.bill();
        }
        else if(option==2)
        {
            CCamt=CCamt-r.recharge();
        }
        else if(option==3)
        {
            CCamt=CCamt-u.upi();
        }
        else if(option==4)
        {
              CCamt=CCamt-bk.booking();
        }
        else{
            cout<<"\nInvalid option"<<endl;
        }
        cout<<"\n\n The Credit card balance is : "<<CCamt;  //displays the balance amount
    }
    virtual ~CreditCard(){}
};

class DebitCard : public Card
{
public:
    float DCamt;
    DebitCard(): Card()
    {
    }
    DebitCard(int cardNo,int cvv,string expiryDate,float DCamt)
    {
        this->cardNo=cardNo;
        this->cvv=cvv;
        this->expiryDate=expiryDate;
        this->DCamt=DCamt;
    }
    void afterPayment(Bill b,Recharge r,UPI u,Booking bk) //The amount in debit card after payment
    {
        int option;
        cout<<"\nYour Debit card amount is your balance amount"<<endl;
        cout<<"The payment options are --- \n"<<"\n1. Bill\n"<<"\n2.Recharge\n"<<"\n3.UPI\n"<<"\n4.Booking\n"<<endl;
        cout<<"\n your option is ?"<<endl;
        cin>>option;
        if(option==1)
        {
            DCamt=DCamt-b.bill();

        }
        else if(option==2)
        {
            DCamt=DCamt-r.recharge();

        }
        else if(option==3)
        {
            DCamt=DCamt-u.upi();

        }
         else if(option==4)
        {
            DCamt=DCamt-bk.booking();

        }
        else{
            cout<<"\nInvalid option"<<endl;
        }

       cout<<"\n\n The Debit card balance is : "<<DCamt; //Displays the amount in debit card
    }
     virtual ~DebitCard(){}
};

class MyException
{
 public:
         string msg;
         MyException(string msg){
         this->msg=msg;
         }
         void show()
         {
             cout<<msg;
         }
};

class Account
{
public:
    long long int accNo;
    double balance;
    string dateOfOpening;
    CreditCard *CC; //Account has credit card
    DebitCard *DC; //Account has debit card
    Account():accNo(0),balance(0),dateOfOpening(" ")
    {
    }
    Account(long long int accNo,float bal,string date)
    {
       this->accNo=accNo;
        balance=bal;
        dateOfOpening=date;
    }

    void creditAmt()   //The user can credit the amount to his account
    {
        int cAmt;
        cout<<"Enter the credit amount : "<<cAmt;
        cin>>cAmt;
        balance = balance+cAmt;
        cout<<"The balance amount after credit is  : "<<balance;
    }
    virtual void newBalance(){}
    void myExcep()  //Exception function for Account number
      {
          if(accNo>0)
          {
              throw MyException("\nValid Account number\n");
          }
          else
          {
              throw MyException("\nInvalid Account number\n");
          }
      }
};


class SavingsAcc:public Account
{
public:

    SavingsAcc():Account(){}
    long long int accNo;
    double balance;
    string dateOfOpening;
    double interestRate;
    SavingsAcc(long long int aNo,double bal,string dOfO,double iRate)
    {
        this->accNo=aNo;
        balance=bal;
        dateOfOpening=dOfO;
        interestRate=iRate;
    }
    void newBalance()
    {
      /*float balance1 = (interestRate/100)*balance;
      balance=balance1+balance;*/
      balance=balance+((interestRate/100)*balance);
       cout<<"\n\nThe new balance is : "<<balance<<endl;  //The new balance after adding the interest rate
    }
      void myExcep()  //Exception function for Account number
      {
          if(accNo>0)
          {
              throw MyException("\nValid Account number\n");
          }
          else
          {
              throw MyException("\nInvalid Account number\n");
          }
      }
};

class CurrentAcc:public Account
{
public:
    long long int accNo;
    double balance;
    string dateOfOpening;
    double depositLimit;
   CurrentAcc(long long int aNo,double bal,string dOfO,double dl)
    {
       this->accNo=aNo;
        balance=bal;
        dateOfOpening=dOfO;
        depositLimit=dl;
    }
    void newBalance()
    {
      balance = depositLimit+balance;
       cout<<"\n\nThe new balance is : "<<balance<<endl;   //the new balance after adding the deposit limit

    }
      void myExcep()  //Exception function for Account number
      {
          if(accNo>0)
          {
              throw MyException("\nValid Account number\n");
          }
          else
          {
              throw MyException("\nInvalid Account number\n");
          }
      }
};

class PaymentDetails
{
protected:
    Card *c;
public:
    PaymentDetails(Card *c1)
    {
        c=c1;
    }
};


int main()

{

  //Objects for Payment
   Bill Bill1(1234,"18-2-22",500);
   Bill Bill2(4356,"25-12-21",2000);
   Bill Bill3(4356,"25-12-21",1500);
   Recharge R4(4598,"6-8-20",700);
   Recharge R5(568,"16-7-20",1000);
   UPI U6(7689,"23-2-22",250);
   UPI U7(6530,"12-6-19",400);
   Booking Bk8(6743,"11-7-20",6000);
   Booking Bk9(7639,"15-12-21",4500);
   Booking B10(6508,"20-10-19",1700);
   Booking Bk11(5347,"30-8-21",2400);
   Booking Bk12(6536,"13-6-19",4300);

//objects for card

  CreditCard Card1(3556,167,"27-7-23",10000);
  CreditCard Card2(4556,527,"10-12-22",45000);
  CreditCard Card3(9056,563,"24-9-24",20000);
  CreditCard Card4(6456,554,"5-5-23",30000);
  CreditCard Card5(3489,667,"6-8-25",50000);
  DebitCard Card6(3590,577,"30-8-22",10000);
  DebitCard Card7(4454,569,"20-12-23",25000);
  DebitCard Card8(4455,560,"17-7-24",50000);
  DebitCard Card9(5645,587,"9-11-22",45000);
  DebitCard Card10(3456,167,"26-8-23",30000);


  Customer C1("Ravi","Hubli",6982345612,"Ravi@gmail.com","Ravi123");
  Customer C2("Ram","Dharawad",6982345672,"Ram@gmail.com","Rami623");
  Customer C3("Rama","Gadag",6123445612,"Rama@gmail.com","Rama5623");
  Customer C4("Priya","Hospete",7682345712,"priyam09@gmail.com","Priya@123");
  Customer C5("Suma","Hubli",6411134561,"Sumadd06@gmail.com","sumadd@56");
  Customer C6("Nayana","Davanagere",7982345822,"Nayana@gmail.com","Nayanadg673");
  Customer C7("Shrinidhi","Bangalore",6982765612,"Shree@gmail.com","Shree923");
  Customer C8("Sindhu","Hasan",7085765637,"Sindhu@gmail.com","Sindhu@5643");
  Customer C9("kriti","Sirsi",7423165610,"Kriti@gmail.com","Kriti4512");
  Customer C10("Soumya","Belgum",7682765656,"Soumya@gmail.com","Soumya1234");


  Rewards r1;

  //objects for account

  SavingsAcc A1(1345627976,50000,"24-5-19",5);
  SavingsAcc A2(1345627975,40000,"24-4-19",3);
  SavingsAcc A3(3454562781,80000,"27-7-16",5);
  SavingsAcc A4(3247562761,100000,"5-5-18",6);
  SavingsAcc A5(4537562741,250000,"24-9-15",2);
  CurrentAcc A6(-3241262791,60000,"5-8-20",10000);
  CurrentAcc A7(4677562781,70000,"19-5-16",25000);
  CurrentAcc A8(5678562756,560000,"24-9-12",50000);
  CurrentAcc A9(3421562561,630000,"10-12-10",45000);
  CurrentAcc A10(4587562891,90000,"30-8-19",30000);

  Account Acc[]={A1,A2,A3,A4,A5,A5,A6,A7,A8,A9,A10};

  Account acc1(1234,45000,"25-3-10");

  //calling exception class
try
{
    A1.myExcep();
 }
   catch (MyException E)
  {
            E.show();
  }

 //the customer login
  //C1.login();

  //The customer credits the amount to his account
 //acc1.creditAmt();

  //The customer checks his balance
  // A1.newBalance();
//   A2.newBalance();
 //  A6.newBalance();

   //The customer is issued a credit card
  //Card1.issueCredit();

   //The customer uses payment and checks his balance in his card after payment

  int choice;
  //cout<<"\nPress 1 for credit card and 2 for Debit card "<<endl;
//  cin>>choice;
//  switch(choice)
//  {
//      case 1: if(choice==1)
//               PaymentDetails *p=new PaymentDetails(new CreditCard());
//               Card1.afterPayment(Bill1,R4,U6,Bk8);
//               break;
//      case 2: if(choice==2)
//               PaymentDetails *p=new PaymentDetails(new CreditCard());
//               Card6.afterPayment(Bill1,R4,U6,Bk8);
//               break;
//      default: break;
//  }


  //The customer receives a reward based on his payment amount
  Rewards *l=l->getInstance();
  //r1.reward(Bill1,R4,U6,Bk8);

  //The customer applies for loan
   Loan L1(2000000);
   L1.tosanctionLoan();

   //The customer logsout
  //C1.logout();
}
