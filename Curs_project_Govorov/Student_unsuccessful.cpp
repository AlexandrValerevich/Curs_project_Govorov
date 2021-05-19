#include "Student_unsuccessful.h"
#include "dbQuery.h"

System::Void CursprojectGovorov::MyFormStudentUnsucsessful::MyFormStudentUnsucsessful_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = StringConnection(); //строка подключени€
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "student.student_id, student_name, student_surname, group_name, COUNT(mark_value)";
    String^ FROM =
        "((student INNER JOIN group_t ON student.group_id = group_t.group_id)" +
        " INNER JOIN mark ON student.student_id = mark.student_id)";
    String^ WHERE = "mark_value < 4";
    String^ GROUP_BY = "student.student_id, student_name, student_surname, group_name";
    String^ HAVING = "COUNT(mark_value) > 2";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE, nullptr, GROUP_BY, HAVING); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewStudent->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            Math::Round(
                Double::Parse(
                    dbReader[4]->ToString()), 1));//заносим строки в таблицу
    }

    //закрываем соединени€
    dbReader->Close();

    if (domainUpDownGroup->Items->Count == 1) {
        SELECT = "group_name";
        FROM = "group_t";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownGroup->Items->Add(dbReader[0]);

        //закрываем соединени€
        dbReader->Close();
    }
    domainUpDownGroup->Text = domainUpDownGroup->Items[0]->ToString();

    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudentUnsucsessful::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ group_name = domainUpDownGroup->Text;

    int count_rows = dataGridViewStudent->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
        dataGridViewStudent->Rows[i]->Visible = true;

    if (group_name == "¬се")
        return;

    for (size_t i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Group"]->Value->ToString() != group_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    return System::Void();
}
