#ifndef STEP_4_H
#define STEP_4_H

#include <QWidget>

class Step4Page : public QWidget
{
    Q_OBJECT
public:
    Step4Page();
    virtual ~Step4Page();

private:
    void displayDomainName();
    void displayDcFQDN();
    void displayTypeBase();
    void displaySizeBase();
    void displayBaseAd();
    void displayAuthMethod();

private:
    Step4Page(const Step4Page &) = delete;
    Step4Page(Step4Page &&)      = delete;
    Step4Page &operator=(const Step4Page &) = delete;
    Step4Page &operator=(Step4Page &&) = delete;
};

#endif // STEP_4_H
