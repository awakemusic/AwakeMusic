#include "getInfo.h"

GetInFo::GetInFo()
{
    vecHeader.clear();
    iPosition = 0;
}

QByteArray GetInFo::getMaxVector(char *pDesc)
{
    QByteArray dataArry;
    dataArry.clear();
    if(!pDesc)
        return dataArry;
    char pHeader[3]={0};
    int iMax = 0;
    if(vecHeader.isEmpty())
        return dataArry;
    else
    {
        for(int i=0;i<vecHeader.size();i++)
        {
            if(i==0)
            {
              memcpy(pHeader,vecHeader.at(i).header,3);
              iMax = vecHeader.at(i).iNumber;
            }
            else
            {
                if(vecHeader.at(i).iNumber>iMax)
                {
                  iMax = vecHeader.at(i).iNumber;
                  memcpy(pHeader,vecHeader.at(i).header,3);
                }
            }
        }
    }
    dataArry.append((const char *)pHeader,3);
    memcpy(pDesc,pHeader,3);
    return dataArry;
}

void GetInFo::getHeadInfo(char *pStart, int iLen)
{
    if(!pStart)
        return;
    if(iLen<=4)
        return;
    int iHead = 0;
    for(int i =0;i<iLen;)
    {
        if((pStart[i]&0xff)==0xff)
        {
            if((pStart[i+1]&0xff) <= 0xe0)
            {
               i+=1;
               continue;
            }
            if((pStart[i+1]&(0x3<<3))==0x08)
            {
               i+=1;
               continue;
            }
            if((pStart[i+1]&(0x3<<1))==0X0)
            {
                i+=1;
                continue;
            }
            if((pStart[i+2]&(0xf0))==0xf0)
            {
                i+=1;
                continue;
            }
            if((pStart[i+2]&0xf0)==0x00)
            {
                i+=1;
                continue;
            }
            if((pStart[i+2]&0x0c)==0x0c)
            {
                i+=1;
                continue;
            }
            iHead = i;
            if(iLen <= iHead+4)
            {
                i+=4;
                continue;
            }
            else
            {
              bool bExit = false;
              char Header[3]={0};
              memcpy(Header,&pStart[i],3);
              if(vecHeader.isEmpty())
              {
                 bExit = true;
                 stcHeader stcNode;
                 stcNode.iNumber = 1;
                 memcpy(stcNode.header,Header,3);
                 vecHeader.append(stcNode);
              }
              else
              {
                  for(int j=0;j<vecHeader.size();j++)
                  {
                      if(memcmp(vecHeader[j].header,Header,3)==0)
                      {
                          bExit= true;
                          vecHeader[j].iNumber+=1;
                      }
                  }
                  if(!bExit)
                  {
                     stcHeader stcNode;
                     memcpy(stcNode.header,Header,3);
                     stcNode.iNumber=1;
                     vecHeader.append(stcNode);
                  }
              }
              i+=4;
            }
        }
        i+=1;
    }
    return;
}

QString GetInFo::chartobit(char cb)
{
    QString strRet;
    for(int i=0;i<=7;i++)
    {
        if((cb&(0x1<<(7-i)))==0x00)
        {
            strRet.append("0");
        }
        else
        {
            strRet.append("1");
        }
    }
    return strRet;
}

QString GetInFo::bitToString(char *pChar, int iLen)
{
    QString strOut = "";
    if(!pChar)
        return strOut;
    if(iLen<=0)
        return strOut;
    for(int i=0;i<iLen;i++)
    {
        strOut.append(chartobit(pChar[i]));
        strOut.append(" ");
    }
    return strOut;
}

