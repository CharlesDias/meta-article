SUMMARY = "Install custom touch calibration service"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit systemd

SRC_URI = "file://run-touch-calibration-once.sh \
           file://run-touch-calibration-once.service"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/run-touch-calibration-once.sh ${D}${bindir}/run-touch-calibration-once

    install -d ${D}/${systemd_unitdir}/system
    install -m 0644 ${S}/run-touch-calibration-once.service ${D}/${systemd_unitdir}/system/
}

FILES_${PN} += "${D}${bindir}/run-touch-calibration-once"

SYSTEMD_SERVICE:${PN} = "run-touch-calibration-once.service"