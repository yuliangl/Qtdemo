#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      isUntitled(true), curFile(tr("newname.txt"))
{
    ui->setupUi(this);
    setWindowTitle(curFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile(){
    if(maybeSave()){
        isUntitled = true;
        curFile = tr("newname.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave(){
    if(ui->textEdit->document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("warning"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr("it has't been saved, do you want save it"));

        QPushButton *yesBut = box.addButton(tr("Yes"),QMessageBox::YesRole);
        box.addButton(tr("No"), QMessageBox::NoRole);

        QPushButton *cancelBut = box.addButton(tr("cancel"), QMessageBox::RejectRole);

        box.exec();
        if(box.clickedButton() == yesBut){
            return save();
        }
        else if (box.clickedButton() == cancelBut)
            return false;

    }
    return true;
}

bool MainWindow::save(){
    if(isUntitled)
        return saveAs();
    else
        return saveFile(curFile);
}

bool MainWindow::saveAs(){
    QString fileName = QFileDialog::getSaveFileName(this,
                                                tr("save as"), curFile);
    if(fileName.isEmpty()) return false;
    return saveFile(fileName);

}

bool MainWindow::saveFile(const QString &fileName){
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, tr("multiple text editer"),
                             tr("can not edit %1: /n %2")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    isUntitled = false;
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;

}

bool MainWindow::loadFile(const QString &fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, tr("multiple editer"),
                             tr("can not loadfile %1 /n %2")
                             .arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_New_Project_N_triggered() {newFile();}

void MainWindow::on_actionsave_S_triggered() {save();}

void MainWindow::on_actionsave_as_A_triggered() {saveAs();}

void MainWindow::on_actionopen_O_triggered(){
    if(maybeSave()){
        QString fileName = QFileDialog::getOpenFileName(this);

        if(!fileName.isEmpty()){
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_actionClose_C_triggered(){
    if(maybeSave()){
        ui->textEdit->setVisible(false);
    }
}

void MainWindow::on_actionexit_X_triggered(){
    on_actionClose_C_triggered();
    qApp->quit();
}

void MainWindow::on_actionundo_Z_triggered(){
    ui->textEdit->undo();
}

void MainWindow::on_actioncut_X_triggered(){
    ui->textEdit->cut();
}

void MainWindow::on_actioncopy_c_triggered(){
    ui->textEdit->copy();
}

void MainWindow::on_actionpaste_V_triggered(){
    ui->textEdit->paste();
}
