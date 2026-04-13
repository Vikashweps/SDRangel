#include <QtPlugin>
#include "plugin/pluginapi.h"

#include "demodhelloplugin.h"
#include "/home/vika/Desktop/SDRangel/plugins/channelrx/demodhelloGeo/ demodhello.h"

#ifndef SERVER_MODE

const PluginDescriptor HelloPlugin::m_pluginDescriptor = {
    ADSBDemod::m_channelId,
    QStringLiteral("HELLO Demodulator"),
    QStringLiteral("1")
};


HelloPlugin::HelloPlugin(QObject* parent) :
    QObject(parent),
    m_pluginAPI(0)
{
}

const PluginDescriptor& HelloPlugin::getPluginDescriptor() const
{
    return m_pluginDescriptor;
}


void HelloPlugin::initPlugin(PluginAPI* pluginAPI) {
    m_pluginDescriptor = pluginAPI; 
    m_pluginAPI->registerRxChannel(HelloPlugin::m_channelIdURI, HelloPlugin::m_channelId, this);
}

void HelloPlugin::createRxChannel(DeviceAPI *deviceAPI, BasebandSampleSink **bs, ChannelAPI **cs) const
{
    if (bs || cs)
    {
        HelloPlugin *instance = new HelloPlugin(deviceAPI);

        if (bs) {
            *bs = instance;
        }

        if (cs) {
            *cs = instance;
        }
    }
}

