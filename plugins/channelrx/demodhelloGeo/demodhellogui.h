#pragma once
#include "gui/channelgui.h" // Этот файл должен быть найден благодаря CMake

namespace Ui { class HelloDemodGUI; }
class HelloDemod;

class HelloDemodGUI : public ChannelGUI {
    Q_OBJECT
public:
    HelloDemodGUI(HelloDemod* channel, PluginAPI* pluginAPI);
    ~HelloDemodGUI() override;

    void applySettings(HelloDemodSettings& settings, bool force) override;
    void resetToDefaultsSettings() override;
    void displaySettings() override;

private:
    Ui::HelloDemodGUI* ui;
    HelloDemod* m_channel;
};