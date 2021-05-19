#include "Group_avg_mark.h"
#include "dbQuery.h"

System::Void CursprojectGovorov::MyFormGroupAvgMark::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ group_name = domainUpDownGroup->Text;

    int count_rows = dataGridViewGroup->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
        dataGridViewGroup->Rows[i]->Visible = true;

    if (group_name == "¬се")
        return;

    for (size_t i = 0; i < count_rows; i++)
        if (dataGridViewGroup->Rows[i]->Cells["Group"]->Value->ToString() != group_name)
            dataGridViewGroup->Rows[i]->Visible = false;

	return System::Void();
}

System::Void CursprojectGovorov::MyFormGroupAvgMark::MyFormGroupAvgMark_Load(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = StringConnection(); //строка подключени€
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_t.group_id, group_name, AVG(mark_value)";
    String^ FROM =
        "((student INNER JOIN group_t ON student.group_id = group_t.group_id)" +
        " INNER JOIN mark ON student.student_id = mark.student_id)";
    String^ GROUP_BY = "group_t.group_id, group_name";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, nullptr, nullptr, GROUP_BY); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewGroup->Rows->Add(
            dbReader[0],
            dbReader[1],
            Math::Round(
                Double::Parse(
                    dbReader[2]->ToString()), 1));//заносим строки в таблицу
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
