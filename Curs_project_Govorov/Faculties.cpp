#include "Faculties.h"
#include "dbQuery.h"


/*----------------------------------СОБЫТИЕ ЗАГРУЗКИ ФОРМЫ--------------------------------------------*/
System::Void CursprojectGovorov::MyFormFaculties::MyFormFaculties_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewFaculty->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "*";
    String^ FROM = "faculty";


    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewFaculty->Rows->Add(
            dbReader[0],
            dbReader[1]);//заносим строки в таблицу
    }

    //закрываем соединения
    dbReader->Close();
    dbConnection->Close();

    return System::Void();
}

/*-----------------------------------КНОПКИ ДОБАВИТЬ, УДАЛИТЬ, ИЗМЕНИТЬ-----------------------------------*/

System::Void CursprojectGovorov::MyFormFaculties::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ faculty_name ="'"+ textBoxFaculties->Text->ToString()+ "'";

    if (String::IsNullOrEmpty(faculty_name->Trim('\''))) {
        MessageBox::Show("Введите имя факультета", "Внимание!");
        textBoxFaculties->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "faculty";
    String^ COLUMN = "faculty_name";
    String^ VALUES = faculty_name;


    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES)) 
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");
    
    MyFormFaculties_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewFaculty->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно изменить!", "Внимание!");
        return;
    }

    int index = dataGridViewFaculty->SelectedCells[0]->RowIndex;

    if (dataGridViewFaculty->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ faculty_id = dataGridViewFaculty->Rows[index]->Cells[0]->Value->ToString();
    String^ faculty_name = "'" + textBoxFaculties->Text->ToString() + "'";
    
    if (String::IsNullOrEmpty(faculty_name->Trim('\''))) {
        MessageBox::Show("Введите имя факультета", "Внимание!");
        textBoxFaculties->Focus();
        return;
    }

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "faculty";
    String^ SET= "faculty_name = " + faculty_name;
    String^ WHERE = "faculty_id = "+faculty_id;


    if (!UpdateRow(dbConnection, TABLE,SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновлена!");

    MyFormFaculties_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewFaculty->SelectedCells->Count == 0) {
        MessageBox::Show("Выберите строку которую нужно удалить!", "Внимание!");
        return;
    }

    int index = dataGridViewFaculty->SelectedCells[0]->RowIndex;

    if (dataGridViewFaculty->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!"); //очистка полей ввода
        return;
    }

    String^ faculty_id = dataGridViewFaculty->Rows[index]->Cells[0]->Value->ToString();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "faculty";
    String^ WHERE = "faculty_id = " + faculty_id;


    if (!DeleteRow(dbConnection,FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    MyFormFaculties_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();

    return System::Void();
}

/*------------------------------ЗАПОЛНЕНИЕ И ОЧИСТКА ТЕКСТБОКСОВ------------------------------------------------*/

System::Void CursprojectGovorov::MyFormFaculties::dataGridViewStudent_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewFaculty->SelectedRows->Count == 0)
        return;

    int index = dataGridViewFaculty->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewFaculty->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }
    
    textBoxFaculties->Text = dataGridViewFaculty->Rows[index]->Cells["Name_faculty"]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::ClearTextBox()
{
    textBoxFaculties->Text = nullptr;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormFaculties::dataGridViewFaculty_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewFaculty->SelectedRows->Count != 0)
        return;

    if (dataGridViewFaculty->SelectedCells->Count == 0)
        return;

    int index = dataGridViewFaculty->SelectedCells[0]->RowIndex;

    if (dataGridViewFaculty->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxFaculties->Text = dataGridViewFaculty->Rows[index]->Cells["Name_faculty"]->Value->ToString();
    return System::Void();
}
