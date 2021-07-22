#!/bin/bash

# Webcamoid, webcam capture application.
# Copyright (C) 2017  Gonzalo Exequiel Pedone
#
# Webcamoid is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Webcamoid is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
#
# Web-Site: http://webcamoid.github.io/

git clone https://github.com/webcamoid/DeployTools.git

export PATH="${PWD}/.local/bin:${PATH}"
export PYTHONPATH="${PWD}/DeployTools"

if [ "${DOCKERIMG}" = ubuntu:focal ]; then
    cat << EOF > package_info_libdir.conf
[System]
libDir = /opt/qt${PPAQTVER}/lib
EOF

    xvfb-run --auto-servernum python3 DeployTools/deploy.py \
        -d "${PWD}/webcamoid-data" \
        -c "${PWD}/build/package_info.conf" \
        -c "${PWD}/build/package_info_libdir.conf" \
        -o "${PWD}/webcamoid-packages/linux"
else
    xvfb-run --auto-servernum python3 DeployTools/deploy.py \
        -d "${PWD}/webcamoid-data" \
        -c "${PWD}/build/package_info.conf" \
        -o "${PWD}/webcamoid-packages/linux"
fi
