#include "tcMsgViewDlg.h"
#include <QClipboard>
#include <QDebug>

tcMsgViewDlg::tcMsgViewDlg(QString aaMsg, QString asSeparator, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    // Turn off the help button
    setWindowFlags (windowFlags() & ~(Qt::WindowContextHelpButtonHint));
    setWindowIcon (QApplication::windowIcon());

    // Close this window if main window has been closed.
    this->setAttribute( Qt::WA_QuitOnClose, false );

    ui.btnCopyToClipboard->setHidden(true);

    msByteArrayString = aaMsg;
    msSeparator = asSeparator;

    ui.twByteView->verticalHeader()->setHidden(true);
    QHeaderView* header = ui.twByteView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

	connect(ui.pushButton_ok, SIGNAL(clicked()), this, SLOT(slot_pushButton_ok()));
    connect(ui.btnCopyToClipboard, SIGNAL(clicked()), this, SLOT(btnCopyToClipboard_clicked()));

    addBytesToView();
    ui.twByteView->resizeColumnsToContents();
    ui.tabWidget->setCurrentIndex(0);
}

tcMsgViewDlg::~tcMsgViewDlg()
{

}

void tcMsgViewDlg::slot_pushButton_ok()
{
	QDialog::done(QDialog::Accepted);
}

void tcMsgViewDlg::btnCopyToClipboard_clicked()
{
    QClipboard* pc = QApplication::clipboard();
    QString strClip = "";

    strClip = msByteArrayString;

    pc->setText(strClip);
}

void tcMsgViewDlg::addBytesToView()
{
    QString asData = msByteArrayString;
    QStringList asDataList = asData.split(msSeparator);

    ui.twByteView->setRowCount(asDataList.size());
    for (int i = 0; i < asDataList.size(); i++)
    {
        // Set index column
        QTableWidgetItem *index = new QTableWidgetItem(QString::number(i+1));
        index->setTextAlignment(Qt::AlignHCenter);
        ui.twByteView->setItem(i, 0, index);

        // Set hex column
        QTableWidgetItem *hex = new QTableWidgetItem((asDataList.at(i)));
        hex->setTextAlignment(Qt::AlignHCenter);
        ui.twByteView->setItem(i, 1, hex);

        // Set decimal column
        int val = asDataList.at(i).toInt(NULL, 16);
        QTableWidgetItem *decimal = new QTableWidgetItem(QString::number(val));
        decimal->setTextAlignment(Qt::AlignHCenter);
        ui.twByteView->setItem(i, 2,decimal);

        // Set bits column
        QTableWidgetItem *bits = new QTableWidgetItem(QString("%1").arg(val, 8, 2, QChar('0')));
        bits->setTextAlignment(Qt::AlignHCenter);
        ui.twByteView->setItem(i, 3, bits);
    }
}
