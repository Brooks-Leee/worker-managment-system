#include "system.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"

System::System() 
{
	//length = 0;
	//workerArrptr = NULL;
	ifstream ifs;
	ifs.open("worker_list.txt", ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "File doesn't exist." << endl;
		workerArrptr = NULL;
		length = 0;
		ifs.close();
		return;
	}
	//判断文件是否为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "File is empty." << endl;
		workerArrptr = NULL;
		length = 0;
		ifs.close();
		return;
	}
	System::initArray();
	

}

System::~System() 
{
	System::saveFile();
	if (workerArrptr != NULL)
	{
		delete[] workerArrptr;
		workerArrptr = NULL;
	}
}

void System::displayMenu()
{
	cout << "*********************************" << endl;
	cout << "* 0. Exist the system.          *" << endl;
	cout << "* 1. Add worker into system.    *" << endl;
	cout << "* 2. Display all workers.       *" << endl;
	cout << "* 3. Delete worker.             *" << endl;
	cout << "* 4. Modify worker info.        *" << endl;
	cout << "* 5. Search and display worker. *" << endl;
	cout << "* 6. Sort the system.           *" << endl;
	cout << "* 7. clear system.              *" << endl;
	cout << "*********************************" << endl;
}

void System::exitSystem()
{
	cout << "System has already exited!" << endl;
	system("pause");
	exit(0);
}

void System::addWorker()
{
	int num;
	while (true)
	{
		cout << "How many workers do you want to add: " << endl;
		cin >> num;
		if (num < 1)
		{
			cout << "Wrong number, Please try again: " << endl;
			system("pause");
			system("cls");
			System::displayMenu();
		}
		else
		{
			//转移数据
			AbstractWorker** newArray = new AbstractWorker * [num + length];	
			for (int i = 0; i < length; i++)
			{
				newArray[i] = workerArrptr[i];
			}
			for (int i = 0; i < num; i++)
			{
				string id, name;
				int job;
				cout << "Enter job:" << endl;
				cout << "1. worker  2. manager  3. boss" << endl;
				cin >> job;
				cout << "Enter name: " << endl;
				cin >> name;
				cout << "Enter id: " << endl;
				cin >> id;
				
				AbstractWorker* temp = NULL;
				switch (job)
				{
				case 1:
					temp = new Worker(id, name, 1);
					break;
				case 2:
					temp = new Manager(id, name, 2);
					break;
				case 3:
					temp = new Boss(id, name, 3);
					break;
				default:
					break;
				}
		
				newArray[length + i] = temp;
				cout << "Added!" << endl;
			}
			delete[] workerArrptr;
			workerArrptr = newArray;
			break;
		}
	}
	length += num;
	System::saveFile();
	cout << "add " << num << " workers." << endl;
	system("pause");
	system("cls");

}

void System::saveFile() {
	ofstream ofs;
	ofs.open("worker_list.txt", ios::out);
	
	for (int i = 0; i < length; i++)
	{
		ofs << workerArrptr[i]->m_id << " "
			<< workerArrptr[i]->m_name << "	"
			<< workerArrptr[i]->m_job << endl;
	}

	ofs.close();
}


void System::initArray() {
	ifstream ifs;
	ifs.open("worker_list.txt", ios::in);
	string id;
	string name;
	int job;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> job)
	{
		num++;
	}
	length = num;
	workerArrptr = new AbstractWorker * [length];
	for (int i = 0; i < length; i++)
	{
		ifs >> id >> name >> job;
		AbstractWorker* temp = NULL;
		switch (job) {
		case 1:
			temp = new Worker(id, name, 1);
			break;
		case 2:
			temp = new Manager(id, name, 2);
			break;
		case 3:
			temp = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		workerArrptr[i] = temp;
	}
	cout << "已有" << length << "名员工" << endl;
	ifs.close();
}

void System::displayWorker() {
	if (length == 0)
	{
		cout << "File does not exist." << endl;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			workerArrptr[i]->display();
		}
		system("pause");
		system("cls");
	}
}

