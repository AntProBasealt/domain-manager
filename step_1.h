#ifndef STEP_1_H
#define STEP_1_H

#include <QWidget>

class Step1Page : public QWidget
{
    Q_OBJECT
public:
    Step1Page();
    virtual ~Step1Page();

private:
    void showBaseAdRadioButton();
    void showFirstDcCheckBox();
    void setDomainName();
    void setComputerName();
    void displayFQDN();
    void setAdminPass();
    void checkAdminPass();
    void setTypeBase();
    void setSizeBase();

private:
    Step1Page(const Step1Page &) = delete;
    Step1Page(Step1Page &&)      = delete;
    Step1Page &operator=(const Step1Page &) = delete;
    Step1Page &operator=(Step1Page &&) = delete;
};

#endif // STEP_1_H
