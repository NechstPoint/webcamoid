/* Webcamoid, webcam capture application.
 * Copyright (C) 2024  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#ifndef VIDEOENCODERRAV1EELEMENT_H
#define VIDEOENCODERRAV1EELEMENT_H

#include <iak/akvideoencoder.h>

class VideoEncoderRav1eElementPrivate;

class VideoEncoderRav1eElement: public AkVideoEncoder
{
    Q_OBJECT

    public:
        VideoEncoderRav1eElement();
        ~VideoEncoderRav1eElement();

        Q_INVOKABLE QStringList codecs() const override;
        Q_INVOKABLE AkVideoEncoderCodecID codecID(const QString &codec) const override;
        Q_INVOKABLE QString codecDescription(const QString &codec) const override;
        Q_INVOKABLE AkCompressedVideoCaps outputCaps() const override;
        Q_INVOKABLE QByteArray headers() const override;
        Q_INVOKABLE qint64 encodedTimePts() const override;
        Q_INVOKABLE AkPropertyOptions options() const override;

    private:
        VideoEncoderRav1eElementPrivate *d;

    protected:
        AkPacket iVideoStream(const AkVideoPacket &packet) override;

    public slots:
        bool setState(AkElement::ElementState state) override;
};

#endif // VIDEOENCODERRAV1EELEMENT_H
