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

System::Void CursprojectGovorov::MyFormInputMarks::SubjectToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyFormSubject^ form = gcnew MyFormSubject(this);
    form->Show();
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

/*-------------------------------—Œ¡€“ﬂ» «¿√–”« » ‘Œ–Ã€ » ¬€¡Œ– » ›À≈Ã≈Õ“Œ¬----------------------------------------------*/

System::Void CursprojectGovorov::MyFormInputMarks::MyFormStudent_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::SelectDataGridItem(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

/*------------------------------ ÕŒœ » ƒŒ¡¿¬À≈Õ»ﬂ, ”ƒ¿À≈Õ»ﬂ, »«Ã≈Õ≈Õ»ﬂ---------------------------------------------------*/

System::Void CursprojectGovorov::MyFormInputMarks::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::buttonChange_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void CursprojectGovorov::MyFormInputMarks::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

/*----------------------------------------«¿¬≈–ÿ≈Õ»≈ –¿¡Œ“€--------------------------------------------------------------*/

System::Void CursprojectGovorov::MyFormInputMarks::MyFormInputMarks_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}


