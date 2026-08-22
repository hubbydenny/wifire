#pragma once
#include <string>
#include <vector>
#include "imgui.h"

namespace Config {
  bool wifi_list = false;
  int fontSize = 15;
  bool autoConnect = false;
  bool autostart = false;
  int scanInterval = 0.5;
  int language = 0;
  std::string lastSsid;
  std::string lastPassword;
};

struct CustomColors {
    ImVec4 WindowBg        = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    ImVec4 ChildBg         = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
    ImVec4 PopupBg         = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
    ImVec4 Border          = ImVec4(0.25f, 0.25f, 0.28f, 0.60f);
    ImVec4 FrameBg         = ImVec4(0.16f, 0.16f, 0.20f, 1.00f);
    ImVec4 FrameBgHovered  = ImVec4(0.22f, 0.22f, 0.28f, 1.00f);
    ImVec4 FrameBgActive   = ImVec4(0.28f, 0.28f, 0.35f, 1.00f);
    ImVec4 TitleBg         = ImVec4(0.08f, 0.08f, 0.10f, 1.00f);
    ImVec4 TitleBgActive   = ImVec4(0.12f, 0.12f, 0.16f, 1.00f);
    ImVec4 ScrollbarBg     = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    ImVec4 ScrollbarGrab   = ImVec4(0.30f, 0.30f, 0.35f, 1.00f);
    ImVec4 Button          = ImVec4(0.20f, 0.22f, 0.28f, 1.00f);
    ImVec4 ButtonHovered   = ImVec4(0.28f, 0.28f, 0.38f, 1.00f);
    ImVec4 ButtonActive    = ImVec4(0.35f, 0.35f, 0.48f, 1.00f);
    ImVec4 Header          = ImVec4(0.22f, 0.24f, 0.32f, 1.00f);
    ImVec4 HeaderHovered   = ImVec4(0.28f, 0.30f, 0.40f, 1.00f);
    ImVec4 HeaderActive    = ImVec4(0.35f, 0.38f, 0.50f, 1.00f);
    ImVec4 CheckMark       = ImVec4(0.45f, 0.56f, 0.98f, 1.00f);
    ImVec4 SliderGrab      = ImVec4(0.45f, 0.56f, 0.98f, 1.00f);
    ImVec4 SliderGrabActive= ImVec4(0.55f, 0.66f, 1.00f, 1.00f);
    ImVec4 Text            = ImVec4(0.92f, 0.92f, 0.95f, 1.00f);
    ImVec4 TextDisabled    = ImVec4(0.50f, 0.50f, 0.55f, 1.00f);
    ImVec4 Tab             = ImVec4(0.14f, 0.14f, 0.18f, 1.00f);
    ImVec4 TabHovered      = ImVec4(0.24f, 0.26f, 0.34f, 1.00f);
    ImVec4 TabSelected     = ImVec4(0.20f, 0.22f, 0.30f, 1.00f);
    ImVec4 TabSelectedOverline = ImVec4(0.45f, 0.56f, 0.98f, 1.00f);
    ImVec4 TabDimmed       = ImVec4(0.12f, 0.12f, 0.15f, 1.00f);
    ImVec4 TabDimmedSelected  = ImVec4(0.18f, 0.18f, 0.24f, 1.00f);
};
CustomColors g_CustomColors;

enum class Theme 
{
  Default,
  Dark,
  Cattppucin,
  Light,
  Ember,
  Custom
};

struct ThemeConfig {
  Theme theme = Theme::Default;
};
ThemeConfig g_Config;

struct ThemeItem_t {
 std::string name;
 Theme theme;
};

std::vector<ThemeItem_t> themes = 
{
  {"Default", Theme::Default},
  {"Dark", Theme::Dark },
  {"Cattppucin", Theme::Cattppucin },
  {"Light", Theme::Light },
  {"Ember", Theme::Ember },
  {"Custom", Theme::Custom }
};





