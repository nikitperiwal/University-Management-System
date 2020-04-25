#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

#include "management.h"
#include "teachers.h"
#include "student.h"
#include "marks.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Codes that are meant to be initalized at the beggining
    ui->setupUi(this);
    ui->tabStudentFaculty->setCurrentIndex(0);
    ui->tabStudentAcademic->setCurrentIndex(0);

    ui->widgetNewMember->hide();
    ui->widgetTeacher->hide();
    ui->btnMemberMaximize->hide();
    ui->btnTeacherMaximize->hide();


    // Codes to check the input of user using regular expression

    const QRegularExpression phRe("^[1-9][0-9]{9}$");                                   // The RegEx to check Phone numbers.
    const QRegularExpression usnRe("^[1-9][a-zA-Z]{2}[0-9]{2}[a-zA-Z]{2}[0-9]{3}$");    // The RegEx to check the USN.
    const QRegularExpression subCodeRe("^[a-zA-Z]{2,3}[1-9]{2}$");                      // The RegEx to check the Subject Code.

    // Assigning the validator to check the input for the text boxes.
    ui->txtStudentPh->setValidator(new QRegularExpressionValidator(phRe, this));
    ui->txtStudentParentPh->setValidator(new QRegularExpressionValidator(phRe, this));
    ui->txtTeacherPh->setValidator(new QRegularExpressionValidator(phRe, this));
    ui->txtTeacherEmPh->setValidator(new QRegularExpressionValidator(phRe, this));
    ui->txtMemberPh->setValidator(new QRegularExpressionValidator(phRe, this));
    ui->txtMemberEmPh->setValidator(new QRegularExpressionValidator(phRe, this));

    //ui->txtSubCode->setValidator(new QRegularExpressionValidator(subCodeRe, this));
    ui->txtStudentUSN->setValidator(new QRegularExpressionValidator(usnRe, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}


// Functions to update the Gui with data.
void MainWindow::tableStudentInput()
{
    // Code to display the student details from the table
    Student obj;
    QSqlQuery query;
    query = obj.getAllStudentRecord(ui->cbxStudentDept->currentText(), ui->txtStudentSearch->text());
    ui->tableStudentInfo->setRowCount(0);
    int rowPos = 0;
    while(query.next()){
        ui->tableStudentInfo->insertRow(rowPos);
        ui->tableStudentInfo->setItem(rowPos, 0, new QTableWidgetItem(query.value(11).toString()));
        ui->tableStudentInfo->setItem(rowPos, 1, new QTableWidgetItem(query.value(0).toString()));
        ui->tableStudentInfo->setItem(rowPos, 2, new QTableWidgetItem(query.value(1).toString()));
        ui->tableStudentInfo->setItem(rowPos, 3, new QTableWidgetItem(query.value(2).toString()));
        ui->tableStudentInfo->setItem(rowPos, 4, new QTableWidgetItem(query.value(3).toString()));
        ui->tableStudentInfo->setItem(rowPos, 5, new QTableWidgetItem(query.value(4).toString()));
        ui->tableStudentInfo->setItem(rowPos, 6, new QTableWidgetItem(query.value(5).toString()));
        ui->tableStudentInfo->setItem(rowPos, 7, new QTableWidgetItem(query.value(7).toString()));
        rowPos++;
    }
}

void MainWindow::tableTeacherInput()
{
    // Code to display the Teacher details
    Teacher obj;
    QSqlQuery query;
    query = obj.getAllTeacherRecord(ui->cbxTeacherDept->currentText(), ui->txtTeacherSearch->text());
    ui->tableTeacher->setRowCount(0);
    int rowPos = 0;
    while(query.next()){
        ui->tableTeacher->insertRow(rowPos);
        ui->tableTeacher->setItem(rowPos, 0, new QTableWidgetItem(query.value(10).toString()));
        ui->tableTeacher->setItem(rowPos, 1, new QTableWidgetItem(query.value(0).toString()));
        ui->tableTeacher->setItem(rowPos, 2, new QTableWidgetItem(query.value(1).toString()));
        ui->tableTeacher->setItem(rowPos, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableTeacher->setItem(rowPos, 4, new QTableWidgetItem(query.value(3).toString()));
        ui->tableTeacher->setItem(rowPos, 5, new QTableWidgetItem(query.value(11).toString()));
        ui->tableTeacher->setItem(rowPos, 6, new QTableWidgetItem(query.value(9).toString()));
        ui->tableTeacher->setItem(rowPos, 7, new QTableWidgetItem(query.value(8).toString()));
        rowPos++;
    }
}

void MainWindow::tableMemberInput()
{
    // Code to display the Management details
    Management obj;
    QSqlQuery query;
    query = obj.getAllManagementRecord(ui->txtMemberSearch->text());
    ui->tableMember->setRowCount(0);
    int rowPos = 0;
    while(query.next()){
        ui->tableMember->insertRow(rowPos);
        ui->tableMember->setItem(rowPos, 0, new QTableWidgetItem(query.value(10).toString()));
        ui->tableMember->setItem(rowPos, 1, new QTableWidgetItem(query.value(0).toString()));
        ui->tableMember->setItem(rowPos, 2, new QTableWidgetItem(query.value(1).toString()));
        ui->tableMember->setItem(rowPos, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->tableMember->setItem(rowPos, 4, new QTableWidgetItem(query.value(3).toString()));
        ui->tableMember->setItem(rowPos, 5, new QTableWidgetItem(query.value(11).toString()));
        ui->tableMember->setItem(rowPos, 6, new QTableWidgetItem(query.value(9).toString()));
        ui->tableMember->setItem(rowPos, 7, new QTableWidgetItem(query.value(8).toString()));
        rowPos++;
    }
}

void MainWindow::updateAcademicList()
{
    // Code to display the marks of the students
    Student obj;
    QSqlQuery query;
    query = obj.getStudentList(ui->cbxAcademicDept->currentText(), ui->sbxAcademicYear->text());
    ui->cbxAcademicUsn->clear();
    ui->cbxAcademicName->clear();
    while(query.next()){
        ui->cbxAcademicUsn->addItem(QString(query.value(0).toString()));
        ui->cbxAcademicName->addItem(QString(query.value(1).toString()));
    }
}

void MainWindow::updateResultList()
{
    // Code to display the results of the students
    Marks obj;
    QSqlQuery query;
    query = obj.getMarksList(ui->cbxResultDept->currentText(), ui->sbxResultYear->text());
    ui->cbxResultUsn->clear();
    ui->txtResultSGPA->clear();
    while(query.next()){
        ui->cbxResultUsn->addItem(QString(query.value(0).toString()));
    }
}



// Actions to be excecuted while Adding new data
void MainWindow::on_btnStudentAdd_clicked()
{
    // Registering a new student
    ui->btnStudentClr->click();
    ui->tabStudentAcademic->setCurrentIndex(1);
    ui->txtStudentName->setFocus();
    ui->btnStudentAccept->setText("Add");
}

void MainWindow::on_btnTeacherAdd_clicked()
{
    // Registering a new Teacher
    ui->btnTeacherClr->click();
    ui->widgetTeacher->show();
    ui->txtTeacherName->setFocus();
    ui->btnTeacherAccept->setText("Add");
}

void MainWindow::on_btnMemberAdd_clicked()
{
    // Registering a new Member
    ui->btnMemberClr->click();
    ui->widgetNewMember->show();
    ui->txtMemberName->setFocus();
    ui->btnMemberAccept->setText("Add");
}


// Accepting the new/ edited data
void MainWindow::on_btnStudentAccept_clicked()
{
    // Registering/Editing a new student
    try {
        QString usn  = ui->txtStudentUSN->text().toUpper();
        QString name = ui->txtStudentName->text().toUpper();
        QString dob  = ui->dateStudentDob->text();
        QString gender;
        if(ui->rbStudentMale->isChecked())
            gender = "M";
        else
            gender = "F";
        QString mobile        = ui->txtStudentPh->text();
        QString email         = ui->txtStudentEmail->text().toUpper();
        QString curr_address  = ui->txtStudentCurAddress->toPlainText().toUpper();
        QString perm_address  = ui->txtStudentAddress->toPlainText().toUpper();
        QString father_name   = ui->txtStudentFatherName->text().toUpper();
        QString mother_name   = ui->txtStudentMotherName->text().toUpper();
        QString parent_mobile = ui->txtStudentParentPh->text().toUpper();
        QString department    = ui->cbxNewStudentDept->currentText();

        // Verifying the inputs of the user and displaying a message
        if(name.length()==0 || usn.length()==0 || !department.compare("Select")) {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid input", "Please enter the Name, USN and Department!",QMessageBox::Ok, this);
            msgBox.exec();
            ui->txtStudentName->setFocus();
        }
        else if(mobile.length()<10 || email.length()==0 || perm_address.length()==0) {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid Contact info", "Please enter the correct Mobile numbers, Address and E-mail!",QMessageBox::Ok, this);
            msgBox.exec();
            ui->txtStudentPh->setFocus();
        }

        // If all the inputs are correct add/update the data.
        // Update the data if only edit button is clicked, otherwise insert the data
        else {
            Student s(usn,name,dob,gender,mobile,email,curr_address,perm_address,father_name,mother_name,parent_mobile,department);
            if(!ui->btnStudentAccept->text().compare("Update")){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Confirmation", "Do you really want to update this record?", QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    s.updateStudent();
                }
                ui->txtStudentUSN->setReadOnly(false);
                ui->txtStudentUSN->setClearButtonEnabled(true);
                ui->btnStudentAccept->setText("Add");
            }
            else
                s.addStudent();

            // Display the table with the inserted data
            tableStudentInput();
            ui->btnStudentClr->click();
            ui->tabStudentAcademic->setCurrentIndex(0);
        }
    }

    // If any error occurs display the error
    catch (exception e) {
        QMessageBox msgBox(QMessageBox::Critical, "Error occured", e.what(),QMessageBox::Ok, this);
        msgBox.exec();
    }
}

void MainWindow::on_btnTeacherAccept_clicked()
{
    // Registering/Editing a new Teacher
    try {
        QString id            = ui->txtTeacherId->text();
        QString name          = ui->txtTeacherName->text().toUpper();
        QString dob           = ui->DateTeacherDob->text().toUpper();
        QString experience    = ui->sbxTeacherExp->text();
        QString position      = ui->txtTeacherPos->text().toUpper();
        QString mobile        = ui->txtTeacherPh->text().toUpper();
        QString email         = ui->txtTeacherEmail->text().toUpper();
        QString address       = ui->txtTeacherAddress->toPlainText();
        QString emname        = ui->txtTeacherEmName->text().toUpper();
        QString emmobile      = ui->txtTeacherEmPh->text().toUpper();
        QString department    = ui->cbxNewTeacherDept->currentText();
        QString qualification = ui->cbxTeacherQual->currentText();

        // Generating a random ID for the new teacher
        if(id.length()==0){
            int num = rand() % 900000 + 100000;
            id = QString::number(num);
        }

        // Verifying the inputs of the user and displaying a message
        if(name.length()==0 || !qualification.compare("Select") || !department.compare("Select")) {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid input", "Please enter the Name, Qualification and Department!",QMessageBox::Ok, this);
            msgBox.exec();
            ui->txtTeacherName->setFocus();
        }
        else if(mobile.length()<10 || email.length()==0) {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid Contact info", "Check the Mobile no and E-mail!",QMessageBox::Ok, this);
            msgBox.exec();
            ui->txtTeacherPh->setFocus();
        }

        // If all the inputs are correct add/update the data.
        // Update the data if only edit button is clicked, otherwise insert the data
        else {
            Teacher s(id,name,dob,mobile,email,address,emname,emmobile,experience,qualification,department,position);
            if(!ui->btnTeacherAccept->text().compare("Update")){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Confirmation","Do you really want to update this record?", QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    s.updateTeacher();
                }
                ui->btnTeacherAccept->setText("Add");
            }
            else{
                s.addTeacher();
            }

            // Display the table with the inserted data
            tableTeacherInput();
            ui->widgetTeacher->hide();
            ui->btnTeacherClr->click();
        }
    }

    // If any error occurs display the error
    catch (exception e) {
        QMessageBox msgBox(QMessageBox::Critical, "Error occured", e.what(),QMessageBox::Ok, this);
        msgBox.exec();
    }
}

void MainWindow::on_btnMemberAccept_clicked()
{
    // Registering/Editing a new Member of Management
    try {
        QMessageBox msgBox;

        QString id            = ui->txtMemberId->text();
        QString name          = ui->txtMemberName->text().toUpper();
        QString dob           = ui->dateMemberDob->text().toUpper();
        QString experience    = ui->sbxMemberExp->text();
        QString position      = ui->txtMemberPos->text().toUpper();
        QString mobile        = ui->txtMemberPh->text().toUpper();
        QString email         = ui->txtMemberEmail->text().toUpper();
        QString address       = ui->txtMemberAddress->toPlainText();
        QString emname        = ui->txtMemberEmName->text().toUpper();
        QString emmobile      = ui->txtMemberEmPh->text().toUpper();
        QString department    = ui->cbxMemberDept->currentText();
        QString qualification = ui->cbxMemberQual->currentText();

        // Generating a random ID for the new Member
        if(id.length()==0){
            int num = rand() % 900000 + 100000;
            id = QString::number(num);
        }

        // Verifying the inputs of the user and displaying a message
        if(name.length()==0 || !qualification.compare("Select") || !department.compare("Select")) {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid input", "Please enter the Name, Qualification and Department!",QMessageBox::Ok, this);
            msgBox.exec();
            ui->txtMemberName->setFocus();
        }
        else if(mobile.length()<10 || email.length()==0) {
            QMessageBox msgBox(QMessageBox::Warning, "Invalid Contact info", "Please enter the correct Mobile no and E-mail!",QMessageBox::Ok, this);
            msgBox.exec();
            ui->txtMemberPh->setFocus();
        }

        // If all the inputs are correct add/update the data.
        // Update the data if only edit button is clicked, otherwise insert the data
        else {
            Management s(id,name,dob,mobile,email,address,emname,emmobile,experience,qualification,department,position);
            if(!ui->btnMemberAccept->text().compare("Update")){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Confirmation","Do you really want to update this record?", QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    s.updateManagement();
                }
                ui->btnMemberAccept->setText("Add");
            }
            else{
                s.addManagement();
            }

            // Display the table with the inserted data
            tableMemberInput();
            ui->widgetNewMember->hide();
            ui->btnMemberClr->click();
        }
    }

    // If any error occurs display the error
    catch (exception e) {
        QMessageBox msgBox(QMessageBox::Critical, "Error encountered", e.what(),QMessageBox::Ok, this);
        msgBox.exec();
    }
}

