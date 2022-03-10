#include "tcHexToDec.h"
#include "ui_tcHexToDec.h"

tcHexToDec::tcHexToDec(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tcHexToDec)
{
    ui->setupUi(this);
    this->setWindowTitle("Hex To Decimal Converter");

    connect (ui->btnConvert, SIGNAL(clicked()), this, SLOT(slot_btnConvert_clicked()));
    connect (ui->btnShowTable, SIGNAL(clicked()), this, SLOT(slot_btnShowTable_clicked()));
}

tcHexToDec::~tcHexToDec()
{
    delete ui;
}

void tcHexToDec::slot_btnConvert_clicked()
{
    // Check if separator has been specified
    if (ui->leSeparator->text().isEmpty())
    {
        QMessageBox::information(this, "Missing separator", "If no separator, just put a space in separator box", QMessageBox::Ok);
        return;
    }

    // Check if hex stream has been given
    if (ui->teHexStream->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Missing hex stream", "Enter some data first", QMessageBox::Ok);
        return;
    }

    // Clear the decimal box
    ui->teDecimalStream->clear();

    // Get separator
    QString sSeparator = ui->leSeparator->text();
    QString sHexStream = ui->teHexStream->toPlainText().trimmed().remove('\n').remove("0x");

    QStringList sHexList = sHexStream.split(sSeparator);
    QStringList sDecimalList;
    for (int i = 0; i < sHexList.size(); i++)
    {
        sDecimalList.append(QString::number(sHexList.at(i).toUInt(0, 16)));
    }

    // Add to box
    ui->teDecimalStream->setText(sDecimalList.join(sSeparator));
}

void tcHexToDec::slot_btnShowTable_clicked()
{
    // Check if separator has been specified
    if (ui->leSeparator->text().isEmpty())
    {
        QMessageBox::information(this, "Missing separator",
                                 "If no separator, just put a space in separator box", QMessageBox::Ok);
        return;
    }

    // Check if hex stream has been given
    if (ui->teHexStream->toPlainText().isEmpty())
    {
        QMessageBox::warning(this, "Missing hex stream", "Enter some data first", QMessageBox::Ok);
        return;
    }

    QString sSeparator = ui->leSeparator->text();
    QString sHexStream = ui->teHexStream->toPlainText().trimmed().remove('\n').remove("0x");
    tcMsgViewDlg oMsgView(sHexStream, sSeparator, this);
    oMsgView.exec();
}
