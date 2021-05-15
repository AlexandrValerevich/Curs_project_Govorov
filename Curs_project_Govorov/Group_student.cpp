#include "Group_student.h"
#include "dbQuery.h"


/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/

System::Void CursprojectGovorov::MyFormGroup::MyFormGroup_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewGroup->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_id, speciality_name, group_name";
    String^ FROM = "speciality INNER JOIN group_t ON group_t.speciality_id = speciality.speciality_id";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewGroup->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2]);//заносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();

    if (domainUpDownSpeciality->Items->Count == 1) {
        SELECT = "speciality_name";
        FROM = "speciality";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSpeciality->Items->Add(dbReader[0]);

        //закрываем соединения
        dbReader->Close();
    }
    domainUpDownSpeciality->Text = domainUpDownSpeciality->Items[0]->ToString();

    //Закрываем соединение
    dbConnection->Close();
    return System::Void();
}

/*-----------------------------------КНОПКИ ДОБАВИТЬ, УДАЛИТЬ, ИЗМЕНИТЬ-----------------------------------*/

System::Void CursprojectGovorov::MyFormGroup::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ group_name = "'" + textBoxGroup->Text->ToString() + "'";

    if (String::IsNullOrEmpty(group_name->Trim('\''))) {
        MessageBox::Show("Введите название специальности!", "Внимание!");
        textBoxGroup->Focus();
        return;
    }

    String^ speciality_name = "'" + domainUpDownSpeciality->Text->ToString() + "'";

    if (speciality_name == "'Все'") {
        MessageBox::Show("Выберите специальность!", "Внимание!");
        domainUpDownSpeciality->Focus();
        return;
    }

    String^ speciality_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "speciality_id";
    String^ FROM = "speciality";
    String^ WHERE = "speciality_name LIKE " + speciality_name;
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;

    speciality_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "group_t";
    COLUMN = "speciality_id, group_name";
    VALUES = speciality_id + ", " + group_name;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormGroup_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormGroup::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewGroup->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно изменить!", "Внимание!");
        return;
    }

    int index = dataGridViewGroup->SelectedCells[0]->RowIndex;

    if (dataGridViewGroup->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ group_id = dataGridViewGroup->Rows[index]->Cells[0]->Value->ToString();
    String^ group_name = "'" + textBoxGroup->Text->ToString() + "'";

    if (String::IsNullOrEmpty(group_name->Trim('\''))) {
        MessageBox::Show("Введите имя кафедры!", "Внимание!");
        textBoxGroup->Focus();
        return;
    }

    String^ speciality_name = "'" + domainUpDownSpeciality->Text->ToString() + "'";

    if (speciality_name == "'Все'") {
        MessageBox::Show("Выберите факультет!", "Внимание!");
        domainUpDownSpeciality->Focus();
        return;
    }

    String^ speciality_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "speciality_id";
    String^ FROM = "speciality";
    String^ WHERE = "speciality_name LIKE " + speciality_name;
    String^ TABLE;
    String^ SET;

    speciality_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "group_t";
    SET = "group_name = " + group_name + ", speciality_id = " + speciality_id;
    WHERE = "group_id = " + group_id;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновлена!");

    MyFormGroup_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();

    return System::Void();
}

System::Void CursprojectGovorov::MyFormGroup::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewGroup->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно удалить!", "Внимание!");
        return;
    }

    int index = dataGridViewGroup->SelectedCells[0]->RowIndex;

    if (dataGridViewGroup->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    String^ group_id = dataGridViewGroup->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "group_t";
    String^ WHERE = "group_id = " + group_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    MyFormGroup_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormGroup::dataGridViewGroup_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewGroup->SelectedRows->Count != 0)
        return;

    if (dataGridViewGroup->SelectedCells->Count == 0)
        return;

    int index = dataGridViewGroup->SelectedCells[0]->RowIndex;

    if (dataGridViewGroup->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxGroup->Text = dataGridViewGroup->Rows[index]->Cells["Group"]->Value->ToString();
    domainUpDownSpeciality->Text = dataGridViewGroup->Rows[index]->Cells["Speciality"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormGroup::dataGridViewGroup_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewGroup->SelectedRows->Count == 0)
        return;

    int index = dataGridViewGroup->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewGroup->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxGroup->Text = dataGridViewGroup->Rows[index]->Cells["Group"]->Value->ToString();
    domainUpDownSpeciality->Text = dataGridViewGroup->Rows[index]->Cells["Speciality"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormGroup::domainUpDownSpeciality_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewGroup->SelectedRows->Count != 0)
        return;

    auto rows = dataGridViewGroup->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows = domainUpDownSpeciality->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows == "Все")
        return;

    for (int i = 0; i < count_row; i++)
        if (rows[i]->Cells["Speciality"]->Value->ToString() != selecting_rows)
            rows[i]->Visible = false;

    return System::Void();
}

System::Void CursprojectGovorov::MyFormGroup::ClearTextBox()
{
    textBoxGroup->Text = nullptr;
    domainUpDownSpeciality->Text = domainUpDownSpeciality->Items[0]->ToString();
    return System::Void();
}


