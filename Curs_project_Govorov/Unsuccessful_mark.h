#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormUnsuccessfuAvgMark
	/// </summary>
	public ref class MyFormUnsuccessfuAvgMark : public System::Windows::Forms::Form
	{
	public:
		MyFormUnsuccessfuAvgMark(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormUnsuccessfuAvgMark(System::Windows::Forms::Form^ pForm)
		{
			InitializeComponent();
			this->Location = pForm->Location;
			this->Owner = pForm;

			this->Owner->Hide();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyFormUnsuccessfuAvgMark()
		{
			this->Owner->Show();

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::DataGridView^ dataGridViewSubject;
	protected:

	private: System::Windows::Forms::DomainUpDown^ domainUpDownSubject;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Avg_mark;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subject;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Unsuccessful_mark;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridViewSubject = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Subject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Unsuccessful_mark = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->domainUpDownSubject = (gcnew System::Windows::Forms::DomainUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSubject))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewSubject
			// 
			this->dataGridViewSubject->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewSubject->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSubject->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id,
					this->Subject, this->Unsuccessful_mark
			});
			this->dataGridViewSubject->Location = System::Drawing::Point(12, 77);
			this->dataGridViewSubject->MaximumSize = System::Drawing::Size(594, 391);
			this->dataGridViewSubject->MinimumSize = System::Drawing::Size(594, 391);
			this->dataGridViewSubject->Name = L"dataGridViewSubject";
			this->dataGridViewSubject->ReadOnly = true;
			this->dataGridViewSubject->Size = System::Drawing::Size(594, 391);
			this->dataGridViewSubject->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// Subject
			// 
			this->Subject->HeaderText = L"Предмет";
			this->Subject->Name = L"Subject";
			this->Subject->ReadOnly = true;
			// 
			// Unsuccessful_mark
			// 
			this->Unsuccessful_mark->HeaderText = L"Неудовлетворительных оценок";
			this->Unsuccessful_mark->Name = L"Unsuccessful_mark";
			this->Unsuccessful_mark->ReadOnly = true;
			// 
			// domainUpDownSubject
			// 
			this->domainUpDownSubject->Items->Add(L"Все");
			this->domainUpDownSubject->Location = System::Drawing::Point(86, 26);
			this->domainUpDownSubject->Name = L"domainUpDownSubject";
			this->domainUpDownSubject->ReadOnly = true;
			this->domainUpDownSubject->Size = System::Drawing::Size(120, 23);
			this->domainUpDownSubject->Sorted = true;
			this->domainUpDownSubject->TabIndex = 1;
			this->domainUpDownSubject->Text = L"Все";
			this->domainUpDownSubject->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormUnsuccessfuAvgMark::domainUpDownSubject_SelectedItemChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Предмет";
			// 
			// MyFormUnsuccessfuAvgMark
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 480);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->domainUpDownSubject);
			this->Controls->Add(this->dataGridViewSubject);
			this->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyFormUnsuccessfuAvgMark";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Количество неудовлетворительных оценок по предмету";
			this->Load += gcnew System::EventHandler(this, &MyFormUnsuccessfuAvgMark::MyFormUnsuccessfuAvgMark_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSubject))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyFormUnsuccessfuAvgMark_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownSubject_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
};
}
