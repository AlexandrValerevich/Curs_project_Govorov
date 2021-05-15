#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormGroup
	/// </summary>
	public ref class MyFormGroup : public System::Windows::Forms::Form
	{
	public:
		MyFormGroup(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormGroup(System::Windows::Forms::Form^ pForm)
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
		~MyFormGroup()
		{
			this->Owner->Show();

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::DataGridView^ dataGridViewGroup;
	protected:

	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxGroup;

	private: System::Windows::Forms::Button^ buttonChange;
	private: System::Windows::Forms::Button^ buttonDelete;

	private: System::Windows::Forms::Button^ buttonAdd;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownSpeciality;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Speciality;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;









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
			this->dataGridViewGroup = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxGroup = (gcnew System::Windows::Forms::TextBox());
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownSpeciality = (gcnew System::Windows::Forms::DomainUpDown());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Speciality = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewGroup))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewGroup
			// 
			this->dataGridViewGroup->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewGroup->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewGroup->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id,
					this->Speciality, this->Group
			});
			this->dataGridViewGroup->Location = System::Drawing::Point(12, 124);
			this->dataGridViewGroup->Name = L"dataGridViewGroup";
			this->dataGridViewGroup->ReadOnly = true;
			this->dataGridViewGroup->Size = System::Drawing::Size(594, 344);
			this->dataGridViewGroup->TabIndex = 0;
			this->dataGridViewGroup->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyFormGroup::dataGridViewGroup_CellClick);
			this->dataGridViewGroup->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyFormGroup::dataGridViewGroup_RowEnter);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Группа";
			// 
			// textBoxGroup
			// 
			this->textBoxGroup->Font = (gcnew System::Drawing::Font(L"Montserrat", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxGroup->Location = System::Drawing::Point(142, 67);
			this->textBoxGroup->Name = L"textBoxGroup";
			this->textBoxGroup->Size = System::Drawing::Size(120, 26);
			this->textBoxGroup->TabIndex = 3;
			// 
			// buttonChange
			// 
			this->buttonChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonChange->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonChange->Location = System::Drawing::Point(402, 62);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(83, 29);
			this->buttonChange->TabIndex = 7;
			this->buttonChange->Text = L"Изменить";
			this->buttonChange->UseVisualStyleBackColor = true;
			this->buttonChange->Click += gcnew System::EventHandler(this, &MyFormGroup::buttonChange_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(513, 62);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(83, 29);
			this->buttonDelete->TabIndex = 6;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyFormGroup::buttonDelete_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(293, 62);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(83, 29);
			this->buttonAdd->TabIndex = 5;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyFormGroup::buttonAdd_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 18);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Специальность";
			// 
			// domainUpDownSpeciality
			// 
			this->domainUpDownSpeciality->Items->Add(L"Все");
			this->domainUpDownSpeciality->Location = System::Drawing::Point(142, 23);
			this->domainUpDownSpeciality->Name = L"domainUpDownSpeciality";
			this->domainUpDownSpeciality->ReadOnly = true;
			this->domainUpDownSpeciality->Size = System::Drawing::Size(234, 23);
			this->domainUpDownSpeciality->Sorted = true;
			this->domainUpDownSpeciality->TabIndex = 9;
			this->domainUpDownSpeciality->Text = L"Все";
			this->domainUpDownSpeciality->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormGroup::domainUpDownSpeciality_SelectedItemChanged);
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// Speciality
			// 
			this->Speciality->HeaderText = L"Специальность";
			this->Speciality->Name = L"Speciality";
			this->Speciality->ReadOnly = true;
			// 
			// Group
			// 
			this->Group->HeaderText = L"Группа";
			this->Group->Name = L"Group";
			this->Group->ReadOnly = true;
			// 
			// MyFormGroup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 480);
			this->Controls->Add(this->domainUpDownSpeciality);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxGroup);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewGroup);
			this->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximumSize = System::Drawing::Size(634, 519);
			this->MinimumSize = System::Drawing::Size(634, 519);
			this->Name = L"MyFormGroup";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Группы";
			this->Load += gcnew System::EventHandler(this, &MyFormGroup::MyFormGroup_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewGroup))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyFormGroup_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownSpeciality_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridViewGroup_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void dataGridViewGroup_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void ClearTextBox();
};
}
