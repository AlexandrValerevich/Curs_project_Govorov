#include "Student_grant.h"
#include "dbQuery.h"

/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudentGrant::MyFormStudentGrant_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewStudent->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "student_id, student_name, student_surname, group_name, student_grant";
    String^ FROM = "student INNER JOIN group_t ON student.group_id = group_t.group_id";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewStudent->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3], 
            dbReader[4]);//заносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();

    if (domainUpDownGroup->Items->Count == 1) {
        SELECT = "group_name";
        FROM = "group_t";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownGroup->Items->Add(dbReader[0]);

        //закрываем соединения
        dbReader->Close();
    }
    domainUpDownGroup->SelectedIndex = 0;

    //Закрываем соединение
    dbConnection->Close();
    return System::Void();
}
/*------------------------------------КНОПКА ИЗМЕНТЬ РАЗМЕР СТИПЕНДИИ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudentGrant::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 1) {
        MessageBox::Show("Выберете в таблице одну строку которую хотите изменить", "Внимание!");
        return;
    }

    int index = dataGridViewStudent->SelectedCells[0]->RowIndex;

    if (dataGridViewStudent->Rows->Count - 1 == index) //проверяем чтобы это не была последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    double student_grant;
    bool isNum = Double::TryParse(textBoxGrant->Text->Replace('.',',') ,student_grant);

     if (!isNum) {
        MessageBox::Show("Некорректный ввод данных!", "Внимание!");
        textBoxGrant->Focus();
        return;
    }

     String^ student_id = dataGridViewStudent->Rows[index]->Cells[0]->Value->ToString();

     String^ connectionString = StringConnection(); //строка подключения
     OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

     dbConnection->Open();//открываем соединение

     String^ TABLE = "student";
     String^ SET = "student_grant = "+student_grant.ToString()->Replace(",", ".");
     String^ WHERE = "student_id = "+ student_id;

     if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
         MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
     else
         MessageBox::Show("Запись успешно обновлена!");

     MyFormStudentGrant_Load(nullptr, nullptr);

     //закрываем соединения
     dbConnection->Close();

    return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudentGrant::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 0)
        return;

    auto rows = dataGridViewStudent->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows = domainUpDownGroup->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows == "Все")
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

    if (dataGridViewStudent->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
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

    int index = dataGridViewStudent->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewStudent->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
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
