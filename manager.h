#pragma once
#include <iostream>
#include <string>
#include "abstractworker.h"
using namespace std;

class Manager :public AbstractWorker {
public:
	Manager(string id, string name, int job);

public:
	void display() override;
	string getJob()override;

};