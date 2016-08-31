/****************************************************************************
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/.
*
* Copyright (c) 2016, shannon.mackey@refaqtory.com
* ***************************************************************************/
#ifndef VEQTOR_H
#define VEQTOR_H

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QSortFilterProxyModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

class Veqtor : public QObject {
    Q_OBJECT

    QSqlDatabase sqlite;
    QSqlTableModel* m_TableModel;
    QSortFilterProxyModel* m_ProxyModel;

    bool openDB(QString filename);
    bool createTables();

public:
    Veqtor(QString filename, QObject* parent = 0);
    virtual ~Veqtor() {}

    QSqlTableModel* TableModel() const
    {
        return m_TableModel;
    }

    QSortFilterProxyModel* ProxyModel() const
    {
        return m_ProxyModel;
    }
};

#endif // VEQTOR_H

Veqtor::Veqtor(QString filename, QObject* parent)
    : QObject(parent)
{
    if (openDB(filename)) {
        m_TableModel = new QSqlTableModel(this, sqlite);
        m_TableModel->setTable("veqtor");
        m_TableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        m_TableModel->select();

        m_ProxyModel = new QSortFilterProxyModel(this);
        m_ProxyModel->setSourceModel(m_TableModel);
        m_ProxyModel->setFilterKeyColumn(-1);
    }
}

bool Veqtor::openDB(QString filename)
{
    // qDebug() << "openDB filename" << filename;
    QFile dbf(filename);
    sqlite = QSqlDatabase::addDatabase("QSQLITE");
    sqlite.setDatabaseName(dbf.fileName());
    if (!dbf.exists()) { //if it doesn't already exist, create one
        if (sqlite.open()) {
            if (!createTables()) {
                qDebug("Database failed to initialize.");
                return false;
            }
        } else {
            qDebug("Database failed to open.");
            return false;
        }
    }
    return sqlite.open();
}

bool Veqtor::createTables()
{
    QSqlQuery createQuery;
    createQuery.prepare("CREATE TABLE veqtor "
                        "(edge TEXT PRIMARY KEY DEFAULT (hex(randomblob(16))),"
                        " node TEXT NOT NULL,"
                        " tag TEXT NOT NULL,"
                        " val TEXT NOT NULL,"
                        " stamp INTEGER DEFAULT (strftime('%s','now')));");
    return createQuery.exec();
}
