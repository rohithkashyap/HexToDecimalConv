#ifndef TCHEXTODEC_H
#define TCHEXTODEC_H

#include <QMainWindow>
#include <QMessageBox>
#include "tcMsgViewDlg.h"

namespace Ui {
class tcHexToDec;
}

class tcHexToDec : public QMainWindow
{
    Q_OBJECT

public:
    explicit tcHexToDec(QWidget *parent = 0);
    ~tcHexToDec();

private slots:
    void slot_btnConvert_clicked();
    void slot_btnShowTable_clicked();

private:
    Ui::tcHexToDec *ui;
};

#endif // TCHEXTODEC_H