int GetInFo::infoToTime(int iSize)
{
    int iBitrate = 0;
    int iTime = 0;
    bool bRate = true;
    char pHeaderMax[3]={0};
    int iMax = 0;
    if(vecHeader.isEmpty())
        return 0;
    for(int i=0;i<vecHeader.size();i++)
    {
        if(i==0)
        {
            iMax = vecHeader[i].iNumber;
            memcpy(pHeaderMax,vecHeader[i].header,3);
        }
        else
        {
            if(vecHeader[i].iNumber > iMax)
            {
                iMax = vecHeader[i].iNumber;
                memcpy(pHeaderMax,vecHeader[i].header,3);
            }
        }
    }
    QString strOut = "";
    strOut = chartobit(pHeaderMax[0]);
    strOut += " ";
    strOut += chartobit(pHeaderMax[1]);
    strOut += " ";
    strOut += chartobit(pHeaderMax[2]);
    //qDebug()<<"Header:"<<strOut;

    int iVersion = 0;
    int iLayout = 0;
    switch((pHeaderMax[1] & (0x3<<3)))
    {
    case 0x00:
    {
        iVersion = 2;
    }
        break;
    case 0x08:
    {
        iVersion = 0;
    }
        break;
    case 0x10:
    {
        iVersion = 2;
    }
        break;
    case 0x18:
    {
        iVersion = 1;
    }
        break;
    default:
    {
        iVersion = 0;
    }
        break;
    }

    if(iVersion<=0)
        return 0;

    switch(pHeaderMax[1] & (0x3<<1))
    {
    case 0x00:
    {
       iLayout = -1;
    }
        break;
    case 0x02:
    {
       iLayout = 3;
    }
        break;
    case 0x04:
    {
       iLayout = 2;
    }
        break;
    case 0x06:
    {
       iLayout = 1;
    }
        break;
    default:
    {
       iLayout = -1;
    }
        break;
    }

    if(iLayout<=0)
        return 0;

    if(iVersion == 1)
    {
        if(iLayout==1)
        {
            switch((pHeaderMax[2]&0xf0))
            {
            case 0x10:
            {iBitrate = 32*1000;}break;
            case 0x20:
            {iBitrate = 64*1000;}break;
            case 0x30:
            {iBitrate = 96*1000;}break;
            case 0x40:
            {iBitrate = 128*1000;}break;
            case 0x50:
            {iBitrate = 160*1000;}break;
            case 0x60:
            {iBitrate = 192*1000;}break;
            case 0x70:
            {iBitrate = 224*1000;}break;
            case 0x80:
            {iBitrate = 256*1000;}break;
            case 0x90:
            {iBitrate = 288*1000;}break;
            case 0xa0:
            {iBitrate = 320*1000;}break;
            case 0xb0:
            {iBitrate = 352*1000;}break;
            case 0xc0:
            {iBitrate = 384*1000;}break;
            case 0xd0:
            {iBitrate = 416*1000;}break;
            case 0xe0:
            {iBitrate = 448*1000;}break;
            default:
            {bRate = false;}break;
            }
        }
        else if(iLayout==2)
        {
            switch((pHeaderMax[2]&0xf0))
            {
            case 0x10:
            {iBitrate = 32*1000;}break;
            case 0x20:
            {iBitrate = 48*1000;}break;
            case 0x30:
            {iBitrate = 56*1000;}break;
            case 0x40:
            {iBitrate = 64*1000;}break;
            case 0x50:
            {iBitrate = 80*1000;}break;
            case 0x60:
            {iBitrate = 96*1000;}break;
            case 0x70:
            {iBitrate = 112*1000;}break;
            case 0x80:
            {iBitrate = 128*1000;}break;
            case 0x90:
            {iBitrate = 160*1000;}break;
            case 0xa0:
            {iBitrate = 192*1000;}break;
            case 0xb0:
            {iBitrate = 224*1000;}break;
            case 0xc0:
            {iBitrate = 256*1000;}break;
            case 0xd0:
            {iBitrate = 320*1000;}break;
            case 0xe0:
            {iBitrate = 384*1000;}break;
            default:
            {bRate = false;}break;
            }
        }
        else if(iLayout == 3)
        {
            switch((pHeaderMax[2]&0xf0))
            {
            case 0x10:
            {iBitrate = 32*1000;}break;
            case 0x20:
            {iBitrate = 40*1000;}break;
            case 0x30:
            {iBitrate = 48*1000;}break;
            case 0x40:
            {iBitrate = 56*1000;}break;
            case 0x50:
            {iBitrate = 64*1000;}break;
            case 0x60:
            {iBitrate = 80*1000;}break;
            case 0x70:
            {iBitrate = 96*1000;}break;
            case 0x80:
            {iBitrate = 112*1000;}break;
            case 0x90:
            {iBitrate = 128*1000;}break;
            case 0xa0:
            {iBitrate = 160*1000;}break;
            case 0xb0:
            {iBitrate = 192*1000;}break;
            case 0xc0:
            {iBitrate = 224*1000;}break;
            case 0xd0:
            {iBitrate = 256*1000;}break;
            case 0xe0:
            {iBitrate = 320*1000;}break;
            default:
            {bRate = false;}break;
            }
        }
        else
        {
           bRate = false;
        }
    }
    else if(iVersion == 2)
    {
        if(iLayout == 1)
        {
            switch((pHeaderMax[2]&0xf0))
            {
            case 0x10:
            {iBitrate = 32*1000;}break;
            case 0x20:
            {iBitrate = 64*1000;}break;
            case 0x30:
            {iBitrate = 96*1000;}break;
            case 0x40:
            {iBitrate = 128*1000;}break;
            case 0x50:
            {iBitrate = 160*1000;}break;
            case 0x60:
            {iBitrate = 192*1000;}break;
            case 0x70:
            {iBitrate = 224*1000;}break;
            case 0x80:
            {iBitrate = 256*1000;}break;
            case 0x90:
            {iBitrate = 288*1000;}break;
            case 0xa0:
            {iBitrate = 320*1000;}break;
            case 0xb0:
            {iBitrate = 352*1000;}break;
            case 0xc0:
            {iBitrate = 384*1000;}break;
            case 0xd0:
            {iBitrate = 416*1000;}break;
            case 0xe0:
            {iBitrate = 448*1000;}break;
            default:
            {bRate = false;}break;
            }
        }
        else if(iLayout == 2)
        {
            switch((pHeaderMax[2]&0xf0))
            {
            case 0x10:
            {iBitrate = 32*1000;}break;
            case 0x20:
            {iBitrate = 48*1000;}break;
            case 0x30:
            {iBitrate = 56*1000;}break;
            case 0x40:
            {iBitrate = 64*1000;}break;
            case 0x50:
            {iBitrate = 80*1000;}break;
            case 0x60:
            {iBitrate = 96*1000;}break;
            case 0x70:
            {iBitrate = 112*1000;}break;
            case 0x80:
            {iBitrate = 128*1000;}break;
            case 0x90:
            {iBitrate = 160*1000;}break;
            case 0xa0:
            {iBitrate = 192*1000;}break;
            case 0xb0:
            {iBitrate = 224*1000;}break;
            case 0xc0:
            {iBitrate = 256*1000;}break;
            case 0xd0:
            {iBitrate = 320*1000;}break;
            case 0xe0:
            {iBitrate = 384*1000;}break;
            default:
            {bRate = false;}break;
            }
        }
        else if(iLayout ==3)
        {
            switch((pHeaderMax[2]&0xf0))
            {
            case 0x10:
            {iBitrate = 8*1000;}break;
            case 0x20:
            {iBitrate = 16*1000;}break;
            case 0x30:
            {iBitrate = 24*1000;}break;
            case 0x40:
            {iBitrate = 32*1000;}break;
            case 0x50:
            {iBitrate = 64*1000;}break;
            case 0x60:
            {iBitrate = 80*1000;}break;
            case 0x70:
            {iBitrate = 56*1000;}break;
            case 0x80:
            {iBitrate = 64*1000;}break;
            case 0x90:
            {iBitrate = 128*1000;}break;
            case 0xa0:
            {iBitrate = 160*1000;}break;
            case 0xb0:
            {iBitrate = 112*1000;}break;
            case 0xc0:
            {iBitrate = 128*1000;}break;
            case 0xd0:
            {iBitrate = 256*1000;}break;
            case 0xe0:
            {iBitrate = 320*1000;}break;
            default:
            {bRate = false;}break;
            }
        }
        else
        {
            bRate = false;
        }
    }
    else
    {
        bRate = false;
    }
    if(!bRate)
    {
        return 0;
    }
    float fTemp = (float)iSize/(float)iBitrate;
    fTemp = fTemp*8;
    iTime = (int)fTemp;
    return iTime;
}

