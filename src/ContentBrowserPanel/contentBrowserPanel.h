#ifndef CONTENT_BROWSER_PANEL_H
#define CONTENT_BROWSER_PANEL_H

#include "imgui.h"
#include <filesystem>

class ContentBrowserPanel
{
public:
    ContentBrowserPanel();
    ~ContentBrowserPanel();

    void OnImGuiRender();

    void SetSelectedEntity();

private:
    std::filesystem::path m_CurrentDir;
};

#endif