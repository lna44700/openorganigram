#ifndef F_TRANSFERT_H
#define F_TRANSFERT_H

#include <QWidget>

namespace Ui {
class f_Transfert;
}

class f_Transfert : public QWidget
{
    Q_OBJECT

public:
    explicit f_Transfert(QWidget *parent = 0);
    ~f_Transfert();

private:
    Ui::f_Transfert *ui;
};

#endif // F_TRANSFERT_H
