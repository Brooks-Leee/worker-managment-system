#pragma once
#include <iostream>
#include <string>
#include "abstractworker.h"
using namespace std;


class Worker :public AbstractWorker {
public:
	Worker(string id, string name, int job);


public:
	void display()override;
	string getJob()override;
};