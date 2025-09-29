#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *fLabCurfile;
    QProgressBar *progressBar;
    QSpinBox *spinFontSize;
    QFontComboBox *comBoxFont;

    void iniUI();
    void iniSingalSlots();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    void on_spinBoxFontSize_changed(int aFontSize);

    void on_comboFont_changed(const QString &arg1);

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
