#pragma once
#include <QString>
#include <QJsonObject>

// Пока пусто — добавим параметры позже
struct HelloDemodSettings {
    void resetToDefaults() {}
    QJsonObject toJson() const { return {}; }
    void fromJson(const QJsonObject&) {}
};