#include "SubjectList.h"
#include "dbQuery.h"


/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/
System::Void CursprojectGovorov::MyFormSubjectList::MyFormSubjectList_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewSubject->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "*";
    String^ FROM = "subject";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewSubject->Rows->Add(
            dbReader[0],
            dbReader[1]);//заносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();
    dbConnection->Close();

    return System::Void();
}

/*-----------------------------------КНОПКИ ДОБАВИТЬ, УДАЛИТЬ, ИЗМЕНИТЬ-----------------------------------*/

System::Void CursprojectGovorov::MyFormSubjectList::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ subject_name = "'" + textBoxSubject->Text->ToString() + "'";

    if (String::IsNullOrEmpty(subject_name->Trim('\''))) {
        MessageBox::Show("Введите название предмета!", "Внимание!");
        textBoxSubject->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "subject";
    String^ COLUMN = "subject_name";
    String^ VALUES = subject_name;


    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormSubjectList_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
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

    String^ subject_id = dataGridViewSubject->Rows[index]->Cells[0]->Value->ToString();
    String^ subject_name = "'" + textBoxSubject->Text->ToString() + "'";

    if (String::IsNullOrEmpty(subject_name->Trim('\''))) {
        MessageBox::Show("Введите имя факультета", "Внимание!");
        textBoxSubject->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "subject";
    String^ SET = "subject_name = " + subject_name;
    String^ WHERE = "subject_id = " + subject_id;


    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновлена!");

    MyFormSubjectList_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно удалить!", "Внимание!");
        return;
    }

    int index = dataGridViewSubject->SelectedCells[0]->RowIndex;

    if (dataGridViewSubject->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ subject_id = dataGridViewSubject->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "subject";
    String^ WHERE = "subject_id = " + subject_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    MyFormSubjectList_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();

    return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormSubjectList::dataGridViewStudent_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewSubject->SelectedRows->Count == 0)
        return;

    int index = dataGridViewSubject->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewSubject->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxSubject->Text = dataGridViewSubject->Rows[index]->Cells["Subject"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::ClearTextBox()
{
    textBoxSubject->Text = nullptr;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormSubjectList::dataGridViewSubject_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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

    textBoxSubject->Text = dataGridViewSubject->Rows[index]->Cells["Subject"]->Value->ToString();
    return System::Void();
}


