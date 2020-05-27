#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QDate>
#include <QMainWindow>
#include <QObject>
#include <QTableWidget>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Class to create a base/ main Window for the program
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // Actions to be excecuted based on slots
    void on_btnStudentAdd_clicked();
    void on_btnStudentAccept_clicked();
    void on_btnStudentClr_clicked();
    void on_btnStudentDelete_clicked();
    void on_btnStudentEdit_clicked();
    void on_btnStudentReject_clicked();
    void on_btnNewStudentHelp_clicked();

    void on_btnAcademicInsert_clicked();
    void on_btnAcademicDelete_clicked();
    void on_btnAcademicAccept_clicked();
    void on_btnAcademicClr_clicked();
    void on_btnAcademicHelp_clicked();

    void on_btnTeacherAdd_clicked();
    void on_btnTeacherAccept_clicked();
    void on_btnTeacherClr_clicked();
    void on_btnTeacherDelete_clicked();
    void on_btnTeacherEdit_clicked();
    void on_btnTeacherReject_clicked();
    void on_btnTeacherHelp_clicked();

    void on_btnMemberAdd_clicked();
    void on_btnMemberAccept_clicked();
    void on_btnMemberClr_clicked();
    void on_btnMemberDelete_clicked();
    void on_btnMemberEdit_clicked();
    void on_btnMemberReject_clicked();
    void on_btnMemberHelp_clicked();

    void on_btnResultHelp_clicked();
    void on_btnResultPrint_clicked();

    void on_tabStudentFaculty_currentChanged(int index);
    void on_tabStudentAcademic_currentChanged(int index);
    void on_tabTeacherManagement_currentChanged(int index);

    void on_cbxStudentDept_currentIndexChanged(int index);
    void on_txtStudentSearch_textEdited(QString text);
    void on_tableStudentInfo_cellDoubleClicked(int row, int col);

    void on_cbxAcademicDept_currentIndexChanged(int index);
    void on_sbxAcademicYear_valueChanged(int index);
    void on_cbxAcademicUsn_currentIndexChanged(int index);

    void on_cbxTeacherDept_currentIndexChanged(int index);
    void on_txtTeacherSearch_textEdited(QString text);
    void on_tableTeacher_cellDoubleClicked(int row, int col);

    void on_txtMemberSearch_textEdited(QString text);
    void on_tableMember_cellDoubleClicked(int row, int col);

    void on_cbxResultDept_currentIndexChanged(int index);
    void on_cbxResultUsn_currentIndexChanged(int index);
    void on_sbxResultYear_valueChanged(int index);

private:
    Ui::MainWindow *ui;

    // User defined functions to make changes to the GUI.
    void tableStudentInput();
    void updateAcademicList();
    void updateResultList();
    void tableTeacherInput();
    void tableMemberInput();
    QString createHtml();
    void printHtml(QString htmlStream);
};
#endif
