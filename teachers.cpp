#include "teachers.h"

void Teacher::addTeacher()
{
    // Query to insert marks into the table
    QString statement = "INSERT INTO teacher (id, name, dob, mobile, email, address,"
                    "emcontact, emphone, experience, qualification, department, position) "
                    "VALUES "
                       "('"+ id               +
                    "', '" + name             +
                    "', '" + dob              +
                    "', '" + mobile           +
                    "', '" + email            +
                    "', '" + address          +
                    "', '" + emcontact_name   +
                    "', '" + emcontact_mobile +
                    "', '" + experience       +
                    "', '" + qualification    +
                    "', '" + department       +
                    "', '" + position         + "')";

    QSqlQuery query;

    // Trying to insert data into the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to add the record", "New Teacher could not be added. Please try again!", QMessageBox::Ok);
        msgBox.exec();
    }
}

void Teacher::updateTeacher()
{
    // Query used to update the values in the database
    QString statement = "UPDATE Teacher SET name = '" + name +
                "', dob = '"           + dob              +
                "', mobile = '"        + mobile           +
                "', email = '"         + email            +
                "', address = '"       + address          +
                "', emcontact = '"     + emcontact_name   +
                "', emphone = '"       + emcontact_mobile +
                "', experience = '"    + experience       +
                "', qualification = '" + qualification    +
                "', position = '"      + position         +
                "', department = '"    + department       +
                "'  WHERE id = '"      + id               +"'";
    QSqlQuery query;

    // Trying to update the data in the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to update the record", "Teacher record could not be edited. Please try again!", QMessageBox::Ok);
        msgBox.exec();
    }
}

void Teacher::removeTeacher(QString ID)
{
    // Query used to delete the selected value in the database.
    QString statement = "DELETE FROM Teacher WHERE id = '" + ID + "'";
    QSqlQuery query;

    // Trying to remove the data from table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to delete the record", "Teacher record could not be deleted! Please try again!", QMessageBox::Ok);
        msgBox.exec();
    }
}


QSqlQuery Teacher::getTeacherRecord(QString ID)
{
    // Query used to display the Teachers based on ID
    QString statement = "Select * FROM Teacher WHERE id = '" + ID + "'";
    QSqlQuery query;
    query.exec(statement);
    return query;
}


QSqlQuery Teacher::getAllTeacherRecord(QString DEPT, QString SEARCH)
{
    // Query used to display all the Teachers based on search
    QString statement = "Select * FROM Teacher WHERE ";
    if(DEPT.compare("Select"))
        statement += " department = '" + DEPT + "' AND ";
    statement += " (id LIKE '%"+SEARCH+"%' OR name LIKE '%"+SEARCH+"%' OR position LIKE '%"+SEARCH+"%')";
    statement += " ORDER BY department ASC , id ASC";
    QSqlQuery query;
    query.exec(statement);
    return query;
}
