#include "Faculties.h"
#include "dbQuery.h"


/*----------------------------------������� �������� �����--------------------------------------------*/
System::Void CursprojectGovorov::MyFormFaculties::MyFormFaculties_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewFaculty->Rows->Clear();

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "*";
    String^ FROM = "faculty";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewFaculty->Rows->Add(
            dbReader[0],
            dbReader[1]);//������� ������ � �������
    }

    //��������� ����������
    dbReader->Close();
    dbConnection->Close();

    return System::Void();
}

/*-----------------------------------������ ��������, �������, ��������-----------------------------------*/

System::Void CursprojectGovorov::MyFormFaculties::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ faculty_name ="'"+ textBoxFaculties->Text->ToString()+ "'";

    if (String::IsNullOrEmpty(faculty_name->Trim('\''))) {
        MessageBox::Show("������� ��� ����������", "��������!");
        textBoxFaculties->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE = "faculty";
    String^ COLUMN = "faculty_name";
    String^ VALUES = faculty_name;


    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES)) 
        MessageBox::Show("������ � ������ ����������!", "��������!");
    else
        MessageBox::Show("������ ������� ���������!");
    
    MyFormFaculties_Load(nullptr, nullptr);

    //��������� ����������
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewFaculty->SelectedCells->Count == 0) {
        MessageBox::Show("�������� ������ ������� ����� ��������!", "��������!");
        return;
    }

    int index = dataGridViewFaculty->SelectedCells[0]->RowIndex;

    if (dataGridViewFaculty->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        MessageBox::Show("��� �� ������!", "��������!"); //������� ����� �����
        return;
    }

    String^ faculty_id = dataGridViewFaculty->Rows[index]->Cells[0]->Value->ToString();
    String^ faculty_name = "'" + textBoxFaculties->Text->ToString() + "'";
    
    if (String::IsNullOrEmpty(faculty_name->Trim('\''))) {
        MessageBox::Show("������� ��� ����������", "��������!");
        textBoxFaculties->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ TABLE = "faculty";
    String^ SET= "faculty_name = " + faculty_name;
    String^ WHERE = "faculty_id = "+faculty_id;


    if (!UpdateRow(dbConnection, TABLE,SET, WHERE))
        MessageBox::Show("������ � ������ ����������!", "��������!");
    else
        MessageBox::Show("������ ������� ���������!");

    MyFormFaculties_Load(nullptr, nullptr);

    //��������� ����������
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewFaculty->SelectedCells->Count == 0) {
        MessageBox::Show("�������� ������ ������� ����� �������!", "��������!");
        return;
    }

    int index = dataGridViewFaculty->SelectedCells[0]->RowIndex;

    if (dataGridViewFaculty->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        MessageBox::Show("��� �� ������!", "��������!"); //������� ����� �����
        return;
    }

    String^ faculty_id = dataGridViewFaculty->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ FROM = "faculty";
    String^ WHERE = "faculty_id = " + faculty_id;


    if (!DeleteRow(dbConnection,FROM, WHERE))
        MessageBox::Show("������ � ������ ��������!", "��������!");
    else
        MessageBox::Show("������ ������� �������!");

    MyFormFaculties_Load(nullptr, nullptr);

    //��������� ����������
    dbConnection->Close();

    return System::Void();
}

/*------------------------------���������� � ������� �����������------------------------------------------------*/

System::Void CursprojectGovorov::MyFormFaculties::dataGridViewStudent_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewFaculty->SelectedRows->Count == 0)
        return;

    int index = dataGridViewFaculty->SelectedRows[0]->Index; //����� ������ ������ ��������� ������

    if (dataGridViewFaculty->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBox(); //������� ����� �����
        return;
    }
    
    textBoxFaculties->Text = dataGridViewFaculty->Rows[index]->Cells["Name_faculty"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::ClearTextBox()
{
    textBoxFaculties->Text = nullptr;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::dataGridViewFaculty_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewFaculty->SelectedRows->Count != 0)
        return;

    if (dataGridViewFaculty->SelectedCells->Count == 0)
        return;

    int index = dataGridViewFaculty->SelectedCells[0]->RowIndex;

    if (dataGridViewFaculty->Rows->Count - 1 == index) //��������� ����� ��� �� ���� ��������� ������
    {
        ClearTextBox(); //������� ����� �����
        return;
    }

    textBoxFaculties->Text = dataGridViewFaculty->Rows[index]->Cells["Name_faculty"]->Value->ToString();
    return System::Void();
}
