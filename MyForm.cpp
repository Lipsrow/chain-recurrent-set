#include "MyForm.h"
#include <Windows.h>
#include "Graph.h"

double total_time = 0;
using namespace My3Цепнорекуррентноемножество;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

System::Void My3Цепнорекуррентноемножество::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	graph.clear();
	areas.clear();
	main::a = System::Convert::ToDouble(textBox_a->Text);
	main::b = System::Convert::ToDouble(textBox_b->Text);
	main::xmin = System::Convert::ToDouble(textBox_xmin->Text);
	main::xmax = System::Convert::ToDouble(textBox_xmax->Text);
	main::ymin = System::Convert::ToDouble(textBox_ymin->Text);
	main::ymax = System::Convert::ToDouble(textBox_ymax->Text);
	main::MAX_ITER = System::Convert::ToInt64(textBox_n->Text);
	clock_t start, end;
	start = clock();
	iterate(MAX_ITER);
	end = clock();
	total_time = double(end - start) / double(CLOCKS_PER_SEC);
	label_time->Text = "";
	auto time_str = "Время работы программы " + std::to_string(total_time) + " секунд";
	String^ str2 = gcnew String(time_str.c_str());
	this->label_time->Text += str2;

	label_amount->Text = "";
	auto amount2 = "Количество ячеек " + std::to_string(main::amount);
	String^ str_amount = gcnew String(amount2.c_str());
	this->label_amount->Text += str_amount;

	Graph^ secondform = gcnew Graph();
	secondform->draw();
	secondform->Show();
	return System::Void();
}

System::Void My3Цепнорекуррентноемножество::MyForm::button_more_Click(System::Object^ sender, System::EventArgs^ e)
{
	clock_t start, end;
	start = clock();
	flag = false;
	iterate_more(++MAX_ITER);
	end = clock();
	total_time = double(end - start) / double(CLOCKS_PER_SEC);
	label_time->Text = "";
	auto time_str = "Время работы программы " + std::to_string(total_time) + " секунд";
	String^ str2 = gcnew String(time_str.c_str());
	this->label_time->Text += str2;
	Graph^ secondform = gcnew Graph();
	label_amount->Text = "";
	auto amount2 = "Количество ячеек " + std::to_string(main::amount);
	String^ str_amount = gcnew String(amount2.c_str());
	this->label_amount->Text += str_amount;
	secondform->draw();
	secondform->Show();
	return System::Void();
}
