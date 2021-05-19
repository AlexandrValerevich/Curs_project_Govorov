#include "Subject_avg_mark.h"
#include "dbQuery.h"

System::Void CursprojectGovorov::MyFormSubjectAvgMark::MyFormSubjectAvgMark_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = StringConnection(); //строка подключени€
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "subject.subject_id, subject_name, AVG(mark_value)";
    String^ FROM =
        "subject INNER JOIN mark ON mark.subject_id = subject.subject_id ";
    String^ GROUP_BY = "subject.subject_id, subject_name";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewSubject->Rows->Add(
            dbReader[0],
            dbReader[1],
            Math::Round(
                Double::Parse(
                    dbReader[2]->ToString()), 1));//заносим строки в таблицу
    }

    //закрываем соединени€
    dbReader->Close();

    if (domainUpDownSubject->Items->Count == 1) {
        SELECT = "subject_name";
        FROM = "subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubject->Items->Add(dbReader[0]);

        //закрываем соединени€
        dbReader->Close();
    }
    domainUpDownSubject->Text = domainUpDownSubject->Items[0]->ToString();

    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectAvgMark::domainUpDownSubject_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ subject_name = domainUpDownSubject->Text;

    int count_rows = dataGridViewSubject->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
        dataGridViewSubject->Rows[i]->Visible = true;

    if (subject_name == "¬се")
        return;

    for (size_t i = 0; i < count_rows; i++)
        if (dataGridViewSubject->Rows[i]->Cells["Subject"]->Value->ToString() != subject_name)
            dataGridViewSubject->Rows[i]->Visible = false;
    return System::Void();
}
