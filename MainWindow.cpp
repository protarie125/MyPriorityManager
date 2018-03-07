#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    ui->setupUi(this);

    ui->actionNew->setShortcut(Qt::Key_N | Qt::CTRL);
    ui->actionOpen->setShortcut(Qt::Key_O | Qt::CTRL);
    ui->actionSave->setShortcut(Qt::Key_S | Qt::CTRL);
    ui->addTaskButton->setShortcut(Qt::Key_A | Qt::CTRL);

    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
    connect(this, &MainWindow::sortDone,
            this, &MainWindow::countTask);
    connect(this, &MainWindow::sortDone,
            this, &MainWindow::numberingTasks);
    connect(this, &MainWindow::nowEditMode,
            this, &MainWindow::toggleButtonHide);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Task *MainWindow::nowPEdit()
{
    return mNowPEdit;
}

MainWindow::PEditMode MainWindow::pem()
{
    return mPEM;
}

void MainWindow::setNowPEdit(Task *task)
{
    mNowPEdit = task;
}

void MainWindow::setPEM(MainWindow::PEditMode mode)
{
    mPEM = mode;
}

QVector<Task *> MainWindow::sortTasks(QVector<Task *> ts)
{
    if (ts.size() == 0) {
        return ts;
    } else if (ts.size() == 1) {
        return ts;
    } else if (ts.size() == 2) {
        if (ts.at(0)->priority() < ts.at(1)->priority()) {
            QVector< Task* > s(2);
            s.clear();
            s.append(ts.at(1));
            s.append(ts.at(0));
            return s;
        } else {
            return ts;
        }
    } else {
        QVector< Task* > less, eq, more, s;
        less.clear();
        eq.clear();
        more.clear();
        s.clear();

        int pivot = (int)round(ts.size() / 2);
        for (int i = 0; i < ts.size(); i++) {
            if (ts.at(i)->priority() < ts.at(pivot)->priority()) {
                less.append(ts.at(i));
            } else if (ts.at(i)->priority() > ts.at(pivot)->priority()) {
                more.append(ts.at(i));
            } else {
                eq.append(ts.at(i));
            }
        }

        s.append(sortTasks(more));
        s.append(eq);
        s.append(sortTasks(less));
        return s;
    }
}

void MainWindow::numberingTasks()
{
    if (mTasks.size() == 1) {
        mTasks.at(0)->setNumber(1);
    } else if (mTasks.size() > 1) {
        for (int i = 0; i < mTasks.size(); i++) {
            mTasks.at(i)->setNumber(i + 1);
        }
    }
}

void MainWindow::countTask()
{
    int n = mTasks.size();
    QString sText = "Status: ";
    sText.append(QString::number(n));
    if (n == 1) {
        sText.append(" task");
    } else {
        sText.append(" tasks");
    }
    ui->statusLabel->setText(sText);
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),
                                         &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        // connect
        connect(task, &Task::priorityChanged,
                this, &MainWindow::doSort);
        connect(task, &Task::attemptRemove,
                this, &MainWindow::removeTask);
        connect(task, &Task::goNormal,
                this, &MainWindow::normalMode);
        connect(task, &Task::goSuper,
                this, &MainWindow::prioritySuperMode);
        connect(task, &Task::goEqual,
                this, &MainWindow::priorityEqualMode);
        connect(task, &Task::thisSelected,
                this, &MainWindow::priorityEdit2Selected);
        // set Task ID
        if (mTasks.size() == 0) {
            task->setTaskID(1);
            qDebug() << "Task ID = 1";
        } else if (mTasks.size() > 0) {
            int id = 0;
            for (int i = 0; i < mTasks.size(); i++) {
                id += mTasks.at(i)->taskID();
            }
            id += 1;
            task->setTaskID(id);
            qDebug() << "Task ID = " << id;
        }
        // append
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        doSort();
    }
}

void MainWindow::doSort()
{
    mTasks = sortTasks(mTasks);
    if (mTasks.size() > 0) {
        for (int i = 0; i < mTasks.size(); i++) {
            ui->tasksLayout->addWidget(mTasks.at(i));
        }
    }

    emit sortDone();
}

void MainWindow::removeTask(Task *task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    doSort();
}

void MainWindow::normalMode()
{
    setPEM(PEditMode::Normal);

    emit nowEditMode(PEditMode::Normal);
}

void MainWindow::prioritySuperMode(Task* task)
{
    setNowPEdit(task);
    setPEM(PEditMode::Super);

    emit nowEditMode(PEditMode::Super);
}

void MainWindow::priorityEqualMode(Task* task)
{
    setNowPEdit(task);
    setPEM(PEditMode::Equal);

    emit nowEditMode(PEditMode::Equal);
}

void MainWindow::toggleButtonHide(PEditMode mode)
{
    switch (mode) {
    case Normal:
        qDebug() << "Priority edit mode: Normal";
        for (int i = 0; i < mTasks.size(); i++) {
            mTasks.at(i)->buttonShowNormal();
        }
        break;
    case Super:
        qDebug() << "Priority edit mode: Super";
        for (int i = 0; i < mTasks.size(); i++) {
            mTasks.at(i)->buttonShowSelect();
        }
        nowPEdit()->buttonShowCancel();
        break;
    case Equal:
        qDebug() << "Priority edit mode: Equal";
        for (int i = 0; i < mTasks.size(); i++) {
            mTasks.at(i)->buttonShowSelect();
        }
        nowPEdit()->buttonShowCancel();
        break;
    default:
        break;
    }
}

void MainWindow::priorityEdit2Selected(Task *selected)
{
    switch (pem()) {
    case Super:
        nowPEdit()->setPriority(selected->priority() + 1);
        doSort();

        emit nowEditMode(PEditMode::Normal);
        break;
    case Equal:
        nowPEdit()->setPriority(selected->priority());
        doSort();

        emit nowEditMode(PEditMode::Normal);
        break;
    default:
        break;
    }
}
