#pragma once
#include <iostream>
#include <string>
#include "abstractworker.h"
using namespace std;

class Boss :public AbstractWorker {
public:
	Boss(string id, string name, int job);

public:
	void display()override;
	string getJob()override;

};