#pragma once
#include "EP_Dll.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <thread>
#include <mutex>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <fileapi.h>


namespace ExPr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{

	public:

		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			timer1->Start();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:
	

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(82, 233);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отобразить исходник";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(305, 238);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 39);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Отобразить изм. файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(23, 69);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(199, 151);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(45, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Исходный файл";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(263, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Преобразованный файл";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(119, 298);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(241, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Авор программы: Николаева О.С (группа 501)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(95, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Системное время:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(256, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"label5";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(259, 69);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(199, 151);
			this->textBox2->TabIndex = 9;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(484, 320);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Thread^ t1;
	private: Thread^ t2; // создание потоков
	   public: Mutex Join;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL));
		char letters[100];
		fstream file1; // создание объекта класса fstream 
		file1.open("1.txt"); // связывание объекта класса fstream с файлом, который будет 
		//использоваться для операций ввода-вывода
		for (int i = 0; i < 100; i++)
		{
			letters[i] = (rand() % ('я' - 'а' + 1)) + 'а'; //присваиваем букве рандомное значение из алфавита
			file1 << letters[i]; // добавляем букву в файл
		}
		file1.close(); //закрываем файл

		String^ file1Path = "1.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			String^ file = File::ReadAllText(file1Path, System::Text::Encoding::GetEncoding(1251)); //открываем файл
			textBox1->Text = file; //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
	public: void T1() { //функция для передачи 1-му потоку
		char letter[100];
		ifstream file1;
		file1.open("1.txt");
		int k = 0;
		for (int i = 0; i < 5; i++)
		{
			std::vector<char> v; //инициализация векторов
			for (int j = k; j < k + 10; j++)
			{
				file1 >> letter[j];
				v.push_back(letter[j]);
			}
			k += 10;
			sort(v.begin(), v.end()); // сортировка вектора по алфавиту
			writeTo(v); // записываем вектор во второй файл
		}
		file1.close();
	}
	public: void T2() { //функция для передачи 2-му потоку
		char letter[100];
		ifstream file1;
		file1.open("1.txt");
		int k = 50;
		for (int i = 0; i < 5; i++)
		{
			std::vector<char> v; //инициализация векторов
			for (int j = k; j < k + 10; j++)
			{
				file1 >> letter[j];
				v.push_back(letter[j]);
			}
			k += 10;
			sort(v.begin(), v.end()); // сортировка вектора по алфавиту
			writeTo(v); // записываем вектор во второй файл
		}
		file1.close();
	}

	public: bool b;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		remove("new.txt");
		t1 = gcnew Thread(gcnew ThreadStart(this, &MyForm1::T1)); //создаем поток, выполняющий функцию T1
		t2 = gcnew Thread(gcnew ThreadStart(this, &MyForm1::T2));
		t1->Start(); // начинаем поток
		t1->Join(); // функция для блокировки вызывающегося потока до тех пор, пока поток выполнения не завершится
		t2->Start();
		t2->Join();
		String^ file2Path = "new.txt";
		try
		{
			String^ file = File::ReadAllText(file2Path, System::Text::Encoding::GetEncoding(1251)); //открываем файл
			textBox2->Text = file; //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	DateTime dateTime = DateTime::Now;
	this->label5->Text = dateTime.ToString();
}
private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	struct tm* date;
	char Current_date[100];
	const time_t timer = time(NULL);
	date = localtime(&timer);
	strftime(Current_date, 100, "%d.%m.%Y %H:%M:%S", date);
	System::String^ strCLR = gcnew System::String(Current_date);
	textBox1->Text += strCLR;
	srand(time(0));
}
};
}