void MainWindow::on_btnAcademicInsert_clicked()
{
    // Inserting marks of a student
    int rowPos = ui->tableAcademic->rowCount();
    bool flag = true;
    QString subCode = ui->txtSubCode->text().toUpper();

    // Checking if the subject code is repeated or not
    for(int i=0;i<rowPos;i++)
        if(ui->tableAcademic->item(i,0)->text() == subCode){
            QMessageBox msgBox(QMessageBox::Warning, "Invalid Input", "Subject Code cannot be repeated!",QMessageBox::Ok, this);
            msgBox.exec();
            flag=false;
            ui->txtSubCode->setFocus();
        }

    if(flag) {
        QString SubCode    = ui->txtSubCode->text().toUpper();
        QString Credits    = ui->sbxCredits->text();
        QString Cie1       = ui->sbxCie1->text();
        QString Cie2       = ui->sbxCie2->text();
        QString Cie3       = ui->sbxCie3->text();
        QString Assignment = ui->sbxAssignment->text();
        QString Activity   = ui->sbxActivity->text();
        QString See        = ui->sbxSee->text();
        QString Attendance = ui->sbxAttendance->text();

        if(SubCode.length() < 4){
            QMessageBox msgBox(QMessageBox::Warning, "Invalid Input", "Invalid Subject Code, Enter a valid Subject Code!",QMessageBox::Ok, this);
            msgBox.exec();
        }
        else{
            ui->tableAcademic->insertRow(rowPos);
            ui->tableAcademic->setItem(rowPos, 0, new QTableWidgetItem(SubCode));
            ui->tableAcademic->setItem(rowPos, 1, new QTableWidgetItem(Credits));
            ui->tableAcademic->setItem(rowPos, 2, new QTableWidgetItem(Cie1));
            ui->tableAcademic->setItem(rowPos, 3, new QTableWidgetItem(Cie2));
            ui->tableAcademic->setItem(rowPos, 4, new QTableWidgetItem(Cie3));
            ui->tableAcademic->setItem(rowPos, 5, new QTableWidgetItem(Assignment));
            ui->tableAcademic->setItem(rowPos, 6, new QTableWidgetItem(Activity));
            ui->tableAcademic->setItem(rowPos, 7, new QTableWidgetItem(See));
            ui->tableAcademic->setItem(rowPos, 8, new QTableWidgetItem(Attendance));
        }
    }
}

