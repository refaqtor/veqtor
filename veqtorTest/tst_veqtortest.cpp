/****************************************************************************
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/.
*
* Copyright (c) 2016, shannon.mackey@refaqtory.com
* ***************************************************************************/
#include <QString>
#include <QtTest>

class VeqtorTest : public QObject
{
    Q_OBJECT

public:
    VeqtorTest();

private Q_SLOTS:
    void testCase1();
};

VeqtorTest::VeqtorTest()
{
}

void VeqtorTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(VeqtorTest)

#include "tst_veqtortest.moc"
