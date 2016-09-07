/****************************************************************************
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/.
*
* Copyright (c) 2016, shannon.mackey@refaqtory.com
* ***************************************************************************/
#ifndef VEQTORCOMMAND_H
#define VEQTORCOMMAND_H

#include <QObject>

class VeqtorCommand : public QObject
{
    Q_OBJECT
public:
    explicit VeqtorCommand(QObject *parent = 0);

signals:

public slots:
};

#endif // VEQTORCOMMAND_H