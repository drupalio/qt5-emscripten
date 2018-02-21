/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QHTML5BACKINGSTORE_H
#define QHTML5BACKINGSTORE_H

#include <qpa/qplatformbackingstore.h>
#include <QtGui/QImage>

QT_BEGIN_NAMESPACE

class QOpenGLTexture;
class QRegion;
class QHtml5Compositor;

class QHtml5BackingStore : public QPlatformBackingStore
{
public:
    QHtml5BackingStore(QHtml5Compositor *compositor, QWindow *window);
    ~QHtml5BackingStore();

    QPaintDevice *paintDevice() override;

    void beginPaint(const QRegion &) override;
    void flush(QWindow *window, const QRegion &region, const QPoint &offset) override;
    void resize(const QSize &size, const QRegion &staticContents) override;
    QImage toImage() const override;
    const QImage &getImageRef() const;

    const QOpenGLTexture* getUpdatedTexture();

protected:
    void updateTexture();

private:
    QHtml5Compositor *mCompositor;

    QImage mImage;

    QScopedPointer<QOpenGLTexture> mTexture;

    QRegion mDirty;

};

QT_END_NAMESPACE

#endif // QHTML5BACKINGSTORE_H