QString GetInFo::secondToTime(int iTime)
{
    int iHour=iTime/(60*60);
    int iMin = (iTime - iHour*60*60)/60;
    int iSec = iTime - iHour*3600 -iMin*60;
    QString strTime = "";
    strTime.append(QString::number(iHour,10));
    strTime.append(":");
    strTime.append(QString::number(iMin,10));
    strTime.append(":");
    strTime.append(QString::number(iSec,10));
    return strTime;
}

int GetInFo::findXing(char *pStart, int iLen)
{
    int iPosition=0;
    if(!pStart)
        return -1;
    if(iLen<=4)
        return -1;
    int iHead = 0;
    bool bExit = false;
    for(int i=0;i<iLen;i++)
    {
        if(pStart[i]==0x58)
        {
            if((pStart[i+1]==0x69)&&(pStart[i+2]==0x6e)&&(pStart[i+3]==0x67))
            {
               iHead = i;
               bExit = true;
               break;
            }
        }
        i+=1;
    }
    if(!bExit)
      return -1;
    bool bFind = false;
    int iMPEG = 0;
    if(iHead>32)
    {
      iMPEG = iHead-32-4;
      QString strOut = chartobit(pStart[iMPEG]);
      strOut.append(" ");
      strOut.append(chartobit(pStart[iMPEG+1]));
      strOut.append(" ");
      strOut.append(chartobit(pStart[iMPEG+2]));
      strOut.append(" ");
      strOut.append(chartobit(pStart[iMPEG+3]));
      bFind = isHeader(&pStart[iMPEG],3);

      if(!bFind)
      {
          iMPEG = iHead-17-4;
          bFind = isHeader(&pStart[iMPEG],3);
          if(!bFind)
          {
              iMPEG = iHead-9-4;
              bFind = isHeader(&pStart[iMPEG],3);
          }
      }
    }
    else if(17<iHead<32)
    {
        iMPEG = iHead-17-4;
        bFind = isHeader(&pStart[iMPEG],3);
        if(!bFind)
        {
           iMPEG = iHead-9-4;
           bFind = isHeader(&pStart[iMPEG],3);
        }
    }
    else if(9<iHead<17)
    {
        iMPEG = iHead-9-4;
        bFind = isHeader(&pStart[iMPEG],3);
    }
    if(bFind)
    {
       iPosition = iMPEG;
    }
    else
        iPosition = -1;
    return iPosition;
}

