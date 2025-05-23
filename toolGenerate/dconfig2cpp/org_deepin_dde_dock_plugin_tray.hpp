/**
 * This file is generated by dconfig2cpp.
 * Command line arguments: ./dconfig2cpp -p ./dde-tray-loader/toolGenerate/dconfig2cpp ./dde-tray-loader/plugins/dde-dock/configs/org.deepin.dde.dock.plugin.tray.json
 * Generation time: 2025-01-14T10:55:03
 * JSON file version: 1.0
 * 
 * WARNING: DO NOT MODIFY THIS FILE MANUALLY.
 * If you need to change the content, please modify the dconfig2cpp tool.
 */

#ifndef ORG_DEEPIN_DDE_DOCK_PLUGIN_TRAY_H
#define ORG_DEEPIN_DDE_DOCK_PLUGIN_TRAY_H

#include <QThread>
#include <QVariant>
#include <QDebug>
#include <QAtomicPointer>
#include <QAtomicInteger>
#include <DConfig>

class org_deepin_dde_dock_plugin_tray : public QObject {
    Q_OBJECT

    Q_PROPERTY(QList<QVariant> dockedTrayPlugins READ dockedTrayPlugins WRITE setDockedTrayPlugins NOTIFY dockedTrayPluginsChanged)
public:
    explicit org_deepin_dde_dock_plugin_tray(QThread *thread, const QString &appId, const QString &name, const QString &subpath, QObject *parent = nullptr)
        : QObject(parent) {

        if (!thread->isRunning()) {
            qWarning() << QStringLiteral("Warning: The provided thread is not running.");
        }
        Q_ASSERT(QThread::currentThread() != thread);
        auto worker = new QObject();
        worker->moveToThread(thread);
        QMetaObject::invokeMethod(worker, [=]() {
            auto config = DTK_CORE_NAMESPACE::DConfig::create(appId, name, subpath, nullptr);
            if (!config) {
                qWarning() << QStringLiteral("Failed to create DConfig instance.");
                worker->deleteLater();
                return;
            }
            config->moveToThread(QThread::currentThread());
            initialize(config);
            worker->deleteLater();
        });
    }
    explicit org_deepin_dde_dock_plugin_tray(QThread *thread, DTK_CORE_NAMESPACE::DConfigBackend *backend, const QString &appId, const QString &name, const QString &subpath, QObject *parent = nullptr)
        : QObject(parent) {

        if (!thread->isRunning()) {
            qWarning() << QStringLiteral("Warning: The provided thread is not running.");
        }
        Q_ASSERT(QThread::currentThread() != thread);
        auto worker = new QObject();
        worker->moveToThread(thread);
        QMetaObject::invokeMethod(worker, [=]() {
            auto config = DTK_CORE_NAMESPACE::DConfig::create(backend, appId, name, subpath, nullptr);
            if (!config) {
                qWarning() << QStringLiteral("Failed to create DConfig instance.");
                worker->deleteLater();
                return;
            }
            config->moveToThread(QThread::currentThread());
            initialize(config);
            worker->deleteLater();
        });
    }
    explicit org_deepin_dde_dock_plugin_tray(QThread *thread, const QString &name, const QString &subpath, QObject *parent = nullptr)
        : QObject(parent) {

        if (!thread->isRunning()) {
            qWarning() << QStringLiteral("Warning: The provided thread is not running.");
        }
        Q_ASSERT(QThread::currentThread() != thread);
        auto worker = new QObject();
        worker->moveToThread(thread);
        QMetaObject::invokeMethod(worker, [=]() {
            auto config = DTK_CORE_NAMESPACE::DConfig::create(name, subpath, nullptr);
            if (!config) {
                qWarning() << QStringLiteral("Failed to create DConfig instance.");
                worker->deleteLater();
                return;
            }
            config->moveToThread(QThread::currentThread());
            initialize(config);
            worker->deleteLater();
        });
    }
    explicit org_deepin_dde_dock_plugin_tray(QThread *thread, DTK_CORE_NAMESPACE::DConfigBackend *backend, const QString &name, const QString &subpath, QObject *parent = nullptr)
        : QObject(parent) {

        if (!thread->isRunning()) {
            qWarning() << QStringLiteral("Warning: The provided thread is not running.");
        }
        Q_ASSERT(QThread::currentThread() != thread);
        auto worker = new QObject();
        worker->moveToThread(thread);
        QMetaObject::invokeMethod(worker, [=]() {
            auto config = DTK_CORE_NAMESPACE::DConfig::create(backend, name, subpath, nullptr);
            if (!config) {
                qWarning() << QStringLiteral("Failed to create DConfig instance.");
                worker->deleteLater();
                return;
            }
            config->moveToThread(QThread::currentThread());
            initialize(config);
            worker->deleteLater();
        });
    }
    ~org_deepin_dde_dock_plugin_tray() {
        if (m_config.loadRelaxed()) {
            m_config.loadRelaxed()->deleteLater();
        }
    }