void MainWindow::on_btnAcademicAccept_clicked()
{
    // Entering Marks of a Student
    QString usn        = ui->cbxAcademicUsn->currentText().toUpper();
    QString name       = ui->cbxAcademicName->currentText().toUpper();
    QString dept       = ui->cbxAcademicDept->currentText();
    QString year       = ui->sbxAcademicYear->text();
    if(usn.length()==0){
        QMessageBox msgBox(QMessageBox::Warning, "Invalid Input", "Select a USN to continue!",QMessageBox::Ok, this);
        msgBox.exec();
    }
    else {
        int row = ui->tableAcademic->rowCount();
        for(int i=0; i<row; i++) {
            QString subcode    = ui->tableAcademic->item(i, 0)->text();
            QString credit     = ui->tableAcademic->item(i, 1)->text();
            QString cie1       = ui->tableAcademic->item(i, 2)->text();
            QString cie2       = ui->tableAcademic->item(i, 3)->text();
            QString cie3       = ui->tableAcademic->item(i, 4)->text();
            QString assignment = ui->tableAcademic->item(i, 5)->text();
            QString activity   = ui->tableAcademic->item(i, 6)->text();
            QString see        = ui->tableAcademic->item(i, 7)->text();
            QString attendance = ui->tableAcademic->item(i, 8)->text();
            attendance = attendance.left(attendance.length()-1);

            // Inserting the data to the table
            Marks m(usn,name,dept,year,subcode,credit,cie1,cie2,cie3,assignment,activity,see,attendance);
            m.addMarks();
        }
        ui->btnAcademicClr->click();
    }
}



