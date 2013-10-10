#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("QTodo");

    QList<Note> listNotes = DomParser::collectAllNotes();
    foreach(Note note, listNotes)
    {
        ui->listWidget->addItem(note.getTitle());

        if (note.getDone() == "true")
           ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::green) ;
    }
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::save()
{
    QList<Note> list;
    QString title;
    QString done;
    if (ui->listWidget->count() != NULL)
    {
    for(int i = 0; i < ui->listWidget->count(); i++){
        title = ui->listWidget->item(i)->text();

        if (ui->listWidget->item(i)->textColor() == Qt::green){
        done = "true";
        }
        else {done = "false";}

        list.append(Note(QString::number(i),title, done));
        DomParser::saveXML(list);
    }

    }
    else DomParser::saveEmptyXML();
}

void MainForm::on_lineEdit_textEdited(const QString &arg1)
{
    if (ui->lineEdit->text().isEmpty())
    {
        ui->addButton->setEnabled(false);
    }
    else ui->addButton->setEnabled(true);
}

void MainForm::on_doneButton_clicked()
{
    if (ui->listWidget->currentItem()->textColor() == Qt::green)
    {
        ui->listWidget->currentItem()->setTextColor(QApplication::palette().text().color());
        ui->doneButton->setText("Done");
    }
    else
    {
        ui->listWidget->currentItem()->setTextColor(Qt::green);
        ui->doneButton->setText("Undone");
    }
    save();
}

void MainForm::on_addButton_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
    ui->addButton->setEnabled(false);
    save();
}

void MainForm::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

    if (current != NULL)
    {
        ui->doneButton->setEnabled(true);
        ui->removeButton->setEnabled(true);

        if (current->textColor() == Qt::green)
            {
                ui->doneButton->setText("Undone");
            }
        else
            {
                ui->doneButton->setText("Done");
            }
    }
    else
    {

        ui->doneButton->setEnabled(false);
        ui->removeButton->setEnabled(false);

    }
}

void MainForm::on_removeButton_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->row(ui->listWidget->currentItem()));
    save();
}

void MainForm::on_removeDoneButton_clicked()
{
    int rows = ui->listWidget->count()-1;

    for(int i=rows; i>=0; i--){

        if (ui->listWidget->item(i)->textColor() == Qt::green)
        {
            ui->listWidget->takeItem(i);
        }
    }
  save();
}

void MainForm::on_lineEdit_returnPressed()
{

    if (ui->lineEdit->text().isEmpty())
    {
    }
    else {
    ui->addButton->setEnabled(true);
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
    ui->addButton->setEnabled(false);
    }
    save();
}