    QList<QVariant> dockedTrayPlugins() const {
        return p_dockedTrayPlugins;
    }
    void setDockedTrayPlugins(const QList<QVariant> &value) {
        auto oldValue = p_dockedTrayPlugins;
        p_dockedTrayPlugins = value;
        markPropertySet(0);
        if (auto config = m_config.loadRelaxed()) {
            QMetaObject::invokeMethod(config, [this, value]() {
                m_config.loadRelaxed()->setValue(QStringLiteral("dockedTrayPlugins"), value);
            });
        }
        if (p_dockedTrayPlugins != oldValue) {
            Q_EMIT dockedTrayPluginsChanged();
        }
    }
Q_SIGNALS:
    void dockedTrayPluginsChanged();
private:
    void initialize(DTK_CORE_NAMESPACE::DConfig *config) {
        Q_ASSERT(!m_config.loadRelaxed());
        m_config.storeRelaxed(config);
        if (testPropertySet(0)) {
            config->setValue(QStringLiteral("dockedTrayPlugins"), QVariant::fromValue(p_dockedTrayPlugins));
        } else {
            updateValue(QStringLiteral("dockedTrayPlugins"), QVariant::fromValue(p_dockedTrayPlugins));
        }

        connect(config, &DTK_CORE_NAMESPACE::DConfig::valueChanged, this, [this](const QString &key) {
            updateValue(key);
        }, Qt::DirectConnection);
    }
    void updateValue(const QString &key, const QVariant &fallback = QVariant()) {
        Q_ASSERT(QThread::currentThread() == m_config.loadRelaxed()->thread());
        const QVariant &value = m_config.loadRelaxed()->value(key, fallback);
        if (key == QStringLiteral("dockedTrayPlugins")) {
            auto newValue = qvariant_cast<QList<QVariant>>(value);
            QMetaObject::invokeMethod(this, [this, newValue]() {
                if (p_dockedTrayPlugins != newValue) {
                    p_dockedTrayPlugins = newValue;
                    Q_EMIT dockedTrayPluginsChanged();
                }
            });
            return;
        }
    }
    inline void markPropertySet(const int index) {
        if (index < 32) {
            m_propertySetStatus0.fetchAndOrOrdered(1 << (index - 0));
            return;
        }
        Q_UNREACHABLE();
    }
    inline bool testPropertySet(const int index) const {
        if (index < 32) {
            return (m_propertySetStatus0.loadRelaxed() & (1 << (index - 0)));
        }
        Q_UNREACHABLE();
    }
    QAtomicPointer<DTK_CORE_NAMESPACE::DConfig> m_config = nullptr;
    QList<QVariant> p_dockedTrayPlugins { QList<QVariant>{QVariant(QStringLiteral("sni:Fcitx")), QVariant(QStringLiteral("mount-item-key")), QVariant(QStringLiteral("sni:uos-activator"))} };
    QAtomicInteger<quint32> m_propertySetStatus0 = 0;
};

#endif // ORG_DEEPIN_DDE_DOCK_PLUGIN_TRAY_H
