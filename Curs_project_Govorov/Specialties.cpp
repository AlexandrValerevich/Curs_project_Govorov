#include "Specialties.h"
#include "dbQuery.h"


/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/

System::Void CursprojectGovorov::MyFormSpeciality::MyFormSpeciality_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewSpecialties->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "speciality_id, chair_name, speciality_name";
    String^ FROM = "speciality INNER JOIN chair ON chair.chair_id = speciality.chair_id";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewSpecialties->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2]);//заносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();

    if (domainUpDownChair->Items->Count == 1) {
        SELECT = "chair_name";
        FROM = "chair";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownChair->Items->Add(dbReader[0]);

        //закрываем соединения
        dbReader->Close();
    }
    domainUpDownChair->Text = domainUpDownChair->Items[0]->ToString();

    //Закрываем соединение
    dbConnection->Close();
    return System::Void();
}

/*-----------------------------------КНОПКИ ДОБАВИТЬ, УДАЛИТЬ, ИЗМЕНИТЬ-----------------------------------*/

System::Void CursprojectGovorov::MyFormSpeciality::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ speciality_name = "'" + textBoxSpecialties->Text->ToString() + "'";

    if (String::IsNullOrEmpty(speciality_name->Trim('\''))) {
        MessageBox::Show("Введите название специальности!", "Внимание!");
        textBoxSpecialties->Focus();
        return;
    }

    String^ chair_name = "'" + domainUpDownChair->Text->ToString() + "'";

    if (chair_name == "'Все'") {
        MessageBox::Show("Выберите Кафедру!", "Внимание!");
        domainUpDownChair->Focus();
        return;
    }

    String^ chair_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "chair_id";
    String^ FROM = "chair";
    String^ WHERE = "chair_name LIKE " + chair_name;
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;

    chair_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "speciality";
    COLUMN = "chair_id, speciality_name";
    VALUES = chair_id + ", " + speciality_name;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormSpeciality_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSpeciality::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSpecialties->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно изменить!", "Внимание!");
        return;
    }

    int index = dataGridViewSpecialties->SelectedCells[0]->RowIndex;

    if (dataGridViewSpecialties->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ speciality_id = dataGridViewSpecialties->Rows[index]->Cells[0]->Value->ToString();
    String^ speciality_name = "'" + textBoxSpecialties->Text->ToString() + "'";

    if (String::IsNullOrEmpty(speciality_name->Trim('\''))) {
        MessageBox::Show("Введите имя кафедры!", "Внимание!");
        textBoxSpecialties->Focus();
        return;
    }

    String^ chair_name = "'" + domainUpDownChair->Text->ToString() + "'";

    if (chair_name == "'Все'") {
        MessageBox::Show("Выберите факультет!", "Внимание!");
        domainUpDownChair->Focus();
        return;
    }

    String^ chair_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "chair_id";
    String^ FROM = "chair";
    String^ WHERE = "chair_name LIKE " + chair_name;
    String^ TABLE;
    String^ SET;

    chair_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "speciality";
    SET = "speciality_name = " + speciality_name + ", chair_id = " + chair_id;
    WHERE = "speciality_id = " + speciality_id;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновлена!");

    MyFormSpeciality_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();

    return System::Void();
}

System::Void CursprojectGovorov::MyFormSpeciality::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSpecialties->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно удалить!", "Внимание!");
        return;
    }

    int index = dataGridViewSpecialties->SelectedCells[0]->RowIndex;

    if (dataGridViewSpecialties->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    String^ speciality_id = dataGridViewSpecialties->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "speciality";
    String^ WHERE = "speciality_id = " + speciality_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    MyFormSpeciality_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormSpeciality::dataGridViewSpecialties_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewSpecialties->SelectedRows->Count != 0)
        return;

    if (dataGridViewSpecialties->SelectedCells->Count == 0)
        return;

    int index = dataGridViewSpecialties->SelectedCells[0]->RowIndex;

    if (dataGridViewSpecialties->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxSpecialties->Text = dataGridViewSpecialties->Rows[index]->Cells["Specialties"]->Value->ToString();
    domainUpDownChair->Text = dataGridViewSpecialties->Rows[index]->Cells["Name_chair"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSpeciality::dataGridViewSpecialties_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewSpecialties->SelectedRows->Count == 0)
        return;

    int index = dataGridViewSpecialties->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewSpecialties->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxSpecialties->Text = dataGridViewSpecialties->Rows[index]->Cells["Specialties"]->Value->ToString();
    domainUpDownChair->Text = dataGridViewSpecialties->Rows[index]->Cells["Name_chair"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSpeciality::domainUpDownChair_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSpecialties->SelectedRows->Count != 0)
        return;

    auto rows = dataGridViewSpecialties->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows = domainUpDownChair->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows == "Все")
        return;

    for (int i = 0; i < count_row; i++)
        if (rows[i]->Cells["Name_chair"]->Value->ToString() != selecting_rows)
            rows[i]->Visible = false;

    return System::Void();
}

System::Void CursprojectGovorov::MyFormSpeciality::ClearTextBox()
{
    textBoxSpecialties->Text = nullptr;
    domainUpDownChair->Text = domainUpDownChair->Items[0]->ToString();
    return System::Void();
}
