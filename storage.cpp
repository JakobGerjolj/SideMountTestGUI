#include "storage.h"

void storage::addPinData(const std::string &pinName)
{
   m_PinDataMap[pinName]= std::make_pair(false,0);

}

std::pair<bool, float> storage::getPinData(const std::string pinName)
{
    return m_PinDataMap[pinName];

}

void storage::setPinData(const std::string &pinName, bool isOK, float pinValue)
{
    m_PinDataMap[pinName].first=isOK;
    m_PinDataMap[pinName].second=pinValue;

}

void storage::addLedData(const std::string &ledName)
{
    m_LedDataMap[ledName]=std::make_pair(false, "");

}

std::pair<bool, std::string> storage::getLedData(const std::string ledName)
{
    return m_LedDataMap[ledName];
}

void storage::setLedData(const std::string &ledName, bool isOK, std::string desc)
{
    m_LedDataMap[ledName].first=isOK;
    m_LedDataMap[ledName].second=desc;

}

void storage::addButtonData(const std::string &buttonName)
{
    m_ButtonDataMap[buttonName]=std::make_pair(false,"");

}

void storage::setButtonData(const std::string &buttonName, bool isOK, std::string desc)
{
    m_ButtonDataMap[buttonName].first=isOK;
    m_ButtonDataMap[buttonName].second=desc;

}

std::pair<bool, std::string> storage::getButtonData(const std::string &buttonName)
{
    return m_ButtonDataMap[buttonName];

}

void storage::setNFCStatus(bool nfcStatus)
{
    m_is_NFC_OK=nfcStatus;

}

bool storage::getNFCStatus()
{

    return m_is_NFC_OK;
}

void storage::setTEMPStatus(bool tempStatus)
{
    m_is_TEMP_OK = tempStatus;
}

bool storage::getTEMPStatus()
{

    return m_is_TEMP_OK;

}

void storage::setHALStatus(bool halStatus)
{
    m_is_HAL_OK=halStatus;

}

bool storage::getHALStatus()
{
    return m_is_HAL_OK;
}

void storage::setZEROStatus(bool zeroStatus)
{
    m_is_ZERO_OK=zeroStatus;
}

bool storage::getZEROStatus()
{
    return m_is_ZERO_OK;
}

void storage::setSERIAL(const std::string& s)
{

    m_Serial_number=s;
}

std::string storage::getSERIAL()
{
    return m_Serial_number;
}

void storage::setDateTime(QDateTime date)
{
    m_Date_Time=date;
}

QDateTime storage::getDateTime()
{
    return m_Date_Time;
}

void storage::setEmployee(const std::string& s)
{
    m_employee = s;
}

std::string storage::getEmployee()
{
    return m_employee;
}

LedDataMap storage::getLedMap()
{
    return m_LedDataMap;

}

bool storage::areAllLEDsOK()
{
    bool temp=true;
    for(auto it = m_LedDataMap.begin(); it!=m_LedDataMap.end();++it){
        if(it->second.first==false){
            temp=false;

        }

    }
    return temp;

}

bool storage::areAllButtonsOK()
{

    bool temp=true;
    for(auto it = m_ButtonDataMap.begin(); it!=m_ButtonDataMap.end();++it){
        if(it->second.first==false){
            temp=false;

        }

    }

    return temp;
}

void storage::setHALDesc(const std::string& s)
{
    m_HAL_desc=s;

}

std::string storage::getHALDesc()
{
    return m_HAL_desc;
}

void storage::setNFCDesc(const std::string& s)
{
    m_NFC_desc = s;

}

std::string storage::getNFCDesc()
{
    return m_NFC_desc;

}

void storage::setZERODesc(const std::string& s)
{
    m_ZERO_desc = s;
}

std::string storage::getZERODesc()
{
    return m_NFC_desc;
}

void storage::setTEMPDesc(const std::string & s)
{
    m_TEMP_desc = s;
}

std::string storage::getTEMPDesc()
{
    return m_TEMP_desc;
}

void storage::setCANTX_OK(bool b)
{
    m_is_CAN_TX_OK=b;
}

bool storage::getCANTX_OK()
{
    return m_is_CAN_TX_OK;
}

void storage::setCANRX_OK(bool b)
{
    m_is_CAN_RX_OK=b;
}

bool storage::getCANRX_OK()
{
    return m_is_CAN_RX_OK;
}

std::string storage::getPA2Value()
{
    return m_PA2;
}

std::string storage::getPA3Value()
{
    return m_PA3;
}

void storage::setPA2Value(const std::string & s)
{
    m_PA2 = s;
}

void storage::setPA3Value(const std::string & s)
{
    m_PA3 = s;
}



