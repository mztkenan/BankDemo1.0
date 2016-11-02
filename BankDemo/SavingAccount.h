
#ifndef ACCOUNT_H
#define ACCOUNT_H 
#include "Date.h"
  class SavingAccount
  {
  private:
	  std::string id;
	  double balance;
	  double rate;
	  Date lastDate;
	  double accumulation;
	  static double total;
	  void record(const Date &date,double amount,const std::string &desc);
	  void error(const std::string &msg)const;
	  double accumulate(const Date& date)const { return accumulation + balance * date.distance(lastDate); }

  public:
	  SavingAccount(const Date &date,const std::string id,double rate);
	  const std::string getId() const {return id;}
	  double getBalance()const {return balance;}
	  double getRate()const {return rate;}
	  static double getTotal() { return total; }
	  void deposit(const Date &date,double amount,const std::string desc);
	  void withdraw(const Date &date,double amount,const std::string desc);
	  void settle(const Date &date);
	  void show() const;
  };
#endif