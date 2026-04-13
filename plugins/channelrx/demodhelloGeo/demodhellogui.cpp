#include "demodhellogui.h"
#include "ui_demodhellogui.h" // Автоматически генерируется из .ui файла
#include "demodhello.h"

HelloDemodGUI::HelloDemodGUI(HelloDemod* channel, PluginAPI* pluginAPI)
    : ChannelGUI(channel, pluginAPI), ui(new Ui::HelloDemodGUI), m_channel(channel) {
    ui->setupUi(this);
}

HelloDemodGUI::~HelloDemodGUI() {
    delete ui;
}

void HelloDemodGUI::applySettings(HelloDemodSettings& settings, bool force) {
    m_channel->applySettings(settings, force);
}

void HelloDemodGUI::resetToDefaultsSettings() {
    HelloDemodSettings settings;
    settings.resetToDefaults();
    applySettings(settings, true);
}

void HelloDemodGUI::displaySettings() {
    // Обновление полей UI из настроек канала
}