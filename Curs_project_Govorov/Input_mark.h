#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyFormInputMarks
	/// </summary>
	public ref class MyFormInputMarks : public System::Windows::Forms::Form
	{
	public:
		MyFormInputMarks(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

		MyFormInputMarks(System::Drawing::Point p)
		{
			InitializeComponent();

			this->Location = p;
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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











private: System::Windows::Forms::DomainUpDown^ domainUpDownSubject;

private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::DomainUpDown^ domainUpDownStudent;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TextBox^ textBoxMark;
	private: System::Windows::Forms::Button^ buttonChange;
	private: System::Windows::Forms::Button^ buttonDelete;


	private: System::Windows::Forms::Button^ buttonAdd;

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
	private: System::Windows::Forms::ToolStripMenuItem^ SubjectListToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ SubjectByGroupToolStripMenuItem;
private: System::Windows::Forms::DomainUpDown^ domainUpDownRecording;

private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::DomainUpDown^ domainUpDownSeasson;

private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname_student;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Subject;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Mark;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Recording;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Seasson;



	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->Recording = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Seasson = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->buttonChange = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
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
			this->domainUpDownRecording = (gcnew System::Windows::Forms::DomainUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->domainUpDownSeasson = (gcnew System::Windows::Forms::DomainUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewStudent))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewStudent
			// 
			this->dataGridViewStudent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewStudent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewStudent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->id,
					this->Name_student, this->Surname_student, this->Group, this->Subject, this->Mark, this->Recording, this->Seasson
			});
			this->dataGridViewStudent->Location = System::Drawing::Point(342, 36);
			this->dataGridViewStudent->Name = L"dataGridViewStudent";
			this->dataGridViewStudent->Size = System::Drawing::Size(558, 298);
			this->dataGridViewStudent->TabIndex = 1;
			this->dataGridViewStudent->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyFormInputMarks::dataGridViewStudent_RowEnter);
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->Visible = false;
			// 
			// Name_student
			// 
			this->Name_student->HeaderText = L"���";
			this->Name_student->Name = L"Name_student";
			this->Name_student->Width = 74;
			// 
			// Surname_student
			// 
			this->Surname_student->HeaderText = L"�������";
			this->Surname_student->Name = L"Surname_student";
			this->Surname_student->Width = 73;
			// 
			// Group
			// 
			this->Group->HeaderText = L"������";
			this->Group->Name = L"Group";
			this->Group->Width = 74;
			// 
			// Subject
			// 
			this->Subject->HeaderText = L"�������";
			this->Subject->Name = L"Subject";
			this->Subject->Width = 73;
			// 
			// Mark
			// 
			this->Mark->HeaderText = L"������";
			this->Mark->Name = L"Mark";
			this->Mark->Width = 74;
			// 
			// Recording
			// 
			this->Recording->HeaderText = L"����������";
			this->Recording->Name = L"Recording";
			this->Recording->Width = 73;
			// 
			// Seasson
			// 
			this->Seasson->HeaderText = L"�����";
			this->Seasson->Name = L"Seasson";
			this->Seasson->Width = 74;
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
			this->label6->Text = L"������";
			// 
			// domainUpDownGroup
			// 
			this->domainUpDownGroup->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownGroup->Items->Add(L"���");
			this->domainUpDownGroup->Location = System::Drawing::Point(142, 104);
			this->domainUpDownGroup->Name = L"domainUpDownGroup";
			this->domainUpDownGroup->ReadOnly = true;
			this->domainUpDownGroup->Size = System::Drawing::Size(140, 23);
			this->domainUpDownGroup->TabIndex = 18;
			this->domainUpDownGroup->Text = L"���";
			this->domainUpDownGroup->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormInputMarks::domainUpDownGroup_SelectedItemChanged);
			// 
			// domainUpDownSubject
			// 
			this->domainUpDownSubject->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownSubject->Items->Add(L"���");
			this->domainUpDownSubject->Location = System::Drawing::Point(142, 139);
			this->domainUpDownSubject->Name = L"domainUpDownSubject";
			this->domainUpDownSubject->ReadOnly = true;
			this->domainUpDownSubject->Size = System::Drawing::Size(140, 23);
			this->domainUpDownSubject->TabIndex = 20;
			this->domainUpDownSubject->Text = L"���";
			this->domainUpDownSubject->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormInputMarks::domainUpDownSubject_SelectedItemChanged);
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
			this->label4->Text = L"�������";
			// 
			// domainUpDownStudent
			// 
			this->domainUpDownStudent->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownStudent->Items->Add(L"���");
			this->domainUpDownStudent->Location = System::Drawing::Point(142, 173);
			this->domainUpDownStudent->Name = L"domainUpDownStudent";
			this->domainUpDownStudent->ReadOnly = true;
			this->domainUpDownStudent->Size = System::Drawing::Size(140, 23);
			this->domainUpDownStudent->TabIndex = 22;
			this->domainUpDownStudent->Text = L"���";
			this->domainUpDownStudent->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormInputMarks::domainUpDownStudent_SelectedItemChanged);
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
			this->label2->Text = L"�������";
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
			this->label3->Text = L"������";
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
			// buttonChange
			// 
			this->buttonChange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonChange->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonChange->Location = System::Drawing::Point(560, 367);
			this->buttonChange->Name = L"buttonChange";
			this->buttonChange->Size = System::Drawing::Size(115, 29);
			this->buttonChange->TabIndex = 27;
			this->buttonChange->Text = L"��������";
			this->buttonChange->UseVisualStyleBackColor = true;
			this->buttonChange->Click += gcnew System::EventHandler(this, &MyFormInputMarks::buttonChange_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(746, 367);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(115, 29);
			this->buttonDelete->TabIndex = 26;
			this->buttonDelete->Text = L"�������";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyFormInputMarks::buttonDelete_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Roboto", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(375, 367);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(115, 29);
			this->buttonAdd->TabIndex = 25;
			this->buttonAdd->Text = L"��������";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyFormInputMarks::buttonAdd_Click);
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
			this->StudentToolStripMenuItem->Text = L"��������";
			// 
			// ListStudentToolStripMenuItem
			// 
			this->ListStudentToolStripMenuItem->Name = L"ListStudentToolStripMenuItem";
			this->ListStudentToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->ListStudentToolStripMenuItem->Text = L"������ ���������";
			this->ListStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ListStudentToolStripMenuItem_Click);
			// 
			// StudentGrantToolStripMenuItem
			// 
			this->StudentGrantToolStripMenuItem->Name = L"StudentGrantToolStripMenuItem";
			this->StudentGrantToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->StudentGrantToolStripMenuItem->Text = L"���������";
			this->StudentGrantToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::StudentGrantToolStripMenuItem_Click);
			// 
			// AvarageMarksToolStripMenuItem
			// 
			this->AvarageMarksToolStripMenuItem->Name = L"AvarageMarksToolStripMenuItem";
			this->AvarageMarksToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->AvarageMarksToolStripMenuItem->Text = L"������� �����";
			this->AvarageMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AvarageMarksToolStripMenuItem_Click);
			// 
			// ListUnsucsessfulStudentToolStripMenuItem1
			// 
			this->ListUnsucsessfulStudentToolStripMenuItem1->Name = L"ListUnsucsessfulStudentToolStripMenuItem1";
			this->ListUnsucsessfulStudentToolStripMenuItem1->Size = System::Drawing::Size(202, 22);
			this->ListUnsucsessfulStudentToolStripMenuItem1->Text = L"������ ������������";
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
			this->SubjectsToolStripMenuItem->Text = L"��������";
			// 
			// AddMarksToolStripMenuItem
			// 
			this->AddMarksToolStripMenuItem->Name = L"AddMarksToolStripMenuItem";
			this->AddMarksToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AddMarksToolStripMenuItem->Text = L"����������� ������";
			this->AddMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AddMarksToolStripMenuItem_Click);
			// 
			// AvarageMarksSubjectToolStripMenuItem
			// 
			this->AvarageMarksSubjectToolStripMenuItem->Name = L"AvarageMarksSubjectToolStripMenuItem";
			this->AvarageMarksSubjectToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AvarageMarksSubjectToolStripMenuItem->Text = L"������� ���� �� ��������";
			this->AvarageMarksSubjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AvarageMarksSubjectToolStripMenuItem_Click);
			// 
			// AvarageMarksGroupToolStripMenuItem
			// 
			this->AvarageMarksGroupToolStripMenuItem->Name = L"AvarageMarksGroupToolStripMenuItem";
			this->AvarageMarksGroupToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->AvarageMarksGroupToolStripMenuItem->Text = L"������� ���� �� �������";
			this->AvarageMarksGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::AvarageMarksGroupToolStripMenuItem_Click);
			// 
			// CountUnsucsessfulMarksToolStripMenuItem
			// 
			this->CountUnsucsessfulMarksToolStripMenuItem->Name = L"CountUnsucsessfulMarksToolStripMenuItem";
			this->CountUnsucsessfulMarksToolStripMenuItem->Size = System::Drawing::Size(314, 22);
			this->CountUnsucsessfulMarksToolStripMenuItem->Text = L"���������� �������������������� ������";
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
			this->ConfigurationToolStripMenuItem->Text = L"������������";
			// 
			// FacultiesToolStripMenuItem
			// 
			this->FacultiesToolStripMenuItem->Name = L"FacultiesToolStripMenuItem";
			this->FacultiesToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->FacultiesToolStripMenuItem->Text = L"����������";
			this->FacultiesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::FacultiesToolStripMenuItem_Click);
			// 
			// ChairToolStripMenuItem
			// 
			this->ChairToolStripMenuItem->Name = L"ChairToolStripMenuItem";
			this->ChairToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->ChairToolStripMenuItem->Text = L"�������";
			this->ChairToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ChairToolStripMenuItem_Click);
			// 
			// SpecialityToolStripMenuItem
			// 
			this->SpecialityToolStripMenuItem->Name = L"SpecialityToolStripMenuItem";
			this->SpecialityToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->SpecialityToolStripMenuItem->Text = L"�������������";
			this->SpecialityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::SpecialityToolStripMenuItem_Click);
			// 
			// GroupsToolStripMenuItem
			// 
			this->GroupsToolStripMenuItem->Name = L"GroupsToolStripMenuItem";
			this->GroupsToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->GroupsToolStripMenuItem->Text = L"������";
			this->GroupsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::GroupsToolStripMenuItem_Click);
			// 
			// SubjectToolStripMenuItem
			// 
			this->SubjectToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->SubjectListToolStripMenuItem,
					this->SubjectByGroupToolStripMenuItem
			});
			this->SubjectToolStripMenuItem->Name = L"SubjectToolStripMenuItem";
			this->SubjectToolStripMenuItem->Size = System::Drawing::Size(160, 22);
			this->SubjectToolStripMenuItem->Text = L"��������";
			// 
			// SubjectListToolStripMenuItem
			// 
			this->SubjectListToolStripMenuItem->Name = L"SubjectListToolStripMenuItem";
			this->SubjectListToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->SubjectListToolStripMenuItem->Text = L"������ ���������";
			this->SubjectListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::SubjectListToolStripMenuItem_Click);
			// 
			// SubjectByGroupToolStripMenuItem
			// 
			this->SubjectByGroupToolStripMenuItem->Name = L"SubjectByGroupToolStripMenuItem";
			this->SubjectByGroupToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->SubjectByGroupToolStripMenuItem->Text = L"�������� �� �������";
			this->SubjectByGroupToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::SubjectByGroupToolStripMenuItem_Click);
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->ExitToolStripMenuItem->Text = L"�����";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyFormInputMarks::ExitToolStripMenuItem_Click);
			// 
			// domainUpDownRecording
			// 
			this->domainUpDownRecording->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownRecording->Items->Add(L"�����");
			this->domainUpDownRecording->Items->Add(L"������");
			this->domainUpDownRecording->Location = System::Drawing::Point(142, 280);
			this->domainUpDownRecording->Name = L"domainUpDownRecording";
			this->domainUpDownRecording->ReadOnly = true;
			this->domainUpDownRecording->Size = System::Drawing::Size(140, 23);
			this->domainUpDownRecording->TabIndex = 30;
			this->domainUpDownRecording->Text = L"�����";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(14, 282);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 18);
			this->label5->TabIndex = 29;
			this->label5->Text = L"����� / ������";
			// 
			// domainUpDownSeasson
			// 
			this->domainUpDownSeasson->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->domainUpDownSeasson->Items->Add(L"������");
			this->domainUpDownSeasson->Items->Add(L"������");
			this->domainUpDownSeasson->Location = System::Drawing::Point(142, 311);
			this->domainUpDownSeasson->Name = L"domainUpDownSeasson";
			this->domainUpDownSeasson->ReadOnly = true;
			this->domainUpDownSeasson->Size = System::Drawing::Size(140, 23);
			this->domainUpDownSeasson->TabIndex = 32;
			this->domainUpDownSeasson->Text = L"������";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(14, 313);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 18);
			this->label7->TabIndex = 31;
			this->label7->Text = L"������ / ������";
			// 
			// MyFormInputMarks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 448);
			this->Controls->Add(this->domainUpDownSeasson);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->domainUpDownRecording);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->buttonChange);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonAdd);
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
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonChange_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyFormInputMarks_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

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
private: System::Void SubjectByGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SubjectListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void dataGridViewStudent_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void ClearTextBox();

private: System::Void domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownSubject_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void domainUpDownStudent_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);



};
}
