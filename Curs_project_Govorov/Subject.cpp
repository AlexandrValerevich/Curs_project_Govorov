#include "Subject.h"
#include "dbQuery.h"


/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/

System::Void CursprojectGovorov::MyFormSubject::MyFormSubject_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewSubject->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_subject_id, group_name, subject_name";
    String^ FROM = "(group_t INNER JOIN group_subject ON group_t.group_id = group_subject.group_id) INNER JOIN subject ON subject.subject_id = group_subject.subject_id";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewSubject->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2]);//заносим строки в таблицу
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
    domainUpDownGroup->Text = domainUpDownGroup->Items[0]->ToString();

    if (domainUpDownSubject->Items->Count == 1) {
        SELECT = "subject_name";
        FROM = "subject";

        dbReader = SelectRow(dbConnection, SELECT, FROM);

        while (dbReader->Read())
            domainUpDownSubject->Items->Add(dbReader[0]);

        //закрываем соединения
        dbReader->Close();
    }
    domainUpDownSubject->Text = domainUpDownSubject->Items[0]->ToString();

    //Закрываем соединение
    dbConnection->Close();
    return System::Void();
}

/*-----------------------------------КНОПКИ ДОБАВИТЬ, УДАЛИТЬ, ИЗМЕНИТЬ-----------------------------------*/

System::Void CursprojectGovorov::MyFormSubject::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ group_name = "'" + domainUpDownGroup->Text->ToString() + "'";

    if (String::IsNullOrEmpty(group_name->Trim('\''))) {
        MessageBox::Show("Выберите группу!", "Внимание!");
        domainUpDownGroup->Focus();
        return;
    }

    String^ subject_name = "'" + domainUpDownSubject->Text->ToString() + "'";

    if (subject_name == "'Все'") {
        MessageBox::Show("Выберите предмет!", "Внимание!");
        domainUpDownSubject->Focus();
        return;
    }

    String^ group_id;
    String^ subject_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_id";
    String^ FROM = "group_t";
    String^ WHERE = "group_name LIKE " + group_name;
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;

    group_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    SELECT = "subject_id";
    FROM = "subject";
    WHERE = "subject_name LIKE " + subject_name;

    subject_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    if (String::IsNullOrEmpty(subject_id)) {
        TABLE = "subject";
        COLUMN = "subject_name";
        VALUES = subject_name;

        if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES)) {
            MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
            dbConnection->Close();
            return;
        }

        subject_id = SelectID(dbConnection, SELECT, FROM, WHERE);
    }

    TABLE = "group_subject";
    COLUMN = "group_id, subject_id";
    VALUES = group_id + ", " + subject_id;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormSubject_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubject::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно изменить!", "Внимание!");
        return;
    }

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ group_id;
    String^ group_name = "'" + domainUpDownGroup->Text->ToString() + "'";

    if (String::IsNullOrEmpty(group_name->Trim('\''))) {
        MessageBox::Show("Введите группу!", "Внимание!");
        domainUpDownGroup->Focus();
        return;
    }

    String^ subject_id;
    String^ subject_name = "'" + domainUpDownSubject->Text->ToString() + "'";

    if (subject_name == "'Все'" || String::IsNullOrEmpty(subject_name)) {
        MessageBox::Show("Выберите предмет!", "Внимание!");
        domainUpDownSubject->Focus();
        return;
    }

    String^ group_subject_id = dataGridViewSubject->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT;
    String^ FROM = "group_subject";
    String^ WHERE = "group_subject_id =" + group_subject_id;
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;

    if (!DeleteRow(dbConnection, FROM, WHERE)) {
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
        dbConnection->Close();
        MyFormSubject_Load(nullptr, nullptr);
        return;
    }

    SELECT = "group_id";
    FROM = "group_t";
    WHERE = "group_name LIKE " + group_name;
    
    group_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    SELECT = "subject_id";
    FROM = "subject";
    WHERE = "subject_name LIKE " + subject_name;

    subject_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    if (String::IsNullOrEmpty(subject_id)) {
        TABLE = "subject";
        COLUMN = "subject_name";
        VALUES = subject_name;

        if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES)) {
            MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
            dbConnection->Close();
            return;
        }

        subject_id = SelectID(dbConnection, SELECT, FROM, WHERE);
    }

    TABLE = "group_subject";
    COLUMN = "group_id, subject_id";
    VALUES = group_id + ", " + subject_id;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновления!");

    //закрываем соединения
    dbConnection->Close();

    MyFormSubject_Load(nullptr, nullptr);

    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubject::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно удалить!", "Внимание!");
        return;
    }

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    String^ group_subject_id = dataGridViewSubject->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "group_subject";
    String^ WHERE = "group_subject_id = " + group_subject_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    //закрываем соединения
    dbConnection->Close();

    MyFormSubject_Load(nullptr, nullptr);

    return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormSubject::dataGridViewSubject_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewSubject->SelectedRows->Count != 0)
        return;

    if (dataGridViewSubject->SelectedCells->Count == 0)
        return;

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    domainUpDownGroup->Text = dataGridViewSubject->Rows[index]->Cells["Group"]->Value->ToString();
    domainUpDownSubject->Text = dataGridViewSubject->Rows[index]->Cells["Subject"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubject::dataGridViewSubject_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewSubject->SelectedRows->Count == 0)
        return;

    int index = dataGridViewSubject->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewSubject->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    domainUpDownGroup->Text = dataGridViewSubject->Rows[index]->Cells["Group"]->Value->ToString();
    domainUpDownSubject->Text = dataGridViewSubject->Rows[index]->Cells["Subject"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubject::domainUpDownSubject_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    domainUpDownGroup_SelectedItemChanged(nullptr, nullptr);
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubject::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedRows->Count != 0)
        return;

    auto rows = dataGridViewSubject->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows_group = domainUpDownGroup->Text;
    String^ selecting_rows_subject = domainUpDownSubject->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows_group != "Все")
    {
        for (int i = 0; i < count_row; i++)
            if (rows[i]->Cells["Group"]->Value->ToString() != selecting_rows_group)
                rows[i]->Visible = false;
    }

    if (selecting_rows_subject != "Все")
    {
        for (int i = 0; i < count_row; i++)
            if (rows[i]->Cells["Subject"]->Value->ToString() != selecting_rows_subject)
                rows[i]->Visible = false;
    }

    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubject::ClearTextBox()
{
    domainUpDownGroup->Text = domainUpDownGroup->Items[0]->ToString();
    domainUpDownSubject->Text = domainUpDownSubject->Items[0]->ToString();
    return System::Void();
}