void System::deleteWorker() {
	cout << "Enter the id or name of worker that you want to delete:" << endl;
	cout << "1.delete by id    2.delete by name" << endl;
	int select;
	cin >> select;
	string delId;
	string delName;
	if (select == 1)
	{
		cout << "Enter id: " << endl;
		cin >> delId;
		
		for (int i = 0; i < length; i++)
		{
			if (workerArrptr[i]->m_id == delId)
			{
				for (int j = i; j < length-1; j++)
				{
					workerArrptr[j] = workerArrptr[j + 1];
				}
			}
		}
		length--;
	}
	else
	{
		cout << "Enter name: " << endl;
		cin >> delName;

		for (int i = 0; i < length; i++)
		{
			if (workerArrptr[i]->m_name == delName)
			{
				for (int j = i; j < length - 1; j++)
				{
					workerArrptr[j] = workerArrptr[j + 1];
				}
			}
		}
		length--;
	}
	cout << "Delete succesful!" << endl;
	system("pause");
	system("cls");
	System::saveFile();
}

void System::modifyWorker() {
	cout << "Enter the id or name of worker that you want to modify:" << endl;
	cout << "1.modify by id    2.modify by name" << endl;
	int select;
	cin >> select;
	string modId;
	string modName;
	if (select == 1)
	{
		cout << "Enter id: " << endl;
		cin >> modId;
		for (int i = 1; i < length; i++)
		{
			if (workerArrptr[i]->m_id == modId)
			{
				cout << "Enter new work:" << endl;
				cout << "id:  name:  job:" << endl;
				string id;
				string name;
				int job;
				cin >> id >> name >> job;
				workerArrptr[i]->m_id = id;
				workerArrptr[i]->m_job = job;
				workerArrptr[i]->m_name = name;
			}
		}
	}
	else if (select == 2)
	{
		cout << "Enter name: " << endl;
		cin >> modName;
		for (int i = 1; i < length; i++)
		{
			if (workerArrptr[i]->m_name == modName)
			{
				cout << "Enter new work:" << endl;
				cout << "id:  name:  job:" << endl;
				string id;
				string name;
				int job;
				cin >> id >> name >> job;
				workerArrptr[i]->m_id = id;
				workerArrptr[i]->m_job = job;
				workerArrptr[i]->m_name = name;
			}
		}
	}
	else
	{
		cout << "Worker does not exist" << endl;
	}

	cout << "Modify succesful!" << endl;
	system("pause");
	system("cls");
	System::saveFile();

}

void System::searchWorker() {
	cout << "Enter id to search: " << endl;
	string id;
	cin >> id;
	for (int i = 0; i < length; i++)
	{
		if (workerArrptr[i]->m_id == id)
		{
			workerArrptr[i]->display();
		}
	}
	system("pause");
	system("cls");
}

void System::sortWorker() {
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (workerArrptr[j]->m_id > workerArrptr[j+1]->m_id)
			{
				AbstractWorker* temp = workerArrptr[j];
				workerArrptr[j] = workerArrptr[j + 1];
				workerArrptr[j + 1] = temp;
			}
		}
	}
	cout << "排序成功" << endl;
	system("pause");
	system("cls");
}

void System::clearSystem() {
	if (length==0)
	{
		cout << "File is empty." << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Are you sure you want to clear the file?" << endl;
	cout << "1. yes     2. no " << endl;
	int a;
	cin >> a;
	if (a == 1)
	{
		//删除文件内容
		ofstream ofs("worker_list.txt", ios::trunc);
		ofs.close();

		//删除三种员工对象
		for (int i = 0; i < length; i++)
		{
			if (workerArrptr[i] != NULL) 
			{
				delete workerArrptr[i];
				workerArrptr[i] = NULL;
			}
		}
		length = 0;
		delete[] workerArrptr;
		workerArrptr = NULL;
		cout << "Already cleared" << endl;
		system("pause");
		system("cls");
		
	}
	else
	{
		cout << "Canceled." << endl;
		system("pause");
		system("cls");
	}
}

