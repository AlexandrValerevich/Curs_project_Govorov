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

System::Void CursprojectGovorov::MyFormInputMarks::ListStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudent^ form = gcnew MyFormStudent(this->Location);
    form->Show();
    this->Hide();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::StudentGrantToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudentGrant^ form = gcnew MyFormStudentGrant(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::AvarageMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudentAvgMark^ form = gcnew MyFormStudentAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::ListUnsucsessfulStudentToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormStudentUnsucsessful^ form = gcnew MyFormStudentUnsucsessful(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::AddMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::AvarageMarksSubjectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubjectAvgMark^ form = gcnew  MyFormSubjectAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::AvarageMarksGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormGroupAvgMark^ form = gcnew  MyFormGroupAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::CountUnsucsessfulMarksToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormUnsuccessfuAvgMark^ form = gcnew  MyFormUnsuccessfuAvgMark(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::FacultiesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormFaculties^ form = gcnew  MyFormFaculties(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::ChairToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormChair^ form = gcnew MyFormChair(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::SpecialityToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSpeciality^ form = gcnew MyFormSpeciality(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::GroupsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormGroup^ form = gcnew MyFormGroup(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::SubjectByGroupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubject^ form = gcnew MyFormSubject(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::SubjectListToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubjectList^ form = gcnew MyFormSubjectList(this);
    form->Show();
    return System::Void();
}

/*-------------------------------СОБЫТЯИ ЗАГРУЗКИ ФОРМЫ И ВЫБОРКИ ЭЛЕМЕНТОВ----------------------------------------------*/

System::Void CursprojectGovorov::MyFormInputMarks::MyFormStudent_Load(System::Object^ sender, System::EventArgs^ e)
{
    dataGridViewStudent->Rows->Clear();

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "mark_id, student_name, student_surname, group_name, subject_name, mark_value, type_recording, type_session";
    String^ FROM = 
        "((student INNER JOIN group_t ON student.group_id = group_t.group_id)"+
        " INNER JOIN mark ON student.student_id = mark.student_id) INNER JOIN subject ON mark.subject_id = subject.subject_id";

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
            dbReader[6],
            dbReader[7]);//заносим строки в таблицу
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

System::Void CursprojectGovorov::MyFormInputMarks::dataGridViewStudent_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count == 0)
        return;

    int index = dataGridViewStudent->SelectedRows[0]->Index; //берем индекс первой выбранной строки

    if (dataGridViewStudent->Rows->Count - 1 == index) //проверяем чтобы это не юыла последняя строка
    {
        ClearTextBox(); //очистка полей ввода
        return;
    }

    textBoxId->Text = dataGridViewStudent->Rows[index]->Cells[0]->Value->ToString();
    textBoxMark->Text = dataGridViewStudent->Rows[index]->Cells["Mark"]->Value->ToString();
    domainUpDownGroup->Text = dataGridViewStudent->Rows[index]->Cells["Group"]->Value->ToString();
    domainUpDownStudent->Text =
        dataGridViewStudent->Rows[index]->Cells["Name_student"]->Value->ToString() + " " 
        + dataGridViewStudent->Rows[index]->Cells["Surname_student"]->Value->ToString();
    domainUpDownSubject->Text = dataGridViewStudent->Rows[index]->Cells["Subject"]->Value->ToString();

    
    return System::Void();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::ClearTextBox()
{
    textBoxMark->Text = nullptr;
    textBoxId->Text = nullptr;
    domainUpDownGroup->SelectedIndex = 0;
    domainUpDownStudent->SelectedIndex = 0;
    domainUpDownSubject->SelectedIndex = 0;
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::domainUpDownGroup_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count >= 1)
        return;

    domainUpDownStudent->Items->Clear();
    domainUpDownSubject->Items->Clear();
    
    domainUpDownStudent->Items->Add("Все");
    domainUpDownSubject->Items->Add("Все");

    domainUpDownStudent->SelectedIndex = 0;
    domainUpDownSubject->SelectedIndex = 0;

    int count_row = dataGridViewStudent->Rows->Count - 1;

    for (size_t i = 0; i < count_row; i++)
        dataGridViewStudent->Rows[i]->Visible = true;

    if (domainUpDownGroup->Text == "Все")
        return;

    String^ group_name = "'" + domainUpDownGroup->Text + "'";

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT = "student_name& ' ' &student_surname";
    String^ FROM = "student";
    String^ WHERE = "group_id IN(SELECT group_id FROM group_t WHERE group_name LIKE" + group_name + " )";

    OleDbDataReader^ dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE); //вызов предыдущей команды

    while (dbReader->Read())
        domainUpDownStudent->Items->Add(dbReader[0]);
    
    dbReader->Close();

    SELECT = "subject_name";
    FROM = 
        "(subject INNER JOIN group_subject ON subject.subject_id = group_subject.subject_id)"+
        " INNER JOIN group_t ON group_t.group_id = group_subject.group_id";
    WHERE = "group_name LIKE " + group_name;
    
    dbReader = SelectRow(dbConnection, SELECT, FROM, WHERE); //вызов предыдущей команды

    while (dbReader->Read())
        domainUpDownSubject->Items->Add(dbReader[0]);

    dbReader->Close();
    dbConnection->Close();

    for (int i = 0; i < count_row; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Group"]->Value->ToString() != group_name->Trim('\''))
            dataGridViewStudent->Rows[i]->Visible = false;

    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::domainUpDownSubject_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count >= 1)
        return;

    String^ subject_name = domainUpDownSubject->Text;
    String^ group_name = domainUpDownGroup->Text;
    String^ student_name = domainUpDownStudent->Text;
    int count_rows = dataGridViewStudent->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
    {
        dataGridViewStudent->Rows[i]->Visible = true;
    }

    if (group_name == "Все")
        return;

    for (int i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Group"]->Value->ToString() != group_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    if (subject_name == "Все")
        return;

    for (int i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Subject"]->Value->ToString() != subject_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    if (student_name == "Все")
        return;

    for (int i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Name_student"]->Value->ToString() + " " + dataGridViewStudent->Rows[i]->Cells["Surname_student"]->Value->ToString()
            != student_name)
            dataGridViewStudent->Rows[i]->Visible = false;


    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::domainUpDownStudent_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count >= 1) 
        return;
    
    String^ subject_name = domainUpDownSubject->Text;
    String^ group_name = domainUpDownGroup->Text;
    String^ student_name = domainUpDownStudent->Text;
    int count_rows = dataGridViewStudent->Rows->Count - 1;

    for (size_t i = 0; i < count_rows; i++)
    {
        dataGridViewStudent->Rows[i]->Visible = true;
    }

    if (group_name == "Все")
        return;

    for (int i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Group"]->Value->ToString() != group_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    if (student_name == "Все")
        return;

    for (int i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Name_student"]->Value->ToString() + " " + dataGridViewStudent->Rows[i]->Cells["Surname_student"]->Value->ToString()
            != student_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    if (subject_name == "Все")
        return;

    for (int i = 0; i < count_rows; i++)
        if (dataGridViewStudent->Rows[i]->Cells["Subject"]->Value->ToString() != subject_name)
            dataGridViewStudent->Rows[i]->Visible = false;

    return System::Void();
}

/*------------------------------КНОПКИ ДОБАВЛЕНИЯ, УДАЛЕНИЯ, ИЗМЕНЕНИЯ---------------------------------------------------*/

System::Void CursprojectGovorov::MyFormInputMarks::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (domainUpDownGroup->SelectedIndex == 0) {
        MessageBox::Show("Выберите группу!","Внимание!");
        domainUpDownGroup->Focus();
        return;
    }

    if (domainUpDownStudent->SelectedIndex == 0) {
        MessageBox::Show("Выберите студента!", "Внимание!");
        domainUpDownStudent->Focus();
        return;
    }

    if (domainUpDownSubject->SelectedIndex == 0) {
        MessageBox::Show("Выберите предмет!", "Внимание!");
        domainUpDownSubject->Focus();
        return;
    }

    int mark;
    bool isValid = Int32::TryParse(textBoxMark->Text, mark);

    if (!isValid) {
        MessageBox::Show("Некорректный ввод оценки!", "Внимание!");
        textBoxMark->Focus();
        return;
    }

    if (mark < 0 || mark>10) {
        MessageBox::Show("Оценка должна быть от 0 до 10!", "Внимание!");
        textBoxMark->Focus();
        return;
    }

    String^ group_name ="'"+ domainUpDownGroup->Text +"'";
    String^ student_name = "'" + domainUpDownStudent->Text + "'";
    String^ subject_name = "'" + domainUpDownSubject->Text + "'";
    String^ recording_name = "'" + domainUpDownRecording->Text + "'";
    String^ seasson_name = "'" + domainUpDownSeasson->Text + "'";

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ TABLE = "mark";
    String^ COLUMN = "student_id, subject_id, mark_value, type_recording, type_session";
    String^ SELECT = "student_id, subject_id, " + mark + ", " + recording_name + ", " + seasson_name;   
    String^ FROM = "student, subject";
    String^ WHERE =
        " student_name & ' ' & student_surname LIKE " + student_name +
        " AND group_id IN(SELECT group_id FROM group_t WHERE group_name LIKE " + group_name + ")"+
        " AND subject_name LIKE " + subject_name;

    if (!InsertRow(dbConnection, TABLE, COLUMN, SELECT, FROM, WHERE))
        MessageBox::Show("Ошибка в момент добавления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно добавлена!");

    MyFormStudent_Load(nullptr, nullptr);
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите одну запись которую хотите изменить!", "Внимание!");
        return;
    }

    if (dataGridViewStudent->Rows->Count - 1 == dataGridViewStudent->SelectedRows[0]->Index) //проверяем чтобы это не была не последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    if (domainUpDownGroup->SelectedIndex == 0) {
        MessageBox::Show("Выберите группу!", "Внимание!");
        domainUpDownGroup->Focus();
        return;
    }

    if (domainUpDownStudent->SelectedIndex == 0) {
        MessageBox::Show("Выберите студента!", "Внимание!");
        domainUpDownStudent->Focus();
        return;
    }

    if (domainUpDownSubject->SelectedIndex == 0) {
        MessageBox::Show("Выберите предмет!", "Внимание!");
        domainUpDownSubject->Focus();
        return;
    }

    int mark;
    bool isValid = Int32::TryParse(textBoxMark->Text, mark);

    if (!isValid) {
        MessageBox::Show("Некорректный ввод оценки!", "Внимание!");
        textBoxMark->Focus();
        return;
    }

    if (mark < 0 || mark>10) {
        MessageBox::Show("Оценка должна быть от 0 до 10!", "Внимание!");
        textBoxMark->Focus();
        return;
    }

    String^ mark_id = textBoxId->Text;
    String^ group_name = "'" + domainUpDownGroup->Text + "'";
    String^ student_name = "'" + domainUpDownStudent->Text + "'";
    String^ subject_name = "'" + domainUpDownSubject->Text + "'";
    String^ recording_name = "'" + domainUpDownRecording->Text + "'";
    String^ seasson_name = "'" + domainUpDownSeasson->Text + "'";

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ SELECT;
    String^ FROM;
    String^ TABLE = "mark";
    String^ SET = "student_id, subject_id, mark_value, type_recording, type_session";
    String^ WHERE; /*"mark_id = " + mark_id;*/

    SELECT = "student_id";
    FROM = "student";
    WHERE =
        " student_name & ' ' & student_surname LIKE " + student_name +
        " AND group_id IN(SELECT group_id FROM group_t WHERE group_name LIKE " + group_name + ")";

    String^ student_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    SELECT = "subject_id";
    FROM = "subject";
    WHERE =" subject_name LIKE " + subject_name;
    
    String^ subject_id = SelectID(dbConnection, SELECT, FROM, WHERE);

    TABLE = "mark";
    SET = "student_id = "+student_id+", subject_id = "+subject_id+", mark_value = "+mark+", type_recording = "+recording_name+", type_session = "+seasson_name;
    WHERE = "mark_id = " + mark_id;

    if (!UpdateRow(dbConnection, TABLE, SET, WHERE))
        MessageBox::Show("Ошибка в момент обновления!", "Внимание!");
    else
        MessageBox::Show("Запись успешно обновление!");

    MyFormStudent_Load(nullptr, nullptr);

    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridViewStudent->SelectedRows->Count != 1) {
        MessageBox::Show("Выберите одну запись которую хотите изменить!", "Внимание!");
        return;
    }

    if (dataGridViewStudent->Rows->Count - 1 == dataGridViewStudent->SelectedRows[0]->Index) //проверяем чтобы это не была не последняя строка
    {
        MessageBox::Show("Это не строка!", "Внимание!");
        return;
    }

    String^ mark_id = textBoxId->Text;

    String^ connectionString = StringConnection(); //строка подключения
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();//открываем соединение

    String^ FROM = "mark";
    String^ WHERE = "mark_id =" + mark_id;

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

System::Void CursprojectGovorov::MyFormInputMarks::MyFormInputMarks_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}


