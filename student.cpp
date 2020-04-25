#include "student.h"

void Student::addStudent()
{
    // Function to insert all data into the table
    QString statement = "INSERT INTO student (usn, name, dob, gender, mobile, email, curAddress,"
                        "address, fatherName, motherName, parentPh, dept) "
                        "VALUES ('"+ usn +
                        "', '" + name          +
                        "', '" + dob           +
                        "', '" + gender        +
                        "', '" + mobile        +
                        "', '" + email         +
                        "', '" + curr_address  +
                        "', '" + perm_address  +
                        "', '" + father_name   +
                        "', '" + mother_name   +
                        "', '" + parent_mobile +
                        "', '" + department    +  "')";

    QSqlQuery query;

    // Trying to insert data into the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to add the record", "New Student could not be added.  Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
}

void Student::updateStudent()
{
    // Function to update the data into the table
    QString statement = "UPDATE student SET name = '" + name +
            "', dob = '"        + dob           +
            "', gender = '"     + gender        +
            "', mobile = '"     + mobile        +
            "', email = '"      + email         +
            "', curAddress = '" + curr_address  +
            "', address = '"    + perm_address  +
            "', fatherName = '" + father_name   +
            "', motherName = '" + mother_name   +
            "', parentPh = '"   + parent_mobile +
            "', dept = '"       + department    +
            "'  WHERE usn = '"  + usn           + "'";
    QSqlQuery query;

    // Trying to update the data into the table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to update the record", "Student record could not be updated. Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
}

void Student::removeStudent(QString USN)
{
    // Function to delete the data from the table
    QString statement = "DELETE FROM student WHERE usn = '" + USN + "'";
    QSqlQuery query;
    query.exec(statement);

    // Trying to delete the data into table and storing the result in res
    bool res = query.exec(statement);

    // Sending a message to user if it has failed
    if(!res){
        QMessageBox msgBox(QMessageBox::Critical, "Failed to delete the record", "Student record could not be deleted. Please try again!",QMessageBox::Ok);
        msgBox.exec();
    }
}


QSqlQuery Student::getStudentRecord(QString USN)
{
    // Query to display the students based on USN
    QString statement = "Select * FROM student WHERE usn = '" + USN + "'";
    QSqlQuery query;
    query.exec(statement);
    return query;
}

QSqlQuery Student::getStudentList(QString DEPT, QString YEAR)
{
    // Query to display the students based on the dept and year
    QString statement = "Select usn, name FROM student WHERE ";
    if(DEPT.compare("Select"))
        statement += " dept = '" + DEPT + "' AND ";
    statement += " usn LIKE '___"+YEAR.right(2)+"_____' ";
    QSqlQuery query;
    query.exec(statement);
    return query;
}


QSqlQuery Student::getAllStudentRecord(QString DEPT, QString SEARCH)
{
    // Query to display all the students or based on search
    QString statement = "Select * FROM student WHERE ";
    if(DEPT.compare("Select"))
        statement += " dept = '" + DEPT + "' AND ";
    statement += " (usn LIKE '%"+SEARCH+"%' OR name LIKE '%"+SEARCH+"%') ";
    statement += " ORDER BY dept ASC , usn ASC";
    QSqlQuery query;
    query.exec(statement);
    return query;
}
