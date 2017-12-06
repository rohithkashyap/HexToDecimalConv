#ifndef TCMSGVIEWDLG_H
#define TCMSGVIEWDLG_H

#include <QDialog>
#include "ui_tcMsgViewDlg.h"

class tcMsgViewDlg: public QDialog
{
	Q_OBJECT

public:
    tcMsgViewDlg(QString aaMsg, QString asSeparator, QWidget *parent = 0);
	~tcMsgViewDlg();

private slots:
	void	slot_pushButton_ok();
    void    btnCopyToClipboard_clicked();

private:
	Ui::tcMsgViewDlgClass ui;
    QStringList msMsgDataList;
    QString msByteArrayString;
    QString msSeparator;

    void addBytesToView();
};

#endif // TCMSGVIEWDLG_H
