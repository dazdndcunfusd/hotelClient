#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "roominfodialog.h"
#include "guestinfodialog.h"
#include "newguestdialog.h"
#include "savefileclass.h"
#include <QDateTime>

QT_BEGIN_NAMESPACE
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void sessionOpened();
    //void requestHotelInfo();
    void readHotelInfo();
    //!Maybe have the connected slot in the server go to a different slot if needed
    //void requestClientInfo();
    void displayError(QAbstractSocket::SocketError socketError);

    void on_lineEdit_textChanged();
    void on_action_Exit_triggered();
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_findRoom_clicked();

    void on_findGuest_clicked();

    void on_actionNew_Guest_triggered();

    void on_actionAbout_2_triggered();

    void on_actionHotel_Information_triggered();

private:
    qint32 roomNum[49];
    QString bedType[49];
    QString fullName[3];
    qint32 checkInDate[3];
    qint32 numNights[3];
    qint32 roomNumAssigned[3];
    bool occupied[49];
    QDate today= QDate::currentDate();
    QString hotelInfo;


    QTcpSocket *tcpSocket;
    bool socketConnected=false;
    QString clientData;
    quint16 blocksize;
    QNetworkSession *networkSession;

    roomInfoDialog *roomDialog;
    guestInfoDialog *guestDialog;
    newGuestDialog *newguestDialog;
    saveFileClass *saveFile;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