// Clearing the data input
void MainWindow::on_btnStudentClr_clicked()
{
    // Clearing the inputs of Student registration form
    ui->txtStudentUSN->clear();
    ui->txtStudentName->clear();
    ui->dateStudentDob->text().toUtf8().constData();
    ui->rbStudentMale->setChecked(true);
    ui->txtStudentPh->clear();
    ui->txtStudentEmail->clear();
    ui->txtStudentCurAddress->clear();
    ui->txtStudentAddress->clear();
    ui->txtStudentFatherName->clear();
    ui->txtStudentMotherName->clear();
    ui->txtStudentParentPh->clear();
    ui->cbxNewStudentDept->setCurrentIndex(0);
    ui->txtStudentName->setFocus();
    ui->txtStudentUSN->setReadOnly(false);
    ui->txtStudentUSN->setClearButtonEnabled(true);
    ui->btnStudentAccept->setText("Add");
}

void MainWindow::on_btnTeacherClr_clicked()
{
    // Clearing the inputs of Teacher registration form
    ui->txtTeacherId->clear();
    ui->txtTeacherName->clear();
    ui->DateTeacherDob->clear();
    ui->sbxTeacherExp->setValue(0);
    ui->txtTeacherPos->clear();
    ui->txtTeacherPh->clear();
    ui->txtTeacherEmail->clear();
    ui->txtTeacherAddress->clear();
    ui->txtTeacherEmName->clear();
    ui->txtTeacherEmPh->clear();
    ui->cbxNewTeacherDept->setCurrentIndex(0);
    ui->cbxTeacherQual->setCurrentIndex(0);
    ui->txtTeacherName->setFocus();
    ui->btnTeacherAccept->setText("Add");
}

