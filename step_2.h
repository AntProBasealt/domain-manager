#ifndef STEP_2_H
#define STEP_2_H

#include <QWidget>

class Step2Page : public QWidget
{
    Q_OBJECT
public:
    Step2Page();
    virtual ~Step2Page();

private:
    void setDcIpAddress();
    void setIpMask();
    void setDnsServer();
    void setGateway();
    void setDnsBackend();

private:
    Step2Page(const Step2Page &) = delete;
    Step2Page(Step2Page &&)      = delete;
    Step2Page &operator=(const Step2Page &) = delete;
    Step2Page &operator=(Step2Page &&) = delete;
};

#endif // STEP_2_H
