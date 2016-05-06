#ifndef FORM_H
#define FORM_H

#include <QWidget>


namespace Ui {
class Form;
}

class QStandardItemModel;
class QAbstractItemModel;

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void receiveData(const QByteArray &data);

public slots:
    void about();
    void run();

private slots: 
    //绝对运动
    void on_absAddBtn_clicked();

    void on_relaAddBtn_clicked();

    void on_resetBtn_clicked();

    void on_deleteBtn_clicked();

protected:
    void dragEnterEvent(QDragEnterEvent *event); //拖动事件
    void dropEvent(QDropEvent *event); //放置事件

signals:
    void sendData(const QByteArray &data);

private slots:
    void forward();
    void backward();

    void on_stopAct_clicked();

    void on_backwardAct_clicked(); //逆向回退

    void on_forwardAct_clicked(); //正向前进

    void on_stepAct_clicked(); //单步运行

private:
    void initUI();
    void initConnect();
    void initModel();

    void convert(quint8 *buf, int data); //int -> quint8[4]
    void array2qa(QByteArray &data, quint8 *buf, int size); //quint8[4] -> QByteArray

private:
    Ui::Form *ui;
    QByteArray echo; //串口返回数据
    //QStandardItemModel *header;
    //QStandardItemModel *model;
    QAbstractItemModel *model;
    //QStringList *m_list;
    int row;   //行位置
    int index; //指令序列位置
    QTimer *ford_timer; //正向计时器
    QTimer *back_timer; //逆向计时器
    bool status;
    QList<QByteArray> *cmd_list; //指令列表
};

#endif // FORM_H
