
#ifndef ACCOUNT_H
#define ACCOUNT_H 
  class SavingAccount
  {
  private:
	  int id;
	  double balance;
	  double rate;
	  int lastDate;
	  double accumulation;
	  void record(int date,double amount);
	  double accumulate(int date)const{return accumulation+balance*(date-lastDate);}

  public:
	  SavingAccount(int date,int id,double rate);
	  int getId(){return id;}
	  double getBalance(){return balance;}
	  double getRate(){return rate;}
	  void deposit(int date,double amount);
	  void withdraw(int date,double amount);
	  void settle(int date);
	  void show();
  };
#endif