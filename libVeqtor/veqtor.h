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