bool GetInFo::isHeader(char *pHead, int iLen)
{
    QString strOut = chartobit(pHead[0]);
    strOut.append(" ");
    strOut.append(chartobit(pHead[1]));
    strOut.append(" ");
    strOut.append(chartobit(pHead[2]));
    if(!pHead)
        return false;
    if(iLen!=3)
    {
       return false;
    }
    if((pHead[0]&0xff)!=0xff)
    {
        //qDebug()<<"First byte is not 0xff!";
        return false;
    }
    if((pHead[1]&0xff)<= 0xe0)
    {
        //qDebug()<<"Second byte <= 0xe0";
        return false;
    }
    if((pHead[1]&(0x03<<3))==0x08)
    {
        //qDebug()<<"Second byte 0x03<<3 == 0x08";
        return false;
    }
    if((pHead[1]&(0x3<<1))==0x0)
    {
        //qDebug()<<"Second byte 0x03<<1 == 0x0";
        return false;
    }
    if((pHead[2]&0xf0)==0xf0)
    {
        //qDebug()<<"Third byte == 0xf0";
        return false;
    }
    if((pHead[2]&0xf0)==0x00)
    {
        //qDebug()<<"Third byte == 0x00";
        return false;
    }
    if((pHead[2]&0x0c)==0x0c)
    {
        //qDebug()<<"Third byte &0x0c == 0x0c";
        return false;
    }
    return true;
}

int GetInFo::comLayout(char *pHead, int iLen)
{
    if(iLen!=3)
        return -1;
    if(!pHead)
        return -1;
    int iLayout = -1;
    switch((pHead[1]&(0x3<<1)))
    {
    case 0x06:
    {iLayout=1;}break;
    case 0x02:
    {iLayout=3;}break;
    case 0x04:
    {iLayout=2;}break;
    default:{iLayout = -1;}break;
    }
    return iLayout;
}

int GetInFo::comVersion(char *pHead, int iLen)
{
    if(iLen!=3)
        return -1;
    if(!pHead)
        return -1;
    int iVersion = -1;
    switch((pHead[1]&(0x3<<3)))
    {
    case 0x18:
    {iVersion=1;}break;
    case 0x10:
    {iVersion=2;}break;
    case 0x00:
    {iVersion=3;}break;
    default:{iVersion = -1;}break;
    }
    return iVersion;
}

int GetInFo::getSample(int iVersion, int iLayout)
{
    int iSample = -1;
    if(iVersion==1)
    {
        switch(iLayout)
        {
        case 1:
        {iSample=384;}break;
        case 2:
        {iSample=1152;}break;
        case 3:
        {iSample=1152;}break;
        }
    }
    else if(iVersion==2)
    {
        switch(iLayout)
        {
        case 1:
        {iSample=384;}break;
        case 2:
        {iSample=1152;}break;
        case 3:
        {iSample=576;}break;
        }
    }
    else if(iVersion==3)
    {
        switch(iLayout)
        {
        case 1:
        {iSample=384;}break;
        case 2:
        {iSample=1152;}break;
        case 3:
        {iSample=576;}break;
        }
    }
    return iSample;
}

