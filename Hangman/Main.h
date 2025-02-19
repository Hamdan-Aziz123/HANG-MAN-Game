#pragma once
#include <iostream>
#include <fstream>
#include"Variables.h"
#include<string>
namespace Hangman 
{	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Label^ Guessed;
	protected:
	private: array<Button^>^ Alphabets = gcnew array<Button^>(26);
	private: Label^ Title;
	private:PictureBox^ pictureBox1;
	private: Label^ type;
	private: Label^ Hangman;
	private: Label^ Mistakes;

		;
	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Guessed = (gcnew Label());
			this->Title = (gcnew Label());
			this->Hangman = (gcnew Label());
			this->type = (gcnew Label());
			this->Mistakes = (gcnew Label());
			this->pictureBox1 = (gcnew PictureBox());
			
			
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			for (int i = 0; i < 26; i++)
			{
				this->Alphabets[i] = (gcnew Button);
			}
			this->SuspendLayout();
			// 
			// Guessed
			// 

			this->type->Location = System::Drawing::Point(375, 91);
			this->type->Name = L"Guessed";
			this->type->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->type->AutoSize = true;
			this->type->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->type->Size = System::Drawing::Size(427, 123);
			this->type->TabIndex = 0;

			this->Guessed->Location = System::Drawing::Point(425, 191);
			this->Guessed->Name = L"Guessed";
			this->Guessed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Guessed->AutoSize = true;
			this->Guessed->TextAlign=System::Drawing::ContentAlignment::MiddleCenter;
			this->Guessed->Size = System::Drawing::Size(427, 123);
			this->Guessed->TabIndex = 0;

			this->Hangman->Location = System::Drawing::Point(37, 390);
			this->Hangman->Name = L"hangman";
			this->Hangman->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hangman->AutoSize = true;
			this->Hangman->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Hangman->Size = System::Drawing::Size(427, 123);
			this->Hangman->TabIndex = 0;