void MainWindow::on_btnMemberClr_clicked()
{
    // Clearing the inputs of Member registration form
    ui->txtMemberId->clear();
    ui->txtMemberName->clear();
    ui->dateMemberDob->clear();
    ui->sbxMemberExp->setValue(0);
    ui->txtMemberPos->clear();
    ui->txtMemberPh->clear();
    ui->txtMemberEmail->clear();
    ui->txtMemberAddress->clear();
    ui->txtMemberEmName->clear();
    ui->txtMemberEmPh->clear();
    ui->cbxMemberDept->setCurrentIndex(0);
    ui->cbxMemberQual->setCurrentIndex(0);
    ui->txtMemberName->setFocus();
    ui->btnTeacherAccept->setText("Add");
}

void MainWindow::on_btnAcademicClr_clicked()
{
    // Clearing the inputs of marks form
    ui->tableAcademic->setRowCount(0);
    ui->txtSubCode->clear();
    ui->sbxCredits->clear();
    ui->sbxCie1->clear();
    ui->sbxCie2->clear();
    ui->sbxCie3->clear();
    ui->sbxActivity->clear();
    ui->sbxAssignment->clear();
    ui->sbxSee->clear();
    ui->sbxAttendance->clear();
    ui->cbxAcademicUsn->setFocus();
}


// Deleting data
void MainWindow::on_btnStudentDelete_clicked()
{
    // Deleting a selected data from the table
    int row = ui->tableStudentInfo->currentRow();
    if(row!=-1) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation","Do you really want to delete this record?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QString usn = ui->tableStudentInfo->item(row,1)->text();
            Student obj;
            obj.removeStudent(usn);
            tableStudentInput();
        }
    }
}

