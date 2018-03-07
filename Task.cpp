#include "Task.h"
#include "ui_Task.h"
#include <QDebug>
#include <QInputDialog>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->upButton, &QPushButton::clicked,
            this, &Task::priorityUp);
    connect(ui->downButton, &QPushButton::clicked,
            this, &Task::priorityDown);
    connect(ui->editButton, &QPushButton::clicked,
            this, &Task::editName);
    connect(ui->deleteButton, &QPushButton::clicked,
            [this] { emit attemptRemove(this); });
    connect(ui->cancelButton, &QPushButton::clicked,
            [=] { emit goNormal(); });
    connect(ui->superButton, &QPushButton::clicked,
            [this] { emit goSuper(this); });
    connect(ui->equalButton, &QPushButton::clicked,
            [this] { emit goEqual(this); });
    connect(ui->selectButton, &QPushButton::clicked,
            [this] { emit thisSelected(this); });

    buttonShowNormal();
}

Task::~Task()
{
    delete ui;
}

unsigned long Task::taskID() const
{
    return mTaskID;
}

int Task::priority()
{
    return mPriority;
}

int Task::number()
{
    QString numberText = ui->numberLabel->text();
    return numberText.toInt();
}

QString Task::name() const
{
    return ui->nameLabel->text();
}

void Task::setTaskID(const unsigned long id)
{
    mTaskID = id;
}

void Task::setPriority(int p)
{
    mPriority = p;
}

void Task::setNumber(int n)
{
    QString numberText = QString::number(n);
    ui->numberLabel->setText(numberText);
}

void Task::setName(const QString &name)
{
    ui->nameLabel->setText(name);
}

void Task::buttonShowNormal()
{
    ui->selectButton->hide();
    ui->cancelButton->hide();

    ui->editButton->show();
    ui->deleteButton->show();

    ui->upButton->setEnabled(true);
    ui->downButton->setEnabled(true);
    ui->superButton->setEnabled(true);
    ui->equalButton->setEnabled(true);
}

void Task::buttonShowSelect()
{
    ui->selectButton->show();
    ui->cancelButton->hide();

    ui->editButton->hide();
    ui->deleteButton->hide();

    ui->upButton->setEnabled(false);
    ui->downButton->setEnabled(false);
    ui->superButton->setEnabled(false);
    ui->equalButton->setEnabled(false);
}

void Task::buttonShowCancel() {
    ui->selectButton->hide();
    ui->cancelButton->show();

    ui->editButton->hide();
    ui->deleteButton->hide();

    ui->upButton->setEnabled(false);
    ui->downButton->setEnabled(false);
    ui->superButton->setEnabled(false);
    ui->equalButton->setEnabled(false);
}

void Task::priorityUp()
{
    int p = priority() + 1;
    setPriority(p);

    emit priorityChanged(p);
}

void Task::priorityDown()
{
    int p = priority() - 1;
    setPriority(p);

    emit priorityChanged(p);
}

void Task::editName()
{
    bool ok;
    QString newText = QInputDialog::getText(this,
                                            tr("Edit task"),
                                            tr("Task name"),
                                            QLineEdit::Normal,
                                            this->name(),
                                            &ok);
    if (ok && !newText.isEmpty()) {
        setName(newText);
    }
}