			this->pictureBox1->Location = System::Drawing::Point(10, 141);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"0")));
			this->pictureBox1->Size = System::Drawing::Size(300, 300);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			

		
			//this->Hint->Text = stoS(Hint);

			int x = 275, y = 350;
			for (int i = 0; i < 26; i++)
			{
				this->Alphabets[i]->BackColor = System::Drawing::SystemColors::ControlDark;
				this->Alphabets[i]->ForeColor = System::Drawing::Color::White;
				this->Alphabets[i]->Location = System::Drawing::Point(x, y);
				this->Alphabets[i]->Size = System::Drawing::Size(45, 45);
				this->Alphabets[i]->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Alphabets[i]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				this->Alphabets[i]->Name = stoS("Alphabet_" + std::to_string(i + 1));
				this->Alphabets[i]->Text = stoS(alphabets[i]);
				x = x + 46;
				if (i == 9 || i == 19) {
					y = y + 46;
					x = 275;
				}
			}
			// 
			// Title
			// 
			this->Title->Location = System::Drawing::Point(300, 25);
			this->Title->Name = L"Title";
			this->Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Size = System::Drawing::Size(625, 64);
			this->Title->TabIndex = 3;
			this->Title->Text = L"          HANGMAN";
			// 
			// Mistakes
			// 
			this->Mistakes->Location = System::Drawing::Point(372, 271);
			this->Mistakes->Name = L"Mistakes";
			this->Mistakes->AutoSize= true;
			this->Mistakes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mistakes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Mistakes->Size = System::Drawing::Size(100, 23);
			this->Mistakes->TabIndex = 4;
			
			
			// 
			// Main
			// 
			//this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);

			this->Alphabets[0]->Click += gcnew System::EventHandler(this, &Hangman::Main::A1);
			this->Alphabets[1]->Click += gcnew System::EventHandler(this, &Hangman::Main::A2);
			this->Alphabets[2]->Click += gcnew System::EventHandler(this, &Hangman::Main::A3);
			this->Alphabets[3]->Click += gcnew System::EventHandler(this, &Hangman::Main::A4);
			this->Alphabets[4]->Click += gcnew System::EventHandler(this, &Hangman::Main::A5);
			this->Alphabets[5]->Click += gcnew System::EventHandler(this, &Hangman::Main::A6);
			this->Alphabets[6]->Click += gcnew System::EventHandler(this, &Hangman::Main::A7);
			this->Alphabets[7]->Click += gcnew System::EventHandler(this, &Hangman::Main::A8);
			this->Alphabets[8]->Click += gcnew System::EventHandler(this, &Hangman::Main::A9);
			this->Alphabets[9]->Click += gcnew System::EventHandler(this, &Hangman::Main::A10);
			this->Alphabets[10]->Click += gcnew System::EventHandler(this, &Hangman::Main::A11);
			this->Alphabets[11]->Click += gcnew System::EventHandler(this, &Hangman::Main::A12);
			this->Alphabets[12]->Click += gcnew System::EventHandler(this, &Hangman::Main::A13);
			this->Alphabets[13]->Click += gcnew System::EventHandler(this, &Hangman::Main::A14);
			this->Alphabets[14]->Click += gcnew System::EventHandler(this, &Hangman::Main::A15);
			this->Alphabets[15]->Click += gcnew System::EventHandler(this, &Hangman::Main::A16);
			this->Alphabets[16]->Click += gcnew System::EventHandler(this, &Hangman::Main::A17);
			this->Alphabets[17]->Click += gcnew System::EventHandler(this, &Hangman::Main::A18);
			this->Alphabets[18]->Click += gcnew System::EventHandler(this, &Hangman::Main::A19);
			this->Alphabets[19]->Click += gcnew System::EventHandler(this, &Hangman::Main::A20);
			this->Alphabets[20]->Click += gcnew System::EventHandler(this, &Hangman::Main::A21);
			this->Alphabets[21]->Click += gcnew System::EventHandler(this, &Hangman::Main::A22);
			this->Alphabets[22]->Click += gcnew System::EventHandler(this, &Hangman::Main::A23);
			this->Alphabets[23]->Click += gcnew System::EventHandler(this, &Hangman::Main::A24);
			this->Alphabets[24]->Click += gcnew System::EventHandler(this, &Hangman::Main::A25);
			this->Alphabets[25]->Click += gcnew System::EventHandler(this, &Hangman::Main::A26);


			Engine();
			this->BackColor = System::Drawing::Color::FromArgb(255, System::Drawing::Color::LightGray);
			this->ClientSize = System::Drawing::Size(1029, 617);
			this->Controls->Add(this->Mistakes);
			this->Controls->AddRange(this->Alphabets);
			this->Controls->Add(this->Title);
			this->Controls->Add(this->Hangman);
			this->Controls->Add(this->type);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->Guessed);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void declare(void) //to reset counters
		{
			check = 0;
			std::srand(time(0));
			mistakes = 0;
			 entries[50];
			 j = 0;
			 choose_array = rand() % 3;
			 size = 0;
			 count = 0;
			 random = rand();
			d = 0;
			
			this->Hangman->Location = System::Drawing::Point(50, 410);
			this->Hangman->Text = L" ";
			
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->pictureBox1->Location = System::Drawing::Point(10, 141);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"0")));
			this->pictureBox1->Size = System::Drawing::Size(300, 300);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
		
		}
		
		void Engine(void)
		{
			
			if(d==0)
			{
				if (choose_array == 0)
			{
				random %= 12;
				int i = 0;
				for (; month[random][i] != '\0'; i++)
					unknown[i] = month[random][i];

				unknown[i] = '\0';

				type->Text=L"You have to guess a \"MONTH\".";
				
			}
			else if (choose_array == 1)
			{
				random %= 7;
				int i = 0;
				for (; day[random][i] != '\0'; i++)
					unknown[i] = day[random][i];
				unknown[i] = '\0';

				type->Text = "You have to guess a \"DAY\"";	
				
			}
			else 
			{
				random %= 10;
				int i = 0;
				for (; fruit[random][i] != '\0'; i++)
					unknown[i] = fruit[random][i];
				unknown[i] = '\0';

				type->Text = L"You have to guess a \"FRUIT\"";
				
			}
		
			for (int i = 0; unknown[i] != '\0'; i++)
			{
				size++;
			}
			for (; j < size; j++)
			{
				if (unknown[j] == ' ')
				{
					working[j] = ' ';
					continue;
				}
				working[j] = '-';
			}
			working[j] = '\0';
			j = 0;
				std::ifstream read;//File HAndling
				read.open("data.txt");
				read >> save;
				if (save == 1)
				{
					if (MessageBox::Show(L"Do You want to open your previous game?", L" ", MessageBoxButtons::YesNo)
						== System::Windows::Forms::DialogResult::Yes)
					{
						read >> working;
						read >> unknown;
						read >> mistakes;
						read.getline(wtype, 50, '\n');

					}
					
				}
				read.close();
				this->Guessed->Text = stoS(working);
			
		}
			
			else 
			{
				bool flag = false;
	
				count = 0;
				for (int i = 0; i < size; i++)
				{
					if (working[i] == '-')
					{
						if (guess == unknown[i])
						{
							working[i] = guess;
							count++;
						}
						else if (guess == unknown[i] - 32)
						{
							working[i] = guess + 32;
							count++;
						}
						else if (guess == unknown[i] + 32)
						{
							working[i] = guess - 32;
							count++;
						}
					}
				}
				if (count != 0)
				{
					flag = true;
					
					//Char mil gya
				}

				if (flag == false)
					for (int i = 0; i < j; i++)
					{
						if (guess == entries[i])
						{
							flag = true;
							MessageBox::Show(L"You have already made this mistake!");
							//repeated mistakes
						}
					}
				//no of mistakes
				if (flag == false)
				{
					if (mistakes == 0)
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"1")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
				
					}
					else if (mistakes == 1)
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"2")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
						
					}
					else if (mistakes == 2)
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"3")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
						
					}
					else if (mistakes == 3)
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"4")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
						
					}
					else if (mistakes == 4)
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"5")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
						
					}
					else if (mistakes == 5)
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"6")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
						
					}
					else  
					{
						System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
						(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
						this->pictureBox1->Location = System::Drawing::Point(10, 141);
						this->pictureBox1->Name = L"pictureBox1";
						this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"7")));
						this->pictureBox1->Size = System::Drawing::Size(300, 300);
						this->pictureBox1->TabIndex = 1;
						this->pictureBox1->TabStop = false;
						
					}
					mistakes++;
					MessageBox::Show(L"You have made a mistake!",L"Opps!!!");
					for (int i = 0; i < mistakes; i++)
					{
						this->Hangman->Location = System::Drawing::Point(50, 410);
						this->Hangman->Text = stoS((hangman[i]));
					
					}
					
					this->Mistakes->Text = stoS("Mistakes : " + std::to_string(mistakes));
				}

				entries[j] = guess;
				save = true;
				string temp;
				temp = Stos(type->Text);
				std::ofstream write;
				write.open("data.txt");
				write << save << "\n";
				write << working << "\n";
				write << unknown << "\n";
				write << mistakes << "\n";
				write << temp << "\n";
				write.close();

				this->Guessed->Text = stoS(working);
				if (mistakes == 7)
				{
					save = 0;
					std::ofstream writeit;
					writeit.open("data.txt");
					writeit << save;
					writeit.close();
					MessageBox::Show(L"You have Lost the Game", L"Opps!!!");
					MessageBox::Show(stoS(unknown),L"Answer");
					if (MessageBox::Show(L"Do you want to play again?", L"", MessageBoxButtons::YesNo)
						== System::Windows::Forms::DialogResult::Yes)
					{

						declare();
						Engine();
						this->Mistakes->Text = L" ";
					}
					else
					{
						Application::Exit();
					}
				}
				j++;
				check = check+count;
				if (check == size)
				{
					save = false;
					std::ofstream writeit;
					writeit.open("data.txt");
					writeit << 0;
					writeit.close();
					MessageBox::Show(L"You have WON the Game",L"Congratulations!!!");

					if (MessageBox::Show(L"Do you want to play again?", L" ", MessageBoxButtons::YesNo)
						== System::Windows::Forms::DialogResult::Yes)
					{
						this->Hangman->Location = System::Drawing::Point(50, 410);
						this->Hangman->Text = L" ";
						save = 0;
						declare();
						Engine();
						this->Mistakes->Text = L" ";
					}
					else
					{
						this->Close();
					}
				}
				
			}
			d++;
		}
