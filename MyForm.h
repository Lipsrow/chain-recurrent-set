#pragma once
#include "main.h"
#include <string>
using namespace main;
namespace My3Цепнорекуррентноемножество {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label_time;
	private: System::Windows::Forms::Label^ label_f;
	private: System::Windows::Forms::Label^ label_a;
	private: System::Windows::Forms::Label^ label_b;
	private: System::Windows::Forms::Label^ label_area;
	private: System::Windows::Forms::Label^ label_min;
	private: System::Windows::Forms::Label^ label_max;
	private: System::Windows::Forms::Label^ label_x;
	private: System::Windows::Forms::Label^ label_y;
	private: System::Windows::Forms::TextBox^ textBox_xmin;
	private: System::Windows::Forms::TextBox^ textBox_xmax;
	private: System::Windows::Forms::TextBox^ textBox_ymin;
	private: System::Windows::Forms::TextBox^ textBox_ymax;
	private: System::Windows::Forms::TextBox^ textBox_a;
	private: System::Windows::Forms::TextBox^ textBox_b;
	private: System::Windows::Forms::Label^ label_n;
	private: System::Windows::Forms::TextBox^ textBox_n;
	private: System::Windows::Forms::Button^ button_more;
	private: System::Windows::Forms::Label^ label_amount;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label_time = (gcnew System::Windows::Forms::Label());
			this->label_f = (gcnew System::Windows::Forms::Label());
			this->label_a = (gcnew System::Windows::Forms::Label());
			this->label_b = (gcnew System::Windows::Forms::Label());
			this->label_area = (gcnew System::Windows::Forms::Label());
			this->label_min = (gcnew System::Windows::Forms::Label());
			this->label_max = (gcnew System::Windows::Forms::Label());
			this->label_x = (gcnew System::Windows::Forms::Label());
			this->label_y = (gcnew System::Windows::Forms::Label());
			this->textBox_xmin = (gcnew System::Windows::Forms::TextBox());
			this->textBox_xmax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ymin = (gcnew System::Windows::Forms::TextBox());
			this->textBox_ymax = (gcnew System::Windows::Forms::TextBox());
			this->textBox_a = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->label_n = (gcnew System::Windows::Forms::Label());
			this->textBox_n = (gcnew System::Windows::Forms::TextBox());
			this->button_more = (gcnew System::Windows::Forms::Button());
			this->label_amount = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(55, 256);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(357, 66);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label_time
			// 
			this->label_time->Location = System::Drawing::Point(50, 345);
			this->label_time->Name = L"label_time";
			this->label_time->Size = System::Drawing::Size(397, 48);
			this->label_time->TabIndex = 2;
			this->label_time->Text = L"Время работы программы: ";
			this->label_time->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_f
			// 
			this->label_f->AutoSize = true;
			this->label_f->Location = System::Drawing::Point(50, 31);
			this->label_f->Name = L"label_f";
			this->label_f->Size = System::Drawing::Size(362, 58);
			this->label_f->TabIndex = 3;
			this->label_f->Text = L"Введите параметры отображения\r\n(x, y) -> (x² - y² + a, 2xy + b)";
			this->label_f->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_a
			// 
			this->label_a->AutoSize = true;
			this->label_a->Location = System::Drawing::Point(50, 121);
			this->label_a->Name = L"label_a";
			this->label_a->Size = System::Drawing::Size(25, 29);
			this->label_a->TabIndex = 4;
			this->label_a->Text = L"a";
			// 
			// label_b
			// 
			this->label_b->AutoSize = true;
			this->label_b->Location = System::Drawing::Point(260, 121);
			this->label_b->Name = L"label_b";
			this->label_b->Size = System::Drawing::Size(26, 29);
			this->label_b->TabIndex = 5;
			this->label_b->Text = L"b";
			// 
			// label_area
			// 
			this->label_area->AutoSize = true;
			this->label_area->Location = System::Drawing::Point(553, 31);
			this->label_area->Name = L"label_area";
			this->label_area->Size = System::Drawing::Size(182, 29);
			this->label_area->TabIndex = 6;
			this->label_area->Text = L"Введите область";
			// 
			// label_min
			// 
			this->label_min->AutoSize = true;
			this->label_min->Location = System::Drawing::Point(529, 60);
			this->label_min->Name = L"label_min";
			this->label_min->Size = System::Drawing::Size(51, 29);
			this->label_min->TabIndex = 7;
			this->label_min->Text = L"min";
			// 
			// label_max
			// 
			this->label_max->AutoSize = true;
			this->label_max->Location = System::Drawing::Point(703, 60);
			this->label_max->Name = L"label_max";
			this->label_max->Size = System::Drawing::Size(54, 29);
			this->label_max->TabIndex = 8;
			this->label_max->Text = L"max";
			// 
			// label_x
			// 
			this->label_x->AutoSize = true;
			this->label_x->Location = System::Drawing::Point(454, 121);
			this->label_x->Name = L"label_x";
			this->label_x->Size = System::Drawing::Size(23, 29);
			this->label_x->TabIndex = 9;
			this->label_x->Text = L"x";
			// 
			// label_y
			// 
			this->label_y->AutoSize = true;
			this->label_y->Location = System::Drawing::Point(454, 193);
			this->label_y->Name = L"label_y";
			this->label_y->Size = System::Drawing::Size(24, 29);
			this->label_y->TabIndex = 10;
			this->label_y->Text = L"y";
			// 
			// textBox_xmin
			// 
			this->textBox_xmin->Location = System::Drawing::Point(512, 118);
			this->textBox_xmin->Name = L"textBox_xmin";
			this->textBox_xmin->Size = System::Drawing::Size(91, 36);
			this->textBox_xmin->TabIndex = 11;
			this->textBox_xmin->Text = L"-1,5";
			// 
			// textBox_xmax
			// 
			this->textBox_xmax->Location = System::Drawing::Point(694, 114);
			this->textBox_xmax->Name = L"textBox_xmax";
			this->textBox_xmax->Size = System::Drawing::Size(91, 36);
			this->textBox_xmax->TabIndex = 12;
			this->textBox_xmax->Text = L"1,5";
			// 
			// textBox_ymin
			// 
			this->textBox_ymin->Location = System::Drawing::Point(512, 190);
			this->textBox_ymin->Name = L"textBox_ymin";
			this->textBox_ymin->Size = System::Drawing::Size(91, 36);
			this->textBox_ymin->TabIndex = 13;
			this->textBox_ymin->Text = L"-1,5";
			// 
			// textBox_ymax
			// 
			this->textBox_ymax->Location = System::Drawing::Point(694, 190);
			this->textBox_ymax->Name = L"textBox_ymax";
			this->textBox_ymax->Size = System::Drawing::Size(91, 36);
			this->textBox_ymax->TabIndex = 14;
			this->textBox_ymax->Text = L"1,5";
			// 
			// textBox_a
			// 
			this->textBox_a->Location = System::Drawing::Point(101, 118);
			this->textBox_a->Name = L"textBox_a";
			this->textBox_a->Size = System::Drawing::Size(91, 36);
			this->textBox_a->TabIndex = 15;
			this->textBox_a->Text = L"0";
			// 
			// textBox_b
			// 
			this->textBox_b->Location = System::Drawing::Point(321, 118);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(91, 36);
			this->textBox_b->TabIndex = 16;
			this->textBox_b->Text = L"-0,8";
			// 
			// label_n
			// 
			this->label_n->Location = System::Drawing::Point(50, 173);
			this->label_n->Name = L"label_n";
			this->label_n->Size = System::Drawing::Size(223, 69);
			this->label_n->TabIndex = 17;
			this->label_n->Text = L"Введите количество итераций";
			this->label_n->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox_n
			// 
			this->textBox_n->Location = System::Drawing::Point(321, 190);
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size(91, 36);
			this->textBox_n->TabIndex = 18;
			this->textBox_n->Text = L"8";
			// 
			// button_more
			// 
			this->button_more->Location = System::Drawing::Point(459, 256);
			this->button_more->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_more->Name = L"button_more";
			this->button_more->Size = System::Drawing::Size(326, 66);
			this->button_more->TabIndex = 19;
			this->button_more->Text = L"Итерировать еще";
			this->button_more->UseVisualStyleBackColor = true;
			this->button_more->Click += gcnew System::EventHandler(this, &MyForm::button_more_Click);
			// 
			// label_amount
			// 
			this->label_amount->Location = System::Drawing::Point(454, 345);
			this->label_amount->Name = L"label_amount";
			this->label_amount->Size = System::Drawing::Size(331, 48);
			this->label_amount->TabIndex = 20;
			this->label_amount->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 413);
			this->Controls->Add(this->label_amount);
			this->Controls->Add(this->button_more);
			this->Controls->Add(this->textBox_n);
			this->Controls->Add(this->label_n);
			this->Controls->Add(this->textBox_b);
			this->Controls->Add(this->textBox_a);
			this->Controls->Add(this->textBox_ymax);
			this->Controls->Add(this->textBox_ymin);
			this->Controls->Add(this->textBox_xmax);
			this->Controls->Add(this->textBox_xmin);
			this->Controls->Add(this->label_y);
			this->Controls->Add(this->label_x);
			this->Controls->Add(this->label_max);
			this->Controls->Add(this->label_min);
			this->Controls->Add(this->label_area);
			this->Controls->Add(this->label_b);
			this->Controls->Add(this->label_a);
			this->Controls->Add(this->label_f);
			this->Controls->Add(this->label_time);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_more_Click(System::Object^ sender, System::EventArgs^ e);
};
}
