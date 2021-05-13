#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormInputMarks
	/// </summary>
	public ref class MyFormInputMarks : public System::Windows::Forms::Form
	{
	public:
		MyFormInputMarks(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormInputMarks(System::Drawing::Point p)
		{
			InitializeComponent();

			this->Location = p;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyFormInputMarks()
		{
			if (components)
			{
				delete components;
			}
		}












	protected:




	private: System::Windows::Forms::DataGridView^ dataGridViewStudent;


	private: System::Windows::Forms::TextBox^ textBoxId;

	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DomainUpDown^ domainUpDownGroup;





private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subject;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Mark;
private: System::Windows::Forms::DomainUpDown^ domainUpDownSubject;

private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::DomainUpDown^ domainUpDownStudent;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ textBoxMark;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ StudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ListStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ StudentGrantToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AvarageMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ListUnsucsessfulStudentToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ SubjectsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AddMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AvarageMarksSubjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ AvarageMarksGroupToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ CountUnsucsessfulMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ConfigurationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ FacultiesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ChairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SpecialityToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ GroupsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ SubjectToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ExitToolStripMenuItem;


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
			this->Subject = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Mark = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownGroup = (gcnew System::Windows::Forms::DomainUpDown());
			this->domainUpDownSubject = (gcnew System::Windows::Forms::DomainUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownStudent = (gcnew System::Windows::Forms::DomainUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxMark = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->ExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewStudent
			// 
			this->dataGridViewStudent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewStudent->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewStudent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id,
					this->Name_student, this->Surname_student, this->Group, this->Subject, this->Mark
			});
			this->dataGridViewStudent->Location = System::Drawing::Point(342, 36);
			this->dataGridViewStudent->Name = L"dataGridViewStudent";
			this->dataGridViewStudent->Size = System::Drawing::Size(558, 298);
			this->dataGridViewStudent->TabIndex = 1;
			this->dataGridViewStudent->Enter += gcnew System::EventHandler(this, &MyFormInputMarks::SelectDataGridItem);
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
			// 
			// Surname_student
			// 
			this->Surname_student->HeaderText = L"Фамилия";
			this->Surname_student->Name = L"Surname_student";
			// 
			// Group
			// 
			this->Group->HeaderText = L"Группа";
			this->Group->Name = L"Group";
			// 
			// Subject
			// 
			this->Subject->HeaderText = L"Предмет";
			this->Subject->Name = L"Subject";
			// 
			// Mark
			// 
			this->Mark->HeaderText = L"Оценка";
			this->Mark->Name = L"Mark";
			// 
			// textBoxId
			// 
			this->textBoxId->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxId->Location = System::Drawing::Point(142, 55);
			this->textBoxId->Name = L"textBoxId";
			this->textBoxId->ReadOnly = true;
			this->textBoxId->Size = System::Drawing::Size(140, 23);
			this->textBoxId->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(14, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 18);
			this->label1->TabIndex = 6;
			this->label1->Text = L"id";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(12, 106);
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
			this->domainUpDownGroup->Location = System::Drawing::Point(142, 104);
			this->domainUpDownGroup->Name = L"domainUpDownGroup";
			this->domainUpDownGroup->ReadOnly = true;
			this->domainUpDownGroup->Size = System::Drawing::Size(140, 23);
			this->domainUpDownGroup->Sorted = true;
			this->domainUpDownGroup->TabIndex = 18;
			this->domainUpDownGroup->Text = L"Все";
			// 
			// domainUpDownSubject
			// 
			this->domainUpDownSubject->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownSubject->Items->Add(L"Все");
			this->domainUpDownSubject->Location = System::Drawing::Point(142, 139);
			this->domainUpDownSubject->Name = L"domainUpDownSubject";
			this->domainUpDownSubject->ReadOnly = true;
			this->domainUpDownSubject->Size = System::Drawing::Size(140, 23);
			this->domainUpDownSubject->Sorted = true;
			this->domainUpDownSubject->TabIndex = 20;
			this->domainUpDownSubject->Text = L"Все";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 18);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Предмет";
			// 
			// domainUpDownStudent
			// 
			this->domainUpDownStudent->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownStudent->Items->Add(L"Все");
			this->domainUpDownStudent->Location = System::Drawing::Point(142, 173);
			this->domainUpDownStudent->Name = L"domainUpDownStudent";
			this->domainUpDownStudent->ReadOnly = true;
			this->domainUpDownStudent->Size = System::Drawing::Size(140, 23);
			this->domainUpDownStudent->Sorted = true;
			this->domainUpDownStudent->TabIndex = 22;
			this->domainUpDownStudent->Text = L"Все";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(14, 175);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 18);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Студент";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(14, 243);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 18);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Оценка";
			// 
			// textBoxMark
			// 
			this->textBoxMark->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxMark->Location = System::Drawing::Point(142, 239);
			this->textBoxMark->Name = L"textBoxMark";
			this->textBoxMark->Size = System::Drawing::Size(140, 23);
			this->textBoxMark->TabIndex = 23;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(560, 367);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 29);
			this->button3->TabIndex = 27;
			this->button3->Text = L"Изменить";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(746, 367);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 29);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(375, 367);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 29);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
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
			this->menuStrip1->TabIndex = 28;
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
			this->ListStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ListStudentToolStripMenuItem_Click);
			// 
			// StudentGrantToolStripMenuItem
			// 
			this->StudentGrantToolStripMenuItem->Name = L"StudentGrantToolStripMenuItem";
			this->StudentGrantToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->StudentGrantToolStripMenuItem->Text = L"Стипендия";
			this->StudentGrantToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::StudentGrantToolStripMenuItem_Click);
			// 
			// AvarageMarksToolStripMenuItem
			// 
			this->AvarageMarksToolStripMenuItem->Name = L"AvarageMarksToolStripMenuItem";
			this->AvarageMarksToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->AvarageMarksToolStripMenuItem->Text = L"Средине баллы";
			this->AvarageMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AvarageMarksToolStripMenuItem_Click);
			// 
			// ListUnsucsessfulStudentToolStripMenuItem1
			// 
			this->ListUnsucsessfulStudentToolStripMenuItem1->Name = L"ListUnsucsessfulStudentToolStripMenuItem1";
			this->ListUnsucsessfulStudentToolStripMenuItem1->Size = System::Drawing::Size(202, 22);
			this->ListUnsucsessfulStudentToolStripMenuItem1->Text = L"Список неуспевающих";
			this->ListUnsucsessfulStudentToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ListUnsucsessfulStudentToolStripMenuItem1_Click);
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
			this->AddMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AddMarksToolStripMenuItem_Click);
			// 
			// AvarageMarksSubjectToolStripMenuItem
			// 
			this->AvarageMarksSubjectToolStripMenuItem->Name = L"AvarageMarksSubjectToolStripMenuItem";
			this->AvarageMarksSubjectToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AvarageMarksSubjectToolStripMenuItem->Text = L"Средний балл по предмету";
			this->AvarageMarksSubjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AvarageMarksSubjectToolStripMenuItem_Click);
			// 
			// AvarageMarksGroupToolStripMenuItem
			// 
			this->AvarageMarksGroupToolStripMenuItem->Name = L"AvarageMarksGroupToolStripMenuItem";
			this->AvarageMarksGroupToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AvarageMarksGroupToolStripMenuItem->Text = L"Средний балл по группам";
			this->AvarageMarksGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AvarageMarksGroupToolStripMenuItem_Click);
			// 
			// CountUnsucsessfulMarksToolStripMenuItem
			// 
			this->CountUnsucsessfulMarksToolStripMenuItem->Name = L"CountUnsucsessfulMarksToolStripMenuItem";
			this->CountUnsucsessfulMarksToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->CountUnsucsessfulMarksToolStripMenuItem->Text = L"Количество неудовлетворительных оценок";
			this->CountUnsucsessfulMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::CountUnsucsessfulMarksToolStripMenuItem_Click);
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
			this->FacultiesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->FacultiesToolStripMenuItem->Text = L"Факультеты";
			this->FacultiesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::FacultiesToolStripMenuItem_Click);
			// 
			// ChairToolStripMenuItem
			// 
			this->ChairToolStripMenuItem->Name = L"ChairToolStripMenuItem";
			this->ChairToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->ChairToolStripMenuItem->Text = L"Кафедры";
			this->ChairToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ChairToolStripMenuItem_Click);
			// 
			// SpecialityToolStripMenuItem
			// 
			this->SpecialityToolStripMenuItem->Name = L"SpecialityToolStripMenuItem";
			this->SpecialityToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->SpecialityToolStripMenuItem->Text = L"Специальности";
			this->SpecialityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::SpecialityToolStripMenuItem_Click);
			// 
			// GroupsToolStripMenuItem
			// 
			this->GroupsToolStripMenuItem->Name = L"GroupsToolStripMenuItem";
			this->GroupsToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->GroupsToolStripMenuItem->Text = L"Группы";
			this->GroupsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::GroupsToolStripMenuItem_Click);
			// 
			// SubjectToolStripMenuItem
			// 
			this->SubjectToolStripMenuItem->Name = L"SubjectToolStripMenuItem";
			this->SubjectToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->SubjectToolStripMenuItem->Text = L"Предметы";
			this->SubjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::SubjectToolStripMenuItem_Click);
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->ExitToolStripMenuItem->Text = L"Выход";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ExitToolStripMenuItem_Click);
			// 
			// MyFormInputMarks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 448);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxMark);
			this->Controls->Add(this->domainUpDownStudent);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->domainUpDownSubject);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->domainUpDownGroup);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxId);
			this->Controls->Add(this->dataGridViewStudent);
			this->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MaximumSize = System::Drawing::Size(928, 487);
			this->MinimumSize = System::Drawing::Size(928, 487);
			this->Name = L"MyFormInputMarks";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"BelSUT";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyFormInputMarks::MyFormInputMarks_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyFormInputMarks::MyFormStudent_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyFormStudent_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SelectDataGridItem(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyFormInputMarks_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void SubjectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);


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
};
}
