#include "Unsuccessful_mark.h"
#include "dbQuery.h"

System::Void CursprojectGovorov::MyFormUnsuccessfuAvgMark::MyFormUnsuccessfuAvgMark_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = StringConnection(); //������ �����������
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//��������� ����������

    String^ SELECT = "subject.subject_id, subject_name, COUNT(mark_value)";
    String^ FROM =
        "subject INNER JOIN mark ON mark.subject_id = subject.subject_id ";
    String^ WHERE = "mark_value < 4";
    String^ GROUP_BY = "subject.subject_id, subject_name";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE, nullptr, GROUP_BY); //����� ���������� �������

    while (dbReader->Read())
    {
        dataGridViewSubject->Rows->Add(
            dbReader[0],
            dbReader[1],
            Math::Round(
                Double::Parse(
                    dbReader[2]->ToString()), 1));//������� ������ � �������
    }

    //��������� ����������
    dbReader->Close();

    if (domainUpDownSubject->Items->Count == 1) {
        SELECT = "subject_name";
        FROM = "subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubject->Items->Add(dbReader[0]);

        //��������� ����������
        dbReader->Close();
    }
    domainUpDownSubject->Text = domainUpDownSubject->Items[0]->ToString();

    dbConnection->Close();

	return System::Void();
}

System::Void CursprojectGovorov::MyFormUnsuccessfuAvgMark::domainUpDownSubject_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ subject_name = domainUpDownSubject->Text;

    int count_rows = dataGridViewSubject->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
        dataGridViewSubject->Rows[i]->Visible = true;

    if (subject_name == "���")
        return;

    for (size_t i = 0; i < count_rows; i++)
        if (dataGridViewSubject->Rows[i]->Cells["Subject"]->Value->ToString() != subject_name)
            dataGridViewSubject->Rows[i]->Visible = false;

	return System::Void();
}
