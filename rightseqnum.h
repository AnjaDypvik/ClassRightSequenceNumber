#ifndef RIGHTSEQNUM_H
#define RIGHTSEQNUM_H
#include <QObject>
#include <QList>
#include <QAbstractListModel>
#include <QStringList>

class RightSequenceNumber
{
public:
    RightSequenceNumber(const int &rSeqNum);
    int rSeqNum() const;

private:
    int m_rSeqNum;
};

class RightSeqNumModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum RightSeqNumRoles {
        RightSeqNumrole
    };

    RightSeqNumModel(QObject *parent =0);


    void addRSeqNum(const RightSequenceNumber &rightSequenceNumber);
    void removeRSeqNum(int index);
    int rowCount(const QModelIndex & parent = QModelIndex())const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void rightAddState(QString value, int num);  //add state button
    Q_INVOKABLE void rightLoadState(QString value, int num);
    Q_INVOKABLE void rightRemove(int index);
    Q_INVOKABLE void rightSave(int newRSeqNum);
    Q_INVOKABLE void rightReset(QString value, int num);



protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<RightSequenceNumber>m_rSeqNum;

};

#endif // RIGHTSEQNUM_H

