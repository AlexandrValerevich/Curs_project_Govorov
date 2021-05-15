#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormSubjectList
	/// </summary>
	public ref class MyFormSubjectList : public System::Windows::Forms::Form
	{
	public:
		MyFormSubjectList(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormSubjectList(System::Windows::Forms::Form^ pForm)
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
		~MyFormSubjectList()
		{
			this->Owner->Show();

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::DataGridView^ dataGridViewSubject;
	protected:

	protected:

	protected:







	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxSubject;


	private: System::Windows::Forms::Button^ buttonChange;
	private: System::Windows::Forms::Button^ buttonDelete;


	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subject;






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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxSubject = (gcnew System::Windows::Forms::TextBox());
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Subject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSubject))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewSubject
			// 
			this->dataGridViewSubject->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewSubject->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSubject->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->id,
					this->Subject
			});
			this->dataGridViewSubject->Location = System::Drawing::Point(12, 77);
			this->dataGridViewSubject->Name = L"dataGridViewSubject";
			this->dataGridViewSubject->ReadOnly = true;
			this->dataGridViewSubject->Size = System::Drawing::Size(594, 391);
			this->dataGridViewSubject->TabIndex = 0;
			this->dataGridViewSubject->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyFormSubjectList::dataGridViewSubject_CellClick);
			this->dataGridViewSubject->SelectionChanged += gcnew System::EventHandler(this, &MyFormSubjectList::dataGridViewStudent_SelectionChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Предмет";
			// 
			// textBoxSubject
			// 
			this->textBoxSubject->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSubject->Location = System::Drawing::Point(113, 28);
			this->textBoxSubject->Name = L"textBoxSubject";
			this->textBoxSubject->Size = System::Drawing::Size(120, 23);
			this->textBoxSubject->TabIndex = 3;
			// 
			// buttonChange
			// 
			this->buttonChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonChange->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonChange->Location = System::Drawing::Point(378, 23);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(83, 29);
			this->buttonChange->TabIndex = 7;
			this->buttonChange->Text = L"Изменить";
			this->buttonChange->UseVisualStyleBackColor = true;
			this->buttonChange->Click += gcnew System::EventHandler(this, &MyFormSubjectList::buttonChange_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(489, 23);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(83, 29);
			this->buttonDelete->TabIndex = 6;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyFormSubjectList::buttonDelete_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(269, 23);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(83, 29);
			this->buttonAdd->TabIndex = 5;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyFormSubjectList::buttonAdd_Click);
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
			// MyFormSubjectList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 480);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->textBoxSubject);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridViewSubject);
			this->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximumSize = System::Drawing::Size(634, 519);
			this->MinimumSize = System::Drawing::Size(634, 519);
			this->Name = L"MyFormSubjectList";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Список предметов";
			this->Load += gcnew System::EventHandler(this, &MyFormSubjectList::MyFormSubjectList_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSubject))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyFormSubjectList_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridViewStudent_SelectionChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ClearTextBox();
	private: System::Void dataGridViewSubject_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	};
}
