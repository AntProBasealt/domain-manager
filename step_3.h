#ifndef STEP_3_H
#define STEP_3_H

#include <QWidget>

class Step3Page : public QWidget
{
    Q_OBJECT
public:
    Step3Page();
    virtual ~Step3Page();

private:
    void instPackage();

private:
    Step3Page(const Step3Page &) = delete;
    Step3Page(Step3Page &&)      = delete;
    Step3Page &operator=(const Step3Page &) = delete;
    Step3Page &operator=(Step3Page &&) = delete;
};

#endif // STEP_3_H
