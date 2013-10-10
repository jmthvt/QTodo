#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QListWidgetItem>
#include <QStringListModel>
#include "domparser.h"

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
    
private slots:

    void on_lineEdit_textEdited(const QString &arg1);

    void on_doneButton_clicked();

    void on_addButton_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_removeButton_clicked();

    void on_removeDoneButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainForm *ui;

    void save();
};

#endif // MAINFORM_H



