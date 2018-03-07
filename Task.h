#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString &name, QWidget *parent = 0);
    ~Task();
    // get
    unsigned long taskID() const;
    int priority();
    int number();
    QString name() const;
    // set
    void setTaskID(const unsigned long id);
    void setPriority(int p);
    void setNumber(int n);
    void setName(const QString &name);
    // fnc
    void buttonShowNormal();
    void buttonShowSelect();
    void buttonShowCancel();

public slots:
    void priorityUp();
    void priorityDown();
    void editName();

signals:
    void priorityChanged(int p);
    void attemptRemove(Task* task);
    void goNormal();
    void goSuper(Task* task);
    void goEqual(Task* task);
    void thisSelected(Task* task);

private:
    Ui::Task *ui;
    unsigned long mTaskID = 1;
    int mPriority = -1;
};

#endif // TASK_H
