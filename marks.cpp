#include "marks.h"

QSqlQuery Marks::addMarks()
{
    // Fuction to insert marks into the table
    calculateGrade();
    QString statement = "INSERT INTO marks (usn, name, dept, year, subcode, credit, cie1, cie2, cie3, assignment, groupproject, see, attendance, grade) "
                        "VALUES ('"+ usn+
            "', '" + name                          +
            "', '" + dept                          +
            "', "  + QString::number(year)         +
            ", '"  + subcode                       +
            "', "  + QString::number(credit)       +
            ",  "  + QString::number(cie1)         +
            ",  "  + QString::number(cie2)         +
            ",  "  + QString::number(cie3)         +
            ",  "  + QString::number(assignment)   +
            ",  "  + QString::number(groupproject) +
            ",  "  + QString::number(see)          +
            ",  "  + QString::number(attendance)   +
            ", '"  + grade                         +  "')";
    QSqlQuery query;

    // Trying to add the data in the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to delete the record", "Member could not be deleted. Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
    return query;
}

QSqlQuery Marks::getMarksRecord(QString usn)
{
    // Query to display the marks based on USN
    QString statement = "Select * FROM  marks WHERE usn = '" + usn + "'";
    QSqlQuery query;
    query.exec(statement);
    return query;
}

QSqlQuery Marks::getMarksList(QString dept, QString year)
{
    // Query to display all the marks or based on year and/or department
    QString statement;
    if(dept.compare("Select"))
        statement = "SELECT DISTINCT usn FROM marks WHERE dept = '" + dept + "' AND year ='"+year+"' ";
    else
        statement = "SELECT DISTINCT usn FROM marks WHERE year ='"+year+"' ";

    QSqlQuery query;
    query.exec(statement);
    return query;
}

QSqlQuery Marks::getAllMarksRecord(QString dept)
{
    // Query to display all the marks or based on department
    QString statement;
    if(dept.compare("Select"))
        statement = "Select * FROM marks WHERE dept = '" + dept + "' ORDER BY dept ASC , usn ASC";
    else
        statement = "Select * FROM marks ORDER BY dept ASC , usn ASC";

    QSqlQuery query;
    query.exec(statement);
    return query;
}
