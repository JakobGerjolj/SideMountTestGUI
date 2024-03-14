#ifndef STORAGE_H
#define STORAGE_H
#include <map>
#include <string>

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


private:
    inline static PinDataMap m_PinDataMap;
    inline static LedDataMap m_LedDataMap;
    inline static bool m_is_HAL_OK;
    inline static bool m_is_ZERO_OK;
    inline static ButtonDataMap m_ButtonDataMap;
    inline static bool m_is_NFC_OK;
    inline static bool m_is_CAN_TX_OK;
    inline static bool m_is_CAN_RX_OK;



};

#endif // STORAGE_H
