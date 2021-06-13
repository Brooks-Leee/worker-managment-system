#include "worker.h"

Worker::Worker(string id, string name, int job)
{
	m_id = id;
	m_name = name;
	m_job = job;
}

void Worker::display(){
	cout << " id: " << m_id << " name: " << m_name << " job: " << Worker::getJob() << endl;
}

string Worker::getJob()
{
	return string("worker");
}