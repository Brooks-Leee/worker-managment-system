#pragma once
#include <iostream>
#include <string>
using namespace std;

class AbstractWorker {
public:
	string m_id;
	string m_name;
	int m_job;

public:
	virtual void display() = 0;
	virtual string getJob() = 0;
};