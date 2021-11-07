#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std::string_literals;
using namespace std;
class Raspisanie {
public:
    int i = 0, j = 0;
    // Всё рассписание
    void Dop(string week)
    {
        string dat, vremya, pred, aud;
        fstream MF;
        MF.open(week);
        while (MF.good()) {
            getline(MF, dat, ','); 
            getline(MF, vremya, ',');
            getline(MF, pred, ',');
            getline(MF, aud, '\n');
            cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
        }
        MF.close();
    }
    int coutrasp() {
        string dat, vremya, pred, aud, svalka, day;
        fstream MF;
        string week[6] = { "Mon.txt", "Tue.txt", "Wed.txt", "Thu.txt", "Fri.txt", "Sat.txt" };
        cout << "Понедельник" << endl;
        Dop(week[0]);
        cout << "Вторник" << endl;
        Dop(week[1]);
        cout << "Среда" << endl;
        Dop(week[2]);
        cout << "Четверг" << endl;
        Dop(week[3]);
        cout << "Пятница" << endl;
        Dop(week[4]);
        cout << "Суббота" << endl;
        Dop(week[5]);
        return 0;
    }
    // Добавить запись
    int formrasp() {
        fstream MF;
        string dat, day, pred, aud, zap = ",", per = "\n", time;
        cout << "Укажите нужный Вам день, например 'Понедельник': ";
        cin >> day;
        if (day != "Понедельник" && day != "Вторник" && day != "Среда" && "Четверг" && day != "Пятница" && day != "Суббота")
            cout << "Некорректно введённые данные";
        else {
            cout << "Введите время начала пары: ";
            cin >> time;
            cout << "Введите название дисциплины: ";
            cin >> pred;
            cout << "Введите номер аудитории: ";
            cin >> aud;
            if (day == "Понедельник") MF.open("Mon.txt", std::ios::app);
            if (day == "Вторник") MF.open("Tue.txt", std::ios::app);
            if (day == "Среда") MF.open("Wed.txt", std::ios::app);
            if (day == "Четверг") MF.open("Thu.txt", std::ios::app);
            if (day == "Пятница") MF.open("Fri.txt", std::ios::app);
            if (day == "Суббота") MF.open("Sat.txt", std::ios::app);
            MF << per << day << zap << time << zap << pred << zap << aud;
            MF.close();
        }
        return 0;
    };
    //  Конкретный день
    int coutraspdate() {
        int n = 0;
        string dat, vremya, pred, aud, svalka, day;
        cout << "Укажите нужный Вам день, например 'Понедельник': ";
        cin >> day; 
        fstream MF;
        if (day != "Понедельник" && day != "Вторник" && day != "Среда" && "Четверг" && day != "Пятница" && day != "Суббота")
            cout << "Некорректно введённые данные";
        else {
            if (day == "Понедельник") MF.open("Mon.txt");
            if (day == "Вторник") MF.open("Tue.txt");
            if (day == "Среда") MF.open("Wed.txt");
            if (day == "Четверг") MF.open("Thu.txt");
            if (day == "Пятница") MF.open("Fri.txt");
            if (day == "Суббота") MF.open("Sat.txt");
            while (MF.good()) {
                getline(MF, dat, ',');
                if (dat == day) {
                    getline(MF, vremya, ',');
                    getline(MF, pred, ',');
                    getline(MF, aud, '\n');
                    cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
                    n++;
                }
                else getline(MF, svalka, '\n');
                if (n == 0) cout << "На указанный день нет расписания\n";
            }
        }
        return 0;
    }
    //Удалить запись
        int udal() {
            string day, dat, vremya, pred, aud, zap = ",", per = "\n";
            int i = 1, j = 0, nomer, chisl = 0;
            fstream MF;
            cout << "В рассписании какого дня вы хотите удалить запись? ";
            cin >> day;
            if (day != "Понедельник" && day != "Вторник" && day != "Среда" && "Четверг" && day != "Пятница" && day != "Суббота")
                cout << "Некорректно введённые данные";
            else {
            if (day == "Понедельник") MF.open("Mon.txt");
            if (day == "Вторник") MF.open("Tue.txt");
            if (day == "Среда") MF.open("Wed.txt");
            if (day == "Четверг") MF.open("Thu.txt");
            if (day == "Пятница") MF.open("Fri.txt");
            if (day == "Суббота") MF.open("Sat.txt");
            fstream COPY;
            COPY.open("copy.txt");
            while (MF.good()) {
                getline(MF, dat, ',');
                getline(MF, vremya, ',');
                getline(MF, pred, ',');
                getline(MF, aud, '\n');
                cout << i << ". " << dat << " " << vremya << ":00" << " " << pred << " " << aud << "\n";
                i++;
            }
            MF.close();
            if (day == "Понедельник") MF.open("Mon.txt");
            if (day == "Вторник") MF.open("Tue.txt");
            if (day == "Среда") MF.open("Wed.txt");
            if (day == "Четверг") MF.open("Thu.txt");
            if (day == "Пятница") MF.open("Fri.txt");
            if (day == "Суббота") MF.open("Sat.txt");
            cout << "Введите номер строки, которую надо удалить: ";
            cin >> nomer;
            i = 1;
            while (MF.good()) {
                getline(MF, dat, ',');
                getline(MF, vremya, ',');
                getline(MF, pred, ',');
                getline(MF, aud, '\n');
                if (nomer == i) {
                    cout << "\nСтрока номер " << i << ". " << dat << " " << vremya << ":00" << " " << pred << " " << aud << " Удалена";
                    chisl = 1;
                }
                else {
                    if (j == 0) {
                        COPY << dat << zap << vremya << zap << pred << zap << aud;
                        j++;
                    }
                    else {
                        COPY << per << dat << zap << vremya << zap << pred << zap << aud;
                    }
                }
                i++;
            }
            MF.close();
            COPY.close();
            if (chisl == 0) {
                cout << "Строки с таким номером нет\n";
            }
            else if (chisl == 1) {
                if (day == "Понедельник") {
                    rename("Mon.txt", "copy1.txt");
                    cout << "\n";
                    rename("copy.txt", "Mon.txt");
                }
                if (day == "Вторник") {
                    rename("Tue.txt", "copy1.txt");
                    cout << "\n";
                    rename("copy.txt", "Tue.txt");
                }
                if (day == "Среда") {
                    rename("Wed.txt", "copy1.txt");
                    cout << "\n";
                    rename("copy.txt", "Wed.txt");
                }
                if (day == "Четверг") {
                    rename("Thu.txt", "copy1.txt");
                    cout << "\n";
                    rename("copy.txt", "Thu.txt");
                }
                if (day == "Пятница") {
                    rename("Fri.txt", "copy1.txt");
                    cout << "\n";
                    rename("copy.txt", "Fri.txt");
                }
                if (day == "Суббота") {
                    rename("Sat.txt", "copy1.txt");
                    cout << "\n";
                    rename("copy.txt", "Sat.txt");
                }
                    cout << "\n";
                    rename("copy1.txt", "copy.txt");
                    remove("copy.txt");
                    ofstream oFile("copy.txt");
            }
            }
            return 0;
        }
        //создание единого файла
        int kon()
        {
            remove("Расписание.txt"); //осуществление перезаписи файла
            ofstream oFile("Расписание.txt");
            std::ifstream Mon("Mon.txt");
            std::ofstream Mon1("Расписание.txt", std::ios::app);
            Mon1 << Mon.rdbuf()<< endl;
            std::ifstream Tue("Tue.txt");
            std::ofstream Tue1("Расписание.txt", std::ios::app);
            Tue1 << Tue.rdbuf() << endl;
            std::ifstream Wed("Wed.txt");
            std::ofstream Wed1("Расписание.txt", std::ios::app);
            Wed1 << Wed.rdbuf() << endl;
            std::ifstream Thu("Thu.txt");
            std::ofstream Thu1("Расписание.txt", std::ios::app);
            Thu1 << Thu.rdbuf() << endl;
            std::ifstream Fri("Fri.txt");
            std::ofstream Fri1("Расписание.txt", std::ios::app);
            Fri1 << Fri.rdbuf() << endl;
            std::ifstream Sat("Sat.txt");
            std::ofstream Sat1("Расписание.txt", std::ios::app);
            Sat1 << Sat.rdbuf()<< endl;
            cout << "До свидания! Файл с расписанием составлен (Расписание.txt)"<<endl;
            return 0;
        }
};
    int main()
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, ".1251");
        Raspisanie raspisanie;
        int a = 0;
        cout << "Список команд:\n1 - посмотреть всё расписание"
            <<"\n2 - добавить запись\n3 - посмотреть расписание на конкретный день"
            <<"\n4 - удалить запись\n5 - завершить программу" << endl;
        while (a != 5)
        {
            cout << "\nКоманда:";
            cin >> a;
            switch (a)
            {
            case 1:
                raspisanie.coutrasp();
                break;

            case 2:
                raspisanie.formrasp();
                break;
            case 3:
                raspisanie.coutraspdate();
                break;
             case 4:
                raspisanie.udal();
                break;
            case 5:
                 raspisanie.kon();
                 break;
            default:
                cout << "Введено некорректное значение" << endl;
                break;
            }
        }
    }