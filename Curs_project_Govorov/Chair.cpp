#include "Chair.h"
#include "dbQuery.h"


/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/

System::Void CursprojectGovorov::MyFormChair::MyFormChair_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewChair->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "chair_id, faculty_name, chair_name";
    String^ FROM = "chair INNER JOIN faculty ON chair.faculty_id = faculty.faculty_id";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewChair->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2]);//заносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();

    if (domainUpDownFaculties->Items->Count == 1) {
        SELECT = "faculty_name";
        FROM = "faculty";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownFaculties->Items->Add(dbReader[0]);
        
        //закрываем соединения
        dbReader->Close();
    }
    domainUpDownFaculties->Text = domainUpDownFaculties->Items[0]->ToString();

    //Закрываем соединение
    dbConnection->Close();
	return System::Void();
}

/*-----------------------------------КНОПКИ ДОБАВИТЬ, УДАЛИТЬ, ИЗМЕНИТЬ-----------------------------------*/

System::Void CursprojectGovorov::MyFormChair::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ chair_name = "'" + textBoxChair->Text->ToString() + "'";

    if (String::IsNullOrEmpty(chair_name->Trim('\''))) {
        MessageBox::Show("Введите имя кафедры!", "Внимание!");
        textBoxChair->Focus();
        return;
    }

    String^ faculty_name = "'" + domainUpDownFaculties->Text->ToString() + "'";

    if (faculty_name == "'Все'") {
        MessageBox::Show("Выберите факультет!", "Внимание!");
        domainUpDownFaculties->Focus();
        return;
    }

    String^ faculty_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "faculty_id";
    String^ FROM   = "faculty";
    String^ WHERE  = "faculty_name LIKE " + faculty_name;
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;

    faculty_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "chair";
    COLUMN = "faculty_id, chair_name";
    VALUES = faculty_id + ", " + chair_name;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormChair_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
	return System::Void();
}

System::Void CursprojectGovorov::MyFormChair::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewChair->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно изменить!", "Внимание!");
        return;
    }

    int index = dataGridViewChair->SelectedCells[0]->RowIndex;

    if (dataGridViewChair->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ chair_id = dataGridViewChair->Rows[index]->Cells[0]->Value->ToString();
    String^ chair_name = "'" + textBoxChair->Text->ToString() + "'";

    if (String::IsNullOrEmpty(chair_name->Trim('\''))) {
        MessageBox::Show("Введите имя кафедры!", "Внимание!");
        textBoxChair->Focus();
        return;
    }

    String^ faculty_name = "'" + domainUpDownFaculties->Text->ToString() + "'";

    if (faculty_name == "'Все'") {
        MessageBox::Show("Выберите факультет!", "Внимание!");
        domainUpDownFaculties->Focus();
        return;
    }

    String^ faculty_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "faculty_id";
    String^ FROM = "faculty";
    String^ WHERE = "faculty_name LIKE " + faculty_name;
    String^ TABLE;
    String^ SET;

    faculty_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "chair";
    SET = "chair_name = " + chair_name + ", faculty_id = " + faculty_id;
    WHERE = "chair_id = " + chair_id;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновлена!");

    MyFormChair_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();

	return System::Void();
}

System::Void CursprojectGovorov::MyFormChair::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewChair->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно удалить!", "Внимание!");
        return;
    }

    int index = dataGridViewChair->SelectedCells[0]->RowIndex;

    if (dataGridViewChair->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    String^ chair_id = dataGridViewChair->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "chair";
    String^ WHERE = "chair_id = " + chair_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    MyFormChair_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
	return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormChair::dataGridViewChair_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewChair->SelectedRows->Count != 0)
        return;

    if (dataGridViewChair->SelectedCells->Count == 0)
        return;

    int index = dataGridViewChair->SelectedCells[0]->RowIndex;

    if (dataGridViewChair->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxChair->Text = dataGridViewChair->Rows[index]->Cells["Chair"]->Value->ToString();
    domainUpDownFaculties->Text = dataGridViewChair->Rows[index]->Cells["Name_faculty"]->Value->ToString();
	return System::Void();
}

System::Void CursprojectGovorov::MyFormChair::dataGridViewChair_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewChair->SelectedRows->Count == 0)
        return;

    int index = dataGridViewChair->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewChair->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxChair->Text = dataGridViewChair->Rows[index]->Cells["Chair"]->Value->ToString();
    domainUpDownFaculties->Text = dataGridViewChair->Rows[index]->Cells["Name_faculty"]->Value->ToString();
	return System::Void();
}

System::Void CursprojectGovorov::MyFormChair::domainUpDownFaculties_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewChair->SelectedRows->Count != 0)
        return;

    auto rows = dataGridViewChair->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows = domainUpDownFaculties->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows == "Все")
        return;

    for (int i = 0; i < count_row; i++)
        if (rows[i]->Cells["Name_faculty"]->Value->ToString() != selecting_rows)
            rows[i]->Visible = false;

	return System::Void();
}

System::Void CursprojectGovorov::MyFormChair::ClearTextBox()
{
    textBoxChair->Text = nullptr;
    domainUpDownFaculties->Text = domainUpDownFaculties->Items[0]->ToString();
	return System::Void();
}
