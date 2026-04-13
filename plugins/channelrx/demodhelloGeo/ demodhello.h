#include "demodhello.h"
#ifndef SERVER_MODE
#include "demodhellogui.h"
#endif
#include <QDebug>

HelloDemod::HelloDemod(const QString& channelName, PluginAPI* pluginAPI)
    : ChannelRx(channelName, pluginAPI) {
    qInfo() << "[HELLO] Demodulator created";
}

HelloDemod::~HelloDemod() {
    if (m_gui) delete m_gui;
}

void HelloDemod::start() {
    ChannelRx::start();
    qInfo() << "[HELLO] Started";
}

void HelloDemod::stop() {
    ChannelRx::stop();
    qInfo() << "[HELLO] Stopped";
}

void HelloDemod::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end) {
    // Здесь будет твоя DSP цепочка. Пока пусто.
    (void)begin; 
    (void)end;
}

void HelloDemod::applySettings(const HelloDemodSettings& settings, bool force) {
    m_settings = settings;
    if (m_gui) m_gui->displaySettings();
}

ChannelGUI* HelloDemod::createChannelGUI(PluginAPI* pluginAPI) {
#ifndef SERVER_MODE
    if (!m_gui) {
        m_gui = new HelloDemodGUI(this, pluginAPI);
    }
    return m_gui;
#else
    (void)pluginAPI;
    return nullptr;
#endif
}