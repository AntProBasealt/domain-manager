#ifndef STEP_2_H
#define STEP_2_H

#include <QWidget>

class Step3Page : public QWidget
{
    Q_OBJECT
public:
    Step3Page();
    virtual ~Step3Page();

private:
    void setDcIpAddress();
    void setIpMask();
    void setDnsServer();
    void setGateway();
    void setDnsBackend();

private:
    Step3Page(const Step3Page &) = delete;
    Step3Page(Step3Page &&)      = delete;
    Step3Page &operator=(const Step3Page &) = delete;
    Step3Page &operator=(Step3Page &&) = delete;
};

#endif // STEP_2_H
