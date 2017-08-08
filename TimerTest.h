#ifndef TIMERTEST_H
#define TIMERTEST_H

#include <QObject>
#include <QTimer>
#include <QThread>

class ThreadSlot : public QObject
{
    Q_OBJECT
public:
    explicit ThreadSlot(QObject *parent = nullptr);
public slots:
    void up();
};

class TimerTest : public QObject
{
    Q_OBJECT
public:
    explicit TimerTest(QObject *parent = nullptr);

signals:

public slots:
    void up();

private:
    QTimer m_timer;
    QThread m_thread;
    ThreadSlot m_slot;
};

#endif // TIMERTEST_H
