#include "mail.h"



void Mail::setState(State * newState)
{
	string msg = "Статус отправления изменён";
	if (newState != nullptr)
	{
		if (state != nullptr)
		{
			msg += " с " + state->to_string();
			delete state;
		}
		state = newState;
		msg += " на " + state->to_string();
	}
	cout << name << ": " << endl << msg << endl;
}

void TakenFromSender::setShipped(Mail* x)
{
	x->setState(new Shipped());
}

void TakenFromSender::setLost(Mail* x)
{
	x->setState(new Lost());
}

void Shipped::setArrivedForSorting(Mail * x)
{
	x->setState(new ArrivedForSorting());
}

void Shipped::setArrivedTransitPost(Mail * x)
{ 
	x->setState(new ArrivedTransitPost());
}

void Shipped::setLost(Mail * x)
{
	x->setState(new Lost());
}

void ArrivedForSorting::setShippedFromSorting(Mail * x)
{
	x->setState(new ShippedFromSorting());
}

void ArrivedForSorting::setLost(Mail * x)
{
	x->setState(new Lost());
}

void ShippedFromSorting::setArrivedTransitPost(Mail * x)
{
	x->setState(new ArrivedTransitPost());
}

void ShippedFromSorting::setArrivedDeliveryPost(Mail * x)
{
	x->setState(new ArrivedDeliveryPost());
}

void ShippedFromSorting::setLost(Mail * x)
{
	x->setState(new Lost());
}

void ArrivedTransitPost::setShippedTransitPost(Mail * x)
{
	x->setState(new ShippedTransitPost());
}

void ArrivedTransitPost::setLost(Mail * x)
{
	x->setState(new Lost());
}

void ShippedTransitPost::setArrivedForSorting(Mail * x)
{
	x->setState(new ArrivedForSorting());
}

void ShippedTransitPost::setArrivedDeliveryPost(Mail * x)
{
	x->setState(new ArrivedDeliveryPost());
}

void ShippedTransitPost::setLost(Mail * x)
{
	x->setState(new Lost());
}

void ArrivedDeliveryPost::setFailedDelivery(Mail * x)
{
	x->setState(new FailedDelivery());
}

void ArrivedDeliveryPost::setReceived(Mail * x)
{
	x->setState(new Received());
}

void ArrivedDeliveryPost::setReturned(Mail * x)
{
	x->setState(new Returned());
}

void ArrivedDeliveryPost::setLost(Mail * x)
{
	x->setState(new Lost());
}

void FailedDelivery::setShipped(Mail * x)
{
	x->setState(new Shipped());
}
