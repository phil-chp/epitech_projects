FROM ubuntu:20.04

#! ==> Utilities
# ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
        git curl unzip zip build-essential \
        # openjdk-13-jdk libc6-dev libstdc++6 tcl \
        xz-utils

#! ==> Install and setup flutter
RUN git clone https://github.com/flutter/flutter.git -b stable --depth 1 /usr/local/flutter
ENV PATH="$PATH:/usr/local/flutter/bin"

#! ==> Install and setup android
# ENV ANDROID_SDK_ROOT=/usr/local/android
# RUN curl -o /tmp/tools.zip https://dl.google.com/android/repository/commandlinetools-linux-7302050_latest.zip \
#     && mkdir ${ANDROID_SDK_ROOT} \
#     && unzip /tmp/tools.zip -d ${ANDROID_SDK_ROOT} \
#     && rm /tmp/tools.zip
# RUN yes | ${ANDROID_SDK_ROOT}/cmdline-tools/bin/sdkmanager --licenses --sdk_root=${ANDROID_SDK_ROOT}
# RUN ${ANDROID_SDK_ROOT}/cmdline-tools/bin/sdkmanager --sdk_root=${ANDROID_SDK_ROOT} "build-tools;31.0.0" "platforms;android-31" "platform-tools"

#! ==> Setup workdir and build (web and apk)
RUN flutter doctor
COPY . /app
WORKDIR /app

# RUN flutter clean
RUN flutter pub get
# RUN flutter build apk --split-per-abi --release --no-tree-shake-icons
# COPY build/app/outputs/flutter-apk/ assets/apk/
