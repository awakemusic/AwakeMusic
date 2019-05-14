#ifndef GETINFO_H
#define GETINFO_H
#include <QVector>
#include <QFile>
#include <QChar>
#include <QDebug>
#include <stdio.h>
typedef struct stcHeader
{
    char header[3];
    int iNumber;
    stcHeader()
    {
      memset(header,0,3);
      iNumber = 0;
    }
}stcHeader;
class GetInFo
{
public:
    GetInFo();
    QByteArray getMaxVector(char *pDesc);
    void getHeadInfo(char *pStart,int iLen);
    QString chartobit(char cb);
    QString bitToString(char *pChar,int iLen);
    int infoToTime(int iSize);
    QString secondToTime(int iTime);
    int findXing(char *pStart,int iLen);
    bool isHeader(char *pHead,int iLen);
    int comLayout(char *pHead,int iLen);
    int comVersion(char *pHead,int iLen);
    int getSample(int iVersion,int iLayout);
    int getSampleRate(char *pHead,int iLen,int iVersion);
    int getAllFrames(char *pFrame,int iLen);
    int getMPEGTime(QString strFile);
private:
    int iPosition;
public:
    QVector<stcHeader> vecHeader;
};
#endif // GETINFO_H
