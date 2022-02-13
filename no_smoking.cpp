#include "./no_smoking_header.h"

using namespace std;

void new_smoke_info();
void help_programm();

class Quit_Smoking
{

private:
	string name;
	int smoke, day_smoke, months_smoke,year_smoke, h_smoke, m_smoke;

public:
	Quit_Smoking(string name,int smoke, int day_smoke, int months_smoke,int year_smoke, int h_smoke, int m_smoke)
	{
		this->name = name;
		this->smoke = smoke;
		this->day_smoke = day_smoke;
		this->months_smoke = months_smoke;
		this->year_smoke = year_smoke;
		this->h_smoke = h_smoke;
		this->m_smoke = m_smoke;
	}

	void print()
	{
		int s_smoke(0),sum(0),sigar(0);
		
		time_t var_date_start = time(NULL);
		time_t var_date_fin   = time(NULL);


		struct tm *timeinfo = localtime(&var_date_start);
		timeinfo->tm_year = year_smoke - 1900;
		timeinfo->tm_mon = months_smoke - 1;
		timeinfo->tm_mday = day_smoke;
		timeinfo->tm_hour = h_smoke;
		timeinfo->tm_min = m_smoke;
		timeinfo->tm_sec = 0;
		var_date_start = mktime(timeinfo);


		cout << " " << YELLOW << name << GREEN 
			<<  ", \n Вы бросили курить : \t" << CYAN
			<< ctime(&var_date_start); // дата и время

		cout << GREEN << " Сейчас : \t\t" << CYAN 
			<< ctime(&var_date_fin);

		sum = (var_date_fin - var_date_start );

		s_smoke = sum % 60;
		m_smoke = sum / 60 % 60;
		h_smoke = sum / 3600 % 24;
		day_smoke = sum / 86400; // 86400 кол-во секунд в одних сутках

		if (day_smoke == 0)
		sigar = (h_smoke * 60) / 72; //  выясняем сколько сигарет выкуренно к этой минуте
		else
		sigar = (day_smoke  * smoke) + ((h_smoke * 60) / 72);


		cout << GREEN << " БРАВО !!! " 
			<< "\n Невыкуренно: \t\t"  << CYAN 
			<< sigar << GREEN << " сигарет 🚭 \n" 
			<< RESET;

		cout << GREEN << " Без вредной привычки: \t" 
			<< CYAN << day_smoke << GREEN 
			<<" дн. " << CYAN << h_smoke << GREEN 
			<< " час. " << CYAN << m_smoke << GREEN 
			<< " мин. " << CYAN << s_smoke << GREEN 
			<< " сек. \n " << RESET <<  endl;

	}
};

int main(int argc, char *argv[])
{
	system("clear");

	for (int i(0); i < argc; i++)

	{
		string str = argv[i];
		if ((str == "-n") || (str == "--new"))
		{
			new_smoke_info();
		}
		
		else if ((str == "?") || (str == "--help"))
		{
			help_programm();
		}
	}

	Quit_Smoking Danil("Данил",20, 01, 01, 2021, 0, 0);
	Danil.print();

	Quit_Smoking Anna("Анна",20, 7, 10, 2021, 07, 17);
	Anna.print();

	return 0;
}

void new_smoke_info()
{
	system("clear");

	int smoke(0), day_smoke(0), months_smoke(0),year_smoke(0), h_smoke(0), m_smoke(0),s_smoke(0),sum(0),sigar(0);
		
	time_t var_date_start = time(NULL);
	time_t var_date_fin   = time(NULL);

	cout << " Введите кол-во сигарет в день: ";
	cin >> smoke;
	cout << " Когда вы бросили курить?  \n";
	cout << " День: ";
	cin >> day_smoke;
	cout << " Месяц: ";
	cin >> months_smoke;
	cout << " Год: ";
	cin >> year_smoke;
	cout << " Час: ";
	cin >> h_smoke;
	cout << " Минуты: ";
	cin >> m_smoke;
	system("clear");

	struct tm *timeinfo = localtime(&var_date_start);
	timeinfo->tm_year = year_smoke - 1900;
	timeinfo->tm_mon = months_smoke - 1;
	timeinfo->tm_mday = day_smoke;
	timeinfo->tm_hour = h_smoke;
	timeinfo->tm_min = m_smoke;
	timeinfo->tm_sec = 0;
	var_date_start = mktime(timeinfo);

	
	cout << " Вы бросили курить : \t" << ctime(&var_date_start) << endl; // дата и время
	cout << " Сейчас : \t\t" << ctime(&var_date_fin) << endl;
	sum = (var_date_fin - var_date_start );

	s_smoke = sum % 60;
	m_smoke = sum / 60 % 60;
	h_smoke = sum / 3600 % 24;
	day_smoke = sum / 86400; // 86400 кол-во секунд в одних сутках

	if (day_smoke == 0)
	sigar = (h_smoke * 60) / 72; //  выясняем сколько сигарет выкуренно к этой минуте
	else
	sigar = (day_smoke  * smoke) + ((h_smoke * 60) / 72);
	
	cout <<  "\n БРАВО !!! \n Невыкуренно: " << sigar << " сигарет 🚭 \n";
	cout << " Без вредной привычки уже: " << day_smoke << " дн. " << h_smoke << " час. " << m_smoke << " мин. " << s_smoke << " сек. \n " << endl;
	exit(0);
	
}

void help_programm()
{
 cout << " Для ввода новых значений для расчёта \n"
	 " нужно ввести в командной строке после программы -n или --new" << endl;
	exit(0);
}
