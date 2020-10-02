#include <QApplication>
#include <QWidget>

#include "mainwindow.h"
#include "database.h"

int main(int argc, char *argv[])
{

    // The QApplication class manages the GUI application's control flow and main settings.
    QApplication a(argc, argv);

    // Creating an object, db from the class 'Database'.
    // Inititalises and connects to the Database.
    Database db;
    db.initDb();

    // Creating an object w from the class 'MainWindow'.
    MainWindow w;
    w.show();
    return a.exec();
}
