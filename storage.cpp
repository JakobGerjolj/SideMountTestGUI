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

void storage::setSERIAL(std::string s)
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

void storage::setEmployee(std::string s)
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



