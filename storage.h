#ifndef STORAGE_H
#define STORAGE_H
#include <map>
#include <string>
#include <QDateTime>

using PinDataMap=std::map<std::string, std::pair<bool,float>>;
using LedDataMap=std::map<std::string, std::pair<bool, std::string>>;
using ButtonDataMap=std::map<std::string, std::pair<bool, std::string>>;

class storage
{
public:
    static void addPinData(const std::string& pinName);
    static std::pair<bool,float> getPinData(const std::string pinName);
    static void setPinData(const std::string& pinName, bool isOK, float pinValue);
    static void addLedData(const std::string& ledName);
    static std::pair<bool,std::string> getLedData(const std::string ledName);
    static void setLedData(const std::string& ledName, bool isOK, std::string desc);
    static void addButtonData(const std::string& buttonName);
    static void setButtonData(const std::string& buttonName, bool isOK, std::string desc);
    static std::pair<bool,std::string> getButtonData(const std::string& buttonName);
    static void setNFCStatus(bool);
    static bool getNFCStatus();
    static void setHALStatus(bool);
    static bool getHALStatus();
    static void setZEROStatus(bool);
    static bool getZEROStatus();
    static void setSERIAL(const std::string&);
    static std::string getSERIAL();
    static void setDateTime(QDateTime);
    static QDateTime getDateTime();
    static void setEmployee(const std::string&);
    static std::string getEmployee();
    static LedDataMap getLedMap();
    static bool areAllLEDsOK();
    static bool areAllButtonsOK();
    static void setHALDesc(const std::string&);
    static std::string getHALDesc();
    static void setNFCDesc(const std::string&);
    static std::string getNFCDesc();
    static void setZERODesc(const std::string&);
    static std::string getZERODesc();
    static void setCANTX_OK(bool);
    static bool getCANTX_OK();
    static void setCANRX_OK(bool);
    static bool getCANRX_OK();



private:
    inline static PinDataMap m_PinDataMap;
    inline static LedDataMap m_LedDataMap;
    inline static bool m_is_HAL_OK;
    inline static bool m_is_ZERO_OK;
    inline static ButtonDataMap m_ButtonDataMap;
    inline static bool m_is_NFC_OK;
    inline static bool m_is_CAN_TX_OK;
    inline static bool m_is_CAN_RX_OK;
    inline static std::string m_Serial_number;
    inline static QDateTime m_Date_Time;
    inline static std::string m_employee;
    inline static std::string m_HAL_desc;
    inline static std::string m_NFC_desc;
    inline static std::string m_ZERO_desc;

};

#endif // STORAGE_H
