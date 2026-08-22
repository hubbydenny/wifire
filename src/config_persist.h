#pragma once
#include "config.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdint>
#include <unistd.h>
#include <sys/stat.h>

static const unsigned char WIFIRE_KEY[] = {0x57,0x69,0x46,0x69,0x72,0x65,0x32,0x30,0x32,0x36};
static const size_t WIFIRE_KEY_LEN = sizeof(WIFIRE_KEY);

static inline std::string xorCrypt(const std::string& data) {
    std::string out = data;
    for (size_t i = 0; i < out.size(); i++)
        out[i] ^= WIFIRE_KEY[i % WIFIRE_KEY_LEN];
    return out;
}

static inline std::string getConfigPath() {
    const char* home = getenv("HOME");
    if (!home) home = "/tmp";
    return std::string(home) + "/.config/wifire/config";
}

static inline std::string getAutostartPath() {
    const char* home = getenv("HOME");
    if (!home) home = "/tmp";
    return std::string(home) + "/.config/autostart/wifire.desktop";
}

static inline void ensureConfigDir() {
    const char* home = getenv("HOME");
    if (!home) return;
    std::string confDir = std::string(home) + "/.config/wifire";
    std::string autoDir = std::string(home) + "/.config/autostart";
    mkdir(confDir.c_str(), 0755);
    mkdir(autoDir.c_str(), 0755);
}

static inline void saveConfig() {
    ensureConfigDir();
    std::ostringstream ss;
    ss << "theme=" << (int)g_Config.theme << "\n";
    ss << "fontSize=" << Config::fontSize << "\n";
    ss << "autoConnect=" << (int)Config::autoConnect << "\n";
    ss << "autostart=" << (int)Config::autostart << "\n";
    ss << "scanInterval=" << Config::scanInterval << "\n";
    ss << "language=" << Config::language << "\n";
    ss << "lastSsid=" << Config::lastSsid << "\n";
    ss << "lastPassword=" << Config::lastPassword << "\n";

    ImVec4 c = g_CustomColors.WindowBg;
    ss << "cWindowBg=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.ChildBg;
    ss << "cChildBg=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.PopupBg;
    ss << "cPopupBg=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.Border;
    ss << "cBorder=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.FrameBg;
    ss << "cFrameBg=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.FrameBgHovered;
    ss << "cFrameBgHovered=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.FrameBgActive;
    ss << "cFrameBgActive=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TitleBg;
    ss << "cTitleBg=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TitleBgActive;
    ss << "cTitleBgActive=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.ScrollbarBg;
    ss << "cScrollbarBg=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.ScrollbarGrab;
    ss << "cScrollbarGrab=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.Button;
    ss << "cButton=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.ButtonHovered;
    ss << "cButtonHovered=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.ButtonActive;
    ss << "cButtonActive=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.Header;
    ss << "cHeader=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.HeaderHovered;
    ss << "cHeaderHovered=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.HeaderActive;
    ss << "cHeaderActive=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.CheckMark;
    ss << "cCheckMark=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.SliderGrab;
    ss << "cSliderGrab=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.SliderGrabActive;
    ss << "cSliderGrabActive=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.Text;
    ss << "cText=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TextDisabled;
    ss << "cTextDisabled=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.Tab;
    ss << "cTab=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TabHovered;
    ss << "cTabHovered=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TabSelected;
    ss << "cTabSelected=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TabSelectedOverline;
    ss << "cTabSelectedOverline=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TabDimmed;
    ss << "cTabDimmed=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";
    c = g_CustomColors.TabDimmedSelected;
    ss << "cTabDimmedSelected=" << c.x << "," << c.y << "," << c.z << "," << c.w << "\n";

    std::string plain = ss.str();
    std::string encrypted = xorCrypt(plain);

    std::string path = getConfigPath();
    std::ofstream f(path, std::ios::binary);
    if (f.is_open()) {
        unsigned int magic = 0x57463236;
        f.write((const char*)&magic, 4);
        uint32_t len = (uint32_t)encrypted.size();
        f.write((const char*)&len, 4);
        f.write(encrypted.data(), encrypted.size());
    }
}

