![SDR Angel banner](doc/img/sdrangel_banner.png)

**SDRangel** is an open-source Qt5 / OpenGL 3.0+ SDR and signal analyzer frontend to various hardware.

**Wiki**: Most of the information and documentation related to SDRangel can be found in the [Wiki](https://github.com/f4exb/sdrangel/wiki). Please make sure to check it in case of questions or trouble and before you post issues on GitHub. You may also seek help from other users using the discussion group below. Before running the program, make sure you read at least the [Home](https://github.com/f4exb/sdrangel/wiki) and [Quick Start](https://github.com/f4exb/sdrangel/wiki/Quick-start) pages.

**Discussion group**: You can ask other users for help or discuss subjects related to SDRangel and its ancillary projects [here](https://groups.io/g/sdrangel).

**Ancillary projects**

* [SDRangelcli](https://github.com/f4exb/sdrangelcli) is a web application that can be used to control a headless (server flavor) instance of SDRangel. It can also be used as a remote control for the GUI flavor.
* [SDRangel-Docker](https://github.com/f4exb/sdrangel-docker) is a collection of Docker files and scripts to facilitate building and running SDRangel in a Docker container. Works for either the GUI (only on a Linux host) or the server.

## Установка

Клонируем репозиторий SDRangel
```bash
git clone https://github.com/Vikashweps/SDRangel.git
```

Далее, из репозитрия запускаем скрипт `install.sh` (все компоненты установятся в `/opt/build` и `/opt/install`):

```bash
cd SDRangel
sudo chmod 777 install.sh   # Даем права скрипту на выполнение
./install.sh                # Вводим пароль и ждем установки всех компонентов.

mkdir build; cd build

# Выполняем большой Cmake
cmake -Wno-dev -DDEBUG_OUTPUT=ON -DRX_SAMPLE_24BIT=OFF \
-DCMAKE_BUILD_TYPE=RelWithDebInfo \
-DMIRISDR_DIR=/opt/install/libmirisdr \
-DAIRSPY_DIR=/opt/install/libairspy \
-DAIRSPYHF_DIR=/opt/install/libairspyhf \
-DBLADERF_DIR=/opt/install/libbladeRF \
-DHACKRF_DIR=/opt/install/libhackrf \
-DRTLSDR_DIR=/opt/install/librtlsdr \
-DLIMESUITE_DIR=/opt/install/LimeSuite \
-DIIO_DIR=/opt/install/libiio \
-DPERSEUS_DIR=/opt/install/libperseus \
-DXTRX_DIR=/opt/install/xtrx-images \
-DSOAPYSDR_DIR=/opt/install/SoapySDR \
-DUHD_DIR=/opt/install/uhd \
-DAPT_DIR=/opt/install/aptdec \
-DCM256CC_DIR=/opt/install/cm256cc \
-DDSDCC_DIR=/opt/install/dsdcc \
-DSERIALDV_DIR=/opt/install/serialdv \
-DMBE_DIR=/opt/install/mbelib \
-DCODEC2_DIR=/opt/install/codec2 \
-DSGP4_DIR=/opt/install/sgp4 \
-DLIBSIGMF_DIR=/opt/install/libsigmf \
-DDAB_DIR=/opt/install/libdab \
-DGGMORSE_DIR=/opt/install/ggmorse \
-DRNNOISE_DIR=/opt/install/rnnoise \
-DINMARSATC_DIR=/opt/install/inmarsatc \
-DCMAKE_INSTALL_PREFIX=/opt/install/sdrangel ..

# Компилируем, без `install`, чтобы во время разработки удобно тестировать изменения
make -j16
```

Запускаем:

```bash
./sdrangel
```