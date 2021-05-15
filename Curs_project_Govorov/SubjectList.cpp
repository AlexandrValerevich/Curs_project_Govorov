#include "SubjectList.h"
#include "dbQuery.h"


/*----------------------------------������� �������� �����--------------------------------------------*/
System::Void CursprojectGovorov::MyFormSubjectList::MyFormSubjectList_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewSubject->Rows->Clear();

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "*";
    String^ FROM = "subject";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewSubject->Rows->Add(
            dbReader[0],
            dbReader[1]);//������� ������ � �������
    }

    //��������� ����������
    dbReader->Close();
    dbConnection->Close();

    return System::Void();
}

/*-----------------------------------������ ��������, �������, ��������-----------------------------------*/

System::Void CursprojectGovorov::MyFormSubjectList::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ subject_name = "'" + textBoxSubject->Text->ToString() + "'";

    if (String::IsNullOrEmpty(subject_name->Trim('\''))) {
        MessageBox::Show("������� �������� ��������!", "��������!");
        textBoxSubject->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE = "subject";
    String^ COLUMN = "subject_name";
    String^ VALUES = subject_name;


    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("������ � ������ ����������!", "��������!");
    else
        MessageBox::Show("������ ������� ���������!");

    MyFormSubjectList_Load(nullptr, nullptr);

    //��������� ����������
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedCells->Count == 0) {
        MessageBox::Show("�������� ������ ������� ����� ��������!", "��������!");
        return;
    }

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        MessageBox::Show("��� �� ������!", "��������!"); //������� ����� �����
        return;
    }

    String^ subject_id = dataGridViewSubject->Rows[index]->Cells[0]->Value->ToString();
    String^ subject_name = "'" + textBoxSubject->Text->ToString() + "'";

    if (String::IsNullOrEmpty(subject_name->Trim('\''))) {
        MessageBox::Show("������� ��� ����������", "��������!");
        textBoxSubject->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE = "subject";
    String^ SET = "subject_name = " + subject_name;
    String^ WHERE = "subject_id = " + subject_id;


    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("������ � ������ ����������!", "��������!");
    else
        MessageBox::Show("������ ������� ���������!");

    MyFormSubjectList_Load(nullptr, nullptr);

    //��������� ����������
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedCells->Count == 0) {
        MessageBox::Show("�������� ������ ������� ����� �������!", "��������!");
        return;
    }

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        MessageBox::Show("��� �� ������!", "��������!"); //������� ����� �����
        return;
    }

    String^ subject_id = dataGridViewSubject->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ FROM = "subject";
    String^ WHERE = "subject_id = " + subject_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("������ � ������ ��������!", "��������!");
    else
        MessageBox::Show("������ ������� �������!");

    MyFormSubjectList_Load(nullptr, nullptr);

    //��������� ����������
    dbConnection->Close();

    return System::Void();
}

/*------------------------------���������� � ������� �����������------------------------------------------------*/

System::Void CursprojectGovorov::MyFormSubjectList::dataGridViewStudent_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedRows->Count == 0)
        return;

    int index = dataGridViewSubject->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewSubject->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBox(); //������� ����� �����
        return;
    }

    textBoxSubject->Text = dataGridViewSubject->Rows[index]->Cells["Subject"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::ClearTextBox()
{
    textBoxSubject->Text = nullptr;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::dataGridViewSubject_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewSubject->SelectedRows->Count != 0)
        return;

    if (dataGridViewSubject->SelectedCells->Count == 0)
        return;

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBox(); //������� ����� �����
        return;
    }

    textBoxSubject->Text = dataGridViewSubject->Rows[index]->Cells["Subject"]->Value->ToString();
    return System::Void();
}


