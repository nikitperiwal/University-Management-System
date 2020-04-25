#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QtSql>
#include <QtWidgets>

class Student
{
private:
    QString usn;
    QString name;
    QString dob;
    QString gender;
    QString mobile;
    QString email;
    QString curr_address;
    QString perm_address;
    QString father_name;
    QString mother_name;
    QString parent_mobile;
    QString department;

public:
    Student() {};
    Student(
            QString Usn,
            QString Name,
            QString Dob,
            QString Gender,
            QString Mobile,
            QString Email,
            QString Curr_address,
            QString Perm_address,
            QString Father_name,
            QString Mother_name,
            QString Parent_mobile,
            QString Department)
    {
        usn           = Usn;
        name          = Name;
        dob           = Dob;
        gender        = Gender;
        mobile        = Mobile;
        email         = Email;
        curr_address  = Curr_address;
        perm_address  = Perm_address;
        father_name   = Father_name;
        mother_name   = Mother_name;
        parent_mobile = Parent_mobile;
        department    = Department;
    }
    void addStudent();
    void updateStudent();
    void removeStudent(QString USN);

    QSqlQuery getStudentRecord(QString USN);
    QSqlQuery getStudentList(QString DEPT, QString YEAR);
    QSqlQuery getAllStudentRecord(QString DEPT, QString SEARCH);
};

#endif
