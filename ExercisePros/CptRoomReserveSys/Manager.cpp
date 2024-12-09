#include "Manager.h"

Manager::Manager()
{}

Manager::Manager(string name, string pwd)
{
	// ��ʼ������Ա����
	this->userName = name;
	this->userPwd = pwd;

	// ��ʼ���û�����
	this->initVec();

	// ��ʼ��������Ϣ
	this->initCrVec();
}

void Manager::showMenu()	// չʾ�û������麯��
{
	// ��ӡϵͳ����
	cout << "\t\t    #################### ��ӭ" << this->userName << "��¼ ####################" << endl;
	cout << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      ********* |       ��ȷ�����Ĳ�����    | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       1�� �鿴�˺�        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |       2�� ����˺�        | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      3���鿴������Ϣ      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |      4�����ԤԼ��¼      | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |        0�� ��  ��         | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* |                           | **********" << endl;
	cout << "\t\t      ********* +---------------------------+ **********" << endl;
	cout << "\t\t      **************************************************" << endl;
	cout << "\t\t      **************************************************" << endl;

	cout << endl;
	cout << "###����������ѡ��" << endl;
}

// �鿴�˺�
void Manager::showAllUser()
{
	cout << "###ϵͳ��ѧ���˻����£�" << endl;

	// ������������ӡ�����û�����
	for (const auto& stu : this->stuVec) {
		cout << "\tѧ�ţ�" << stu.stuId << "  �û�����" << stu.userName << "  ���룺" << stu.userPwd << endl;
	}
	cout << endl;
	cout << "###ϵͳ�ڽ�ʦ�˻����£�" << endl;

	for (const auto& tea : this->teaVec) {
		cout << "\tְ���ţ�" << tea.teaId << "  �û�����" << tea.userName << "  ���룺" << tea.userPwd << endl;
	}
	cout << endl;
	cout << "###ϵͳ���˺�����" << endl;
	system("pause");
	system("cls");
	return;
}

