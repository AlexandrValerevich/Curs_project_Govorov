#include "dbQuery.h"
#include "Student.h"
#include "Chair.h"
#include "Faculties.h"
#include "Group_avg_mark.h"
#include "Group_student.h"
#include "Input_mark.h"
#include "Specialties.h"
#include "Student_avg_mark.h"
#include "Student_grant.h"
#include "Student_unsuccessful.h"
#include "Subject_avg_mark.h"
#include "Unsuccessful_mark.h"
#include "Subject.h"
#include "SubjectList.h"

/*---------------------------------------------------КНОПКИ ПЕРЕКЛЮЧЕНИЯ МЕЖДУ ФОРМАМИ-------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::ListStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::StudentGrantToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudentGrant^ form = gcnew MyFormStudentGrant(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::AvarageMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudentAvgMark^ form = gcnew MyFormStudentAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::ListUnsucsessfulStudentToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudentUnsucsessful^ form = gcnew MyFormStudentUnsucsessful(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::AddMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormInputMarks^ form = gcnew MyFormInputMarks(this->Location);
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::AvarageMarksSubjectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubjectAvgMark^ form = gcnew  MyFormSubjectAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::AvarageMarksGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormGroupAvgMark^ form = gcnew  MyFormGroupAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::CountUnsucsessfulMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormUnsuccessfuAvgMark^ form = gcnew  MyFormUnsuccessfuAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::FacultiesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormFaculties^ form = gcnew  MyFormFaculties(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::ChairToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormChair^ form = gcnew MyFormChair(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::SpecialityToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSpeciality^ form = gcnew MyFormSpeciality(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::GroupsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormGroup^ form = gcnew MyFormGroup(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::SubjectByGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubject^ form = gcnew MyFormSubject(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::SubjectListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubjectList^ form = gcnew MyFormSubjectList(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------СОБЫТЯИ ЗАГРУЗКИ ФОРМЫ И ВЫБОРКИ ЭЛЕМЕНТОВ----------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::MyFormStudent_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewStudent->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "student_id, student_name, student_surname, student_patronymic, group_name, student_record_book, student_address";
    String^ FROM = "student INNER JOIN group_t ON student.group_id = group_t.group_id";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM); //вызов предыдущей команды

    while (dbReader->Read())
    {
        dataGridViewStudent->Rows->Add(
            dbReader[0],
            dbReader[1],
            dbReader[2],
            dbReader[3],
            dbReader[4],
            dbReader[5],
            dbReader[6]);//заносим строки в таблицу
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

    //Закрываем соединение
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::SelectDataGridItem(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count == 0)
        return;

    int index = dataGridViewStudent->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewStudent->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxId->Text         = dataGridViewStudent->Rows[index]->Cells[0]->Value->ToString();
    textBoxName->Text       = dataGridViewStudent->Rows[index]->Cells[1]->Value->ToString();
    textBoxSurname->Text    = dataGridViewStudent->Rows[index]->Cells[2]->Value->ToString();
    textBoxPatronymic->Text = dataGridViewStudent->Rows[index]->Cells[3]->Value->ToString();
    domainUpDownGroup->Text = dataGridViewStudent->Rows[index]->Cells[4]->Value->ToString();
    textBoxRecordBook->Text = dataGridViewStudent->Rows[index]->Cells[5]->Value->ToString();
    textBoxAddress->Text    = dataGridViewStudent->Rows[index]->Cells[6]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::dataGridViewStudent_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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

    textBoxId->Text = dataGridViewStudent->Rows[index]->Cells[0]->Value->ToString();
    textBoxName->Text = dataGridViewStudent->Rows[index]->Cells[1]->Value->ToString();
    textBoxSurname->Text = dataGridViewStudent->Rows[index]->Cells[2]->Value->ToString();
    textBoxPatronymic->Text = dataGridViewStudent->Rows[index]->Cells[3]->Value->ToString();
    domainUpDownGroup->Text = dataGridViewStudent->Rows[index]->Cells[4]->Value->ToString();
    textBoxRecordBook->Text = dataGridViewStudent->Rows[index]->Cells[5]->Value->ToString();
    textBoxAddress->Text = dataGridViewStudent->Rows[index]->Cells[6]->Value->ToString();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::ClearTextBox()
{
    textBoxId->Text         = nullptr;
    textBoxName->Text       = nullptr;
    textBoxSurname->Text    = nullptr;
    textBoxPatronymic->Text = nullptr;
    domainUpDownGroup->Text = domainUpDownGroup->Items[0]->ToString();
    textBoxRecordBook->Text = nullptr;
    textBoxAddress->Text    = nullptr;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    int index = dataGridViewStudent->SelectedCells[0]->RowIndex;

    auto rows = dataGridViewStudent->Rows;
    int count_row = rows->Count - 1;
    String^ selecting_rows = domainUpDownGroup->Text;

    for (int i = 0; i < count_row; i++)
        rows[i]->Visible = true;

    if (selecting_rows == "Все")
        return;

    for (int i = 0; i < count_row; i++)
        if (rows[i]->Cells["Group"]->Value->ToString() != selecting_rows && index != i)
            rows[i]->Visible = false;

    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::buttonUpdateGroupList_Click(System::Object^ sender, System::EventArgs^ e)
{
    domainUpDownGroup->Items->Clear();
    domainUpDownGroup->Items->Add("Все");

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_name";
    String^ FROM = "group_t";

    auto dbReader = SelectRow(dbConnection, SELECT, FROM);

    while (dbReader->Read())
        domainUpDownGroup->Items->Add(dbReader[0]);

    //закрываем соединения
    dbReader->Close();

    domainUpDownGroup->Text = domainUpDownGroup->Items[0]->ToString();

    dbConnection->Close();

    return System::Void();
}


/*------------------------------КНОПКИ ДОБАВЛЕНИЯ, УДАЛЕНИЯ, ИЗМЕНЕНИЯ---------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ student_name    = "'" + textBoxName->Text->ToString() + "'";
    String^ student_surname = "'" + textBoxSurname->Text->ToString() + "'";
    String^ student_patronymic = "'" + textBoxPatronymic->Text->ToString() + "'";
    String^ student_record_book = "'" +textBoxRecordBook->Text->ToString() + "'";
    String^ student_address = "'" + textBoxAddress->Text->ToString() + "'";
    String^ student_group = "'" + domainUpDownGroup->Text + "'";////;

    if (String::IsNullOrEmpty(student_name->Trim('\''))) {
        MessageBox::Show("Введите имя студента!", "Внимание!");
        textBoxName->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_surname->Trim('\''))) {
        MessageBox::Show("Введите фамилию студента!", "Внимание!");
        textBoxName->Focus();
        return;
    }
    
    if (String::IsNullOrEmpty(student_patronymic->Trim('\''))) {
        MessageBox::Show("Введите отчество студента!", "Внимание!");
        textBoxPatronymic->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_record_book->Trim('\''))) {
        MessageBox::Show("Введите номер заетной книжки!", "Внимание!");
        textBoxRecordBook->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_address->Trim('\''))) {
        MessageBox::Show("Введите адрес сиудента!", "Внимание!");
        textBoxRecordBook->Focus();
        return;
    }

    if (student_group == "'Все'") {
        MessageBox::Show("Выберите группу!", "Внимание!");
        domainUpDownGroup->Focus();
        return;
    }

    String^ group_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_id";
    String^ FROM = "group_t";
    String^ WHERE = "group_name LIKE " + student_group;
    String^ TABLE;
    String^ COLUMN;
    String^ VALUES;

    group_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "student";
    COLUMN = "student_name, student_surname, student_patronymic, student_record_book, student_address, group_id";
    VALUES = 
        student_name + ", " +
        student_surname + ", " +
        student_patronymic + ", " +
        student_record_book + ", " +
        student_address + ", " +
        group_id;

    if (!InsertRow(dbConnection, TABLE, COLUMN, VALUES))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormStudent_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 1) {
        MessageBox::Show("Выберете в таблице одну строку которую хотите изменить","Внимание!");
        return;
    }

    String^ student_id = textBoxId->Text;
    String^ student_name = "'" + textBoxName->Text->ToString() + "'";
    String^ student_surname = "'" + textBoxSurname->Text->ToString() + "'";
    String^ student_patronymic = "'" + textBoxPatronymic->Text->ToString() + "'";
    String^ student_record_book = "'" + textBoxRecordBook->Text->ToString() + "'";
    String^ student_address = "'" + textBoxAddress->Text->ToString() + "'";
    String^ student_group = "'" + domainUpDownGroup->Text + "'";////;

    if (String::IsNullOrEmpty(student_name->Trim('\''))) {
        MessageBox::Show("Введите имя студента!", "Внимание!");
        textBoxName->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_surname->Trim('\''))) {
        MessageBox::Show("Введите фамилию студента!", "Внимание!");
        textBoxName->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_patronymic->Trim('\''))) {
        MessageBox::Show("Введите отчество студента!", "Внимание!");
        textBoxPatronymic->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_record_book->Trim('\''))) {
        MessageBox::Show("Введите номер заетной книжки!", "Внимание!");
        textBoxRecordBook->Focus();
        return;
    }

    if (String::IsNullOrEmpty(student_address->Trim('\''))) {
        MessageBox::Show("Введите адрес сиудента!", "Внимание!");
        textBoxRecordBook->Focus();
        return;
    }

    if (student_group == "'Все'") {
        MessageBox::Show("Выберите группу!", "Внимание!");
        domainUpDownGroup->Focus();
        return;
    }

    String^ group_id;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "group_id";
    String^ FROM = "group_t";
    String^ WHERE = "group_name LIKE " + student_group;
    String^ TABLE;
    String^ SET;

    group_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "student";
    SET = 
        "student_name = " + student_name + ", " +
        "student_surname = " + student_surname + ", " +
        "student_patronymic = " + student_patronymic + ", " +
        "studen_record_book = " + student_record_book + ", " +
        "student_address = " + student_address + ", " +
        "group_id = " + group_id;
    WHERE = "student_id = " + student_id;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновлена!");

    MyFormStudent_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();


    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 1) {
        MessageBox::Show("Выберете в таблице одну строку которую хотите изменить", "Внимание!");
        return;
    }

    if (dataGridViewStudent->Rows->Count - 1 == dataGridViewStudent->SelectedRows[0]->Index) //проверяем чтобы это не была не последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    String^ student_id = textBoxId->Text;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "student";
    String^ WHERE = "student_id = " + student_id;


    if (!DeleteRow(dbConnection, FROM, WHERE))
        MessageBox::Show("Ошибка в момент удаления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно удалена!");

    MyFormStudent_Load(nullptr, nullptr);

    //закрываем соединения
    dbConnection->Close();
    return System::Void();
}

/*----------------------------------------ЗАВЕРШЕНИЕ РАБОТЫ--------------------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::MyFormStudent_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

