/********************************************************************************
** Form generated from reading UI file 'Task.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *numberLabel;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer;
    QFrame *line_2;
    QVBoxLayout *tastEditLayout;
    QPushButton *editButton;
    QPushButton *selectButton;
    QPushButton *cancelButton;
    QPushButton *deleteButton;
    QGridLayout *gridLayout;
    QPushButton *upButton;
    QPushButton *superButton;
    QPushButton *equalButton;
    QPushButton *downButton;
    QFrame *line;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QStringLiteral("Task"));
        Task->resize(685, 126);
        verticalLayout_2 = new QVBoxLayout(Task);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        numberLabel = new QLabel(Task);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numberLabel->sizePolicy().hasHeightForWidth());
        numberLabel->setSizePolicy(sizePolicy);
        numberLabel->setMinimumSize(QSize(30, 30));
        numberLabel->setMaximumSize(QSize(30, 30));
        numberLabel->setFrameShape(QFrame::Box);
        numberLabel->setAlignment(Qt::AlignCenter);
        numberLabel->setIndent(0);

        horizontalLayout->addWidget(numberLabel);

        nameLabel = new QLabel(Task);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        horizontalLayout->addWidget(nameLabel);

        horizontalSpacer = new QSpacerItem(660, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line_2 = new QFrame(Task);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        tastEditLayout = new QVBoxLayout();
        tastEditLayout->setSpacing(3);
        tastEditLayout->setObjectName(QStringLiteral("tastEditLayout"));
        editButton = new QPushButton(Task);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setEnabled(true);
        editButton->setCheckable(false);
        editButton->setChecked(false);

        tastEditLayout->addWidget(editButton);

        selectButton = new QPushButton(Task);
        selectButton->setObjectName(QStringLiteral("selectButton"));

        tastEditLayout->addWidget(selectButton);

        cancelButton = new QPushButton(Task);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        tastEditLayout->addWidget(cancelButton);

        deleteButton = new QPushButton(Task);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        tastEditLayout->addWidget(deleteButton);


        horizontalLayout->addLayout(tastEditLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        upButton = new QPushButton(Task);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(upButton, 0, 1, 1, 1);

        superButton = new QPushButton(Task);
        superButton->setObjectName(QStringLiteral("superButton"));
        superButton->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(superButton, 0, 2, 1, 1);

        equalButton = new QPushButton(Task);
        equalButton->setObjectName(QStringLiteral("equalButton"));
        equalButton->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(equalButton, 1, 2, 1, 1);

        downButton = new QPushButton(Task);
        downButton->setObjectName(QStringLiteral("downButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(downButton->sizePolicy().hasHeightForWidth());
        downButton->setSizePolicy(sizePolicy1);
        downButton->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(downButton, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(Task);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QApplication::translate("Task", "Task", 0));
        numberLabel->setText(QApplication::translate("Task", "0", 0));
        nameLabel->setText(QApplication::translate("Task", "Task->name", 0));
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("Task", "<html><head/><body><p>Edit task</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        editButton->setText(QApplication::translate("Task", "Edit", 0));
        selectButton->setText(QApplication::translate("Task", "Select", 0));
        cancelButton->setText(QApplication::translate("Task", "Cancel", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("Task", "<html><head/><body><p>Delete task</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("Task", "Delete", 0));
#ifndef QT_NO_TOOLTIP
        upButton->setToolTip(QApplication::translate("Task", "<html><head/><body><p>Priority +1</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        upButton->setText(QApplication::translate("Task", "+", 0));
#ifndef QT_NO_TOOLTIP
        superButton->setToolTip(QApplication::translate("Task", "<html><head/><body><p>Set Priority +1 more than next selected task.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        superButton->setText(QApplication::translate("Task", "^", 0));
#ifndef QT_NO_TOOLTIP
        equalButton->setToolTip(QApplication::translate("Task", "<html><head/><body><p>Set Priority equal to next selected task.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        equalButton->setText(QApplication::translate("Task", "=", 0));
#ifndef QT_NO_TOOLTIP
        downButton->setToolTip(QApplication::translate("Task", "<html><head/><body><p>Priority -1</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        downButton->setText(QApplication::translate("Task", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
