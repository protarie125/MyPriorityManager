#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "Task.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum PEditMode { Normal = 0, Super = 1, Equal = 2 };
    // get
    Task* nowPEdit();
    PEditMode pem();
    // set
    void setNowPEdit(Task* task);
    void setPEM(PEditMode mode);
    // fnc
    QVector< Task* > sortTasks(QVector< Task* > ts);
    void numberingTasks();

public slots:
    void countTask();
    void addTask();
    void doSort();
    void removeTask(Task* task);
    void normalMode();
    void prioritySuperMode(Task* task);
    void priorityEqualMode(Task* task);
    void toggleButtonHide(PEditMode mode);
    void priorityEdit2Selected(Task* selected);

signals:
    void sortDone();
    void nowEditMode(PEditMode mode);

private:
    Ui::MainWindow *ui;
    QVector< Task* > mTasks;
    Task* mNowPEdit;
    PEditMode mPEM;
};

#endif // MAINWINDOW_H
