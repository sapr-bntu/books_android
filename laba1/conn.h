/////****************************************************************************
////**
////** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
////** All rights reserved.
////** Contact: Nokia Corporation (qt-info@nokia.com)
////**
////** This file is part of the examples of the Qt Toolkit.
////**
////** $QT_BEGIN_LICENSE:BSD$
////** You may use this file under the terms of the BSD license as follows:
////**
////** "Redistribution and use in source and binary forms, with or without
////** modification, are permitted provided that the following conditions are
////** met:
////**   * Redistributions of source code must retain the above copyright
////**     notice, this list of conditions and the following disclaimer.
////**   * Redistributions in binary form must reproduce the above copyright
////**     notice, this list of conditions and the following disclaimer in
////**     the documentation and/or other materials provided with the
////**     distribution.
////**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
////**     the names of its contributors may be used to endorse or promote
////**     products derived from this software without specific prior written
////**     permission.
////**
////** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
////** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
////** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
////** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
////** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
////** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
//** $QT_END_LICENSE$
//**
//****************************************************************************/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtCore/QFile>

/*
    This file defines a helper function to open a connection to an
    in-memory SQLITE database and to create a test table.

    If you want to use another database, simply modify the code
    below. All the examples in this directory use this function to
    connect to a database.
*/
//! [0]
static bool createConnection()
{
    QFile::exists("asd.db");

    if (!(QFile::exists("asd.db")))
    {
        qDebug()<<"no";
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("dsa.db");
        db.open();
        QSqlQuery query;
        query.exec("CREATE TABLE [books] ([id] INTEGER  PRIMARY KEY AUTOINCREMENT NOT NULL,[title] varchar(20)  NULL,[author] varchar(20)  NULL,[genre] varchar(20)  NULL,[year] int  NULL,[rating] int  NULL,[text] VARCHAR(10000)  NULL)");
        query.first();
     }
    else
    {
        qDebug()<<"yes";
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("asd.db");
        db.open();
    }

    return true;
}
//! [0]

#endif
