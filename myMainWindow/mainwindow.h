#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void newFile(); //create file
    bool maybeSave(); //decide whetherto save
    bool save();
    bool saveAs();
    bool close();
    bool saveFile(const QString &fileName);

private slots:
    void on_action_New_Project_N_triggered();

    void on_actionsave_S_triggered();

    void on_actionsave_as_A_triggered();

private:
    Ui::MainWindow *ui;
    bool isUntitled; //true is saved,false is unsave
    QString curFile; //save current file's path
};
#endif // MAINWINDOW_H