static inline void parseLine(const std::string& line) {
    auto eq = line.find('=');
    if (eq == std::string::npos) return;
    std::string key = line.substr(0, eq);
    std::string val = line.substr(eq + 1);

    if (key == "theme") g_Config.theme = (Theme)std::stoi(val);
    else if (key == "fontSize") Config::fontSize = std::stoi(val);
    else if (key == "autoConnect") Config::autoConnect = (bool)std::stoi(val);
    else if (key == "autostart") Config::autostart = (bool)std::stoi(val);
    else if (key == "scanInterval") Config::scanInterval = std::stoi(val);
    else if (key == "language") Config::language = std::stoi(val);
    else if (key == "lastSsid") Config::lastSsid = val;
    else if (key == "lastPassword") Config::lastPassword = val;

    if (key.size() > 1 && key[0] == 'c') {
        float r = 0, g = 0, b = 0, a = 1;
        char comma;
        std::istringstream vs(val);
        vs >> r >> comma >> g >> comma >> b >> comma >> a;
        ImVec4 color(r, g, b, a);
        std::string cname = key.substr(1);
        if (cname == "WindowBg") g_CustomColors.WindowBg = color;
        else if (cname == "ChildBg") g_CustomColors.ChildBg = color;
        else if (cname == "PopupBg") g_CustomColors.PopupBg = color;
        else if (cname == "Border") g_CustomColors.Border = color;
        else if (cname == "FrameBg") g_CustomColors.FrameBg = color;
        else if (cname == "FrameBgHovered") g_CustomColors.FrameBgHovered = color;
        else if (cname == "FrameBgActive") g_CustomColors.FrameBgActive = color;
        else if (cname == "TitleBg") g_CustomColors.TitleBg = color;
        else if (cname == "TitleBgActive") g_CustomColors.TitleBgActive = color;
        else if (cname == "ScrollbarBg") g_CustomColors.ScrollbarBg = color;
        else if (cname == "ScrollbarGrab") g_CustomColors.ScrollbarGrab = color;
        else if (cname == "Button") g_CustomColors.Button = color;
        else if (cname == "ButtonHovered") g_CustomColors.ButtonHovered = color;
        else if (cname == "ButtonActive") g_CustomColors.ButtonActive = color;
        else if (cname == "Header") g_CustomColors.Header = color;
        else if (cname == "HeaderHovered") g_CustomColors.HeaderHovered = color;
        else if (cname == "HeaderActive") g_CustomColors.HeaderActive = color;
        else if (cname == "CheckMark") g_CustomColors.CheckMark = color;
        else if (cname == "SliderGrab") g_CustomColors.SliderGrab = color;
        else if (cname == "SliderGrabActive") g_CustomColors.SliderGrabActive = color;
        else if (cname == "Text") g_CustomColors.Text = color;
        else if (cname == "TextDisabled") g_CustomColors.TextDisabled = color;
        else if (cname == "Tab") g_CustomColors.Tab = color;
        else if (cname == "TabHovered") g_CustomColors.TabHovered = color;
        else if (cname == "TabSelected") g_CustomColors.TabSelected = color;
        else if (cname == "TabSelectedOverline") g_CustomColors.TabSelectedOverline = color;
        else if (cname == "TabDimmed") g_CustomColors.TabDimmed = color;
        else if (cname == "TabDimmedSelected") g_CustomColors.TabDimmedSelected = color;
    }
}

static inline void loadConfig() {
    std::string path = getConfigPath();
    std::ifstream f(path, std::ios::binary);
    if (!f.is_open()) return;

    unsigned int magic = 0;
    f.read((char*)&magic, 4);
    if (magic != 0x57463236) return;

    uint32_t len = 0;
    f.read((char*)&len, 4);
    if (len > 1024 * 1024) return;

    std::string encrypted(len, '\0');
    f.read(&encrypted[0], len);
    f.close();

    std::string plain = xorCrypt(encrypted);
    std::istringstream ss(plain);
    std::string line;
    while (std::getline(ss, line))
        parseLine(line);
}

static inline void setAutostart(bool enabled) {
    ensureConfigDir();
    std::string path = getAutostartPath();
    if (enabled) {
        char exePath[4096];
        ssize_t len = readlink("/proc/self/exe", exePath, sizeof(exePath) - 1);
        if (len == -1) return;
        exePath[len] = '\0';

        std::ofstream f(path);
        if (f.is_open()) {
            f << "[Desktop Entry]\n";
            f << "Type=Application\n";
            f << "Name=WiFire\n";
            f << "Exec=" << exePath << "\n";
            f << "Hidden=false\n";
            f << "NoDisplay=false\n";
            f << "X-GNOME-Autostart-enabled=true\n";
        }
    } else {
        remove(path.c_str());
    }
}

static inline bool isAutostartEnabled() {
    struct stat st;
    return stat(getAutostartPath().c_str(), &st) == 0;
}

// --- Localization ---

enum Lang { LANG_EN = 0, LANG_RU = 1 };

struct LocStrings {
    const char* tabWifi;
    const char* tabStats;
    const char* tabSettings;
    const char* search;
    const char* networksFound;
    const char* ssid;
    const char* signal;
    const char* password;
    const char* connect;
    const char* cancel;
    const char* interfaces;
    const char* status;
    const char* up;
    const char* down;
    const char* download;
    const char* upload;
    const char* theme;
    const char* apply;
    const char* customColors;
    const char* applyColors;
    const char* fontSize;
    const char* fontSizeRestart;
    const char* language;
    const char* autoConnect;
    const char* autostart;
    const char* scanInterval;
    const char* connected;
    const char* connecting;
    const char* connectFailed;
    const char* notConnected;
    const char* noWireless;
};

static const LocStrings g_en = {
    "Wifi", "Stats", "Settings",
    "Search...", "%d networks found",
    "SSID", "Signal", "Password",
    "Connect", "Cancel",
    "Interfaces", "Status",
    "UP", "DOWN",
    "Download", "Upload",
    "Theme", "Apply", "Custom colors", "Apply colors",
    "Font Size", "Font Size (restart to apply)",
    "Language", "Auto-connect to last network",
    "Autostart on login", "Scan interval (sec)",
    "Connected", "Connecting", "Connection failed", "Not connected", "No wireless interface"
};

static const LocStrings g_ru = {
    "WiFi", "Статистика", "Настройки",
    "Поиск...", "Найдено сетей: %d",
    "SSID", "Сигнал", "Пароль",
    "Подключить", "Отмена",
    "Интерфейсы", "Статус",
    "ВКЛ", "ВЫКЛ",
    "Загрузка", "Отдача",
    "Тема", "Применить", "Пользовательские цвета", "Применить цвета",
    "Размер шрифта", "Размер шрифта (перезапуск)",
    "Язык", "Автоподключение к последней сети",
    "Автозапуск при входе", "Интервал сканирования (сек)",
    "Подключено", "Подключение...", "Ошибка подключения", "Не подключено", "Нет беспроводного интерфейса"
};

static inline const LocStrings& loc() {
    return Config::language == LANG_RU ? g_ru : g_en;
}
