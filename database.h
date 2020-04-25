#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    // Default Constructor
    Database() {}

    // A function to create database and the tables which returns the SQL database error information
    QSqlError initDb() {

        // This code connects to the database 'database.db' using SQLITE
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("database.db");

        // Checks if we are able to open the database.
        if(!db.open()){
            return db.lastError();
        }

        QSqlQuery query;
        // CREATE TABLE STUDENT
        query.exec("create table student (usn int primary key, "
                                         "name varchar, "
                                         "dob varchar, "
                                         "gender varchar, "
                                         "mobile varchar, "
                                         "email varchar, "
                                         "curAddress varchar, "
                                         "Address varchar, "
                                         "fatherName varchar, "
                                         "motherName varchar, "
                                         "parentPh varchar, "
                                         "dept varchar )");


        // CREATE TABLE TEACHER
        query.exec("create table teacher (id int primary key, "
                                         "name varchar, "
                                         "dob varchar, "
                                         "mobile varchar, "
                                         "email varchar, "
                                         "Address varchar, "
                                         "emcontact varchar, "
                                         "emphone varchar, "
                                         "experience int, "
                                         "qualification varchar, "
                                         "department varchar, "
                                         "position varchar )");


        // CREATE TABLE MANAGEMENT
        query.exec("create table management (id int primary key, "
                                           "name varchar, "
                                           "dob varchar, "
                                           "mobile varchar, "
                                           "email varchar, "
                                           "Address varchar, "
                                           "emcontact varchar, "
                                           "emphone varchar, "
                                           "experience int, "
                                           "qualification varchar, "
                                           "department varchar, "
                                           "position varchar )");


        // CREATE TABLE MARKS
        query.exec("create table marks (usn varchar, "
                                           "name varchar, "
                                           "dept varchar, "
                                           "year int, "
                                           "subcode varchar, "
                                           "credit int, "
                                           "cie1 int, "
                                           "cie2 int, "
                                           "cie3 int, "
                                           "assignment int, "
                                           "groupproject int, "
                                           "see int, "
                                           "attendance int, "
                                           "grade varchar, "
                                           "PRIMARY KEY(usn, subcode))");
        return db.lastError();
    }

};

#endif // DATABASE_H
