#include <iostream>
#include <string>
#include "system.h"
#include "boss.h"
#include "manager.h"
#include "worker.h"
using namespace std;



int main() {
	System sys1;
	int select = 0;
	while (true)
	{
		sys1.displayMenu();
		cout << "Enter number to manipulate: ";
		cin >> select;
		switch (select)
		{
		case 0:
			sys1.exitSystem(); 
			break;
		case 1:
			sys1.addWorker();
			break;
		case 2:
			sys1.displayWorker();
			break;
		case 3:
			sys1.deleteWorker();
			break;
		case 4:
			sys1.modifyWorker();
			break;
		case 5:
			sys1.searchWorker();
			break;
		case 6:
			sys1.sortWorker();
			break;
		case 7:
			sys1.clearSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
}