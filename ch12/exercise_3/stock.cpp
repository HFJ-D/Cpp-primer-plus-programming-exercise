
#include "stock.h"
#include <cstring>

Stock::Stock()
{
	company = "nullptr";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}


Stock::Stock(const char * co, long n, double pr)
{
	company = new char[strlen(co)+1];
	strcpy(company, co);

	if(n < 0)
	{
		std::cout << "Numer of shares can't be negative; " << company << " shares set to be 0." << std::endl;
		shares = 0;
	}	
	else
		shares = n;

	share_val = pr;

	set_tot();
}

Stock::~Stock()
{
	delete []company;
}

void Stock::buy(long num, double price)
{
	if(num < 0)
	{
		std::cout << "Numer of shares can't be negative, Transaction is aborted" << std::endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;

	if(num < 0)
	{
		std::cout << "Numer of shares can't be negative, Transaction is aborted" << std::endl;
	}
	else if(num > shares)
	{
		cout << "You can't sell more than you have! Transaction is aborted." << std::endl;
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

ostream & operator<<(ostream & os, const Stock & s)
{
	using std::ios_base;
	ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << s.company
	   << " Shares: " << s.shares << '\n';
	os << " Share price: $" << s.share_val;
	os.precision(2);
	os <<" Total Worth: $" << s.total_val << '\n';
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}

const Stock & Stock::topval(const Stock &s) const
{
	if(s.total_val > total_val)  //total_val == this->total_val
		return s;
	else
		return *this;
}
