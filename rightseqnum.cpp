#include <stdio.h>
#include <QDebug>
#include "rightseqnum.h"

RightSequenceNumber::RightSequenceNumber( const int &rSeqNum)
    :m_rseqnum(rseqnum)
{
}

int RightSequenceNumber::rSeqNum()const
{
    return m_rSeqNum;
}


void RightSeqNumModel::rightSave( int newRSeqNum)       //rightSave=save button
{
   qDebug() << "Saving number: " <<newRSeqNum;
   QFile storeFile("FILNAVN");              //Sett inn filnavn!!
   if (!storeFile.exists())            //kun for testing
   {
       qDebug () <<"File does not exist."<<endl;

   }
   if (!storeFile.open(QIODevice::Append))     //storeFile = mellomlager
   {
       return;
   }
   QTextStream newData(&storeFile);            //newData henter ny info fra mellomlager

    newData <<newRSeqNum<<endl;
    addNew(RightSequenceNumber(newRSeqNum));             //addNew er navnet på funksjonen
}



void RightSeqNumModel::rightRemove(QString value, int num)
{
    qDebug()<<"deleted"<<value<<num;
    RightSeqnumModel::removeRSeqNum(index);
}
RightSeqNumModel::RightSeqNumModel(QObject *parent)
    :QAbstractListModel(parent)
{
}

int RightSeqNumModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_rSeqNum.count();
}

QVariant RightSeqNumModel::data(const QModelIndex &index, int role) const {
    if (index.row()< 0 || index.row() >=m_rSeqNum.count())
        return QVariant();
    const RightSeqNumModel &rSeqNum = m_rSeqNum[index.row()];
    if (role == rsNumRole)
        return rightSequenceNumber.rSeqNum();

    return QVariant();
}

QHash<int, QByteArray> RightSeqNumModel::roleNames() const {
    QHash<int, QByteArray>roles;
    roles [rsNumRole] = "rSeqNum";
    return roles;

}
