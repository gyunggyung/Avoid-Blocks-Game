#include "input_output.h"

void user_input_output(string  name, int point)
{
	ifstream logFile2("log.txt");			   //파일 읽기
	ofstream  logFile("log.txt", ios::app);    //파일 쓰기, 내용 추가
	string Rname, stop;
	logFile << name << "   " << point << endl; //파일에 이름, 포인트 쓰기
	cout << "gamers name and point \n\n";
	while(1)
	{	
		logFile2 >> Rname;					//파일 읽기
		if (stop == Rname)					//중복 제거
			break;
		cout <<setw(12) <<Rname << "   ";	//읽은 내용 출력
		logFile2 >> Rname;
		cout << Rname << endl;

		stop = Rname;
	}

	//사용이 끝난 뒤 파일을 닫아줍니다.
	logFile2.close();
	logFile.close();
	cout << "\n\n아무키나 입력하세요\n";
	cin.get();
}