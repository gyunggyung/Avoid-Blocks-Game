#include "input_output.h"

void user_input_output(string  name, int point)
{
	ifstream logFile2("log.txt");			   //���� �б�
	ofstream  logFile("log.txt", ios::app);    //���� ����, ���� �߰�
	string Rname, stop;
	logFile << name << "   " << point << endl; //���Ͽ� �̸�, ����Ʈ ����
	cout << "gamers name and point \n\n";
	while(1)
	{	
		logFile2 >> Rname;					//���� �б�
		if (stop == Rname)					//�ߺ� ����
			break;
		cout <<setw(12) <<Rname << "   ";	//���� ���� ���
		logFile2 >> Rname;
		cout << Rname << endl;

		stop = Rname;
	}

	//����� ���� �� ������ �ݾ��ݴϴ�.
	logFile2.close();
	logFile.close();
	cout << "\n\n�ƹ�Ű�� �Է��ϼ���\n";
	cin.get();
}