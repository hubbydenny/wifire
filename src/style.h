#pragma once
#include "imgui.h"
#include "config.h"
#include "stb_image.h"
#include "../src/fonts/JetBrains.hpp"
#include <string>
#include <iostream>

static ImFont* g_Font = nullptr;

inline void LoadFont(int fontSize) {
    ImGuiIO& io = ImGui::GetIO();
    io.Fonts->Clear();
    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;
    g_Font = io.Fonts->AddFontFromMemoryTTF(JetBrainsFont, JetBrainsSize, (float)fontSize, &font_cfg, io.Fonts->GetGlyphRangesCyrillic());
    if (!g_Font) {
        std::cerr << "Error JetBrainsFont cannot load" << std::endl;
        g_Font = io.Fonts->AddFontDefault();
    }
}

inline void ApplyTheme(Theme theme) {
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 6.0f;
    style.FrameRounding = 4.0f;
    style.GrabRounding = 4.0f;
    style.ScrollbarRounding = 4.0f;
    style.FramePadding = ImVec2(8, 4);
    style.ItemSpacing = ImVec2(8, 6);
    style.WindowPadding = ImVec2(12, 12);

    ImVec4* colors = style.Colors;

    switch (theme) {
    case Theme::Default:
        colors[ImGuiCol_WindowBg]        = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
        colors[ImGuiCol_ChildBg]         = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
        colors[ImGuiCol_PopupBg]         = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
        colors[ImGuiCol_Border]          = ImVec4(0.25f, 0.25f, 0.28f, 0.60f);
        colors[ImGuiCol_FrameBg]         = ImVec4(0.16f, 0.16f, 0.20f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.22f, 0.22f, 0.28f, 1.00f);
        colors[ImGuiCol_FrameBgActive]   = ImVec4(0.28f, 0.28f, 0.35f, 1.00f);
        colors[ImGuiCol_TitleBg]         = ImVec4(0.08f, 0.08f, 0.10f, 1.00f);
        colors[ImGuiCol_TitleBgActive]   = ImVec4(0.12f, 0.12f, 0.16f, 1.00f);
        colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
        colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.30f, 0.30f, 0.35f, 1.00f);
        colors[ImGuiCol_Button]          = ImVec4(0.20f, 0.22f, 0.28f, 1.00f);
        colors[ImGuiCol_ButtonHovered]   = ImVec4(0.28f, 0.28f, 0.38f, 1.00f);
        colors[ImGuiCol_ButtonActive]    = ImVec4(0.35f, 0.35f, 0.48f, 1.00f);
        colors[ImGuiCol_Header]          = ImVec4(0.22f, 0.24f, 0.32f, 1.00f);
        colors[ImGuiCol_HeaderHovered]   = ImVec4(0.28f, 0.30f, 0.40f, 1.00f);
        colors[ImGuiCol_HeaderActive]    = ImVec4(0.35f, 0.38f, 0.50f, 1.00f);
        colors[ImGuiCol_CheckMark]       = ImVec4(0.45f, 0.56f, 0.98f, 1.00f);
        colors[ImGuiCol_SliderGrab]      = ImVec4(0.45f, 0.56f, 0.98f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]= ImVec4(0.55f, 0.66f, 1.00f, 1.00f);
        colors[ImGuiCol_Text]            = ImVec4(0.92f, 0.92f, 0.95f, 1.00f);
        colors[ImGuiCol_TextDisabled]    = ImVec4(0.50f, 0.50f, 0.55f, 1.00f);
        colors[ImGuiCol_Tab]             = ImVec4(0.14f, 0.14f, 0.18f, 1.00f);
        colors[ImGuiCol_TabHovered]      = ImVec4(0.24f, 0.26f, 0.34f, 1.00f);
        colors[ImGuiCol_TabSelected]     = ImVec4(0.20f, 0.22f, 0.30f, 1.00f);
        colors[ImGuiCol_TabSelectedOverline] = ImVec4(0.45f, 0.56f, 0.98f, 1.00f);
        colors[ImGuiCol_TabDimmed]       = ImVec4(0.12f, 0.12f, 0.15f, 1.00f);
        colors[ImGuiCol_TabDimmedSelected] = ImVec4(0.18f, 0.18f, 0.24f, 1.00f);
        break;

    case Theme::Dark:
        colors[ImGuiCol_WindowBg]        = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
        colors[ImGuiCol_ChildBg]         = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_PopupBg]         = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_Border]          = ImVec4(0.18f, 0.18f, 0.18f, 0.60f);
        colors[ImGuiCol_FrameBg]         = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.18f, 0.18f, 0.18f, 1.00f);
        colors[ImGuiCol_FrameBgActive]   = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
        colors[ImGuiCol_TitleBg]         = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
        colors[ImGuiCol_TitleBgActive]   = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
        colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
        colors[ImGuiCol_Button]          = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_ButtonHovered]   = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
        colors[ImGuiCol_ButtonActive]    = ImVec4(0.28f, 0.28f, 0.28f, 1.00f);
        colors[ImGuiCol_Header]          = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
        colors[ImGuiCol_HeaderHovered]   = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
        colors[ImGuiCol_HeaderActive]    = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
        colors[ImGuiCol_CheckMark]       = ImVec4(0.90f, 0.30f, 0.30f, 1.00f);
        colors[ImGuiCol_SliderGrab]      = ImVec4(0.90f, 0.30f, 0.30f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]= ImVec4(1.00f, 0.40f, 0.40f, 1.00f);
        colors[ImGuiCol_Text]            = ImVec4(0.88f, 0.88f, 0.88f, 1.00f);
        colors[ImGuiCol_TextDisabled]    = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);
        break;

    case Theme::Cattppucin:
        colors[ImGuiCol_WindowBg]        = ImVec4(0.13f, 0.13f, 0.20f, 1.00f);
        colors[ImGuiCol_ChildBg]         = ImVec4(0.15f, 0.15f, 0.22f, 1.00f);
        colors[ImGuiCol_PopupBg]         = ImVec4(0.15f, 0.15f, 0.22f, 1.00f);
        colors[ImGuiCol_Border]          = ImVec4(0.25f, 0.24f, 0.35f, 0.60f);
        colors[ImGuiCol_FrameBg]         = ImVec4(0.18f, 0.17f, 0.26f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.24f, 0.23f, 0.34f, 1.00f);
        colors[ImGuiCol_FrameBgActive]   = ImVec4(0.30f, 0.28f, 0.42f, 1.00f);
        colors[ImGuiCol_TitleBg]         = ImVec4(0.11f, 0.11f, 0.18f, 1.00f);
        colors[ImGuiCol_TitleBgActive]   = ImVec4(0.15f, 0.14f, 0.22f, 1.00f);
        colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.13f, 0.13f, 0.20f, 1.00f);
        colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.30f, 0.28f, 0.42f, 1.00f);
        colors[ImGuiCol_Button]          = ImVec4(0.22f, 0.21f, 0.32f, 1.00f);
        colors[ImGuiCol_ButtonHovered]   = ImVec4(0.30f, 0.28f, 0.42f, 1.00f);
        colors[ImGuiCol_ButtonActive]    = ImVec4(0.38f, 0.36f, 0.52f, 1.00f);
        colors[ImGuiCol_Header]          = ImVec4(0.24f, 0.23f, 0.34f, 1.00f);
        colors[ImGuiCol_HeaderHovered]   = ImVec4(0.32f, 0.30f, 0.44f, 1.00f);
        colors[ImGuiCol_HeaderActive]    = ImVec4(0.40f, 0.38f, 0.56f, 1.00f);
        colors[ImGuiCol_CheckMark]       = ImVec4(0.84f, 0.70f, 1.00f, 1.00f);
        colors[ImGuiCol_SliderGrab]      = ImVec4(0.84f, 0.70f, 1.00f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]= ImVec4(0.92f, 0.80f, 1.00f, 1.00f);
        colors[ImGuiCol_Text]            = ImVec4(0.90f, 0.88f, 0.98f, 1.00f);
        colors[ImGuiCol_TextDisabled]    = ImVec4(0.50f, 0.48f, 0.58f, 1.00f);
        break;

    case Theme::Light:
        colors[ImGuiCol_WindowBg]        = ImVec4(0.94f, 0.94f, 0.96f, 1.00f);
        colors[ImGuiCol_ChildBg]         = ImVec4(0.96f, 0.96f, 0.98f, 1.00f);
        colors[ImGuiCol_PopupBg]         = ImVec4(0.96f, 0.96f, 0.98f, 1.00f);
        colors[ImGuiCol_Border]          = ImVec4(0.78f, 0.78f, 0.82f, 0.60f);
        colors[ImGuiCol_FrameBg]         = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.90f, 0.90f, 0.94f, 1.00f);
        colors[ImGuiCol_FrameBgActive]   = ImVec4(0.84f, 0.84f, 0.90f, 1.00f);
        colors[ImGuiCol_TitleBg]         = ImVec4(0.90f, 0.90f, 0.94f, 1.00f);
        colors[ImGuiCol_TitleBgActive]   = ImVec4(0.84f, 0.84f, 0.90f, 1.00f);
        colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.94f, 0.94f, 0.96f, 1.00f);
        colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.78f, 0.78f, 0.82f, 1.00f);
        colors[ImGuiCol_Button]          = ImVec4(0.84f, 0.84f, 0.90f, 1.00f);
        colors[ImGuiCol_ButtonHovered]   = ImVec4(0.78f, 0.78f, 0.86f, 1.00f);
        colors[ImGuiCol_ButtonActive]    = ImVec4(0.70f, 0.70f, 0.80f, 1.00f);
        colors[ImGuiCol_Header]          = ImVec4(0.84f, 0.84f, 0.90f, 1.00f);
        colors[ImGuiCol_HeaderHovered]   = ImVec4(0.78f, 0.78f, 0.86f, 1.00f);
        colors[ImGuiCol_HeaderActive]    = ImVec4(0.70f, 0.70f, 0.80f, 1.00f);
        colors[ImGuiCol_CheckMark]       = ImVec4(0.26f, 0.40f, 0.86f, 1.00f);
        colors[ImGuiCol_SliderGrab]      = ImVec4(0.26f, 0.40f, 0.86f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]= ImVec4(0.20f, 0.34f, 0.78f, 1.00f);
        colors[ImGuiCol_Text]            = ImVec4(0.12f, 0.12f, 0.15f, 1.00f);
        colors[ImGuiCol_TextDisabled]    = ImVec4(0.55f, 0.55f, 0.60f, 1.00f);
        break;

    case Theme::Ember:
        colors[ImGuiCol_WindowBg]        = ImVec4(0.10f, 0.06f, 0.04f, 1.00f);
        colors[ImGuiCol_ChildBg]         = ImVec4(0.12f, 0.07f, 0.05f, 1.00f);
        colors[ImGuiCol_PopupBg]         = ImVec4(0.12f, 0.07f, 0.05f, 1.00f);
        colors[ImGuiCol_Border]          = ImVec4(0.28f, 0.16f, 0.10f, 0.60f);
        colors[ImGuiCol_FrameBg]         = ImVec4(0.16f, 0.10f, 0.06f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.24f, 0.14f, 0.08f, 1.00f);
        colors[ImGuiCol_FrameBgActive]   = ImVec4(0.30f, 0.18f, 0.10f, 1.00f);
        colors[ImGuiCol_TitleBg]         = ImVec4(0.08f, 0.04f, 0.02f, 1.00f);
        colors[ImGuiCol_TitleBgActive]   = ImVec4(0.12f, 0.06f, 0.04f, 1.00f);
        colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.10f, 0.06f, 0.04f, 1.00f);
        colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.30f, 0.18f, 0.10f, 1.00f);
        colors[ImGuiCol_Button]          = ImVec4(0.22f, 0.12f, 0.06f, 1.00f);
        colors[ImGuiCol_ButtonHovered]   = ImVec4(0.32f, 0.18f, 0.08f, 1.00f);
        colors[ImGuiCol_ButtonActive]    = ImVec4(0.42f, 0.22f, 0.10f, 1.00f);
        colors[ImGuiCol_Header]          = ImVec4(0.24f, 0.14f, 0.08f, 1.00f);
        colors[ImGuiCol_HeaderHovered]   = ImVec4(0.34f, 0.20f, 0.10f, 1.00f);
        colors[ImGuiCol_HeaderActive]    = ImVec4(0.44f, 0.26f, 0.12f, 1.00f);
        colors[ImGuiCol_CheckMark]       = ImVec4(1.00f, 0.50f, 0.15f, 1.00f);
        colors[ImGuiCol_SliderGrab]      = ImVec4(1.00f, 0.50f, 0.15f, 1.00f);
        colors[ImGuiCol_SliderGrabActive]= ImVec4(1.00f, 0.60f, 0.20f, 1.00f);
        colors[ImGuiCol_Text]            = ImVec4(0.95f, 0.80f, 0.68f, 1.00f);
        colors[ImGuiCol_TextDisabled]    = ImVec4(0.55f, 0.42f, 0.35f, 1.00f);
        break;

    case Theme::Custom:
        colors[ImGuiCol_WindowBg]           = g_CustomColors.WindowBg;
        colors[ImGuiCol_ChildBg]            = g_CustomColors.ChildBg;
        colors[ImGuiCol_PopupBg]            = g_CustomColors.PopupBg;
        colors[ImGuiCol_Border]             = g_CustomColors.Border;
        colors[ImGuiCol_FrameBg]            = g_CustomColors.FrameBg;
        colors[ImGuiCol_FrameBgHovered]     = g_CustomColors.FrameBgHovered;
        colors[ImGuiCol_FrameBgActive]      = g_CustomColors.FrameBgActive;
        colors[ImGuiCol_TitleBg]            = g_CustomColors.TitleBg;
        colors[ImGuiCol_TitleBgActive]      = g_CustomColors.TitleBgActive;
        colors[ImGuiCol_ScrollbarBg]        = g_CustomColors.ScrollbarBg;
        colors[ImGuiCol_ScrollbarGrab]      = g_CustomColors.ScrollbarGrab;
        colors[ImGuiCol_Button]             = g_CustomColors.Button;
        colors[ImGuiCol_ButtonHovered]      = g_CustomColors.ButtonHovered;
        colors[ImGuiCol_ButtonActive]       = g_CustomColors.ButtonActive;
        colors[ImGuiCol_Header]             = g_CustomColors.Header;
        colors[ImGuiCol_HeaderHovered]      = g_CustomColors.HeaderHovered;
        colors[ImGuiCol_HeaderActive]       = g_CustomColors.HeaderActive;
        colors[ImGuiCol_CheckMark]          = g_CustomColors.CheckMark;
        colors[ImGuiCol_SliderGrab]         = g_CustomColors.SliderGrab;
        colors[ImGuiCol_SliderGrabActive]   = g_CustomColors.SliderGrabActive;
        colors[ImGuiCol_Text]               = g_CustomColors.Text;
        colors[ImGuiCol_TextDisabled]       = g_CustomColors.TextDisabled;
        colors[ImGuiCol_Tab]                = g_CustomColors.Tab;
        colors[ImGuiCol_TabHovered]         = g_CustomColors.TabHovered;
        colors[ImGuiCol_TabSelected]        = g_CustomColors.TabSelected;
        colors[ImGuiCol_TabSelectedOverline]= g_CustomColors.TabSelectedOverline;
        colors[ImGuiCol_TabDimmed]          = g_CustomColors.TabDimmed;
        colors[ImGuiCol_TabDimmedSelected]  = g_CustomColors.TabDimmedSelected;
        break;
    }
}