void MainWindow::on_btnTeacherDelete_clicked()
{
    // Deleting a selected data from the table
    int row = ui->tableTeacher->currentRow();
    if(row!=-1) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation","Do you really want to delete this record?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QString usn = ui->tableTeacher->item(row,1)->text();
            Teacher obj;
            obj.removeTeacher(usn);
            tableTeacherInput();
        }
    }
}

void MainWindow::on_btnMemberDelete_clicked()
{
    // Deleting a selected data from the table
    int row = ui->tableMember->currentRow();
    if(row!=-1) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation","Do you really want to delete this record?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QString usn = ui->tableMember->item(row,1)->text();
            Management obj;
            obj.removeManagement(usn);
            tableMemberInput();
        }
    }
}

void MainWindow::on_btnAcademicDelete_clicked()
{
    // Deleting a selected data from the table
    int row = ui->tableAcademic->currentRow();
    if(row!=-1) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation","Do you really want to delete this record?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            ui->tableAcademic->removeRow(row);
        }
    }
}


// Editing a data
void MainWindow::on_btnStudentEdit_clicked()
{
    // Editing a selected data from the table
    int row = ui->tableStudentInfo->currentRow();
    if(row!=-1) {
        QString usn = ui->tableStudentInfo->item(row,1)->text();
        Student obj;
        QSqlQuery query;
        query = obj.getStudentRecord(usn);
        query.next();

        ui->txtStudentUSN->setText(query.value(0).toString());
        ui->txtStudentName->setText(query.value(1).toString());
        QDate date = QDate::fromString(query.value(2).toString(),"dd-MMM-yyyy");
        ui->dateStudentDob->setDate(date);
        if(query.value(3) == "M")
            ui->rbStudentMale->setChecked(true);
        else
            ui->rbStudentFemale->setChecked(true);

        ui->txtStudentPh->setText(query.value(4).toString());
        ui->txtStudentEmail->setText(query.value(5).toString());
        ui->txtStudentCurAddress->setText(query.value(6).toString());
        ui->txtStudentAddress->setText(query.value(7).toString());
        ui->txtStudentFatherName->setText(query.value(8).toString());
        ui->txtStudentMotherName->setText(query.value(9).toString());
        ui->txtStudentParentPh->setText(query.value(10).toString());
        ui->cbxNewStudentDept->setCurrentText(query.value(11).toString());

        ui->widgetStudentAdd->raise();
        ui->widgetStudentAdd->show();
        ui->txtStudentUSN->setReadOnly(true);
        ui->txtStudentUSN->setClearButtonEnabled(false);
        ui->txtStudentName->setFocus();
        ui->btnStudentAccept->setText("Update");
        ui->tabStudentAcademic->setCurrentIndex(1);
    }
}

void MainWindow::on_btnTeacherEdit_clicked()
{
    // Editing a selected data from the table
    ui->btnTeacherMaximize->hide();
    int row = ui->tableTeacher->currentRow();
    if(row!=-1) {
        QString id = ui->tableTeacher->item(row,1)->text();
        Teacher obj;
        QSqlQuery query;
        query = obj.getTeacherRecord(id);
        query.next();

        ui->txtTeacherId->setText(query.value(0).toString());
        ui->txtTeacherName->setText(query.value(1).toString());
        QDate date = QDate::fromString(query.value(2).toString(),"dd-MMM-yyyy");
        ui->DateTeacherDob->setDate(date);
        ui->txtTeacherPh->setText(query.value(3).toString());
        ui->txtTeacherEmail->setText(query.value(4).toString());
        ui->txtTeacherAddress->setPlainText(query.value(5).toString());
        ui->txtTeacherEmName->setText(query.value(6).toString());
        ui->txtTeacherEmPh->setText(query.value(7).toString());
        ui->sbxTeacherExp->setValue(query.value(8).toInt());
        ui->cbxTeacherQual->setCurrentText(query.value(9).toString());
        ui->cbxNewTeacherDept->setCurrentText(query.value(10).toString());
        ui->txtTeacherPos->setText(query.value(11).toString());

        ui->widgetTeacher->raise();
        ui->widgetTeacher->show();
        ui->txtTeacherId->setReadOnly(true);
        ui->txtTeacherName->setFocus();
        ui->btnTeacherAccept->setText("Update");
    }
}

