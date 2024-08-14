#pragma once

namespace My3÷епнорекуррентноемножество {
	bool flag = false;
	const int offsetx = 700;
	const int offsety = 400;
	const int scale = 200;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// —водка дл€ Graph
	/// </summary>
	public ref class Graph : public System::Windows::Forms::Form
	{
	public:
		Graph(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Graph()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(10, 14);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(1760, 976);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// Graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1770, 985);
			this->Controls->Add(this->pictureBox);
			this->Name = L"Graph";
			this->Text = L"Graph";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Graph::Graph_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
	public:
		void draw() {
			flag = true;
			pictureBox->Invalidate();
		}

#pragma endregion
	private: System::Void Graph_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (flag) {
			Graphics^ g = pictureBox->CreateGraphics();
			Pen^ pen = gcnew Pen(Color::White);
			SolidBrush^ brush = gcnew SolidBrush(Color::Purple);
			auto f = areas;
			for (Area a: areas) {
				float x = a.A.x * scale + offsetx;
				float y = -a.A.y * scale + offsety;
				float width = (a.B.x - a.A.x) * scale;
				float height = (a.A.y - a.B.y) * scale;
				g->FillRectangle(brush, x, y, width, height);
				//g->DrawRectangle(pen, x, y, width, height);
			}
			delete pen;
			delete brush;
		}
	}
	};
}
