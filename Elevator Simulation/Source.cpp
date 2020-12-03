
// Забележки
// а1 -> асансьор 1, а2 -> асансьор 2

// Ако а1 се намира на етаж по-нисък от а2, а а2 е качил пътник и трябва да го остави на етаж Х
// и в това време получим заявка от етаж Х за движение надолу, а1 ще тръгне към етаж Х,
// въпреки че е възможно а2 да пристигне първи и да качи пътника от етаж Х, а а1 да отчете празен ход
// Причина: по време на движението към етаж Х, ако а2 качи друг пътник и този пътник даде заявка за етаж
// по-висок от Х, а2 няма да качи пътника от етаж Х, а ще продължи към етажа на другия пътник.
// Подобна е логиката и при движение надолу

// Aко и двата асансьора се намират на 1ви етаж и са с големина 2 и получат 3 заявки "call UP 2 0" и 1 "call Down 2 0"
// в този ред, а1 ще вземе пъривте двама за нагоре, а а2 ще вземе човека за надолу, оставяйки 3тия натиснал UP да чака,
// въпреки че неговата заявка е подадена преди тази за надолу
// Причина: а1 тръгва за заявките за нагоре, но не знае кога ще бъде зает капацитета му, докато а2 получава следващ
// курс - "DOWN"

// Ако асансьор спре на етаж и не може да качи всички пътници там, ако другият е свободен, той ще тръгне на 
// следващата секунда

// Във входния файл числото за брой на заявките трябва да е броя на всички редове от файла без първия
// "UP", "DOWN" трябва да са написани с главни букви за да се избегнат неточности при изпълнението

#include <iostream>
#include <fstream>
#include <string>
#include "ElevatorSimulation.h"
using namespace std;
int main()
{
	string file_name;
	cout << "Enter file name..." << endl;
	cin >> file_name;

	bool extension = false;
	for (int i = 0; i <= file_name.size(); i++)
	{
		if (file_name[i] == '.')
		{
			if (file_name[i + 1] != 't' || file_name[i + 2] != 'x' || file_name[i + 3] != 't' || file_name[i + 4] != '\0')
			{
				cout << "Invalid file!" << endl;
				return -1;
			}
			extension = true;
			break;
		}
	}
	if (!extension)
		file_name += ".txt";

	ifstream fread(file_name);
	if (fread)
	{
		cout << "\nStart\n";
		ElevatorSimulation a(fread);
		a.Run();
	}
	else
	{
		cout << "Couldn't open or find the file!" << endl;
		return -1;
	}

	fread.close();

	return 0;
}
