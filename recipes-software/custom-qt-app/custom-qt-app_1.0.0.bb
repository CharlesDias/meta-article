SUMMARY = "Recipe for a QT5 application"
DESCRIPTION = "Recipe created to build the QT5 application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "git://github.com/CharlesDias/Qt-on-iMX6ULL.git;branch=main;protocol=https"
PV = "1.0+git${SRCPV}"
SRCREV = "8646e916f66f0f3a951c0c31f50545f5ab4598aa"

DEPENDS += " qtbase libgpiod "

S = "${WORKDIR}/git/samples/Part2-DemoProject"

do_install:append() {
    # Install the application
    install -d ${D}/opt/DemoProject/bin/
    install -m 0755 DemoProject ${D}/opt/DemoProject/bin/
}

FILES:${PN} += "/opt/DemoProject/bin/DemoProject"

# Inherit the qmake5 class to build the application
inherit qmake5