#pragma endregion

	private: System::Void A1(System::Object^ sender, System::EventArgs^ e) {
		guess = 'A';
		Engine();
	}
	private: System::Void A2(System::Object^ sender, System::EventArgs^ e) {
		guess = 'B';
		Engine();
	}
	private: System::Void A3(System::Object^ sender, System::EventArgs^ e) {
		guess = 'C';
		Engine();
	}
	private: System::Void A4(System::Object^ sender, System::EventArgs^ e) {
		guess = 'D';
		Engine();
	}
	private: System::Void A5(System::Object^ sender, System::EventArgs^ e) {
		guess = 'E';
		Engine();
	}
	private: System::Void A6(System::Object^ sender, System::EventArgs^ e) {
		guess = 'F';
		Engine();
	}
	private: System::Void A7(System::Object^ sender, System::EventArgs^ e) {
		guess = 'G';
		Engine();
	}
	private: System::Void A8(System::Object^ sender, System::EventArgs^ e) {
		guess = 'H';
		Engine();
	}
	private: System::Void A9(System::Object^ sender, System::EventArgs^ e) {
		guess = 'I';
		Engine();
	}
	private: System::Void A10(System::Object^ sender, System::EventArgs^ e) {
		guess = 'J';
		Engine();
	}
	private: System::Void A11(System::Object^ sender, System::EventArgs^ e) {
		guess = 'K';
		Engine();
	}
	private: System::Void A12(System::Object^ sender, System::EventArgs^ e) {
		guess = 'L';
		Engine();
	}
	private: System::Void A13(System::Object^ sender, System::EventArgs^ e) {
		guess = 'M';
		Engine();
	}
	private: System::Void A14(System::Object^ sender, System::EventArgs^ e) {
		guess = 'N';
		Engine();
	}
	private: System::Void A15(System::Object^ sender, System::EventArgs^ e) {
		guess = 'O';
		Engine();
	}
	private: System::Void A16(System::Object^ sender, System::EventArgs^ e) {
		guess = 'P';
		Engine();
	}
	private: System::Void A17(System::Object^ sender, System::EventArgs^ e) {
		guess = 'Q';
		Engine();
	}
	private: System::Void A18(System::Object^ sender, System::EventArgs^ e) {
		guess = 'R';
		Engine();
	}
	private: System::Void A19(System::Object^ sender, System::EventArgs^ e) {
		guess = 'S';
		Engine();
	}
	private: System::Void A20(System::Object^ sender, System::EventArgs^ e) {
		guess = 'T';
		Engine();
	}
	private: System::Void A21(System::Object^ sender, System::EventArgs^ e) {
		guess = 'U';
		Engine();
	}
	private: System::Void A22(System::Object^ sender, System::EventArgs^ e) {
		guess = 'V';
		Engine();
	}
	private: System::Void A23(System::Object^ sender, System::EventArgs^ e) {
		guess = 'W';
		Engine();
	}
	private: System::Void A24(System::Object^ sender, System::EventArgs^ e) {
		guess = 'X';
		Engine();
	}
	private: System::Void A25(System::Object^ sender, System::EventArgs^ e) {
		guess = 'Y';
		Engine();
	}
	private: System::Void A26(System::Object^ sender, System::EventArgs^ e) {
		guess = 'Z';
		Engine();
	}
	

};
}
