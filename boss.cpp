#include "boss.h"

Boss::Boss(string id, string name, int job)
{
	m_id = id;
	m_name = name;
	m_job = job;
}

void Boss::display() {
	cout << " id: " << m_id << " name: " << m_name << " job: " << Boss::getJob() << endl;
}

string Boss::getJob()
{
	return string("boss");
}