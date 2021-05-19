#include "Student_grant.h"
#include "dbQuery.h"

/*----------------------------------������� �������� �����--------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudentGrant::MyFormStudentGrant_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewStudent->Rows->Clear();

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "student_id, student_name, student_surname, group_name, student_grant";
    String^ FROM = "student INNER JOIN group_t ON student.group_id = group_t.group_id";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewStudent->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3], 
            dbReader[4]);//������� ������ � �������
    }

    //��������� ����������
    dbReader->Close();

    if (domainUpDownGroup->Items->Count == 1) {
        SELECT = "group_name";
        FROM = "group_t";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownGroup->Items->Add(dbReader[0]);

        //��������� ����������
        dbReader->Close();
    }
    domainUpDownGroup->SelectedIndex = 0;

    //��������� ����������
    dbConnection->Close();
    return System::Void();
}
/*------------------------------------������ ������� ������ ���������------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudentGrant::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 1) {
        MessageBox::Show("�������� � ������� ���� ������ ������� ������ ��������", "��������!");
        return;
    }

    int index = dataGridViewStudent->SelectedCells[0]->RowIndex;

    if (dataGridViewStudent->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        MessageBox::Show("��� �� ������!", "��������!"); //������� ����� �����
        return;
    }

    double student_grant;
    bool isNum = Double::TryParse(textBoxGrant->Text->Replace('.',',') ,student_grant);

     if (!isNum) {
        MessageBox::Show("������������ ���� ������!", "��������!");
        textBoxGrant->Focus();
        return;
    }

     String^ student_id = dataGridViewStudent->Rows[index]->Cells[0]->Value->ToString();

     String^ connectionString = StringConnection(); //������ �����������
     OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

     dbConnection->Open();//��������� ����������

     String^ TABLE = "student";
     String^ SET = "student_grant = "+student_grant.ToString()->Replace(",", ".");
     String^ WHERE = "student_id = "+ student_id;

     if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
         MessageBox::Show("������ � ������ ����������!", "��������!");
     else
         MessageBox::Show("������ ������� ���������!");

     MyFormStudentGrant_Load(nullptr, nullptr);

     //��������� ����������
     dbConnection->Close();

    return System::Void();
}

/*------------------------------���������� � ������� �����������------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudentGrant::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 0)
        return;

    auto rows = dataGridViewStudent->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows = domainUpDownGroup->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows == "���")
        return;

    for (int i = 0; i < count_row; i++)
        if (rows[i]->Cells["Group"]->Value->ToString() != selecting_rows)
            rows[i]->Visible = false;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudentGrant::dataGridViewStudent_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 0)
        return;

    if (dataGridViewStudent->SelectedCells->Count == 0)
        return;

    int index = dataGridViewStudent->SelectedCells[0]->RowIndex;

    if (dataGridViewStudent->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBox(); //������� ����� �����
        return;
    }

    textBoxGrant->Text = dataGridViewStudent->Rows[index]->Cells["Grant"]->Value->ToString();
    domainUpDownGroup->Text = dataGridViewStudent->Rows[index]->Cells["Group"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudentGrant::dataGridViewStudent_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count == 0)
        return;

    int index = dataGridViewStudent->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewStudent->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBox(); //������� ����� �����
        return;
    }

    textBoxGrant->Text = dataGridViewStudent->Rows[index]->Cells["Grant"]->Value->ToString();
    domainUpDownGroup->Text = dataGridViewStudent->Rows[index]->Cells["Group"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudentGrant::ClearTextBox()
{
    domainUpDownGroup->SelectedIndex = 0;
    textBoxGrant->Text = nullptr;
    return System::Void();
}
