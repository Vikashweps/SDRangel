#include "demodhello.h"
#include "demodhellogui.h"

HelloDemod::HelloDemod(const QString& channelName, PluginAPI* pluginAPI)
    : ChannelRx(channelName, pluginAPI) {}

HelloDemod::~HelloDemod() {}

ChannelGUI* HelloDemod::createChannelGUI(PluginAPI* pluginAPI) {
    return new HelloDemodGUI(this, pluginAPI);
}