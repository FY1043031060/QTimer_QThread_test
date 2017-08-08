#include "TimerTest.h"
#include <QDebug>
#include <QTime>
TimerTest::TimerTest(QObject *parent) : QObject(parent)
{
    m_slot.moveToThread(&m_thread);
    connect(&m_timer,&QTimer::timeout,&m_slot,&ThreadSlot::up);
    m_thread.start();
    m_timer.start(50);
}

void TimerTest::up()
{
    qDebug() << __FUNCTION__ <<QTime::currentTime()<< "front";
    QThread::sleep(3);
    qDebug() << __FUNCTION__ << QTime::currentTime()<< "end";
}

ThreadSlot::ThreadSlot(QObject *parent)
{

}

void ThreadSlot::up()
{
    qDebug() << __FUNCTION__ << QTime::currentTime()<< "front";
    QThread::sleep(3);
    qDebug() << __FUNCTION__ << QTime::currentTime()<< "end";
}
