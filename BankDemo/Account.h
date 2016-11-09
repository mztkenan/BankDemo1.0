
#ifndef ACCOUNT_H
#define ACCOUNT_H 
#include "Date.h"
#include "Accumulator.h"
using namespace std;

class Account
{
public:
	const string &getId() const { return id; }
	double getBalance()const { return balance; }
	void show()const;
	static double getTotal() { return total; }
protected:
	Account(const Date &date, const string &id);
	void record(const Date &date, double amount, const string &desc);
	void error(const string &msg)const;
private:
	std::string id;
	double balance;
	static double total;
};


  class SavingAccount:public Account
  {
  private:
	  double rate;
	  Accumulator acc;
  public:
	  SavingAccount(const Date &date,const string &id,double rate);
	  double getRate()const {return rate;}
	  void deposit(const Date &date,double amount,const string &desc);
	  void withdraw(const Date &date,double amount,const string &desc);
	  void settle(const Date &date);
  };

  class CreditAccount:public Account
  {
  public:
	  CreditAccount(const Date &date, const string &id,double credit, double rate,double fee);
	  double getCredit() const { return credit; }
	  double getRate() const{ return rate; }
	  double getFee() const{ return fee; }
	  double getAvailableCredit() const{
		  if (getBalance() < 0) return credit + getBalance();
		  else return credit;
	  }
	  void deposit(const Date &date, double amount, const string &desc);
	  void withdraw(const Date &date, double amount, const string &desc);
	  void settle(const Date &date);
	  void show()const; 
  private:
	  Accumulator acc;
	  double credit, rate, fee;
	  double getDebt()const {
		  double balance = getBalance();
		  return(balance < 0 ? balance : 0);
	  }
  };
#endif