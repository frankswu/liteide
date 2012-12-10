/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011-2012 LiteIDE Team. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: htmlpreview.h
// Creator: visualfc <visualfc@gmail.com>

#ifndef HTMLPREVIEW_H
#define HTMLPREVIEW_H

#include <liteapi/liteapi.h>

#include <QPointer>

class QActionGroup;
class HtmlPreview : public QObject
{
    Q_OBJECT
public:
    explicit HtmlPreview(LiteApi::IApplication *app,QObject *parent = 0);
    virtual ~HtmlPreview();
public slots:
    void appLoaded();
    QByteArray loadCssData(const QString &fileName);
    void currentEditorChanged(LiteApi::IEditor*);
    void contentsChanged();
    void scrollValueChanged();
    void syncScrollValue();
    void toggledSyncSwitch(bool);
    void toggledSyncScroll(bool);
    void editorHtmlPrivew(bool force = false);
    void triggeredTool(bool);
    void exportHtml();
    void exportPdf();
    void cssTtriggered(QAction*);
    void loadFinished(bool);
protected:
    LiteApi::IApplication *m_liteApp;
    QWidget               *m_widget;
    LiteApi::IHtmlWidget  *m_htmlWidget;
    QAction     *m_exportHtmlAct;
    QAction     *m_exportPdfAct;
    QAction     *m_configAct;
    QAction     *m_syncScrollAct;
    QAction     *m_syncSwitchAct;
    QMenu       *m_cssMenu;
    QMenu       *m_configMenu;
    QActionGroup *m_cssActGroup;
    QAction     *m_toolAct;
    QPointer<LiteApi::ITextEditor> m_curEditor;
    QPointer<QPlainTextEdit> m_curTextEditor;
    bool        m_bWebkit;
    bool        m_bFileChanged;
    QByteArray  m_exportOrgTemple;
    QByteArray  m_exportTemple;
    QByteArray  m_exportHtml;
    QByteArray  m_lastData;
    QByteArray  m_head;
    QPoint      m_prevPos;
};

#endif // HTMLPREVIEW_H