int GetInFo::getSampleRate(char *pHead, int iLen, int iVersion)
{
    if(!pHead)
        return -1;
    if(iLen!=3)
        return -1;
    int iSamRate = -1;
    if(iVersion==1)
    {
        switch((pHead[2]&(0x3<<2)))
        {
        case 0x00:
        {iSamRate=44100;}break;
        case 0x04:
        {iSamRate=48000;}break;
        case 0x08:
        {iSamRate=32000;}break;

        }
    }
    else if(iVersion==2)
    {
        switch((pHead[2]&(0x3<<2)))
        {
        case 0x00:
        {iSamRate=22050;}break;
        case 0x04:
        {iSamRate=24000;}break;
        case 0x08:
        {iSamRate=16000;}break;

        }
    }
    else if(iVersion==3)
    {
        switch((pHead[2]&(0x3<<2)))
        {
        case 0x00:
        {iSamRate=25000;}break;
        case 0x04:
        {iSamRate=11025;}break;
        case 0x08:
        {iSamRate=8000;}break;

        }
    }
    return iSamRate;
}

int GetInFo::getAllFrames(char *pFrame, int iLen)
{
    if(!pFrame)
        return -1;
    if(iLen!=4)
        return -1;
    int iFrames = 0;
    char pNum[4];
    memset(pNum,0,4);
    pNum[3]=pFrame[0];
    pNum[2]=pFrame[1];
    pNum[1]=pFrame[2];
    pNum[0]=pFrame[3];
    memcpy(&iFrames,pNum,sizeof(int));
    return iFrames;
}

int GetInFo::getMPEGTime(QString strFile)
{
    int iTime = 0;
    vecHeader.clear();
    QFile file(strFile);
    if(!file.exists())
        return 0;
    if(file.size()<=8)
        return 0;
    int iPart = 0;
    if(file.size()>4096)
        iPart=4096;
    else
    {
       iPart = file.size()/2;
    }
    if(file.isOpen())
        file.close();
    file.open(QFile::ReadOnly);
    QByteArray dataArry = file.read(iPart);
    file.close();
    int iXing = findXing(dataArry.data(),dataArry.size());
    bool bXing = false;
    if(iXing>0)
    {//find Xing
        int iFramePos = iXing+44;
        int iAllFrames = getAllFrames(dataArry.data()+iFramePos,4);
        int iVersion = comVersion(dataArry.data()+iXing,3);
        int iLayout = comLayout(dataArry.data()+iXing,3);
        int iSamples = getSample(iVersion,iLayout);
        int isamRate = getSampleRate(dataArry.data()+iXing,3,iVersion);
        if(iAllFrames>0&&iSamples>0&&isamRate>0)
        {
           bXing = true;
           iTime = iAllFrames*iSamples/isamRate;
        }
    }
    if(!bXing)
    {
       dataArry.clear();
       int iCMP = 0;//test number
       bool bBig = false;
       if(file.size()>100*5120)
       {
         bBig = true;
         iPart = 5120;
       }
       else
       {
          iPart = file.size()/2;
       }
       if(file.isOpen())
           file.close();
       file.open(QFile::ReadOnly);
       file.seek(0);
       if(bBig)
       {
           while(iCMP<50)
           {
             iCMP++;
             int iPos = iPart*iCMP;
             iPos += (int)(file.size()/3);
             if((iPos+iPart)<file.size())
             {
                 file.seek(iPos);
             }
             dataArry = file.read(iPart);
             getHeadInfo(dataArry.data(),dataArry.size());
             if(vecHeader.size()>0)
                 break;
           }
           file.close();
           iTime=infoToTime(file.size());
       }
       else
       {
           dataArry = file.read(file.size()/2);
           getHeadInfo(dataArry.data(),dataArry.size());
           if(!vecHeader.isEmpty())
           {
              iTime=infoToTime(file.size());
           }
           else
           {
             dataArry = file.read(file.size()/2);
             getHeadInfo(dataArry.data(),dataArry.size());
             if(!vecHeader.isEmpty())
             {
               iTime = infoToTime(file.size());
             }
           }
           file.close();
       }
    }
    return iTime;
}




