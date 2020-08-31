#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Logging_messages
{
private:

	static Logging_messages* instance;
	
	Logging_messages() {}
	Logging_messages(const Logging_messages&) = delete;
	Logging_messages& operator=(Logging_messages&) = delete;

public:

	static Logging_messages* GetInstance()
	{
		if (instance == nullptr)
			instance = new  Logging_messages();
		return instance;

	}

	void Write_to_file(string msg)
	{
		ofstream fout;

		fout.open("file.txt",ios::app);

		fout << msg << endl;

		fout.close();
	}

	void Reading_from_file()
	{
		string line;

		ifstream fin;

		fin.open("file.txt");

		while (getline(fin, line))
		{
			cout << line << endl;
		}
		fin.close();
	}


};


Logging_messages* Logging_messages::instance = nullptr;


int main()
{
	Logging_messages::GetInstance()->Reading_from_file();
	Logging_messages::GetInstance()->Write_to_file("vov");
	Logging_messages::GetInstance()->Reading_from_file();
	system("pause");
	return 0;
}