#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QString>
#include <QtSql>
#include <QtWidgets>


class Management
{
private:
    QString id;
    QString name;
    QString dob;
    QString mobile;
    QString email;
    QString address;
    QString emcontact_name;
    QString emcontact_mobile;
    QString experience;
    QString qualification;
    QString department;
    QString position;
public:

    Management() {};

    Management(
            QString Id,
            QString Name,
            QString Dob,
            QString Mobile,
            QString Email,
            QString Address,
            QString Emcontact_name,
            QString Emcontact_mobile,
            QString Experience,
            QString Qualification,
            QString Department,
            QString Position)
    {
        id               = Id;
        name             = Name;
        dob              = Dob;
        mobile           = Mobile;
        email            = Email;
        address          = Address;
        emcontact_name   = Emcontact_name;
        emcontact_mobile = Emcontact_mobile;
        experience       = Experience;
        qualification    = Qualification;
        position         = Position;
        department       = Department;
    }

    void addManagement();
    void updateManagement();
    void removeManagement(QString ID);
    QSqlQuery getManagementRecord(QString ID);
    QSqlQuery getAllManagementRecord(QString SEARCH);
};
#endif
