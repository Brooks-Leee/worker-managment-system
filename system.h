#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "abstractworker.h"
using namespace std;

class System {
public:
	AbstractWorker** workerArrptr;
	int length;

public:
	System() ;
	~System() ;

public:
	void exitSystem();
	void addWorker();
	void displayWorker();
	void deleteWorker();
	void modifyWorker();
	void searchWorker();
	void sortWorker();
	void clearSystem();

	void displayMenu();
	void saveFile();
	void initArray();


};	