void MainWindow::on_btnMemberEdit_clicked()
{
    // Editing a selected data from the table
    ui->btnMemberMaximize->hide();
    int row = ui->tableMember->currentRow();
    if(row!=-1) {
        QString id = ui->tableMember->item(row,1)->text();
        Management obj;
        QSqlQuery query;
        query = obj.getManagementRecord(id);
        query.next();

        ui->txtMemberId->setText(query.value(0).toString());
        ui->txtMemberName->setText(query.value(1).toString());
        QDate date = QDate::fromString(query.value(2).toString(),"dd-MMM-yyyy");
        ui->dateMemberDob->setDate(date);
        ui->txtMemberPh->setText(query.value(3).toString());
        ui->txtMemberEmail->setText(query.value(4).toString());
        ui->txtMemberAddress->setPlainText(query.value(5).toString());
        ui->txtMemberEmName->setText(query.value(6).toString());
        ui->txtMemberEmPh->setText(query.value(7).toString());
        ui->sbxMemberExp->setValue(query.value(8).toInt());
        ui->cbxMemberQual->setCurrentText(query.value(9).toString());
        ui->cbxMemberDept->setCurrentText(query.value(10).toString());
        ui->txtMemberPos->setText(query.value(11).toString());

        ui->widgetNewMember->raise();
        ui->widgetNewMember->show();
        ui->txtMemberId->setReadOnly(true);
        ui->txtMemberName->setFocus();
        ui->btnMemberAccept->setText("Update");
    }
}


// Rejecting an input
void MainWindow::on_btnStudentReject_clicked()
{
    // Rejecting/ Cancelling the Student registration form
    ui->tabStudentAcademic->setCurrentIndex(0);
    ui->btnStudentClr->click();
    ui->btnStudentAccept->setText("Add");

}

void MainWindow::on_btnTeacherReject_clicked()
{
    // Rejecting/ Cancelling the Teacher registration form
    ui->btnTeacherClr->click();
    ui->widgetTeacher->hide();
}

void MainWindow::on_btnMemberReject_clicked()
{
    // Rejecting/ Cancelling the Member registration form
    ui->btnMemberClr->click();
    ui->widgetNewMember->hide();
}


// Changing tabs
void MainWindow::on_tabStudentFaculty_currentChanged(int index)
{
    // Set the tabs to the first tab when the Index is changed
    if(index==0){
        ui->tabStudentAcademic->setCurrentIndex(0);
    }
    else if (index==1){
        ui->tabTeacherManagement->setCurrentIndex(0);
    }
}

void MainWindow::on_tabStudentAcademic_currentChanged(int index)
{
    // Refresh the table when tab is changed
    if(index == 0){
        tableStudentInput();
    }
    else if (index == 2){
        updateAcademicList();
    }
    else if (index == 3){
        updateResultList();
    }

}

void MainWindow::on_tabTeacherManagement_currentChanged(int index)
{
    // Refresh the table when tab is changed
    if (index == 0) {
        tableTeacherInput();
    }
    else if (index == 1) {
        tableMemberInput();
    }
}


// Function signals to run when userinput changed.
void MainWindow::on_cbxStudentDept_currentIndexChanged(int index)
{
    // Refreshes the table with the desired department when combobox is changed
    tableStudentInput();
}

void MainWindow::on_cbxTeacherDept_currentIndexChanged(int index)
{
    // Refreshes the table with the desired department when combobox is changed
    tableTeacherInput();
}

void MainWindow::on_cbxAcademicDept_currentIndexChanged(int index)
{
    // Refreshes the table with the desired department when combobox is changed
    updateAcademicList();
}

void MainWindow::on_cbxAcademicUsn_currentIndexChanged(int index)
{
    // Select a USN with which the table will be populated.
    ui->cbxAcademicName->setCurrentIndex(index);
    Marks m;
    QSqlQuery query = m.getMarksRecord(ui->cbxAcademicUsn->currentText());
    ui->tableAcademic->setRowCount(0);
    while(query.next()){
        ui->tableAcademic->insertRow(0);
        ui->tableAcademic->setItem(0, 0, new QTableWidgetItem(query.value(4).toString()));
        ui->tableAcademic->setItem(0, 1, new QTableWidgetItem(query.value(5).toString()));
        ui->tableAcademic->setItem(0, 2, new QTableWidgetItem(query.value(6).toString()));
        ui->tableAcademic->setItem(0, 3, new QTableWidgetItem(query.value(7).toString()));
        ui->tableAcademic->setItem(0, 4, new QTableWidgetItem(query.value(8).toString()));
        ui->tableAcademic->setItem(0, 5, new QTableWidgetItem(query.value(9).toString()));
        ui->tableAcademic->setItem(0, 6, new QTableWidgetItem(query.value(10).toString()));
        ui->tableAcademic->setItem(0, 7, new QTableWidgetItem(query.value(11).toString()));
        ui->tableAcademic->setItem(0, 8, new QTableWidgetItem(query.value(12).toString()));
    }
}

