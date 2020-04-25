#include "management.h"

void Management::addManagement()
{
    // Query used to insert the values into the database
    QString statement = "INSERT INTO Management (id, name, dob, mobile, email, address,"
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
                    "', '" + position         +"')";

    QSqlQuery query;

    // Trying to insert data into the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to add the record", "New Member could not be added. Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
}

void Management::updateManagement()
{
    // Query used to update the values in the database
    QString statement = "UPDATE Management SET name = '" + name +
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

    // Trying to update the data into the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to update the record", "Member could not be edited. Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
}

void Management::removeManagement(QString ID)
{
    // Query used to delete the selected value in the database
    QString statement = "DELETE FROM Management WHERE id = '" + ID + "'";
    QSqlQuery query;

    // Trying to delete the data from the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to delete the record", "Member could not be deleted. Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
}


QSqlQuery Management::getManagementRecord(QString ID)
{
    // Query used to display the members of management based on ID
    QString statement = "Select * FROM Management WHERE id = '" + ID + "'";
    QSqlQuery query;
    query.exec(statement);
    return query;
}


QSqlQuery Management::getAllManagementRecord(QString SEARCH)
{
    // Query used to display all members of management or based on search input
    QString statement = "Select * FROM Management WHERE ";
    statement += " (id LIKE '%"+SEARCH+"%' OR name LIKE '%"+SEARCH+"%' OR position LIKE '%"+SEARCH+"%')";
    statement += " ORDER BY id ASC";
    QSqlQuery query;
    query.exec(statement);
    return query;
}