// ����˺�
void Manager::addUser()
{
	// ��ʾ����˺�����
	cout << "###��ѡ������˺�����" << endl;
	cout << "### 1��ѧ���˺�" << endl;
	cout << "### 2����ʦ�˺�" << endl;
	cout << "### 0��ȡ��" << endl;
	
	int select = 0;		// ��¼ѡ��
	cin >> select;

	int id = 0;
	string name;
	string pwd;
	ofstream ofs;

	while (true) {
		if (select == 1) {
			// ��ѧ����Ϣ�ļ�
			ofs.open(STUDENT_FILE, ios::app);

			while (true) {
				// ���ѧ���˻�
				cout << "������ѧ�ţ�" << endl;
				cin >> id;

				// ���id�ظ�
				if (this->checkIdRepeat(id, 1)) {
					cerr << "!!!ѧ���ظ�������������" << endl;
					continue;
				}
				break;
			}
			
			break;
		}
		else if (select == 2) {
			// �򿪽�ʦ��Ϣ�ļ�
			ofs.open(TEACHER_FILE, ios::app);

			while (true) {
				// ���ѧ���˻�
				cout << "������ְ���ţ�" << endl;
				cin >> id;

				// ���id�ظ�
				if (this->checkIdRepeat(id, 2)) {
					cerr << "!!!ְ�����ظ�������������" << endl;
					continue;
				}
				break;
			}

			break;
		}
		else if (select == 0) {
			// ȡ��
			cout << "###ȡ������" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			// ��������
			cerr << "!!!������������������" << endl;
			system("pause");
			system("cls");
		}
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	// ���ļ���д����Ϣ
	ofs << id << " " << name << " " << pwd << endl;

	// ��ʾ�ɹ����ر��ļ��������¼�������
	cout << "###����û��ɹ�" << endl;
	ofs.close();

	this->initVec();
	system("pause");
	system("cls");

	return;
}

// �鿴������Ϣ
void Manager::showCptRoom() {
	cout << "###������Ϣ���£�" << endl;

	// ������������ӡ�����û�����
	for (const auto& cr : this->crVec) {
		cout << "\t�����ţ�" << cr.crId << "  ����������" << cr.crCapacity  << "  ����ԤԼ״̬��" << (cr.statusCode == 1 ? "ԤԼ��" : "����") << endl;
	}
	cout << endl;
	cout << "###������Ϣ����" << endl;
	system("pause");
	system("cls");
	return;
}

// �������ԤԼ��¼
void Manager::cleanOrder() {

	// ȷ���Ƿ����
	cout << "###��ȷ���Ƿ��������ԤԼ��¼" << endl;
	cout << "###1��ȷ�����" << endl;
	cout << "###2��ȡ������" << endl;

	int command = 0;	// ��¼����ѡ��
	cin >> command;

	if (command == 1) {
		// ��շ�ʽ��ԤԼ��¼�ļ�
		ofstream ofs;
		ofs.open(ORDER_FILE, ios::trunc);

		// �жϴ򿪲����Ƿ�ɹ�
		if (!ofs.is_open()) {
			cerr << "!!!���ʧ�ܣ������²���" << endl;
		}
		else {
			cout << "###��ճɹ�" << endl;

			// ���û�����Ϣ״̬
			for (auto& cr : this->crVec) {
				cr.statusCode = 0;
			}
			// ����д���ļ�
			ofstream crOfs;
			crOfs.open(COMPUTER_FILE, ios::trunc);

			for (const auto& cr : this->crVec) {
				crOfs << cr.crId << " " << cr.crCapacity << " " << cr.statusCode << endl;
			}

			crOfs.close();
		}

		ofs.close();

		system("pause");
		system("cls");
		return;
	}
	
	cout << "###����ȡ���ɹ�" << endl;
	system("pause");
	system("cls");
}

// ��ʼ������
void Manager::initVec()
{
	// ���û��ļ�
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	// �жϴ��Ƿ�ɹ�
	if (!ifs.is_open()) {
		cerr << "!!!�ļ���ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���ԭ����
	this->stuVec.clear();
	this->teaVec.clear();

	// ��ȡ�ļ�������ʼ��vec����
	int fId;
	string fName;
	string fPwd;

	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		//cout << fId << " " << fName << " " << fPwd << endl;
		// ���ʵ������
		this->stuVec.push_back(Student(fId, fName, fPwd));
	}

	cout << "��ǰѧ���û�����" << this->stuVec.size() << endl;// ����������

	ifs.close();

	// ��ʼ����ʦ����
	ifs.open(TEACHER_FILE, ios::in);
	// �жϴ��Ƿ�ɹ�
	if (!ifs.is_open()) {
		cerr << "!!!�ļ���ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
		// ���ʵ������
		this->teaVec.push_back(Teacher(fId, fName, fPwd));
	}
	cout << "��ǰ��ʦ�û�����" << this->teaVec.size() << endl;// ����������
}

// ��ʼ��������Ϣ
void Manager::initCrVec()
{
	// ���û��ļ�
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	// �жϴ��Ƿ�ɹ�
	if (!ifs.is_open()) {
		cerr << "!!!�ļ���ʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// ���ԭ����
	this->crVec.clear();

	// ���������Ϣ
	ComputerRoom cr;
	while (ifs >> cr.crId && ifs >> cr.crCapacity && ifs >> cr.statusCode) {
		this->crVec.push_back(cr);
	}

	ifs.close();
}

// ����Ƿ���id���ظ�
bool Manager::checkIdRepeat(int id, int type)
{
	if (type == 1) {
		// ���ѧ���ظ�
		// �����������鿴�Ƿ�id�ظ�
		for (const auto& stu : this->stuVec) {
			if (stu.stuId == id) {
				return true;
			}
		}
	}
	else {
		// ���ְ�����ظ�
		for (const auto& tea : this->teaVec) {
			if (tea.teaId == id) {
				return true;
			}
		}
	}

	return false;
}
