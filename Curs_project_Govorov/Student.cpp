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

/*--------------------------------------------------- ÕŒœ » œ≈–≈ Àﬁ◊≈Õ»ﬂ Ã≈∆ƒ” ‘Œ–Ã¿Ã»-------------------------------------------------*/

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

System::Void CursprojectGovorov::MyFormStudent::SubjectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubject^ form = gcnew MyFormSubject(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------—Œ¡€“ﬂ» «¿√–”« » ‘Œ–Ã€ » ¬€¡Œ– » ›À≈Ã≈Õ“Œ¬----------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::MyFormStudent_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::SelectDataGridItem(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

/*------------------------------ ÕŒœ » ƒŒ¡¿¬À≈Õ»ﬂ, ”ƒ¿À≈Õ»ﬂ, »«Ã≈Õ≈Õ»ﬂ---------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormStudent::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

/*----------------------------------------«¿¬≈–ÿ≈Õ»≈ –¿¡Œ“€--------------------------------------------------------------*/

System::Void CursprojectGovorov::MyFormStudent::MyFormStudent_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

