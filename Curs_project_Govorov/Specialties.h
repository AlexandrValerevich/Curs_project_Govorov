#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormSpeciality
	/// </summary>
	public ref class MyFormSpeciality : public System::Windows::Forms::Form
	{
	public:
		MyFormSpeciality(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormSpeciality(System::Windows::Forms::Form^ pForm)
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
		~MyFormSpeciality()
		{
			this->Owner->Show();

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::DataGridView^ dataGridViewStudent;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxFaculties;
	private: System::Windows::Forms::Button^ buttonChange;
	private: System::Windows::Forms::Button^ buttonDelete;

	private: System::Windows::Forms::Button^ buttonAdd;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownChair;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_chair;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Specialties;






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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxFaculties = (gcnew System::Windows::Forms::TextBox());
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownChair = (gcnew System::Windows::Forms::DomainUpDown());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name_chair = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Specialties = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewStudent
			// 
			this->dataGridViewStudent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewStudent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id,
					this->Name_chair, this->Specialties
			});
			this->dataGridViewStudent->Location = System::Drawing::Point(12, 124);
			this->dataGridViewStudent->Name = L"dataGridViewStudent";
			this->dataGridViewStudent->ReadOnly = true;
			this->dataGridViewStudent->Size = System::Drawing::Size(594, 344);
			this->dataGridViewStudent->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Специальность";
			// 
			// textBoxFaculties
			// 
			this->textBoxFaculties->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxFaculties->Location = System::Drawing::Point(131, 67);
			this->textBoxFaculties->Name = L"textBoxFaculties";
			this->textBoxFaculties->Size = System::Drawing::Size(120, 26);
			this->textBoxFaculties->TabIndex = 3;
			// 
			// buttonChange
			// 
			this->buttonChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonChange->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonChange->Location = System::Drawing::Point(399, 62);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(83, 29);
			this->buttonChange->TabIndex = 7;
			this->buttonChange->Text = L"Изменить";
			this->buttonChange->UseVisualStyleBackColor = true;
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(510, 62);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(83, 29);
			this->buttonDelete->TabIndex = 6;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(290, 62);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(83, 29);
			this->buttonAdd->TabIndex = 5;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 18);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Кафедра";
			// 
			// domainUpDownChair
			// 
			this->domainUpDownChair->Location = System::Drawing::Point(131, 23);
			this->domainUpDownChair->Name = L"domainUpDownChair";
			this->domainUpDownChair->ReadOnly = true;
			this->domainUpDownChair->Size = System::Drawing::Size(120, 23);
			this->domainUpDownChair->Sorted = true;
			this->domainUpDownChair->TabIndex = 9;
			this->domainUpDownChair->Text = L"Все";
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// Name_chair
			// 
			this->Name_chair->HeaderText = L"Кафедра";
			this->Name_chair->Name = L"Name_chair";
			this->Name_chair->ReadOnly = true;
			// 
			// Specialties
			// 
			this->Specialties->HeaderText = L"Специальность";
			this->Specialties->Name = L"Specialties";
			this->Specialties->ReadOnly = true;
			// 
			// MyFormSpeciality
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 480);
			this->Controls->Add(this->domainUpDownChair);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxFaculties);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewStudent);
			this->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximumSize = System::Drawing::Size(634, 519);
			this->MinimumSize = System::Drawing::Size(634, 519);
			this->Name = L"MyFormSpeciality";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Факультеты";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
