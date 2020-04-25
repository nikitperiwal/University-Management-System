#ifndef MARKS_H
#define MARKS_H

#include <QString>
#include <QtSql>
#include <QtWidgets>

class Marks
{
private:
    QString usn;
    QString name;
    QString dept;
    int     year;
    QString subcode;
    int     credit;
    int     cie1;
    int     cie2;
    int     cie3;
    int     assignment;
    int     groupproject;
    int     see;
    double  attendance;
    QString grade;

public:
    Marks(){}
    Marks(QString Usn,
          QString Name,
          QString Dept,
          QString Year,
          QString Subcode,
          QString Credit,
          QString Cie1,
          QString Cie2,
          QString Cie3,
          QString Assignment,
          QString Groupproject,
          QString See,
          QString Attendance)
    {
        usn          = Usn;
        name         = Name;
        dept         = Dept;
        year         = Year.toInt();
        subcode      = Subcode;
        credit       = Credit.toInt();
        cie1         = Cie1.toInt();
        cie2         = Cie2.toInt();
        cie3         = Cie3.toInt();
        assignment   = Assignment.toInt();
        groupproject = Groupproject.toInt();
        see          = See.toInt();
        attendance   = Attendance.toDouble();
    }

    // Function to calculate the grade they secured
    void calculateGrade(){
        float total = 0;
        float totalinternal = 0;

        // Best 2 of 3 internal Marks
        if(cie3<cie1 && cie3<cie2)
            totalinternal = (cie1+cie2);
        else if(cie2<cie1 && cie2<cie3)
            totalinternal = (cie1+cie3);
        else
            totalinternal = (cie2+cie3);

        totalinternal = totalinternal * 0.8;
        totalinternal += assignment;
        totalinternal += groupproject;

        total += totalinternal;
        total += see * 0.5;

        if(see<40)
            grade="F";
        else if(totalinternal<20)
            grade="NSC";
        else if(attendance<75)
            grade="NSA";
        else if(total>=90)
            grade="S";
        else if(total>=80)
            grade="A";
        else if(total>=70)
            grade="B";
        else if(total>=60)
            grade="C";
        else if(total>=50)
            grade="D";
        else if(total>=40)
            grade="E";
        else
            grade="F";
    }

    QSqlQuery addMarks();
    QSqlQuery getMarksRecord(QString USN);
    QSqlQuery getMarksList(QString DEPT, QString YEAR);
    QSqlQuery getAllMarksRecord(QString DEPT);

};

#endif // MARKS_H
