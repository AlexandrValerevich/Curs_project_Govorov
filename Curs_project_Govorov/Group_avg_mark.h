#pragma once

namespace CursprojectGovorov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyFormGroupAvgMark
	/// </summary>
	public ref class MyFormGroupAvgMark : public System::Windows::Forms::Form
	{
	public:
		MyFormGroupAvgMark(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		MyFormGroupAvgMark(System::Windows::Forms::Form^ pForm)
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
		~MyFormGroupAvgMark()
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





	private: System::Windows::Forms::DomainUpDown^ domainUpDownGroup;





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Group;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Avg_mark;




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
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Group = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Avg_mark = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->domainUpDownGroup = (gcnew System::Windows::Forms::DomainUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewGroup))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewGroup
			// 
			this->dataGridViewGroup->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewGroup->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id,
					this->Group, this->Avg_mark
			});
			this->dataGridViewGroup->Location = System::Drawing::Point(12, 77);
			this->dataGridViewGroup->Name = L"dataGridViewGroup";
			this->dataGridViewGroup->ReadOnly = true;
			this->dataGridViewGroup->Size = System::Drawing::Size(594, 391);
			this->dataGridViewGroup->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Visible = false;
			// 
			// Group
			// 
			this->Group->HeaderText = L"Группа";
			this->Group->Name = L"Group";
			this->Group->ReadOnly = true;
			this->Group->Width = 276;
			// 
			// Avg_mark
			// 
			this->Avg_mark->HeaderText = L"Средний балл";
			this->Avg_mark->Name = L"Avg_mark";
			this->Avg_mark->ReadOnly = true;
			this->Avg_mark->Width = 275;
			// 
			// domainUpDownGroup
			// 
			this->domainUpDownGroup->Items->Add(L"Все");
			this->domainUpDownGroup->Location = System::Drawing::Point(86, 26);
			this->domainUpDownGroup->Name = L"domainUpDownGroup";
			this->domainUpDownGroup->ReadOnly = true;
			this->domainUpDownGroup->Size = System::Drawing::Size(120, 23);
			this->domainUpDownGroup->Sorted = true;
			this->domainUpDownGroup->TabIndex = 1;
			this->domainUpDownGroup->Text = L"Все";
			this->domainUpDownGroup->SelectedItemChanged += gcnew System::EventHandler(this, &MyFormGroupAvgMark::domainUpDownGroup_SelectedItemChanged);
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
			// MyFormGroupAvgMark
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 480);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->domainUpDownGroup);
			this->Controls->Add(this->dataGridViewGroup);
			this->Font = (gcnew System::Drawing::Font(L"Montserrat", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyFormGroupAvgMark";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Средний балл по группам";
			this->Load += gcnew System::EventHandler(this, &MyFormGroupAvgMark::MyFormGroupAvgMark_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewGroup))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyFormGroupAvgMark_Load(System::Object^ sender, System::EventArgs^ e);
};
}
