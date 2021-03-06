#include "Student_avg_mark.h"
#include "dbQuery.h"

System::Void CursprojectGovorov::MyFormStudentAvgMark::MyFormStudentAvgMark_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = StringConnection(); //?????? ???????????
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//????????? ??????????

    String^ SELECT = "student.student_id, student_name, student_surname, group_name, AVG(mark_value)";
    String^ FROM =
        "((student INNER JOIN group_t ON student.group_id = group_t.group_id)" +
        " INNER JOIN mark ON student.student_id = mark.student_id)";
    String^ GROUP_BY = "student.student_id, student_name, student_surname, group_name";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY); //????? ?????????? ???????

    while (dbReader->Read())
    {
        dataGridViewStudent->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            Math::Round(
                Double::Parse(
                    dbReader[4]->ToString()),1));//??????? ?????? ? ???????
    }

    //????????? ??????????
    dbReader->Close();

    if (domainUpDownGroup->Items->Count == 1) {
        SELECT = "group_name";
        FROM = "group_t";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownGroup->Items->Add(dbReader[0]);

        //????????? ??????????
        dbReader->Close();
    }
    domainUpDownGroup->Text = domainUpDownGroup->Items[0]->ToString();

    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudentAvgMark::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ group_name = domainUpDownGroup->Text;

    int count_rows = dataGridViewStudent->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
        dataGridViewStudent->Rows[i]->Visible = true;

    if (group_name == "???")
        return;

    for (size_t i = 0; i < count_rows; i++)
        if(dataGridViewStudent->Rows[i]->Cells["Group"]->Value->ToString() != group_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    return System::Void();
}
