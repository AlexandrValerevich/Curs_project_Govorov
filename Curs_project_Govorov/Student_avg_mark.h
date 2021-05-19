#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormStudentAvgMark
	/// </summary>
	public ref class MyFormStudentAvgMark : public System::Windows::Forms::Form
	{
	public:
		MyFormStudentAvgMark(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormStudentAvgMark(System::Windows::Forms::Form^ pForm)
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
		~MyFormStudentAvgMark()
		{
			this->Owner->Show();

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::DataGridView^ dataGridViewStudent;
	protected:





	private: System::Windows::Forms::DomainUpDown^ domainUpDownGroup;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname_student;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Avg_mark;
	private: System::Windows::Forms::Label^ label1;

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
			this->dataGridViewStudent = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name_student = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname_student = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Avg_mark = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->domainUpDownGroup = (gcnew System::Windows::Forms::DomainUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewStudent
			// 
			this->dataGridViewStudent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewStudent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->id,
					this->Name_student, this->Surname_student, this->Group, this->Avg_mark
			});
			this->dataGridViewStudent->Location = System::Drawing::Point(12, 77);
			this->dataGridViewStudent->MaximumSize = System::Drawing::Size(594, 391);
			this->dataGridViewStudent->MinimumSize = System::Drawing::Size(594, 391);
			this->dataGridViewStudent->Name = L"dataGridViewStudent";
			this->dataGridViewStudent->ReadOnly = true;
			this->dataGridViewStudent->Size = System::Drawing::Size(594, 391);
			this->dataGridViewStudent->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// Name_student
			// 
			this->Name_student->HeaderText = L"Имя";
			this->Name_student->Name = L"Name_student";
			this->Name_student->ReadOnly = true;
			// 
			// Surname_student
			// 
			this->Surname_student->HeaderText = L"Фамилия";
			this->Surname_student->Name = L"Surname_student";
			this->Surname_student->ReadOnly = true;
			// 
			// Group
			// 
			this->Group->HeaderText = L"Группа";
			this->Group->Name = L"Group";
			this->Group->ReadOnly = true;
			// 
			// Avg_mark
			// 
			this->Avg_mark->HeaderText = L"Средний балл";
			this->Avg_mark->Name = L"Avg_mark";
			this->Avg_mark->ReadOnly = true;
			// 
			// domainUpDownGroup
			// 
			this->domainUpDownGroup->Items->Add(L"Все");
			this->domainUpDownGroup->Location = System::Drawing::Point(84, 26);
			this->domainUpDownGroup->Name = L"domainUpDownGroup";
			this->domainUpDownGroup->ReadOnly = true;
			this->domainUpDownGroup->Size = System::Drawing::Size(120, 23);
			this->domainUpDownGroup->Sorted = true;
			this->domainUpDownGroup->TabIndex = 1;
			this->domainUpDownGroup->Text = L"Все";
			this->domainUpDownGroup->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormStudentAvgMark::domainUpDownGroup_SelectedItemChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Группа";
			// 
			// MyFormStudentAvgMark
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 480);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->domainUpDownGroup);
			this->Controls->Add(this->dataGridViewStudent);
			this->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyFormStudentAvgMark";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Средний балл студентов";
			this->Load += gcnew System::EventHandler(this, &MyFormStudentAvgMark::MyFormStudentAvgMark_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyFormStudentAvgMark_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
};
}
