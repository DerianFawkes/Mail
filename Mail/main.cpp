#include "mail.h"

int main()
{
	setlocale(0, "rus");
	Mail mail1("Îòïðàâëåíèå N1");
	mail1.setState(new Shipped);
	mail1.setState(new ArrivedForSorting);
	mail1.setState(new ShippedFromSorting);
	//mail1.setState(new Lost);

	system("pause");
	return 0;
}
