#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

void MainWindow::iniUI()
{
    fLabCurfile = new QLabel;
    fLabCurfile->setMinimumWidth(150);
    fLabCurfile->setText("当前文件: ");
    ui->statusbar->addWidget(fLabCurfile);

    progressBar = new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    comBoxFont = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel("字体"));
    ui->toolBar->addWidget(comBoxFont);
}

void MainWindow::iniSingalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinBoxFontSize_changed(int)));
    connect(comBoxFont,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(on_comboFont_changed(const QString&)));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniSingalSlots();
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actCopy->setEnabled(b);
    ui->actCut->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());

}


void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    ui->actFontltalic->setCheckable(fmt.fontItalic());
    ui->actFontBold->setCheckable(fmt.font().bold());
    ui->actFontUnder->setCheckable(fmt.fontUnderline());
}

void MainWindow::on_spinBoxFontSize_changed(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar->setValue(aFontSize);
}

void MainWindow::on_comboFont_changed(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}





void MainWindow::on_action_triggered()
{
    QMessageBox::about(this,"信息","姓名: 郭梓轩\n""学号: 2023414290411\n");
}

