
FROM espressif/idf:release-v4.4

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

WORKDIR /app

ADD . /app

# Apply existing ESP-IDF patches
RUN cd /opt/esp/idf && \
    patch --ignore-whitespace -p1 -i "/app/tools/patches/panic-hook (esp-idf 4.2 and 4.3).diff" && \
    patch --ignore-whitespace -p1 -i "/app/tools/patches/sdcard-fix (esp-idf 4.2 and 4.3).diff"

# Build ESP32-S3
RUN source /opt/esp/idf/export.sh && \
    python rg_tool.py --with-networking --target=esp32-s3-devkit release
	