void MainWindow::on_sbxAcademicYear_valueChanged(int index)
{
    // Refreshes the table with the desired year when combobox is changed
    updateAcademicList();
}

void MainWindow::on_cbxResultDept_currentIndexChanged(int index)
{
    // Refreshes the table with the desired department when combobox is changed
    updateResultList();
}

void MainWindow::on_cbxResultUsn_currentIndexChanged(int index)
{
    // Select a USN with which the table will be populated.
    QString usn = ui->cbxResultUsn->currentText();
    Student s;
    QSqlQuery query = s.getStudentRecord(usn);
    query.next();

    // Showing the details of the student with the selected USN.
    ui->txtResultName->setText(query.value(1).toString());
    ui->txtResultGender->setText(query.value(3).toString());
    ui->txtResultDept->setText(query.value(11).toString());
    ui->txtResultPh->setText(query.value(4).toString());
    ui->txtResultEmail->setText(query.value(5).toString());
    ui->txtResultParentPh->setText(query.value(10).toString());

    Marks m;
    query = m.getMarksRecord(usn);
    ui->tableResult->setRowCount(0);
    int totalcredit = 0;
    int sum = 0;
    while(query.next()){
        ui->tableResult->insertRow(0);
        ui->tableResult->setItem(0, 0, new QTableWidgetItem(query.value(4).toString()));
        ui->tableResult->setItem(0, 1, new QTableWidgetItem(query.value(5).toString()));
        ui->tableResult->setItem(0, 2, new QTableWidgetItem(query.value(6).toString()));
        ui->tableResult->setItem(0, 3, new QTableWidgetItem(query.value(7).toString()));
        ui->tableResult->setItem(0, 4, new QTableWidgetItem(query.value(8).toString()));
        ui->tableResult->setItem(0, 5, new QTableWidgetItem(query.value(9).toString()));
        ui->tableResult->setItem(0, 6, new QTableWidgetItem(query.value(10).toString()));
        ui->tableResult->setItem(0, 7, new QTableWidgetItem(query.value(11).toString()));
        ui->tableResult->setItem(0, 8, new QTableWidgetItem(query.value(12).toString()));
        ui->tableResult->setItem(0, 9, new QTableWidgetItem(query.value(13).toString()));

        // Calculating Credit for the Semester based on the grades
        int credit = query.value(5).toInt();
        QString grade = query.value(13).toString();
        if(grade=="S")
            sum += 10*credit;
        else if(grade=="A")
            sum += 9*credit;
        else if(grade=="B")
            sum += 8*credit;
        else if(grade=="C")
            sum += 7*credit;
        else if(grade=="D")
            sum += 6*credit;
        else if(grade=="E")
            sum += 5*credit;
        totalcredit+=credit;
    }
    if(totalcredit!=0){
        float sgpa = sum/totalcredit;
        ui->txtResultSGPA->setText(QString::number(sgpa));
    }
}

void MainWindow::on_sbxResultYear_valueChanged(int index)
{
    // Refreshes the table with the desired year when combobox is changed
    updateResultList();
}

void MainWindow::on_txtStudentSearch_textEdited(QString text)
{
    // Refreshes the table with the changes in the search box
    tableStudentInput();
}

void MainWindow::on_txtTeacherSearch_textEdited(QString text)
{
    // Refreshes the table with the changes in the search box
    tableTeacherInput();
}

void MainWindow::on_txtMemberSearch_textEdited(QString text)
{
    // Refreshes the table with the changes in the search box
    tableMemberInput();
}

void MainWindow::on_tableStudentInfo_cellDoubleClicked(int row, int col)
{
    // Double click to edit the selected row in the table
    ui->btnStudentEdit->click();
}

void MainWindow::on_tableTeacher_cellDoubleClicked(int row, int col)
{
    // Double click to edit the selected row in the table
    ui->btnTeacherEdit->click();
}

void MainWindow::on_tableMember_cellDoubleClicked(int row, int col)
{
    // Double click to edit the selected row in the table
    ui->btnMemberEdit->click();
}

