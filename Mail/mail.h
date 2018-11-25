#pragma once
#include <iostream>
#include <string>

using namespace std;



class Mail
{
protected:
	string name;
	class State* state;
public:
	
	Mail(string n) { name = n; };
	//~Mail() {delete state; state = nullptr;};
	
	class State& getState() { return *state; }
	void setState(class State* newState);
	string getName() { return name; };
	void setName(string nameMail) { name = nameMail; };


};

class  State
{
public:
	virtual string to_string() = 0;
	virtual void setTakenFromSender(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setShipped(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setArrivedForSorting(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setShippedFromSorting(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setArrivedTransitPost(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setShippedTransitPost(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setArrivedDeliveryPost(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setFailedDelivery(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setReceived(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setReturned(Mail* x) { cout << "������������ ������" << endl; };
	virtual void setLost(Mail* x) { cout << "������������ ������" << endl; };
};

class TakenFromSender :
	public State
{
public:
	string to_string() { return "\"������� � ��������� �����\""; };
	void setShipped(Mail* x);
	void setLost(Mail* x);
};

class Shipped :
	public State
{
public:
	string to_string() { return "\"�������� ����� �����\""; };
	void setArrivedForSorting(Mail* x);
	void setArrivedTransitPost(Mail* x);
	void setLost(Mail* x);
};

class ArrivedForSorting :
	public State
{
public:
	string to_string() { return "\"������� � ������������� �����\""; };
	void setShippedFromSorting(Mail* x);
	void setLost(Mail* x);
};

class ShippedFromSorting :
	public State
{
public:
	string to_string() { return "\"�������� ������������� �����\""; };
	void setArrivedTransitPost(Mail* x);
	void setArrivedDeliveryPost(Mail* x);
	void setLost(Mail* x);
};

class ArrivedTransitPost :
	public State
{
public:
	string to_string() { return "\"������� � ������������� �����\""; };
	void setShippedTransitPost(Mail* x);
	void setLost(Mail* x);
};

class ShippedTransitPost :
	public State
{
public:
	string to_string() { return "\"�������� ������������� �����\""; };
	void setArrivedForSorting(Mail* x);
	void setArrivedDeliveryPost(Mail* x);
	void setLost(Mail* x);
};

class ArrivedDeliveryPost :
	public State
{
public:
	string to_string() { return "\"������� � ����� ��������\""; };
	void setFailedDelivery(Mail* x);
	void setReceived(Mail* x);
	void setReturned(Mail* x);
	void setLost(Mail* x);
};

class FailedDelivery :
	public State
{
public:
	string to_string() { return "\"��������� ������� ��������\""; };
	void setShipped(Mail* x);
};

class Received :
	public State
{
public:
	string to_string() { return "\"���������� ����������\""; };
};

class Returned :
	public State
{
public:
	string to_string() { return "\"���������� �����������\""; };
};

class Lost :
	public State
{
	string to_string() { return "\"�������\""; };
};

