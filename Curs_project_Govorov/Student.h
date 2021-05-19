#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormStudent
	/// </summary>
	public ref class MyFormStudent : public System::Windows::Forms::Form
	{
	public:
		MyFormStudent(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormStudent(System::Drawing::Point p)
		{
			InitializeComponent();

			this->StartPosition = System::Windows::Forms::FormStartPosition();

			this->Location = p;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyFormStudent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ StudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ StudentGrantToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AvarageMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ListUnsucsessfulStudentToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ SubjectsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ AvarageMarksSubjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AvarageMarksGroupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ CountUnsucsessfulMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ConfigurationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ FacultiesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ExitToolStripMenuItem;
	protected:











	private: System::Windows::Forms::ToolStripMenuItem^ ChairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SpecialityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GroupsToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridViewStudent;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::Button^ buttonDelete;







	private: System::Windows::Forms::Button^ buttonChange;

	private: System::Windows::Forms::TextBox^ textBoxId;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxName;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxSurname;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxPatronymic;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownGroup;









	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBoxAddress;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxRecordBook;







	private: System::Windows::Forms::ToolStripMenuItem^ AddMarksToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ ListStudentToolStripMenuItem;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Patronymic_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Record_book;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Address;
private: System::Windows::Forms::ToolStripMenuItem^ SubjectToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ SubjectListToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^ SubjectByGroupToolStripMenuItem;
private: System::Windows::Forms::Button^ buttonUpdateGroupList;





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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->StudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ListStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StudentGrantToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AvarageMarksToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ListUnsucsessfulStudentToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SubjectsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddMarksToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AvarageMarksSubjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AvarageMarksGroupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CountUnsucsessfulMarksToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ConfigurationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FacultiesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ChairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SpecialityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GroupsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SubjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SubjectListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SubjectByGroupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridViewStudent = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name_student = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname_student = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Patronymic_student = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Record_book = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxSurname = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxPatronymic = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownGroup = (gcnew System::Windows::Forms::DomainUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxRecordBook = (gcnew System::Windows::Forms::TextBox());
			this->buttonUpdateGroupList = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->StudentToolStripMenuItem,
					this->SubjectsToolStripMenuItem, this->ConfigurationToolStripMenuItem, this->ExitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(912, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// StudentToolStripMenuItem
			// 
			this->StudentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ListStudentToolStripMenuItem,
					this->StudentGrantToolStripMenuItem, this->AvarageMarksToolStripMenuItem, this->ListUnsucsessfulStudentToolStripMenuItem1
			});
			this->StudentToolStripMenuItem->Name = L"StudentToolStripMenuItem";
			this->StudentToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->StudentToolStripMenuItem->Text = L"Студенты";
			// 
			// ListStudentToolStripMenuItem
			// 
			this->ListStudentToolStripMenuItem->Name = L"ListStudentToolStripMenuItem";
			this->ListStudentToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->ListStudentToolStripMenuItem->Text = L"Список студентов";
			this->ListStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::ListStudentToolStripMenuItem_Click);
			// 
			// StudentGrantToolStripMenuItem
			// 
			this->StudentGrantToolStripMenuItem->Name = L"StudentGrantToolStripMenuItem";
			this->StudentGrantToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->StudentGrantToolStripMenuItem->Text = L"Стипендия";
			this->StudentGrantToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::StudentGrantToolStripMenuItem_Click);
			// 
			// AvarageMarksToolStripMenuItem
			// 
			this->AvarageMarksToolStripMenuItem->Name = L"AvarageMarksToolStripMenuItem";
			this->AvarageMarksToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->AvarageMarksToolStripMenuItem->Text = L"Средине баллы";
			this->AvarageMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::AvarageMarksToolStripMenuItem_Click);
			// 
			// ListUnsucsessfulStudentToolStripMenuItem1
			// 
			this->ListUnsucsessfulStudentToolStripMenuItem1->Name = L"ListUnsucsessfulStudentToolStripMenuItem1";
			this->ListUnsucsessfulStudentToolStripMenuItem1->Size = System::Drawing::Size(202, 22);
			this->ListUnsucsessfulStudentToolStripMenuItem1->Text = L"Список неуспевающих";
			this->ListUnsucsessfulStudentToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyFormStudent::ListUnsucsessfulStudentToolStripMenuItem1_Click);
			// 
			// SubjectsToolStripMenuItem
			// 
			this->SubjectsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->AddMarksToolStripMenuItem,
					this->AvarageMarksSubjectToolStripMenuItem, this->AvarageMarksGroupToolStripMenuItem, this->CountUnsucsessfulMarksToolStripMenuItem
			});
			this->SubjectsToolStripMenuItem->Name = L"SubjectsToolStripMenuItem";
			this->SubjectsToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->SubjectsToolStripMenuItem->Text = L"Предметы";
			// 
			// AddMarksToolStripMenuItem
			// 
			this->AddMarksToolStripMenuItem->Name = L"AddMarksToolStripMenuItem";
			this->AddMarksToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AddMarksToolStripMenuItem->Text = L"Выставление оценок";
			this->AddMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::AddMarksToolStripMenuItem_Click);
			// 
			// AvarageMarksSubjectToolStripMenuItem
			// 
			this->AvarageMarksSubjectToolStripMenuItem->Name = L"AvarageMarksSubjectToolStripMenuItem";
			this->AvarageMarksSubjectToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AvarageMarksSubjectToolStripMenuItem->Text = L"Средний балл по предмету";
			this->AvarageMarksSubjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::AvarageMarksSubjectToolStripMenuItem_Click);
			// 
			// AvarageMarksGroupToolStripMenuItem
			// 
			this->AvarageMarksGroupToolStripMenuItem->Name = L"AvarageMarksGroupToolStripMenuItem";
			this->AvarageMarksGroupToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AvarageMarksGroupToolStripMenuItem->Text = L"Средний балл по группам";
			this->AvarageMarksGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::AvarageMarksGroupToolStripMenuItem_Click);
			// 
			// CountUnsucsessfulMarksToolStripMenuItem
			// 
			this->CountUnsucsessfulMarksToolStripMenuItem->Name = L"CountUnsucsessfulMarksToolStripMenuItem";
			this->CountUnsucsessfulMarksToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->CountUnsucsessfulMarksToolStripMenuItem->Text = L"Количество неудовлетворительных оценок";
			this->CountUnsucsessfulMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::CountUnsucsessfulMarksToolStripMenuItem_Click);
			// 
			// ConfigurationToolStripMenuItem
			// 
			this->ConfigurationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->FacultiesToolStripMenuItem,
					this->ChairToolStripMenuItem, this->SpecialityToolStripMenuItem, this->GroupsToolStripMenuItem, this->SubjectToolStripMenuItem
			});
			this->ConfigurationToolStripMenuItem->Name = L"ConfigurationToolStripMenuItem";
			this->ConfigurationToolStripMenuItem->Size = System::Drawing::Size(100, 20);
			this->ConfigurationToolStripMenuItem->Text = L"Конфигурация";
			// 
			// FacultiesToolStripMenuItem
			// 
			this->FacultiesToolStripMenuItem->Name = L"FacultiesToolStripMenuItem";
			this->FacultiesToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->FacultiesToolStripMenuItem->Text = L"Факультеты";
			this->FacultiesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::FacultiesToolStripMenuItem_Click);
			// 
			// ChairToolStripMenuItem
			// 
			this->ChairToolStripMenuItem->Name = L"ChairToolStripMenuItem";
			this->ChairToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->ChairToolStripMenuItem->Text = L"Кафедры";
			this->ChairToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::ChairToolStripMenuItem_Click);
			// 
			// SpecialityToolStripMenuItem
			// 
			this->SpecialityToolStripMenuItem->Name = L"SpecialityToolStripMenuItem";
			this->SpecialityToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->SpecialityToolStripMenuItem->Text = L"Специальности";
			this->SpecialityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::SpecialityToolStripMenuItem_Click);
			// 
			// GroupsToolStripMenuItem
			// 
			this->GroupsToolStripMenuItem->Name = L"GroupsToolStripMenuItem";
			this->GroupsToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->GroupsToolStripMenuItem->Text = L"Группы";
			this->GroupsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::GroupsToolStripMenuItem_Click);
			// 
			// SubjectToolStripMenuItem
			// 
			this->SubjectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->SubjectListToolStripMenuItem,
					this->SubjectByGroupToolStripMenuItem
			});
			this->SubjectToolStripMenuItem->Name = L"SubjectToolStripMenuItem";
			this->SubjectToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->SubjectToolStripMenuItem->Text = L"Предметы";
			// 
			// SubjectListToolStripMenuItem
			// 
			this->SubjectListToolStripMenuItem->Name = L"SubjectListToolStripMenuItem";
			this->SubjectListToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->SubjectListToolStripMenuItem->Text = L"Список предметов";
			this->SubjectListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::SubjectListToolStripMenuItem_Click);
			// 
			// SubjectByGroupToolStripMenuItem
			// 
			this->SubjectByGroupToolStripMenuItem->Name = L"SubjectByGroupToolStripMenuItem";
			this->SubjectByGroupToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->SubjectByGroupToolStripMenuItem->Text = L"Предметы по группам";
			this->SubjectByGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::SubjectByGroupToolStripMenuItem_Click);
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->ExitToolStripMenuItem->Text = L"Выход";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormStudent::ExitToolStripMenuItem_Click);
			// 
			// dataGridViewStudent
			// 
			this->dataGridViewStudent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewStudent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id,
					this->Name_student, this->Surname_student, this->Patronymic_student, this->Group, this->Record_book, this->Address
			});
			this->dataGridViewStudent->Location = System::Drawing::Point(342, 36);
			this->dataGridViewStudent->Name = L"dataGridViewStudent";
			this->dataGridViewStudent->Size = System::Drawing::Size(558, 298);
			this->dataGridViewStudent->TabIndex = 1;
			this->dataGridViewStudent->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyFormStudent::dataGridViewStudent_RowEnter);
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->Visible = false;
			// 
			// Name_student
			// 
			this->Name_student->HeaderText = L"Имя";
			this->Name_student->Name = L"Name_student";
			this->Name_student->Width = 86;
			// 
			// Surname_student
			// 
			this->Surname_student->HeaderText = L"Фамилия";
			this->Surname_student->Name = L"Surname_student";
			this->Surname_student->Width = 86;
			// 
			// Patronymic_student
			// 
			this->Patronymic_student->HeaderText = L"Отчество";
			this->Patronymic_student->Name = L"Patronymic_student";
			this->Patronymic_student->Width = 86;
			// 
			// Group
			// 
			this->Group->HeaderText = L"Группа";
			this->Group->Name = L"Group";
			this->Group->Width = 85;
			// 
			// Record_book
			// 
			this->Record_book->HeaderText = L"Зачетная книжка";
			this->Record_book->Name = L"Record_book";
			this->Record_book->Width = 86;
			// 
			// Address
			// 
			this->Address->HeaderText = L"Адрес";
			this->Address->Name = L"Address";
			this->Address->Width = 86;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(375, 371);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(115, 29);
			this->buttonAdd->TabIndex = 2;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyFormStudent::buttonAdd_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(746, 371);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(115, 29);
			this->buttonDelete->TabIndex = 3;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyFormStudent::buttonDelete_Click);
			// 
			// buttonChange
			// 
			this->buttonChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonChange->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonChange->Location = System::Drawing::Point(560, 371);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(115, 29);
			this->buttonChange->TabIndex = 4;
			this->buttonChange->Text = L"Изменить";
			this->buttonChange->UseVisualStyleBackColor = true;
			this->buttonChange->Click += gcnew System::EventHandler(this, &MyFormStudent::buttonChange_Click);
			// 
			// textBoxId
			// 
			this->textBoxId->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxId->Location = System::Drawing::Point(168, 48);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->ReadOnly = true;
			this->textBoxId->Size = System::Drawing::Size(121, 23);
			this->textBoxId->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 18);
			this->label1->TabIndex = 6;
			this->label1->Text = L"id";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 18);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Имя";
			// 
			// textBoxName
			// 
			this->textBoxName->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxName->Location = System::Drawing::Point(168, 98);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(121, 23);
			this->textBoxName->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 18);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Фамилия";
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSurname->Location = System::Drawing::Point(168, 127);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(121, 23);
			this->textBoxSurname->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 18);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Отчество";
			// 
			// textBoxPatronymic
			// 
			this->textBoxPatronymic->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPatronymic->Location = System::Drawing::Point(168, 156);
			this->textBoxPatronymic->Name = L"textBoxPatronymic";
			this->textBoxPatronymic->Size = System::Drawing::Size(121, 23);
			this->textBoxPatronymic->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(15, 286);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 18);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Группа";
			// 
			// domainUpDownGroup
			// 
			this->domainUpDownGroup->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownGroup->Items->Add(L"Все");
			this->domainUpDownGroup->Location = System::Drawing::Point(168, 284);
			this->domainUpDownGroup->Name = L"domainUpDownGroup";
			this->domainUpDownGroup->ReadOnly = true;
			this->domainUpDownGroup->Size = System::Drawing::Size(120, 23);
			this->domainUpDownGroup->Sorted = true;
			this->domainUpDownGroup->TabIndex = 18;
			this->domainUpDownGroup->Text = L"Все";
			this->domainUpDownGroup->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormStudent::domainUpDownGroup_SelectedItemChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(14, 240);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 18);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Адрес";
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxAddress->Location = System::Drawing::Point(168, 233);
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(121, 23);
			this->textBoxAddress->TabIndex = 21;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 207);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 18);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Зачетная книжка";
			// 
			// textBoxRecordBook
			// 
			this->textBoxRecordBook->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxRecordBook->Location = System::Drawing::Point(168, 204);
			this->textBoxRecordBook->Name = L"textBoxRecordBook";
			this->textBoxRecordBook->Size = System::Drawing::Size(121, 23);
			this->textBoxRecordBook->TabIndex = 19;
			// 
			// buttonUpdateGroupList
			// 
			this->buttonUpdateGroupList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonUpdateGroupList->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonUpdateGroupList->Location = System::Drawing::Point(70, 334);
			this->buttonUpdateGroupList->Name = L"buttonUpdateGroupList";
			this->buttonUpdateGroupList->Size = System::Drawing::Size(168, 29);
			this->buttonUpdateGroupList->TabIndex = 23;
			this->buttonUpdateGroupList->Text = L"Обновить список групп";
			this->buttonUpdateGroupList->UseVisualStyleBackColor = true;
			this->buttonUpdateGroupList->Click += gcnew System::EventHandler(this, &MyFormStudent::buttonUpdateGroupList_Click);
			// 
			// MyFormStudent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 448);
			this->Controls->Add(this->buttonUpdateGroupList);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxAddress);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBoxRecordBook);
			this->Controls->Add(this->domainUpDownGroup);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxPatronymic);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxSurname);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->dataGridViewStudent);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(928, 487);
			this->MinimumSize = System::Drawing::Size(928, 487);
			this->Name = L"MyFormStudent";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BelSUT";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyFormStudent::MyFormStudent_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyFormStudent::MyFormStudent_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ListStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void StudentGrantToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AvarageMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ListUnsucsessfulStudentToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AddMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AvarageMarksSubjectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AvarageMarksGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CountUnsucsessfulMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FacultiesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ChairToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SpecialityToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GroupsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyFormStudent_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyFormStudent_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void SubjectByGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SubjectListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridViewStudent_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void ClearTextBox();
private: System::Void domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonUpdateGroupList_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridViewStudent_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
