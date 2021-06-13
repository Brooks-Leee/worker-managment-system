#include "manager.h"

Manager::Manager(string id, string name, int job)
{
	m_id = id;
	m_name = name;
	m_job = job;
}

void Manager::display(){
	cout << " id: " << m_id << " name: " << m_name << " job: " << Manager::getJob() << endl;
}

string Manager::getJob()
{
	return string("manager");
}